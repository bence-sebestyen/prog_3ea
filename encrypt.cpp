#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Titkosit(string input, string kulcs) {

	string titkositott;
	ofstream tFile("titkositott.txt");

	for (int i = 0; i < input.length(); i++) {
		titkositott += input[i] ^ kulcs[i % kulcs.length()];
	}

	tFile << titkositott;
	tFile.close();

}

int main(int argc, char* argv[]) {

	string input;
	string kulcs;

	cout << "Adja meg a titkositando szoveget: ";
	getline(cin, input);

	cout << "Adja meg a kulcsot: ";
	cin >> kulcs;

	Titkosit(input, kulcs);
	
}