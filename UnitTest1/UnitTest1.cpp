#define CATCH_CONFIG_MAIN

#include "pch.h"
#include "CppUnitTest.h"
#include "../6.2i/6.2i.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = nullptr, * last = nullptr;
			enqueue(first, last, 1);
			enqueue(first, last, 2);
			remove(first, 1);
			Assert::AreEqual(first->info , 2);
		}
	};
}
