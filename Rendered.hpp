#ifndef Rendered_hpp
#define Rendered_hpp

#include "SDL.h"
#define SetRenderColor(renderer, color) do{ SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a); } while(0)
#define DrawLine(renderer, p1, p2) do { SDL_RenderDrawLineF(renderer, p1.x, p1.y, p2.x, p2.y); } while(0)

class Rendered {
protected:
	~Rendered() {
		delete pos;
		delete rot;
		delete color;
	}
	void* pos;
	float* rot;
	SDL_Color* color;
	SDL_Renderer* renderer;
	int stage = 0;
public:
	virtual void Render(SDL_Renderer* renderer, int stage) { return; }
	virtual void RenderUI(SDL_Renderer* renderer) { return; }
	virtual int getStage() { return stage; }
};

#endif //Rendered_hpp