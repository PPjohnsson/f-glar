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
int valTvå();
int valTre();
int database();
int räknare_2 = 0;

struct föglar{

	string klass;
	string svensktNamn;
	string latinsktNamn;
	int observationer;

};
vector<föglar> fågel_database;

// Anropa denna funktion för att enkelt kunna få åäö rätt utskriva:
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
	cout << "    Totalt antal fåglar:"  << räknare_2 <<"                    ";
	cout << "**\n";
	cout << "**";
	cout << "    1. Lägg till fåglar från fil                     ";
	cout << "**\n";
	cout << "**";
	cout << "    2. Visa alla fåglar                              ";
	cout << "**\n";
	cout << "**";
	cout << "    3. Visa vanligaste fåglar                        ";
	cout << "**\n";
	cout << "**";
	cout << "    4. Avsluta                                       ";
	cout << "**\n";
	cout << "**                                               **\n";
	cout << "***************************************************\n";
	cout << "***************************************************\n";
	cout << "Välj alternativ: ";


	choice = GetInput();


	switch (choice) {

	case 1: {
		database();
		break;
	}
	case 2: {

		valTvå();
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



int räknare = 0;

int database() {

	

	string filnamn;
	cout << "Ange filnamn: ";
	cin >> filnamn;

	ifstream fil(filnamn);

	if (!fil) {
		cout << "kunde inte öppna filen" << endl;
	}


	string rad;
	

	while (getline(fil, rad)) {
		
		if (räknare_2 >= 100) {
			cout << "Listan är full med " << räknare_2 << " fåglar" << endl << endl;
			break;
		}
		else {
			föglar fåglar;
			istringstream iss(rad);

			getline(iss >> ws, fåglar.klass, ',');
			getline(iss >> ws, fåglar.svensktNamn, ',');
			getline(iss >> ws, fåglar.latinsktNamn, ',');
			iss >> fåglar.observationer;
			räknare_2++;

			string s;
			getline(iss, s);

			fågel_database.push_back(fåglar);


		}

			
	}

	
	cout << räknare_2;
//	for (string s : fågel_database) {
//		if (räknare >= 100){
//			cout << "Listan är full med " << räknare << " fåglar" << endl;
//			break;
//		}
//		räknare++;
//	}
//	cout << räknare;
	displayOptionsMeny();
	
	return 0;
}

int valTvå() {

	int fågel_räknare = 0;
	cin.ignore();
	
	for (föglar fåglar : fågel_database) {
		
		if (fågel_räknare == 20) {
			cout << fågel_räknare;
			cout << "Klicka på Enter för att fortsätta" << endl;
			cin.ignore();
			fågel_räknare = 0;

		}
		else {
			cout << fågel_räknare;
			cout << " " << fåglar.klass << ", " << fåglar.svensktNamn << ", " << fåglar.latinsktNamn << ", " << fåglar.observationer << endl;
			fågel_räknare++;
		}
	}
	
	/*
	int fågel_räknare = 0;
	cin.ignore();
		for (int i = 0; i < fågel_database.size(); i++) {
			
			fågel_räknare++;
			cout << i + 1 << ": " << fågel_database[i] << endl;
			
			if (fågel_räknare == 20) {
				cout << "Klicka på Enter för att forrsätta" << endl;
				cin.ignore();
				fågel_räknare = 0;
			}
		}
	*/	
	/*	for (int i = 0; i < fågel_database.size(); i += 20) {
			for (int j = i; j < min(i + 20, (int)fågel_database.size()); j++) {

				cout << j + 1 << ": " << fågel_database[j] << endl;
			
			}
			if (i + 20 < fågel_database.size()) {
				cout << "Klicka på Enter för att forrsätta" << endl;
				cin.ignore();
			}
		}*/

		//cout << fågel_räknare++ << ": " << s << endl;
		//if (fågel_räknare > 1 && fågel_räknare % 20 == 1) {
		//	cout << "Klicka på Enter för att fortsätta" << endl;
		//}	
	//}

	displayOptionsMeny();

	return 0;

};
int valTre() {

	
	cout << "Visa vanliga fåglar" << endl;
	int max;
	cout << "Visa vanliga fåglar, ange minimum observationer: ";
	cin >> max;
	for (föglar fåglar : fågel_database) {
		if (fåglar.observationer >= max) {
			cout << " " << fåglar.klass << ", " << fåglar.svensktNamn << ", " << fåglar.latinsktNamn << ", " << fåglar.observationer << endl;
			
		}
	}

	displayOptionsMeny();
	return 0;
}
int main() {

	displayOptionsMeny();
	return 0;

}
