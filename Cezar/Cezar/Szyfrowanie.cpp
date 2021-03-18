#include<iostream>
#include<fstream>
#include<string>
#include "Header.h"

using namespace std;
using namespace N;

char E(int k, char x) { 
	if (x == ' ')
		return 32;
	else {
		if (x >= 'a' && x <= 'z')
			return 'a' + (((x - 'a') + k) % 26);
		else
		{
			return 'A' + (((x - 'A') + k) % 26);
		}
	}
}

char A(int a, int b, char x) {
	if (x == ' ') 
		return 32;
	else {
		if (x >= 'a' && x <= 'z')
			return 'a' + (((x - 'a') * a + b) % 26);
		else
		{
			return 'A' + (((x - 'A') * a + b) % 26);
		}
	}
}

int funkcje::szyfrowanie(char szyfr) {
	ifstream plain, key;
	ofstream krypt;
	krypt.open("zakryptowny.txt");
	krypt.clear();
	plain.open("Plain.txt");
	key.open("Key.txt");
	
	char x;
	if (szyfr == 'c') {
		int klucz = (int)key.get() - 48;
		while (plain.get(x)) {
			char c = E(klucz, x);
			cout << c;
			krypt << c;
		}
	}
	else {
		int a = (int)key.get() - 48;
		key.get();
		int b = (int)key.get() - 48;
		while (plain.get(x)) {
			char c = A(a, b, x);
			cout << c;
			krypt << c;
		}
	}

	plain.close();
	key.close();
	krypt.close();
	return 0;
}