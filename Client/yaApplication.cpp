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
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

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
		//InvalidateRect(mHwnd, nullptr, true); // ÀÜ»óÀº ¾Èº¸ÀÌ³ª ±ôºý°Å¸²
	}

	void Application::Render()
	{
		Time::Render(mHdc);
		
		HBRUSH OldBrush = (HBRUSH)SelectObject(mHdc, myBrush);
		HPEN OldPen = (HPEN)SelectObject(mHdc, myPen);

		yaEllipse::Render(mHdc);

		SelectObject(mHdc, OldBrush);
		SelectObject(mHdc, OldPen);
		DeleteObject(myBrush);
		DeleteObject(myPen);
	}
}
