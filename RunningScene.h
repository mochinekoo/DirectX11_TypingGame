#pragma once
#include "MochinekoEngine/BaseScene.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <string>
#include "WordData.h"
#include "MochinekoEngine/Box.h"

class RunningScene : public BaseScene {
private:
	Box* backTimerBox_;
	Box* frontTimerBox_;
public:

	RunningScene();
	~RunningScene();

	void Init() override;
	void Update() override;
	void Draw() override;

	void InitGameConfig();
};

