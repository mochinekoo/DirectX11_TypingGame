#pragma once
#include "MochinekoEngine/BaseScene.h"
#include "MochinekoEngine/ImageButton.h"

class TitleScene : public BaseScene {
private:
	ImageButton* startButton_;
	ImageButton* exitButton_;
public:

	TitleScene();
	~TitleScene();

	void Init() override;
	void Update() override;
	void Draw() override;

};

