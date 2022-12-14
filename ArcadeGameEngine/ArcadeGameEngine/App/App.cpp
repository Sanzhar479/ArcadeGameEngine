#include "App.h"
#include <SDL.h>
#include "../Scene/ArcadeMenuScene.h"
#include <cassert>

App& App::Singleton()
{
	static App theApp;
	return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
	mnoptrWindow = mScreen.Init(width, height, mag);
	std::unique_ptr<ArcadeMenuScene> arcadeScene = std::make_unique<ArcadeMenuScene>();
	PushScene(std::move(arcadeScene));
	return mnoptrWindow != nullptr;
}

void App::Run()
{
	if (mnoptrWindow)
	{
        bool running = true;

		uint32_t lastTick = SDL_GetTicks();  //start ticking since SDL initialization
		uint32_t currentTick = lastTick;

		uint32_t dt = 10; //update every 10 milliseconds
		uint32_t accumulator = 0;
		mInputController.Init([&running](uint32_t dt, InputState state) {running = false; });


		while (running)
		{
			currentTick = SDL_GetTicks();
			uint32_t frameTime = currentTick - lastTick;
			if (frameTime > 300)
			{
				frameTime = 300;
			}
			lastTick = currentTick;

			accumulator += frameTime;

			//Input//
			mInputController.Update(dt);

			Scene* topScene = App::TopScene();
			assert(topScene && "Why no scene?");
			if (topScene)
			{	
				//Proper Update//
				while (accumulator >= dt)
				{
					//update current scene by Delta time 
					topScene->Update(dt);
					//std::cout << "Delta time step: " << dt << std::endl;
					accumulator -= dt;
				}

			}
			//Render//
			topScene->Draw(mScreen);
		
			mScreen.SwapScreen();
		}
	}
}

void App::PushScene(std::unique_ptr<Scene> scene)
{
	assert(scene && "Don't push nullPtr");
	if (scene)
	{
		scene->Init();
		mInputController.SetGameController(scene->GetGameController());
		mSceneStack.emplace_back(std::move(scene));
		SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());

	}
}

void App::PopScene()
{
	if (mSceneStack.size() > 1)
	{
		mSceneStack.pop_back();
	}
	if (TopScene())
	{
		mInputController.SetGameController(TopScene()->GetGameController());
		SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
	}

}

Scene* App::TopScene()
{
	if (mSceneStack.empty())
	{
		return nullptr;
	}
	return mSceneStack.back().get();
}
