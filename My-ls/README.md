# DOCUMENTATION

Fonctionnalités

1. Exploration de Répertoire

    opendir, readdir, closedir: Ces fonctions sont utilisées pour ouvrir, lire et fermer un répertoire respectivement. Elles permettent d'accéder aux entrées d'un répertoire et de récupérer des informations sur ses fichiers et sous-répertoires.

2. Obtention d'Informations sur les Fichiers

    stat, lstat: Ces fonctions sont utilisées pour obtenir des informations sur un fichier, telles que sa taille, son type, ses permissions, etc. stat est utilisé pour les fichiers ordinaires, tandis que lstat est utilisé pour les liens symboliques.
    getpwuid, getgrgid: Ces fonctions permettent de récupérer les noms des utilisateurs et des groupes à partir de leurs identifiants respectifs, ce qui peut être utile pour afficher des informations sur les propriétaires des fichiers.
    ctime, ctime_r, strftime, localtime, localtime_r: Ces fonctions sont utilisées pour formater et afficher les horodatages des fichiers de manière conviviale pour l'utilisateur, en convertissant les horodatages de modification en formats compréhensibles.

3. Gestion des Liens Symboliques

    readlink: Cette fonction est utilisée pour lire la cible d'un lien symbolique, fournissant ainsi des informations sur le chemin auquel il pointe.

4. Gestion des Options de Programme

    getopt: Cette fonction est utilisée pour analyser les options de ligne de commande fournies par l'utilisateur. Elle permet de modifier le comportement du programme en fonction des options spécifiées.

5. Gestion de la Mémoire

    malloc, free: Ces fonctions sont utilisées pour allouer et libérer de la mémoire dynamiquement, assurant ainsi une gestion efficace de la mémoire pendant l'exécution du programme.

6. Gestion des Erreurs

    errno, strerror: Ces fonctions sont utilisées pour récupérer des informations sur les erreurs système qui se produisent pendant l'exécution du programme, facilitant ainsi le débogage et la gestion des erreurs.

7. Interaction avec le Système de Fichiers

    write: Cette fonction est utilisée pour écrire des données sur la sortie standard, ce qui permet d'afficher les résultats de l'exploration du répertoire à l'utilisateur.

## Utilisation du Programme

Pour lancer le programme on utilise:

$ ./my_ls

on utilise aussi make and make clean pour créer le programme et pour le supprimer
