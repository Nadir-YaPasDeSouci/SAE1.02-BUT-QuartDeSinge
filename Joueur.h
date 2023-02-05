/**
 * @file Joueur.h
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 2 3/12/2022
 * composant Joueur
 */

#ifndef _JOUEUR_
#define _JOUEUR_
typedef unsigned int uint;

struct Joueur {
    char nature; //nature du joueur, robot ou humain
    uint numerojoueur; //numero du joueur
    float quartDeSinge; // nombre de quart de singe affecté au joueur (0.25, 0.5, 0.75, 1)
};



/**@brief ajoute un quart de singe à un joueur
* @param[in,out] Joueur : joueur écopant d'un quart de singe
* @pre singe du joueur < 1 
*/
void Ajout_Quart_de_Singe(Joueur& Joueur);

/**@brief verifie si un joueur a obtenu quatre quarts de singe
* @param[in] joueur : joueur pour lequel on veut verifier le nombre de quart de singe
* @return un booléen selon si le joueur a quatre quarts de singe ou non
*/
bool A_Joueur_Singe(const Joueur& joueur);

/**@brief donne l'indice du joueur suivant le joueur courant pendant le déroulement d'une partie de quart de singe
* @param[in] indice_joueur_courant : indice du joueur courant
* @param[in] NombreJoueurs : le nombre de joueurs jouant au jeu du quart de singe
* @return indice du joueur suivant
*/
uint Joueur_Suivant(uint indice_joueur_courant, const uint NombreJoueurs);

/**@brief donne l'indice du joueur precedent le joueur courant pendant le déroulement d'une partie de quart de singe
* @param[in] indice_joueur_courant : indice du joueur courant
* @param[in] NombreJoueurs : le nombre de joueurs jouant au jeu du quart de singe
* @return indice du joueur precedent
*/
uint Joueur_Precedent(uint& indice_joueur, const uint NombreJoueurs);

/**@brief quitte le programme si autres que des humains('H') et des robots('R') sont entrés dans l'invite de commande pour jouer une partie de quart de singe
* @param[in] argv : chaîne de caractères récupérer depuis l'invite de commande
* @param[in] nombreJoueurs : nombre de joueurs entrés par l'utilisateur sur l'invite de commande
*/
void Joueur_Inconnu(const char* argv, const uint nombreJoueurs);

/**@brief quitte le programme si le jeu accueil moins de 2 joueurs
* @param[in] nombreJoueurs: nombre de joueurs
*/
void Nombre_Incorrect_Joueur(const uint nombreJoueurs);

#endif // !_JOUEUR_
