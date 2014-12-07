/*clasa locuinta 
-suprafata
-nr camere
-tip locuinta
-adresa
-nr locatari*/

#include<iostream>
#include<string>

using namespace std;

 class locuinta {

 public:
	 float suprafata;
	 int nr_camere;
	 char *tip;
	 char *adresa;
	 int nr_locatari;

	 
	 
	float metri(){
		 return suprafata / nr_locatari;
	 }

	private: void afisare() {
		 cout << "Casa este de tip " <<tip << " si are un numar de camere " << nr_camere << " cu un numar de locatari de " << nr_locatari << " si cu o suprafata de " << suprafata << " cu adresa " << adresa << "\n";
	 }

 public:
	 void metoda(){
		return afisare();

	}


 };

 int main() {

	 locuinta casa;
	 locuinta casa1;
	 casa.nr_camere = 3;
	 casa.nr_locatari = 7;
	 casa.suprafata = 80.5; 
	 /*strcpy(aux,"apartament");
	 casa.tip = new char[strlen(aux)];*/
	 casa.tip = (char*)malloc(sizeof(char)* 10);
	 casa.adresa = (char*)malloc(sizeof(char)* 20);
	 strcpy(casa.tip, "garsoniera");
	 strcpy(casa.adresa, "Mihai Eminescu");

	 char s[20];
	 casa1.tip = new char[10];
	 casa1.adresa = new char[20];

	 cout << "Tipul locuintei este: "; cin >>s;
	 strcpy(casa1.tip, s);
	 cout << "Numarul de camere este: "; cin >> casa1.nr_camere;
	 cout << "Numarul de locatari este: "; cin >> casa1.nr_locatari;
	 cout << "Suprafata este de: "; cin >> casa1.suprafata;

	 cout << "Adresa este: "; cin >> s;
	 cin.get();
	 strcpy(casa1.adresa, s);

	 //cout << "Casa este de tip " << casa1.tip << " si are un numar de camere " << casa1.nr_camere << " cu un numar de locatari de " << casa1.nr_locatari << " si cu o suprafata de " << casa1.suprafata << " cu adresa " << casa1.adresa << "\n";

	 casa1.metoda();
	 cout << "Fiecare locatar dispune de o suprafata de " << casa1.metri() << " patrati.\n";

	 return 0;
 }