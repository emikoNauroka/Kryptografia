#include<iostream>
#include<fstream>
#include "Header.h"

using namespace std;
using namespace N;

char Ea (int k, char x) { 
	if (x == ' ')
		return 32;
	else {
		if (x >= 'a' && x <= 'z')
			return 'a' + (((x - 'a') - k) % 26);
		else
		{
			return 'A' + (((x - 'A') - k) % 26);
		}
	}
}

char Aa (int a, int b, char x) { 
	if (x == ' ')
		return 32;
	else {
		if (x >= 'a' && x <= 'z')
			return 'a' + ((((x - 'a') - b) * a ) % 26);
		else
		{
			return 'A' + ((((x - 'A') * a + b) - b) % 26);
		}
	}
}

int funkcje::odszyfrowanie(char szyfr) {
	ifstream zakrypto, key;
	zakrypto.open("zakryptowany.txt");
	key.open("Key.txt");

	char x;
	if (szyfr == 'c') {
		int klucz = (int)key.get() - 48;
		while (zakrypto.get(x)) {
			cout << Ea(klucz, x);
		}
	}
	else {
		int a = (int)key.get() - 48;
		key.get();
		int b = (int)key.get() - 48;
		while (zakrypto.get(x)) {
			cout << Aa(a, b, x);
		}
	}

	zakrypto.close();
	key.close();
	return 0;
}