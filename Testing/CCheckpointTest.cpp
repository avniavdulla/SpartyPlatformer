#include "pch.h"
#include "CppUnitTest.h"

#include "Game.h"
#include "Level.h"
#include "Declare.h"
#include "DeclareCheckpoint.h"
#include "Item.h"
#include "Gnome.h"
#include "Checkpoint.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CCheckpointTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCCheckpointConstruct)
		{
			CGame game;
			shared_ptr<CCheckpoint> checkpoint = make_shared<CCheckpoint>(&game);
			game.Add(checkpoint);
		}

		TEST_METHOD(TestCCheckpointSet)
		{
			CGame game;

			shared_ptr<CCheckpoint> checkpoint = make_shared<CCheckpoint>(&game);
			checkpoint->SetLocation(500, 500);
			game.Add(checkpoint);
			game.GetGnome()->SetLocation(0, 0);
			game.SetStart(0, 0);

			game.CollisionTest(game.GetGnome().get());

			// Check checkpoint has not changed
			Assert::IsTrue(game.GetStart().X() == 0);
			Assert::IsTrue(game.GetStart().Y() == 0);

			game.GetGnome()->SetLocation(500, 500);

			game.CollisionTest(game.GetGnome().get());

			// Check checkpoint has changed
			Assert::IsTrue(game.GetStart().X() == 500);
			Assert::IsTrue(game.GetStart().Y() == 500);
			
		}

		TEST_METHOD(TestCCheckpointMultipleSet)
		{
			CGame game;

			shared_ptr<CCheckpoint> checkpoint1 = make_shared<CCheckpoint>(&game);
			checkpoint1->SetLocation(500, 500);
			shared_ptr<CCheckpoint> checkpoint2 = make_shared<CCheckpoint>(&game);
			checkpoint2->SetLocation(1000, 1000);
			game.Add(checkpoint1);
			game.Add(checkpoint2);
			game.GetGnome()->SetLocation(0, 0);
			game.GetGnome()->SetLocation(500, 500);

			game.CollisionTest(game.GetGnome().get());

			// Check checkpoint has changed
			Assert::IsTrue(game.GetStart().X() == 500);
			Assert::IsTrue(game.GetStart().Y() == 500);

			game.GetGnome()->SetLocation(1000, 1000);

			game.CollisionTest(game.GetGnome().get());

			// Check checkpoint has changed
			Assert::IsTrue(game.GetStart().X() == 1000);
			Assert::IsTrue(game.GetStart().Y() == 1000);

			// Move Gnome out of the way
			game.GetGnome()->SetLocation(750, 750);

			game.CollisionTest(game.GetGnome().get());

			// Check checkpoint has not changed
			Assert::IsTrue(game.GetStart().X() == 1000);
			Assert::IsTrue(game.GetStart().Y() == 1000);

			// Move Gnome back to checkpoint1
			game.GetGnome()->SetLocation(500, 500);

			game.CollisionTest(game.GetGnome().get());

			// Check checkpoint has changed back
			Assert::IsTrue(game.GetStart().X() == 500);
			Assert::IsTrue(game.GetStart().Y() == 500);

		}

	};
}