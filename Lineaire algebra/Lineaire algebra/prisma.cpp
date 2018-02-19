#include "prisma.h"



prisma::prisma()
{
	createPrisma();
}


prisma::~prisma()
{
}

void prisma::createPrisma()
{
	Matrix<float> testbottom = Matrix<float>(4, 3);
	testbottom(0, 0) = 0;
	testbottom(0, 1) = 0;
	testbottom(0, 2) = 0;
	testbottom(1, 0) = 40;
	testbottom(1, 1) = 0;
	testbottom(1, 2) = 0;
	testbottom(2, 0) = 40;
	testbottom(2, 1) = 0;
	testbottom(2, 2) = 20;
	testbottom(3, 0) = 0;
	testbottom(3, 1) = 0;
	testbottom(3, 2) = 20;
	sides.push_back(testbottom);

	Matrix<float> testright = Matrix<float>(4, 3);
	testright(0, 0) = 40;
	testright(0, 1) = 0;
	testright(0, 2) = 0;
	testright(1, 0) = 40;
	testright(1, 1) = 0;
	testright(1, 2) = 20;
	testright(2, 0) = 40;
	testright(2, 1) = 20;
	testright(2, 2) = 20;
	testright(3, 0) = 40;
	testright(3, 1) = 20;
	testright(3, 2) = 0;
	sides.push_back(testright);

	Matrix<float> testfront = Matrix<float>(4, 3);
	testfront(0, 0) = 40;
	testfront(0, 1) = 0;
	testfront(0, 2) = 0;
	testfront(1, 0) = 40;
	testfront(1, 1) = 20;
	testfront(1, 2) = 0;
	testfront(2, 0) = 0;
	testfront(2, 1) = 20;
	testfront(2, 2) = 0;
	testfront(3, 0) = 0;
	testfront(3, 1) = 0;
	testfront(3, 2) = 0;
	sides.push_back(testfront);

	Matrix<float> testback = Matrix<float>(4, 3);
	testback(0, 0) = 40;
	testback(0, 1) = 0;
	testback(0, 2) = 20;
	testback(1, 0) = 40;
	testback(1, 1) = 20;
	testback(1, 2) = 20;
	testback(2, 0) = 0;
	testback(2, 1) = 20;
	testback(2, 2) = 20;
	testback(3, 0) = 0;
	testback(3, 1) = 0;
	testback(3, 2) = 20;
	sides.push_back(testback);

	Matrix<float> testleft = Matrix<float>(4, 3);
	testleft(0, 0) = 0;
	testleft(0, 1) = 0;
	testleft(0, 2) = 0;
	testleft(1, 0) = 0;
	testleft(1, 1) = 0;
	testleft(1, 2) = 20;
	testleft(2, 0) = 0;
	testleft(2, 1) = 20;
	testleft(2, 2) = 20;
	testleft(3, 0) = 0;
	testleft(3, 1) = 20;
	testleft(3, 2) = 0;
	sides.push_back(testleft);
}

std::vector<Matrix<float>>& prisma::getSides()
{
	return sides;
}

void prisma::Update(float deltaTime)
{
}

void prisma::rotate(float degrees)
{
	for (auto &element : sides)
	{
		element = element.rotate3dall(degrees, 20, 10, 10);
	}
}

void prisma::move(float movex, float movey)
{
	if (movex != 0)
	{
		Vector normal = getDirection(4, movex);
		for (int i = 0; i < sides.size(); i++) {
			sides[i] = sides[i] * sides[3].translate3d(normal.getDeltaX(), normal.getDeltaY(), normal.getDeltaZ());
		}
	}

	if (movey != 0)
	{
		Vector normal = getDirection(3, movey);
		for (int i = 0; i < sides.size(); i++) {
			sides[i] = sides[i] * sides[4].translate3d(normal.getDeltaX(), normal.getDeltaY(), normal.getDeltaZ());
		}
	}
}

Vector& prisma::getDirection(int sideIndex, float move)
{
	Matrix<float> side = sides[sideIndex];
	Vector v1 = Vector(side(0, 0), side(0, 1), side(0, 2));
	Vector v2 = Vector(side(1, 0), side(1, 1), side(1, 2));
	Vector v3 = Vector(side(2, 0), side(2, 1), side(2, 2));

	Vector r1 = v2 - v1;
	Vector r2 = v3 - v1;
	Vector normal = r1.crossProduct(r2);
	normal.normalize();
	normal.scaleVector(move, move, move);

	return normal;
}