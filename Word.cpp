/**
 * @file Word.cpp
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 1 2/12/2022
 * fonctions associées au Composant Word
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "Word.h"
#pragma warning(disable:4996);
using namespace std;

void Nouveau_Mot(Word& NouveauMotManche) {
    NouveauMotManche.word = new char[zerochar];
    NouveauMotManche.word[0] = '\0';
    NouveauMotManche.lenword = 0;
}

void Add_Letter(Word& motDePartie, const char lettre) {
    uint lenMot = motDePartie.lenword;
    uint newTaille = lenMot + 2;

    char* newword = new char[newTaille];
    strcpy(newword, motDePartie.word);
    newword[lenMot] = toupper(lettre);

    delete[] motDePartie.word;
    motDePartie.word = newword;
    motDePartie.word[lenMot + 1] = '\0';
    motDePartie.lenword = lenMot + 1;
}

bool Compare_Mot(const Word& motDeLaManche, const char motSaisi[]) {
    uint i = 0;
    while (i < motDeLaManche.lenword) {
        if (motSaisi[i] != motDeLaManche.word[i]) {
            return false;
        }
        ++i;
    }
    return true;
}

void Detruire_Mot_Manche(Word& MotDeLaManche) {
    delete[] MotDeLaManche.word;
    MotDeLaManche.word = NULL;
}