#include "ShotSin.h"
#include "game.h"

namespace
{
	constexpr float kShotSpeed = 8.0f;
}

ShotSin::ShotSin()
{
	m_sinRate = 0;
}


void ShotSin::start(Vec2 pos)
{
	ShotBase::start(pos);
	m_vec.x = kShotSpeed;
	m_vec.y = 0.0f;

	m_basePos = m_pos;
}

void ShotSin::update()
{
	// サインカーブの弾
	m_basePos += m_vec;
	m_sinRate += 0.50f;

	m_pos = m_basePos;
	
	m_pos.y += sinf(m_sinRate) * 50.0f;
	
	// 画面外に出たら弾を回収
	if (!m_isExist) return;
	m_pos += m_vec;
	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}