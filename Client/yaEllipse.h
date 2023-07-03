#pragma once
#include "CommonInclude.h"
#include <math.h>
#include <queue>
#define BallScale 25 // �� ũ��
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

		// �� �浹 üũ �Լ�
		__forceinline static bool CollisionCheck(float cx, float cy);

	private:
		static std::vector<Ball> mBall;
		static int idx;							// �׷��� ���� �ε���
		static std::queue<int> col_Ball_idx;	// �浹�� ���� �ε��� ����
	};
}
