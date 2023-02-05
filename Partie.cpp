/**
 * @file Partie.cpp
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 1 31/11/2022
 * Composant de la partie
 */

#include <iostream>
#include <iomanip> // pour setw
#include <fstream>
#include <cctype>
#include <cassert>
#include <cassert>
#include "Partie.h"
using namespace std;

void Create_Game(Partie& game, const int NombreJoueurs) {
    assert(NombreJoueurs > 1);
    game.joueurs = new Joueur[NombreJoueurs];
    game.nbjoueurs = NombreJoueurs;
}

void Add_Players(Partie& game, const int NombreJoueurs, const char* argv) {
    assert(NombreJoueurs > 1);
    for (int i = 0; i < NombreJoueurs; ++i) {
        game.joueurs[i].nature = toupper(argv[i]);
        game.joueurs[i].numerojoueur = i + 1;
        game.joueurs[i].quartDeSinge = 0;
    }
}

void End_Game(Partie& game) {
    delete[] game.joueurs;
    game.joueurs = NULL;
}