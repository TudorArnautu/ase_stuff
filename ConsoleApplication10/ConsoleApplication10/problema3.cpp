#include <iostream>
#include <string>
using namespace std;

class numere{
public:
	int a;
	int b;
	

public:
	numere add1(int, int) {
		this.a = a;
		this.b = b;
		
	}

	int adunare(add2){
		int new_a = a + add2.a; int new_b = b + add2.b;
		return numere(new_a, new_b)
	}
};

int main(){

	numere add1, add2;

	cout << "a = "; cin >> add1.a;
	cout << "b = "; cin >> add1.b;

	add1.adunare();
	cout << "Rezultatul adunarii este: " << add1.adunare();

}

