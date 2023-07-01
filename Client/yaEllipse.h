#pragma once
#include "CommonInclude.h"
#include <math.h>
#define BallScale 25 // °ø Å©±â
#define PI 3.141592

namespace ya
{
	using namespace math;

	struct Ball
	{
		Vector2 mStartPos;
		Vector2 mMove;
		int mAngle;
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
