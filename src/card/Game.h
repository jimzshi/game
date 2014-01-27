#ifndef GAME_H_
#define GAME_H_

#include "Card.h"
#include "Player.h"

#include <string>

namespace zks {
namespace game {
namespace card {

int simple_card_rank(Card const& c);

class Game {
public:
	Game(int players, int decks = 1, bool need_joker = true);
	Game() : Game(4, 1, true) {}
	Game(Game const& ) = delete;
	Game(Game&& ) = delete;
	virtual ~Game() = default;

	int prepare();
	int play() ;
	int post() ;

	std::string str() const;
protected:
	CardDeck deck_;
	std::vector<Player> players_;

private:
	int prepare_deck_() ;
	int prepare_players_() ;
	int prepare_others_() ;

	int deal_ ();

	int pre_round_() ;
	int play_a_round_();
	int post_round_();
};

} /* namespace card */
} /* namespace game */
} /* namespace zks */

#endif /* GAME_H_ */
