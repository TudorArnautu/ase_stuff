#include <iostream>
#include <string>
using namespace std;

class masina{
public:
	char *tip_caroseie;
	char *marca;
	int nr_scaune;
	char *nr_inmatriculare;
	int an_fabricatie;
	int km; // km calatorie
	float consum_l; //consum litri/100km
	float nr_litri;



	void metoda(){
		return afisare();
	}
	float consum(){

		return  consum_l / 100 * km;
	}


private:
	void afisare(){
		cout << "Autosurism marca " << marca << " " << tip_caroseie << " cu " << nr_scaune << " scaune " << "an fabricatie " << an_fabricatie << " cu numarul de inmatriculare " << nr_inmatriculare << ".\n";
	}

};




	int main(){

		masina add;

		char s[20];
		add.tip_caroseie = new char[10];
		add.marca = new char[10];
		add.nr_inmatriculare = new char[10];

		cout << "Marca autoturismului: "; cin >> s;
		strcpy(add.marca, s);
		cout << "Tipul caroseriei: "; cin >> s;
		strcpy(add.tip_caroseie, s);
		cout << "Numarul de scaune: "; cin >> add.nr_scaune;
		cout << "An fabricatie: "; cin >> add.an_fabricatie;
		cout << "Numar de inmatriculare: "; cin >> s;
		strcpy(add.nr_inmatriculare, s);
		cout << "Pentru a afla consumul de combustibil pentru o eventuala calatorie , specificati numarul de km:"; cin >> add.km; 
		cout << "Si consumul la 100 km "; cin >> add.consum_l; cout << "\n";
		cout << "\n";

		add.metoda();
		
		cout << "Pentru o calatorie de " << add.km << " km " << "aveti nevoie de: " << add.consum() << " litri de combustibil.\n";
		
		
		return 0;
	}
