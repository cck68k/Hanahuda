#pragma once
#include"Scene.h"

class FusumaScene : public Scene {
private:
	int count;
	int leftx_limit;
	int rightx_limit;

	bool isclosing;

	int waitcount = 0;

public:
	FusumaScene();
	~FusumaScene();

	void Update();
	void Draw();
};