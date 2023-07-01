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
		//InvalidateRect(mHwnd, nullptr, true);
	}

	void Application::Render()
	{
		Time::Render(mHdc);
		
		yaEllipse::Render(mHdc);

	}
}
