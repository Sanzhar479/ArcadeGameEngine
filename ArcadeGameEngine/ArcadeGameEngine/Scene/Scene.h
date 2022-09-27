#ifndef SCENE_H_
#define SCENE_H_
#include <string>
#include<stdint.h>

class Screen;

//Interface
class Scene
{
public:
	virtual ~Scene() {};
	virtual void init() =0;
	virtual void Update(uint32_t dt) =0;
	virtual void Draw(Screen& theScreen);

	virtual const std::string& GetSceneName() const = 0;
};
#endif
