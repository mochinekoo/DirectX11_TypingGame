#pragma once
#include "MochinekoEngine/BaseObject.h"
#include "WordData.h"

class Player : public BaseObject {
protected:
private:
	int correctCount_;
public:

	Player();
	~Player();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	int GetCorrectCount() const {
		return correctCount_;
	};

	void AddCorrectCount() {
		correctCount_++;
	};

	void RemoveCorrectCount() {
		correctCount_--;
	};
};