#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<vector>
#include<stdlib.h>
using namespace std;

void die(){
	cout << "Bad input.\n";
	exit(EXIT_FAILURE);
}

int main(){
	string input;
	string x;
//	Vectors containing operations
	vector<string> string_vec;
	vector<int> value_vec;
	vector<char> op_vec;
	getline(cin, input);

	// This loop breaks down the input
	for( char i : input){
	//	cout << i << endl;
		if (isalpha(i)) x += i; // checks if i is a letter then adds it to the string
		else if (isspace(i)){ // on whitespace pushes the current x onto the vector then clears the x value
			string_vec.push_back(x);
		//	cout << x << endl;
			x.clear();
				}
		//if i is a number and if the current x is 0 
		else if (isdigit(i)&& x.size() == 0 ){
		// atoi()
			char *h = &i;
	 		//value = atoi(h);
			value_vec.push_back(atoi(h)); // converts i to a int and stores it
		}
		else if ( (i == '+' || i == '-' || // checks if i = a sign and x is 0
				  i == '*'  || i == '/')  && x.size() == 0) op_vec.push_back(i);
		else {
			die();
		}
	
	}
	if (string_vec.back() != x){
		string_vec.push_back(x);
		x.clear();
	}
//	cout << x << endl;
	for( string i : string_vec) cout << i << (" ");
//	cout << value << endl;
	for( int i : value_vec) cout << i << (" ");
	for(char i : op_vec) cout << i << (" ");
}
