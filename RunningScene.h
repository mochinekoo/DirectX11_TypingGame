#pragma once
#include "MochinekoEngine/BaseScene.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <string>

struct WordData {
	std::string displayName = "";
};

class RunningScene : public BaseScene {
private:
	std::vector<WordData> wordDataList_;
public:

	RunningScene();
	~RunningScene();

	void Init() override;
	void Update() override;
	void Draw() override;

	void InitWordData();
	void InitGameConfig();
};

