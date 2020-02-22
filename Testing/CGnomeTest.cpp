#include "pch.h"
#include "CppUnitTest.h"

#include <memory>
#include <string>
#include "Game.h"
#include "Level.h"
#include "Item.h"
#include "Gnome.h"
#include "Villain.h"
#include "Declare.h"
#include "DeclareBackground.h"
#include "DeclarePlatform.h"
#include "Background.h"
#include "Platform.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{

	TEST_CLASS(CGnomeTest)
	{
	public:
		
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCGnomeConstruct)
		{
			CGame game;
			CGnome gnome(&game);
		}

		TEST_METHOD(TestLose)
		{
			CGame game;
			//load level 1 
			game.Load(1);

			shared_ptr<CGnome> gnome = game.GetGnome();

			// starts as false
			Assert::IsFalse(gnome->GetDying());
			// sets location to be on top of villan so it collides
			gnome->SetLocation(1111, 850);
			game.Lose();
			// position reset to start
			Assert::IsTrue(gnome->GetLocation().X() == 852 && gnome->GetLocation().Y() == 540);

			// reset gnome to a safe position to make sure its not dying 
			gnome->SetLocation(0, 0);
			game.Update(.01);
			Assert::IsFalse(gnome->GetDying());
			
			// update and set gnome to fall off screen
			gnome->SetLocation(0, 5000);
			game.Update(0.01);
			Assert::IsTrue(gnome->GetDying());



		}

		TEST_METHOD(TestNextLevel)
		{
			CGame game;
			//load level 0 
			game.Load(0);

			// make sure it is set to 0 from loading level0
			Assert::IsTrue(game.GetLevelNumber() == 0);
			game.NextLevel();

			// make sure it is set to 0 from loading level1
			Assert::IsTrue(game.GetLevelNumber() == 1);
			game.NextLevel();

			// make sure it is set to 0 from loading level2
			Assert::IsTrue(game.GetLevelNumber() == 2);
			game.NextLevel();

			// make sure it is set to 0 from loading level3
			Assert::IsTrue(game.GetLevelNumber() == 3);
			game.NextLevel();

			// going to next level after 3, just resets 3
			Assert::IsTrue(game.GetLevelNumber() == 3);

		}

	};
}