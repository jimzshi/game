#ifndef CARD_H_
#define CARD_H_

#include <array>
#include <string>
#include <vector>
#include <functional>

namespace zks {
namespace game {
namespace card {

enum struct Suite { DIAMOND, CLUB, HEART, SPADE, JOKER, BLANK };
Suite operator++(Suite& suite);
Suite operator*(const Suite& suite);
Suite begin(const Suite& suite);
Suite end(const Suite& suite);
std::string to_string(Suite s);


enum struct Number { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, BLANK};
Number operator++(Number& n);
Number operator*(const Number& n);
Number begin(const Number& n) ;
Number end(const Number& n) ;
std::string to_string(Number n);

struct Card
{
	Suite suite;
	Number num;

	Card() : suite(Suite::BLANK), num(Number::BLANK) {}
	Card(Suite s, Number n) : suite(s), num(n) {}
	Card(const Card& c) : suite(c.suite), num(c.num) {}
	//Card(Card&& c) = default;
	Card& operator=(Card const& c) = default;
	~Card() = default;
};
bool operator<(Card const& lh, Card const& rh);
bool operator==(Card const& lh, Card const& rh);
std::string to_string(Card const& c);

extern const Card JOKER1;
extern const Card JOKER2;

typedef std::function<int(Card const&)> RankFunc_t;

class CardDeck
{
	int decks_;
	bool need_joker_;
	std::vector<Card> cards_;
public:
	CardDeck();
	CardDeck(int decks, bool need_joker = true);
	CardDeck(CardDeck const&) = default;
	//CardDeck(CardDeck &&) = default;
	~CardDeck() = default;

	int reset(int decks, bool need_joker = true);
	void shuffle();
	void sort_by(RankFunc_t rank_fun, bool desc = false);

	Card get_card(bool from_back = true);
//	std::vector<Card> get_cards(bool from_back = true);
	int put_card(Card const& c, bool from_back = true);
//	int put_cards(std::vector<Card> const& cv, bool from_back = true);

	size_t size() const { return cards_.size(); }
	std::string str() const;
};

} /* namespace card */
} /* namespace game */
} /* namespace zks */


#endif /* CARD_H_ */
