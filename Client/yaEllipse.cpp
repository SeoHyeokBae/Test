#include "yaEllipse.h"
#include "yaTime.h"
#include "yaApplication.h"

namespace ya
{
	std::vector<Ball>yaEllipse::mBall = { };
	int yaEllipse::idx = 0;
	std::queue<int>yaEllipse::col_Ball_idx = { };



	void yaEllipse::Initailize()
	{
		idx++;

		Ball ball = {};
		ball.mBallPos.x = 800.0f;	// �ʱ� ��ġ
		ball.mBallPos.y = 450.0f;
		ball.mAngle = rand() % 360; // ���� ���� ����

		mBall.push_back(ball);
	}

	// ������ �浹 üũ
	bool yaEllipse::CollisionCheck(float cx, float cy)
	{
		// ���� �Ѱ��� 
		if (idx == 1)
		{
			return false;
		}
		else
		{
			for (int i =  1; i < idx; i++)	// ������ ������ ������ �Ÿ� = 2r
			{
				float dX = cx - mBall[i].mBallPos.x;
				float dY = cy - mBall[i].mBallPos.y;
				float dLength = sqrt(dX * dX + dY * dY);

				if (dLength <= 2*BallScale)	// 2r =  2BallScale
				{
					col_Ball_idx.push(i);	// ���� �ε��� ����
					return true;
				}
				else
					continue;
			}
			return false;
		}
	}

	void yaEllipse::Update()
	{
		// �ð�üũ
		static float NewBallTime = 0.0f;
		NewBallTime += Time::DeltaTime();

		// 3�ʸ��� ���ο� �� 
		if (NewBallTime >= 3.0f)
		{
			yaEllipse::Initailize();
			NewBallTime = 0.0f;
		}


		for (int i = 0; i < idx; i++)
		{
			// �浹üũ ( ������ �߽��� ��ǥ �Ķ���� )
			if (yaEllipse::CollisionCheck(mBall[i].mBallPos.x, 
										  mBall[i].mBallPos.y ))
			{
				float temp = mBall[i].mAngle;
				mBall[i].mAngle = mBall[col_Ball_idx.front()].mAngle;
				mBall[col_Ball_idx.front()].mAngle = temp;
				col_Ball_idx.pop();
			}

			// ���� ƨ��� ������ȭ 
			if (mBall[i].mBallPos.y - BallScale < 0)
				mBall[i].mAngle = (mBall[i].mAngle + (-2) * mBall[i].mAngle) % 360;
			if (mBall[i].mBallPos.y + BallScale> 900)
				mBall[i].mAngle = (mBall[i].mAngle + (-2) * mBall[i].mAngle) % 360;
			if (mBall[i].mBallPos.x - BallScale  < 0)
				mBall[i].mAngle = (mBall[i].mAngle + (-2) * (mBall[i].mAngle - 90)) % 360;
			if (mBall[i].mBallPos.x + BallScale > 1600)
				mBall[i].mAngle = (mBall[i].mAngle + (2) * (90 - mBall[i].mAngle)) % 360;
			
			
			mBall[i].mBallPos.x += 400.0f * cos(mBall[i].mAngle * PI / 180) * Time::DeltaTime() ;
			mBall[i].mBallPos.y += 400.0f * (-1)*sin(mBall[i].mAngle * PI / 180) * Time::DeltaTime() ;
		}

	}

	void yaEllipse::Render(HDC hdc)
	{
		for (int i = 0; i < idx; i++)
		{
			Ellipse(hdc,
				mBall[i].mBallPos.x - BallScale,
				mBall[i].mBallPos.y - BallScale,
				mBall[i].mBallPos.x + BallScale,
				mBall[i].mBallPos.y + BallScale);
		}

	}

}
