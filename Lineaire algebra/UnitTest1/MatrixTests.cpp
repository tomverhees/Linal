#include "stdafx.h"
#include "CppUnitTest.h"
#include "TestMatrix.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(MatrixTests)
	{
	public:

		TEST_METHOD(Translate3DTest)
		{
			// TODO: Your test code here
			TestMatrix<float> test = TestMatrix<float>(4, 4);
			test(0, 0) = 10;
			test(0, 1) = 5;
			test(0, 2) = 20;
			test(0, 3) = 1;
			test(1, 0) = 10;
			test(1, 1) = 20;
			test(1, 2) = 40;
			test(1, 3) = 1;
			test(2, 0) = 10;
			test(2, 1) = 25;
			test(2, 2) = 15;
			test(2, 3) = 1;
			test(3, 0) = 5;
			test(3, 1) = 0;
			test(3, 2) = 0;
			test(3, 3) = 1;

			TestMatrix<float> test2 = test * test.translate3d(3, 4, 5);

			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(test(i, 0) + 3, test2(i, 0));
				Assert::AreEqual(test(i, 1) + 4, test2(i, 1));
				Assert::AreEqual(test(i, 2) + 5, test2(i, 2));
			}
		}

		TEST_METHOD(Scale3DTest)
		{
			// TODO: Your test code here
			TestMatrix<float> test = TestMatrix<float>(4, 4);
			test(0, 0) = 10;
			test(0, 1) = 5;
			test(0, 2) = 20;
			test(0, 3) = 1;
			test(1, 0) = 10;
			test(1, 1) = 20;
			test(1, 2) = 40;
			test(1, 3) = 1;
			test(2, 0) = 10;
			test(2, 1) = 25;
			test(2, 2) = 15;
			test(2, 3) = 1;
			test(3, 0) = 5;
			test(3, 1) = 0;
			test(3, 2) = 0;
			test(3, 3) = 1;

			TestMatrix<float> test2 = test * test.scale3d(3, 4, 5);

			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(test(i, 0) * 3, test2(i, 0));
				Assert::AreEqual(test(i, 1) * 4, test2(i, 1));
				Assert::AreEqual(test(i, 2) * 5, test2(i, 2));
			}
		}

		TEST_METHOD(Rotate3DTest)
		{
			// TODO: Your test code here
			TestMatrix<float> test = TestMatrix<float>(4, 3);
			test(0, 0) = 10;
			test(0, 1) = 5;
			test(0, 2) = 20;
			test(1, 0) = 10;
			test(1, 1) = 20;
			test(1, 2) = 40;
			test(2, 0) = 10;
			test(2, 1) = 25;
			test(2, 2) = 15;
			test(3, 0) = 5;
			test(3, 1) = 0;
			test(3, 2) = 0;

			TestMatrix<float> side = test;
			Testvector v1 = Testvector(side(0, 0), side(0, 1), side(0, 2));
			Testvector v2 = Testvector(side(1, 0), side(1, 1), side(1, 2));
			Testvector v3 = Testvector(side(2, 0), side(2, 1), side(2, 2));

			Testvector r1 = v2 - v1;
			Testvector r2 = v3 - v1;
			Testvector normal = r1.crossProduct(r2);
			normal.normalize();

			float centerx = side(1, 0) + (side(2, 0) - side(1, 0)) / 2; //sides[0].getCenter(0);
			float centery = side(1, 1) + (side(2, 1) - side(1, 1)) / 2; //sides[1].getCenter(1);
			float centerz = side(1, 2) + (side(2, 2) - side(1, 2)) / 2; //sides[0].getCenter(2);
			TestMatrix<float> test2 = test.rotate3dall(90, centerx, centery, centerz, normal);

			const float tolerance = 0.0001;
			Assert::AreEqual(10, test2(0, 0), tolerance);
			Assert::AreEqual(15, test2(0, 1), tolerance);
			Assert::AreEqual(45, test2(0, 2), tolerance);
			Assert::AreEqual(10, test2(1, 0), tolerance);
			Assert::AreEqual(35, test2(1, 1), tolerance);
			Assert::AreEqual(30, test2(1, 2), tolerance);
			Assert::AreEqual(10, test2(2, 0), tolerance);
			Assert::AreEqual(10, test2(2, 1), tolerance);
			Assert::AreEqual(25, test2(2, 2), tolerance);
			Assert::AreEqual(5, test2(3, 0), tolerance);
			Assert::AreEqual(-5, test2(3, 1), tolerance);
			Assert::AreEqual(50, test2(3, 2), tolerance);
		}

		TEST_METHOD(MultiplyMatrixTest)
		{
			// TODO: Your test code here
			TestMatrix<float> test = TestMatrix<float>(4, 3);
			test(0, 0) = 10;
			test(0, 1) = 5;
			test(0, 2) = 20;
			test(1, 0) = 10;
			test(1, 1) = 20;
			test(1, 2) = 40;
			test(2, 0) = 10;
			test(2, 1) = 25;
			test(2, 2) = 15;
			test(3, 0) = 5;
			test(3, 1) = 0;
			test(3, 2) = 0;

			TestMatrix<float> test2 = TestMatrix<float>(4, 3);
			test2(0, 0) = 20;
			test2(0, 1) = 20;
			test2(0, 2) = 4;
			test2(1, 0) = 5;
			test2(1, 1) = 3;
			test2(1, 2) = 2;
			test2(2, 0) = 1;
			test2(2, 1) = 4;
			test2(2, 2) = 6;
			test2(3, 0) = 7;
			test2(3, 1) = 9;
			test2(3, 2) = 40;


			TestMatrix<float> test3 = test * test2;

			Assert::AreEqual(252.0f, test3(0, 0));
			Assert::AreEqual(304.0f, test3(0, 1));
			Assert::AreEqual(210.0f, test3(0, 2));
			Assert::AreEqual(347.0f, test3(1, 0));
			Assert::AreEqual(429.0f, test3(1, 1));
			Assert::AreEqual(360.0f, test3(1, 2));
			Assert::AreEqual(347.0f, test3(2, 0));
			Assert::AreEqual(344.0f, test3(2, 1));
			Assert::AreEqual(220.0f, test3(2, 2));
			Assert::AreEqual(107.0f, test3(3, 0));
			Assert::AreEqual(109.0f, test3(3, 1));
			Assert::AreEqual(60.0f, test3(3, 2));
		}


		TEST_METHOD(Camera3DTest)
		{
			// TODO: Your test code here
			TestMatrix<float> test = TestMatrix<float>(4, 3);
			test(0, 0) = 10;
			test(0, 1) = 5;
			test(0, 2) = 20;
			test(1, 0) = 10;
			test(1, 1) = 20;
			test(1, 2) = 40;
			test(2, 0) = 10;
			test(2, 1) = 25;
			test(2, 2) = 15;
			test(3, 0) = 5;
			test(3, 1) = 0;
			test(3, 2) = 0;

			Testvector eye = Testvector(0, 0, 500);
			Testvector lookAt = Testvector(250, 250, 0);
			Testvector up = Testvector(0, 1, 0);
			TestMatrix<float> cameraMatrix = TestMatrix<float>(4, 4);
			TestMatrix<float> perspectionMatrix = TestMatrix<float>(4, 4);
			cameraMatrix = cameraMatrix.generateCameraMatrix(eye, lookAt, up);
			perspectionMatrix = perspectionMatrix.generatePerspectionMatrix(100, 1000, 90);
			TestMatrix<float> displayVector = test * cameraMatrix * perspectionMatrix;
			displayVector.afterCalculation(1200);

			const float tolerance = 0.01;
			Assert::AreEqual(320.93f, displayVector(0, 0), tolerance);
			Assert::AreEqual(365.94f, displayVector(0, 1), tolerance);
			Assert::AreEqual(-441.27f, displayVector(0, 2), tolerance);
			Assert::AreEqual(326.04f, displayVector(1, 0), tolerance);
			Assert::AreEqual(389.02f, displayVector(1, 1), tolerance);
			Assert::AreEqual(-429.93f, displayVector(1, 2), tolerance);
			Assert::AreEqual(326.32f, displayVector(2, 0), tolerance);
			Assert::AreEqual(394.56f, displayVector(2, 1), tolerance);
			Assert::AreEqual(-454.88f, displayVector(2, 2), tolerance);
			Assert::AreEqual(311.60f, displayVector(3, 0), tolerance);
			Assert::AreEqual(358.52f, displayVector(3, 1), tolerance);
			Assert::AreEqual(-454.88f, displayVector(3, 2), tolerance);
		}
	};
}