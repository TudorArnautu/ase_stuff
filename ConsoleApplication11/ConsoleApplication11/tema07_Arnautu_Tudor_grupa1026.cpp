#include "tema7.h"

class Companie_asociata : public Companie {
	char *oras;
	int departamente1;
	const int cod;
	static int numar;

public:

	Companie_asociata() :cod(123), Companie(){
		oras = new char[strlen("Bucuresti") + 1];
		strcpy(oras, "Bucuresti");
		departamente1 = 2;
		
	}

	Companie_asociata(char *oras, int departamente1, int new_cod1, char *nume_companie, int nr_angajati, int *salariu, int departamente, int new_cod) :cod(new_cod1), Companie(nume_companie, nr_angajati, salariu, departamente, new_cod) {
		this->oras = new char[strlen(oras) + 1];
		strcpy(this->oras, oras);
		this->departamente1 = departamente1;
	}

	~Companie_asociata() {
		delete[] oras;
	}

	Companie_asociata(const Companie_asociata &aux):cod(aux.cod), Companie(aux)
	{
		this->oras = new char[strlen(aux.oras) + 1];
		strcpy(this->oras, aux.oras);

		this->departamente1 = aux.departamente1;
	}

	void set_oras(char *oras) {
		delete[] this->oras;
		this->oras = new char[strlen(oras) + 1];
		strcpy(this->oras, oras);
	}

	char *get_oras() {
		return oras;
	}

	void set_departamente1(int departamente1) {
		this->departamente1 = departamente1;
	}

	int get_departamente1() {
		return departamente1;
	}
	Companie_asociata operator++()
	{
		this->departamente1++;
		return *this;
	}

	Companie_asociata operator++(int)
	{
		Companie_asociata aux = *this;
		this->departamente1++;
		return aux;
	}

	bool operator==(Companie_asociata obj)
	{
		bool temp = this->departamente1 == obj.departamente1;
		return temp;
	}


	friend ostream &operator<<(ostream &out, Companie_asociata obj);

};

int Companie_asociata::numar = 9;

ostream &operator<<(ostream &out, Companie_asociata obj) {
	out << obj.oras;
	out << obj.departamente1;
	out << (Companie)obj;

	return out;
}



int main() {
	Companie_asociata obiect;

	cout << obiect;

	int v[] = { 5000, 4366, 7654 };
	Companie_asociata obiect1("Bucuresti",3,3,"Luxoft",3,v,3,2);
	cout << obiect1 << "\n";


	 Companie_asociata obiect2;
	 if (obiect2 == obiect1)cout << "Au acelasi numar de departamente.\n";
	else cout << "Nu au acelasi numar de departamente.\n";

	obiect2++;
	cout << obiect2 << endl;

	Companie_asociata obiect3 = obiect2++;
	cout << obiect3 << endl;


	
	return 0;
}