#include <iostream>
#include <cmath>
using namespace std;



void die() {
	cout << "BAD INPUT\n";
	exit (EXIT_FAILURE);
}

class SpecialInt{
	private:
		int data;

	public:
		SpecialInt(){}


		//Set Function
		void set_data(int new_data) {
			if (data <= 255){
				data = new_data;
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
		}




};


int main(){





	return 0;
}

