/**
 * @file JeuEnCours.cpp
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 2 28/12/2022
 * Fonctions essentiels au bon déroulement du jeu du quart de singe
 */

#include <iostream>
#include <cassert>
#include <iomanip>
#include "JeuEnCours.h"
using namespace std;

void Fin_Manche(Partie& game,Word& motdeLaManche) {
	Affiche_Check_Point(game);
	Detruire_Mot_Manche(motdeLaManche);
}
 

void Abandon_Joueur(Partie& game,Word& motDeLaManche, Joueur& joueur) {
	Affiche_Abandon(joueur);
	Ajout_Quart_de_Singe(joueur);
	Fin_Manche(game,motDeLaManche);
}


uint Determine_Joueur_Suivant(const bool finManche, const uint joueur, const uint nombreJoueurs) {
	if (finManche == true) {
		return joueur;
	}
	else {
		return Joueur_Suivant(joueur, nombreJoueurs);
	}
} 

void Mauvais_Debut_Mot(const char motEnCoursDeSaisie[], Joueur& joueurInterroge) {
    Affiche_Mauvais_Debut_Mot(motEnCoursDeSaisie, joueurInterroge);
    Ajout_Quart_de_Singe(joueurInterroge);
}

void Majuscule(char* motEnCoursDeSaisie) {
    for (int i = 0; i < strlen(motEnCoursDeSaisie); ++i) {
        motEnCoursDeSaisie[i] = toupper(motEnCoursDeSaisie[i]);
    }
}



void Saisie_Mot_Humain(Partie& game, Joueur& joueurInterroge, Joueur& joueurConcurrent, Word& motDeLaManche, Dictionnaire& dico, uint& plDebManche) {
    char motEnCoursDeSaisie[MAX];
    cin >> setw(MAX) >> motEnCoursDeSaisie;
    cin.ignore(INT_MAX, '\n');

    Majuscule(motEnCoursDeSaisie);
    if (motDeLaManche.lenword != 0) {
        if (Compare_Mot(motDeLaManche, motEnCoursDeSaisie) == false) {
            Mauvais_Debut_Mot(motEnCoursDeSaisie, joueurInterroge);
            Fin_Manche(game, motDeLaManche);
            plDebManche = joueurInterroge.numerojoueur - 1; // ce joueur entamera la manche suivante
            return;
        }
    }
    

    if (Recherche_Mot_Dico_Dichoto(dico.contenu, dico.nombreMots, motEnCoursDeSaisie)) {
        Affiche_Joueur_Concurrent_Manche_Perdu(motEnCoursDeSaisie, joueurConcurrent);
        Ajout_Quart_de_Singe(joueurConcurrent);
        Fin_Manche(game, motDeLaManche);
        plDebManche = joueurConcurrent.numerojoueur - 1; // ce joueur entamera la manche suivante
        return;
    }

    Affiche_Joueur_Interroge_Manche_Perdu(motEnCoursDeSaisie, joueurInterroge);
    Ajout_Quart_de_Singe(joueurInterroge);
    Fin_Manche(game, motDeLaManche);
    plDebManche = joueurInterroge.numerojoueur - 1; // ce joueur entamera la manche suivante
    return;
}

char Lettre_Random_Robot() {
    char lettre;
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t indice;

    indice = rand() % (25 + 1);
    lettre = alphabet[indice];
    return lettre;
}

void Affiche_Tour(const Joueur& joueur, Word& motDelaPartie) {
    cout << joueur.numerojoueur << joueur.nature << "," << " ";
    cout << "(" << motDelaPartie.word << ") > ";
}

void Affiche_Abandon(const Joueur& joueur) {
    cout << "le joueur " << joueur.numerojoueur << joueur.nature << " abandonne la manche et prend un quart de singe" << endl;

}

void Affiche_Mot_Existe(const Word& MotDeLaManche, const Joueur& joueur) {
    cout << "le mot " << MotDeLaManche.word << " existe, le joueur " << joueur.numerojoueur << joueur.nature << " prend un quart de singe" << endl;
}

void Affiche_Check_Point(const Partie& game) {
    for (uint i = 0; i < game.nbjoueurs; ++i) {
        if (i == game.nbjoueurs - 1)
            cout << game.joueurs[i].numerojoueur << game.joueurs[i].nature << " : " << game.joueurs[i].quartDeSinge;
        else
            cout << game.joueurs[i].numerojoueur << game.joueurs[i].nature << " : " << game.joueurs[i].quartDeSinge << "; ";
    }
    cout << endl;
}

void Affiche_Saisir_Mot(const Joueur& joueurInterroge) {
    cout << joueurInterroge.numerojoueur << joueurInterroge.nature << ", saisir le mot > ";
}

void Affiche_Mauvais_Debut_Mot(const char motEnCoursDeSaisie[], Joueur& joueurInterroge) {
    cout << "le mot " << motEnCoursDeSaisie << " ne commence pas par les lettres attendues, ";
    cout << "le joueur " << joueurInterroge.numerojoueur << joueurInterroge.nature << " prend un quart de singe" << endl;
}

void Affiche_Joueur_Concurrent_Manche_Perdu(const char motSaisie[], Joueur& joueurConcurrent) {
    cout << "le mot " << motSaisie << " existe, le joueur " << joueurConcurrent.numerojoueur << joueurConcurrent.nature << " prend un quart de singe" << endl;
}

void Affiche_Joueur_Interroge_Manche_Perdu(const char motSaisie[], Joueur& joueurInterroge) {
    cout << "le mot " << motSaisie << " n'existe pas, le joueur " << joueurInterroge.numerojoueur << joueurInterroge.nature << " prend un quart de singe" << endl;
}

void Affiche_Mot_Existe(char* reponse, const Joueur& joueur) {
    cout << "le mot " << reponse << " existe, le joueur " << joueur.numerojoueur << joueur.nature << " prend un quart de singe" << endl;

}

void Afficher_Lettre(const char lettre) {
    cout << lettre << endl;
}
