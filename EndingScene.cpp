#include "EndingScene.h"
#include "MochinekoEngine/DX2DManager.h"
#include "MochinekoEngine/ObjectManager.h"
#include "MochinekoEngine/SceneManager.h"
#include "MochinekoEngine/Framework.h"
#include "Player.h"

namespace {
	const int NEXT_SCENE_TIME = 10;
}

EndingScene::EndingScene()
	 : BaseScene("EndingScene") {
	sceneCounter_ = 0;
}

EndingScene::~EndingScene()
{
}

void EndingScene::Init()
{
}

void EndingScene::Update() {
	sceneCounter_ += MochinekoEngine::GetDeltaTime();

	if (sceneCounter_ >= NEXT_SCENE_TIME) {
		SceneManager::ChangeScene("TitleScene");

		sceneCounter_ = 0;
		auto playerList = ObjectManager::FindObjects<Player>();
		for (Player* player : playerList) {
			player->ResetCorrectCount();
		}
	}
}

void EndingScene::Draw() {
	Player* player = ObjectManager::FindObject<Player>();
	if (player != nullptr) {
		DX2DManager::DrawFontText(0, 0, "‚ ‚È‚½‚Ì¬Ñ‚ÍF" + std::to_string(player->GetCorrectCount()), Color::Black(), CP_ACP);
	}
}
