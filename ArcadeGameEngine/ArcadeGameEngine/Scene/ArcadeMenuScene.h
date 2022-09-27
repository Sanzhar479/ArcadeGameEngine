#ifndef ARCADEMENUSCENE_H_
#define ARCADEMENUSCENE_H_
#include"Scene.h"
#include <memory>
enum eGame
{
	TETRIS,
	BREAK_OUT,
	ASTEROIDS,
	CAPMAN,
	NUM_GAMES
};

class Screen;

class ArcadeMenuScene:public Scene
{

public:
	ArcadeMenuScene();
	virtual void init() override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& theScreen) override;
	virtual const std::string& GetSceneName() const override;
private:
	std::unique_ptr<Scene> GetScene(eGame game);
};
#endif
