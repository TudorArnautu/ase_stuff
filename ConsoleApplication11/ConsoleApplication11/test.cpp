#include<iostream>
#include<string>

using namespace std;


class masina
{
private:


public: int nr_roti, nr_usi;
		float cc;
		char *culoare, *model;
		void afisare() {
			cout<< nr_roti << " " << nr_usi << " " << cc << " " << culoare << " " << model;
		}
		

};

void main()
{
	masina b;
	b.nr_roti = 4;
	b.nr_usi = 5;
	b.cc = 1800;
	b.culoare = new char[strlen("alb")];
	strcpy(b.culoare, "alb");
	b.model = new char[strlen("bmw")];
	strcpy(b.model, "bmw");
	cout << b.nr_roti << " " << b.nr_usi << " " << b.cc << " " << b.culoare << " " << b.model;

	masina c;
	cin >> c.nr_roti;
	cin >> c.nr_usi;
	cin >> c.cc;
	char aux[100];
	cout << "Culoarea este:";
	cin >> aux;
	c.culoare = new char[strlen(aux)];
	strcpy(c.culoare, aux);
	char aux1[100];
	cout << "Modelul este:";
	cin >> aux1;
	c.model = new char[strlen(aux1)];
	strcpy(c.model, aux1);
	cout << c.nr_roti << " " << c.nr_usi << " " << c.cc << " " << c.culoare << " " << c.model;
	cout << endl;
	b.afisare();
	c.afisare();
}