#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<math.h>
using namespace std;

class Instruments {
	char maker[64];
	unsigned manuf;
	unsigned quality;
	unsigned luxury;
public:
	
	Instruments() {
		maker[0] = manuf = quality =luxury= 0;
	}
	void setInstrum(char buf_maker[], unsigned buf_manuf, unsigned buf_quality)
	{
		strcpy_s(maker, buf_maker);
		this->manuf = buf_manuf;
		this->quality = buf_quality;
	}
	Instruments(char buf_maker[], unsigned buf_manuf, unsigned buf_quality)
	{
		strcpy_s(maker, buf_maker);
		this->manuf = buf_manuf;
		this->quality = buf_quality;
	}

	void getInstrum() {
		cout << "\nCreator:" << maker << endl << "Manufactured in:" << manuf << endl << "Overall nowaday quality:" << quality << endl;
	}

	void getLuxury() {
		this->luxury = (abs(manuf-200.)) / 100 * quality;
		cout << luxury;
	}
};

int main() {
	Instruments *pInstrum;
	unsigned n;
	cout << "\nEnter the number of instruments:" << endl;
	cin >> n;
	pInstrum = new Instruments[n];
	char maker[64];
	unsigned manuf, quality;
	for (unsigned i = 0; i < n; ++i) {
		cout << "\nInstrument # " << i + 1 << endl;
		cout << "Enter the creator name:";
		cin.ignore(2, '\n');
		cin.getline(maker, 63);
		cout << "\nEnter the year of manufacturing(from 1400 to 2000):" << endl;
		cin >> manuf;
		while (manuf < 1400 || manuf>2000) {
			cout << "\nEnter correct number:";
			cin >> manuf;
		}
		cout << "Enter the percentage of overall quality(from 0 to 100):" << endl;
		cin >> quality;
		while (quality < 0 || quality>100) {
			cout << "\nEnter correct number:";
			cin >> quality;
		}
			pInstrum[i].setInstrum(maker, manuf, quality);
		}

		for (unsigned i = 0; i < n; ++i) {
			cout << "\nInstrument #" << i + 1 << ":" << endl;
			pInstrum[i].getInstrum();
		}

		for (unsigned i = 0; i < n; ++i) {
			cout << "\nLuxury of instrument #" << i + 1 << " is:";
			pInstrum[i].getLuxury();
		}


			delete pInstrum;
		
	

	_getch();
	return 0;
}

