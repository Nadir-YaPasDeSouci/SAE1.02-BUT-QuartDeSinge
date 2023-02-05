/**
 * @file Dico.cpp
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 1 24/12/2022
 * Composant du dictionnaire
 */

#include <iostream>
#include <iomanip> // pour setw
#include <fstream>
#include <cctype>
#include <cassert>
#include "Dico.h"
using namespace std;
 



void Initialiser_Dico(Dictionnaire& dico, const uint capa, const double p) {
    assert((capa > 0) && (p>0));
    dico.capacite = capa;
    dico.pasExtension = p;
    dico.contenu = new char*[capa];
}

void Ecrire_Mots_Dico(Dictionnaire& conteneurTdeDico) {
    ifstream in("ods4.txt");
    if (!in) {
        cout << "le dictionnaire n'a pu etre ouvert" << endl;
        exit(69);
    }
    const int MAX = 26;
    char motFichier[MAX];
    conteneurTdeDico.nombreMots = 0;
    in >> setw(MAX) >> motFichier; // on essaye de lire le premier mot
    
    while (in) {
        char* mot = new char[strlen(motFichier)+1];
        strcpy(mot, motFichier);
        if (conteneurTdeDico.nombreMots >= conteneurTdeDico.capacite) {
            uint newTaille = (conteneurTdeDico.capacite * conteneurTdeDico.pasExtension);
            char** newDico = new char*[newTaille];
            for (uint j = 0; j < conteneurTdeDico.capacite; ++j) {
                newDico[j] = conteneurTdeDico.contenu[j];
            }
            delete[] conteneurTdeDico.contenu;
            conteneurTdeDico.contenu = newDico;
            conteneurTdeDico.capacite = newTaille;
        }
        conteneurTdeDico.contenu[conteneurTdeDico.nombreMots] = mot;
        conteneurTdeDico.nombreMots ++;
        in >> setw(MAX) >> motFichier; // on essaye de lire le mot suivant
 
    }
    in.close(); // on ferme le fichier
}

bool Recherche_Mot_Dico_Dichoto(char** dico, const uint nombreMots, const char* word) {
    bool estMotDico = false;
    int debutDico = 0, finDico = nombreMots - 1;

    while (debutDico <= finDico) {
        int milieuDico = (debutDico + finDico) / 2;
        if (strcmp(word, dico[milieuDico]) == 0) {
            estMotDico = true;
            break;
        }
        else {
            if (strcmp(word, dico[milieuDico]) < 0)
                finDico = milieuDico - 1;
            else
                debutDico = milieuDico + 1;
        }

    }
    return estMotDico;
}

char* Recherche_Robot_Mot_Dichoto(char** dico, const uint dicoNombreMots, const char* motDeLaManche,const uint lenword) {
    int debutDico = 0, finDico = dicoNombreMots - 1;
    while (debutDico <= finDico) {
        int milieuDico = (debutDico + finDico) / 2;

        if (strncmp(motDeLaManche, dico[milieuDico], lenword) == 0) {
            cout << dico[milieuDico] << endl;
            return dico[milieuDico];

        }
        else {
            if (strncmp(motDeLaManche, dico[milieuDico], strlen(dico[milieuDico])) < 0)
                finDico = milieuDico - 1;

            else
                debutDico = milieuDico + 1;
        }

    }
}

char Recherche_Début_Mot_Dichoto(char** dico, const uint dicoNombreMots, const char* motDeLaManche, const uint lenword) {

    int debutDico = 0, finDico = dicoNombreMots - 1;

    while (debutDico <= finDico) {
        int milieuDico = (debutDico + finDico) / 2;

        if (strncmp(motDeLaManche, dico[milieuDico], lenword) == 0) {
            return dico[milieuDico][lenword];
        }
        else {
            if (strncmp(motDeLaManche, dico[milieuDico], strlen(dico[milieuDico])) < 0)
                finDico = milieuDico - 1;

            else
                debutDico = milieuDico + 1;
        }

    }
    return '?';
}

void Detruire_Dico(Dictionnaire& dico) {
    delete[] dico.contenu;
    dico.contenu = NULL;
}
