#ifndef ZKS_SUDOKU_H_
#define ZKS_SUDOKU_H_

#include <array>
#include <iosfwd>
#include <string>
#include <set>
#include <array>

namespace zks {
namespace game {

	class Sudoku {
	public:
		typedef char digit_t;
		typedef std::set<digit_t> grids_t;
		typedef std::array<digit_t, 81> board_t;
		typedef std::array<grids_t, 81> oppor_t;
		static const std::string valid_chars;
		static const grids_t full_set;

	private:
		board_t board_;
		oppor_t opportunities_;

		int xy2i_(int x, int y) const { return y % 9 * 9 + x % 9; }
		int i2x_(int i) const { return i % 9; }
		int i2y_(int i) const { return i / 9; }
		grids_t set_diff(grids_t const& lh, grids_t const& rh) const;
		grids_t set_inter(grids_t const& lh, grids_t const& rh) const;
		grids_t set_union(grids_t const& lh, grids_t const& rh) const;
		grids_t traverse_x_(int i) const ;
		grids_t traverse_y_(int i) const ;
		grids_t traverse_r_(int i) const ;
		grids_t left_digits_x_(int i) const {
			return set_diff(full_set, traverse_x_(i));
		}
		grids_t left_digits_y_(int i) const {
			return set_diff(full_set, traverse_y_(i));
		}
		grids_t left_digits_r_(int i) const {
			return set_diff(full_set, traverse_r_(i));
		}
		grids_t left_digits(int i) const {
			return set_diff(full_set, 
							set_union(traverse_x_(i), set_union(traverse_y_(i), traverse_r_(i)))
							);
		}

		std::set<int> traverse(int i);
		int rank(digit_t d, int i);
		digit_t pop_top(grids_t& g, int i);


		int find_oppor_impl1(int from, int to);
		int find_oppor_impl2(int from, int to);
		int find_oppor_impl3(int from, int to);

		bool solve_impl1();
		bool solve_impl2(int start);
		bool solve_impl3();

	public:
		Sudoku() { reset(); }
		Sudoku(std::string const& s);
		~Sudoku() {}

		bool read(std::istream& in);

		void reset() {
			for (auto& c : board_) {
				c = '0';
			}
		}
		//origin coordinate(0,0) starts at left-top corner.
		//y axis is vertical;
		digit_t& grid(int x, int y) { return board_[xy2i_(x, y)]; }
		digit_t cgrid(int x, int y) const { return board_[xy2i_(x, y)]; }

		bool write(std::ostream& out) const {
			for (auto c : board_) {
				out << c;
			}
			return true;
		}
		std::string str() const;

		int find_opportunites(int from, int to) {
			return find_oppor_impl3(from, to);
		}
		bool solve() {
			return solve_impl3();
		}
	};


}
}



#endif