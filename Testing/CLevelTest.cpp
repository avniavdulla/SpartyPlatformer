#include "pch.h"
#include "CppUnitTest.h"

#include <string>
#include "Level.h"
#include "Game.h"
#include "Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CLevelTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCLevelConstruct)
		{
			CLevel level;
		}

		TEST_METHOD(TestCLevelInstall)
		{
			CGame game;
			CLevel level;
			CVector start;

			level.SetLevel(0);
			level.Install(&game);

			start = level.GetStart();
			// Check if Level has correct start
			Assert::IsTrue(start.X() == 468);
			Assert::IsTrue(start.Y() == 572);

			vector<shared_ptr<CItem> > items = level.GetItems();
			// Check if Level has installed the 7 items in our Level 0
			Assert::IsTrue(items.size() == 7);

			// Check if Level installed a Gnome
			Assert::IsTrue(game.GetGnome() != nullptr);
		}

		TEST_METHOD(TestCLevelReset)
		{
			CGame game;
			CLevel level;
			CVector start;

			level.SetLevel(0);
			level.Install(&game);

			vector<shared_ptr<CItem> > items = level.GetItems();
			// Check if Level has installed the 7 items in our Level 0
			Assert::IsTrue(items.size() == 7);

			level.Reset();
			items = level.GetItems();
			// Check if Level cleared all items
			Assert::IsTrue(items.size() == 0);
		}

	};
}