#include <iostream>

using namespace std;

class prajitura {
	int nr_consumatori;
	float pret;
	char *nume_prajitura;
	float *cantitate;
	static int nrTotal_prajituri;
	static int nr_inregistrare;
	const int ingrediente;

public:
	void afisare() {
		cout << "Numele prajiturii este: " << nume_prajitura << endl;
		cout << "Pretul acesteia este: " << pret << " RON" << endl;
		cout << "Numarul persoanelor care au cumparat-o este: " << nr_consumatori << endl;
		for (int i = 0; i<nr_consumatori; i++)
			cout << "Clientul numarul " << i + 1 << " a cumparat " << cantitate[i] << " prajituri." << endl;
		cout << "Numarul total de prajituri din cofetarie este: " << nrTotal_prajituri << endl;
		cout << "Prajitura avand " << ingrediente << " ingrediente.";
	}
	prajitura() :ingrediente(5) {
		nr_consumatori = 5;
		pret = 10;
		nume_prajitura = new char[strlen("Tiramisu") + 1];
		strcpy(nume_prajitura, "Tiramisu");
		cantitate = new float[nr_consumatori];
		for (int i = 0; i<nr_consumatori; i++)
			cantitate[i] = 8 - i;
		nrTotal_prajituri++;
	}
	prajitura(int nr_consumatori, float pret, char *nume_prajitura, float *cantitate, int ingredient_nou) :ingrediente(ingredient_nou) {
		this->nr_consumatori = nr_consumatori;
		this->pret = pret;
		this->nume_prajitura = new char[strlen(nume_prajitura) + 1];
		strcpy(this->nume_prajitura, nume_prajitura);
		this->cantitate = new float[nr_consumatori];
		for (int i = 0; i<nr_consumatori; i++)
			this->cantitate[i] = cantitate[i];
	}
	~prajitura() {
		delete[] nume_prajitura;
		delete[] cantitate;
		nrTotal_prajituri--;
	}

	char *get_nume_prajitura() {
		return nume_prajitura;
	}

	void set_nume_prajitura(char *nume_prajitura) {
		delete[] this->nume_prajitura;
		this->nume_prajitura = new char[strlen(nume_prajitura) + 1];
		strcpy(this->nume_prajitura, nume_prajitura);
	}

	float get_pret() {
		return pret;
	}

	void set_pret(float pret) {
		this->pret = pret;
	}

	float *get_cantitate() {
		return cantitate;
	}
	void set_cantitate(int nr_consumatori, float *cantitate) {
		this->nr_consumatori = nr_consumatori;
		delete[] this->cantitate;
		this->cantitate = new float[nr_consumatori];
		for (int i = 0; i<nr_consumatori; i++)
			this->cantitate[i] = cantitate[i];
	}

	int get_nr_consumatori() {
		return nr_consumatori;
	}

	static int get_nrTotal_prajituri() {
		return nrTotal_prajituri;
	}

	static int get_nr_inregistrare() {
		return nr_inregistrare;
	}

	int get_ingrediente() {
		return ingrediente;
	}

	//constructor de copiere
	prajitura(prajitura &sec) :ingrediente(sec.ingrediente) {
		this->nume_prajitura = new char[strlen(sec.nume_prajitura) + 1];
		strcpy(this->nume_prajitura, sec.nume_prajitura);
		this->nr_consumatori = sec.nr_consumatori;
		this->cantitate = new float[sec.nr_consumatori];
		for (int i = 0; i<sec.nr_consumatori; i++)
			this->cantitate[i] = sec.cantitate[i];
		this->pret = sec.pret;
		nrTotal_prajituri++;
	}

	prajitura operator = (const prajitura &amb) {
		delete[] this->nume_prajitura;
		this->nume_prajitura = new char[strlen(amb.nume_prajitura) + 1];
		strcpy(this->nume_prajitura, amb.nume_prajitura);
		this->nr_consumatori = amb.nr_consumatori;
		this->cantitate = new float[amb.nr_consumatori];
		for (int i = 0; i<amb.nr_consumatori; i++)
			this->cantitate[i] = amb.cantitate[i];
		this->pret = amb.pret;
		//staticul nu se modifica aici!
		return *this;
	}

	//operator de cast
	operator float() {
		return nr_consumatori;
	}

	prajitura operator +(int plus) {
		prajitura sec = *this;
		sec.pret += plus;
		return sec;
	}

	/*prajitura operator +(prajitura amb) {
	prajitura sec=*this;
	sec.nr_consumatori=this->nr_consumatori+sec.nr_consumatori;
	delete [] sec.cantitate;
	sec.cantitate=new float[sec.nr_consumatori];
	for(int i=0;i<this->nr_consumatori;i++)
	sec.cantitate[i]=this->cantitate[i];
	for(int i=0;i<sec.nr_consumatori;i++)
	sec.cantitate[this->nr_consumatori+i]=sec.cantitate[i];
	return sec;
	}*/

	prajitura operator -(int minus) {
		prajitura sec = *this;
		sec.pret -= minus;
		return sec;
	}

	/*prajitura operator -(prajitura amb) {
	prajitura sec=*this;
	sec.nr_consumatori=this->nr_consumatori-sec.nr_consumatori;
	delete [] sec.cantitate;
	sec.cantitate=new float[sec.nr_consumatori];
	for(int i=0;i<this->nr_consumatori;i++)
	sec.cantitate[i]=this->cantitate[i];
	for(int i=0;i<sec.nr_consumatori;i++)
	sec.cantitate[this->nr_consumatori+i]=sec.cantitate[i];
	return sec;
	}*/

	prajitura operator /(int impartit) {
		prajitura sec = *this;
		sec.pret = sec.pret / impartit;
		return sec;
	}

	prajitura operator *(int inmultit) {
		prajitura sec = *this;
		sec.pret = sec.pret*inmultit;
		return sec;
	}

	friend ostream &operator<<(ostream &out, prajitura amb);

	friend istream &operator>>(istream &in, prajitura &amb);

	bool operator>=(prajitura amb) {
		bool temp = this->pret >= amb.pret;
		return temp;
	}

	bool operator==(prajitura amb) {
		bool temp = this->nr_consumatori == amb.nr_consumatori;
		return temp;
	}

	prajitura operator++() {
		this->pret++;
		return *this;
	}

	prajitura operator++(int) {
		prajitura amb = *this;
		this->pret++;
		return amb;
	}

	float &operator [] (int index) {
		if (index<this->nr_consumatori)
			return cantitate[index];
		return cantitate[0];
	}


};

int operator+(int E, prajitura B) {
	return E + B.get_pret();
}

ostream &operator<<(ostream &out, prajitura amb) {
	out << "Numele prajiturii este: " << amb.nume_prajitura << endl;
	out << "Pretul acesteia este: " << amb.pret << " RON" << endl;
	out << "Numarul persoanelor care au cumparat-o este: " << amb.nr_consumatori << endl;
	for (int i = 0; i<amb.nr_consumatori; i++)
		out << "Clientul numarul " << i + 1 << " a cumparat " << amb.cantitate[i] << " prajituri." << endl;
	out << "Numarul total de prajituri din cofetarie este: " << amb.nrTotal_prajituri << endl;
	out << "Prajitura avand " << amb.ingrediente << " ingrediente." << endl;
	return out;
}

istream &operator>>(istream &in, prajitura &amb) {
	char s[20];
	cout << "Dati numele prajiturii: ";
	in >> s;
	amb.nume_prajitura = new char[strlen(s) + 1];
	strcpy(amb.nume_prajitura, s);
	cout << "Pretul acesteia este: ";
	in >> amb.pret;
	cout << "Numarul de consumatori este: ";
	in >> amb.nr_consumatori;
	for (int i = 0; i<amb.nr_consumatori; i++)
	{
		cout << "Cumparatorul " << i + 1 << " achizitioneaza urmatorul numar de prajituri: ";
		in >> amb.cantitate[i];
	}
	cout << endl << endl;
	return in;
}

int prajitura::nrTotal_prajituri = 50;
int prajitura::nr_inregistrare = 15;

int main()
{
	//float V[5]={8,7,6,5,4};
	//prajitura A(5,10,"Tiramisu",V);
	//A.afisare();
	//prajitura B;
	//B.afisare();
	/*prajitura C;

	float X[4]={10,5,11,3};

	C.set_nume_prajitura("Placinta");
	cout<<endl<<"Numele prajiturii este: "<<C.get_nume_prajitura();
	C.set_pret(12);
	cout<<endl<<"Pretul acesteia este: "<<C.get_pret()<<" RON.";
	C.set_cantitate(4,X);
	cout<<endl<<"Numarul persoanelor care au cumparat-o este: "<<C.get_nr_consumatori();
	float *X1=C.get_cantitate();
	for(int i=0;i<C.get_nr_consumatori();i++)
	cout<<endl<<"Clientul numarul "<<i+1<<" a cumparat "<<X1[i]<<" prajituri.";
	C.get_nrTotal_prajituri();
	cout<<endl<<"Numarul de placinte aflate in cofetarie este: "<<prajitura::get_nrTotal_prajituri();
	cout<<endl<<"Aceasta prajitura avand "<<C.get_ingrediente()<<" ingrediente.";
	cout<<endl;
	return 0;

	prajitura A;
	prajitura B=A;
	B.afisare();

	cout<<endl<<endl;

	prajitura C;
	prajitura D;
	C.set_nume_prajitura("Tort de ciocolata");
	D=C;
	D.afisare();

	cout<<endl<<endl;

	prajitura E;
	int F;
	F=E;
	cout<<F;

	cout<<endl<<endl;

	prajitura G;
	prajitura H;
	G=H+3;
	G.afisare();

	cout<<endl<<endl;

	prajitura A1;
	prajitura B1;
	A1=B1-7;
	A1.afisare();

	cout<<endl<<endl;

	prajitura A2;
	prajitura B2;
	A1=B1/2;
	A1.afisare();

	cout<<endl<<endl;

	prajitura A3;
	prajitura B3;
	A1=B1*3;
	A1.afisare();

	cout<<endl<<endl;*/

	prajitura A;
	prajitura B;
	cout << A;
	cin >> B;
	cout << B;

	if (A >= B)
		cout << "Pretul primei prajituri este mai mare sau egal cu pretul celei de-a doua prajituri." << endl;
	else
		cout << "Pretul primei prajituri este mai mic decat pretul celei de-a doua prajituri." << endl;

	cout << endl << endl;

	/*if (A == B)
		cout << "Cele doua prajituri sunt consumate de acelasi numar de persoane." << endl;
	else
		cout << "Cumparatorii prefera prima sau a doua prajitura." << endl;

	cout << endl << endl;

	B = A++;
	A.afisare();

	cout << endl << endl;

	B = ++A;
	B.afisare();

	cout << endl << endl;

	prajitura G;
	float G1 = G[2];
	G[2] = 6;
	cout << G1 << endl << endl;
	G.afisare();

	cout << endl << endl;

	int E;
	prajitura F;
	E = E + F;
	cout << E;*/
}
