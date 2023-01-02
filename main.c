#include <stdio.h>
#include <stdlib.h>

#include "CartesChances.c"       //Inclusion de tous les sources .c du programme
#include "CaisseDeCommunaute.c"
#include "Dés.c"
#include "HypothequeEtRachat.c"
#include "Joueur.c"
#include "MenuJoueur.c"
#include "MenuMonopoly.c"
#include "Plateau.c"
#include "Prison.c"
#include "Proprietes.c"
#include "Sauvegarder.c"
#include "Vente.c"

#include "Structures.h"     //Inclusion des structures dans tous les sous programmes



int main()  //Debut de main
{
    MenuMonopoly();     //Appel de la fonction du menu global du monopoly
    return 0;
}
