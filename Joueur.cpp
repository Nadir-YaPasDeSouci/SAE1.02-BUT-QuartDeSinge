/**
 * @file Joueur.cpp
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 2 3/12/2022
 * composant Joueur
 */

#include <iostream>
#include <cassert>
#include "joueur.h"
using namespace std;

void Ajout_Quart_de_Singe(Joueur& joueur) {
    assert(joueur.quartDeSinge < 1);
    joueur.quartDeSinge += 0.25;
}

bool A_Joueur_Singe(const Joueur& joueur) {
    return (joueur.quartDeSinge == 1) ? true : false;
}

uint Joueur_Suivant(uint indice_joueur_courant, const uint NombreJoueurs) {
    if (indice_joueur_courant == NombreJoueurs - 1) {
        return 0;
    }
    else {
        return indice_joueur_courant += 1;
    }
}

uint Joueur_Precedent(uint& indice_joueur, const uint NombreJoueurs) {
    if (indice_joueur == 0) {
        return NombreJoueurs-1;
    }
    else {
        return indice_joueur - 1;
    }
}

void Joueur_Inconnu(const char* argv, const uint nombreJoueurs) {
    for (int i = 0; i < nombreJoueurs; ++i) {
        if (argv[i] != 'H' && argv[i] != 'R') {
            cout << "seuls les humains et les robots peuvent jouer";
            exit(2);
        }
    }
}

void Nombre_Incorrect_Joueur(const uint nombreJoueurs) {
    if (nombreJoueurs < 2) {
        cout << "La partie se joue doit se jouer a plusieurs";
        exit(2);
    }
}