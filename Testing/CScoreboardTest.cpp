#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Level.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CScoreboardTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCScordboardConstruct)
		{
			CGame game;
			CScoreboard board;
		}

	};
}