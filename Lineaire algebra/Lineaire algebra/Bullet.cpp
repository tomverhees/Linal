#include "Bullet.h"
#include "Matrix.h"


Bullet::Bullet(Matrix<float> start): matrix(start)
{
}


Bullet::~Bullet()
{
}

void Bullet::Draw()
{
	matrix.Draw();
}


void Bullet::Update(float deltaTime)
{
	matrix = matrix * matrix.translate3d(matrix(1, 0) - matrix(0, 0), matrix(1, 1) - matrix(0, 1), matrix(1, 2) - matrix(0, 2));
}

Matrix<float>& Bullet::getMatrix()
{
	return matrix;
}
