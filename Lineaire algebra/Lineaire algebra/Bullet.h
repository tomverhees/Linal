#pragma once
#include "Matrix.h"

class Bullet : public IGameObject
{
public:
	Bullet(Matrix<float> start);
	~Bullet();
	void Update(float deltaTime) override;
	void Draw() override;
	Matrix<float>& getMatrix();
private : 
	Matrix<float> matrix; 
};

