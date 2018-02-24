#include "prisma.h"
#include "Bullet.h"


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
	float centerx = sides[2](1,0) + (sides[2](2,0)- sides[2](1,0)) / 2; //sides[0].getCenter(0);
	float centery = sides[2](1, 1) + (sides[2](2, 1) - sides[2](1, 1)) / 2; //sides[1].getCenter(1);
	float centerz = sides[2](1, 2) + (sides[2](2, 2) - sides[2](1, 2)) / 2; //sides[0].getCenter(2);
	Vector front1 = Vector(sides[2](0, 0), sides[2](0, 1), sides[2](0, 2)); 
	Vector front2 = Vector(sides[2](1, 0), sides[2](1, 1), sides[2](1, 2));
	Vector front3 = Vector(sides[2](2, 0), sides[2](2, 1), sides[2](2, 2));
	Vector direction = front1 - front2; 
	Vector direction2 = front2 - front3; 
	Vector normal = direction.crossProduct(direction2); 
	normal.normalize(); 
	for (auto &element : sides)
	{
		element = element.rotate3dall(degrees, centerx, centery, centerz, normal);
	}
}

void prisma::rotateVertical(float degrees)
{
	float centerx = sides[2](1, 0) + (sides[2](2, 0) - sides[2](1, 0)) / 2; //sides[0].getCenter(0);
	float centery = sides[2](1, 1) + (sides[2](2, 1) - sides[2](1, 1)) / 2; //sides[1].getCenter(1);
	float centerz = sides[2](1, 2) + (sides[2](2, 2) - sides[2](1, 2)) / 2; //sides[0].getCenter(2);
	Vector normal = Vector(sides[2](2, 0) - sides[2](1,0), sides[2](2, 1)- sides[2](1,1), sides[2](2, 2)- sides[2](1,2));
	normal.normalize();
	for (auto &element : sides)
	{
		element = element.rotate3dall(degrees, centerx, centery, centerz, normal);
	}
}

void prisma::rotateRoll(float degrees)
{
	float centerx = sides[4](1, 0) + (sides[4](2, 0) - sides[4](1, 0)) / 2; //sides[0].getCenter(0);
	float centery = sides[4](1, 1) + (sides[4](2, 1) - sides[4](1, 1)) / 2; //sides[1].getCenter(1);
	float centerz = sides[4](1, 2) + (sides[4](2, 2) - sides[4](1, 2)) / 2; //sides[0].getCenter(2);
	Vector front1 = Vector(sides[4](0, 0), sides[4](0, 1), sides[4](0, 2));
	Vector front2 = Vector(sides[4](1, 0), sides[4](1, 1), sides[4](1, 2));
	Vector front3 = Vector(sides[4](2, 0), sides[4](2, 1), sides[4](2, 2));
	Vector direction = front1 - front2;
	Vector direction2 = front2 - front3;
	Vector normal = direction.crossProduct(direction2);
	normal.normalize();
	for (auto &element : sides)
	{
		element = element.rotate3dall(degrees, centerx, centery, centerz, normal);
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

Bullet prisma::shoot()
{
	Vector normal = getDirection(3, 1); 
	Matrix<float> bullet1 = Matrix<float>(2,3); 
	bullet1(0, 0) = sides[3](0,0);
	bullet1(0, 1) = sides[3](0, 1); 
	bullet1(0, 2) = sides[3](0, 2); 
	bullet1(1, 0) = sides[3](0, 0) + normal.getDeltaX(); 
	bullet1(1, 1) = sides[3](0, 1) + normal.getDeltaY(); 
	bullet1(1, 2) = sides[3](0, 2) + normal.getDeltaZ();
	Bullet bullet(bullet1); 
	return bullet; 
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