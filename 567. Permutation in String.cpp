#include <iostream> // std::cout; std::cin
#include <fstream> // std::fstream::open; std::fstream::close; 
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // std::memset
#include <algorithm> // std::swap; std::max; std::min; std::min_element; std::max_element; std::minmax_element; std::next_permutation; std::prev_permutation; std::nth_element; std::sort; std::lower_bound; std::upper_bound; std::reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::to_string; std::string::npos; std::stoul; std::stoull; std::stoi; std::stol; std::stoll; std::stof; std::stod; std::stold; 
#include <list> // std::list::merge; std::list::splice; std::list::merge; std::list::unique; std::list::sort
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.empty() or s1.size() > s2.size()) {
			return false;
		}
		if (s1.size() == s2.size()) {
			sort(begin(s1), end(s1));
			sort(begin(s2), end(s2));
			return s1 == s2;
		}
		int h1[26], h2[26];
		memset(h1, 0, sizeof(h1));
		memset(h2, 0, sizeof(h2));
		for (const auto &i : s1) {
			int id = i - 'a';
			h1[id]++;
		}
		for (size_t i = 0, n = s2.size(); i < n; i++) {
			int id = s2.at(i) - 'a';
			if (i + 1 < s1.size()) {
				h2[id]++;
				continue;
			}
			if (i + 1 == s1.size()) {
				h2[id]++;
			}
			if (i >= s1.size()) {
				int jd = s2.at(i - s1.size()) - 'a';
				h2[jd]--;
				h2[id]++;
			}
			bool equal = true;
			for (int j = 0; j < 26 and equal; j++) {
				equal = (h1[j] == h2[j]);
			}
			if (equal) {
				return true;
			}
		}
		return false;
	}
};
