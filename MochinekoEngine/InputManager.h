#pragma once

#include <Windows.h>
#include <dinput.h>
#include <Xinput.h>
#include <DirectXMath.h>
#include <string>

#pragma comment(lib, "XInput.lib")

namespace InputManager {

	int Init(const HINSTANCE hInstance, const HWND hwnd);
	void Update();

	bool CheckPushKey(const int key);
	bool CheckDownKey(const int key);
	bool CheckUpKey(const int key);
	bool CheckPushMouse(const int button);
	bool CheckDownMouse(const int button);
	bool CheckUpMouse(const int button);

	const char* ConvertKeyName(const int key);
	std::string GetUpKeyBuffer();
	std::string GetLowKeyBuffer();
	void DestoryKeyBuffer();

	POINT GetMousePostion();

	bool IsControllerButtonPush(const int button);

	DirectX::XMFLOAT2 GetControllerTiltLeft();
	DirectX::XMFLOAT2 GetControllerTiltRight();

	float GetControllerLeftTrigger();
	float GetControllerRightTrigger();

	void StartControllerVibration(const int leftSpeed, const int rightSpeed);
	void StopControllerVibration();
}