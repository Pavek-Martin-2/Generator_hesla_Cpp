#include <iostream> // cout
#include <vector> // znaky{}
#include <ctime> // srand()
#include <windows.h> // Sleep();
using namespace std;

/* 
generuje heslo o zadane delce max. 64 znaku
znaky se muzou v hesle opakovat i stejne
prohazuje mezi nahodne mezi sebou dva znaky pole znaky{}
a pak s takto zamichaneho pole (promenna "michej") vybere
nahodne "delka_hesla" klicu a sestavi stoho vysledne heslo
takze maximalni mozne znahodneni
*/

int michej = 100000; // pocet michani
int delka_hesla;
int rnd_1, rnd_2, rnd_3, aa, bb;
string pomocna, heslo = "";

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
cout<<endl<<"Generator nahodneho hesla (mala, velka abecada a cislice)"<<endl;
cout<<"jak dlouhe ma byt heslo, zadej pocet znaku (3 - 64) : ";
cin>>delka_hesla;

// osetreni vstupu
if (delka_hesla < 3 || delka_hesla > 64) {
cout<<"chybne zadani, zadej cislo 3 - 64 "<<endl;
Sleep(3000);
return 1;
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

// predchozi verze 2, byla vlastne bez opakovani stejneho znaku, coz nejni dobre
// takze zde jiz upraveno
for (bb = 0; bb <= delka_hesla -1; bb++){
rnd_3 = rand() % MAX;
heslo += znaky[rnd_3];
}

cout<<endl<<heslo<<endl<<endl;

system("pause");
return 0;
}

