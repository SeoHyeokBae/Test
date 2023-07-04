#include "yaTime.h"
#include "yaApplication.h"

namespace ya
{
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurFrequency = {};
	float Time::mDeltaTime = 0.0f;

	float Time::Display_DT = 0.0f;
	float Time::Display_fps = 0.0f;

	void Time::Initailize()
	{
		// CPU ���� �������� �����´�.
		QueryPerformanceFrequency(&mCpuFrequency);

		// ���α׷��� ���ۉ����� �������� �����´�.
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&mCurFrequency);

		float differenceFrequency
			= static_cast<float>(mCurFrequency.QuadPart - mPrevFrequency.QuadPart);
			
		mDeltaTime = differenceFrequency / static_cast<float>(mCpuFrequency.QuadPart);
		mPrevFrequency.QuadPart = mCurFrequency.QuadPart;

		static float timeCheck = 0.0f;

	}

	void Time::Render(HDC hdc) 
	{
		static float timeCheck = 0.0f;

		wchar_t szFloat[50] = {};
		//float fps = 1.0f / mDeltaTime;

		timeCheck += mDeltaTime;
		if (timeCheck >= 1.0f)
		{
			Display_DT = mDeltaTime;
			Display_fps = 1.0f / Display_DT;

			timeCheck = 0.0f;
		}
			swprintf_s(szFloat, 50, L"fps : %f , DT : %f", Display_fps, Display_DT);
			int strLen = wcsnlen_s(szFloat, 50);

			TextOut(hdc, 10, 10, szFloat, strLen);
	}

}