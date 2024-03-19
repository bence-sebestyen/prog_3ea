#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int kulcs_meret = 8;

bool tiszta_lehet(const string& titkos) {
    return titkos.find("hogy") != string::npos &&
        titkos.find("nem") != string::npos &&
        titkos.find("az") != string::npos &&
        titkos.find("ha") != string::npos;
}

void exor(char kulcs[], int kulcs_meret, string& titkos) {
    for (int i = 0; i < titkos.length(); ++i)
        titkos[i] = titkos[i] ^ kulcs[i % kulcs_meret];
}

bool exor_tores(char kulcs[], int kulcs_meret, string& titkos) {
    string titkos_masolat = titkos;
    exor(kulcs, kulcs_meret, titkos_masolat);
    return tiszta_lehet(titkos_masolat);
}

int main() {

    char kulcs[kulcs_meret];
    string titkos;

    ifstream tFile("titkositott.txt");
    

    getline(tFile, titkos, '\0');

    tFile.close();

    for (int ii = '0'; ii <= '9'; ++ii)
        for (int ji = '0'; ji <= '9'; ++ji)
            for (int ki = '0'; ki <= '9'; ++ki)
                for (int li = '0'; li <= '9'; ++li)
                    for (int mi = '0'; mi <= '9'; ++mi)
                        for (int ni = '0'; ni <= '9'; ++ni)
                            for (int oi = '0'; oi <= '9'; ++oi)
                                for (int pi = '0'; pi <= '9'; ++pi) {
                                    kulcs[0] = ii;
                                    kulcs[1] = ji;
                                    kulcs[2] = ki;
                                    kulcs[3] = li;
                                    kulcs[4] = mi;
                                    kulcs[5] = ni;
                                    kulcs[6] = oi;
                                    kulcs[7] = pi;

                                    if (exor_tores(kulcs, kulcs_meret, titkos)) {
                                        cout << "Kulcs: [" << ii << ji << ki << li << mi << ni << oi << pi << "]" << endl
                                            << "Tiszta szoveg: [" << titkos << "]" << endl;
                                        return 0;
                                    }

                                }

    cout << "Nem sikerult megfejteni a kulcsot." << endl;
    return 0;
}
