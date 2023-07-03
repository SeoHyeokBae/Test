#pragma once
#include "CommonInclude.h"
#include <math.h>
#include <queue>
#define BallScale 25 // 공 크기
#define PI 3.141592

namespace ya
{
	using namespace math;

	struct Ball
	{
		Vector2 mBallPos;
		int mAngle;
	};

	class yaEllipse
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		// 공 충돌 체크 함수
		__forceinline static bool CollisionCheck(float cx, float cy);

	private:
		static std::vector<Ball> mBall;
		static int idx;							// 그려줄 공의 인덱스
		static std::queue<int> col_Ball_idx;	// 충돌한 공의 인덱스 저장
	};
}
