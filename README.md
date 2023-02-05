# BUT-INFO-SAE1.02-Jeu du Quart de Singe

#### Langages Utilisés: C-C++

## Description

Le programme octroie la possibilité à deux joueurs ou plus, humains ou robots, de participer à une partie de jeu "Quart de Singe". Le déroulement est le suivant: chaque joueur est invité à entrer une lettre à tour de rôle. L'objectif des joueurs est de concevoir un mot qui existe dans un dictionnaire donné mais de ne jamais le compléter, le but étant de faire en sorte qu'un autre joueur le complète et perde la manche. Le joueur complétant un mot reçoit un quart de singe. Aussi, Le joueur peut décider d'abandonner la manche et prendre un quart de singe par conséquent. Enfin, un joueur peut interroger le joueur qui le précède afin que ce dernier lui annonce le mot auquel il pense. Si le joueur interrogé annonce un mot existant, c'est le joueur qu'il l'a interrogé qui prend un quart de singe, sinon c'est l'inverse qui se produit. Le premier joueur ayant obtenu quatre quarts de singe perd la partie.

## Détails 

Le dictionnaire est au départ un fichier texte qu'on traite autrement dans le programme. De ce fait, la recherche dichotomique pour toutes les vérifications (mot existant, non existant, à compléter par le robot...) est employée. Le robot est un joueur parfait : il complète le mot à partir des mots existants dans le dictionnaire. Ainsi, il ne peut perdre facilement.

## Important

Vous êtes invités vivement à consulter le rapport de la SAE pour plus de détails. Il est impératif de le lire.
Pour jouer, veuillez utiliser la ligne de commande. Exemple d'entrée pour faire jouer 2 humains : SINGE.exe HH.

