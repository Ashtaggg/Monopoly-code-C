#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Structures.h"






void affichageProprietes(struct proprietes nom)     //Sous programme d'affichage d'une structure proprietes
{
    int col = 130;
    gotoligcol(14,col);
    printf("Nom : %s", nom.nom);
    gotoligcol(15,col);
    printf("Prix d'achat : %d", nom.prix);
    gotoligcol(16,col);
    printf("Loyer sans maison : %d", nom.loyer0);
    gotoligcol(17,col);
    printf("Loyer avec 1 maison : %d", nom.loyer1);
    gotoligcol(18,col);
    printf("Loyer avec 2 maisons : %d", nom.loyer2);
    gotoligcol(19,col);
    printf("Loyer avec 3 maisons : %d", nom.loyer3);
    gotoligcol(20,col);
    printf("Loyer avec 4 maisons : %d", nom.loyer4);
    gotoligcol(21,col);
    printf("Loyer avec hotel : %d", nom.loyer5);
    gotoligcol(22,col);
    printf("Hypotheque : %d", nom.valeur_hypotheque);
    gotoligcol(23,col);
    printf("Prix d'achat d'une maison : %d", nom.prix_maison);
    gotoligcol(24,col);
    printf("Nom proprietaire : %s", nom.proprietaire);
    if (nom.nbrMaisons <= 4)
    {
        gotoligcol(25,col);
        printf("Nombre de maisons : %d maisons", nom.nbrMaisons);
    }
    else if (nom.nbrMaisons == 5)
    {
        gotoligcol(25,col);
        printf("Nombre d'hotel : 1");
    }
    gotoligcol(26,col);
    printf("Famille : %s", nom.famille);
}









int cases(int propActuelle, struct joueur *joueurActuel, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8, struct proprietes *Gdynia, struct proprietes *Taipei, struct proprietes *Tokyo, struct proprietes *Barcelone, struct proprietes *Athenes, struct proprietes *Istanbul, struct proprietes *Kyiv, struct proprietes *Toronto, struct proprietes *Rome, struct proprietes *Shanghai, struct proprietes *Vancouver, struct proprietes *Sydney, struct proprietes *NewYork, struct proprietes *Londres, struct proprietes *Beijing, struct proprietes *HongKong, struct proprietes *Jerusalem, struct proprietes *Paris, struct proprietes *Belgrade, struct proprietes *LeCap, struct proprietes *Riga, struct proprietes *Montreal)
{   //Sous programme pour les cases qui ne sont pas des proprietes
    int col = 130;
    int suite;
    int maxdouble = 0;
    srand(time(NULL));
    if (propActuelle == 3)  //Si la case est Impot sur le revennu
    {
        (*joueurActuel).argent = (*joueurActuel).argent - 200;
        gotoligcol(16,col);
        printf("Vous perdez 200 dollars.");
        gotoligcol(17,col);
        printf("%s possede maintenant %d dollars\n\n",(*joueurActuel).prenom, (*joueurActuel).argent);
        gotoligcol(22,col);
        printf("Appuyer sur n'importe quelle touche pour continuer");
        gotoligcol(23,col);
        fflush(stdin);
        scanf("%d", &suite);
    }
    else if (propActuelle == 5 || propActuelle == 21)   //Si la case est une carte chance
    {
        cartechance(joueurActuel); //sous programme pour les cartes chances
    }
    else if (propActuelle == 9) //Si la case est la visite simple
    {
        gotoligcol(14,col);
        printf("Vous etes en visite simple de la prison");
        gotoligcol(17,col);
        printf("Appuyer sur n'importe quelle touche pour continuer");
        gotoligcol(18,col);
        fflush(stdin);
        scanf("%d", &suite);
    }
    else if (propActuelle == 17)    //Si la case est le parc gratuit
    {
        gotoligcol(14,col);
        printf("Vous etes dans le parc gratuit");
        gotoligcol(15,col);
        printf("L'air est pure, la paysage vous apaise");
        gotoligcol(18,col);
        printf("Appuyer sur n'importe quelle touche pour continuer");
        gotoligcol(19,col);
        fflush(stdin);
        scanf("%d", &suite);
    }

    else if (propActuelle == 13 || propActuelle == 29)  //Si la case est une case Caisse de Communauté
    {
            int a = 0;
            a = 16 - rand()%(1 - 16);
            carteCaisseCom(joueurActuel, &a); //Sous programme des cartes chances
    }
    else if (propActuelle == 31)    //Si la case est la taxe de Luxe
    {
        (*joueurActuel).argent = (*joueurActuel).argent - 100;
        gotoligcol(16,col);
        printf("Vous perdez 100 dollars.");
        gotoligcol(17,col);
        printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
        gotoligcol(22,col);
        printf("Appuyer sur n'importe quelle touche pour continuer");
        gotoligcol(23,col);
        fflush(stdin);
        scanf("%d", &suite);
    }
    else if (propActuelle == 25)        //Si la case est aller en prison
    {
        menuPrison(joueurActuel, maxdouble, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
    }

}










void menuProp(int *NbHotels, int *NbMaisons, int propActuelle, struct joueur **joueurActuel, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8, struct proprietes **Gdynia, struct proprietes **Taipei, struct proprietes **Tokyo, struct proprietes **Barcelone, struct proprietes **Athenes, struct proprietes **Istanbul, struct proprietes **Kyiv, struct proprietes **Toronto, struct proprietes **Rome, struct proprietes **Shanghai, struct proprietes **Vancouver, struct proprietes **Sydney, struct proprietes **NewYork, struct proprietes **Londres, struct proprietes **Beijing, struct proprietes **HongKong, struct proprietes **Jerusalem, struct proprietes **Paris, struct proprietes **Belgrade, struct proprietes **LeCap, struct proprietes **Riga, struct proprietes **Montreal)
{   //Sous programme pour les cases qui sont des proprietes
    if (propActuelle == 2)
    {
        MenuAchat(NbHotels, NbMaisons, Gdynia, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 4)
    {
        MenuAchat(NbHotels, NbMaisons, Taipei, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 6)
    {
        MenuAchat(NbHotels, NbMaisons, Tokyo, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 7)
    {
        MenuAchat(NbHotels, NbMaisons, Barcelone, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 8)
    {
        MenuAchat(NbHotels, NbMaisons, Athenes, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 10)
    {
        MenuAchat(NbHotels, NbMaisons, Istanbul, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 11)
    {
        MenuAchat(NbHotels, NbMaisons, Kyiv, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 12)
    {
        MenuAchat(NbHotels, NbMaisons, Toronto, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 14)
    {
        MenuAchat(NbHotels, NbMaisons, Rome, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 15)
    {
        MenuAchat(NbHotels, NbMaisons, Shanghai, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 16)
    {
        MenuAchat(NbHotels, NbMaisons, Vancouver, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 18)
    {
        MenuAchat(NbHotels, NbMaisons, Sydney, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 19)
    {
        MenuAchat(NbHotels, NbMaisons, NewYork, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 20)
    {
        MenuAchat(NbHotels, NbMaisons, Londres, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 22)
    {
        MenuAchat(NbHotels, NbMaisons, Beijing, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 23)
    {
        MenuAchat(NbHotels, NbMaisons, HongKong, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 24)
    {
        MenuAchat(NbHotels, NbMaisons, Jerusalem, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 26)
    {
        MenuAchat(NbHotels, NbMaisons, Paris, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 27)
    {
        MenuAchat(NbHotels, NbMaisons, Belgrade, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 28)
    {
        MenuAchat(NbHotels, NbMaisons, LeCap, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 30)
    {
        MenuAchat(NbHotels, NbMaisons, Riga, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);    //Sous programme du menu d'achat de proprietes
    }
    else if (propActuelle == 32)
    {
        MenuAchat(NbHotels, NbMaisons, Montreal, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
    }
    else
    {
        cases(propActuelle, joueurActuel, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal); ///On appel le sous programme pour les autres case
    }   //Sous programme pour les cases qui ne sont pas des proprietes

}


