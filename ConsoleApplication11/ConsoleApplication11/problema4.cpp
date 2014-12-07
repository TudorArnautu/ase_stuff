# include <iostream>
using namespace std;

class concurs
{
	int nr_participanti;
	char *nume;
	float *punctaje;
	float taxa;


public:

	void afisare()
	{
		cout << "La concursul " << nume << " s-au inscris " << nr_participanti << " participanti care au platit o taxa in valoare de " << taxa << " lei, obtinand urmatoarele punctaje :\n";
		for (int i = 0; i<nr_participanti; i++)
			cout << "Participantul " << i + 1 << " a obtinut " << punctaje[i] << " puncte.\n";
	}
	concurs()
	{

		nr_participanti = 3;
		nume = new char[strlen("Informatica") + 1];
		strcpy(nume, "Informatica");
		punctaje = new float[nr_participanti];
		punctaje[0] = 10;//for(int i=0;i<nr_participanti;i++)
		punctaje[1] = 9;
		punctaje[2] = 7.5;
		taxa = 450;
	}


	concurs(char *nume, float*punctaje, int nr_participanti, float taxa)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->taxa = taxa;
		this->nr_participanti = nr_participanti;
		this->punctaje = new float[nr_participanti];
		for (int i = 0; i<nr_participanti; i++)
			this->punctaje[i] = punctaje[i];

	}

	~concurs()
	{
		delete[] nume;
		delete[] punctaje;
	}

};

void main()
{

	float v[3] = { 10, 9, 7.5 };
	concurs d("Fizica", v, 3, 450);

	concurs part;

	d.afisare();

	float x[3] = { 5, 23, 75 };
	char numep[3][10] = { "Mate", "Info", "Fizica" };
	float taxe[3] = { 100, 250, 375 };

	for (int i = 0; i <= 2; i++)
	{
		part = concurs(numep[i], x, 3, taxe[i]);
		part.afisare();
	}
}