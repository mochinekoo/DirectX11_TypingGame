#pragma once
#include "MochinekoEngine/BaseScene.h"

class RunningScene : public BaseScene {
private:
public:

	RunningScene();
	~RunningScene();

	void Init() override;
	void Update() override;
	void Draw() override;

};

