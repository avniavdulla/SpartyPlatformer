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
			//load level 0 
			game.Load(1);

			shared_ptr<CGnome> gnome = game.GetGnome();

			// starts as false
			Assert::IsFalse(gnome->GetDying());
			gnome->SetLocation(0, 5000);
			game.Update(0.5);
			// update and gnome falls off screen
			Assert::IsTrue(gnome->GetDying());

			gnome->SetLocation(0, 0);
			game.Update(.01);
			Assert::IsFalse(gnome->GetDying());

			game.Update(.01);

		}

		TEST_METHOD(TestWin)
		{


		}

	};
}