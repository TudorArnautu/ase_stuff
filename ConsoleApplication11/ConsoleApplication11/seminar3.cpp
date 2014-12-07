#include <iostream>
#include <string>

using namespace std;

class concurs {
	int nr_participanti;
	char *nume;
	float *punctaje;
	float taxa;

public:
	
	void afisare() {
		cout << "Concursul " << nume << " cu taxa de inscriere de " << taxa << " lei " << " s-au obtinut punctajele: " << "\n";
		for (int i = 0; i < nr_participanti; i++)
			cout << "Participantul " <<i+1 << " are " << punctaje[i] << " puncte.\n ";

	}

	concurs() {
	nr_participanti = 3;
	nume = new char[strlen("romana") + 1];
	strcpy(nume, "romana");
	punctaje = new float[nr_participanti];
	punctaje[0] = 10;
	punctaje[1] = 9;
	punctaje[2] = 8;
	taxa = 70;
	}
	

	concurs(char *nume, float *punctaje, int nr_participanti, float taxa) {
		this->nume = new char[strlen(nume)];
		strcpy(this -> nume, nume);
		this->taxa = taxa;
		this->nr_participanti = nr_participanti;
		this->punctaje = new float[nr_participanti];

		for (int i = 0; i < nr_participanti; i++) {
			this->punctaje[i] = punctaje[i];
		}
	}

	~concurs() {
		cout << "\nS-a apelat destructorul.\n ";
		delete[] nume;
		delete[] punctaje;
	}
};

int main() {

	{
		concurs z;
	}

	concurs a;
	
	float v[3] = { 9, 8, 7 };

	concurs d("romana", v, 3, 70);
	d.afisare();

	concurs b[3];
	float x[3] = { 4, 5, 3 };
	

	for (int i = 0; i <= 2; i++){
		b[i].afisare();	
	
	}

	
	
	return 0;
}
