/**
 * @file Partie.h
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 1 31/11/2022
 * Composant de la partie
 */

#ifndef _PARTIE_
#define _PARTIE_

#include "Joueur.h"
#include "Word.h"




struct Partie {
    uint nbjoueurs; //nombre de joueurs participant à la partie de quart de Singe
    Joueur* joueurs; //tableau de joueurs participants à la partie de quart de Singe (voir structure de données Joueur dans Joueur.h)
    Word wordInGame; //mot à compléter pendant la partie de quart de singe
};

/**
 * @brief CreateGame crée une partie de quart de singe
 * Allocation en mémoire dynamique de la partie
 * de capacité (NombreJoueurs)
 * @see EndGame, pour sa désallocation en fin d'utilisation
 * @param[out] game : la partie de quart de singe
 * @param [in] NombreJoueurs : le nombre de joueurs
 * @pre NombreJoueurs>1
 */
void Create_Game(Partie& game, const int NombreJoueurs);

/**
 * @brief Ajouter des joueurs dans une Partie
 * @param[out] game : la partie de quart de singe
 * @param[in] NombreJoueurs : le nombre de joueurs dans la partie
 * @param[in] argv : une chaine de caractère contenant la liste des joueurs et leur nature respective
 * @pre NombreJoueurs > 1
 */
void Add_Players(Partie& game, const int NombreJoueurs, const char* argv);

/**
 * @brief Désalloue une partie de quart de singe
 * @see CreateGame, la partie à déjà été alloué
 * @param[out] game : la partie de quart de singe
 */
void End_Game(Partie& game);

#endif // !_PARTIE_
