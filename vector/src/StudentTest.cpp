#include "pch.h"
#include "CppUnitTest.h"
#include "Studentas.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentTest
{
	TEST_CLASS(StudentTest)
	{
	public:
		
		TEST_METHOD(DefaultConstructor)
		{
			Studentas A;

			std::string expected = "\t\t0\t0\t\t0.0\t0.0\t0.0";

			Assert::AreEqual(expected, A.output());

		}
		
	};
}
