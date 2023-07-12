#pragma once

#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <d3dx12.h>
#include <cstdlib>
#include <imgui.h>
#include <chrono>

#include "WinApp.h"

class FPSControll
{

public:
	FPSControll();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void PreFPSSet60();

	/// <summary>
	/// FPSを60に固定
	/// </summary>
	void PostFPSSet60();

private:
	// ウィンドウズアプリケーション管理
	WinApp* winApp;

	LARGE_INTEGER mTimeFreq;
	LARGE_INTEGER mTimeStart;
	LARGE_INTEGER mTimeEnd;
	float FRAME_TIME;
	float mFrameTime;

};

