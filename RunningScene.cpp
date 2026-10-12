#include "RunningScene.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "MochinekoEngine/DX2DManager.h"
#include <random>
#include "MochinekoEngine/SceneManager.h"
#include "MochinekoEngine/InputManager.h"

using json = nlohmann::json;

RunningScene::RunningScene()
    : BaseScene("RunningScene") {
    nowWord_ = {};
    wordDataList_ = {};
    time_ = 0;
}

RunningScene::~RunningScene()
{
}

void RunningScene::Init() {
    // InitWordData();

    wordDataList_ = DEFAULT_WORD_DATA;
    time_ = DEFAULT_WORD_TIME;
    nowWord_ = wordDataList_[0];
}

void RunningScene::Update() {
    auto keyBuffer = InputManager::GetLowKeyBuffer();
    time_ -= MochinekoEngine::GetDeltaTime();

    if (keyBuffer == nowWord_.typingText) {
        NextWord();
        InputManager::DestoryKeyBuffer();
    }

    if (time_ <= 0) {
        NextWord();
        time_ = DEFAULT_WORD_TIME;
        InputManager::DestoryKeyBuffer();
    }
}

void RunningScene::Draw() {
    //DX2DManager::DrawFontText(0, 0, wordDataList_[0].displayName, Color::Black());
    std::string keyBuffer = InputManager::GetUpKeyBuffer();
    std::string lowKeyBuffer = InputManager::GetLowKeyBuffer();

    DX2DManager::DrawFontText(0, 0, nowWord_.displayName, Color::Black());
    DX2DManager::DrawFontText(0, 50, "(" + nowWord_.typingText + ")", Color::Black());
    DX2DManager::DrawFontText(0, 75, lowKeyBuffer, Color::Black());
    DX2DManager::DrawFontText(0, 100, std::to_string(time_), Color::Black());

}

void RunningScene::NextWord() {

    auto it = std::remove_if(wordDataList_.begin(), wordDataList_.end(), [this](const WordData& word) {return word == nowWord_;});
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

void RunningScene::InitWordData() {
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

void RunningScene::InitGameConfig() {
    std::ifstream file("config.json");

    if (!file.is_open()) {
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string str = buffer.str();

    try {
        json rootJson = json::parse(str);

        for (const auto& wordJson : rootJson) {
        }
    }
    catch (const std::exception& e) {
        OutputDebugStringA(e.what());
        OutputDebugStringA("\n");
    }
}
