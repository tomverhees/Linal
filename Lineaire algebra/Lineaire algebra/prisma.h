#pragma once
#include <vector>
#include "Matrix.h"
#include "Bullet.h"

class prisma : public IGameObject
{
public:
	prisma();
	~prisma();
	void createPrisma();
	void Update(float deltaTime) override;
	std::vector<Matrix<float>>& getSides();
	void rotate(float degrees);
	void rotateVertical(float degrees);
	void rotateRoll(float degrees);
	void move(float movex, float movey);
	Bullet shoot();

	Vector& getDirection(int sideIndex, float move);

private: 
	std::vector<Matrix<float>> sides; 


};

