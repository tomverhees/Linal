#pragma once
#include <vector>
#include "Matrix.h"

class prisma : public IGameObject
{
public:
	prisma();
	~prisma();
	void createPrisma();
	void Update(float deltaTime) override;
	std::vector<Matrix<float>>& getSides();
	void rotate(float degrees);
	void move(float movex, float movey);

private: 
	std::vector<Matrix<float>> sides; 


};

