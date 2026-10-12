#include "GameManager.h"
#include <vector>
#include "WordData.h"
#include "MochinekoEngine/SceneManager.h"
#include <random>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Player.h"
#include <Windows.h>

using json = nlohmann::json;

namespace {
	float time_;
	std::vector<WordData> wordDataList_;
    WordData nowWord_;
}

void GameManager::Init() {
    time_ = DEFAULT_WORD_TIME;
    wordDataList_ = DEFAULT_WORD_DATA;
    nowWord_ = wordDataList_[0];
}

void GameManager::InitWordData() {
    std::ifstream file("worddata.json");

    if (!file.is_open()) {
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string str = buffer.str();

    try {
        json rootJson = json::parse(str);

        OutputDebugStringA(rootJson.dump(2).c_str());
        OutputDebugStringA("\n");

        for (const auto& wordJson : rootJson) {
            std::string displayWord =
                wordJson.at("displayName").get<std::string>();
            wordDataList_.push_back({ displayWord });
        }
    }
    catch (const std::exception& e) {
        OutputDebugStringA(e.what());
        OutputDebugStringA("\n");
    }
}

WordData GameManager::GetWord() {
    return nowWord_;
}

void GameManager::NextWord() {
    auto it = std::remove_if(wordDataList_.begin(), wordDataList_.end(), [](const WordData& word) {return word == nowWord_;});
    wordDataList_.erase(it);    // ワードリストから現在のワードを削除する

    if (wordDataList_.empty()) {    // ワードリストが空の時
        SceneManager::ChangeScene("EndingScene");
    }
    else {
        std::random_device seed_gen;
        std::mt19937 engine(seed_gen());
        std::shuffle(wordDataList_.begin(), wordDataList_.end(), engine);

        nowWord_ = wordDataList_[0];    // シャッフルしてから、現在のワードを代入
    }
}

float GameManager::GetTime() {
	return time_;
}

void GameManager::SetTime(float time) {
    time_ = time;
}
