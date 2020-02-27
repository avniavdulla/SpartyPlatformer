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
		
		TEST_METHOD(TestCScoreboardConstruct)
		{
			CGame game;
			CScoreboard board;
		}

		TEST_METHOD(TestCScoreboardReset)
		{
			CGame game;
			game.Load(1);
			// Assert scoreboard starts at 0
			Assert::IsTrue(game.GetScoreboard()->GetScore() == 0);

			game.GetScoreboard()->AddScore(300);

			// Assert scoreboard has updated
			Assert::IsTrue(game.GetScoreboard()->GetScore() == 300);

			game.Load(1);

			// Assert scoreboard resets on game load
			Assert::IsTrue(game.GetScoreboard()->GetScore() == 0);
		}
	};
}