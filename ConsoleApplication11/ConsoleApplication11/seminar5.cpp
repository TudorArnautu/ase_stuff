//getturi si setteri
//atribut static
//atribute constante

#include <iostream>
#include <string>
using namespace std;

class concurs
{
	int nr_participanti;
	char *nume;
	float *punctaje;
	float taxa;
	const int id;

	static float impozit;
	static int nr_concursuri;


public:

	operator int() {
		return nr_participanti;
	}

	concurs operator+(int val) {
		concurs aux = *this;
		aux.taxa +=val;
		return aux;
	}

	concurs operator+(concurs obj) {
		concurs aux = *this;
		aux.nr_participanti+= obj.nr_participanti;
		delete[] aux.punctaje;
		aux.punctaje = new float[aux.nr_participanti];

		for (int i = 0; i < this->nr_participanti; i++) {
			aux.punctaje[i] = this->punctaje[i];
		}

		for (int i = 0; i < obj.nr_participanti; i++){
			aux.punctaje[i+this->nr_participanti] = obj.punctaje[i];
		}
		return aux;
	}

	void afisare()
	{
		cout << "La concursul " << nume << " s-au inscris " << nr_participanti << " participanti care au platit o taxa in valoare de " << taxa << " lei, obtinand urmatoarele punctaje :\n";
		for (int i = 0; i<nr_participanti; i++)
			cout << "Participantul " << i + 1 << " a obtinut " << punctaje[i] << " puncte.\n";
	}
	concurs() :id(0)
	{

		nr_participanti = 3;
		nume = new char[strlen("Informatica") + 1];
		strcpy(nume, "Informatica");
		punctaje = new float[nr_participanti];
		punctaje[0] = 10;//for(int i=0;i<nr_participanti;i++)
		punctaje[1] = 9;
		punctaje[2] = 7.5;
		taxa = 450;

		nr_concursuri++;
	}


	concurs(char *nume, float*punctaje, int nr_participanti, float taxa, int id_nou) :id(id_nou)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->taxa = taxa;
		this->nr_participanti = nr_participanti;
		this->punctaje = new float[nr_participanti];
		for (int i = 0; i<nr_participanti; i++)
			this->punctaje[i] = punctaje[i];

		nr_concursuri++;

	}

	~concurs()
	{
		delete[] nume;
		delete[] punctaje;
		nr_concursuri--;
	}

	concurs(const concurs &aux):id(aux.id) {
		this->nume = new char[strlen(aux.nume) + 1];
		strcpy(this->nume, aux.nume);
		this->nr_participanti = aux.nr_participanti;
		this->punctaje = new float(nr_participanti);
		for (int i = 0; i<aux.nr_participanti; i++)
			this->punctaje[i] = aux.punctaje[i];
		this->taxa = taxa;
		nr_concursuri++;
	}

	concurs operator = (const concurs &obj)  {
		delete[] nume;
		delete[] punctaje;
		this->nume = new char[strlen(obj.nume) + 1];
		strcpy(this->nume, obj.nume);
		this->nr_participanti = obj.nr_participanti;
		this->punctaje = new float(nr_participanti);
		for (int i = 0; i < nr_participanti; i++) {
			this->punctaje[i] = obj.punctaje[i];
		}

		this->taxa = obj.taxa;
	

		return *this;
	}


	char * get_nume() {
		return nume;
	}

	void set_nume(char *nume) {
		delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	
	float get_taxa() {
		return taxa;
	}

	void set_taxa(float taxa) {
		this->taxa = taxa;
	}

	
	static void set_impozit(float impozit_nou) {
		impozit_nou = impozit;
	}

	static float get_impozit() {
		return impozit;
	}

	static int get_nr_concursuri(){
		return nr_concursuri;
	}

	void set_nr_participanti(int nr_participanti) {
		this->nr_participanti = nr_participanti;
	}

	int get_nr_participanti() {
		return nr_participanti;
	}

	float *get_punctaje() {
		return punctaje;
	}

	void set_punctaje(int nr_participanti, float *punctaje) {
		this->nr_participanti = nr_participanti;
		delete[] this->punctaje;
		this->punctaje = new float[nr_participanti];

		for (int i = 0; i < nr_participanti; i++) {
			this->punctaje = punctaje;
		}
	}

	const int get_id() {
		return id;
	}

};

float concurs::impozit = 10;
int concurs::nr_concursuri = 0;

void main()
{

	
	concurs a;
	concurs b;
	//a.set_nume("Concurs");
	//b = a;

	//cout << b << endl;
	concurs c;

	c = a + b;
	c.afisare();
}