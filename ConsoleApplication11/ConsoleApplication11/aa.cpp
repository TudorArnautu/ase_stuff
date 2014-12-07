# include <iostream>
# include <string>
using namespace std;

class interviu
{
	char *nume_candidat;
	char *post;
	//int timp_alocat; timpul va fi exprimat in minute
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
		cout << "Candidatul " << nume_candidat << " s-a prezentat la interviul pentru ocuparea postului de  " << post << ",acesta sustinand doua teste la care a obtinut " << nota_1 << " puncte si " << nota_2 << " puncte, acestora fiind alocate " << timp_alocat << " minute.Rezultatul final pentru candidat este " << rezultat << ".\n";
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
		cand_rezultat();
		nr_posturi++;
	}


	interviu(char *nume_candidat, float nota_1, float nota_2, char*post, int id_nou) :id(id_nou)
	{
		this->nume_candidat = new char[strlen(nume_candidat) + 1];
		strcpy(this->nume_candidat, nume_candidat);
		this->nota_1 = nota_1;
		this->nota_2 = nota_2;
		this->post = new char[strlen(post) + 1];
		strcpy(this->post, post);

	}

	~interviu()
	{
		delete[] nume_candidat;
		delete[] post;
		delete[] rezultat;
	}


	interviu(const interviu &aux) :id(aux.id)
	{
		this->nume_candidat = new char[strlen(aux.nume_candidat) + 1];
		strcpy(this->nume_candidat, aux.nume_candidat);

		this->post = new char[strlen(aux.post) + 1];
		strcpy(this->post, aux.post);

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
		this->nota_1 = obj.nota_1;
		this->nota_2 = obj.nota_2;
		this->cand_rezultat();
		return *this;
	}

	interviu operator++()
	{
		this->nota_1++;
		this->nota_2++;
		return *this;
	}
	interviu operator+(double val)
	{
		interviu aux = *this;
		aux.nota_1 += val;
		aux.nota_2 += val;
		return aux;
	}

};

int interviu::timp_alocat = 30;
int interviu::nr_posturi = 0;

interviu operator+(double a, interviu b)//a este o valoare ce apartine intervalului (0,1)
{
	interviu aux = b;
	double x, y;
	x = aux.get_nota_1();
	x = x*(1 + a);
	y = aux.get_nota2();
	y = y*(1 + a);

	aux.set_note(x, y);
	return aux;
}
void main()
{

	/*interviu candidat("Andrei Mihai",8,8.3,"casier",30);
	candidat.cand_rezultat();

	candidat.afisare();
	cout<<"\n\n";

	interviu candidat2;

	candidat2.afisare();
	*/

	/*cout<<cand.get_nume_cand()<<"\n";
	cand.set_nume_candidat("Popescu Marian");
	cout<<cand.get_nume_cand()<<"\n";
	cand.get_timp();
	cout<<interviu::get_timp()<<"\n";
	cand.set_timp(25);
	cout<<interviu::get_timp()<<"\n";

	cand.set_note(10,9);
	cand.cand_rezultat();
	cand.afisare();*/
	interviu a, b, cand;

	a = cand + 0.3;//operator obiect +alt tip
	a.afisare();
	b = 0.2 + cand;//operator alt tip+obiect(metoda independeta)
	b.afisare();

}