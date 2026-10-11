#include "RunningScene.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "MochinekoEngine/DX2DManager.h"

using json = nlohmann::json;

RunningScene::RunningScene()
    : BaseScene("RunningScene") {
}

RunningScene::~RunningScene()
{
}

void RunningScene::Init() {
    InitJson();
}

void RunningScene::Update() {
}

void RunningScene::Draw() {
    DX2DManager::DrawFontText(0, 0, wordDataList_[0].displayName, Color::Black());
}

void RunningScene::InitJson() {
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