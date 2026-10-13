#include "TitleScene.h"
#include "MochinekoEngine/DX2DManager.h"
#include "MochinekoEngine/InputManager.h"
#include "MochinekoEngine/SceneManager.h"
#include "MochinekoEngine/ObjectManager.h"
#include "MochinekoEngine/MathUtil.h"

TitleScene::TitleScene()
	: BaseScene("TitleScene") {
}

TitleScene::~TitleScene() {
}

void TitleScene::Init() {
	startButton_ = new ImageButton("Asset/StartButton.png");
	startButton_->SetLocation({ 480, 170, 0 });
	exitButton_ = new ImageButton("Asset/ExitButton.png");
	exitButton_->SetLocation({480, 420, 0});


	ObjectManager::AddObject(startButton_);
	ObjectManager::AddObject(exitButton_);
}

void TitleScene::Update() {

	static float startButtonTime = 0.0f;
	static float exitButtonTime = 0.0f;
	const float scaleTime = 0.1f;
	if (startButton_->IsHover()) {
		startButtonTime += MochinekoEngine::GetDeltaTime();
		float rate = startButtonTime / scaleTime;
		float scale = MathUtil::Lerp(1.0f, 1.5f, rate);
		startButton_->SetScale({scale, scale, scale});
	}
	else {
		startButtonTime = 0.0f;
		startButton_->SetScale({1.0f, 1.0f, 1.0f});
	}

	if (exitButton_->IsHover()) {
		exitButtonTime += MochinekoEngine::GetDeltaTime();
		float rate = exitButtonTime / scaleTime;
		float scale = MathUtil::Lerp(1.0f, 1.5f, rate);

		exitButton_->SetScale({scale, scale, scale});
	}
	else {
		exitButtonTime = 0.0f;
		exitButton_->SetScale({1.0f, 1.0f, 1.0f});
	}

	if (startButton_->IsPush()) {
		SceneManager::ChangeScene("RunningScene");
	}
	if (exitButton_->IsPush()) {
		MochinekoEngine::Shutdown();
	}
}

void TitleScene::Draw() {
	DX2DManager::DrawFontText(0, 0, "ゲームを開始するにはスペースキーを押してください", Color::Black());
}
