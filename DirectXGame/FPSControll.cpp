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
//	//���g���擾
//	QueryPerformanceFrequency(&mTimeFreq);
//	//�v���J�n���Ԃ̏�����
//	QueryPerformanceCounter(&mTimeStart);
//	//60FPS�ɌŒ肷��ꍇ��1�t���[���ɂ������鎞��
//	FRAME_TIME = 1.0 / 60.0;
//}
//
//void FPSControll::PostFPSSet60()
//{
//
//	// ���̎��Ԃ��擾
//	QueryPerformanceCounter(&mTimeEnd);
//	// (���̎��� - �O�t���[���̎���) / ���g�� = �o�ߎ���(�b�P��)
//	mFrameTime = static_cast<double>(mTimeEnd.QuadPart - mTimeStart.QuadPart) / static_cast<double>(mTimeFreq.QuadPart);
//	//�������Ԃɗ]�T������ꍇ�͂��̕��҂�
//	if (mFrameTime < FRAME_TIME)
//	{
//		//Sleep�̎��Ԃ��v�Z
//		DWORD sleepTime = static_cast<DWORD>((FRAME_TIME - mFrameTime) * 1000);
//		timeBeginPeriod(1);
//		//�Q��
//		Sleep(sleepTime);
//		timeEndPeriod(1);
//	}
//	
//}
