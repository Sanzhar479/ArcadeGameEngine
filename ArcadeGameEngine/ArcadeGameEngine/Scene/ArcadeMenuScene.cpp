#include "ArcadeMenuScene.h"
#include "../Graphics/Screen.h"
#include"../Shapes/AllShapesInclude.h"
#include "../Input/GameController.h"
#include <iostream>
ArcadeMenuScene::ArcadeMenuScene()
{
}

void ArcadeMenuScene::Init()
{
	ButtonAction action;
	action.key = GameController::ActionKey();
	action.action = [](uint32_t, InputState state)
	{
		if (GameController::IsPressed(state))
		{
			std::cout << "Action Pressed!" << std::endl;
		}
	};
	mGameController.AddInputActionForKey(action);

	MouseButtonAction mouseAction;
	mouseAction.mouseButton = GameController::LeftMouseButton();
	mouseAction.mouseInputAction = [](InputState state, const MousePosition& position)
	{
		if (GameController::IsPressed(state))
		{
			std::cout << "LMB is pressed" << std::endl;
		}
	};
	mGameController.AddMouseButtonAction(mouseAction);

	mGameController.SetMouseMovedAction([](const MousePosition& mousePosition)
		{std::cout << "Mouse posX: " << mousePosition.xPos << "    ,Mouse posY: " << mousePosition.yPos <<std::endl; });
}

void ArcadeMenuScene::Update(uint32_t dt)
{
}

void ArcadeMenuScene::Draw(Screen& theScreen)
{
	Line2D line = { Vec2D(0,0), Vec2D(theScreen.Width() / 2,theScreen.Height() / 2) };
	Triangle triangle = { Vec2D(60,10), Vec2D(10,110),Vec2D(110,110) };
	AARectangle rect = { Vec2D(theScreen.Width() / 2 - 25,theScreen.Height() / 2 - 25),50,50 };
	Circle circle = { Vec2D(theScreen.Width() / 2 + 30,theScreen.Height() / 2 + 30),50 };

	theScreen.Draw(triangle, Color::Red(), true, Color::Red());
	theScreen.Draw(rect, Color::Cyan(), true, Color::Cyan());
	theScreen.Draw(circle, Color::Green(), true, Color(0, 255, 0, 150));

}

const std::string& ArcadeMenuScene::GetSceneName() const
{
	static std::string sceneName = "Arcade Scene";
	return sceneName;
}

std::unique_ptr<Scene> ArcadeMenuScene::GetScene(eGame game)
{
	switch (game)
	{
	case TETRIS:
	{

	}
		break;
	case BREAK_OUT:
	{

	}
		break;
	case ASTEROIDS:
	{

	}
		break;
	case PACMAN:
	{

	}
		break;
	default:
	{
	}
		break;
	}
	return nullptr;
}
