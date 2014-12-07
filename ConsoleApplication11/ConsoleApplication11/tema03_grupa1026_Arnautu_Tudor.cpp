#include <iostream>
#include <string>

using namespace std;

class Companie {
	char *nume_companie;
	int nr_angajati;
	int *salariu;
	const int cod;
	static int orar_companie; // ora la care trebuie sa fie angajatii in companie 
	static int nr_companii;

public:
	void afisare() {
		cout << "Compania " << nume_companie << " dispune de un numar de " << nr_angajati << " angajati.\n " << "Salariile sunt urmatoarele: "<<  endl;
		for (int i = 0; i < nr_angajati; i++){
			cout << i+1 << ". " << salariu[i] << " lei." << endl;
		}
	}

	Companie() :cod(1234) {
		nr_angajati = 3;
		nume_companie = new char[strlen("LUXOFT") + 1];
		strcpy(nume_companie, "LUXOFT");
		salariu = new int[nr_angajati];
		salariu[0] = 6000;
		salariu[1] = 5200;
		salariu[2] = 5000;
		nr_companii++;
		
	}


	Companie(char *nume_companie, int nr_angajati, int *salariu, int salariu_ora, int new_cod):cod(new_cod) {

		this->nume_companie = new char[strlen(nume_companie) + 1];
		strcpy(this->nume_companie, nume_companie);
		this->nr_angajati = nr_angajati;
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

	
	float ore() {
		return ore_lucrate();
	}

	float salariu_ora() {
		for (int i = 0; i < nr_angajati; i++) {
			this->salariu[i] = salariu[i];
			float s = salariu[i] / ore();
			cout << "Angajatii  sunt platiti cu "<< s << " lei pe ora." << endl;
	return s;
		}		
	}

	
	void set_nume_companie(char *nume_companie) {
		delete this->nume_companie;
		this->nume_companie = new char [strlen(nume_companie) + 1];
			strcpy(this->nume_companie, nume_companie);
	}                                                                                                                                                                                                                                                                                                                                                                                        

	char *get_nume_companie() {
		return nume_companie;
	}

	void set_nr_angajati(int nr_angajati) {
		this->nr_angajati = nr_angajati;
	}
	int get_nr_angajati() {
		return nr_angajati;
	}

	void set_salariu(int nr_angajati, int *salariu){
		this->nr_angajati = nr_angajati;
		delete this->salariu;
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


	Companie operator+(int val)
	{
		Companie aux = *this;
		aux.salariu += val;
		return aux;
	}

	Companie operator+(Companie obj)
	{
		Companie aux = *this;
		aux.nr_angajati += obj.nr_angajati;
	
		this->salariu = new int[nr_angajati];
		for (int i = 0; i<this->nr_angajati; i++)
			aux.salariu[i] = this->salariu[i];

		for (int i = 0; i<obj.nr_angajati; i++)
			aux.salariu[i + this->nr_angajati] = obj.salariu[i];

		return aux;
	}

	Companie operator *(int inmultit) {
		Companie aux = *this;
		aux.nr_angajati = aux.nr_angajati*inmultit;
		return aux;
	}

	Companie(const Companie &aux) :cod(aux.cod)
	{
		this->nume_companie = new char[strlen(aux.nume_companie) + 1];
		strcpy(this->nume_companie, aux.nume_companie);
		this->nr_angajati = aux.nr_angajati;
		this->salariu = new int[nr_angajati];
		
		for (int i = 0; i<aux.nr_angajati; i++)
			this->salariu[i] = aux.salariu[i];
		
		nr_companii++;
	}

	
	Companie operator=(const Companie &obj)
	{
		delete[] nume_companie;
		delete[] salariu;
		this->nume_companie = new char[strlen(obj.nume_companie) + 1];
		strcpy(this->nume_companie, obj.nume_companie);
		this->nr_angajati = obj.nr_angajati;
		this->salariu = new int[nr_angajati];
		
		for (int i = 0; i<obj.nr_angajati; i++)
			this->salariu[i] = obj.salariu[i];
		

		return *this;
	}
	

private:
	float ore_lucrate() {
		int ore;
		ore = 20 * 8;  // zile_luna * ore pe zi.
		cout << "Angajatii lucreaza " << ore << " ore pe luna ." << endl;
	return ore;
	}


};


int Companie::orar_companie = 9;
int Companie::nr_companii = 1;




int main() {
	
	Companie afis_obiect = Companie();
	/*
	//afis_obiect.afisare();

	int x[3] = { 3000, 5000, 6300 };
	Companie afisare_obiect("Luxoft", 3, x, 3);

	afis_obiect.afisare();
    afis_obiect.ore();
	afis_obiect.salariu_ora(); 

	afis_obiect.set_nume_companie("SNS");
	cout << afis_obiect.get_nume_companie() << endl;

	int *salariu;
	int nr;
	salariu = afis_obiect.get_salariu();
	nr = afis_obiect.get_nr_angajati();
	for (int i = 0; i<nr; i++)
		cout << "Angajatul " << i + 1 << " are salariul de " << salariu[i] << endl;

	afis_obiect.get_orar_companie();
	cout << "Angajatii trebuie sa fie la serviciu la ora: " << Companie::get_orar_companie() << endl;

	afis_obiect.get_nr_companii();
	cout << "Numar companii: " << Companie::get_nr_companii() << endl;

	afis_obiect.get_cod();
	cout << "Codul este:" << afis_obiect.get_cod() << endl;
	*/

	Companie a;
	Companie b;
	Companie c;

	c = a + b;
	c.afisare();

	Companie d;
	Companie e;
	d = e * 3;
	d.afisare();


	return 0;
}