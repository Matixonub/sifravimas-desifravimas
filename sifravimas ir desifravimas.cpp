#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int veiksm, veiksm2;
string abc = "abcdefghijklmnopqrstuvwxyz ";
string key;
string txt;
int abcsk[99];
int sifsk[90];
int keysk[90];

void klausymas();
void klausymas2();
void klausymas3();
void ivedimas();
void sifruoti();
void desifruoti();
void sifruotiascii();
void desifruotiascii();

int main() {
    setlocale(LC_ALL, "Lithuanian");
    klausymas();
    if (veiksm == 1) {
        klausymas2();
        if (veiksm2 == 1) {
            ivedimas();
            sifruoti();
        }
        else if (veiksm2 == 2) {
            ivedimas();
            desifruoti();
        }
    }

    else {
        klausymas2();
        if (veiksm2 == 1) {
            ivedimas();
            sifruotiascii();
        }
        else if (veiksm2 == 2) {
            ivedimas();
            desifruotiascii();
        }
    }

}


//Pasirinkimas tarp abeceles ir ASCII:
void klausymas() {
    cout << "Alphabet - 1" << endl;
    cout << "ASCII - 2" << endl;
    cin >> veiksm;
}////Pasirinkimas tarp abeceles ir ASCII


//Pasirinkimas tarp sifravimo ir desifravimo:
void klausymas2() {
    cout << "Sifruoti - 1: " << endl;
    cout << "Desifruoti - 2: " << endl;
    cin >> veiksm2;
}


//teskto su raktu ivedimas:
void ivedimas() {
    cout << "Iveskite teksta: " << endl;
    cin.ignore();
    getline(cin, txt);
    cout << "Iveskite rakta: " << endl;
    getline(cin, key);
    for (int i = 0; i <= txt.size() - 1; i++) { // teksto raidziu vieta abeceleje iraso i "abcsk"
        for (int j = 0; j <= abc.size(); j++) {
            if (txt[i] == abc[j]) {
                abcsk[i] = j;
            }
        }
    }
    for (int i = 0; i <= key.size() - 1; i++) { //rakto raidziu skaiciu uzraso i "keysk"
        for (int j = 0; j <= abc.size(); j++) {
            if (key[i] == abc[j]) {
                keysk[i] = j;
            }
        }
    }
}


//sifravimo veiksmas:
void sifruoti() {
    for (int i = 0; i < txt.size(); i++) {
        for (int j = 0; j < key.size() && i < txt.size(); j++) {
            if (abcsk[i] == abc.size()-1) {
                sifsk[i] = abc.size()-1;
                j--;
            }
            else if (abcsk[i] < abc.size()-1) {
                sifsk[i] = abcsk[i] + keysk[j];
                if (sifsk[i] >= abc.size()-1) sifsk[i] = sifsk[i] - (abc.size()-1);
            }
            cout << abc[sifsk[i]];
            i++;
        }
        i--;
    }
}


//desifravimo veiksmas:
void desifruoti() {
    for (int i = 0; i < txt.size(); i++) {
        for (int j = 0; j < key.size() && i < txt.size(); j++) {
            if (abcsk[i] == abc.size() - 1) {
                sifsk[i] = abc.size() - 1;
                j--;
            }
            else if (abcsk[i] == keysk[j]) sifsk[i] = abcsk[i] - keysk[j];
            else if (abcsk[i] < abc.size()-1) {
                sifsk[i] = abcsk[i] - keysk[j]+(abc.size()-1);
                if (sifsk[i] > abc.size()-1) {
                    sifsk[i] -= (abc.size() - 1);
                }
            }
            cout << abc[sifsk[i]];
            i++;
            }
        i--;
    }
}



void sifruotiascii() {
    

}

void desifruotiascii() {


}


