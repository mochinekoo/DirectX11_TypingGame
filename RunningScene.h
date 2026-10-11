#pragma once
#include "MochinekoEngine/BaseScene.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <string>

struct WordData {
	std::string displayName = "";
	std::string typingText = "";

	bool operator==(const WordData& other) const {
		return displayName == other.displayName && typingText == other.typingText;
	}
};

namespace {
	const float DEFAULT_WORD_TIME = 20;
	std::vector<WordData> DEFAULT_WORD_DATA = { {"車", "kuruma"}, {"パソコン", "pasokonn"}, {"学校", "gakkou"}};
}

class RunningScene : public BaseScene {
private:
	float time_;
	WordData nowWord_;
	std::vector<WordData> wordDataList_;
public:

	RunningScene();
	~RunningScene();

	void Init() override;
	void Update() override;
	void Draw() override;

	void NextWord();

	void InitWordData();
	void InitGameConfig();
};

