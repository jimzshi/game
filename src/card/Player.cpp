#include "Player.h"

namespace zks {
namespace game {
namespace card {

Player::Player() {
	if(reset("") < 0) {
		throw std::runtime_error("fatal error!");
	}
}

Player::Player(const std::string& n) {
	if(reset(n) < 0) {
		throw std::runtime_error("invalid player!");
	}
}

Player::Player(char const* s) {
	if(reset(s) < 0) {
		throw std::runtime_error("invalid player!");
	}
}

int Player::reset(const std::string& n) {
	name_ = n;
	return hand.reset(0);
}

std::string Player::str() const {
	std::string ret{"[Player: "};
	ret += name_ + ", Hand: " + hand.str() + "]";
	return ret;
}

} /* namespace card */
} /* namespace game */
} /* namespace zks */


