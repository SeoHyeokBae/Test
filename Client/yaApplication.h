#pragma once
#include "CommonInclude.h"


namespace ya
{
	using namespace math;
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HBRUSH myBrush = CreateSolidBrush(RGB(169, 169, 169));
		HPEN myPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	};
}


