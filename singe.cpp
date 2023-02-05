/**
 * @file singe.cpp
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version finale 3/1/2023
 * Deroulement d'une partie de quart de singe
 */

#include <iostream>
#include <iomanip> // pour setw
#include "JeuEnCours.h"
using namespace std;




int main(int argc, const char* argv[]) {
    srand(time(NULL));
    Partie game;
    uint NombreJoueurs = strlen(argv[1]);

    Nombre_Incorrect_Joueur(NombreJoueurs);
    Joueur_Inconnu(argv[1], NombreJoueurs);

    Create_Game(game, NombreJoueurs);
    Add_Players(game, NombreJoueurs, argv[1]);
    Nouveau_Mot(game.wordInGame);
    Word& motDePartie = game.wordInGame;


    Dictionnaire dico;
    Initialiser_Dico(dico, 350000, 1.25);
    Ecrire_Mots_Dico(dico);

    
    bool finmanche = false;
    uint i = 0;

    while (1) {
        char lettre;
        finmanche = false;
        Affiche_Tour(game.joueurs[i], motDePartie);
        if (game.joueurs[i].nature == 'H') {
            cin >> lettre;
            cin.ignore(INT_MAX, '\n');
        }
        else if (game.joueurs[i].nature == 'R') {
            if (motDePartie.lenword == 0) {
              
                lettre = Lettre_Random_Robot();
            }
            else {
                lettre = Recherche_Début_Mot_Dichoto(dico.contenu, dico.nombreMots, motDePartie.word,motDePartie.lenword);
            }
            Afficher_Lettre(lettre);
        }

        if (lettre == '!') {

            Abandon_Joueur(game, motDePartie, game.joueurs[i]);
            if (A_Joueur_Singe(game.joueurs[i])) {
                break;
            }
            Nouveau_Mot(motDePartie);
        }
        else if (lettre == '?') {
            i = Joueur_Precedent(i, NombreJoueurs);
            Affiche_Saisir_Mot(game.joueurs[i]);
            if (game.joueurs[i].nature == 'H') {
                Saisie_Mot_Humain(game, game.joueurs[i], game.joueurs[Joueur_Suivant(i, NombreJoueurs)], motDePartie, dico, i);
            }
            else if (game.joueurs[i].nature == 'R') {
                char* reponse;
                reponse = Recherche_Robot_Mot_Dichoto(dico.contenu, dico.nombreMots, motDePartie.word,motDePartie.lenword);
                Affiche_Mot_Existe(reponse, game.joueurs[Joueur_Suivant(i,NombreJoueurs)]);
                Ajout_Quart_de_Singe(game.joueurs[Joueur_Suivant(i, NombreJoueurs)]);
                Fin_Manche(game, motDePartie);
                i = Joueur_Suivant(i, NombreJoueurs);
            }
            if (A_Joueur_Singe(game.joueurs[i]) || A_Joueur_Singe(game.joueurs[Joueur_Suivant(i, NombreJoueurs)])) {
                break;
            }
            Nouveau_Mot(motDePartie);
        }
        else {
            Add_Letter(motDePartie, lettre);
            if (motDePartie.lenword > 2) {
                if (Recherche_Mot_Dico_Dichoto(dico.contenu, dico.nombreMots, motDePartie.word)) {
                    Affiche_Mot_Existe(motDePartie, game.joueurs[i]);
                    Ajout_Quart_de_Singe(game.joueurs[i]);
                    Fin_Manche(game, motDePartie);
                    if (A_Joueur_Singe(game.joueurs[i])) {
                        break;
                    }
                    Nouveau_Mot(motDePartie);
                    finmanche = true;
                }
            }
            i = Determine_Joueur_Suivant(finmanche, i, NombreJoueurs);
        }
    }
       
    cout << "La partie est finie";
    Detruire_Dico(dico);
    End_Game(game);
}