#pragma once
#include <string>

struct WordData {
	std::string displayName = "";
	std::string typingText = "";

	bool operator==(const WordData& other) const {
		return displayName == other.displayName && typingText == other.typingText;
	}
};
