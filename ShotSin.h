#pragma once

#include  "ShotBase.h"

class ShotSin : public ShotBase
{
public:
	ShotSin();
	virtual ~ShotSin(){}

	// �V���b�g�J�n
	virtual void start(Vec2 pos);

	// �X�V
	virtual void update();

private:
	Vec2 m_basePos;
	float m_sinRate;

};