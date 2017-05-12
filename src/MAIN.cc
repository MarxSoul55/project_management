// By:  Beltran, Jow, Machado, Gardner, Borden

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

void peacefully_die() {
	// Die peacefully, no "INVALID INPUT!"
	exit(EXIT_SUCCESS);
}

inline bool is_int(const string &s) {
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '+'))) return false;
	char *p;
	strtol(s.c_str(), &p, 10);
	return (*p == 0);
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

// Hash table.
unordered_map <string, SpecialInt> table;

vector<string> input() {
	vector<string> retval;
	string statement;
	getline(cin, statement);
	if (!cin) peacefully_die();
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
			// But wait! No negatives.
			if (statement.at(8) == '-') die();
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
	int retval;
	// Separate the statement into logical parts.
	istringstream iss(statement);
	vector<string> vec;
	copy(istream_iterator<string> (iss), istream_iterator<string>(), back_inserter(vec));
	// No operators at the end of vec! Makes no sense!
	string last = vec.at(vec.size()-1);
	if (last == "+" || last == "-" || last == "*" || last == "/" || last == "^" || last == "%") {
		die();
	}
	// Create stack for evaluation.
	vector<string> op_table;
	/*
	if (vec.size() == 1) {
		//
	}
	*/
	for (string s : vec) {
		// We're going to treat this kinda like the RPN calculator.
		op_table.push_back(s);
		// This fucks all the logic up! Needed to add check for this!
		if (vec.size() == 1) {
			if (table.find(s) != table.end()) {
				retval = table[s].get_data();
				table[s].increment_data();
				//retval = table[s].get_data();
				return retval;
			} else if (is_int(s)) {
				retval = stoi(s);
				return retval;
			} else { die(); } // Doesn't exist.
		}
		if (op_table.size() == 3) {
			// We got the operator.
			string operat = op_table.at(1);
			// We have to declare the first and second values because of stupid C++ scoping rules.
			int val1;
			int val2;
			// The first value.
			// If the string is not an integer, it must be a variable. Look it up!
			// We're also handling conversion from a string to an integer with this.
			if (!is_int(op_table.at(0))) {
				if (table.find(op_table.at(0)) == table.end()) die();
				val1 = table[op_table.at(0)].get_data();
				table[op_table.at(0)].increment_data();
			}
			// OK, it's an integer then. Let's make it so (via conversion as before).
			else { val1 = stoi(op_table.at(0)); }
			// Do the same process for the second item.
			if (!is_int(op_table.at(2))) {
				if (table.find(op_table.at(2)) == table.end()) die();
				val2 = table[op_table.at(2)].get_data();
				table[op_table.at(2)].increment_data();
			}
			else { val2 = stoi(op_table.at(2)); }
			// Now we got the integer values. Now based off of the operator, let's do this!
			if (operat == "+") {
				// We got the result.
				int result = val1 + val2;
				// Clear the operation table.
				op_table.clear();
				// Now add the string of the result back onto it!
				op_table.push_back(to_string(result));
				retval = result;
			}
			else if (operat == "-") {
				int result = val1 - val2;
				op_table.clear();
				op_table.push_back(to_string(result));
				retval = result;
			}
			else if (operat == "*") {
				int result = val1 * val2;
				op_table.clear();
				op_table.push_back(to_string(result));
				retval = result;
			}
			else if (operat == "/") {
				if (val2 == 0) die();
				int result = val1 / val2;
				op_table.clear();
				op_table.push_back(to_string(result));
				retval = result;
			}
			else if (operat == "^") {
				// No 0^0
				if (val1 == 0 && val2 == 0) die();
				int result = pow(val1, val2);
				op_table.clear();
				op_table.push_back(to_string(result));
				retval = result;
			}
			else if (operat == "%") {
				// No 0 % 0
				if (val2 == 0) die();
				int result = val1 % val2;
				op_table.clear();
				op_table.push_back(to_string(result));
				retval = result;
			}
		}
	}
	return retval;
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
			if (table.find(vec.at(0)) == table.end()) {
				table[vec.at(0)] = val;
			}
			// We must be trying to redeclare a variable! Bad!
			else {
				die();
			}
		}
		else {
			// Call logic function.
			int result = logic(vec.at(0));
			cout << result << endl;
		}
	}
	return 0;
}
