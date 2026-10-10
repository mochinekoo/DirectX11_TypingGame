#pragma once
#include "MochinekoEngine/BaseScene.h"

class TitleScene : public BaseScene {
private:
public:

	TitleScene();
	~TitleScene();

	void Init() override;
	void Update() override;
	void Draw() override;

};

