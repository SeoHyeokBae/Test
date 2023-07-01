#include "yaEllipse.h"
#include "yaTime.h"

namespace ya
{
	std::vector<Ball>yaEllipse::mBall = { };
	int yaEllipse::idx = 0;

	void yaEllipse::Initailize()
	{
		idx++;

		Ball ball = {};
		ball.mStartPos.x = 800.0f;
		ball.mStartPos.y = 450.0f;
		ball.dire.x = rand() % 3;
		ball.dire.y = rand() % 3;

		// 초기 방향 설정
		if (ball.dire.x == 1)
		{
			ball.dire.x = 1;
		}
		else if (ball.dire.x == 2)
		{
			ball.dire.x = -1;
		}

		if (ball.dire.y == 1)
		{
			ball.dire.y = 1;
		}
		else if (ball.dire.y == 2)
		{
			ball.dire.y = -1;
		}

		mBall.push_back(ball);
	}

	void yaEllipse::Update()
	{
		// 시간체크
		static float NewBallTime = 0.0f;
		NewBallTime += Time::DeltaTime();

		// 5초후 새로운 공 
		if (NewBallTime >= 5.0f)
		{
			yaEllipse::Initailize();
			NewBallTime = 0.0f;
		}

		for (int i = 0; i < idx; i++)
		{
			mBall[i].mMove.x += 100.0f * Time::DeltaTime() * mBall[i].dire.x;
			mBall[i].mMove.y += 100.0f * Time::DeltaTime() * mBall[i].dire.y;
		}

	}

	void yaEllipse::Render(HDC hdc)
	{
		for (int i = 0; i < idx; i++)
		{
			Ellipse(hdc,
				mBall[i].mStartPos.x - 25 + mBall[i].mMove.x,
				mBall[i].mStartPos.y - 25 + mBall[i].mMove.y,
				mBall[i].mStartPos.x + 25 + mBall[i].mMove.x,
				mBall[i].mStartPos.y + 25 + mBall[i].mMove.y);
		}

	}

}
