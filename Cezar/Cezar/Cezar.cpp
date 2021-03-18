#include<iostream>
#include<fstream>
#include "Header.h"	
using namespace N;

using namespace std;

int main() {
	char ctrl1,ctrl2;
	cout << "Podaj \'c\', aby wybrac szyfr Cezara. \n";
	cout << "Podaj \'a\', aby wybrac szyfr afiniczny.\n";
	cin >> ctrl1;
	funkcje fun;
	
	switch (ctrl1)
	{
		case 'c': {
			cout << "Wybrano szyfr Cezara.\n";
			break;
		}
		case 'a': {
			cout << "Wybrano szyfr afiniczny.\n";
			break;
		}
		default: {
			cout << "Wybrano nieprawidlowa opcje, zamykanie programu.";
			return 0;
		}
	}

	cout << "Podaj \'e\', aby zaszyfrowac tekst za pomoca wybranego szyfru. \n";
	cout << "Podaj \'d\', aby odszyfrowac tekst za pomoca wybranego szyfru. \n";
	cout << "Podaj \'j\', aby dokonac kryptoanalizy z tekstem jawnym. \n";
	cout << "Podaj \'k\', aby dokonac kryptoanalizy w oparciu wylacznie o kryptogram. \n";
	cin >> ctrl2;

	switch (ctrl2)
	{
		case 'e': {
			fun.szyfrowanie(ctrl1);
			break;
			}
		case 'd': {
			fun.odszyfrowanie(ctrl1);
			break;
		}
		case 'j': {
			fun.krypto_analiza_jaw(ctrl1);
			break;
		}
		case 'k': {
			fun.krypto_analiza_njaw(ctrl1);
			break;
		}
		default: {
			cout << "Wybrano nieprawidlowa opcje, zamykanie programu.";
			return 0;
		}
	}
	return 0;
}