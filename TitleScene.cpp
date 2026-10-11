#include "TitleScene.h"
#include "MochinekoEngine/DX2DManager.h"
#include "MochinekoEngine/InputManager.h"
#include "MochinekoEngine/SceneManager.h"

TitleScene::TitleScene()
	: BaseScene("TitleScene") {
}

TitleScene::~TitleScene() {
}

void TitleScene::Init() {
}

void TitleScene::Update() {
	if (InputManager::CheckDownKey(DIK_SPACE)) {
		SceneManager::ChangeScene("RunningScene");
	}
}

void TitleScene::Draw() {
	DX2DManager::DrawFontText(0, 0, "ゲームを開始するにはスペースキーを押してください", Color::Black());
}
