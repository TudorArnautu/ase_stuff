//constructori de copiere 
//operator =
//opreatori

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

	operator int()
	{
		return nr_participanti;
	}


	concurs operator+(int val)
	{
		concurs aux = *this;
		aux.taxa += val;
		return aux;
	}

	concurs operator+(concurs obj)
	{
		concurs aux = *this;
		aux.nr_participanti += obj.nr_participanti;
		delete[] aux.punctaje;
		aux.punctaje = new float[aux.nr_participanti];

		for (int i = 0; i<this->nr_participanti; i++)
			aux.punctaje[i] = this->punctaje[i];

		for (int i = 0; i<obj.nr_participanti; i++)
			aux.punctaje[i + this->nr_participanti] = obj.punctaje[i];

		return aux;
	}
	void set_nume(char *nume)
	{
		delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	char * get_nume()
	{
		return nume;
	}

	void set_taxa(float taxa)
	{
		this->taxa = taxa;
	}
	float get_taxa()
	{
		return taxa;
	}

	void set_nr_participanti(int nr_participanti)
	{
		this->nr_participanti = nr_participanti;
	}
	int get_nr_participanti()
	{
		return nr_participanti;
	}

	float * get_punctaje()
	{
		return punctaje;
	}
	void set_punctaje(int nr_participanti, float* punctaje)
	{

		this->nr_participanti = nr_participanti;
		delete[] this->punctaje;
		this->punctaje = new float[nr_participanti];

		for (int i = 0; i<nr_participanti; i++)
			this->punctaje[i] = punctaje[i];
	}
	static void set_impozit(float new_impozit)
	{
		impozit = new_impozit;
	}
	static float get_impozit()
	{
		return impozit;
	}

	static int get_nr_concursuri()
	{
		return nr_concursuri;
	}

	const int get_id()
	{
		return id;
	}
	void afisare()
	{
		cout << "La concursul " << nume << " s-au inscris " << nr_participanti << " participanti care au platit o taxa in valoare de " << taxa << " lei, obtinand urmatoarele punctaje :\n";
		for (int i = 0; i<nr_participanti; i++)
			cout << "Participantul " << i + 1 << " a obtinut " << punctaje[i] << " puncte.\n";
	}
	concurs() :id(0)//atribut constant - nu poate fi modificat
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


	concurs(char *nume, float*punctaje, int nr_participanti, float taxa, int id_nou) :id(id_nou)    //atribut constant au doar getter
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

	//constructor de copiere

	concurs(const concurs &aux) :id(aux.id)
	{
		this->nume = new char[strlen(aux.nume) + 1];
		strcpy(this->nume, aux.nume);
		this->nr_participanti = aux.nr_participanti;
		this->punctaje = new float[nr_participanti];
		for (int i = 0; i<aux.nr_participanti; i++)
			this->punctaje[i] = aux.punctaje[i];
		this->taxa = aux.taxa;
		nr_concursuri++;
	}

	//operator 0    b=a
	concurs operator=(const concurs &obj)
	{
		delete[] nume;
		delete[] punctaje;
		this->nume = new char[strlen(obj.nume) + 1];
		strcpy(this->nume, obj.nume);
		this->nr_participanti = obj.nr_participanti;
		this->punctaje = new float[nr_participanti];
		for (int i = 0; i<obj.nr_participanti; i++)
			this->punctaje[i] = obj.punctaje[i];
		this->taxa = obj.taxa;

		return *this;
	}

	bool operator>=(concurs aux)
	{
		bool temp = this->taxa >= aux.taxa;
		return temp;
	}

	bool operator==(concurs aux)
	{
		bool temp = this->nr_participanti == aux.nr_participanti;
		return temp;
	}

	concurs operator++()//preincrementare
	{
		this->taxa++;
		return *this;
	}

	concurs operator++(int)
	{
		concurs aux = *this;
		this->taxa++;

		return aux;
	}

	float &operator[](int index)
	{
		if (index<this->nr_participanti)
			return punctaje[index];
		return punctaje[0];
	}
	friend ostream &operator<<(ostream &c5, concurs obj);
	friend istream &operator>>(istream &c5, concurs &obj);

};

ostream &operator<<(ostream &c5, concurs obj)
{
	c5 << obj.nume << "\n ";
	c5 << obj.taxa << "\n ";
	c5 << obj.nr_participanti << "\n ";

	for (int i = 0; i<obj.nr_participanti; i++)
		c5 << obj.punctaje[i] << " ";
	c5 << "\n" << obj.id << " " << obj.impozit;
	return c5;

}

istream &operator>>(istream &c5, concurs &obj)
{
	char aux[20];
	cout << "Dati numele :"; c5 >> aux;
	obj.nume = new char[strlen(aux) + 1];
	strcpy(obj.nume, aux);
	cout << "Taxa este de "; c5 >> obj.taxa;
	cout << "Numarul de participanti este "; c5 >> obj.nr_participanti;

	cout << "Punctajele pentru cei " << obj.nr_participanti << " participanti sunt: ";
	for (int i = 0; i<obj.nr_participanti; i++)
		c5 >> obj.punctaje[i];
	return c5;

}


float concurs::impozit = 10;
int   concurs::nr_concursuri = 0;

int operator+(int a, concurs b)
{
	return a + b.get_taxa();
}
void main()
{
	//SEMINAR 3
	/*float v[3]={10,9,7.5};
	concurs d("Fizica",v,3,450);

	concurs part;

	d.afisare();

	float x[3]={5,23,75};
	char numep[3][10]={"Mate","Info","Fizica"};
	float taxe[3]={100,250,375};


	for(int i=0;i<=2;i++)
	{
	//aceasta parte va merge dupa ce invatam constructorul de copiere si operatorul =
	//part=concurs (numep[i],x,3,taxe[i]);
	part.afisare();
	}
	*/


	//SEMINAR 4
	//concurs a;

	// getter : char * gt_nume()
	//          {return nume;}

	//cout<<a.get_nume()<<"\n";

	//setter : void set_nume(char *nume)
	//         {delete [] this->nume;
	//          this->nume = new char[strlen(nume)+1];
	//          strcpy(this->nume,nume)}

	/*a.set_nume("Informatica in c++");

	cout<<a.get_nume()<<"\n";

	cout<<a.get_taxa()<<"\n";

	a.set_taxa(780);
	cout<<a.get_taxa()<<"\n";

	float *v;
	int nr;
	nr=a.get_nr_participanti();
	v=a.get_punctaje();

	for(int i=0;i<nr;i++)
	cout<<"Participantul "<<i+1<<" a obtinut punctajul "<<v[i]<<".\n";

	//atributul static apartine clasei.nu trebuie sa avem o instanta a clasei. un obiect
	//putem accesa direct prin numele clasei.. ex: concurs::
	//pentru a defini: in private : static : ....
	//atributele statice se initializeaza in afara clasei si in afara oricaror altor functii

	a.get_impozit();//concurs::get_impozit();

	cout<<concurs::get_impozit()<<"\n";
	*/


	//SEMINAR 5

	//concurs b=a;
	/*concurs a;
	concurs b;
	a.set_nume("Programare");
	a.set_taxa(125);
	b = a;
	*/
	concurs a;
	//concurs k;
	//int b;
	//b=a;//implicit
	//b=(int)a explicit
	//cout<<b<<"\n";

	//operatorul +

	//k=a+3;//se modifica taxa
	//cout<<k.get_taxa()<<"\n";

	concurs b;
	concurs c;
	//c = a + b;

	////c.afisare();
	//cout<<c;


	//SEMINAR 6
	/*concurs z;
	cout << "\n";
	cin >> z;
	cout << "\n";

	cout<<z;*/
	/*
	cout<<"\nTaxa cea mai mare este: ";
	if(c>=b) cout<<c.get_taxa();
	else cout<<b.get_taxa();*/

	if(b==c)cout<<"\nConcursul de "<<b.get_nume()<<"are acelasi numar de partcipanti ca si concursul de "<<c.get_nume();
	else cout << "\nCele doua concursuri nu au acelasi numar de participanti."; 
	
	/*c=b++;
	c.afisare();

	c++;
	c.afisare();*/

	/*int x = b[2];
	b[2] = 6;

	cout << x << " " << b[2] << "\n";
	x = x + a;
	cout << x;*/
}