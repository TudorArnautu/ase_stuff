#include <iostream>
#include <string>
#define TRUE 1;
#define FALSE 0;
#define BOOL int;

using namespace std;

class BigNumber{
protected:
	string value;
	int length;
	bool IsNegative;

public:
	BigNumber(string value){

		this->value = value;
		this->length = length;
		this->IsNegative = false;
	}

	void SetValue(string value){
		this->value = value;
	}

	string getValue(){
		return this->value;
	}

	string ToString(){
		if (this->getValue == true){
			return "-" + this->getValue;
		}
		return this->getValue;
	}

	BigNumber clone(){
		BigNumber clone = new BigNumber(this->getValue());
		clone.IsNegative(this->getIsNegative());

		return clone;
	}

	

	


};

int main(){


	return 0;
}