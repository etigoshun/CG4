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
	/// ����������
	/// </summary>
	void PreFPSSet60();

	/// <summary>
	/// FPS��60�ɌŒ�
	/// </summary>
	void PostFPSSet60();

private:
	// �E�B���h�E�Y�A�v���P�[�V�����Ǘ�
	WinApp* winApp;

	LARGE_INTEGER mTimeFreq;
	LARGE_INTEGER mTimeStart;
	LARGE_INTEGER mTimeEnd;
	float FRAME_TIME;
	float mFrameTime;

};

