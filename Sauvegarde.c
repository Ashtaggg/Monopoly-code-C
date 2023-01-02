#include <stdio.h>
#include <stdlib.h>


#include "Structures.h"






int questionSauvegarde(int nbrJoueurs, struct joueur *joueur1, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8, struct proprietes *Gdynia, struct proprietes *Taipei, struct proprietes *Tokyo, struct proprietes *Barcelone, struct proprietes *Athenes, struct proprietes *Istanbul, struct proprietes *Kyiv, struct proprietes *Toronto, struct proprietes *Rome, struct proprietes *Shanghai, struct proprietes *Vancouver, struct proprietes *Sydney, struct proprietes *NewYork, struct proprietes *Londres, struct proprietes *Beijing, struct proprietes *HongKong, struct proprietes *Jerusalem, struct proprietes *Paris, struct proprietes *Belgrade, struct proprietes *LeCap, struct proprietes *Riga, struct proprietes *Montreal)
{
    int quitter = 0;
    int choix = 0;
    int col = 130;
    reset(3,9,col,col+50);
    gotoligcol(3,col);
    printf("Voulez vous :");    //En quittant on demande ce que le joueur veut faire
    gotoligcol(4,col);
    printf("1.\tQuitter et sauvegarder ?");
    gotoligcol(5,col);
    printf("2.\tQuitter sans sauvegarder ?");
    gotoligcol(6,col);
    fflush(stdin);
    scanf("%d", &choix);
    while(choix < 1 || choix > 2)   //On blinde la valeur
    {
        reset(6,6,col,col+10);
        gotoligcol(6,col);
        fflush(stdin);
        scanf("%d",&choix);
    }
    if (choix == 1)     //On appel le sous programme de sauvegarde
    {
        quitter = sauvegarder(nbrJoueurs, joueur1, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
        if (quitter == 1)
        {
            return 1;   //On quitte le sous programme
        }
    }
    else if (choix == 2)
    {
        return 1;       //On quitte le sous programme
    }
}













void ouvrirUneSauvegarde()  //Sous programme pour continuer une partie sauvegardé
{
    int quitter = 0;



    FILE* pf = NULL;    //On ouvre le fichier texte de la partie deja sauvegardé
    pf = fopen("./partieMonopoly.txt","r");
    if (pf == NULL)
    {
        printf("\nErreur d'ouverture de fichier\n");
        return 1;
    }




    struct joueur joueur1;  //On crée les structures joueurs
    struct joueur joueur2;
    struct joueur joueur3;
    struct joueur joueur4;
    struct joueur joueur5;
    struct joueur joueur6;
    struct joueur joueur7;
    struct joueur joueur8;


    int nbrJoueurs = 0;


    fscanf(pf, "%d", &nbrJoueurs);  //On recupère les éléments placés dans le fichier texte



    int pion1 = 0;
    int pion2 = 0;
    int pion3 = 0;
    int pion4 = 0;
    int pion5 = 0;
    int pion6 = 0;
    int pion7 = 0;
    int pion8 = 0;



    if (nbrJoueurs >= 1)    //Pour chaque joueur présent on recupère les éléments placés dans le fichier texte pour remplir chaque structures joueurs
    {
        fscanf(pf, "%s\n", &((joueur1).prenom));
        fscanf(pf, "%d\n", &((joueur1).argent));
        fscanf(pf, "%d\n", &((joueur1).nbrProprietes));
        fscanf(pf, "%d\n", &((joueur1).cartePrison));
        fscanf(pf, "%d\n", &((joueur1).OrdreDePassage));
        fscanf(pf, "%d\n", &((joueur1).caseActuelle));
        fscanf(pf, "%d\n", &((joueur1).enJeu));
        fscanf(pf, "%d\n", &pion1);
        if (pion1 == 1)
        {
            (joueur1).pion = 0x01;
        }
        else if (pion1 == 2)
        {
            (joueur1).pion = 0x02;
        }
        else if (pion1 == 3)
        {
            (joueur1).pion = 0x03;
        }
        else if (pion1 == 4)
        {
            (joueur1).pion = 0x04;
        }
        else if (pion1 == 5)
        {
            (joueur1).pion = 0x05;
        }
        else if (pion1 == 6)
        {
            (joueur1).pion = 0x06;
        }
        else if (pion1 == 7)
        {
            (joueur1).pion = 0x0B;
        }
        else if (pion1 == 8)
        {
            (joueur1).pion = 0x0C;
        }
        else if (pion1 == 9)
        {
            (joueur1).pion = 0x0F;
        }
    }
    if (nbrJoueurs >= 2)    //Pour chaque joueur présent on recupère les éléments placés dans le fichier texte pour remplir chaque structures joueurs
    {
        fscanf(pf, "%s\n", &((joueur2).prenom));
        fscanf(pf, "%d\n", &((joueur2).argent));
        fscanf(pf, "%d\n", &((joueur2).nbrProprietes));
        fscanf(pf, "%d\n", &((joueur2).cartePrison));
        fscanf(pf, "%d\n", &((joueur2).OrdreDePassage));
        fscanf(pf, "%d\n", &((joueur2).caseActuelle));
        fscanf(pf, "%d\n", &((joueur2).enJeu));
        fscanf(pf, "%d\n", &pion2);
        if (pion2 == 1)
        {
            (joueur2).pion = 0x01;
        }
        else if (pion2 == 2)
        {
            (joueur2).pion = 0x02;
        }
        else if (pion2 == 3)
        {
            (joueur2).pion = 0x03;
        }
        else if (pion2 == 4)
        {
            (joueur2).pion = 0x04;
        }
        else if (pion2 == 5)
        {
            (joueur2).pion = 0x05;
        }
        else if (pion2 == 6)
        {
            (joueur2).pion = 0x06;
        }
        else if (pion2 == 7)
        {
            (joueur2).pion = 0x0B;
        }
        else if (pion2 == 8)
        {
            (joueur2).pion = 0x0C;
        }
        else if (pion2 == 9)
        {
            (joueur2).pion = 0x0F;
        }
        fscanf(pf, "%d\n\n", &((joueur2).nbrTours));
    }
    if (nbrJoueurs >= 3)    //Pour chaque joueur présent on recupère les éléments placés dans le fichier texte pour remplir chaque structures joueurs
    {
        fscanf(pf, "%s\n", &((joueur3).prenom));
        fscanf(pf, "%d\n", &((joueur3).argent));
        fscanf(pf, "%d\n", &((joueur3).nbrProprietes));
        fscanf(pf, "%d\n", &((joueur3).cartePrison));
        fscanf(pf, "%d\n", &((joueur3).OrdreDePassage));
        fscanf(pf, "%d\n", &((joueur3).caseActuelle));
        fscanf(pf, "%d\n", &((joueur3).enJeu));
        fscanf(pf, "%d\n", &pion3);
        if (pion3 == 1)
        {
            (joueur3).pion = 0x01;
        }
        else if (pion3 == 2)
        {
            (joueur3).pion = 0x02;
        }
        else if (pion3 == 3)
        {
            (joueur3).pion = 0x03;
        }
        else if (pion3 == 4)
        {
            (joueur3).pion = 0x04;
        }
        else if (pion3 == 5)
        {
            (joueur3).pion = 0x05;
        }
        else if (pion3 == 6)
        {
            (joueur3).pion = 0x06;
        }
        else if (pion3 == 7)
        {
            (joueur3).pion = 0x0B;
        }
        else if (pion3 == 8)
        {
            (joueur3).pion = 0x0C;
        }
        else if (pion3 == 9)
        {
            (joueur3).pion = 0x0F;
        }
        fscanf(pf, "%d\n\n", &((joueur3).nbrTours));
    }
    if (nbrJoueurs >= 4)    //Pour chaque joueur présent on recupère les éléments placés dans le fichier texte pour remplir chaque structures joueurs
    {
        fscanf(pf, "%s\n", &((joueur4).prenom));
        fscanf(pf, "%d\n", &((joueur4).argent));
        fscanf(pf, "%d\n", &((joueur4).nbrProprietes));
        fscanf(pf, "%d\n", &((joueur4).cartePrison));
        fscanf(pf, "%d\n", &((joueur4).OrdreDePassage));
        fscanf(pf, "%d\n", &((joueur4).caseActuelle));
        fscanf(pf, "%d\n", &((joueur4).enJeu));
        fscanf(pf, "%d\n", &pion4);
        if (pion4 == 1)
        {
            (joueur4).pion = 0x01;
        }
        else if (pion4 == 2)
        {
            (joueur4).pion = 0x02;
        }
        else if (pion4 == 3)
        {
            (joueur4).pion = 0x03;
        }
        else if (pion4 == 4)
        {
            (joueur4).pion = 0x04;
        }
        else if (pion4 == 5)
        {
            (joueur4).pion = 0x05;
        }
        else if (pion4 == 6)
        {
            (joueur4).pion = 0x06;
        }
        else if (pion4 == 7)
        {
            (joueur4).pion = 0x0B;
        }
        else if (pion4 == 8)
        {
            (joueur4).pion = 0x0C;
        }
        else if (pion4 == 9)
        {
            (joueur4).pion = 0x0F;
        }
        fscanf(pf, "%d\n\n", &((joueur4).nbrTours));
    }
    if (nbrJoueurs >= 5)    //Pour chaque joueur présent on recupère les éléments placés dans le fichier texte pour remplir chaque structures joueurs
    {
        fscanf(pf, "%s\n", &((joueur5).prenom));
        fscanf(pf, "%d\n", &((joueur5).argent));
        fscanf(pf, "%d\n", &((joueur5).nbrProprietes));
        fscanf(pf, "%d\n", &((joueur5).cartePrison));
        fscanf(pf, "%d\n", &((joueur5).OrdreDePassage));
        fscanf(pf, "%d\n", &((joueur5).caseActuelle));
        fscanf(pf, "%d\n", &((joueur5).enJeu));
        fscanf(pf, "%d\n", &pion5);
        if (pion5 == 1)
        {
            (joueur5).pion = 0x01;
        }
        else if (pion5 == 2)
        {
            (joueur5).pion = 0x02;
        }
        else if (pion5 == 3)
        {
            (joueur5).pion = 0x03;
        }
        else if (pion5 == 4)
        {
            (joueur5).pion = 0x04;
        }
        else if (pion5 == 5)
        {
            (joueur5).pion = 0x05;
        }
        else if (pion5 == 6)
        {
            (joueur5).pion = 0x06;
        }
        else if (pion5 == 7)
        {
            (joueur5).pion = 0x0B;
        }
        else if (pion5 == 8)
        {
            (joueur5).pion = 0x0C;
        }
        else if (pion5 == 9)
        {
            (joueur5).pion = 0x0F;
        }
        fscanf(pf, "%d\n\n", &((joueur5).nbrTours));
    }
    if (nbrJoueurs >= 6)    //Pour chaque joueur présent on recupère les éléments placés dans le fichier texte pour remplir chaque structures joueurs
    {
        fscanf(pf, "%s\n", &((joueur6).prenom));
        fscanf(pf, "%d\n", &((joueur6).argent));
        fscanf(pf, "%d\n", &((joueur6).nbrProprietes));
        fscanf(pf, "%d\n", &((joueur6).cartePrison));
        fscanf(pf, "%d\n", &((joueur6).OrdreDePassage));
        fscanf(pf, "%d\n", &((joueur6).caseActuelle));
        fscanf(pf, "%d\n", &((joueur6).enJeu));
        fscanf(pf, "%d\n", &pion6);
        if (pion6 == 1)
        {
            (joueur6).pion = 0x01;
        }
        else if (pion6 == 2)
        {
            (joueur6).pion = 0x02;
        }
        else if (pion6 == 3)
        {
            (joueur6).pion = 0x03;
        }
        else if (pion6 == 4)
        {
            (joueur6).pion = 0x04;
        }
        else if (pion6 == 5)
        {
            (joueur6).pion = 0x05;
        }
        else if (pion6 == 6)
        {
            (joueur6).pion = 0x06;
        }
        else if (pion6 == 7)
        {
            (joueur6).pion = 0x0B;
        }
        else if (pion6 == 8)
        {
            (joueur6).pion = 0x0C;
        }
        else if (pion6 == 9)
        {
            (joueur6).pion = 0x0F;
        }
        fscanf(pf, "%d\n\n", &((joueur6).nbrTours));
    }
    if (nbrJoueurs >= 7)    //Pour chaque joueur présent on recupère les éléments placés dans le fichier texte pour remplir chaque structures joueurs
    {
        fscanf(pf, "%s\n", &((joueur7).prenom));
        fscanf(pf, "%d\n", &((joueur7).argent));
        fscanf(pf, "%d\n", &((joueur7).nbrProprietes));
        fscanf(pf, "%d\n", &((joueur7).cartePrison));
        fscanf(pf, "%d\n", &((joueur7).OrdreDePassage));
        fscanf(pf, "%d\n", &((joueur7).caseActuelle));
        fscanf(pf, "%d\n", &((joueur7).enJeu));
        fscanf(pf, "%d\n", &pion7);
        if (pion7 == 1)
        {
            (joueur7).pion = 0x01;
        }
        else if (pion7 == 2)
        {
            (joueur7).pion = 0x02;
        }
        else if (pion7 == 3)
        {
            (joueur7).pion = 0x03;
        }
        else if (pion7 == 4)
        {
            (joueur7).pion = 0x04;
        }
        else if (pion7 == 5)
        {
            (joueur7).pion = 0x05;
        }
        else if (pion7 == 6)
        {
            (joueur7).pion = 0x06;
        }
        else if (pion7 == 7)
        {
            (joueur7).pion = 0x0B;
        }
        else if (pion7 == 8)
        {
            (joueur7).pion = 0x0C;
        }
        else if (pion7 == 9)
        {
            (joueur7).pion = 0x0F;
        }
        fscanf(pf, "%d\n\n", &((joueur7).nbrTours));
    }
    if (nbrJoueurs == 8)    //Pour chaque joueur présent on recupère les éléments placés dans le fichier texte pour remplir chaque structures joueurs
    {
        fscanf(pf, "%s\n", &((joueur8).prenom));
        fscanf(pf, "%d\n", &((joueur8).argent));
        fscanf(pf, "%d\n", &((joueur8).nbrProprietes));
        fscanf(pf, "%d\n", &((joueur8).cartePrison));
        fscanf(pf, "%d\n", &((joueur8).OrdreDePassage));
        fscanf(pf, "%d\n", &((joueur8).caseActuelle));
        fscanf(pf, "%d\n", &((joueur8).enJeu));
        fscanf(pf, "%d\n", &pion8);
        if (pion8 == 1)
        {
            (joueur8).pion = 0x01;
        }
        else if (pion8 == 2)
        {
            (joueur8).pion = 0x02;
        }
        else if (pion8 == 3)
        {
            (joueur8).pion = 0x03;
        }
        else if (pion8 == 4)
        {
            (joueur8).pion = 0x04;
        }
        else if (pion8 == 5)
        {
            (joueur8).pion = 0x05;
        }
        else if (pion8 == 6)
        {
            (joueur8).pion = 0x06;
        }
        else if (pion8 == 7)
        {
            (joueur8).pion = 0x0B;
        }
        else if (pion8 == 8)
        {
            (joueur8).pion = 0x0C;
        }
        else if (pion8 == 9)
        {
            (joueur8).pion = 0x0F;
        }
        fscanf(pf, "%d\n\n", &((joueur8).nbrTours));
    }








    struct proprietes Gdynia;   //On crée les structures proprietes
    struct proprietes Taipei;
    struct proprietes Tokyo;
    struct proprietes Barcelone;
    struct proprietes Athenes;
    struct proprietes Istanbul;
    struct proprietes Kyiv;
    struct proprietes Toronto;
    struct proprietes Rome;
    struct proprietes Shanghai;
    struct proprietes Vancouver;
    struct proprietes Sydney;
    struct proprietes NewYork;
    struct proprietes Londres;
    struct proprietes Beijing;
    struct proprietes HongKong;
    struct proprietes Jerusalem;
    struct proprietes Paris;
    struct proprietes Belgrade;
    struct proprietes LeCap;
    struct proprietes Riga;
    struct proprietes Montreal;





    fscanf(pf, "%s\n", &((Gdynia).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Gdynia).numPlateau));
    fscanf(pf, "%d\n", &((Gdynia).prix));
    fscanf(pf, "%d\n", &((Gdynia).loyer0));
    fscanf(pf, "%d\n", &((Gdynia).loyer1));
    fscanf(pf, "%d\n", &((Gdynia).loyer2));
    fscanf(pf, "%d\n", &((Gdynia).loyer3));
    fscanf(pf, "%d\n", &((Gdynia).loyer4));
    fscanf(pf, "%d\n", &((Gdynia).loyer5));
    fscanf(pf, "%d\n", &((Gdynia).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Gdynia).prix_maison));
    fscanf(pf, "%s\n", &((Gdynia).proprietaire));
    fscanf(pf, "%s\n", &((Gdynia).famille));
    fscanf(pf, "%d\n", &((Gdynia).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Gdynia).valHypotheque));


    fscanf(pf, "%s\n", &((Taipei).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Taipei).numPlateau));
    fscanf(pf, "%d\n", &((Taipei).prix));
    fscanf(pf, "%d\n", &((Taipei).loyer0));
    fscanf(pf, "%d\n", &((Taipei).loyer1));
    fscanf(pf, "%d\n", &((Taipei).loyer2));
    fscanf(pf, "%d\n", &((Taipei).loyer3));
    fscanf(pf, "%d\n", &((Taipei).loyer4));
    fscanf(pf, "%d\n", &((Taipei).loyer5));
    fscanf(pf, "%d\n", &((Taipei).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Taipei).prix_maison));
    fscanf(pf, "%s\n", &((Taipei).proprietaire));
    fscanf(pf, "%s\n", &((Taipei).famille));
    fscanf(pf, "%d\n", &((Taipei).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Taipei).valHypotheque));


    fscanf(pf, "%s\n", &((Tokyo).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Tokyo).numPlateau));
    fscanf(pf, "%d\n", &((Tokyo).prix));
    fscanf(pf, "%d\n", &((Tokyo).loyer0));
    fscanf(pf, "%d\n", &((Tokyo).loyer1));
    fscanf(pf, "%d\n", &((Tokyo).loyer2));
    fscanf(pf, "%d\n", &((Tokyo).loyer3));
    fscanf(pf, "%d\n", &((Tokyo).loyer4));
    fscanf(pf, "%d\n", &((Tokyo).loyer5));
    fscanf(pf, "%d\n", &((Tokyo).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Tokyo).prix_maison));
    fscanf(pf, "%s\n", &((Tokyo).proprietaire));
    fscanf(pf, "%s\n", &((Tokyo).famille));
    fscanf(pf, "%d\n", &((Tokyo).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Tokyo).valHypotheque));



    fscanf(pf, "%s\n", &((Barcelone).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Barcelone).numPlateau));
    fscanf(pf, "%d\n", &((Barcelone).prix));
    fscanf(pf, "%d\n", &((Barcelone).loyer0));
    fscanf(pf, "%d\n", &((Barcelone).loyer1));
    fscanf(pf, "%d\n", &((Barcelone).loyer2));
    fscanf(pf, "%d\n", &((Barcelone).loyer3));
    fscanf(pf, "%d\n", &((Barcelone).loyer4));
    fscanf(pf, "%d\n", &((Barcelone).loyer5));
    fscanf(pf, "%d\n", &((Barcelone).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Barcelone).prix_maison));
    fscanf(pf, "%s\n", &((Barcelone).proprietaire));
    fscanf(pf, "%s\n", &((Barcelone).famille));
    fscanf(pf, "%d\n", &((Barcelone).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Barcelone).valHypotheque));


    fscanf(pf, "%s\n", &((Athenes).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Athenes).numPlateau));
    fscanf(pf, "%d\n", &((Athenes).prix));
    fscanf(pf, "%d\n", &((Athenes).loyer0));
    fscanf(pf, "%d\n", &((Athenes).loyer1));
    fscanf(pf, "%d\n", &((Athenes).loyer2));
    fscanf(pf, "%d\n", &((Athenes).loyer3));
    fscanf(pf, "%d\n", &((Athenes).loyer4));
    fscanf(pf, "%d\n", &((Athenes).loyer5));
    fscanf(pf, "%d\n", &((Athenes).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Athenes).prix_maison));
    fscanf(pf, "%s\n", &((Athenes).proprietaire));
    fscanf(pf, "%s\n", &((Athenes).famille));
    fscanf(pf, "%d\n", &((Athenes).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Athenes).valHypotheque));


    fscanf(pf, "%s\n", &((Istanbul).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Istanbul).numPlateau));
    fscanf(pf, "%d\n", &((Istanbul).prix));
    fscanf(pf, "%d\n", &((Istanbul).loyer0));
    fscanf(pf, "%d\n", &((Istanbul).loyer1));
    fscanf(pf, "%d\n", &((Istanbul).loyer2));
    fscanf(pf, "%d\n", &((Istanbul).loyer3));
    fscanf(pf, "%d\n", &((Istanbul).loyer4));
    fscanf(pf, "%d\n", &((Istanbul).loyer5));
    fscanf(pf, "%d\n", &((Istanbul).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Istanbul).prix_maison));
    fscanf(pf, "%s\n", &((Istanbul).proprietaire));
    fscanf(pf, "%s\n", &((Istanbul).famille));
    fscanf(pf, "%d\n", &((Istanbul).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Istanbul).valHypotheque));


    fscanf(pf, "%s\n", &((Kyiv).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Kyiv).numPlateau));
    fscanf(pf, "%d\n", &((Kyiv).prix));
    fscanf(pf, "%d\n", &((Kyiv).loyer0));
    fscanf(pf, "%d\n", &((Kyiv).loyer1));
    fscanf(pf, "%d\n", &((Kyiv).loyer2));
    fscanf(pf, "%d\n", &((Kyiv).loyer3));
    fscanf(pf, "%d\n", &((Kyiv).loyer4));
    fscanf(pf, "%d\n", &((Kyiv).loyer5));
    fscanf(pf, "%d\n", &((Kyiv).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Kyiv).prix_maison));
    fscanf(pf, "%s\n", &((Kyiv).proprietaire));
    fscanf(pf, "%s\n", &((Kyiv).famille));
    fscanf(pf, "%d\n", &((Kyiv).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Kyiv).valHypotheque));



    fscanf(pf, "%s\n", &((Toronto).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Toronto).numPlateau));
    fscanf(pf, "%d\n", &((Toronto).prix));
    fscanf(pf, "%d\n", &((Toronto).loyer0));
    fscanf(pf, "%d\n", &((Toronto).loyer1));
    fscanf(pf, "%d\n", &((Toronto).loyer2));
    fscanf(pf, "%d\n", &((Toronto).loyer3));
    fscanf(pf, "%d\n", &((Toronto).loyer4));
    fscanf(pf, "%d\n", &((Toronto).loyer5));
    fscanf(pf, "%d\n", &((Toronto).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Toronto).prix_maison));
    fscanf(pf, "%s\n", &((Toronto).proprietaire));
    fscanf(pf, "%s\n", &((Toronto).famille));
    fscanf(pf, "%d\n", &((Toronto).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Toronto).valHypotheque));



    fscanf(pf, "%s\n", &((Rome).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Rome).numPlateau));
    fscanf(pf, "%d\n", &((Rome).prix));
    fscanf(pf, "%d\n", &((Rome).loyer0));
    fscanf(pf, "%d\n", &((Rome).loyer1));
    fscanf(pf, "%d\n", &((Rome).loyer2));
    fscanf(pf, "%d\n", &((Rome).loyer3));
    fscanf(pf, "%d\n", &((Rome).loyer4));
    fscanf(pf, "%d\n", &((Rome).loyer5));
    fscanf(pf, "%d\n", &((Rome).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Rome).prix_maison));
    fscanf(pf, "%s\n", &((Rome).proprietaire));
    fscanf(pf, "%s\n", &((Rome).famille));
    fscanf(pf, "%d\n", &((Rome).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Rome).valHypotheque));




    fscanf(pf, "%s\n", &((Shanghai).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Shanghai).numPlateau));
    fscanf(pf, "%d\n", &((Shanghai).prix));
    fscanf(pf, "%d\n", &((Shanghai).loyer0));
    fscanf(pf, "%d\n", &((Shanghai).loyer1));
    fscanf(pf, "%d\n", &((Shanghai).loyer2));
    fscanf(pf, "%d\n", &((Shanghai).loyer3));
    fscanf(pf, "%d\n", &((Shanghai).loyer4));
    fscanf(pf, "%d\n", &((Shanghai).loyer5));
    fscanf(pf, "%d\n", &((Shanghai).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Shanghai).prix_maison));
    fscanf(pf, "%s\n", &((Shanghai).proprietaire));
    fscanf(pf, "%s\n", &((Shanghai).famille));
    fscanf(pf, "%d\n", &((Shanghai).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Shanghai).valHypotheque));




    fscanf(pf, "%s\n", &((Vancouver).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Vancouver).numPlateau));
    fscanf(pf, "%d\n", &((Vancouver).prix));
    fscanf(pf, "%d\n", &((Vancouver).loyer0));
    fscanf(pf, "%d\n", &((Vancouver).loyer1));
    fscanf(pf, "%d\n", &((Vancouver).loyer2));
    fscanf(pf, "%d\n", &((Vancouver).loyer3));
    fscanf(pf, "%d\n", &((Vancouver).loyer4));
    fscanf(pf, "%d\n", &((Vancouver).loyer5));
    fscanf(pf, "%d\n", &((Vancouver).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Vancouver).prix_maison));
    fscanf(pf, "%s\n", &((Vancouver).proprietaire));
    fscanf(pf, "%s\n", &((Vancouver).famille));
    fscanf(pf, "%d\n", &((Vancouver).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Vancouver).valHypotheque));






    fscanf(pf, "%s\n", &((Sydney).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Sydney).numPlateau));
    fscanf(pf, "%d\n", &((Sydney).prix));
    fscanf(pf, "%d\n", &((Sydney).loyer0));
    fscanf(pf, "%d\n", &((Sydney).loyer1));
    fscanf(pf, "%d\n", &((Sydney).loyer2));
    fscanf(pf, "%d\n", &((Sydney).loyer3));
    fscanf(pf, "%d\n", &((Sydney).loyer4));
    fscanf(pf, "%d\n", &((Sydney).loyer5));
    fscanf(pf, "%d\n", &((Sydney).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Sydney).prix_maison));
    fscanf(pf, "%s\n", &((Sydney).proprietaire));
    fscanf(pf, "%s\n", &((Sydney).famille));
    fscanf(pf, "%d\n", &((Sydney).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Sydney).valHypotheque));



    fscanf(pf, "%s\n", &((NewYork).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((NewYork).numPlateau));
    fscanf(pf, "%d\n", &((NewYork).prix));
    fscanf(pf, "%d\n", &((NewYork).loyer0));
    fscanf(pf, "%d\n", &((NewYork).loyer1));
    fscanf(pf, "%d\n", &((NewYork).loyer2));
    fscanf(pf, "%d\n", &((NewYork).loyer3));
    fscanf(pf, "%d\n", &((NewYork).loyer4));
    fscanf(pf, "%d\n", &((NewYork).loyer5));
    fscanf(pf, "%d\n", &((NewYork).valeur_hypotheque));
    fscanf(pf, "%d\n", &((NewYork).prix_maison));
    fscanf(pf, "%s\n", &((NewYork).proprietaire));
    fscanf(pf, "%s\n", &((NewYork).famille));
    fscanf(pf, "%d\n", &((NewYork).nbrMaisons));
    fscanf(pf, "%d\n\n", &((NewYork).valHypotheque));




    fscanf(pf, "%s\n", &((Londres).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Londres).numPlateau));
    fscanf(pf, "%d\n", &((Londres).prix));
    fscanf(pf, "%d\n", &((Londres).loyer0));
    fscanf(pf, "%d\n", &((Londres).loyer1));
    fscanf(pf, "%d\n", &((Londres).loyer2));
    fscanf(pf, "%d\n", &((Londres).loyer3));
    fscanf(pf, "%d\n", &((Londres).loyer4));
    fscanf(pf, "%d\n", &((Londres).loyer5));
    fscanf(pf, "%d\n", &((Londres).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Londres).prix_maison));
    fscanf(pf, "%s\n", &((Londres).proprietaire));
    fscanf(pf, "%s\n", &((Londres).famille));
    fscanf(pf, "%d\n", &((Londres).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Londres).valHypotheque));




    fscanf(pf, "%s\n", &((Beijing).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Beijing).numPlateau));
    fscanf(pf, "%d\n", &((Beijing).prix));
    fscanf(pf, "%d\n", &((Beijing).loyer0));
    fscanf(pf, "%d\n", &((Beijing).loyer1));
    fscanf(pf, "%d\n", &((Beijing).loyer2));
    fscanf(pf, "%d\n", &((Beijing).loyer3));
    fscanf(pf, "%d\n", &((Beijing).loyer4));
    fscanf(pf, "%d\n", &((Beijing).loyer5));
    fscanf(pf, "%d\n", &((Beijing).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Beijing).prix_maison));
    fscanf(pf, "%s\n", &((Beijing).proprietaire));
    fscanf(pf, "%s\n", &((Beijing).famille));
    fscanf(pf, "%d\n", &((Beijing).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Beijing).valHypotheque));


    fscanf(pf, "%s\n", &((HongKong).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((HongKong).numPlateau));
    fscanf(pf, "%d\n", &((HongKong).prix));
    fscanf(pf, "%d\n", &((HongKong).loyer0));
    fscanf(pf, "%d\n", &((HongKong).loyer1));
    fscanf(pf, "%d\n", &((HongKong).loyer2));
    fscanf(pf, "%d\n", &((HongKong).loyer3));
    fscanf(pf, "%d\n", &((HongKong).loyer4));
    fscanf(pf, "%d\n", &((HongKong).loyer5));
    fscanf(pf, "%d\n", &((HongKong).valeur_hypotheque));
    fscanf(pf, "%d\n", &((HongKong).prix_maison));
    fscanf(pf, "%s\n", &((HongKong).proprietaire));
    fscanf(pf, "%s\n", &((HongKong).famille));
    fscanf(pf, "%d\n", &((HongKong).nbrMaisons));
    fscanf(pf, "%d\n\n", &((HongKong).valHypotheque));


    fscanf(pf, "%s\n", &((Jerusalem).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Jerusalem).numPlateau));
    fscanf(pf, "%d\n", &((Jerusalem).prix));
    fscanf(pf, "%d\n", &((Jerusalem).loyer0));
    fscanf(pf, "%d\n", &((Jerusalem).loyer1));
    fscanf(pf, "%d\n", &((Jerusalem).loyer2));
    fscanf(pf, "%d\n", &((Jerusalem).loyer3));
    fscanf(pf, "%d\n", &((Jerusalem).loyer4));
    fscanf(pf, "%d\n", &((Jerusalem).loyer5));
    fscanf(pf, "%d\n", &((Jerusalem).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Jerusalem).prix_maison));
    fscanf(pf, "%s\n", &((Jerusalem).proprietaire));
    fscanf(pf, "%s\n", &((Jerusalem).famille));
    fscanf(pf, "%d\n", &((Jerusalem).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Jerusalem).valHypotheque));




    fscanf(pf, "%s\n", &((Paris).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Paris).numPlateau));
    fscanf(pf, "%d\n", &((Paris).prix));
    fscanf(pf, "%d\n", &((Paris).loyer0));
    fscanf(pf, "%d\n", &((Paris).loyer1));
    fscanf(pf, "%d\n", &((Paris).loyer2));
    fscanf(pf, "%d\n", &((Paris).loyer3));
    fscanf(pf, "%d\n", &((Paris).loyer4));
    fscanf(pf, "%d\n", &((Paris).loyer5));
    fscanf(pf, "%d\n", &((Paris).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Paris).prix_maison));
    fscanf(pf, "%s\n", &((Paris).proprietaire));
    fscanf(pf, "%s\n", &((Paris).famille));
    fscanf(pf, "%d\n", &((Paris).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Paris).valHypotheque));



    fscanf(pf, "%s\n", &((Belgrade).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Belgrade).numPlateau));
    fscanf(pf, "%d\n", &((Belgrade).prix));
    fscanf(pf, "%d\n", &((Belgrade).loyer0));
    fscanf(pf, "%d\n", &((Belgrade).loyer1));
    fscanf(pf, "%d\n", &((Belgrade).loyer2));
    fscanf(pf, "%d\n", &((Belgrade).loyer3));
    fscanf(pf, "%d\n", &((Belgrade).loyer4));
    fscanf(pf, "%d\n", &((Belgrade).loyer5));
    fscanf(pf, "%d\n", &((Belgrade).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Belgrade).prix_maison));
    fscanf(pf, "%s\n", &((Belgrade).proprietaire));
    fscanf(pf, "%s\n", &((Belgrade).famille));
    fscanf(pf, "%d\n", &((Belgrade).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Belgrade).valHypotheque));



    fscanf(pf, "%s\n", &((LeCap).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((LeCap).numPlateau));
    fscanf(pf, "%d\n", &((LeCap).prix));
    fscanf(pf, "%d\n", &((LeCap).loyer0));
    fscanf(pf, "%d\n", &((LeCap).loyer1));
    fscanf(pf, "%d\n", &((LeCap).loyer2));
    fscanf(pf, "%d\n", &((LeCap).loyer3));
    fscanf(pf, "%d\n", &((LeCap).loyer4));
    fscanf(pf, "%d\n", &((LeCap).loyer5));
    fscanf(pf, "%d\n", &((LeCap).valeur_hypotheque));
    fscanf(pf, "%d\n", &((LeCap).prix_maison));
    fscanf(pf, "%s\n", &((LeCap).proprietaire));
    fscanf(pf, "%s\n", &((LeCap).famille));
    fscanf(pf, "%d\n", &((LeCap).nbrMaisons));
    fscanf(pf, "%d\n\n", &((LeCap).valHypotheque));


    fscanf(pf, "%s\n", &((Riga).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Riga).numPlateau));
    fscanf(pf, "%d\n", &((Riga).prix));
    fscanf(pf, "%d\n", &((Riga).loyer0));
    fscanf(pf, "%d\n", &((Riga).loyer1));
    fscanf(pf, "%d\n", &((Riga).loyer2));
    fscanf(pf, "%d\n", &((Riga).loyer3));
    fscanf(pf, "%d\n", &((Riga).loyer4));
    fscanf(pf, "%d\n", &((Riga).loyer5));
    fscanf(pf, "%d\n", &((Riga).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Riga).prix_maison));
    fscanf(pf, "%s\n", &((Riga).proprietaire));
    fscanf(pf, "%s\n", &((Riga).famille));
    fscanf(pf, "%d\n", &((Riga).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Riga).valHypotheque));


    fscanf(pf, "%s\n", &((Montreal).nom));    //On recupère les éléments placés dans le fichier texte pour remplir chaque structures proprietes
    fscanf(pf, "%d\n", &((Montreal).numPlateau));
    fscanf(pf, "%d\n", &((Montreal).prix));
    fscanf(pf, "%d\n", &((Montreal).loyer0));
    fscanf(pf, "%d\n", &((Montreal).loyer1));
    fscanf(pf, "%d\n", &((Montreal).loyer2));
    fscanf(pf, "%d\n", &((Montreal).loyer3));
    fscanf(pf, "%d\n", &((Montreal).loyer4));
    fscanf(pf, "%d\n", &((Montreal).loyer5));
    fscanf(pf, "%d\n", &((Montreal).valeur_hypotheque));
    fscanf(pf, "%d\n", &((Montreal).prix_maison));
    fscanf(pf, "%s\n", &((Montreal).proprietaire));
    fscanf(pf, "%s\n", &((Montreal).famille));
    fscanf(pf, "%d\n", &((Montreal).nbrMaisons));
    fscanf(pf, "%d\n\n", &((Montreal).valHypotheque));





    fclose(pf); //On referme le fichier texte, vu que l'on en a plus besoin
    pf = NULL;






    reset(0,100,0,210);     //On reset l'écran
    int tour = 1;
    int NbHotels = 0;
    int NbMaisons = 0;




    plateau();      //On affiche le plateau de jeu





        for(int i=1;i<nbrJoueurs+1;i++)     //On appelle le sous programme du menu de jeu en fonction de l'ordre de passage de chaque joueur
        {
            if (joueur1.OrdreDePassage == i)
            {
                quitter = MenuJoueur(NbHotels, NbMaisons ,tour, nbrJoueurs, &joueur1, &joueur1, &joueur2, &joueur3, &joueur4, &joueur5, &joueur6, &joueur7, &joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur2.OrdreDePassage == i)
            {
                quitter = MenuJoueur(NbHotels, NbMaisons, tour, nbrJoueurs, &joueur2, &joueur1,&joueur2, &joueur3, &joueur4, &joueur5, &joueur6, &joueur7, &joueur8,&Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur3.OrdreDePassage == i)
            {
                quitter = MenuJoueur(NbHotels, NbMaisons, tour, nbrJoueurs, &joueur3, &joueur1, &joueur2, &joueur3,&joueur4, &joueur5, &joueur6, &joueur7, &joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur4.OrdreDePassage == i)
            {
                quitter = MenuJoueur(NbHotels, NbMaisons, tour, nbrJoueurs, &joueur4, &joueur1, &joueur2, &joueur3, &joueur4,&joueur5, &joueur6, &joueur7, &joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur5.OrdreDePassage == i)
            {
                quitter = MenuJoueur(NbHotels, NbMaisons, tour, nbrJoueurs, &joueur5, &joueur1, &joueur2, &joueur3, &joueur4, &joueur5,&joueur6, &joueur7, &joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur6.OrdreDePassage == i)
            {
                quitter = MenuJoueur(NbHotels, NbMaisons, tour, nbrJoueurs, &joueur6, &joueur1, &joueur2, &joueur3, &joueur4, &joueur5, &joueur6,&joueur7, &joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur7.OrdreDePassage == i)
            {
                quitter = MenuJoueur(NbHotels, NbMaisons, tour, nbrJoueurs, &joueur7, &joueur1, &joueur2, &joueur3, &joueur4, &joueur5, &joueur6, &joueur7,&joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur8.OrdreDePassage == i)
            {
                quitter = MenuJoueur(NbHotels, NbMaisons, tour, nbrJoueurs, &joueur8, &joueur1, &joueur2, &joueur3, &joueur4, &joueur5, &joueur6, &joueur7,&joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            tour = tour + 1;
        }


}























int sauvegarder(int nbrJoueurs, struct joueur *joueur1, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8, struct proprietes *Gdynia, struct proprietes *Taipei, struct proprietes *Tokyo, struct proprietes *Barcelone, struct proprietes *Athenes, struct proprietes *Istanbul, struct proprietes *Kyiv, struct proprietes *Toronto, struct proprietes *Rome, struct proprietes *Shanghai, struct proprietes *Vancouver, struct proprietes *Sydney, struct proprietes *NewYork, struct proprietes *Londres, struct proprietes *Beijing, struct proprietes *HongKong, struct proprietes *Jerusalem, struct proprietes *Paris, struct proprietes *Belgrade, struct proprietes *LeCap, struct proprietes *Riga, struct proprietes *Montreal)
{
    printf("Sauvegarde de votre fichier ...");  //Sous programme de sauvegarde d'une partie



    FILE* pf = fopen ("./partieMonopoly.txt","w");  //On ouvre le fichier texte
    if (pf == NULL)
    {
        printf("\nErreur d'ouverture de fichier\n");
        return 1;
    }



    fprintf(pf, "%d\n\n", nbrJoueurs);  //On ecrit dans le fichier texte le nombre de joueur






    if (nbrJoueurs >= 1)      //On ecrit dans le fichier texte tout le contenu des structures joueur en fonction du nombre de joueur en jeu
    {
        fprintf(pf, "%s\n", (*joueur1).prenom);
        fprintf(pf, "%d\n", (*joueur1).argent);
        fprintf(pf, "%d\n", (*joueur1).nbrProprietes);
        fprintf(pf, "%d\n", (*joueur1).cartePrison);
        fprintf(pf, "%d\n", (*joueur1).OrdreDePassage);
        fprintf(pf, "%d\n", (*joueur1).caseActuelle);
        fprintf(pf, "%d\n", (*joueur1).enJeu);
        if ((*joueur1).pion == 0x01)
        {
            fprintf(pf, "1\n");
        }
        else if ((*joueur1).pion == 0x02)
        {
            fprintf(pf, "2\n");
        }
        else if ((*joueur1).pion == 0x03)
        {
            fprintf(pf, "3\n");
        }
        else if ((*joueur1).pion == 0x04)
        {
            fprintf(pf, "4\n");
        }
        else if ((*joueur1).pion == 0x05)
        {
            fprintf(pf, "5\n");
        }
        else if ((*joueur1).pion == 0x06)
        {
            fprintf(pf, "6\n");
        }
        else if ((*joueur1).pion == 0x0B)
        {
            fprintf(pf, "7\n");
        }
        else if ((*joueur1).pion == 0x0C)
        {
            fprintf(pf, "8\n");
        }
        else if ((*joueur1).pion == 0x0F)
        {
            fprintf(pf, "9\n");
        }
        fprintf(pf, "%d\n\n", (*joueur1).nbrTours);
    }
    if (nbrJoueurs >= 2)      //On ecrit dans le fichier texte tout le contenu des structures joueur en fonction du nombre de joueur en jeu
    {
        fprintf(pf, "%s\n", (*joueur2).prenom);
        fprintf(pf, "%d\n", (*joueur2).argent);
        fprintf(pf, "%d\n", (*joueur2).nbrProprietes);
        fprintf(pf, "%d\n", (*joueur2).cartePrison);
        fprintf(pf, "%d\n", (*joueur2).OrdreDePassage);
        fprintf(pf, "%d\n", (*joueur2).caseActuelle);
        fprintf(pf, "%d\n", (*joueur2).enJeu);
        if ((*joueur2).pion == 0x01)
        {
            fprintf(pf, "1\n");
        }
        else if ((*joueur2).pion == 0x02)
        {
            fprintf(pf, "2\n");
        }
        else if ((*joueur2).pion == 0x03)
        {
            fprintf(pf, "3\n");
        }
        else if ((*joueur2).pion == 0x04)
        {
            fprintf(pf, "4\n");
        }
        else if ((*joueur2).pion == 0x05)
        {
            fprintf(pf, "5\n");
        }
        else if ((*joueur2).pion == 0x06)
        {
            fprintf(pf, "6\n");
        }
        else if ((*joueur2).pion == 0x0B)
        {
            fprintf(pf, "7\n");
        }
        else if ((*joueur2).pion == 0x0C)
        {
            fprintf(pf, "8\n");
        }
        else if ((*joueur2).pion == 0x0F)
        {
            fprintf(pf, "9\n");
        }
        fprintf(pf, "%d\n\n", (*joueur2).nbrTours);
    }
    if (nbrJoueurs >= 3)      //On ecrit dans le fichier texte tout le contenu des structures joueur en fonction du nombre de joueur en jeu
    {
        fprintf(pf, "%s\n", (*joueur3).prenom);
        fprintf(pf, "%d\n", (*joueur3).argent);
        fprintf(pf, "%d\n", (*joueur3).nbrProprietes);
        fprintf(pf, "%d\n", (*joueur3).cartePrison);
        fprintf(pf, "%d\n", (*joueur3).OrdreDePassage);
        fprintf(pf, "%d\n", (*joueur3).caseActuelle);
        fprintf(pf, "%d\n", (*joueur3).enJeu);
        if ((*joueur3).pion == 0x01)
        {
            fprintf(pf, "1\n");
        }
        else if ((*joueur3).pion == 0x02)
        {
            fprintf(pf, "2\n");
        }
        else if ((*joueur3).pion == 0x03)
        {
            fprintf(pf, "3\n");
        }
        else if ((*joueur3).pion == 0x04)
        {
            fprintf(pf, "4\n");
        }
        else if ((*joueur3).pion == 0x05)
        {
            fprintf(pf, "5\n");
        }
        else if ((*joueur3).pion == 0x06)
        {
            fprintf(pf, "6\n");
        }
        else if ((*joueur3).pion == 0x0B)
        {
            fprintf(pf, "7\n");
        }
        else if ((*joueur3).pion == 0x0C)
        {
            fprintf(pf, "8\n");
        }
        else if ((*joueur3).pion == 0x0F)
        {
            fprintf(pf, "9\n");
        }
        fprintf(pf, "%d\n\n", (*joueur3).nbrTours);
    }
    if (nbrJoueurs >= 4)      //On ecrit dans le fichier texte tout le contenu des structures joueur en fonction du nombre de joueur en jeu
    {
        fprintf(pf, "%s\n", (*joueur4).prenom);
        fprintf(pf, "%d\n", (*joueur4).argent);
        fprintf(pf, "%d\n", (*joueur4).nbrProprietes);
        fprintf(pf, "%d\n", (*joueur4).cartePrison);
        fprintf(pf, "%d\n", (*joueur4).OrdreDePassage);
        fprintf(pf, "%d\n", (*joueur4).caseActuelle);
        fprintf(pf, "%d\n", (*joueur4).enJeu);
        if ((*joueur4).pion == 0x01)
        {
            fprintf(pf, "1\n");
        }
        else if ((*joueur4).pion == 0x02)
        {
            fprintf(pf, "2\n");
        }
        else if ((*joueur4).pion == 0x03)
        {
            fprintf(pf, "3\n");
        }
        else if ((*joueur4).pion == 0x04)
        {
            fprintf(pf, "4\n");
        }
        else if ((*joueur4).pion == 0x05)
        {
            fprintf(pf, "5\n");
        }
        else if ((*joueur4).pion == 0x06)
        {
            fprintf(pf, "6\n");
        }
        else if ((*joueur4).pion == 0x0B)
        {
            fprintf(pf, "7\n");
        }
        else if ((*joueur4).pion == 0x0C)
        {
            fprintf(pf, "8\n");
        }
        else if ((*joueur4).pion == 0x0F)
        {
            fprintf(pf, "9\n");
        }
        fprintf(pf, "%d\n\n", (*joueur4).nbrTours);
    }
    if (nbrJoueurs >= 5)      //On ecrit dans le fichier texte tout le contenu des structures joueur en fonction du nombre de joueur en jeu
    {
        fprintf(pf, "%s\n", (*joueur5).prenom);
        fprintf(pf, "%d\n", (*joueur5).argent);
        fprintf(pf, "%d\n", (*joueur5).nbrProprietes);
        fprintf(pf, "%d\n", (*joueur5).cartePrison);
        fprintf(pf, "%d\n", (*joueur5).OrdreDePassage);
        fprintf(pf, "%d\n", (*joueur5).caseActuelle);
        fprintf(pf, "%d\n", (*joueur5).enJeu);
        if ((*joueur5).pion == 0x01)
        {
            fprintf(pf, "1\n");
        }
        else if ((*joueur5).pion == 0x02)
        {
            fprintf(pf, "2\n");
        }
        else if ((*joueur5).pion == 0x03)
        {
            fprintf(pf, "3\n");
        }
        else if ((*joueur5).pion == 0x04)
        {
            fprintf(pf, "4\n");
        }
        else if ((*joueur5).pion == 0x05)
        {
            fprintf(pf, "5\n");
        }
        else if ((*joueur5).pion == 0x06)
        {
            fprintf(pf, "6\n");
        }
        else if ((*joueur5).pion == 0x0B)
        {
            fprintf(pf, "7\n");
        }
        else if ((*joueur5).pion == 0x0C)
        {
            fprintf(pf, "5\n");
        }
        else if ((*joueur5).pion == 0x0F)
        {
            fprintf(pf, "9\n");
        }
        fprintf(pf, "%d\n\n", (*joueur5).nbrTours);
    }
    if (nbrJoueurs >= 6)      //On ecrit dans le fichier texte tout le contenu des structures joueur en fonction du nombre de joueur en jeu
    {
        fprintf(pf, "%s\n", (*joueur6).prenom);
        fprintf(pf, "%d\n", (*joueur6).argent);
        fprintf(pf, "%d\n", (*joueur6).nbrProprietes);
        fprintf(pf, "%d\n", (*joueur6).cartePrison);
        fprintf(pf, "%d\n", (*joueur6).OrdreDePassage);
        fprintf(pf, "%d\n", (*joueur6).caseActuelle);
        fprintf(pf, "%d\n", (*joueur6).enJeu);
        if ((*joueur6).pion == 0x01)
        {
            fprintf(pf, "1\n");
        }
        else if ((*joueur6).pion == 0x02)
        {
            fprintf(pf, "2\n");
        }
        else if ((*joueur6).pion == 0x03)
        {
            fprintf(pf, "3\n");
        }
        else if ((*joueur6).pion == 0x04)
        {
            fprintf(pf, "4\n");
        }
        else if ((*joueur6).pion == 0x05)
        {
            fprintf(pf, "5\n");
        }
        else if ((*joueur6).pion == 0x06)
        {
            fprintf(pf, "6\n");
        }
        else if ((*joueur6).pion == 0x0B)
        {
            fprintf(pf, "7\n");
        }
        else if ((*joueur6).pion == 0x0C)
        {
            fprintf(pf, "8\n");
        }
        else if ((*joueur6).pion == 0x0F)
        {
            fprintf(pf, "9\n");
        }
        fprintf(pf, "%d\n\n", (*joueur6).nbrTours);
    }
    if (nbrJoueurs >= 7)      //On ecrit dans le fichier texte tout le contenu des structures joueur en fonction du nombre de joueur en jeu
    {
        fprintf(pf, "%s\n", (*joueur7).prenom);
        fprintf(pf, "%d\n", (*joueur7).argent);
        fprintf(pf, "%d\n", (*joueur7).nbrProprietes);
        fprintf(pf, "%d\n", (*joueur7).cartePrison);
        fprintf(pf, "%d\n", (*joueur7).OrdreDePassage);
        fprintf(pf, "%d\n", (*joueur7).caseActuelle);
        fprintf(pf, "%d\n", (*joueur7).enJeu);
        if ((*joueur7).pion == 0x01)
        {
            fprintf(pf, "1\n");
        }
        else if ((*joueur7).pion == 0x02)
        {
            fprintf(pf, "2\n");
        }
        else if ((*joueur7).pion == 0x03)
        {
            fprintf(pf, "3\n");
        }
        else if ((*joueur7).pion == 0x04)
        {
            fprintf(pf, "4\n");
        }
        else if ((*joueur7).pion == 0x05)
        {
            fprintf(pf, "5\n");
        }
        else if ((*joueur7).pion == 0x06)
        {
            fprintf(pf, "6\n");
        }
        else if ((*joueur7).pion == 0x0B)
        {
            fprintf(pf, "7\n");
        }
        else if ((*joueur7).pion == 0x0C)
        {
            fprintf(pf, "8\n");
        }
        else if ((*joueur7).pion == 0x0F)
        {
            fprintf(pf, "9\n");
        }
        fprintf(pf, "%d\n\n", (*joueur7).nbrTours);
    }
    if (nbrJoueurs == 8)      //On ecrit dans le fichier texte tout le contenu des structures joueur en fonction du nombre de joueur en jeu
    {
        fprintf(pf, "%s\n", (*joueur8).prenom);
        fprintf(pf, "%d\n", (*joueur8).argent);
        fprintf(pf, "%d\n", (*joueur8).nbrProprietes);
        fprintf(pf, "%d\n", (*joueur8).cartePrison);
        fprintf(pf, "%d\n", (*joueur8).OrdreDePassage);
        fprintf(pf, "%d\n", (*joueur8).caseActuelle);
        fprintf(pf, "%d\n", (*joueur8).enJeu);
        if ((*joueur8).pion == 0x01)
        {
            fprintf(pf, "1\n");
        }
        else if ((*joueur8).pion == 0x02)
        {
            fprintf(pf, "2\n");
        }
        else if ((*joueur8).pion == 0x03)
        {
            fprintf(pf, "3\n");
        }
        else if ((*joueur8).pion == 0x04)
        {
            fprintf(pf, "4\n");
        }
        else if ((*joueur8).pion == 0x05)
        {
            fprintf(pf, "5\n");
        }
        else if ((*joueur8).pion == 0x06)
        {
            fprintf(pf, "6\n");
        }
        else if ((*joueur8).pion == 0x0B)
        {
            fprintf(pf, "7\n");
        }
        else if ((*joueur8).pion == 0x0C)
        {
            fprintf(pf, "8\n");
        }
        else if ((*joueur8).pion == 0x0F)
        {
            fprintf(pf, "9\n");
        }
        fprintf(pf, "%d\n\n", (*joueur8).nbrTours);
    }









    p tableauProp[22];      //On crée un tableau dans lequel on met toutes les structures proprietes
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
    for (int i=0;i<22;i++)
    {
        fprintf(pf, "%s\n", (tableauProp[i]).nom);        //On ecrit dans le fichier texte tout le contenu des structures proprietes
        fprintf(pf, "%d\n", (tableauProp[i]).numPlateau);
        fprintf(pf, "%d\n", (tableauProp[i]).prix);
        fprintf(pf, "%d\n", (tableauProp[i]).loyer0);
        fprintf(pf, "%d\n", (tableauProp[i]).loyer1);
        fprintf(pf, "%d\n", (tableauProp[i]).loyer2);
        fprintf(pf, "%d\n", (tableauProp[i]).loyer3);
        fprintf(pf, "%d\n", (tableauProp[i]).loyer4);
        fprintf(pf, "%d\n", (tableauProp[i]).loyer5);
        fprintf(pf, "%d\n", (tableauProp[i]).valeur_hypotheque);
        fprintf(pf, "%d\n", (tableauProp[i]).prix_maison);
        fprintf(pf, "%s\n", (tableauProp[i]).proprietaire);
        fprintf(pf, "%s\n", (tableauProp[i]).famille);
        fprintf(pf, "%d\n", (tableauProp[i]).nbrMaisons);
        fprintf(pf, "%d\n\n", (tableauProp[i]).valHypotheque);
    }




    fclose(pf);     //On referme le fichier texte
    pf = NULL;
    return 1;
}


