#pragma once
#include <vector>
#include "WordData.h"

namespace {
	const float DEFAULT_WORD_TIME = 20;
	std::vector<WordData> DEFAULT_WORD_DATA = { {"車", "kuruma"}, {"パソコン", "pasokonn"}, {"学校", "gakkou"} };
}

namespace GameManager {

	void Init();
	void InitWordData();

	WordData GetWord();
	void NextWord();

	int GetTime();
	void SetTime(int time);
}