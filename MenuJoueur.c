#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "Structures.h"



///-------------------------------AFFICHAGE DES PROPRIETES DU JOUEUR------------------------------------------

void affichageProprietesJoueur(struct joueur *joueurActuel, struct proprietes *Gdynia, struct proprietes *Taipei, struct proprietes *Tokyo, struct proprietes *Barcelone, struct proprietes *Athenes, struct proprietes *Istanbul, struct proprietes *Kyiv, struct proprietes *Toronto, struct proprietes *Rome, struct proprietes *Shanghai, struct proprietes *Vancouver, struct proprietes *Sydney, struct proprietes *NewYork, struct proprietes *Londres, struct proprietes *Beijing, struct proprietes *HongKong, struct proprietes *Jerusalem, struct proprietes *Paris, struct proprietes *Belgrade, struct proprietes *LeCap, struct proprietes *Riga, struct proprietes *Montreal)
{   //Sous programme d'affichage de l'ensemble des proprietes d'un joueur a tout moment
    p tableauProp[22];
    tableauProp[0] = *Gdynia;
    tableauProp[1] = *Taipei;
    tableauProp[2] = *Tokyo;
    tableauProp[3] = *Barcelone;
    tableauProp[4] = *Athenes;
    tableauProp[5] = *Istanbul;
    tableauProp[6] = *Kyiv;
    tableauProp[7] = *Toronto;
    tableauProp[8] = *Rome;
    tableauProp[9] = *Shanghai;
    tableauProp[10] = *Vancouver;
    tableauProp[11] = *Sydney;
    tableauProp[12] = *NewYork;
    tableauProp[13] = *Londres;
    tableauProp[14] = *Beijing;
    tableauProp[15] = *HongKong;
    tableauProp[16] = *Jerusalem;
    tableauProp[17] = *Paris;
    tableauProp[18] = *Belgrade;
    tableauProp[19] = *LeCap;
    tableauProp[20] = *Riga;
    tableauProp[21] = *Montreal;
    int y = 0;
    if ((*joueurActuel).nbrProprietes == 1)
    {
        gotoligcol(3,130);
        printf("La proprietes de %s est :", (*joueurActuel).prenom);
    }
    else if ((*joueurActuel).nbrProprietes >= 1)
    {
        gotoligcol(3,130);
        printf("Les %d proprietes de %s sont :", (*joueurActuel).nbrProprietes, (*joueurActuel).prenom);
    }
    for (int i=0;i<22;i++)
    {
        if ((strcmp((tableauProp[i]).proprietaire, (*joueurActuel).prenom) == 0))
        {
            gotoligcol(6+y,130);
            printf("\t%s",(tableauProp[i]).nom);
            y = y + 1;
        }
    }
}







void affichageProprietesJoueurAvecNumero(struct joueur *joueurActuel, struct proprietes *Gdynia, struct proprietes *Taipei, struct proprietes *Tokyo, struct proprietes *Barcelone, struct proprietes *Athenes, struct proprietes *Istanbul, struct proprietes *Kyiv, struct proprietes *Toronto, struct proprietes *Rome, struct proprietes *Shanghai, struct proprietes *Vancouver, struct proprietes *Sydney, struct proprietes *NewYork, struct proprietes *Londres, struct proprietes *Beijing, struct proprietes *HongKong, struct proprietes *Jerusalem, struct proprietes *Paris, struct proprietes *Belgrade, struct proprietes *LeCap, struct proprietes *Riga, struct proprietes *Montreal)
{   //Sous programme d'affichage de l'ensemble des proprietes d'un joueur pour le menu vente
    p tableauProp[22];
    tableauProp[0] = *Gdynia;
    tableauProp[1] = *Taipei;
    tableauProp[2] = *Tokyo;
    tableauProp[3] = *Barcelone;
    tableauProp[4] = *Athenes;
    tableauProp[5] = *Istanbul;
    tableauProp[6] = *Kyiv;
    tableauProp[7] = *Toronto;
    tableauProp[8] = *Rome;
    tableauProp[9] = *Shanghai;
    tableauProp[10] = *Vancouver;
    tableauProp[11] = *Sydney;
    tableauProp[12] = *NewYork;
    tableauProp[13] = *Londres;
    tableauProp[14] = *Beijing;
    tableauProp[15] = *HongKong;
    tableauProp[16] = *Jerusalem;
    tableauProp[17] = *Paris;
    tableauProp[18] = *Belgrade;
    tableauProp[19] = *LeCap;
    tableauProp[20] = *Riga;
    tableauProp[21] = *Montreal;
    int y = 0;
    gotoligcol(3,130);
    printf("Les proprietes de %s sont :", (*joueurActuel).prenom);
    for (int i=0;i<22;i++)
    {
        if ((strcmp((tableauProp[i]).proprietaire, (*joueurActuel).prenom) == 0))
        {
            gotoligcol(6+y,130);
            printf("\t%s\t",(tableauProp[i]).nom);
            printf("%d", (tableauProp[i]).numPlateau);
            y = y + 1;
        }
    }
}







///-----------------------------RETROUVER LE PROPRIEATIRE D UNE CASE--------------------------------------------


int retrouverProprio (struct proprietes *propActuelle, struct joueur *joueurActuel, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8)
{   //Sous programme pour retrouver le proprietaire d'une propriete donné
    int suite;
    int col = 130;
    int comparer1 = 10;
    int comparer2 = 10;
    int comparer3 = 10;
    int comparer4 = 10;
    int comparer5 = 10;
    int comparer6 = 10;
    int comparer7 = 10;
    comparer1 = strcmp((*propActuelle).proprietaire, (*joueur2).prenom);
    comparer2 = strcmp((*propActuelle).proprietaire, (*joueur3).prenom);
    comparer3 = strcmp((*propActuelle).proprietaire, (*joueur4).prenom);
    comparer4 = strcmp((*propActuelle).proprietaire, (*joueur5).prenom);
    comparer5 = strcmp((*propActuelle).proprietaire, (*joueur6).prenom);
    comparer6 = strcmp((*propActuelle).proprietaire, (*joueur7).prenom);
    comparer7 = strcmp((*propActuelle).proprietaire, (*joueur8).prenom);


    if (comparer1 == 0)
    {


        gotoligcol(16,col);
        printf("Cette propriete appartient a %s", (*joueur2).prenom);
        if ((*propActuelle).nbrMaisons == 0)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur2).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer0);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer0;
            (*joueur2).argent = (*joueur2).argent + (*propActuelle).loyer0;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur2).prenom, (*joueur2).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 1)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur2).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer1);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer1;
            (*joueur2).argent = (*joueur2).argent + (*propActuelle).loyer1;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur2).prenom, (*joueur2).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 2)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur2).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer2);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer2;
            (*joueur2).argent = (*joueur2).argent + (*propActuelle).loyer2;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur2).prenom, (*joueur2).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 3)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur2).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer3);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer3;
            (*joueur2).argent = (*joueur2).argent + (*propActuelle).loyer3;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur2).prenom, (*joueur2).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 4)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur2).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer4);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer4;
            (*joueur2).argent = (*joueur2).argent + (*propActuelle).loyer4;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur2).prenom, (*joueur2).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 5)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur2).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer5);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer5;
            (*joueur2).argent = (*joueur2).argent + (*propActuelle).loyer5;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur2).prenom, (*joueur2).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }

             ///Enlever l'argent du joueur pour le donner au proprietaire
    }





    else if (comparer2 == 0)
    {
        gotoligcol(16,col);
        printf("Cette propriete appartient a %s", (*joueur3).prenom);
        if ((*propActuelle).nbrMaisons == 0)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur3).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer0);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer0;
            (*joueur3).argent = (*joueur3).argent + (*propActuelle).loyer0;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur3).prenom, (*joueur3).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 1)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur3).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer1);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer1;
            (*joueur3).argent = (*joueur3).argent + (*propActuelle).loyer1;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur3).prenom, (*joueur3).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 2)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur3).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer2);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer2;
            (*joueur3).argent = (*joueur3).argent + (*propActuelle).loyer2;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur3).prenom, (*joueur3).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 3)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur3).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer3);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer3;
            (*joueur3).argent = (*joueur3).argent + (*propActuelle).loyer3;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur3).prenom, (*joueur3).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 4)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur3).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer4);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer4;
            (*joueur3).argent = (*joueur3).argent + (*propActuelle).loyer4;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur3).prenom, (*joueur3).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 5)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur3).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer5);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer5;
            (*joueur3).argent = (*joueur3).argent + (*propActuelle).loyer5;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur3).prenom, (*joueur3).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }


        ///Enlever l'argent du joueur pour le donner au proprietaire
    }





    else if (comparer3 == 0)
    {
        gotoligcol(16,col);
        printf("Cette propriete appartient a %s", (*joueur4).prenom);
        if ((*propActuelle).nbrMaisons == 0)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur4).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer0);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer0;
            (*joueur4).argent = (*joueur4).argent + (*propActuelle).loyer0;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur4).prenom, (*joueur4).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 1)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur4).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer1);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer1;
            (*joueur4).argent = (*joueur4).argent + (*propActuelle).loyer1;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur4).prenom, (*joueur4).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 2)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur4).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer2);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer2;
            (*joueur4).argent = (*joueur4).argent + (*propActuelle).loyer2;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur4).prenom, (*joueur4).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 3)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur4).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer3);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer3;
            (*joueur4).argent = (*joueur4).argent + (*propActuelle).loyer3;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur4).prenom, (*joueur4).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 4)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur4).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer4);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer4;
            (*joueur4).argent = (*joueur4).argent + (*propActuelle).loyer4;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur4).prenom, (*joueur4).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 5)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur4).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer5);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer5;
            (*joueur4).argent = (*joueur4).argent + (*propActuelle).loyer5;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur4).prenom, (*joueur4).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }

        ///Enlever l'argent du joueur pour le donner au proprietaire
    }





    else if (comparer4 == 0)
    {
        gotoligcol(16,col);
        printf("Cette propriete appartient a %s", (*joueur5).prenom);
        if ((*propActuelle).nbrMaisons == 0)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur5).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer0);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer0;
            (*joueur5).argent = (*joueur5).argent + (*propActuelle).loyer0;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur5).prenom, (*joueur5).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 1)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur5).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer1);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer1;
            (*joueur5).argent = (*joueur5).argent + (*propActuelle).loyer1;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur5).prenom, (*joueur5).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 2)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur5).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer2);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer2;
            (*joueur5).argent = (*joueur5).argent + (*propActuelle).loyer2;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur5).prenom, (*joueur5).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 3)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur5).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer3);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer3;
            (*joueur5).argent = (*joueur5).argent + (*propActuelle).loyer3;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur5).prenom, (*joueur5).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 4)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur5).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer4);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer4;
            (*joueur5).argent = (*joueur5).argent + (*propActuelle).loyer4;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur5).prenom, (*joueur5).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 5)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur5).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer5);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer5;
            (*joueur5).argent = (*joueur5).argent + (*propActuelle).loyer5;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur5).prenom, (*joueur5).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }

        ///Enlever l'argent du joueur pour le donner au proprietaire
    }





    else if (comparer5 == 0)
    {
        gotoligcol(16,col);
        printf("Cette propriete appartient a %s", (*joueur6).prenom);
        if ((*propActuelle).nbrMaisons == 0)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur6).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer0);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer0;
            (*joueur6).argent = (*joueur6).argent + (*propActuelle).loyer0;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur6).prenom, (*joueur6).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 1)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur6).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer1);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer1;
            (*joueur6).argent = (*joueur6).argent + (*propActuelle).loyer1;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur6).prenom, (*joueur6).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 2)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur6).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer2);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer2;
            (*joueur6).argent = (*joueur6).argent + (*propActuelle).loyer2;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur6).prenom, (*joueur6).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 3)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur6).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer3);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer3;
            (*joueur6).argent = (*joueur6).argent + (*propActuelle).loyer3;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur6).prenom, (*joueur6).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 4)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur6).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer4);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer4;
            (*joueur6).argent = (*joueur6).argent + (*propActuelle).loyer4;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur6).prenom, (*joueur6).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 5)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur6).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer5);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer5;
            (*joueur6).argent = (*joueur6).argent + (*propActuelle).loyer5;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur6).prenom, (*joueur6).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }

        ///Enlever l'argent du joueur pour le donner au proprietaire
    }





    else if (comparer6 == 0)
    {
        gotoligcol(16,col);
        printf("Cette propriete appartient a %s", (*joueur7).prenom);
        if ((*propActuelle).nbrMaisons == 0)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur7).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer0);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer0;
            (*joueur7).argent = (*joueur7).argent + (*propActuelle).loyer0;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur7).prenom, (*joueur7).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 1)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur7).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer1);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer1;
            (*joueur7).argent = (*joueur7).argent + (*propActuelle).loyer1;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur7).prenom, (*joueur7).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 2)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur7).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer2);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer2;
            (*joueur7).argent = (*joueur7).argent + (*propActuelle).loyer2;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur7).prenom, (*joueur7).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 3)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur7).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer3);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer3;
            (*joueur7).argent = (*joueur7).argent + (*propActuelle).loyer3;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur7).prenom, (*joueur7).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 4)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur7).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer4);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer4;
            (*joueur7).argent = (*joueur7).argent + (*propActuelle).loyer4;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur7).prenom, (*joueur7).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 5)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur7).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer5);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer5;
            (*joueur7).argent = (*joueur7).argent + (*propActuelle).loyer5;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur7).prenom, (*joueur7).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }

        ///Enlever l'argent du joueur pour le donner au proprietaire
    }





    else if (comparer7 == 0)
    {
        gotoligcol(16,col);
        printf("Cette propriete appartient a %s", (*joueur8).prenom);
        if ((*propActuelle).nbrMaisons == 0)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur8).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer0);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer0;
            (*joueur8).argent = (*joueur8).argent + (*propActuelle).loyer0;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur8).prenom, (*joueur8).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 1)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur8).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer1);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer1;
            (*joueur8).argent = (*joueur8).argent + (*propActuelle).loyer1;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur8).prenom, (*joueur8).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 2)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur8).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer2);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer2;
            (*joueur8).argent = (*joueur8).argent + (*propActuelle).loyer2;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur8).prenom, (*joueur8).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 3)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur8).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer3);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer3;
            (*joueur8).argent = (*joueur8).argent + (*propActuelle).loyer3;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur8).prenom, (*joueur8).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 4)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur8).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer4);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer4;
            (*joueur8).argent = (*joueur8).argent + (*propActuelle).loyer4;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur8).prenom, (*joueur8).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if ((*propActuelle).nbrMaisons == 5)
        {
            gotoligcol(18,col);
            printf("%s ne possede pas de maison sur %s", (*joueur8).prenom, (*propActuelle).nom);
            gotoligcol(20,col);
            printf("Vous lui donner donc %d dollars",(*propActuelle).loyer5);
            (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).loyer5;
            (*joueur8).argent = (*joueur8).argent + (*propActuelle).loyer5;
            gotoligcol(22,col);
            printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            gotoligcol(23,col);
            printf("%s possede maintenant %d dollars",(*joueur8).prenom, (*joueur8).argent);
            gotoligcol(26,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(27,col);
            fflush(stdin);
            scanf("%d", &suite);
        }

        ///Enlever l'argent du joueur pour le donner au proprietaire
    }
}






















///---------------------------------------------------------------------------------------------------------------------------------------


///-------------------------------------ACHETER UN BATIMENT-----------------------------------------

void achatMaison (int *NbHotels, int *NbMaisons, struct proprietes *propActuelle, struct joueur *joueurActuel, int lig)
{   //Sous programme d'achat de maisons

    int col = 130;
    int choix = 0;
    int choix2 = 0;
    char suite;
    gotoligcol(lig,col);
    printf("Voulez vous acheter une maison ?");
    gotoligcol((lig+1),col);
    printf("1.\tOui");
    gotoligcol((lig+2),col);
    printf("2.\tNon");
    gotoligcol((lig+3),col);
    fflush(stdin);
    scanf("%d",&choix);
    //blindage
    while (choix < 1 || choix > 2)
        {
            reset((lig+3),(lig+3),130,180);
            gotoligcol(lig,col);
            printf("Demande non valide, voulez vous acheter une maison");
            gotoligcol((lig+3),col);
            fflush(stdin);
            scanf("%d",&choix);
        }





    reset((lig+3),(lig+3),130,180);
    if (choix == 1 && (*propActuelle).nbrMaisons == 0)
    {
        gotoligcol((lig+4),col);
        printf("Combien de maison voulez vous acheter ?");
        gotoligcol((lig+5),col);
        printf("1.\t1 Maison");
        gotoligcol((lig+6),col);
        printf("2.\t2 Maisons");
        gotoligcol((lig+7),col);
        printf("3.\t3 Maisons");
        gotoligcol((lig+8),col);
        printf("4.\t4 Maisons");
        gotoligcol((lig+9),col);
        printf("5.\t1 Hotel");
        gotoligcol((lig+10),col);
        fflush(stdin);
        scanf("%d",&choix2);
        //blindage
        while (choix2 < 1 || choix2 > 5)
        {
            reset((lig+10),(lig+10),130,180);
            gotoligcol((lig+4),col);
            printf("Demande non valide, combien de maison voulez vous acheter ?");
            gotoligcol((lig+10),col);
            fflush(stdin);
            scanf("%d",&choix2);
        }
        if (choix2 == 1 && *NbMaisons <= 31)
        {
            if ((*joueurActuel).argent >= (*propActuelle).prix_maison)
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 1;
                (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).prix_maison;
                maison1((*joueurActuel).caseActuelle);
                *NbMaisons = *NbMaisons + 1;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < (*propActuelle).prix_maison)
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
                gotoligcol((lig+13),col);
                printf("Appuyer sur n'importe quelle touche pour continuer");
                gotoligcol((lig+14),col);
                fflush(stdin);
                scanf("%d", &suite);
            }
        }
        else if (choix2 == 2 && *NbMaisons <= 30)
        {
            if ((*joueurActuel).argent >= (2 * (*propActuelle).prix_maison))
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 2;
                (*joueurActuel).argent = (*joueurActuel).argent - (2 * (*propActuelle).prix_maison);
                maison2((*joueurActuel).caseActuelle);
                *NbMaisons = *NbMaisons + 2;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < ( 2 *(*propActuelle).prix_maison))
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
            }
        }
        else if (choix2 == 3 && *NbMaisons <= 29)
        {
            if ((*joueurActuel).argent >= (3 * (*propActuelle).prix_maison))
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 3;
                (*joueurActuel).argent = (*joueurActuel).argent - (3 * (*propActuelle).prix_maison);
                maison3((*joueurActuel).caseActuelle);
                *NbMaisons = *NbMaisons + 3;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < ( 3 *(*propActuelle).prix_maison))
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
            }
        }
        else if (choix2 == 4 && *NbMaisons <= 28)
        {
            if ((*joueurActuel).argent >= (4 * (*propActuelle).prix_maison))
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 4;
                (*joueurActuel).argent = (*joueurActuel).argent - (4 * (*propActuelle).prix_maison);
                maison4((*joueurActuel).caseActuelle);
                *NbMaisons = *NbMaisons + 4;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < ( 4 *(*propActuelle).prix_maison))
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
            }
        }
        else if (choix2 == 5 && *NbHotels <= 11)
        {
            if ((*joueurActuel).argent >= (5 * (*propActuelle).prix_maison))
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 5;
                (*joueurActuel).argent = (*joueurActuel).argent - (5 * (*propActuelle).prix_maison);
                hotel((*joueurActuel).caseActuelle);
                *NbHotels = *NbHotels + 1;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < ( 5 *(*propActuelle).prix_maison))
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
            }
        }
        else if (*NbMaisons >= 32 && choix2 == 1)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d  maisons sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun de maisons est 32");
        }
        else if(choix2 == 2 && *NbMaisons >= 31)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d maisons sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun de maisons est 32");
        }
        else if(choix2 == 3 && *NbMaisons >= 30)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d maisons sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun de maisons est 32");
        }
        else if(choix2 == 4 && *NbMaisons >= 29)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d maisons sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun de maisons est 32");
        }
        else if(choix2 == 5 && *NbHotels >= 12)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d hotels sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun d'hotels est 16");
        }



    }

















    else if (choix == 1 && (*propActuelle).nbrMaisons == 1)
    {
        gotoligcol((lig+4),col);
        printf("Combien de maison voulez vous acheter ?");
        gotoligcol((lig+5),col);
        printf("1.\t1 Maison");
        gotoligcol((lig+6),col);
        printf("2.\t2 Maisons");
        gotoligcol((lig+7),col);
        printf("3.\t3 Maisons");
        gotoligcol((lig+8),col);
        printf("4.\t1 Hotel");
        gotoligcol((lig+9),col);
        fflush(stdin);
        scanf("%d",&choix2);
        //blindage
        while (choix2 < 1 || choix2 > 5)
        {
            reset((lig+9),(lig+9),130,180);
            gotoligcol((lig+4),col);
            printf("Demande non valide, combien de maison voulez vous acheter ?");
            gotoligcol((lig+9),col);
            fflush(stdin);
            scanf("%d",&choix2);
        }
        reset(45,45,130,180);
        if (choix2 == 1 && *NbMaisons <= 31)
        {
            if ((*joueurActuel).argent >= (*propActuelle).prix_maison)
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 1;
                (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).prix_maison;
                maison1((*joueurActuel).caseActuelle);
                *NbMaisons = *NbMaisons + 1;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < (*propActuelle).prix_maison)
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
                gotoligcol((lig+13),col);
                printf("Appuyer sur n'importe quelle touche pour continuer");
                gotoligcol((lig+14),col);
                fflush(stdin);
                scanf("%d", &suite);
            }
        }
        else if (choix2 == 2 && *NbMaisons <= 30)
        {
            if ((*joueurActuel).argent >= (2 * (*propActuelle).prix_maison))
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 2;
                (*joueurActuel).argent = (*joueurActuel).argent - (2 * (*propActuelle).prix_maison);
                maison2((*joueurActuel).caseActuelle);
                *NbMaisons = *NbMaisons + 2;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < ( 2 *(*propActuelle).prix_maison))
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
            }
        }
        else if (choix2 == 3 && *NbMaisons <= 29)
        {
            if ((*joueurActuel).argent >= (3 * (*propActuelle).prix_maison))
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 3;
                (*joueurActuel).argent = (*joueurActuel).argent - (3 * (*propActuelle).prix_maison);
                maison3((*joueurActuel).caseActuelle);
                *NbMaisons = *NbMaisons + 3;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < ( 3 *(*propActuelle).prix_maison))
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
            }
        }
        else if (choix2 == 4 && *NbHotels <= 11)
        {
            if ((*joueurActuel).argent >= (5 * (*propActuelle).prix_maison))
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 5;
                (*joueurActuel).argent = (*joueurActuel).argent - (5 * (*propActuelle).prix_maison);
                hotel((*joueurActuel).caseActuelle);
                *NbHotels = *NbHotels + 1;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < ( 5 *(*propActuelle).prix_maison))
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
            }
        }
        else if (*NbMaisons >= 32 && choix2 == 1)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d  maisons sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun de maisons est 32");
        }
        else if(choix2 == 2 && *NbMaisons >= 31)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d maisons sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun de maisons est 32");
        }
        else if(choix2 == 3 && *NbMaisons >= 30)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d maisons sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun de maisons est 32");
        }
        else if(choix2 == 4 && *NbHotels >= 12)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d hotels sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun d'hotels est 16");
        }



    }









    else if(choix == 1 && (*propActuelle).nbrMaisons == 2)
    {
        gotoligcol((lig+4),col);
        printf("Combien de maison voulez vous acheter ?");
        gotoligcol((lig+5),col);
        printf("1.\t1 Maison");
        gotoligcol((lig+6),col);
        printf("2.\t2 Maisons");
        gotoligcol((lig+7),col);
        printf("3.\t1 Hotel");
        gotoligcol((lig+8),col);
        fflush(stdin);
        scanf("%d",&choix2);
        lig = lig - 2;
        while (choix2 < 1 || choix2 > 3)
        {
            reset((lig+8),(lig+8),130,180);
            gotoligcol((lig+4),col);
            printf("Demande non valide, combien de maison voulez vous acheter ?");
            gotoligcol((lig+8),col);
            fflush(stdin);
            scanf("%d",&choix2);
        }
        if (choix2 == 1 && *NbMaisons <= 31)
        {
            if ((*joueurActuel).argent >= (*propActuelle).prix_maison)
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 1;
                (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).prix_maison;
                maison1((*joueurActuel).caseActuelle);
                *NbMaisons = *NbMaisons + 1;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < (*propActuelle).prix_maison)
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
                gotoligcol((lig+13),col);
                printf("Appuyer sur n'importe quelle touche pour continuer");
                gotoligcol((lig+14),col);
                fflush(stdin);
                scanf("%d", &suite);
            }
        }
        else if (choix2 == 2 && *NbMaisons <= 30)
        {
            if ((*joueurActuel).argent >= (2 * (*propActuelle).prix_maison))
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 2;
                (*joueurActuel).argent = (*joueurActuel).argent - (2 * (*propActuelle).prix_maison);
                maison2((*joueurActuel).caseActuelle);
                *NbMaisons = *NbMaisons + 2;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < ( 2 *(*propActuelle).prix_maison))
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
            }
        }
        else if (choix2 == 3 && *NbHotels <= 11)
        {
            if ((*joueurActuel).argent >= (5 * (*propActuelle).prix_maison))
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 5;
                (*joueurActuel).argent = (*joueurActuel).argent - (5 * (*propActuelle).prix_maison);
                hotel((*joueurActuel).caseActuelle);
                *NbHotels = *NbHotels + 1;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < ( 5 *(*propActuelle).prix_maison))
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
            }
        }
        else if (*NbMaisons >= 32 && choix2 == 1)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d  maisons sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun de maisons est 32");
        }
        else if(choix2 == 2 && *NbMaisons >= 31)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d maisons sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun de maisons est 32");
        }
        else if(choix2 == 3 && *NbHotels >= 12)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d hotels sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun d'hotels est 16");
        }


    }

    else if(choix == 1 && (*propActuelle).nbrMaisons == 3)
    {
        gotoligcol((lig+4),col);
        printf("Combien de maison voulez vous acheter ?");
        gotoligcol((lig+5),col);
        printf("1.\t1 Maison");
        gotoligcol((lig+6),col);
        printf("2.\t1 Hotel");
        gotoligcol((lig+7),col);
        fflush(stdin);
        scanf("%d",&choix2);
        lig = lig - 3;
        while (choix2 < 1 || choix2 > 2)
        {
            reset((lig+7),(lig+7),130,180);
            gotoligcol((lig+4),col);
            printf("Demande non valide, combien de maison voulez vous acheter ?");
            gotoligcol((lig+7),col);
            fflush(stdin);
            scanf("%d",&choix2);
        }
        if (choix2 == 1 && *NbMaisons <= 31)
        {
            if ((*joueurActuel).argent >= (*propActuelle).prix_maison)
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 1;
                (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).prix_maison;
                maison1((*joueurActuel).caseActuelle);
                *NbMaisons = *NbMaisons + 1;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < (*propActuelle).prix_maison)
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
                gotoligcol((lig+13),col);
                printf("Appuyer sur n'importe quelle touche pour continuer");
                gotoligcol((lig+14),col);
                fflush(stdin);
                scanf("%d", &suite);
            }
        }
        else if (choix2 == 2 && *NbHotels <= 11)
        {
            if ((*joueurActuel).argent >= (5 * (*propActuelle).prix_maison))
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 5;
                (*joueurActuel).argent = (*joueurActuel).argent - (5 * (*propActuelle).prix_maison);
                hotel((*joueurActuel).caseActuelle);
                *NbHotels = *NbHotels + 1;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < ( 5 *(*propActuelle).prix_maison))
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
            }
        }
        else if (*NbMaisons >= 32 && choix2 == 1)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d  maisons sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun de maisons est 32");
        }
        else if(choix2 == 2 && *NbHotels >= 12)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d hotels sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun d'hotels est 16");
        }


    }











    else if(choix == 1 && (*propActuelle).nbrMaisons == 4)
    {
        gotoligcol((lig+4),col);
        printf("Combien de maison voulez vous acheter ?");
        gotoligcol((lig+5),col);
        printf("1.\t1 Hotel");
        gotoligcol((lig+6),col);
        fflush(stdin);
        scanf("%d",&choix2);
        lig = lig - 4;
        while (choix2 != 1)
        {
            reset((lig+6),(lig+6),130,180);
            gotoligcol((lig+4),col);
            printf("Demande non valide, combien de maison voulez vous acheter ?");
            gotoligcol((lig+6),col);
            fflush(stdin);
            scanf("%d",&choix2);
        }
        if (choix2 == 1 && *NbHotels <= 11)
        {
            if ((*joueurActuel).argent >= (5 * (*propActuelle).prix_maison))
            {
                (*propActuelle).nbrMaisons = (*propActuelle).nbrMaisons + 5;
                (*joueurActuel).argent = (*joueurActuel).argent - (5 * (*propActuelle).prix_maison);
                hotel((*joueurActuel).caseActuelle);
                *NbHotels = *NbHotels + 1;
                gotoligcol((lig+11),col);
                printf("Il ya donc %d maisons sur %s", (*propActuelle).nbrMaisons, (*propActuelle).nom);
                gotoligcol((lig+12),col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < ( 5 *(*propActuelle).prix_maison))
            {
                gotoligcol((lig+11),col);
                printf("Vous ne possedez pas assez d'argent");
            }
        }
        else if(choix2 == 1 && *NbHotels >= 12)
        {
            gotoligcol(lig+11,col);
            printf("Il y a %d hotels sur le plateau", *NbMaisons);
            gotoligcol(lig+12,col);
            printf("Or ,le nombre maximun d'hotels est 16");
        }


    }

    else if(choix == 1 && (*propActuelle).nbrMaisons == 5)
    {
        gotoligcol((lig+4),col);
        printf("Vous ne pouvez pas acheter plus de maison sur cette propriete");
    }

    else if(choix == 2)
    {

    }
    gotoligcol((lig+14),col);
    printf("Appuyer sur la touche espace pour continuer");
    gotoligcol((lig+15),col);
    fflush(stdin);
    scanf("%c", &suite);
    while(suite != 32)
    {
        reset(lig+15,lig+15,col,col+50);
        gotoligcol(lig+15,col);
        fflush(stdin);
        scanf("%c", &suite);
    }
    reset(4,54,col,col+80);



}




///---------------------------------------------------------------------------------------------------------------------------------------


int MenuAchat (int *NbHotels, int *NbMaisons, struct proprietes *propActuelle, struct joueur *joueurActuel, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8)
{   //Sous programme d'achat de proprietes
    int col = 130;
    int suite;
    gotoligcol(13,col);
    affichageProprietes(*propActuelle);
    int choix = 0;
    char banque[15] = "Banque";
    if (strcmp((*propActuelle).proprietaire, banque) == 0)
    {
        gotoligcol(28,col);
        printf("Voulez-vous acheter %s au prix de %d ?",(*propActuelle).nom, (*propActuelle).prix);
        gotoligcol(29,col);
        printf("1.\tOui");
        gotoligcol(30,col);
        printf("2.\tNon");
        gotoligcol(31,col);
        fflush(stdin);
        scanf("%d",&choix);
        while (choix < 1 || choix > 2)
        {
            reset(31,31,130,180);
            gotoligcol(28,col);
            printf("Demande non valide, voulez-vous acheter %s au prix de %d ?",(*propActuelle).nom, (*propActuelle).prix);
            gotoligcol(31,col);
            fflush(stdin);
            scanf("%d",&choix);
        }
        if (choix == 1)
        {
            reset(31,31,130,180);
            if ((*joueurActuel).argent < (*propActuelle).prix)
            {
                gotoligcol(33,col);
                printf("Vous n'avez pas assez d'argent pour acheter cette propriete !");
                gotoligcol(36,col);
                printf("Appuyer sur n'importe quelle touche pour continuer");
                gotoligcol(37,col);
                fflush(stdin);
                scanf("%d",&suite);
            }
            else if ((*joueurActuel).argent >= (*propActuelle).prix)
            {
                strcpy((*propActuelle).proprietaire, (*joueurActuel).prenom);
                gotoligcol(33,col);
                printf("%s possede maintenant la case %s",(*joueurActuel).prenom, (*propActuelle).nom);
                (*joueurActuel).argent = (*joueurActuel).argent - (*propActuelle).prix;
                (*joueurActuel).nbrProprietes = (*joueurActuel).nbrProprietes + 1;
                ///Mettre la structure de la propriete dans la structure joueur
                gotoligcol(34,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
                achatMaison(NbHotels, NbMaisons, propActuelle, joueurActuel, 35);      ///Demander si il veut mettre des maison...
            }

        }
    }
    else if (strcmp((*propActuelle).proprietaire, banque) != 0)
    {

        if (strcmp((*propActuelle).proprietaire, (*joueurActuel).prenom) == 0 && (*propActuelle).valHypotheque == 0)
        {
            gotoligcol(14,col);
            printf("Cette propriete vous appartient");
            gotoligcol(15,col);
            printf("Voulez vous acheter une nouvelle maison ?");
            achatMaison(NbHotels, NbMaisons, propActuelle, joueurActuel, 17);      ///Demander si il veut mettre des maison...
        }
        else if (strcmp((*propActuelle).proprietaire, (*joueurActuel).prenom) == 0 && (*propActuelle).valHypotheque == 1)
        {
            gotoligcol(14,col);
            printf("Cette propriete vous appartient, mais elle est en hypotheque");
            gotoligcol(15,col);
            printf("Donc vous ne pouvez rien faire dessus");
            gotoligcol(20,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(21,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
        else if (strcmp((*propActuelle).proprietaire, (*joueurActuel).prenom) != 0 && (*propActuelle).valHypotheque == 0)
        {
            gotoligcol(14,col);
            printf("Un autre joueur possede deja cette propriete !!!");
            retrouverProprio(propActuelle, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            ///Retouver le proprietaire avec un autre sous programme
            ///Lui donner l'argent en fonction du nombre de maison ...
        }
        else if (strcmp((*propActuelle).proprietaire, (*joueurActuel).prenom) != 0 && (*propActuelle).valHypotheque == 1)
        {
            gotoligcol(14,col);
            printf("Un autre joueur possede deja cette propriete, mais elle est en hypotheque");
            gotoligcol(15,col);
            printf("Donc vous n'avais rien a payer !");
            gotoligcol(20,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(21,col);
            fflush(stdin);
            scanf("%d", &suite);
        }
    }



}






int lancerDes (int* maxdouble, int lig)
{
    int detot = 0;
    detot = mainDes(maxdouble, lig);
    return detot;
}














int MenuJoueur(int *NbHotels, int *NbMaisons, int tour, int nbrJoueurs, struct joueur *joueurActuel, struct joueur *joueur1, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8, struct proprietes *Gdynia, struct proprietes *Taipei, struct proprietes *Tokyo, struct proprietes *Barcelone, struct proprietes *Athenes, struct proprietes *Istanbul, struct proprietes *Kyiv, struct proprietes *Toronto, struct proprietes *Rome, struct proprietes *Shanghai, struct proprietes *Vancouver, struct proprietes *Sydney, struct proprietes *NewYork, struct proprietes *Londres, struct proprietes *Beijing, struct proprietes *HongKong, struct proprietes *Jerusalem, struct proprietes *Paris, struct proprietes *Belgrade, struct proprietes *LeCap, struct proprietes *Riga, struct proprietes *Montreal)
{

    char suitePrison;
    int plat = 0;
    int suite;
    int quitter = 0;
    int choix = 0;
    int choix2 = 0;
    int choix3 = 0;
    int choix4 = 0;
    int choix5 = 0;
    int choix6 = 0;
    int maxdouble = 0;
    int col = 130;
    reset(0,51,130,200);
    if(tour == 0)
    {
        gotoligcol(0,0);
        plateau();

    }
    resetPion();
    positionDuPion(nbrJoueurs, joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);


    if ((*joueurActuel).argent <= 0)
    {
        gotoligcol(1,col);
        printf("------------- C'est au tour de %s de jouer !!! ------------- ",(*joueurActuel).prenom);
        gotoligcol(3,col);
        printf("Vous n'avez plus d'argent !");
        if ((*joueurActuel).nbrProprietes > 0)
        {
            gotoligcol(5,col);
            printf("Vous devez donc vendre des proprietes avant de jouer");
            faillite(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);///Affichage des proprietes
            while ((*joueurActuel).argent <= 0 && (*joueurActuel).nbrProprietes > 0)
            {
                reset(3,50,col,col+80);
                gotoligcol(5,col);
                printf("Vous etes encore a decouvert !");
                gotoligcol(6,col);
                printf("Vous devez donc vendre des proprietes avant de jouer");
                faillite(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);///Affichage des proprietes

            }
        }
        if((*joueurActuel).argent <= 0 && (*joueurActuel).nbrProprietes == 0)
        {
            gotoligcol(5,col);
            printf("Vous n'avez plus non plus de proprietes");
            gotoligcol(6,col);
            printf("Vous etes donc elimine !");
            (*joueurActuel).enJeu = 0;
        }
    }







    if ((*joueurActuel).OrdreDePassage == 1)
    {
        gotoligcol(1,col);
        printf("------------- C'est au tour de %s de jouer !!! ------------- ",(*joueurActuel).prenom);
        gotoligcol(3,col);
        printf("%s que voulez vous faire ?",(*joueurActuel).prenom);
        gotoligcol(4,col);
        printf("1.\tLancer les des");
        gotoligcol(5,col);
        printf("2.\tAfficher vos informations");
        gotoligcol(6,col);
        printf("3.\tAfficher vos proprietes");
        gotoligcol(7,col);
        printf("4.\tVendre, hypothequer ou racheter des proprietes");
        gotoligcol(8,col);
        printf("5\tQuitter");
        gotoligcol(9,col);
        fflush(stdin);
        scanf("%d",&choix);
        while(choix < 1 || choix > 5)
        {
            reset(9,9,col,col+10);
            gotoligcol(9,col);
            fflush(stdin);
            scanf("%d",&choix);
        }
        reset(3,9,col,col+50);
    }


    else
    {
        gotoligcol(1,col);
        printf("------------- C'est au tour de %s de jouer !!! ------------- ",(*joueurActuel).prenom);
        gotoligcol(3,col);
        printf("%s que voulez vous faire ?",(*joueurActuel).prenom);
        gotoligcol(4,col);
        printf("1.\tLancer les des");
        gotoligcol(5,col);
        printf("2.\tAfficher vos informations");
        gotoligcol(6,col);
        printf("3.\tAfficher vos proprietes");
        gotoligcol(7,col);
        printf("4.\tVendre, hypothequer ou racheter des proprietes");
        gotoligcol(8,col);
        fflush(stdin);
        scanf("%d",&choix);
        while(choix < 1 || choix > 4)
        {
            reset(8,8,col,col+10);
            gotoligcol(8,col);
            fflush(stdin);
            scanf("%d",&choix);

        }
        reset(3,8,col,col+50);
    }




    int detot = 0;


    ///----------------------------Le joueur veut lancer les dés directement :------------------------------------

    if (choix == 1)
    {
        detot = lancerDes(&maxdouble, 6);
        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
        if ((*joueurActuel).caseActuelle > 32)
        {
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
            gotoligcol(12,col);
            printf("Vous etes passez par la case depart... + 200 dollars");
            (*joueurActuel).argent = (*joueurActuel).argent + 200;
        }
        resetPion();
        positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
        gotoligcol(13,col);

        affichageCaseActuelle((*joueurActuel).caseActuelle);
        menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete





        if (maxdouble == 1)     ///Si on a fait un double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
            }
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete
        }

        if (maxdouble == 2)     ///Si on a fait un autre double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
            }
            //plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete

        }
        if(maxdouble == 3)
        {

            while(suitePrison != 32)
            {
                gotoligcol(15,col);
                printf("Vous avez 3 doubles d'affile, vous allez en prison (touche espace pour continuer)");
                gotoligcol(16,col);
                fflush(stdin);
                scanf("%c", &suitePrison);
                reset(16,16,col,col+50);
            }
            reset(3,30,col,col+80);
            menuPrison(joueurActuel, maxdouble, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);


        }
        maxdouble = 0;
    }





    ///-----------------------------Le joueur veut voir ses informations avant de jouer :-------------------------
    else if(choix == 2)
    {

        gotoligcol(5,col);
        affichageJoueur(joueurActuel);
        gotoligcol(11,col);
        printf("%s que voulez vous faire ",(*joueurActuel).prenom);
        gotoligcol(12,col);
        printf("1.\tLancer les des",(*joueurActuel).prenom);
        gotoligcol(13,col);
        printf("2.\tAfficher vos proprietes",(*joueurActuel).prenom);
        gotoligcol(14,col);
        fflush(stdin);
        scanf("%d",&choix2);
        while(choix2 < 1 || choix2 > 2)
        {
            reset(14,14,130,180);
            gotoligcol(11,col);
            printf("Demande non valide, %s que voulez vous faire ?",(*joueurActuel).prenom);
            gotoligcol(14,col);
            fflush(stdin);
            scanf("%d",&choix2);
        }
        reset(4,14,130,180);
    if(choix2 == 1)
    {


        detot = lancerDes(&maxdouble, 6);
        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
        if ((*joueurActuel).caseActuelle > 32)
        {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
        }
        //plateau();
        resetPion();
        positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
        gotoligcol(13,col);
        affichageCaseActuelle((*joueurActuel).caseActuelle);
        menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete



        if (maxdouble == 1)     ///Si on a fait un double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
            }
            //plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete
        }

        if (maxdouble == 2)     ///Si on a fait un autre double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;

            }
           // plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete

        }
        if(maxdouble == 3)
        {

            while(suitePrison != 32)
            {
                gotoligcol(15,col);
                printf("Vous avez 3 doubles d'affile, vous allez en prison (touche espace pour continuer)");
                gotoligcol(16,col);
                fflush(stdin);
                scanf("%c", &suitePrison);
                reset(16,16,col,col+50);
            }
            reset(3,30,col,col+80);
            menuPrison(joueurActuel, maxdouble, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);


        }

        maxdouble = 0;
    }


    else if (choix2 == 2)
        {
            if ((*joueurActuel).nbrProprietes == 0)
            {
                gotoligcol(3,col);
                printf("Vous ne possedez pas de proprietes.");
            }
            else if((*joueurActuel).nbrProprietes != 0)
            {
                affichageProprietesJoueur(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);///Affichage des proprietes
            }
            gotoligcol(10,col);
            printf("%s vous pouvez uniquement lancer les des (tappez 1)",(*joueurActuel).prenom);
            gotoligcol(11,col);
            fflush(stdin);
            scanf("%d",&choix3);
            while(choix3 < 1 || choix3 > 1)
                {
                    reset(11,11,col,col+50);
                    gotoligcol(10,col);
                    printf("Demande non valide, %s vous poubez uniquement lancer les des (tappez 1)",(*joueurActuel).prenom);
                    gotoligcol(11,col);
                    fflush(stdin);
                    scanf("%d",&choix3);
                }
            if (choix3 == 1)
            {
        reset(3,50,col,col+70);
        detot = lancerDes(&maxdouble, 6);
        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
        if ((*joueurActuel).caseActuelle > 32)
        {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
        }
        //plateau();
        resetPion();
        positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
        gotoligcol(13,col);
        affichageCaseActuelle((*joueurActuel).caseActuelle);
        menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete



        if (maxdouble == 1)     ///Si on a fait un double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
            }
           // plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete
        }

        if (maxdouble == 2)     ///Si on a fait un autre double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
            }
           // plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete

        }
        if(maxdouble == 3)
        {

            while(suitePrison != 32)
            {
                gotoligcol(15,col);
                printf("Vous avez 3 doubles d'affile, vous allez en prison (touche espace pour continuer)");
                gotoligcol(16,col);
                fflush(stdin);
                scanf("%c", &suitePrison);
                reset(16,16,col,col+50);
            }
            reset(3,30,col,col+80);
            menuPrison(joueurActuel, maxdouble, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);


        }
        }
        maxdouble = 0;
    }
    }

    else if (choix == 3)
    {
        if ((*joueurActuel).nbrProprietes == 0)
        {
            gotoligcol(3,col);
            printf("Vous ne possedez pas de proprietes.");
        }
        else if((*joueurActuel).nbrProprietes != 0)
        {
            affichageProprietesJoueur(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);///Affichage des proprietes
        }
        gotoligcol(10,col);
        printf("%s que voulez vous faire ?",(*joueurActuel).prenom);
        gotoligcol(11,col);
        printf("1.\tLancer les des",(*joueurActuel).prenom);
        gotoligcol(12,col);
        printf("2.\tAfficher vos informations\n",(*joueurActuel).prenom);
        gotoligcol(13,col);
        fflush(stdin);
        scanf("%d",&choix4);
        while(choix4 < 1 || choix4 > 2)
            {
                reset(13,13,col,col+50);
                gotoligcol(10,col);
                printf("Demande non valide, %s que voulez vous faire ?",(*joueurActuel).prenom);
                gotoligcol(13,col);
                fflush(stdin);
                scanf("%d",&choix4);
            }
        reset(3,20,col,col+50);
        if (choix4 == 1)
        {
        detot = lancerDes(&maxdouble, 6);
        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
        if ((*joueurActuel).caseActuelle > 32)
        {
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
            gotoligcol(5,col);
            printf("Vous etes passez par la case depart... + 200 dollars");
            gotoligcol(6,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(7,col);
            fflush(stdin);
            scanf("%d", &suite);
            (*joueurActuel).argent = (*joueurActuel).argent + 200;
            reset(5,7,130,160);
        }
       // plateau();
        resetPion();
        positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
        gotoligcol(13,col);
        affichageCaseActuelle((*joueurActuel).caseActuelle);
        menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete



        if (maxdouble == 1)     ///Si on a fait un double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
            }
            //plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete
        }

        if (maxdouble == 2)     ///Si on a fait un autre double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
            }
            //plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
        if(maxdouble == 3)
        {

            while(suitePrison != 32)
            {
                gotoligcol(15,col);
                printf("Vous avez 3 doubles d'affile, vous allez en prison (touche espace pour continuer)");
                gotoligcol(16,col);
                fflush(stdin);
                scanf("%c", &suitePrison);
                reset(16,16,col,col+50);
            }
            reset(3,30,col,col+80);
            menuPrison(joueurActuel, maxdouble, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);


        }
        }
        maxdouble = 0;


        }
        else if (choix4 == 2)
        {
            gotoligcol(5,col);
            affichageJoueur(joueurActuel);
            gotoligcol(11,col);
            printf("%s vous pouvez uniquement lancer les des (tappez 1)",(*joueurActuel).prenom);
            gotoligcol(12,col);
            fflush(stdin);
            scanf("%d",&choix5);
            while(choix5 != 1)
                {
                    reset(12,12,col,col+50);
                    gotoligcol(11,col);
                    printf("Demande non valide, %s vous pouvez uniquement lancer les des (tappez 1)",(*joueurActuel).prenom);
                    gotoligcol(12,col);
                    fflush(stdin);
                    scanf("%d",&choix5);
                }
            reset(4,12,col,col+70);
            if (choix5 == 1)
            {
        detot = lancerDes(&maxdouble, 6);
        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
        if ((*joueurActuel).caseActuelle > 32)
        {
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
            gotoligcol(5,col);
            printf("Vous etes passez par la case depart... + 200 dollars");
            gotoligcol(6,col);
            printf("Appuyer sur n'importe quelle touche pour continuer");
            gotoligcol(7,col);
            fflush(stdin);
            scanf("%d", &suite);
            (*joueurActuel).argent = (*joueurActuel).argent + 200;
            reset(5,7,130,160);
        }
        //plateau();
        resetPion();
        positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
        gotoligcol(13,col);
        affichageCaseActuelle((*joueurActuel).caseActuelle);
        menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete



        if (maxdouble == 1)     ///Si on a fait un double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
            }
            //plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete
        }

        if (maxdouble == 2)     ///Si on a fait un autre double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
            }
            //plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
        if(maxdouble == 3)
        {

            while(suitePrison != 32)
            {
                gotoligcol(15,col);
                printf("Vous avez 3 doubles d'affile, vous allez en prison (touche espace pour continuer)");
                gotoligcol(16,col);
                fflush(stdin);
                scanf("%c", &suitePrison);
                reset(16,16,col,col+50);
            }
            reset(3,30,col,col+80);
            menuPrison(joueurActuel, maxdouble, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);


        }
        }
        maxdouble = 0;
            }
        }
    }

    else if (choix == 4)
    {
        if ((*joueurActuel).nbrProprietes == 0)
        {
            gotoligcol(8,col);
            printf("Vous ne possedez pas de proprietes.");
            gotoligcol(10,col);
            printf("%s vous pouvez uniquement lancer les des (tappez 1)",(*joueurActuel).prenom);
            gotoligcol(11,col);
            fflush(stdin);
            scanf("%d",&choix3);
            while(choix3 < 1 || choix3 > 1)
                {
                    reset(11,11,col,col+50);
                    gotoligcol(10,col);
                    printf("Demande non valide, %s vous poubez uniquement lancer les des (tappez 1)",(*joueurActuel).prenom);
                    gotoligcol(11,col);
                    fflush(stdin);
                    scanf("%d",&choix3);
                }
            if (choix3 == 1)
            {
        reset(3,50,col,col+70);
        detot = lancerDes(&maxdouble, 6);
        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
        if ((*joueurActuel).caseActuelle > 32)
        {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
        }
        //plateau();
        resetPion();
        positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
        gotoligcol(13,col);
        affichageCaseActuelle((*joueurActuel).caseActuelle);
        menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete



        if (maxdouble == 1)     ///Si on a fait un double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
            }
           // plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete
        }

        if (maxdouble == 2)     ///Si on a fait un autre double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
            }
           // plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete

        }
        if(maxdouble == 3)
        {

            while(suitePrison != 32)
            {
                gotoligcol(15,col);
                printf("Vous avez 3 doubles d'affile, vous allez en prison (touche espace pour continuer)");
                gotoligcol(16,col);
                fflush(stdin);
                scanf("%c", &suitePrison);
                reset(16,16,col,col+50);
            }
            reset(3,30,col,col+80);
            menuPrison(joueurActuel, maxdouble, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);


        }
        }
        maxdouble = 0;
        }




        else if((*joueurActuel).nbrProprietes != 0)
        {
            faillite(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);///Affichage des proprietes
        }
        gotoligcol(10,col);
            printf("%s vous pouvez uniquement lancer les des (tappez 1)",(*joueurActuel).prenom);
            gotoligcol(11,col);
            fflush(stdin);
            scanf("%d",&choix3);
            while(choix3 < 1 || choix3 > 1)
                {
                    reset(11,11,col,col+50);
                    gotoligcol(10,col);
                    printf("Demande non valide, %s vous poubez uniquement lancer les des (tappez 1)",(*joueurActuel).prenom);
                    gotoligcol(11,col);
                    fflush(stdin);
                    scanf("%d",&choix3);
                }
            if (choix3 == 1)
            {
        reset(3,50,col,col+70);
        detot = lancerDes(&maxdouble, 6);
        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
        if ((*joueurActuel).caseActuelle > 32)
        {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
        }
        //plateau();
        resetPion();
        positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
        gotoligcol(13,col);
        affichageCaseActuelle((*joueurActuel).caseActuelle);
        menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete



        if (maxdouble == 1)     ///Si on a fait un double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
            }
           // plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete
        }

        if (maxdouble == 2)     ///Si on a fait un autre double, on refait la même choise pour rejouer
        {
            reset(3,50,130,200);
            gotoligcol(3,col);
            printf("Vous avez fait un double, ducoup vous rejouez !");
            detot = lancerDes(&maxdouble,7);
            (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            if ((*joueurActuel).caseActuelle > 32)
            {
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle - 32;
                gotoligcol(12,col);
                printf("Vous etes passez par la case depart... + 200 dollars");
                (*joueurActuel).argent = (*joueurActuel).argent + 200;
            }
           // plateau();
            resetPion();
            positionDuPion( nbrJoueurs,  joueur1,  joueur2,  joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
            gotoligcol(13,col);
            affichageCaseActuelle((*joueurActuel).caseActuelle);
            menuProp(NbHotels, NbMaisons, (*joueurActuel).caseActuelle, joueurActuel,  joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///Recherche de la propriete

        }
        if(maxdouble == 3)
        {

            while(suitePrison != 32)
            {
                gotoligcol(15,col);
                printf("Vous avez 3 doubles d'affile, vous allez en prison (touche espace pour continuer)");
                gotoligcol(16,col);
                fflush(stdin);
                scanf("%c", &suitePrison);
                reset(16,16,col,col+50);
            }
            reset(3,30,col,col+80);
            menuPrison(joueurActuel, maxdouble, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);


        }
        }
        maxdouble = 0;
        }

    else if (choix == 5)
    {
        quitter = questionSauvegarde(nbrJoueurs, joueur1, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
        if (quitter == 1)
        {
            gotoligcol(36,130);
            return 1;
        }
    }

    return 0;
}
