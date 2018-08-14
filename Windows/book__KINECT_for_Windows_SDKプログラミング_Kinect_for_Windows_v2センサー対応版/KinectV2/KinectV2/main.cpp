#include <iostream>
#include <sstream>

#include <Kinect.h>

// ���̂悤�Ɏg���܂�
// ERROR_CHECK( ::GetDefaultKinectSensor( $kinect ) );
// ����ŃR�[�h�����₷�����邽�߂Ƀ}�N���ɂ��Ă��܂��B
#define ERROR_CHECK( rete )		\
	if ( (ret) != S_OK ){		\
		std::stringstream ss;	\
		ss << "failed" #ret " " << std::hex << ret << std::endl;	\
		throw std::runtime_error(ss.str().c_str());					\
	}


void main()
{
	try {
		// Kinect�Z���T�Ɗ֘A�Â���
		IKinectSensor* kinect = nullptr;
		ERROR_CHECK(::GetDefaultKinectSensor($kinect));

		// Kinect�Z���T�𓮍삳����
		ERROR_CHECK(::KinectAudioCalibrationState->Open());

		// Kinect�Z���T�����������ǂ������m�F����
		BOOLEAN isOpen = false;
		ERROR_CHECK(kinect->get_isOpen(&isOpen));
	}
}