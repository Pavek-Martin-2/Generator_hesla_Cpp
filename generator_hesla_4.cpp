#include <iostream> // cout
#include <vector> // znaky{}
#include <ctime> // srand()
#include <windows.h> // Sleep();
#include <fstream> // file write
using namespace std;

/* 
generuje heslo o zadane delce max. 64 znaku
znaky se muzou v hesle opakovat i stejne
prohazuje mezi sebou nahodne dva znaky v pole znaky{}
a pak s takto zamichaneho pole (promenna "michej") vybere
nahodne "delka_hesla" pocet klicu a sestavi stoho vysledne heslo
takze maximalni mozne znahodneni
heslo nakonec jeste zapise do souboru "heslo.txt"
*/

int michej = 100000; // pocet michani
int delka_hesla;
int rnd_1, rnd_2, rnd_3, aa, bb;
string pomocna, heslo = "";
string file = "heslo.txt";
//string file = "C:\\work\\heslo.txt";

vector<string> znaky = {
"a","b","c","d","e","f","g","h","i","j","k","l","m",
"n","o","p","q","r","s","t","u","v","w","x","y","z",
"A","B","C","D","E","F","G","H","I","J","K","L","M",
"N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
"0","1","2","3","4","5","6","7","8","9"
}; // 62 znaku v poly

const int MAX = 62; // delka vektoru znaky {}

int main() {
	
// uzivatelsky vstup, delka hesla
cout<<endl<<"https://github.com/Pavek-Martin-2"<<endl;
cout<<"Generator nahodneho hesla (mala, velka abecada a cislice)"<<endl;
cout<<"jak dlouhe ma byt heslo, zadej pocet znaku (3 - 64) : ";
cin>>delka_hesla;

// osetreni vstupu
if (delka_hesla < 3 || delka_hesla > 64) {
cout<<"chybne zadani, zadej cislo 3 - 64 "<<endl;
Sleep(3000);
return 1; // navratovy kod bude 1 (neuspech) viz. screenshoty
}

srand(static_cast<unsigned>(time(NULL))); // neco jako, randomize os.time

for (aa = 1; aa <= michej; aa++){

rnd_1 = rand() % MAX;
rnd_2 = rand() % MAX;

// micha pole znaky{}
pomocna = znaky[rnd_1];
znaky[rnd_1] = znaky[rnd_2];
znaky[rnd_2] = pomocna;
}

for (bb = 0; bb <= delka_hesla -1; bb++){
rnd_3 = rand() % MAX;
heslo += znaky[rnd_3];
Sleep(60); // kvuli funkci srand()
}

// zapis hesla do souboru "heslo.txt" v aktualnim adresari
ofstream fo(file);
if (!fo){ // chyba ReadOnly apod.
cout<<endl<<"chyba pri zapisu do souboru "<<'"'<<file<<'"'<<endl;
Sleep(3000);
return 1; // navratovy kod bude 1 (neuspech) viz. screenshoty
}

// zapis hesla do souboru
fo<<heslo;
fo.close();

// tisk hesla
cout<<endl<<heslo<<endl;
cout<<endl<<"zapsano do souboru "<<'"'<<file<<'"'<<endl;

system("pause");
return 0; // navratovy kod bude 0 (uspech) viz. screenshoty
}
