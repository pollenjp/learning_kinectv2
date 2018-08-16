#include <iostream>
#include <sstream>

#include <Kinect.h>

// ���̂悤�Ɏg���܂�
// ERROR_CHECK( ::GetDefaultKinectSensor( $kinect ) );
// ����ŃR�[�h�����₷�����邽�߂Ƀ}�N���ɂ��Ă��܂��B
#define ERROR_CHECK( ret )		\
	if ( (ret) != S_OK ){		\
		std::stringstream ss;	\
		ss << "failed" #ret " " << std::hex << ret << std::endl;	\
		throw std::runtime_error(ss.str().c_str());					\
	}


int main()
{
	try {
		// Kinect�Z���T�Ɗ֘A�Â���
		IKinectSensor* kinect = nullptr;
		ERROR_CHECK(::GetDefaultKinectSensor(&kinect));

		// Kinect�Z���T�𓮍삳����
		ERROR_CHECK(kinect->Open());

		// Kinect�Z���T�����������ǂ������m�F����
		BOOLEAN isOpen = false;
		ERROR_CHECK(kinect->get_IsOpen(&isOpen));
		std::cout << "Kinect is " << (isOpen ? "Open" : "Not Open") << std::endl;

		// ������Ƒ҂�
		::Sleep(3000);

		// Kinect�Z���T�̓�����~�߂�
		kinect->Close();
		kinect->Release();
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}