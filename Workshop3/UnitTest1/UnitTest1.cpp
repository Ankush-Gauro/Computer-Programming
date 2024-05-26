#include "pch.h"
#include "CppUnitTest.h"
#include "customer_r.h"
#include <cstring>
#include <cctype>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTest1
{

	//Whitebox testing for converting to upper case function
	TEST_CLASS(ToUppercaseTest)
	{
	public:

		TEST_METHOD(Test1)
		{
			char postalCode[] = "m2e 4x4";
			ToUppercase(postalCode);
			Assert::AreEqual("M2E 4X4", postalCode);
		}

	};


	//Black box testing for blank input
	TEST_CLASS(BlankLineTesting)
	{
	public:
		TEST_METHOD(Test1)
		{
			bool result = ValidPostalCode("\n");
			Assert::IsFalse(result);
		}
	};


	//Blackbox testing for postal code
	TEST_CLASS(PostalCodeTesting)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			char pos1[] = "M1B 1H6";
			Assert::IsTrue(pos1);
		}
		

		TEST_METHOD(Test2)
		{
			char pos2[] = "m2e4x4";

			Assert::IsTrue(pos2);
		}
	};
}
