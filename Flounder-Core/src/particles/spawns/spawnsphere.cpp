﻿#include "spawnsphere.hpp"

namespace flounder
{
	spawnsphere::spawnsphere(const float &radius, const vector3 &heading) :
		ispawnparticle(),
		m_radius(radius),
		m_spawnPosition(new vector3())
	{
	}

	spawnsphere::~spawnsphere()
	{
		delete m_spawnPosition;
	}

	vector3 *spawnsphere::getBaseSpawnPosition()
	{
		vector3::generateRandomUnitVector(m_spawnPosition);

		m_spawnPosition->scale(m_radius);
		float a = maths::randomInRange(0.0f, 1.0f);
		float b = maths::randomInRange(0.0f, 1.0f);

		if (a > b)
		{
			float temp = a;
			a = b;
			b = temp;
		}

		float randX = b * cos(2.0f * PI * (a / b));
		float randY = b * sin(2.0f * PI * (a / b));
		float distance = vector2(randX, randY).length();
		m_spawnPosition->scale(distance);
		return m_spawnPosition;
	}
}