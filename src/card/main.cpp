#include "Card.h"
#include "Game.h"

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace zks::game::card;



int test_deck() {
	CardDeck deck(1);
	CardDeck d1, d2;

	deck.shuffle();
	cout << "deck: " << deck.str() << endl;
	cout << "d1: " << d1.str() << endl;
	cout << "d2: " << d2.str() << endl;

	cout << "\nget from back:\n";
	for (auto i = 0; i<10; ++i) {
		d1.put_card(deck.get_card());
		cout << d1.str() << endl;
	}
	cout << "\nget from front:\n";
	for (auto i = 0; i<10; ++i) {
		d2.put_card(deck.get_card(false));
		cout << d2.str() << endl;
	}
	cout << "\n";

	cout << "deck: " << deck.str() << endl;

	return 0;
}

int main() {
	Game g;
	cout << "game: \n" << g.str() << endl;

	g.prepare();
	cout << "game: \n" << g.str() << endl;

	g.play();
	cout << "game: \n" << g.str() << endl;

	g.post();
	cout << "game: \n" << g.str() << endl;

	return 0;
}


int test_suite() {
	for (const auto& s : Suite()) {
		cout << to_string(s) << ", ";
	}
	cout << endl;
	return 0;
}

int test_number() {
	for (const auto& n : Number()) {
		cout << to_string(n) << ", ";
	}
	cout << endl;
	return 0;
}

int test_card() {
	vector<Card> deck;
	for (auto s = begin(Suite()); s<Suite::JOKER; ++s) {
		for (const auto& n : Number()) {
			deck.emplace_back(s, n);
		}
	}

	cout << "\n";
	for (auto const& c : deck) {
		cout << to_string(c) << ", ";
	}
	cout << "\n";

	std::srand(std::time(0));
	std::array<int, std::mt19937::state_size> seed_data;
	std::generate(seed_data.begin(), seed_data.end(), std::rand);
	std::seed_seq seq(seed_data.begin(), seed_data.end());
	std::mt19937 g(seq);
	std::shuffle(deck.begin(), deck.end(), g);

	cout << "\n";
	for (auto const& c : deck) {
		cout << to_string(c) << ", ";
	}
	cout << "\n";

	return 0;
}
