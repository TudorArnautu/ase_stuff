#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

class Medic {
	char* nume;
	int nrPacienti;
	static int nrMedici;

public:
	int varsta;
	bool rezident;

	Medic():nrPacienti(0), varsta(0),rezident(false) {
		cout << "apel constructor def" << endl;
		nume = NULL;

	}

	Medic(char* n, int p, int v, bool r) :nrPacienti(p), varsta(v), rezident(r) {
		cout << "apel constructor param" << endl;
		if (n) {
			nume = new char[strlen(n) + 1];
			strcpy(nume, n);
		}
		else
			nume = NULL;
	}

	Medic(const Medic& m) {
		cout << "apel copy constructor" << endl;
		this->nrPacienti = nrPacienti;
		this->varsta = m.varsta;
		if (m.nume) {
			this->nume = new char[strlen(m.nume) + 1];
			strcpy(this->nume, m.nume);
		}
		else {
			this->nume = NULL;
		}
	}

	Medic operator=(const Medic& m) {
		cout << "apel operator egal" << endl;
		this->nrPacienti = m.nrPacienti;
		this->varsta = m.varsta;
		if (this->nume) {
			delete[] this->nume;
			this->nume = new char[strlen(m.nume) + 1];
			strcpy(this->nume, m.nume);
		}
		else {
			this->nume = NULL;
		}
		return (*this);
	}

	~Medic() {

		cout << "apel destructor" << endl;
		if (this->nume) {
			delete[] this->nume;
		}
	}

	Medic operator!() {
		if (this->rezident) {
			rezident = false;
		}
		else {
			rezident = true;
		}
		return (*this);
	}
};
		

int main() {
	Medic m1;//constructor def
	Medic m2("ionescu", 100, 34,true);
	m2 = !m2;
	Medic m3 = m1;
	Medic m4;
	m4 = m2;



	/*char *c = 0;
	char *d= new char;
	if (c) {
		cout << "c == NULL";
	}
	if(d) {
		cout << "d ! Null";
	}*/

	//definire pointer la membru in clasa
	int Medic::*pmembru;
	//initializare pointer la membru
	pmembru = &Medic::varsta;
	//apel/utilizare pointer la membru
	cout << m1.*pmembru << "   "<< m2.*pmembru;
		
	Medic* pm1 = &m1;  
	Medic** pm2 = new Medic*[5];
	Medic* pm3 = new Medic[5]; 
	Medic* pm4 = new Medic("Ionescu", 23, 32, true);
	cout << "============";
	delete[] pm3;


	return 0;
}