#include "Player.h"
#include "MochinekoEngine/InputManager.h"
#include "MochinekoEngine/Framework.h"
#include "GameManager.h"

Player::Player()
	: BaseObject("Player") {
    correctCount_ = 0;
	canDestroyNextScene_ = false;
}

Player::~Player() {
}

void Player::Init() {
}

void Player::Update() {
}

void Player::Draw() {
}

void Player::Release() {
}
