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

		TEST_METHOD(ParamtericConstructor) {
			{
				Studentas A("Jonas", "Jonaitis", 3, 9, { 1, 5, 4 }, 9.0, 9.4, 9.0);
				std::string expected = "Jonas\tJonaitis\t3\t9\t1 5 4 \t9.0\t9.4\t9.0";

				Assert::AreEqual(expected, A.output());
			}

		}
		
	};
}
