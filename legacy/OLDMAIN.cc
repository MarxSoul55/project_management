#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;


enum variables{//purpose?
	a = 0,
	b,
	c,
	d,
	e,
	f,
	g,
	h,
	i,
	j,
	k,
	l,
	m,
	n,
	o,
	p,
	q,
	r,
	s,
	t,
	u,
	v,
	w,
	x,
	y,
	z
};

//Die Function
void die() {
	cout << "INVALID INPUT!\n";
	exit (EXIT_FAILURE);
}


//Class for Incrementing Int
class SpecialInt{
	private:
		int data;

	public:
		SpecialInt(){}

		//Set Function
		void set_data(int new_data) {
			if (new_data <= 255){
				data = new_data + 1;//Increment data by 1
			}
			//If data is greater than 255 "BAD INPUT"
			else{
				die();
			}
		}

		//Get Function
		int get_data() {
			if (data <= 255){
				return data;
			}
			//If data is greater than 255 "BAD INPUT"
			else{
				die();
			}
			void increment_data() {
			if (data + 1 > 255) die();
			data++;
		}
		}
};

void uppercaseify(string& mystr) {
	for (auto& c: mystr)
		c = toupper(c);
}

//MAIN
int main(){

	SpecialInt SI;
	unordered_map<string, int> hash;
	string variable_vec; //has to be string, we must allow the user input
                       //more than one variables but error if they do so
	vector<int> value_vec;

	string operation;//Commands (LET & LOOP)
	string variable;//Assign Variable
	char sign;//Operation Sign
	int value = 0;//Value for Variable
	

	while (cin){
		cin >> operation;
		int c = cin.peek();//Peek at next letter
		uppercaseify(operation);
		if (!cin || cin.eof() || operation == "QUIT" || operation == "quit"){
			break;
		}
    
		else if (operation == "LET"){
			//skip whitespace, assign variable, execute sign, assign variable
			cin >> skipws >> variable >> sign >> value;
//kill conditions----------------------------------------------------
    if(variable.size() > 1){//if key isn't single letter
      die();
    }
    if(value < 0 || value > 255){//if data is beyond range
      die();
    }
     if (hash.count(variable)>0){//if key is a duplicate
       die();
     }      
//--------------------------------------------------------------------
		if (sign == '='){
				hash.insert({variable, value});//insert variable and value pair
			}
			
		}

		else if (isalpha(c)){
			if (sign == '+'){
        //got figure out how to pull from variable
			}
			else if (sign == '-'){
       //will be smooth sailing
			}
			else if (sign == '*'){
      //once done
			}
			else if (sign == '/'){

			}
			else if (sign == '^'){

			}
			else if (sign == '%'){

			}
    
		}
		else if (operation == "LOOP"){
			cerr<<"Inside Loop\n";
			
		}
		else{
			die();
		}

	}
	return 0;
}