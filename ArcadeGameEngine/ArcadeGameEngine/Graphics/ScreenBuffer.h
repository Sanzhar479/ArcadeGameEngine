#ifndef ScreenBuffer_H
#define ScreenBuffer_H
#include "Color.h"

struct SDL_Surface;

struct SDL_Surface;

class ScreenBuffer
{
public:
	ScreenBuffer();
	ScreenBuffer(const ScreenBuffer& screenBuffer);
	~ScreenBuffer();

	ScreenBuffer& operator=(const ScreenBuffer& screenBuffer);

	void Init(uint32_t format, uint32_t width, uint32_t h);

	inline SDL_Surface * GetSurface() {return mSurface;}

	void Clear(const Color& c = Color::Black());

	void SetPixel(const Color& color, int x, int y);

private:

	SDL_Surface * mSurface;
	uint32_t GetIndex(int r, int c);
};
#endif
