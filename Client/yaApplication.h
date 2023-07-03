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

		void Initialize(HWND hwnd, POINT _Resolution);
		void Run();
		void Update();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
		POINT mResolution; // ������ �ػ�

		// ���� ���۸�
		HBITMAP mCpyhbit;
		HDC mCpyDC;


		//HBRUSH myBrush = CreateSolidBrush(RGB(0, 0, 0));
		//HPEN myPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	};
}


