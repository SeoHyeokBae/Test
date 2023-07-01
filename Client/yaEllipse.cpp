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
		ball.mAngle = rand() % 360; // 각도 방향 랜덤

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
			// 벽에 튕길시 각도변화 
			if (mBall[i].mStartPos.y - BallScale + mBall[i].mMove.y < 0)
				mBall[i].mAngle = (mBall[i].mAngle + (-2) * mBall[i].mAngle) % 360;
			if (mBall[i].mStartPos.y + 3*BallScale + mBall[i].mMove.y > 900)
				mBall[i].mAngle = (mBall[i].mAngle + (-2) * mBall[i].mAngle) % 360;
			if (mBall[i].mStartPos.x - BallScale + mBall[i].mMove.x < 0)
				mBall[i].mAngle = (mBall[i].mAngle + (-2) * (mBall[i].mAngle - 90)) % 360;
			if (mBall[i].mStartPos.x + BallScale + mBall[i].mMove.x > 1600)
				mBall[i].mAngle = (mBall[i].mAngle + (2) * (90 - mBall[i].mAngle)) % 360;
			
			
			mBall[i].mMove.x += 300.0f * cos(mBall[i].mAngle * PI / 180) * Time::DeltaTime() ;
			mBall[i].mMove.y += 300.0f * (-1)*sin(mBall[i].mAngle * PI / 180) * Time::DeltaTime() ;
		}

	}

	void yaEllipse::Render(HDC hdc)
	{
		for (int i = 0; i < idx; i++)
		{
			Ellipse(hdc,
				mBall[i].mStartPos.x - BallScale + mBall[i].mMove.x,
				mBall[i].mStartPos.y - BallScale + mBall[i].mMove.y,
				mBall[i].mStartPos.x + BallScale + mBall[i].mMove.x,
				mBall[i].mStartPos.y + BallScale + mBall[i].mMove.y);
		}

	}


}
