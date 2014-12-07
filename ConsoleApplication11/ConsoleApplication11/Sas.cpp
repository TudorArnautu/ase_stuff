# include <iostream>
# include <string>
using namespace std;

class interviu
{
	char *nume_candidat;
	char *post;
	int salariu;
	float nota_1; // cele doua note reflecta rezultatul celor 2 teste sustinute de un candidat
	float nota_2;
	char *rezultat; // aceasta variabila va lua valoarea "acceptat/respins"

	static int timp_alocat;
	static int nr_posturi;

	const int id;


public:

	void set_nume_candidat(char *nume_candidat)
	{
		delete[] this->nume_candidat;
		this->nume_candidat = new char[strlen(nume_candidat) + 1];
		strcpy(this->nume_candidat, nume_candidat);
	}
	char * get_nume_cand()
	{
		return nume_candidat;
	}

	void set_post(char *post)
	{
		delete[] this->post;
		this->post = new char[strlen(post) + 1];
		strcpy(this->post, post);
	}
	char * get_post()
	{
		return post;
	}

	char * get_rezultat()
	{
		return rezultat;
	}

	void set_salariu(int salariu)
	{
		this->salariu = salariu;
	}
	int get_salariu()
	{
		return salariu;
	}

	float get_nota_1()
	{
		return nota_1;
	}

	float get_nota2()
	{
		return nota_2;
	}

	void set_note(float n1, float n2)
	{
		nota_1 = n1;
		nota_2 = n2;
	}
	static void set_timp(int new_timp)
	{
		timp_alocat = new_timp;
	}
	static int get_timp()
	{
		return timp_alocat;
	}
	static int get_nr_posturi()
	{
		return nr_posturi;
	}
	void afisare()
	{
		cout << "Candidatul " << nume_candidat << " s-a prezentat la interviul pentru ocuparea postului de  " << post << ",acesta sustinand doua teste la care a obtinut " << nota_1 << " puncte si " << nota_2 << " puncte, acestora fiind alocate " << timp_alocat << " minute.Rezultatul final pentru candidat este " << rezultat << ". Salariul pentru acest post este de " << salariu << " lei.\n";
	}

	void cand_rezultat()
	{
		if ((nota_1 + nota_2) / 2>7.5)
		{

			rezultat = new char[strlen("admis") + 1];
			strcpy(rezultat, "admis");
		}
		else
		{

			rezultat = new char[strlen("respins") + 1];
			strcpy(rezultat, "respins");
		}
	}

	const int get_id()
	{
		return id;
	}
	interviu() :id(0)
	{
		nume_candidat = new char[strlen("Mihai Popescu") + 1];
		strcpy(nume_candidat, "Mihai Popescu");

		post = new char[strlen("Asistent manager") + 1];
		strcpy(post, "asistent manager");
		//timp_alocat=45;
		nota_1 = (float)7;
		nota_2 = (float)6.3;
		salariu = 1000;
		cand_rezultat();
		nr_posturi++;
	}


	interviu(char *nume_candidat, int salariu, float nota_1, float nota_2, char*post, int id_nou) :id(id_nou)
	{
		this->nume_candidat = new char[strlen(nume_candidat) + 1];
		strcpy(this->nume_candidat, nume_candidat);
		this->salariu = salariu;
		this->nota_1 = nota_1;
		this->nota_2 = nota_2;
		this->post = new char[strlen(post) + 1];
		strcpy(this->post, post);
		this->cand_rezultat();

	}

	~interviu()
	{
		delete[] nume_candidat;
		//delete[] post;
		delete[] rezultat;
	}


	interviu(const interviu &aux) :id(aux.id)
	{
		this->nume_candidat = new char[strlen(aux.nume_candidat) + 1];
		strcpy(this->nume_candidat, aux.nume_candidat);

		this->post = new char[strlen(aux.post) + 1];
		strcpy(this->post, aux.post);
		this->salariu = aux.salariu;
		this->nota_1 = aux.nota_1;
		this->nota_2 = aux.nota_2;
		nr_posturi++;
	}

	operator int()
	{
		return nr_posturi;
	}
	interviu operator=(const interviu &obj)
	{
		delete[] nume_candidat;
		delete[] post;
		this->nume_candidat = new char[strlen(obj.nume_candidat) + 1];
		strcpy(this->nume_candidat, obj.nume_candidat);

		this->post = new char[strlen(obj.post) + 1];
		strcpy(this->post, obj.post);
		this->salariu = obj.salariu;
		this->nota_1 = obj.nota_1;
		this->nota_2 = obj.nota_2;
		return *this;
	}

	interviu operator+(interviu obj)
	{
		interviu aux = *this;
		aux.salariu += obj.salariu;
		return aux;
	}

	interviu operator+(int value)
	{
		interviu aux;
		aux = *this;
		aux.salariu += value;
		return aux;
	}

	interviu operator++()//preincrementare
	{
		this->nota_1++;
		this->nota_2++;
		return *this;
	}
	interviu operator++(int)//postincrementare
	{
		interviu aux = *this;
		this->nota_1++;
		this->nota_2++;
		return aux;
	}

	bool operator<=(interviu aux)
	{
		bool temp = this->salariu <= aux.salariu;
		return temp;
	}
	bool operator==(interviu aux)
	{
		bool temp = strcmp(this->post, aux.post);
		return temp;
	}

	friend ostream &operator<<(ostream &c4, interviu obj);
	friend istream &operator>>(istream &c4, interviu &obj);
	friend int operator+(int a, interviu b);
};

int interviu::timp_alocat = 30;
int interviu::nr_posturi = 0;
int operator+(int a, interviu b)
{
	return a + b.get_salariu();

}

ostream &operator<<(ostream &c4, interviu obj)
{
	c4 << "Informatii candidat: \n";
	c4 << "Nume:" << obj.nume_candidat << "\n";
	c4 << "Post:" << obj.post << "\n";
	c4 << "Salariu job: " << obj.salariu << "\n";
	c4 << "Note obtinute: " << obj.nota_1 << " " << obj.nota_2 << "\n";
	c4 << "Rezultatul Candidatului : " << obj.rezultat;
	return c4;
}

istream &operator>>(istream &c4, interviu &obj)
{
	char aux[20];
	cout << "Dati numele candidatului : "; c4 >> aux;
	obj.nume_candidat = new char[strlen(aux) + 1];
	strcpy(obj.nume_candidat, aux);
	cout << "Postul: "; c4 >> aux;
	obj.post = new char[strlen(aux) + 1];
	strcpy(obj.post, aux);
	cout << "Salariul: "; c4 >> obj.salariu;
	cout << "Notele obtinute:"; c4 >> obj.nota_1 >> obj.nota_2;
	return c4;

}
void main()
{

	interviu candidat("Andrei Mihai", 1500, 8, 8.3, "casier", 30);
	candidat.cand_rezultat();
	candidat.afisare();
	cout << "\n\n";

	interviu candidat2;
	candidat2.afisare();


	interviu candidat3;
	//Getter, setter
	cout << candidat3.get_nume_cand() << "\n";
	candidat3.set_nume_candidat("Popescu Marian");
	cout << candidat3.get_nume_cand() << "\n";
	candidat3.get_timp();
	cout << interviu::get_timp() << "\n";
	candidat3.set_timp(25);
	cout << interviu::get_timp() << "\n";

	candidat3.set_note(10, 9);
	candidat3.cand_rezultat();
	candidat3.afisare();

	//Operatorii >> , <<

	interviu candidat0;
	cin >> candidat0;
	candidat0.cand_rezultat();
	cout << candidat0;


	//Operatorul =
	candidat3 = candidat;
	candidat3.cand_rezultat();
	candidat3.afisare();

	//Operatorul ++
	candidat3++;
	candidat3.cand_rezultat();
	candidat3.afisare();

	interviu candidat4;
	candidat4 = candidat3++;
	candidat4.cand_rezultat();
	candidat4.afisare();

	//Operatorul + 
	interviu candidat5;
	candidat5 = candidat5 + 120;
	candidat5.cand_rezultat();
	interviu a, b;
	b = a + candidat5;
	b.cand_rezultat();
	b.afisare();
}