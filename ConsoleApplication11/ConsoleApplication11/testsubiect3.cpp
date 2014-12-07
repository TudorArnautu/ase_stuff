#include<iostream>
#include<string>

using namespace std;

class Jurnal{
	char *denumire;
	int nr_numere;
	int *articole_pe_numar;
	float pret;
	const int ISSN;

public:
	void afisare() {
		cout << "Jurnalul cu numele " << denumire << " ,la un pret de " << pret << " si ISSN - ul " << ISSN << ", cu " << nr_numere << " numere "<<" si urmatoarele articole pe numar" << endl;
		cout << "     \n================================\n" << endl;
		for (int i = 0; i < nr_numere; i++) {
			cout << "Articolul cu numarul " <<i + 1 << " are " << articole_pe_numar[i]<< " articole." << endl;
		}
	}


	Jurnal() :ISSN(4) {
		denumire = new char[strlen("Jurnalul") + 1];
		strcpy(denumire, "Jurnalul1");
		nr_numere = 3;
		pret = 20;
		articole_pe_numar = new int[nr_numere];
		articole_pe_numar[0] = 3;
		articole_pe_numar[1] = 6;
		articole_pe_numar[2] = 22;
		
	}

	Jurnal(char *denumire, int nr_numere, int *articole_pe_numar, float pret, int new_ISSN) :ISSN(new_ISSN) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->nr_numere = nr_numere;
		this->pret = pret;
		this->articole_pe_numar = new int[nr_numere];
		for (int i = 0; i < nr_numere; i++) {
			cout << i + 1 << ". " << this->articole_pe_numar[i] << endl;
		}
	}

};


int main() {

	Jurnal obiect;

	obiect.afisare();

	return 0;
}