#include <iostream>
#include <string>

using namespace std;

class Companie {
	char *nume_companie;
	int nr_angajati;
	int *salariu;
	int departamente;
	const int cod;
	static int orar_companie; // ora la care trebuie sa fie angajatii in companie 
	static int nr_companii;

public:
	void afisare() {
		cout << "Compania " << nume_companie << " dispune de un numar de " << nr_angajati << " angajati.\n Impartiti in " << departamente << " departamente. \n" << "Salariile sunt urmatoarele: " << endl;
		for (int i = 0; i < nr_angajati; i++){
			cout << i + 1 << ". " << salariu[i] << " lei." << endl;
		}
	}

	Companie() :cod(1234) {
		nr_angajati = 3;
		departamente = 2;
		nume_companie = new char[strlen("LUXOFT") + 1];
		strcpy(nume_companie, "LUXOFT");
		salariu = new int[nr_angajati];
		salariu[0] = 6000;
		salariu[1] = 5200;
		salariu[2] = 5000;
		nr_companii++;

	}


	Companie(char *nume_companie, int nr_angajati, int *salariu, int departamente, int new_cod) :cod(new_cod) {

		this->nume_companie = new char[strlen(nume_companie) + 1];
		strcpy(this->nume_companie, nume_companie);
		this->nr_angajati = nr_angajati;
		this->departamente = departamente;
		this->salariu = new int[nr_angajati];
		for (int i = 0; i < nr_angajati; i++) {
			this->salariu[i] = salariu[i];
		}
		nr_companii++;


	}

	~Companie() {

			delete[] nume_companie;
			delete[] salariu;
		nr_companii--;
	}

	void set_nume_companie(char *nume_companie) {
		delete[] this->nume_companie;
		this->nume_companie = new char[strlen(nume_companie) + 1];
		strcpy(this->nume_companie, nume_companie);
	}

	char *get_nume_companie() {
		return nume_companie;
	}

	void set_nr_angajati(int nr_angajati) {
		this->nr_angajati = nr_angajati;
	}
	void set_departamente(int departamente) {
		this->departamente = departamente;
	}
	int get_departamente() {
		return departamente;
	}
	int get_nr_angajati() {
		return nr_angajati;
	}

	void set_salariu(int nr_angajati, int *salariu){
		this->nr_angajati = nr_angajati;
		delete[] this->salariu;
		this->salariu = new int[nr_angajati];
		for (int i = 0; i<nr_angajati; i++)
			this->salariu[i] = salariu[i];
	}
	int *get_salariu() {
		return salariu;
	}

	static void set_orar_companie(int new_orar_companie) {
		orar_companie = new_orar_companie;
	}
	static int get_orar_companie() {
		return orar_companie;
	}

	static int set_nr_companii(int companii) {
		nr_companii = companii;
	}
	static int get_nr_companii() {
		return nr_companii;
	}

	const int get_cod() {
		return cod;
	}

	operator int()
	{
		return nr_angajati;
	}


	Companie operator+ (int val)
	{
		Companie aux = *this;
		aux.departamente += val;
		return aux;
	}

	/*Companie operator+ (Companie obj)
	{
	Companie aux = *this;
	aux.nr_angajati += obj.nr_angajati;
	delete [] aux.salariu;
	this->salariu = new int[nr_angajati];
	for (int i = 0; i<this->nr_angajati; i++)
	aux.salariu[i] = this->salariu[i];

	for (int i = 0; i<obj.nr_angajati; i++)
	aux.salariu[i + this->nr_angajati] = obj.salariu[i];

	return aux;
	}*/

	Companie operator * (int val1) {
		Companie aux = *this;
		aux.departamente = aux.departamente*val1;
		return aux;
	}

	Companie(const Companie &aux) :cod(aux.cod)	{
		this->nume_companie = new char[strlen(aux.nume_companie) + 1];
		strcpy(this->nume_companie, aux.nume_companie);
		this->nr_angajati = aux.nr_angajati;
		this->departamente = aux.departamente;
		this->salariu = new int[nr_angajati];

		for (int i = 0; i<aux.nr_angajati; i++)
			this->salariu[i] = aux.salariu[i];

		nr_companii++;
	}


	Companie operator=(const Companie &obj)	{
		delete[] nume_companie;
		delete[] salariu;
		this->nume_companie = new char[strlen(obj.nume_companie) + 1];
		strcpy(this->nume_companie, obj.nume_companie);
		this->nr_angajati = obj.nr_angajati;
		this->departamente = obj.departamente;
		this->salariu = new int[nr_angajati];

		for (int i = 0; i < obj.nr_angajati; i++)
			this->salariu[i] = obj.salariu[i];

		return *this;

	}

	bool operator>=(Companie aux) {
		bool result = this->departamente >= aux.departamente;
		return result;
	}

	bool operator==(Companie aux) {
		bool result = this->nr_angajati == aux.nr_angajati;
		return result;
	}

	Companie operator++() {
		this->departamente++;
		return *this;
	}

	Companie operator++(int) {
		Companie obj = *this;
		this->departamente;
		return obj;
	}

	int &operator[](int index)
	{
		if (index<this->nr_angajati)
			return salariu[index];
		return salariu[0];
	}

	friend ostream &operator<<(ostream &out, Companie aux);
	friend istream &operator>>(istream &in, Companie &aux);
};

ostream &operator<<(ostream &out, Companie aux) {
	out << "Numele companiei: ";
	out << aux.nume_companie << "\n";
	out << "Numar de angajati: ";
	out << aux.nr_angajati << "\n";

	out << "Cu urmatoarele salarii:\n";
	for (int i = 0; i < aux.nr_angajati; i++) {
		out << i + 1 << ". " << aux.salariu[i] << "\n";
	}
	out << "Cod: ";
	out << aux.cod << "\n";
	out << "Orar companie: ";
	out << aux.orar_companie << "\n";
	out << "Numar companii: ";
	out << aux.nr_companii << "\n";
	out << "Numar departamente: ";
	out << aux.departamente << "\n";

	return out;
}

istream &operator>>(istream &in, Companie &aux) {
	char obj[10];
	cout << "Numele companiei: ";
	in >> obj;
	aux.nume_companie = new char(strlen(obj) + 1);
	strcpy(aux.nume_companie, obj);

	cout << "Numarul de angajati: ";
	in >> aux.nr_angajati;

	cout << "Cu urmatoarele salarii: \n";
	for (int i = 0; i < aux.nr_angajati; i++) {
		cout << i + 1 << ". ";
		in >> aux.salariu[i];
	}
	cout << "Numarul departamentelor: ";
	in >> aux.departamente;

	return in;

}
int operator+(int obiect, Companie obiect1)
{
	return obiect + obiect1.get_departamente();
}

int Companie::orar_companie = 9;
int Companie::nr_companii = 1;

