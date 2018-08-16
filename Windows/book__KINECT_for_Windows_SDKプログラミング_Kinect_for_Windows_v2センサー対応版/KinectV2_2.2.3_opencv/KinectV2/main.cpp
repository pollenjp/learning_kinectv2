#include <iostream>
#include <sstream>

#include <Kinect.h>

// 次のように使います
// ERROR_CHECK( ::GetDefaultKinectSensor( $kinect ) );
// 解説でコードを見やすくするためにマクロにしています。
#define ERROR_CHECK( ret )		\
	if ( (ret) != S_OK ){		\
		std::stringstream ss;	\
		ss << "failed" #ret " " << std::hex << ret << std::endl;	\
		throw std::runtime_error(ss.str().c_str());					\
	}


int main()
{
	try {
		// Kinectセンサと関連づける
		IKinectSensor* kinect = nullptr;
		ERROR_CHECK(::GetDefaultKinectSensor(&kinect));

		// Kinectセンサを動作させる
		ERROR_CHECK(kinect->Open());

		// Kinectセンサが動いたかどうかを確認する
		BOOLEAN isOpen = false;
		ERROR_CHECK(kinect->get_IsOpen(&isOpen));
		std::cout << "Kinect is " << (isOpen ? "Open" : "Not Open") << std::endl;

		// ちょっと待つ
		::Sleep(3000);

		// Kinectセンサの動作を止める
		kinect->Close();
		kinect->Release();
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}