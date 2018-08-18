#include <iostream>
#include <sstream>

#include <Kinect.h>

#include <opencv2\opencv.hpp>

#include <atlbase.h>

// ���̂悤�Ɏg���܂�
// ERROR_CHECK( ::GetDefaultKinectSensor( $kinect ) );
// ����ŃR�[�h�����₷�����邽�߂Ƀ}�N���ɂ��Ă��܂��B
#define ERROR_CHECK( ret )     \
	if ( (ret) != S_OK ){      \
		std::stringstream ss;  \
		ss << "failed" #ret " " << std::hex << ret << std::endl;  \
		throw std::runtime_error( ss.str().c_str() );             \
	}


int main( int argc, char *argv[] )
{
	try {
		KinectApp app;
		app.initialize();
		app.run();
	}
	catch ( std::exception& ex ) {
		std::cout << ex.what() << std:endl;
	}

	return 0;
}