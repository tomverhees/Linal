#pragma once
#include <vector>
#include "Matrix.h"
#include "Bullet.h"

class Prisma : public IGameObject
{
public:
	Prisma();
	~Prisma();
	void createPrisma();
	void Update(float deltaTime) override;
	std::vector<Matrix<float>>& getSides();
	void rotate(float degrees);
	void rotateVertical(float degrees);
	void rotateRoll(float degrees);
	void move(float movex, float movey);
	Bullet shoot();

	Vector& getDirection(int sideIndex, float move = 1);

private: 
	std::vector<Matrix<float>> sides; 


};

