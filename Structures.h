#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct proprietes
{
    char nom[15];    //nom de la propriete
    int numPlateau; //numero de la case sur le plateau
    int prix;    //prix propriete
    int loyer0;  //loyer sans maison
    int loyer1;  //loyer 1 maison
    int loyer2;  //loyer 2 maisons
    int loyer3;  //loyer 3 maisons
    int loyer4;  //loyer 4 maisons
    int loyer5;  //loyer 1 hotel
    int valeur_hypotheque;
    int prix_maison;    //prix pour l'achat d'une maison
    char proprietaire[15];  //nom du proprietaire
    char famille[15];       //famille de couleur
    int nbrMaisons;     //Nombre de maisons sur la proprieté
    int valHypotheque;  //Si la propriete est hypothequé ou non
}p;








typedef struct joueur
{
    char prenom[15];      //prenom du joueur
    int argent;         //argent du joueur
    int nbrProprietes;      //nombre de proprietes que possede le joueur
    int cartePrison;        //nombre de cartes sortie de prison que possede le joueur
    int OrdreDePassage;     //ordre de passage du joueur par rapport au autres joueurs
    int caseActuelle;       //numéro de la case actuelle du joueur
    int enJeu;      //si le joueur est eliminé ou si il est toujours en jeu
    char pion;      //design du pion du joueur
    int nbrTours;   //nombre de tour en prison du joueur
}j;





#endif // STRUCTURES_H_INCLUDED
