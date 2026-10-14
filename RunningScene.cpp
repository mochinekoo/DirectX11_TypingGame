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
#include "GameManager.h"
#include "MochinekoEngine/ObjectManager.h"
#include "Player.h"

using json = nlohmann::json;

namespace {
    Player* player_ = nullptr;
}

RunningScene::RunningScene()
    : BaseScene("RunningScene") {
}

RunningScene::~RunningScene()
{
}

void RunningScene::Init() {
    // InitWordData();
    GameManager::Init();
    player_ = new Player();
    ObjectManager::AddObject(player_);
}

void RunningScene::Update() {
    auto keyBuffer = InputManager::GetLowKeyBuffer();
    auto nowWord = GameManager::GetWord();
    float time = GameManager::GetTime();
    GameManager::SetTime(time - MochinekoEngine::GetDeltaTime());

    if (keyBuffer == nowWord.typingText) {
        GameManager::NextWord();
        InputManager::DestoryKeyBuffer();
        player_->AddCorrectCount();
    }

    if (time <= 0) {
        GameManager::NextWord();
        GameManager::SetTime(GameManager::DEFAULT_WORD_TIME);
        InputManager::DestoryKeyBuffer();
    }
}

void RunningScene::Draw() {
    //DX2DManager::DrawFontText(0, 0, wordDataList_[0].displayName, Color::Black());
    RECT rect = {};
    GetWindowRect(MochinekoEngine::GetGameWindowHandle(), &rect);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;

    std::string keyBuffer = InputManager::GetUpKeyBuffer();
    std::string lowKeyBuffer = InputManager::GetLowKeyBuffer();
    auto nowWord = GameManager::GetWord();
    float time = GameManager::GetTime();

    DX2DManager::SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER, DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
    DX2DManager::DrawFontText(0, 100, nowWord.displayName, Color::Black(), CP_ACP);
    DX2DManager::DrawFontText(0, 150, "(" + nowWord.typingText + ")", Color::Black(), CP_ACP);
    DX2DManager::DrawFontText(0, 200, lowKeyBuffer, Color::Black(), CP_ACP);

    DX2DManager::SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING, DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
    DX2DManager::DrawFontText(50, 50, "Žc‚èŽžŠÔF" + std::to_string(time), Color::Black(), CP_ACP);

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
