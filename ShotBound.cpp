#include "ShotBound.h"
#include "game.h"
#include "DxLib.h"

namespace
{
	constexpr float kShotSpeed = 3.0f;

	// 跳ね返る回数
	constexpr int kboundMax = 3;

	// グラフィックデータのサイズ
	constexpr int kSizeX = 16;
	constexpr int kSizeY = 16;
}


void ShotBound::start(Vec2 pos)
{
	ShotBase::start(pos);

	float randAngle = static_cast<float>(GetRand(359));
	float rad = randAngle * DX_PI_F / 180.0;	// ラジアンに変更  DX_PI = 



	m_vec.x = cosf(rad) * kShotSpeed;
	m_vec.y = sinf(rad) * kShotSpeed;
	m_vec *= kShotSpeed;

	m_boundCount = 0;
}

void ShotBound::update()
{
	// 画面外に出たら弾を回収
	if (!m_isExist) return;
	m_pos += m_vec;

	if (m_boundCount <= kboundMax)
	{
		if (m_pos.x < 0.0f)
		{
			m_pos.x = 0.0f;
			m_vec.x *= -1.0f;
			m_boundCount++;
		}
		if (m_pos.y < 0.0f)
		{
			m_pos.y = 0.0f;
			m_vec.y *= -1.0f;
			m_boundCount++;
		}
		if (m_pos.x > Game::kScreenWidth - kSizeX)
		{
			m_pos.x = Game::kScreenWidth - kSizeX;
			m_vec.x *= -1.0f;
			m_boundCount++;
		}
		if (m_pos.y > Game::kScreenHeight- kSizeY)
		{
			m_pos.y = Game::kScreenHeight - kSizeY;
			m_vec.y *= -1.0f;
			m_boundCount++;
		}
	}
	else
	{
		// 画面外に行ったショットの終了処理
		if (m_pos.x < (0 - kSizeX))
		{
			m_isExist = false;
		}
		if (m_pos.y < (0 - kSizeY))
		{
			m_isExist = false;
		}
		if (m_pos.x > Game::kScreenWidth)
		{
			m_isExist = false;
		}
		if (m_pos.y > Game::kScreenHeight)
		{
			m_isExist = false;
		}



	}

	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}

}
