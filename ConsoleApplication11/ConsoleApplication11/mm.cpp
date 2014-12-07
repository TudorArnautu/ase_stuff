#include <iostream>
#include <stdio.h>
using namespace std;

class magazin
{
private:
	char *nume;
	int nr_angajati;
	double *profit;
	int nr_ani;
	const int cod;

	static float tva;
	static int nr_magazine;

public:

	operator int()
	{
		return nr_ani;
	}
	magazin operator-(int val)
	{
		magazin t = *this;
		t.nr_angajati -= val;
		return t;
	}
	magazin operator-(magazin obj)
	{
		magazin t = *this;
		t.nr_ani -= obj.nr_ani;
		delete[] t.profit;
		t.profit = new double[t.nr_ani];
		for (int i = 0; i<this->nr_ani; i++)
			t.profit[i] = this->profit[i];
		for (int i = 0; i<obj.nr_ani; i++)
			t.profit[i + this->nr_ani] = obj.profit[i];
		return t;
	}

	char *get_nume()
	{
		return nume;
	}
	void set_nume(char *nume)
	{
		delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	int get_nr_angajati()
	{
		return nr_angajati;
	}
	void set_nr_angajati(int nr_angajati)
	{
		this->nr_angajati = nr_angajati;
	}
	int get_nr_ani()
	{
		return nr_ani;
	}
	void set_nr_ani(int nr_ani)
	{
		this->nr_ani = nr_ani;
	}

	double *get_profit()
	{
		return profit;
	}
	void set_profit(int nr_ani, double *profit)
	{
		this->nr_ani = nr_ani;
		delete[] profit;
		this->profit = new double[nr_ani];
		for (int i = 0; i<nr_ani; i++)
			this->profit[i] = profit[i];
	}

	static void set_tva(float new_tva)
	{
		tva = new_tva;
	}
	static float get_tva()
	{
		return tva;
	}
	static int get_nr_magazine()
	{
		return nr_magazine;
	}

	const int get_cod()
	{
		return cod;
	}

	magazin() :cod(0)
	{
		nume = new char[strlen("Cora") + 1];
		strcpy(nume, "Cora");
		nr_angajati = 100;
		nr_ani = 5;
		profit = new double[nr_ani];
		for (int i = 0; i<nr_ani; i++)
			profit[i] = i*nr_ani;
		nr_magazine++;
	}

	magazin(char* nume, int nr_angajati, int nr_ani, float *profit, int cod_nou) :cod(cod_nou)
	{
		this->nr_angajati = nr_angajati;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nr_ani = nr_ani;
		this->profit = new double[nr_ani];
		for (int i = 0; i<nr_ani; i++)
		{
			this->profit[i] = profit[i];
		}
		nr_magazine++;

	}
	magazin(const magazin &t) :cod(t.cod)
	{
		this->nume = new char[strlen(t.nume) + 1];
		strcpy(this->nume, t.nume);
		this->nr_ani = t.nr_ani;
		this->profit = new double[nr_ani];
		for (int i = 0; i<t.nr_ani; i++)
			this->profit[i] = t.profit[i];
		this->nr_angajati = t.nr_angajati;
		nr_magazine++;
	}

	magazin operator=(const magazin &obj)
	{
		delete[] nume;
		delete[] profit;
		this->nume = new char[strlen(obj.nume) + 1];
		strcpy(this->nume, obj.nume);
		this->nr_ani = obj.nr_ani;
		this->profit = new double[nr_ani];
		for (int i = 0; i<obj.nr_ani; i++)
			this->profit[i] = obj.profit[i];
		this->nr_angajati = obj.nr_angajati;
		return *this;
	}

	void afisare()
	{
		cout << " Numele magazinului este " << nume << " si are " << nr_angajati << " angajati" << endl;
		cout << "Profitul este egal cu: ";
		for (int i = 0; i< nr_ani; i++)
		{
			cout << endl << profit[i];
		}
		cout << "\nNumarul de ani fiind " << nr_ani << ". " << endl;
	}

	~magazin()
	{
		delete[] nume;
		delete[] profit;
		nr_magazine--;
	}
	double profit_med()
	{
		double s = 0;
		for (int i = 0; i<nr_ani; i++)
			s = s + profit[i];
		return s / nr_ani;
	}
};

float magazin::tva = 24;
int magazin::nr_magazine = 0;

void main()
{
	/*
	{
	magazin z;
	}
	magazin x;
	x.afisare();

	float v[4];
	cout<<"Valori profit in 4 ani:\n";
	for(int i=0; i<4; i++)
	{
	cin>>v[i];
	}
	magazin b("cora", 20, 4, v);
	b.afisare();
	cout<<endl<<" magazinul a avut un profit mediu de "<<b.profit_med()<<" lei."<<endl<<endl<<"Getteri si setteri:"<<endl;
	*/
	//getteri si setteri

	/*magazin x;
	cout <<"Nume vechi:"<< x.get_nume() << endl;
	x.set_nume("Mega Image");
	cout <<"Nume nou:"<< x.get_nume() << endl;

	cout <<"Numar initial angajati:"<< x.get_nr_angajati() << endl;
	x.set_nr_angajati(143);
	cout <<"Numar final angajati:"<< x.get_nr_angajati() << endl;

	cout<<"Numar initial ani:" << x.get_nr_ani() << endl;
	x.set_nr_ani(3);
	cout <<"Numar final ani: "<< x.get_nr_ani() << endl;

	/*int nr=3;
	double t[3]={1,2,3};
	x.set_profit(nr,t);
	double *v=x.get_profit();
	x.get_nr_ani();
	for(int i=0;i<nr;i++)
	cout<<"Participantul "<<i+1<<" a obtinut punctajul "<<t[i]<<".\n";

	for (int i = 0; i<x.get_nr_ani(); i++)
	cout << endl << "magazinul " << i + 1 << " a avut un profit de " << x.get_profit()[i] << " lei."<< endl;
	//x.get_tva();
	cout<<"TVA-ul este de "<< magazin::get_tva()<<" %." << endl;*/
	//magazin b=a;
	/*magazin a;
	magazin b;
	a.set_nume("Billa");
	a.set_nr_angajati(134);
	b=a;
	*/
	
	//magazin k;
	//int b;
	//b=a;
	//cout<<b<<endl;

	//k=a-3;
	//cout<<k.get_nr_angajati()<<endl;

	magazin A;
	magazin B = A;
	B.afisare();

	cout << endl << endl;

	

}