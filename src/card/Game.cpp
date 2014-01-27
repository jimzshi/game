#include "Game.h"

#include <string>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

int zks::game::card::simple_card_rank(Card const& c) {
	if(c.suite == Suite::JOKER) {
		return 100 + static_cast<int>(c.num);
	}
	if(c.num == Number::ACE) {
		return 14;
	}
	if(c.num == Number::TWO) {
		return 15;
	}
	return static_cast<int>(c.num);
}

zks::game::card::Game::Game(int players, int decks, bool need_joker) {
	players_.resize(players);
	for(auto i=0; i<players; ++i) {
		ostringstream oss;
		oss << "Player" << i;
		players_[i].reset(oss.str());
	}
	deck_.reset(decks, need_joker);
}

int zks::game::card::Game::prepare() {
	prepare_deck_();

	return 0;
}

int zks::game::card::Game::play() {
	prepare_players_();

	return 0;
}

int zks::game::card::Game::post() {
	prepare_others_();
	return 0;
}

std::string zks::game::card::Game::str() const {
	ostringstream oss;
	oss << string(15, '*') << "\n" << "deck: " << deck_.str() << "\n";
	for(auto const& p : players_) {
		oss << p.str() << "\n";
	}
	oss << string(15, '*');
	return oss.str();
}

int zks::game::card::Game::prepare_deck_() {
	deck_.shuffle();
	return 0;
}

int zks::game::card::Game::prepare_players_() {
	deal_();
	return 0;
}

int zks::game::card::Game::prepare_others_() {
	std::for_each(players_.begin(), players_.end(), [&](Player& p) {
		p.hand.sort_by( simple_card_rank );
	});
	return 0;
}

int zks::game::card::Game::deal_() {
	while(deck_.size() >= players_.size()) {
		for(Player& p : players_) {
			p.hand.put_card( deck_.get_card() );
		}
	}
	return 0;
}

int zks::game::card::Game::pre_round_() {
	return 0;
}

int zks::game::card::Game::play_a_round_() {
	return 0;
}

int zks::game::card::Game::post_round_() {
	return 0;
}
