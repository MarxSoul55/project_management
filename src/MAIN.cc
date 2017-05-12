#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cmath>
#include <stack>
#include <cstdlib>

using namespace std;

void die() {
	cout << "INVALID INPUT!" << endl;
	exit(EXIT_FAILURE);
}


class SpecialInt {
	private:
		int data;
	public:
		void set_data(int x) {
			if (x > 255) die();
			data = x;
		}
		int get_data() {
			if (data > 255) die();
			return data;
		}
		void increment_data() {
			if (data + 1 > 255) die();
			data++;
		}
};


vector<string> input() {
	vector<string> retval;
	string statement;
	getline(cin, statement);
	size_t found_let = statement.find("LET");
	size_t found_equals = statement.find("=");
	// "LET" is in there, so we're setting a variable!
	if (found_let != string::npos) {
		// But wait! Remember, a variable can only be one letter.
		// So how can we check for that? Well, if the variable is only one letter...
		// Then "=" will always be at the same index: 6
		if (found_equals == 6) {
			// Okay, so by now we know everything from the beginning to "=" is fine!
			// You may ask, what about the number? What if it's out of bounds?
			// Well, the SpecialInt class will handle that :)
			string var_name;
			var_name.push_back(statement.at(4));
			// Value should start at index: 8
			string var_value = statement.substr(8, (statement.size() - 1) - 7);
			retval.push_back(var_name);
			retval.push_back(var_value);
			return retval;
		}
		// OK, it's an error!
		else {
			die();
		}
	}
	// So there's no "LET", but maybe it's just an expression? An expression wouldn't have "=".
	else if (found_equals == string::npos) {
		retval.push_back(statement);
		return retval;
	}
	// OK, it's an error for sure!
	else {
		die();
	}
}


int logic(string statement) {
	// Separate the statement into logical parts.
	istringstream iss(statement);
	vector<string> vec;
	copy(istream_iterator<string> (iss), istream_iterator<string>(), back_inserter(vec));
	// Create stack for evaluation.
	stack<int> my_stack;
	if (vec.size() == 1) {
		// TODO
	}
}


int main() {
	// Hash table that holds variables.
	unordered_map<string, SpecialInt> hash;
	while (true) {
		// Get the input-vector from the function.
		vector<string> vec = input();
		// It's setting a variable.
		if (vec.size() == 2) {
			SpecialInt val;
			val.set_data(stoi(vec.at(1)));
			// But wait! We can't redeclare a variable! Let's make sure of that.
			if (hash.find(vec.at(0)) == hash.end()) {
				hash[vec.at(0)] = val;
			}
			// We must be trying to redeclare a variable! Bad!
			else {
				die();
			}
		}
		else {
			// Call logic function.
			int result = logic(vec.at(0));
		}
	}
	return 0;
}
