#include "stdafx.h"
#include "CppUnitTest.h"
#include "Testvector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(VectorTests)
	{
	public:

		TEST_METHOD(NormalizeTests)
		{
			// TODO: Your test code here
			Testvector test = Testvector(5, 3, 8);

			test.normalize();

			float tolerance = 0.01;
			Assert::AreEqual(0.51f, test.getDeltaX(), tolerance);
			Assert::AreEqual(0.30f, test.getDeltaY(), tolerance);
			Assert::AreEqual(0.81f, test.getDeltaZ(), tolerance);
		}

		TEST_METHOD(InProductTest)
		{
			// TODO: Your test code here
			Testvector test = Testvector(5, 3, 8);
			Testvector test2 = Testvector(8, 7, 2);

			float test3 = test.inProduct(test2);

			Assert::AreEqual(77.0f, test3);
		}

		TEST_METHOD(CrossProductTest)
		{
			// TODO: Your test code here
			Testvector test = Testvector(5, 3, 8);
			Testvector test2 = Testvector(3, 6, 4);

			Testvector test3 = test.crossProduct(test2);

			Assert::AreEqual(-36.0f, test3.getDeltaX());
			Assert::AreEqual(4.0f, test3.getDeltaY());
			Assert::AreEqual(21.0f, test3.getDeltaZ());
		}
	};
}