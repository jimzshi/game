#ifndef COMBINATION_H_
#define COMBINATION_H_

namespace zks {
namespace game {
namespace card {

class Combination {
public:
	Combination();
	virtual ~Combination();

	virtual size_t Cardinal() const = 0; /* how many cards in this combination */

};

class Single : public Combination {

};

class Pair : public Combination {

};

class ThreeCards : public Combination {

};

class Flush : public Combination {

};

class Straight : public Combination {

};

} /* namespace card */
} /* namespace game */
} /* namespace zks */

#endif /* COMBINATION_H_ */
