#pragma once
#include <vector>
#include "WordData.h"

namespace GameManager {
	inline const float DEFAULT_WORD_TIME = 20;
	inline std::vector<WordData> DEFAULT_WORD_DATA = { {"車", "kuruma"}, {"パソコン", "pasokonn"}, {"学校", "gakkou"} };

	void Init();
	void InitWordData();

	WordData GetWord();
	void NextWord();

	float GetTime();
	void SetTime(float time);
}