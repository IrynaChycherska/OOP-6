#include "pch.h"
#include "CppUnitTest.h"
#include"../6.1/Array.h"
#include"../6.1/Array.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61
{
	TEST_CLASS(UnitTest61)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Array Test = Array(49);
			for (int i = 0; i < 49; i++)
				Test[i] = 0;
			Test[18] = -50;

			Assert::AreEqual(Test.Min(), -50.);
		}
	};
}
