#pragma once
#include "MochinekoEngine/BaseScene.h"

class EndingScene : public BaseScene {
private:
	float sceneCounter_;
public:

	EndingScene();
	~EndingScene();

	void Init() override;
	void Update() override;
	void Draw() override;

};

