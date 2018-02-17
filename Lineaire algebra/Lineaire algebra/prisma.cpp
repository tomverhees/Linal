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
	move(1, 1);
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
	for (auto &element : sides)
	{
		element = element * element.translate3d(movex, movey,0); 
	}
}