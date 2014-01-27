#ifndef PLAYER_H_
#define PLAYER_H_

#include "Card.h"

#include <string>

namespace zks {
namespace game {
namespace card {

class Player {
	std::string name_;
public:
	Player();
	Player(std::string const& n);
	Player(char const* s);
	Player(Player const& p) = default;
	Player(Player &&) = default;
	virtual ~Player() = default;

	int reset(std::string const& n) ;

	CardDeck hand;

	std::string str() const;
};

} /* namespace card */
} /* namespace game */
} /* namespace zks */

#endif /* PLAYER_H_ */
