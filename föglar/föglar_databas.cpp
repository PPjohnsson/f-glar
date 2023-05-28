#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <string>
#include < iomanip >
#include <vector>
#include <fstream>
#include <limits>
#include <sstream>
using namespace std;


void displayOptionsMeny();
int valTv�();
int valTre();
int database();
int r�knare_2 = 0;

struct f�glar{

	string klass;
	string svensktNamn;
	string latinsktNamn;
	int observationer;

};
vector<f�glar> f�gel_database;

// Anropa denna funktion f�r att enkelt kunna f� ��� r�tt utskriva:
void setWesternEuropeanCodePage() {
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
}


int GetInput()
{
	int choice;
	cin >> choice;
	return choice;
}
void displayOptionsMeny() {
	setWesternEuropeanCodePage();
	int choice = 0;
	cout << endl << "***************************************************\n";
	cout << "************  Uppgift 2  **************************\n";
	cout << "***************************************************\n";
	cout << "**";
	cout << "    Totalt antal f�glar:"  << r�knare_2 <<"                    ";
	cout << "**\n";
	cout << "**";
	cout << "    1. L�gg till f�glar fr�n fil                     ";
	cout << "**\n";
	cout << "**";
	cout << "    2. Visa alla f�glar                              ";
	cout << "**\n";
	cout << "**";
	cout << "    3. Visa vanligaste f�glar                        ";
	cout << "**\n";
	cout << "**";
	cout << "    4. Avsluta                                       ";
	cout << "**\n";
	cout << "**                                               **\n";
	cout << "***************************************************\n";
	cout << "***************************************************\n";
	cout << "V�lj alternativ: ";


	choice = GetInput();


	switch (choice) {

	case 1: {
		database();
		break;
	}
	case 2: {

		valTv�();
		break;
	}
	case 3: {
		valTre();
		break;
	}
	case 4: {

		exit(1);

	}
	}
}



int r�knare = 0;

int database() {

	

	string filnamn;
	cout << "Ange filnamn: ";
	cin >> filnamn;

	ifstream fil(filnamn);

	if (!fil) {
		cout << "kunde inte �ppna filen" << endl;
	}


	string rad;
	

	while (getline(fil, rad)) {
		
		if (r�knare_2 >= 100) {
			cout << "Listan �r full med " << r�knare_2 << " f�glar" << endl << endl;
			break;
		}
		else {
			f�glar f�glar;
			istringstream iss(rad);

			getline(iss >> ws, f�glar.klass, ',');
			getline(iss >> ws, f�glar.svensktNamn, ',');
			getline(iss >> ws, f�glar.latinsktNamn, ',');
			iss >> f�glar.observationer;
			r�knare_2++;

			string s;
			getline(iss, s);

			f�gel_database.push_back(f�glar);


		}

			
	}

	
	cout << r�knare_2;
//	for (string s : f�gel_database) {
//		if (r�knare >= 100){
//			cout << "Listan �r full med " << r�knare << " f�glar" << endl;
//			break;
//		}
//		r�knare++;
//	}
//	cout << r�knare;
	displayOptionsMeny();
	
	return 0;
}

int valTv�() {

	int f�gel_r�knare = 0;
	cin.ignore();
	
	for (f�glar f�glar : f�gel_database) {
		
		if (f�gel_r�knare == 20) {
			cout << f�gel_r�knare;
			cout << "Klicka p� Enter f�r att forts�tta" << endl;
			cin.ignore();
			f�gel_r�knare = 0;

		}
		else {
			cout << f�gel_r�knare;
			cout << " " << f�glar.klass << ", " << f�glar.svensktNamn << ", " << f�glar.latinsktNamn << ", " << f�glar.observationer << endl;
			f�gel_r�knare++;
		}
	}
	
	/*
	int f�gel_r�knare = 0;
	cin.ignore();
		for (int i = 0; i < f�gel_database.size(); i++) {
			
			f�gel_r�knare++;
			cout << i + 1 << ": " << f�gel_database[i] << endl;
			
			if (f�gel_r�knare == 20) {
				cout << "Klicka p� Enter f�r att forrs�tta" << endl;
				cin.ignore();
				f�gel_r�knare = 0;
			}
		}
	*/	
	/*	for (int i = 0; i < f�gel_database.size(); i += 20) {
			for (int j = i; j < min(i + 20, (int)f�gel_database.size()); j++) {

				cout << j + 1 << ": " << f�gel_database[j] << endl;
			
			}
			if (i + 20 < f�gel_database.size()) {
				cout << "Klicka p� Enter f�r att forrs�tta" << endl;
				cin.ignore();
			}
		}*/

		//cout << f�gel_r�knare++ << ": " << s << endl;
		//if (f�gel_r�knare > 1 && f�gel_r�knare % 20 == 1) {
		//	cout << "Klicka p� Enter f�r att forts�tta" << endl;
		//}	
	//}

	displayOptionsMeny();

	return 0;

};
int valTre() {

	
	cout << "Visa vanliga f�glar" << endl;
	int max;
	cout << "Visa vanliga f�glar, ange minimum observationer: ";
	cin >> max;
	for (f�glar f�glar : f�gel_database) {
		if (f�glar.observationer >= max) {
			cout << " " << f�glar.klass << ", " << f�glar.svensktNamn << ", " << f�glar.latinsktNamn << ", " << f�glar.observationer << endl;
			
		}
	}

	displayOptionsMeny();
	return 0;
}
int main() {

	displayOptionsMeny();
	return 0;

}
