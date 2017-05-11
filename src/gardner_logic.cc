#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;


enum variables{
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
			if (data <= 255){
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
			return 0;
		}
};




int addition(int data){	
	
}

void uppercaseify(string& mystr) {
	for (auto& c: mystr)
		c = toupper(c);
}

//MAIN
int main(){

	SpecialInt SI;
	unordered_map<char, int> hash;
	vector<char> variable_vec;
	vector<int> value_vec;

	string operation;//Commands (LET & LOOP)
	char variable;//Assign Variable
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
			cin >> variable;
			//skip whitespace, assign variable, execute sign, assign variable
			cin >> skipws >> variable >> sign >> value;
			if (sign == '='){
				
			}
			
		}
		else if (isalpha(c)){
			if (sign == '+'){

			}
			else if (sign == '-'){

			}
			else if (sign == '*'){

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


/*
 
#include <string>
#include <iostream>
#include <unordered_map>
 using namespace std;
   
 void die(){
 	cout << "BAD INPUT" << endl;
exit(1);
}

int main ()
{
unordered_map<string, int> hash;
while(cin){
string key = "";
string confirm = "";
string operat = "";
int data = -1;

cin >> confirm >> key >> operat >> data;//find better method, check input
for(char& Char : confirm) Char = toupper(Char);//needed?
  
//kill conditions----------------------------------------------------
if(key.size() > 1){//if key isn't single letter
die();
}
if(data < 0 || data > 255){//if data is beyond range
die();
}
if (confirm == "" || key == "" || operat != "=" || data < 0){//if data input isn't proper
die();                                                      //will look into alt methods
}
if (hash.count(key)>0){//if key is a duplicate
die();
}
//If input is proper-------------------------------------------------
if (confirm == "LET"){
hash.insert({key,data}); 
cout << "contents:\n";
for(auto& i: hash){//see whats in the hashtable
cout << " " << i.first << " => " << i.second << '\n';
}
} 
}
}
*You will read one line of input at a time. The input will be in one of three
* forms:
* 1) Create a variable. All variables are single letters, like x or y. They can
* hold values only between 0 and 255. - DONE
* Valid Example: LET x = 7 - DONE
* Error: LET x = 9 (you can't redeclare a variable - x is already declared to be 7.) - DONE
* Error: LET bob = 27 (bob is 3 letters) - DONE
* Error: LET y = 300 (300 is out of range) - DONE
* Error: z = 2 (forgot the LET) - DONE
* On an error, print "BAD INPUT" and quit. You should probably make a die()
* function.
*/
