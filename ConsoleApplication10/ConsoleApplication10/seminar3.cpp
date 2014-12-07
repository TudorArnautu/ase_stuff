#include <iostream>
#include <string>

using namespace std;

class concurs {
	int nr_participanti;
	char *nume;
	float *punctaje;
	float taxa;

public:
	concurs() {
		nr_participanti = 100;
		nume = new char[strlen("romana")];
		strcpy(nume, "romana");
		punctaje = new float[nr_participanti];
		punctaje[0] = 10;
		punctaje[1] = 9;
		punctaje[2] = 8;
		taxa = 70;


	}


	void afisare() {
		cout << "Concursul " << nume << " cu taxa de inscriere de " << taxa << " lei " << " s-au obtinut punctajele: " <<  "\n";
		for (int i = 0; i < nr_participanti; i++)
			cout << punctaje[i] << " ";

	}
};

int main(){

	concurs a;

	a.afisare();

	return 0;
}
