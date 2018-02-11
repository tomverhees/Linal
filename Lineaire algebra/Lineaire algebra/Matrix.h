#pragma once
#include "Vector.h"
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
template<typename T>
class Matrix : public IGameObject
{
private:
	std::vector<T> array;
	int x;
	int y;
public:
	Matrix(int x1, int y2) : x(x1), y(y2), array(x1 * y2)
	{
	}
	~Matrix()
	{
		array.clear();
	}
	T& operator()(int x, int y) {
		return array[(this->y* x) + y];
	}
	Matrix Matrix::operator*(const Matrix& other)
	{
		if (other.ylength() == 4 && this->xlength() == 4)
		{
			return this->multiplyMatrices4X4(other);
		}
		else if (other.ylength() == 3 && this->xlength() == 3)
		{
			return this->multiplyMatrices3X3(other);
		}
		else if (other.ylength() == 2 && this->xlength() == 2)
		{
			return this->multiplyMatrices2X2(other);
		}
		else
		{
			throw std::exception("The matrix was not compatible");
		}
	}
	Matrix rotateMatrix(float degrees)
	{
		float radians = degrees * (M_PI / 180);
		Matrix scale = Matrix(2, 2);
		scale(0, 0) = cos(radians);
		scale(0, 1) = sin(radians);
		scale(1, 0) = -sin(radians);
		scale(1, 1) = cos(radians);
		return scale;
	}
	Matrix rotateMatrixwp(float degrees)
	{
		float radians = degrees * (M_PI / 180);
		Matrix scale = Matrix(3, 3);
		scale(0, 0) = cos(radians);
		scale(0, 1) = sin(radians);
		scale(1, 0) = -sin(radians);
		scale(1, 1) = cos(radians);
		scale(2, 0) = 0;
		scale(2, 1) = 0;
		scale(2, 2) = 1;
		scale(0, 2) = 0;
		scale(1, 2) = 0;
		return scale;
	}
	Matrix rotate(float degrees, float x = 0, float y = 0)
	{
		Matrix product = Matrix(3, 3);
		if (x == 0 && y == 0)
		{
			product = (*this) * rotateMatrix(degrees);
		}
		else
		{
			Matrix extra = Matrix(3, 3);
			for (int l = 0; l < this->xlength(); l++)
			{
				for (int n = 0; n < this->ylength(); n++)
				{
					extra(l, n) = array[this->ylength() * l + n];
				}
			}
			for (int m = 0; m < this->xlength(); m++) {
				extra(m, 2) = 1;
			}
			product = translate2d(x, y) * (rotateMatrixwp(degrees) * (translate2d(-x, -y) * extra));
		}
		return product;
	}

	Matrix rotate3dO(float degrees, float x, float y, float z)
	{
		Matrix product = Matrix(4, 4);
		Matrix temp = Matrix(4, 4);
		float t1 = atan2(z, x);
		auto t2 = atan2(y, sqrt((x*x) + (z*z)));
		temp = (*this) * InverseRotateY(t1);
		temp = temp * InverseRotateZ(t2);
		temp = temp * rotateX(degrees);
		temp = temp * rotateZ(t2);
		product = temp * rotateY(t1);
		return product;
	}
	Matrix multiplyMatrices2X2(const Matrix& multiplierMatrix)
	{
		Matrix matrix = (*this);
		Matrix multiplyingMatrixPoints = multiplierMatrix;
		if (multiplyingMatrixPoints.ylength() != 2 || matrix.xlength() != 2)
		{
			throw std::exception("MatrixHelper::multiplyMatrices2X2 >> multiplierMatrix must have exactly 2 points (columns).");
		}
		int k = 0;
		Matrix product = Matrix(multiplierMatrix.xlength(), matrix.ylength());
		for (int i = 0; i < multiplyingMatrixPoints.ylength(); i++)
		{
			for (int l = 0; l < multiplyingMatrixPoints.xlength(); l++)
			{
				for (int n = 0; n < matrix.ylength(); n++)
				{
					k += multiplyingMatrixPoints(l, n) * matrix.array[(ylength() * n) + i];
				}
				product(l, i) = k;
				k = 0;
			}
		}
		return product;
	}
	Matrix multiplyMatrices3X3(const Matrix& multiplierMatrix)
	{
		Matrix matrix = (*this);
		Matrix multiplyingMatrixPoints = multiplierMatrix;
		if (multiplyingMatrixPoints.ylength() != 3 || matrix.xlength() != 3)
		{
			throw std::exception("MatrixHelper::multiplyMatrices3X3 >> multiplierMatrix must have exactly 3 points (columns).");
		}
		int k = 0;
		Matrix product = Matrix(multiplierMatrix.xlength(), matrix.ylength());
		for (int i = 0; i < multiplyingMatrixPoints.ylength(); i++)
		{
			for (int l = 0; l < multiplyingMatrixPoints.xlength(); l++)
			{
				for (int n = 0; n < matrix.ylength(); n++)
				{
					k += multiplyingMatrixPoints(l, n) * matrix.array[(ylength() * n) + i];
				}
				product(l, i) = k;
				k = 0;
			}
		}
		return product;
	}
	Matrix multiplyMatrices4X4(const Matrix& multiplierMatrix)
	{
		Matrix matrix = (*this);
		Matrix multiplyingMatrixPoints = multiplierMatrix;
		if (multiplyingMatrixPoints.ylength() != 4 || matrix.xlength() != 4)
		{
			throw std::exception("MatrixHelper::multiplyMatrices4X4 >> multiplierMatrix must have exactly 4 points (columns).");
		}
		int k = 0;
		Matrix product = Matrix(multiplierMatrix.xlength(), matrix.ylength());
		for (int i = 0; i < multiplyingMatrixPoints.ylength(); i++)
		{
			for (int l = 0; l < multiplyingMatrixPoints.xlength(); l++)
			{
				for (int n = 0; n < matrix.ylength(); n++)
				{
					k += multiplyingMatrixPoints(l, n) * matrix.array[(ylength() * n) + i];
				}
				product(l, i) = k;
				k = 0;
			}
		}
		return product;
	}
	Matrix rotate3dall(float degrees, float x, float y, float z)
	{
		Matrix product = Matrix(4, 4);
		Matrix temp = Matrix(4, 4);
		float t1 = atan2(z, x);
		auto t2 = atan2(y, sqrt((x*x) + (z*z)));
		temp = (*this) * translate3d(-x, -y, -z);
		temp = temp * rotate3dO(degrees, x, y, z);
		product = temp * translate3d(-x, -y, -z);
		return product;
	}
	Matrix rotateX(float degrees)
	{
		float radians = degrees * M_PI / 180;
		Matrix scale = Matrix(4, 4);
		scale(0, 0) = 1;
		scale(0, 1) = 0;
		scale(0, 2) = 0;
		scale(0, 3) = 0;
		scale(1, 0) = 0;
		scale(1, 1) = cos(radians);
		scale(1, 2) = sin(radians);
		scale(1, 3) = 0;
		scale(2, 0) = 0;
		scale(2, 1) = -sin(radians);
		scale(2, 2) = cos(radians);
		scale(2, 3) = 0;
		scale(3, 3) = 1;
		return scale;
	}
	Matrix rotateY(float radians)
	{
		//float radians = degrees * M_PI / 180;
		Matrix scale = Matrix(4, 4);
		scale(0, 0) = cos(radians);
		scale(0, 1) = 0;
		scale(0, 2) = sin(radians);
		scale(0, 3) = 0;
		scale(1, 0) = 0;
		scale(1, 1) = 1;
		scale(1, 2) = 0;
		scale(1, 3) = 0;
		scale(2, 0) = -sin(radians);
		scale(2, 1) = 0;
		scale(2, 2) = cos(radians);
		scale(2, 3) = 0;
		scale(3, 3) = 1;
		return scale;
	}
	Matrix InverseRotateY(float radians)
	{
		//float radians = degrees * M_PI / 180;
		Matrix scale = Matrix(4, 4);
		scale(0, 0) = cos(radians);
		scale(0, 1) = 0;
		scale(0, 2) = -sin(radians);
		scale(0, 3) = 0;
		scale(1, 0) = 0;
		scale(1, 1) = 1;
		scale(1, 2) = 0;
		scale(1, 3) = 0;
		scale(2, 0) = sin(radians);
		scale(2, 1) = 0;
		scale(2, 2) = cos(radians);
		scale(2, 3) = 0;
		scale(3, 3) = 1;
		return scale;
	}
	Matrix rotateZ(float radians)
	{
		//float radians = degrees * M_PI / 180;
		Matrix scale = Matrix(4, 4);
		scale(0, 0) = cos(radians);
		scale(0, 1) = sin(radians);
		scale(0, 2) = 0;
		scale(1, 0) = -sin(radians);

		scale(1, 1) = cos(radians);
		scale(1, 2) = 0;
		scale(2, 0) = 0;
		scale(2, 1) = 0;
		scale(2, 2) = 1;
		scale(3, 3) = 1;
		return scale;
	}
	Matrix InverseRotateZ(float radians)
	{
		//float radians = degrees * M_PI / 180;
		Matrix scale = Matrix(4, 4);
		scale(0, 0) = cos(radians);
		scale(0, 1) = -sin(radians);
		scale(0, 2) = 0;
		scale(1, 0) = sin(radians);
		scale(2, 0) = 0;
		scale(1, 1) = cos(radians);
		scale(1, 2) = 0;
		scale(2, 1) = 0;
		scale(2, 2) = 1;
		scale(3, 3) = 1;
		return scale;
	}
	Matrix scale2d(float scalex, float scaley)
	{
		Matrix scale = Matrix(2, 2);
		scale(0, 0) = scalex;
		scale(1, 1) = scaley;
		return scale;
	}
	Matrix scale3d(float scalex, float scaley, float scalez)
	{
		Matrix scale = Matrix(4, 4);
		scale(0, 0) = scalex;
		scale(1, 1) = scaley;
		scale(2, 2) = scalez;
		scale(3, 3) = 1;
		return scale;
	}
	Matrix translate2d(float transx, float transy)
	{
		Matrix scale = Matrix(3, 3);
		scale(0, 0) = 1;
		scale(1, 1) = 1;
		scale(2, 2) = 1;
		scale(2, 0) = transx;
		scale(2, 1) = transy;
		return scale;
	}
	Matrix translate3d(float transx, float transy, float transz)
	{
		Matrix scale = Matrix(4, 4);
		scale(0, 0) = 1;
		scale(1, 1) = 1;
		scale(2, 2) = 1;
		scale(3, 3) = 1;
		scale(3, 0) = transx;
		scale(3, 1) = transy;
		scale(3, 2) = transz;
		return scale;
	}
	int xlength() const
	{
		return x;
	}
	int ylength() const
	{
		return y;
	}
	std::vector<T> getMatrix()
	{
		return array;
	}
	void Update(float deltaTime) override
	{

	}
	void Draw() override
	{
		for (int i = 0; i < x; i++)
		{
			if (i < x - 1)
			{
				mApplication->SetColor(Color(0, 0, 0, 0));
				mApplication->DrawLine(this->operator()(i, 0) * 10, this->operator()(i, 1) * 10, this->operator()(i + 1, 0) * 10, this->operator()(i + 1, 1) * 10);
				mApplication->SetColor(Color(255, 255, 255, 255));
			}
			else
			{
				mApplication->SetColor(Color(0, 0, 0, 0));
				mApplication->DrawLine(this->operator()(i, 0) * 10, this->operator()(i, 1) * 10, this->operator()(0, 0) * 10, this->operator()(0, 1) * 10);
				mApplication->SetColor(Color(255, 255, 255, 255));
			}
		}
	}

	Matrix generateCameraMatrix(Vector eye, Vector lookAt, Vector up)
	{
		Vector z = eye - lookAt;
		z.normalize();

		Vector y = up;
		y.normalize();

		Vector x = y.crossProduct(z);
		x.normalize();

		y = z.crossProduct(y);
		y.normalize();

		float inProductX = x.inProduct(eye) * -1;
		float inProductY = y.inProduct(eye) * -1;
		float inProductZ = z.inProduct(eye) * -1;

		Matrix cameraMatrix = Matrix(4, 4);
		cameraMatrix(0, 0) = x.getDeltaX();
		cameraMatrix(0, 1) = y.getDeltaX();
		cameraMatrix(0, 2) = z.getDeltaX();
		cameraMatrix(0, 3) = 0;
		cameraMatrix(1, 0) = x.getDeltaY();
		cameraMatrix(1, 1) = y.getDeltaY();
		cameraMatrix(1, 2) = z.getDeltaY();
		cameraMatrix(1, 3) = 0;
		cameraMatrix(2, 0) = x.getDeltaZ();
		cameraMatrix(2, 1) = y.getDeltaZ();
		cameraMatrix(2, 2) = z.getDeltaZ();
		cameraMatrix(2, 3) = 0;
		cameraMatrix(3, 0) = inProductX;
		cameraMatrix(3, 1) = inProductY;
		cameraMatrix(3, 2) = inProductZ;
		cameraMatrix(3, 3) = 1;

		return cameraMatrix;
	}

	Matrix generatePerspectionMatrix(float near, float far, float fieldOfView)
	{
		const float scale = near * tan((fieldOfView / 180.0 * M_PI) * .5);

		const float matrix2_2 = (far * -1) / (far - near);
		const float matrix2_3 = (far * -1 * near) / (far - near);

		Matrix perspectionMatrix = Matrix(4, 4);
		perspectionMatrix(0, 0) = scale;
		perspectionMatrix(0, 1) = 0;
		perspectionMatrix(0, 2) = 0;
		perspectionMatrix(0, 3) = 0;
		perspectionMatrix(1, 0) = 0;
		perspectionMatrix(1, 1) = scale;
		perspectionMatrix(1, 2) = 0;
		perspectionMatrix(1, 3) = 0;
		perspectionMatrix(2, 0) = 0;
		perspectionMatrix(2, 1) = 0;
		perspectionMatrix(2, 2) = matrix2_2;
		perspectionMatrix(2, 3) = matrix2_3;
		perspectionMatrix(3, 0) = 0;
		perspectionMatrix(3, 1) = 0;
		perspectionMatrix(3, 2) = -1;
		perspectionMatrix(3, 3) = 0;

		return perspectionMatrix;
	}

	void afterCalculation(float screenSize)
	{
		for (int i = 0; i < x; i++)
		{
			this->operator()(0, i) = (screenSize / 2) + ((this->operator()(0, i) + 1) / this->operator()(3, i)) * screenSize * 0.5;
			this->operator()(1, i) = (screenSize / 2) + ((this->operator()(1, i) + 1) / this->operator()(3, i)) * screenSize * 0.5;
			this->operator()(2, i) *= -1;
		}
	}

	Matrix generate3dMatrix(float screenSize)
	{
		Matrix matrix3d = (*this) * (generatePerspectionMatrix(0, 0, 0) * generateCameraMatrix(Vector(0, 0, 0), Vector(0, 0, 0), Vector(0, 0, 0)));
		matrix3d.afterCalculation(screenSize);
		return matrix3d;
	}
};

