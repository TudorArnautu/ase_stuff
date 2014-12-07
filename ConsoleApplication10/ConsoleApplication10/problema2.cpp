#include <iostream>
#include <string>
using namespace std;

typedef struct masina{
	char *tip_caroseie;
	char *marca;
	int nr_scaune;
	char *nr_inmatriculare;
	int an_fabricatie;
}EX;

void write(EX add){
	cout << "Autosurism marca " << add.marca << " " << add.tip_caroseie <<" cu " << add.nr_scaune << " scaune " << " an fabricatie " << add.an_fabricatie << " cu numarul de inmatriculare " << add.nr_inmatriculare << ".\n";
	

	
}

int main(){

	EX add1;
	char s[20];
	add1.marca = new char[20];
	add1.tip_caroseie = new char[20];
	add1.nr_inmatriculare = new char[20];
	
	cout << "Marca: "; cin >> s;
	strcpy(add1.marca, s);
	cout << "Tipul caroseriei: "; cin >> s;
	strcpy(add1.tip_caroseie, s);
	cout << "Numarul de scaune: "; cin >> add1.nr_scaune ;
	cout << "An fabricatie: "; cin >> add1.an_fabricatie;
	cout << "Numarul de inmatriculare: "; cin >> s; 
	strcpy(add1.nr_inmatriculare, s);
	write(add1);

	return 0;
}