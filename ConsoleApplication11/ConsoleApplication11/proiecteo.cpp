# include <iostream>
# include <fstream>
# include <string>
# include <stdio.h>
using namespace std;

//Acest program va prelua informatii despre un folder 'Music' in care sunt un numar de foldere denumite dupa anumiti artisti.
//Acestea la randul lor contin foldere ce fac trimitere la albumele artistului respectiv. Fiecare dintre aceste foldere (album)
//contin melodiile de pe acel album.

//Locatiile pentru fiecare melodie in parte se gasesc in fisierul text : location.txt
//Melodiile au extensii diferite(mp3 sau wav).. Acestea se gasesc in fisierul text: extension.txt

class artist
{
	char *name;
	int nr_albums;
	char album[10][30];
	static int nr_artist;

public:
	//constructor fara parametri
	artist()
	{
		this->name = new char[strlen("NumeArtist") + 1];
		strcpy(this->name, "NumeArtist");
		nr_albums = 2;
		for (int i = 0; i<nr_albums; i++)
			strcpy(album[i], "Album");
		nr_artist++;
	}
	//constructor cu parametri
	artist(char*name, int nr, char album[][30])
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->nr_albums = nr;
		for (int i = 0; i<nr; i++)
			strcpy(this->album[i], album[i]);
		nr_artist++;
	}

	//destructor
	~artist()
	{
		delete[] name;
	}

	//constructor de copiere
	artist(const artist &aux)
	{
		this->name = new char[strlen(aux.name) + 1];
		strcpy(this->name, aux.name);
		this->nr_albums = aux.nr_albums;
		for (int i = 0; i<aux.nr_albums; i++)
			strcpy(this->album[i], aux.album[i]);
		nr_artist++;
	}

	//operator =
	artist operator=(const artist &obj)
	{
		delete[] this->name;

		this->name = new char[strlen(obj.name) + 1];
		strcpy(this->name, obj.name);
		this->nr_albums = obj.nr_albums;
		for (int i = 0; i<obj.nr_albums; i++)
			strcpy(this->album[i], obj.album[i]);
		return *this;
	}

	//operator >= (Acest operator va facilita sortarea folderelor 'artist' in ordine alfabetica)
	bool operator>=(artist obj)
	{
		bool temp = strcmp(this->name, obj.name);
		return temp;
	}

	//operator <= (Acest operator va facilita sortarea folderelor 'artist' in functie de numarul de albume, descrescator)
	bool operator<=(artist obj)
	{
		bool temp = this->nr_albums <= obj.nr_albums;
		return temp;
	}

	// Getter-i si setter-i

	char* get_artist_name()
	{
		return name;
	}

	void set_artist_name(char *new_name)
	{
		delete[] name;
		this->name = new char[strlen(new_name) + 1];
		strcpy(this->name, new_name);
	}

	int get_artist_nr_albums()
	{
		return nr_albums;
	}
	void set_artist_nr_albums(int nr)
	{
		this->nr_albums = nr;
	}

	int get_nr_artist()
	{
		return nr_artist;
	}

	void set_artist_album(char albums[][30])
	{
		for (int i = 0; i<this->nr_albums; i++)
			strcpy(this->album[i], albums[i]);
	}

	artist operator+=(char s[])
	{
		this->nr_albums++;
		strcpy(this->album[nr_albums], s);
		//cand se va apela aceasta functie in main, este obligatoriu sa citim un nou obiect de tip album (cand vom lucra cu fisierele respective)
		return *this;

	}

	void print()
	{
		cout << "Artistul " << this->name << " a lansat " << this->nr_albums << " albume.\n";
		cout << "Lista acestora este :\n";
		for (int i = 0; i<this->nr_albums; i++)
			cout << "Album " << i + 1 << " : " << this->album[i] << "\n";
	}

	friend istream &operator>>(istream &c, artist &obj);
	friend ostream &operator<<(ostream &c, artist obj);
};

class album
{
	char *album_name;
	int year;//anul aparitiei
	char *source_file;
	int nr_songs;
	float* time_list; // in acest vector vor fi memorate duratele melodiilor din album. Duratele vor fi exprimate in minute,
	//iar ceea ce este dupa virgula sunt secundele

public:
	album()
	{
		this->album_name = new char[strlen("NumeleAlbumului") + 1];
		strcpy(this->album_name, "NumeleAlbumului");
		this->year = 2010;
		this->source_file = new char[strlen("CaleSursa") + 1];
		strcpy(this->source_file, "CaleSursa");
		this->nr_songs = 5;
		this->time_list = new float[this->nr_songs];
		for (int i = 0; i<this->nr_songs; i++)
			this->time_list[i] = 0.5;
	}

	album(char* new_name, int new_year, char*new_source, int songs, float time[])
	{
		this->album_name = new char[strlen(new_name) + 1];
		strcpy(this->album_name, new_name);

		this->year = new_year;
		this->nr_songs = songs;

		this->source_file = new char[strlen("new_source") + 1];
		strcpy(this->source_file, new_source);

		this->time_list = new float[nr_songs];
		for (int i = 0; i<songs; i++)
			this->time_list[i] = time[i];
	}
	~album()
	{
		delete[] album_name;
		delete[] source_file;
		delete[] time_list;
	}

	album(const album &aux)
	{
		this->album_name = new char[strlen(aux.album_name) + 1];
		strcpy(this->album_name, aux.album_name);
		this->year = aux.year;
		this->nr_songs = aux.nr_songs;
		this->source_file = new char[strlen(aux.source_file) + 1];
		strcpy(this->source_file, aux.source_file);
		this->time_list = new float[aux.nr_songs];
		for (int i = 0; i<aux.nr_songs; i++)
			this->time_list[i] = aux.time_list[i];
	}

	void set_album_name(char *new_name)
	{
		delete[] album_name;
		this->album_name = new char[strlen(new_name) + 1];
		strcpy(this->album_name, new_name);
	}

	char* get_album_name()
	{
		return album_name;
	}

	int get_album_year()
	{
		return year;
	}

	int get_album_nr_songs()
	{
		return nr_songs;
	}

	char* get_album_source()
	{
		return source_file;
	}

	album operator=(const album &obj)
	{
		delete[] album_name;
		delete[] source_file;
		delete[] time_list;
		this->album_name = new char[strlen(obj.album_name) + 1];
		strcpy(this->album_name, obj.album_name);
		this->year = obj.year;
		this->nr_songs = obj.nr_songs;
		this->source_file = new char[strlen(obj.source_file) + 1];
		strcpy(this->source_file, obj.source_file);
		this->time_list = new float[obj.nr_songs];
		for (int i = 0; i<obj.nr_songs; i++)
			this->time_list[i] = obj.time_list[i];
		return *this;
	}

	bool operator>=(album obj)
	{
		bool temp = this->year >= obj.year;
		return temp;
	}

	float duration()
	{
		float s = 0;
		for (int i = 0; i<this->nr_songs; i++)
			s += this->time_list[i];
		return s;
	}

	album operator -=(int val)
	{
		for (int i = val - 1; i<this->nr_songs - 1; i++)
			this->time_list[i] = this->time_list[i + 1];
		this->nr_songs--;
		album aux = *this;
		return aux;
	}

	void print_album()
	{
		cout << "Albumul " << this->album_name << " aparut in anul " << this->year << " contine " << this->nr_songs << " melodii si are o durata totala de " << this->duration() << " minute.\n";
	}

	friend istream &operator>>(istream &c1, album &obj);
	friend ostream &operator<<(ostream &c1, album obj);

};

class song
{
	char *song_name;
	char ext[5];
	char *source;//acest camp va fi completat in main() deoarece va fi alcatuit din sursa unui fisier 'album' + numele melodiei

	int nr_countries;
	int *views;

	const int id;//ID-ul va indica index-ul melodiei pentru a ne putea da seama carui album ii apartine

public:
	song() :id(0)
	{
		this->song_name = new char[strlen("NumeMelodie") + 1];
		strcpy(this->song_name, "NumeMelodie");

		this->source = new char[strlen("source") + 1];
		strcpy(this->song_name, "source");

		strcpy(this->ext, ".mp3");
		this->nr_countries = 2;
		this->views = new int[this->nr_countries];

		for (int i = 0; i<this->nr_countries; i++)
			this->views[i] = i * 1000 + i * 3 + 1;
	}

	song(char *new_name, char *new_source, char ext[], int nr, int views[], int id_new) :id(id_new)
	{
		this->song_name = new char[strlen(new_name) + 1];
		strcpy(this->song_name, new_name);

		this->source = new char[strlen(new_source) + 1];
		strcpy(this->source, new_source);

		strcpy(this->ext, ext);
		this->nr_countries = nr;
		this->views = new int[nr];
		for (int i = 0; i<nr; i++)
			this->views[i] = views[i];
	}

	song(const song &aux) :id(aux.id)
	{
		this->song_name = new char[strlen(aux.song_name) + 1];
		strcpy(this->song_name, aux.song_name);

		this->source = new char[strlen(aux.source) + 1];
		strcpy(this->source, aux.source);

		strcpy(this->ext, aux.ext);
		this->nr_countries = aux.nr_countries;
		this->views = new int[aux.nr_countries];
		for (int i = 0; i<this->nr_countries; i++)
			this->views[i] = aux.views[i];
	}

	~song()
	{
		delete[] song_name;
		delete[] source;
		delete[] views;
	}

	char* get_song_name()
	{
		return song_name;
	}

	void set_source(char *new_source)
	{
		delete[] source;
		this->source = new char[strlen(new_source) + 1];
		strcpy(this->source, new_source);
	}
	char* get_song_source()
	{
		return source;
	}

	char* get_ext()
	{
		return ext;
	}

	int all_views()
	{
		int s = 0;
		for (int i = 0; i<this->nr_countries; i++)
			s += this->views[i];
		return s;
	}

	void print_song()
	{
		cout << "Melodia " << this->song_name << " se gaseste in locatia " << this->source << ".\nAceasta a fost ascultata in " << this->nr_countries
			<< " insumand un total de " << this->all_views() << " vizualizari.\n";
	}

	song operator=(const song &obj)
	{
		delete[] song_name;
		delete[] source;
		delete[] views;
		this->song_name = new char[strlen(obj.song_name) + 1];
		strcpy(this->song_name, obj.song_name);

		this->source = new char[strlen(obj.source) + 1];
		strcpy(this->source, obj.source);

		strcpy(this->ext, obj.ext);
		this->nr_countries = obj.nr_countries;
		this->views = new int[obj.nr_countries];
		for (int i = 0; i<this->nr_countries; i++)
			this->views[i] = obj.views[i];
		return *this;
	}

	friend istream &operator>>(istream &c2, song &obj);
	friend ostream &operator<<(ostream &c2, song obj);
};
int artist::nr_artist = 0;
// Citire si scriere clasa artist
istream &operator>>(istream &c, artist &obj)
{
	char s[30];
	cout << "Dati numele artistului: "; c >> s;
	obj.name = new char[strlen(s) + 1];
	strcpy(obj.name, s);
	cout << "Dati numarul de albume: "; c >> obj.nr_albums;
	cout << "Dati numele albumelor:\n";
	for (int i = 0; i<obj.nr_albums; i++)
	{
		cout << "Albumul " << i + 1 << " : "; c >> obj.album[i];
	}
	return c;
}

ostream &operator<<(ostream &c, artist obj)
{
	c << "Informatii despre artist: \n";
	c << "1.Nume artist: " << obj.name << "\n";
	c << "2.Numar de albume lansate : " << obj.nr_albums << "\n";
	c << "3.Lista albume lansate: \n";
	for (int i = 0; i<obj.nr_albums; i++)
		c << "     <#> " << obj.album[i] << "\n";
	return c;
}

//Citire si scriere clasa album
istream &operator>>(istream &c1, album &obj)
{
	char s[50];
	cout << "Dati numele albumului:"; c1 >> s;
	obj.album_name = new char[strlen(s) + 1];
	strcpy(obj.album_name, s);

	cout << "Anul aparitiei : "; c1 >> obj.year;

	obj.source_file = new char[strlen("source") + 1];
	strcpy(obj.source_file, "source");//initial acest atribut va fi initializat cu sirul de caractere "source", fiind 
	//modificat ulterior cu valorile din fisierul text

	cout << "Numarul de cantece de pe album: "; c1 >> obj.nr_songs;
	obj.time_list = new float[obj.nr_songs];
	cout << "Dati timpii melodiilor:\n";
	for (int i = 0; i<obj.nr_songs; i++)
	{
		cout << "Melodia " << i + 1 << " : "; c1 >> obj.time_list[i];
	}
	return c1;
}

ostream &operator<<(ostream &c1, album obj)
{
	c1 << "Informatii album: \n";
	c1 << "1.Nume album : " << obj.album_name << "\n";
	c1 << "2.Anul aparititei : " << obj.year << "\n";
	c1 << "3.Fisierul se gaseste in locatia: " << obj.source_file << "\n";
	c1 << "4.Albumul contine " << obj.nr_songs << " cantece.\n";
	c1 << "5.Timpul total este de " << obj.duration() << " minute.";
	return c1;
}

//Citire si scriere clasa song

istream &operator>>(istream &c2, song &obj)
{
	char s[30];
	cout << "Dati numele melodiei : "; c2 >> s;
	obj.song_name = new char[strlen(s) + 1];
	strcpy(obj.song_name, s);

	obj.source = new char[strlen("FisierSursa") + 1];
	strcpy(obj.source, "FisierSursa");
	//extensia va fi standard .mp3. Aceasta va fi modificata la citirea din fisier
	//Locatia sursa va fi de asemenea initializata in constructor. Va fi modificata ulterior.
	cout << "Numarul de tari in care a fost ascultata : "; c2 >> obj.nr_countries;
	cout << "Numarul de vizualizari pentru fiecare tara :\n";
	for (int i = 0; i<obj.nr_countries; i++)
	{
		cout << "Tara " << i + 1 << " : "; c2 >> obj.views[i];
	}
	return c2;
}

ostream &operator<<(ostream &c2, song obj)
{
	c2 << "Informatii melodie : \n";
	c2 << "1.Denumire melodie : " << obj.song_name << "\n";
	c2 << "2.Locatie : " << obj.source << "\n";
	c2 << "3.Numar total de vizualizari : " << obj.all_views() << "\n";
	return c2;
}
void main()
{
	int opt;
	do
	{
		puts("0.Iesire program");
		puts("1.Creare entitate Artist->Albume->Melodii/album");
		puts("2.Creare entitate Artist->Albume->Melodii/album prin operatorii >> <<");
		puts("3.Modificare atribute - clasa artist");
		puts("4.Sortare obiecte de tip artist");
		puts("5.Adaugare album in obiectul artist");
		puts("6.Crearea unui obiect de tip album");
		puts("7.Ordonarea unor albume in functie de anul aparitiei");
		puts("8.Stergerea unei melodii din vectorul unui album");
		puts("9.Crearea unui obiect de tip song");
		puts("10.Citire scriere obiect de tip song de la tastatura");
		puts("11.Creare locatie sursa pentru un obiect de tip song");
		cout << "Optiunea dvs. este: "; cin >> opt;


		switch (opt)
		{
		case 1:
		{
				  //Creare entitate Artist->Albume->Melodii/album

				  //Metoda 1 : Aceasta metoda este implementata pentru a fi utilizata in cazul in care preluam datele din fisier
				  char artist_name[30], aux[30], *album_name, *album_name1, line[100], album_matrix[10][30];
				  int check = 0, nr = 1;
				  cin.getline(artist_name, 30);
				  while (!check)
				  {
					  cin.getline(aux, 30);
					  if (strcmp(artist_name, aux) != 0)
						  check = 1;
					  else nr++;
				  }
				  for (int i = 0; i<nr; i++)
				  {
					  cin >> line;
					  album_name = strtok(line, "/");
					  while (album_name != NULL)
					  {
						  album_name1 = new char[strlen(album_name) + 1];
						  strcpy(album_name1, album_name);
						  album_name = strtok(NULL, "/");
					  }
					  strcpy(album_matrix[i], album_name1);
				  }
				  artist artist1(artist_name, nr, album_matrix);
				  artist1.print();
				  cout << "\n\n";
				  break;
		}
		case 2:
		{
				  //Metoda 2 : Se va folosi pentru a testa validitatea supraincarcarii operatorilor >> , <<
				  artist artist2;
				  cin >> artist2;
				  cout << artist2;
				  cout << "\n\n";
				  break;
		}
		case 3:
		{
				  //Modificarea datelor unui obiect de tip artist utilizand getter-i si setter-i
				  artist artist3;

				  char new_album[][30] = { "LoveSongs", "Unique", "Greatest hits" };
				  artist3.set_artist_name("Lara Fabian");
				  artist3.set_artist_nr_albums(3);
				  artist3.set_artist_album(new_album);

				  artist3.print();
				  cout << "\n\n";
				  break;
		}

		case 4:
		{
				  //Sortarea celor 3 obiecte in ordine alfabetica: Testare operator =
				  artist obj, artist1, artist2, artist3;
				  cin >> artist1;
				  cin >> artist2;
				  cin >> artist3;
				  if (artist1 >= artist2)
				  if (artist1 >= artist3)
				  {
					  obj = artist1;
					  artist1 = artist3;
					  artist3 = obj;
				  }
				  else if (artist2 >= artist3)
				  {
					  obj = artist2;
					  artist2 = artist3;
					  artist3 = obj;
				  }
				  else
				  {
					  obj = artist1;
					  artist1 = artist2;
					  artist2 = obj;
				  }
				  cout << "Numele artistilor ordonate alfabetic:\n";
				  cout << artist1.get_artist_name() << "\n" << artist2.get_artist_name() << "\n" << artist3.get_artist_name() << "\n";
				  cout << "\n\n";
				  break;
		}

		case 5:
		{
				  artist artist1;
				  cin >> artist1;
				  artist1 += "Greatest Hits";
				  cout << artist1;
				  cout << "\n\n";
				  break;
		}

		case 6:
		{
				  album album1;
				  cin >> album1;
				  album1.print_album();
				  cout << "\n\n";
				  break;
		}

		case 7:
		{
				  album album_v[10], aux;
				  int nr_album;
				  cout << "Dati numarul de albume: "; cin >> nr_album;
				  cout << "Cititi informatiile referitoare la cele " << nr_album << " albume : \n";
				  for (int i = 0; i<nr_album; i++)
				  {
					  cout << "Album " << i + 1 << " info:"; cin >> album_v[i];
				  }
				  for (int i = 0; i<nr_album - 1; i++)
				  for (int j = i + 1; j<nr_album; j++)
				  if (album_v[i] >= album_v[j])
				  {
					  aux = album_v[i];
					  album_v[i] = album_v[j];
					  album_v[j] = aux;
				  }
				  cout << "Afisare albume in ordine cronologica : \n";
				  for (int i = 0; i<nr_album; i++)
					  cout << i + 1 << " . " << album_v[i].get_album_name() << " ->Year ->" << album_v[i].get_album_year() << "\n";
				  cout << "\n\n";
				  break;

		}

		case 8:
		{
				  album album1;
				  int value;
				  cin >> album1;
				  cout << "Doriti sa stergeti melodia cu numarul : (alegeti un numar de la 1 la " << album1.get_album_nr_songs() << ") :"; cin >> value;
				  album1 -= value;
				  album1.print_album();
				  cout << "\n\n";
				  break;
		}

		case 9:
		{
				  int v[] = { 10000, 123594, 23000, 52000, 78000, 123000 };
				  song song1("Counting Stars", "Source", ".mp3", 6, v, 1);
				  song1.print_song();
				  cout << "\n\n";
				  break;
		}

		case 10:
		{
				   song song1;
				   cin >> song1;
				   cout << song1;
				   cout << "\n\n";
				   break;
		}

		case 11:
		{
				   song song1;
				   cin >> song1;

				   album album1;
				   cin >> album1;

				   char s[100];
				   strcpy(s, album1.get_album_source());
				   strcat(s, "/");
				   strcat(s, song1.get_song_name());
				   strcat(s, song1.get_ext());
				   song1.set_source(s);

				   cout << song1;
				   cout << "\n\n";
				   break;

		}
		}
	} while (opt != 0);
}
