#include "seminar9.h"
#include<fstream>

class concurs_online : public concurs{
	char* site;
	int durata_zile;

public:

	virtual float nr_total_puncte() {
		float f = concurs::nr_total_puncte();
		return this->durata_zile*concurs(*this).nr_total_puncte();
	}

	concurs_online(): concurs() {
		site = new char[strlen("www.orl.com")+1];
		strcpy(site, "www.orl.com");
		durata_zile = 0;
	}

	concurs_online(char* site, int new_time, char *nume, float*punctaje, int nr_participanti, float taxa, int id_nou) : concurs(nume, punctaje, nr_participanti,taxa, id_nou) {
		this->site = new char[strlen(site) + 1];
		strcpy(this->site, site);
		this->durata_zile = new_time;

	}
	
	concurs_online(const concurs_online &aux):concurs(aux) {
		this->site = new char[strlen(aux.site) + 1];
		strcpy(this->site, aux.site);
		this->durata_zile = aux.durata_zile;
	}

	concurs_online operator=(const concurs_online &obj) {
		concurs::operator=(obj);
		delete[] site;
		this->site = new char[strlen(site) + 1];
		strcpy(this->site, obj.site);
		this->durata_zile = obj.durata_zile;

		return *this;
	}

	~concurs_online() {
		delete[] site;

	}

	void set_site(char *site)
	{
		delete[] this->site;
		this->site = new char[strlen(site) + 1];
		strcpy(this->site, site);
	}
	char * get_site()
	{
		return site;
	}

	void set_durata_zile(int durata_zile) {
		this->durata_zile = durata_zile;
	}

	int get_durata_zile() {
		return durata_zile;
	}

	bool operator==(concurs_online aux)
	{
		bool temp = this->durata_zile == aux.durata_zile;
		return temp;
	}

	concurs_online operator++()
	{
		this->durata_zile++;
		return *this;
	}

	concurs_online operator++(int)
	{
		concurs_online aux = *this;
		this->durata_zile++;

		return aux;
	}

	friend ostream &operator<<(ostream&in, concurs_online obj);

};

ostream &operator<<(ostream&in, concurs_online obj) {
	in << obj.site << "\n";
	in << obj.durata_zile << "\n";
	in << (concurs)obj;
	
	return in;
}



void main() {

	concurs_online a;
	

	cout << a;
	float v[] = { 8, 5, 4, 9, 2 };
	concurs_online b("Koncurs.com", 30, "HK", v, 5, 120, 2);
	cout << b;
	
	concurs_online c;
	c = b;
	cout << c;

	c.set_durata_zile(5);
	cout << c.get_durata_zile();


	if (c == b) cout <<" egale " ;
	else cout << "nu sunt egale";

	concurs d;
	cout<<d.nr_total_puncte();

	concurs_online e;
	cout << e.nr_total_puncte();

	d = e;
	
	concurs *p;
	p = &d;
	cout << p->nr_total_puncte()<<"\n";

	p = &e;
	cout << p->nr_total_puncte() << "\n";

	int n;
	cin >> n;
	if (n)p = &d;
	else p = &e;
	cout << p->nr_total_puncte()<< "\n";

	fstream f("qq.csv", ios::out);
	f << "Id, Nume, Nr_participanti,Taxa"<<endl;
	concurs g;
	f << g.get_id() << "," << g.get_nume() << "," << g.get_nr_participanti() << "," << g.get_taxa()<<"\n";

	concurs h;
	f << h.get_id() << "," << h.get_nume() << "," << h.get_nr_participanti() << "," << h.get_taxa() << "\n";
	
	f.close();
}