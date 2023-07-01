#pragma once
#include "CommonInclude.h"

namespace ya
{
	using namespace math;
	struct Ball
	{
		Vector2 mStartPos;
		Vector2 dire;
		Vector2 mMove;
	};

	class yaEllipse
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);


	private:
		static std::vector<Ball> mBall;
		static int idx;
	};
}
