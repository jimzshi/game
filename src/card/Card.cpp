#include "Card.h"

//#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>

namespace zks {
namespace game {
namespace card {

Suite operator++(Suite& suite) {
	if (suite < Suite::DIAMOND) {
		return Suite::DIAMOND;
	}
	if (suite > Suite::BLANK) {
		return Suite::BLANK;
	}
	suite = static_cast<Suite>(static_cast<int>(suite) + 1);
	return suite;
}
Suite operator*(const Suite& suite) {
	return suite;
}
Suite begin(const Suite& suite) {
	return Suite::DIAMOND;
}
Suite end(const Suite& suite) {
	return Suite::BLANK;
}
const std::array<std::string, 6> SUITE_STR{ { "D", "C", "H", "S", "Joker", "BLANK" } };
std::string to_string(Suite s) {
	return SUITE_STR[int(s)];
}

Number operator++(Number& n) {
	if (n < Number::ACE) {
		return Number::ACE;
	}
	if (n > Number::BLANK) {
		return Number::BLANK;
	}
	n = static_cast<Number>(static_cast<int>(n) + 1);
	return n;
}
Number operator*(const Number& n) {
	return n;
}
Number begin(const Number& n) {
	return Number::ACE;
}
Number end(const Number& n) {
	return Number::BLANK;
}
const std::array<std::string, 14> NUM_STR{ { "A", "2", "3", "4", "5", "6", "7",
"8", "9", "10", "J", "Q", "K", "BLANK" } };

std::string to_string(Number n) {
	return NUM_STR[int(n)];
}

bool operator<(Card const& lh, Card const& rh) {
	return lh.num < rh.num ?
			true : (lh.num == rh.num ? lh.suite < rh.suite : false);
}
bool operator==(Card const& lh, Card const& rh) {
	return lh.num == rh.num && lh.suite == rh.suite;
}
std::string to_string(Card const& c) {
	return to_string(c.suite) + "(" + to_string(c.num) + ")";
}

const Card JOKER1 {Suite::JOKER, Number::ACE};
const Card JOKER2 {Suite::JOKER, Number::TWO};

CardDeck::CardDeck() {
	if(reset(0) < 0) {
		throw std::runtime_error("fatal error.");
	}
}

CardDeck::CardDeck(int decks, bool need_joker) {
	if(reset(decks, need_joker) < 0) {
		throw std::runtime_error("invalid deck.");
	}
}

int CardDeck::reset(int decks, bool need_joker) {
	if(decks < 0) {
		return -1;
	}
	decks_ = decks;
	need_joker_ = need_joker;
	cards_.clear();

	for(int d=0; d<decks_; ++d) {
		for(auto s = begin(Suite()); s<Suite::JOKER; ++s) {
			for(const auto& n : Number()) {
				cards_.emplace_back(s, n);
			}
		}
		if(need_joker_) {
			cards_.push_back(JOKER1);
			cards_.push_back(JOKER2);
		}
	}

	return cards_.size();
}

void CardDeck::shuffle() {
	std::srand(std::time(0));
	std::array<int, std::mt19937::state_size> seed_data;
	std::generate(seed_data.begin(), seed_data.end(), std::rand);
	std::seed_seq seq(seed_data.begin(), seed_data.end());
    std::mt19937 g(seq);
    std::shuffle(cards_.begin(), cards_.end(), g);
}

void CardDeck::sort_by(RankFunc_t rank_fun, bool desc) {
	std::sort(cards_.begin(), cards_.end(), [&](Card const& c1, Card const& c2){
		bool r = rank_fun(c1) < rank_fun(c2);
		return desc ? r : !r;
	});
}

Card CardDeck::get_card(bool from_back) {
	Card ret;
	if(from_back) {
		ret = cards_.back();
		cards_.pop_back();
	} else {
		ret = cards_.front();
		cards_.erase(cards_.begin());
	}
	return ret;
}

int CardDeck::put_card(const Card& c, bool from_back) {
	if(from_back) {
		cards_.push_back(c);
	} else {
		cards_.insert(cards_.begin(), c);
	}
	return cards_.size();
}

std::string CardDeck::str() const {
	std::string ret{"{"};
	for(auto const& c : cards_) {
		ret += to_string(c) + ", ";
	}
	ret += "}";
	return ret;
}

} /* namespace card */
} /* namespace game */
} /* namespace zks */

