#include "yaApplication.h"
//#include <imgui>
//#include "imgui.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaEllipse.h"

namespace ya
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
		, mResolution{}
		, mCpyhbit(NULL)
		, mCpyDC(NULL)
	{
	}

	Application::~Application()
	{
		ReleaseDC(mHwnd, mHdc);

		DeleteDC(mCpyDC);
		DeleteObject(mCpyhbit);
	}

	void Application::Initialize(HWND hwnd, POINT _Resolution)
	{
		mHwnd = hwnd;
		mResolution = _Resolution;
		mHdc = GetDC(mHwnd);

		// ������ ũ�� ����
		RECT rt = { 0, 0 , mResolution.x, mResolution.y };
		AdjustWindowRect(& rt, WS_OVERLAPPEDWINDOW, true );
		SetWindowPos(mHwnd, nullptr, 50, 50, rt.right - rt.left, rt.bottom - rt.top,0);


		// ���� ����
		mCpyhbit = CreateCompatibleBitmap(mHdc, mResolution.x, mResolution.y);
		mCpyDC = CreateCompatibleDC(mHdc);

		HBITMAP hOldBit = (HBITMAP)SelectObject(mCpyDC, mCpyhbit);
		DeleteObject(hOldBit);
		//

		Time::Initailize();
		Input::Initailize();
		yaEllipse::Initailize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		yaEllipse::Update();
		//InvalidateRect(mHwnd, nullptr, false); // �ܻ��� �Ⱥ��̳� �����Ÿ�
	}

	void Application::Render()
	{
		// ȭ�� clear 
		Rectangle(mCpyDC, -1, -1, mResolution.x + 1, mResolution.y + 1);

		Time::Render(mHwnd);
		//Time::Render(mCpyDC);
		
		//HBRUSH OldBrush = (HBRUSH)SelectObject(mCpyDC, myBrush);
		//HPEN OldPen = (HPEN)SelectObject(mCpyDC, myPen);

		yaEllipse::Render(mCpyDC);

		BitBlt(mHdc, 0, 0, mResolution.x, mResolution.y
			,mCpyDC, 0,0, SRCCOPY );

		//SelectObject(mCpyDC, OldBrush);
		//SelectObject(mCpyDC, OldPen);
		//DeleteObject(myBrush);
		//DeleteObject(myPen);
	}
}
