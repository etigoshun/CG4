#include "FPSControll.h"
#include <vector>
#include <cassert>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx12.h>
#include "SafeDelete.h"

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")

//FPSControll::FPSControll()
//{
//}
//
//void FPSControll::PreFPSSet60()
//{
//	//周波数取得
//	QueryPerformanceFrequency(&mTimeFreq);
//	//計測開始時間の初期化
//	QueryPerformanceCounter(&mTimeStart);
//	//60FPSに固定する場合の1フレームにかけられる時間
//	FRAME_TIME = 1.0 / 60.0;
//}
//
//void FPSControll::PostFPSSet60()
//{
//
//	// 今の時間を取得
//	QueryPerformanceCounter(&mTimeEnd);
//	// (今の時間 - 前フレームの時間) / 周波数 = 経過時間(秒単位)
//	mFrameTime = static_cast<double>(mTimeEnd.QuadPart - mTimeStart.QuadPart) / static_cast<double>(mTimeFreq.QuadPart);
//	//処理時間に余裕がある場合はその分待つ
//	if (mFrameTime < FRAME_TIME)
//	{
//		//Sleepの時間を計算
//		DWORD sleepTime = static_cast<DWORD>((FRAME_TIME - mFrameTime) * 1000);
//		timeBeginPeriod(1);
//		//寝る
//		Sleep(sleepTime);
//		timeEndPeriod(1);
//	}
//	
//}
