/**
 * @file Dico.h
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 1 24/12/2022
 * Composant du dictionnaire
 */

#ifndef _DICO_
#define _DICO_
#include <cstring> 
#pragma warning(disable: 4996)

typedef unsigned int uint;

struct Dictionnaire {
    char** contenu; //un tableau de mots appelé dictionnaire contenant l'ensemble des mots d'un dictionnaire
    uint capacite; // capacité du dictionnaire (souvent différente du nombre de mots réel)
    double pasExtension; //pas d'extension de la capacité du dictionnaire
    uint nombreMots; // nombre réel de mots dans le dictionnaire
};


/**@brief initialise un tableau de chaine de caractères qui contiendra tous les mots du dictionnaire
*@see Detruire_Dico pour la desallocation du Dictionnaire
*@param[in,out] dico : le Dictionnaire contenant tous les mots d'un fichier
*@param[in] capa : la capacité initiale du Dictionnaire
*@param[in] p : le pas d'extension choisi lorsqu'il faudra augmenter la taille du Dictionnaire
* @pre capa > 0 , p > 0
*/
void Initialiser_Dico(Dictionnaire& dico, const uint capa, const double p);

/**@brief inclus (en lisant) tous les mots d'un fichier texte représentant le dictionnaire dans le Dictionnaire dynamique 
*@param[in,out] dico : le Dictionnaire qui va contenir tous les mots du dictionnaire
*/
void Ecrire_Mots_Dico(Dictionnaire& conteneurTdeDico);

/**@brief recherche dichotomique d'une chaîne de caractères dans un tableau de chaine de caractères
*@param[in] dico : le tableau de chaines de caractères dans lequel on cherche le mot
*@param[in] nombreMots : nombre de chaînes de caractères dans le tableau
*@param[in] word : mot pour lequel on cherche la présence ou non dans le tableau de chaînes de caractères
*@return la présence ou non du mot dans le tableau de chaînes de caractères sous la forme d'un booléen
*/
bool Recherche_Mot_Dico_Dichoto(char** dico, const uint nombreMots, const char* word);

/**@brief recherche dichotomique, par le robot, dans un tableau de chaine de caractères, d'un mot commençant par les mêmes lettres que le chaine de caractère complétée durant la partie pour le soumettre en réponse
*@param[in] dico : le tableau de chaines de caractères dans lequel on cherche le mot
*@param[in] dicoNombreMots : nombre de chaînes de caractères dans le tableau de chaîne de caracètre
*@param[in] motDeLaManche : mot complétée durant la partie, pour lequel on cherche un mot identique
*@param[in] lenword : longueur du mot complété durant la manche
*@return le mot trouvé, ayant les premières lettres identiques à celui complétée durant la partie
*/
char* Recherche_Robot_Mot_Dichoto(char** dico, const uint dicoNombreMots, const char* motDeLaManche, const uint lenword);

/**@brief recherche dichotomique, par le robot, dans un tableau de chaine de caractères, d'un mot commençant par les mêmes lettres que le chaine de caractère complétée durant la partie pour jouer la lettre suivante
*@param[in] dico : le tableau de chaines de caractères dans lequel on cherche le mot
*@param[in] dicoNombreMots : nombre de chaînes de caractères dans le tableau de chaîne de caracètre
*@param[in] motDeLaManche : mot complété durant la partie, pour lequel on cherche la lettre suivante
* @param[in] lenword : longueur du mot complété durant la manche
*@return une lettre, pour un mot ayant les premières lettres identiques à celui complétée durant la partie, ou d'un ? si aucune lettre n'est cohérente
*/
char Recherche_Début_Mot_Dichoto(char** dico, const uint dicoNombreMots, const char* motDeLaManche, const uint lenword);

/**@brief desalloue le dictionnaire à la fin de la partie
*@see Initialiser_Dico pour l'allocation du Dictionnaire
*@param[in,out] dico : le Dictionnaire utilisé pour stocké tous les mots du dictionnaire
*/
void Detruire_Dico(Dictionnaire& dico);


#endif // !_DICO_
