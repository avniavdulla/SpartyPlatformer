#include "pch.h"
#include "CppUnitTest.h"

#include <memory>
#include <string>
#include "Game.h"
#include "Level.h"
#include "Declare.h"
#include "DeclareBackground.h"
#include "DeclarePlatform.h"
#include "Item.h"
#include "Gnome.h"
#include "Background.h"
#include "Platform.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CGameTest)
	{
	public:
		/**
		* Add Items to Game
		*/
		void TestThreeItems(CGame* game)
		{
			shared_ptr<CBackground> bg1 = make_shared<CBackground>(game);
			game->Add(bg1);

			shared_ptr<CBackground> bg2 = make_shared<CBackground>(game);
			game->Add(bg2);

			shared_ptr<CPlatform> platform = make_shared<CPlatform>(game);
			game->Add(platform);
		}

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCGameConstruct)
		{
			CGame game;
		}

		TEST_METHOD(TestCGameAdd)
		{
			CGame game;

			vector<shared_ptr<CItem> > items = game.GetItems();

			// Check if Game is empty
			Assert::IsTrue(items.size() == 0);

			TestThreeItems(&game);
			items = game.GetItems();
			// Check if Game has three items
			Assert::IsTrue(items.size() == 3);

			TestThreeItems(&game);
			items = game.GetItems();
			// Check if Game has six items
			Assert::IsTrue(items.size() == 6);
		}

		TEST_METHOD(TestCGameClear)
		{
			CGame game;

			vector<shared_ptr<CItem> > items = game.GetItems();

			TestThreeItems(&game);
			items = game.GetItems();
			// Check if Game has three items
			Assert::IsTrue(items.size() == 3);

			game.Clear();
			items = game.GetItems();
			// Check if Game is empty
			Assert::IsTrue(items.size() == 0);
		}

		TEST_METHOD(TestCGameLoad)
		{
			CGame game;

			vector<shared_ptr<CItem> > items = game.GetItems();

			game.Load(0);
			items = game.GetItems();
			// Check if Game has loaded the 7 items in our Level 0
			Assert::IsTrue(items.size() == 7);
		}

	};
}