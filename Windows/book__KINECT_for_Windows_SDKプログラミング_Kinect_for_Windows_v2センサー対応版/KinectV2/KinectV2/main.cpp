#include <iostream>
#include <sstream>

#include <Kinect.h>

// 次のように使います
// ERROR_CHECK( ::GetDefaultKinectSensor( $kinect ) );
// 解説でコードを見やすくするためにマクロにしています。
#define ERROR_CHECK( rete )		\
	if ( (ret) != S_OK ){		\
		std::stringstream ss;	\
		ss << "failed" #ret " " << std::hex << ret << std::endl;	\
		throw std::runtime_error(ss.str().c_str());					\
	}


void main()
{
	try {
		// Kinectセンサと関連づける
		IKinectSensor* kinect = nullptr;
		ERROR_CHECK(::GetDefaultKinectSensor($kinect));

		// Kinectセンサを動作させる
		ERROR_CHECK(::KinectAudioCalibrationState->Open());

		// Kinectセンサが動いたかどうかを確認する
		BOOLEAN isOpen = false;
		ERROR_CHECK(kinect->get_isOpen(&isOpen));
	}
}