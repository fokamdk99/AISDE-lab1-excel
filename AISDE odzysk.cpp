#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Dane
{
	double executiontime[100];
	int vertices[100], branches[100], multiplications[100], divisions[100], additions[100], X[100], Y[100];
	int licznikvertices, licznikbranches, licznikmultiplications, licznikdivisions, licznikadditions, licznikexecutiontime, licznikX, licznikY;
public:
	Dane() { licznikadditions = 0; licznikbranches = 0; licznikdivisions = 0; licznikmultiplications = 0; licznikvertices = 0; licznikexecutiontime = 0; licznikX = 0; licznikY = 0; }
	void odczytfloat(string& a);
	void odczytvertices(string &a);
	void odczytbranches(string &a);
	void odczytmultiplications(string &a);
	void odczytdivisions(string &a);
	void odczytadditions(string &a);
	bool czyjestliczba(char a);
	void odczytXY(string &a);
	int zapiszdocsv();
};


int main()
{
	Dane dane;
	fstream plik;
	string nazwa, odczyt;
	cout << "podaj nazwe pliku" << endl;
	cin >> nazwa;
	plik.open(nazwa, ios::in);
	if (plik.is_open())
	{
		cout << "otwarto plik do odczytu" << endl;
	}
	else
	{
		cout << "nie udalo sie otworzyc pliku" << endl;
		return 0;
	}
	while (!plik.eof())
	{
		//getline(plik, odczyt);
		getline(plik, odczyt, '\n');
		dane.odczytfloat(odczyt);
		dane.odczytvertices(odczyt);
		dane.odczytbranches(odczyt);
		dane.odczytmultiplications(odczyt);
		dane.odczytdivisions(odczyt);
		dane.odczytadditions(odczyt);
		dane.odczytXY(odczyt);
	}
	//cout << "odczytano: " << endl << odczyt;
	plik.close();
	dane.zapiszdocsv();
	return 0;
}

void Dane::odczytfloat(string& a)
{
	string tmp;
	cout.precision(10);
	if (a.length() >= 3)
	{
		for (int i = 0; i < 3; i++)
		{
			tmp += a[i];
		}
		if (tmp == "Alg")
		{
			string liczba;
			for (int i = 0; i < 16; i++)
			{
				liczba += a[a.length()-18+i];
			}
			while (!czyjestliczba(liczba[0]))
			{
				liczba.erase(liczba.begin());
			}
			while (!czyjestliczba(liczba[liczba.length()-1]))
			{
				liczba.erase(liczba.end()-1);
			}
			executiontime[licznikexecutiontime] = stod(liczba);//atof(liczba.c_str());//stod(liczba);
			//cout << "string wynosi: " << liczba << endl;
			
			cout << "liczba wynosi: " << executiontime[licznikexecutiontime] << endl;
			licznikexecutiontime++;
		}
	}
	
}

void Dane::odczytvertices(string &a)
{
	string tmp;

	if (a.length() >= 13)
	{
		for (int i = 0; i < 13; i++)
		{
			tmp += a[i];
		}
		if (tmp == "number of ver")
		{
			string liczba;
			for (int i = 0; i < 10; i++)
			{
				liczba += a[a.length()-10+i];
			}
			while (!czyjestliczba(liczba[0]))
			{
				liczba.erase(liczba.begin());
			}
			int wynik;
			wynik = stoi(liczba);
			cout << "liczba wynosi: " << wynik << endl;
			vertices[licznikvertices] = wynik;
			licznikvertices++;
		}
	}
}

void Dane::odczytbranches(string& a)
{
	string tmp;

	if (a.length() >= 13)
	{
		for (int i = 0; i < 13; i++)
		{
			tmp += a[i];
		}
		if (tmp == "number of bra")
		{
			string liczba;
			for (int i = 0; i < 10; i++)
			{
				liczba += a[a.length() - 10 + i];
			}
			while (!czyjestliczba(liczba[0]))
			{
				liczba.erase(liczba.begin());
			}
			int wynik;
			wynik = stoi(liczba);
			cout << "liczba wynosi: " << wynik << endl;
			branches[licznikbranches] = wynik;
			licznikbranches++;
		}
	}
}

void Dane::odczytmultiplications(string& a)
{
	string tmp;

	if (a.length() >= 13)
	{
		for (int i = 0; i < 13; i++)
		{
			tmp += a[i];
		}
		if (tmp == "number of mul")
		{
			string liczba;
			for (int i = 0; i < 10; i++)
			{
				liczba += a[a.length() - 10 + i];
			}
			while (!czyjestliczba(liczba[0]))
			{
				liczba.erase(liczba.begin());
			}
			int wynik;
			wynik = stoi(liczba);
			cout << "liczba wynosi: " << wynik << endl;
			multiplications[licznikmultiplications] = wynik;
			licznikmultiplications++;
		}
	}
}

void Dane::odczytdivisions(string& a)
{
	string tmp;

	if (a.length() >= 13)
	{
		for (int i = 0; i < 13; i++)
		{
			tmp += a[i];
		}
		if (tmp == "number of div")
		{
			string liczba;
			for (int i = 0; i < 10; i++)
			{
				liczba += a[a.length() - 10 + i];
			}
			while (!czyjestliczba(liczba[0]))
			{
				liczba.erase(liczba.begin());
			}
			int wynik;
			wynik = stoi(liczba);
			cout << "liczba wynosi: " << wynik << endl;
			divisions[licznikdivisions] = wynik;
			licznikdivisions++;
		}
	}
}

void Dane::odczytadditions(string& a)
{
	string tmp;

	if (a.length() >= 13)
	{
		for (int i = 0; i < 13; i++)
		{
			tmp += a[i];
		}
		if (tmp == "number of add")
		{
			string liczba;
			for (int i = 0; i < 10; i++)
			{
				liczba += a[a.length() - 10 + i];
			}
			while (!czyjestliczba(liczba[0]))
			{
				liczba.erase(liczba.begin());
			}
			int wynik;
			wynik = stoi(liczba);
			cout << "liczba wynosi: " << wynik << endl;
			additions[licznikadditions] = wynik;
			licznikadditions++;
		}
	}
}

bool Dane::czyjestliczba(char a)
{
	if (a == '1' ||
		a == '2' ||
		a == '3' ||
		a == '4' ||
		a == '5' ||
		a == '6' ||
		a == '7' ||
		a == '8' ||
		a == '9' ||
		a == '0')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Dane::odczytXY(string &a)
{
	string tmp;
	int i = 0;

	if (czyjestliczba(a[0]))
	{
		while (czyjestliczba(a[i]))
		{
			tmp += a[i];
			i++;
		}
		X[licznikX] = stoi(tmp);
		Y[licznikY] = stoi(tmp);
		cout << "X: " << X[licznikX] << ", Y: " << Y[licznikY] << endl;
		licznikX++;
		licznikY++;
	}
}

int Dane::zapiszdocsv()
{
	fstream plikcsv;
	string nazwa, odczyt;
	int i = 0;
	cout << "podaj nazwe pliku" << endl;
	cin >> nazwa;
	plikcsv.open(nazwa, ios::out);
	if (plikcsv.is_open())
	{
		cout << "otwarto plik do odczytu" << endl;
	}
	else
	{
		cout << "nie udalo sie otworzyc pliku" << endl;
		return 0;
	}
	while (i < licznikexecutiontime)
	{
		plikcsv << X[i] << "," << Y[i] << "," << executiontime[i] << "," << vertices[i] << "," << branches[i] << "," << multiplications[i] << "," << divisions[i] << "," << additions[i] << endl;
		i++;
	}
	plikcsv.close();
	return 0;
}