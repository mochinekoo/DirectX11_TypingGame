#pragma once
#include "MochinekoEngine/BaseScene.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <string>
#include "WordData.h"

class RunningScene : public BaseScene {
private:
public:

	RunningScene();
	~RunningScene();

	void Init() override;
	void Update() override;
	void Draw() override;

	void InitGameConfig();
};

