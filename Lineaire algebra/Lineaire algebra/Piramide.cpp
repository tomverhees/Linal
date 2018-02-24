#include "Piramide.h"
#include <chrono>


Piramide::Piramide()
{
	createPiramide(80, 80, 80, 40, 40, 40);
	scaleFactor_ = 0.99; 
	startTime_ = std::chrono::system_clock::now();
}


Piramide::~Piramide()
{
}

void Piramide::createPiramide(int depth, int width, int height, int startX, int startY, int startZ)
{
	Matrix<float> testbottom = Matrix<float>(4, 3);
	testbottom(0, 0) = startX;
	testbottom(0, 1) = startY;
	testbottom(0, 2) = startZ;
	testbottom(1, 0) = startX + width;
	testbottom(1, 1) = startY;
	testbottom(1, 2) = startZ;
	testbottom(2, 0) = startX + width;
	testbottom(2, 1) = startY;
	testbottom(2, 2) = startZ + depth;
	testbottom(3, 0) = startX;
	testbottom(3, 1) = startY;
	testbottom(3, 2) = startZ + depth;
	sides.push_back(testbottom);

	Matrix<float> testright = Matrix<float>(3, 3);
	testright(0, 0) = startX + width;
	testright(0, 1) = startY;
	testright(0, 2) = startZ;
	testright(1, 0) = startX + width;
	testright(1, 1) = startY;
	testright(1, 2) = startZ + depth;
	testright(2, 0) = startX + width / 2;
	testright(2, 1) = startY - height;
	testright(2, 2) = startZ + depth / 2;
	sides.push_back(testright);

	Matrix<float> testfront = Matrix<float>(3, 3);
	testfront(0, 0) = startX;
	testfront(0, 1) = startY;
	testfront(0, 2) = startZ;
	testfront(1, 0) = startX + width;
	testfront(1, 1) = startY;
	testfront(1, 2) = startZ;
	testfront(2, 0) = startX + width / 2;
	testfront(2, 1) = startY - height;
	testfront(2, 2) = startZ + depth / 2;
	sides.push_back(testfront);

	Matrix<float> testback = Matrix<float>(3, 3);
	testback(0, 0) = startX;
	testback(0, 1) = startY;
	testback(0, 2) = startZ + depth;
	testback(1, 0) = startX + width;
	testback(1, 1) = startY;
	testback(1, 2) = startZ + depth;
	testback(2, 0) = startX + width / 2;
	testback(2, 1) = startY - height;
	testback(2, 2) = startZ + depth / 2;
	sides.push_back(testback);

	Matrix<float> testleft = Matrix<float>(3, 3);
	testleft(0, 0) = startX;
	testleft(0, 1) = startY;
	testleft(0, 2) = startZ;
	testleft(1, 0) = startX;
	testleft(1, 1) = startY;
	testleft(1, 2) = startZ + depth;
	testleft(2, 0) = startX + width / 2;
	testleft(2, 1) = startY - height;
	testleft(2, 2) = startZ + depth / 2;
	sides.push_back(testleft);
}

std::vector<Matrix<float>>& Piramide::getSides()
{
	return sides;
}

void Piramide::Update(float deltaTime)
{
	Pulsesate();
}


void Piramide::Pulsesate()
{
	std::chrono::duration<double> time = std::chrono::system_clock::now() - startTime_;
	if(time.count() > 0.5)
	{
		startTime_ = std::chrono::system_clock::now(); 
		scaleFactor_ = 2 - scaleFactor_; 
	}
	for (auto &element : sides)
	{
		element = element * element.translate3d(-40, -40, 0) * element.scale3d(scaleFactor_, scaleFactor_,scaleFactor_) * element.translate3d(40,40,0); 
	}
}
