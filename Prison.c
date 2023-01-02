#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "Structures.h"


///------------------------------------- Trouver quel joueur a une carte sortie de prison -------------------------------------

void trouverCarteSortiePrison (struct joueur *joueurActuel, struct joueur joueurCartePrison, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8)
{
    if ((*joueur2).cartePrison > 0)
    {
        joueurCartePrison = *joueur2;
    }
    else if ((*joueur3).cartePrison > 0)
    {
        joueurCartePrison = *joueur3;
    }
    else if ((*joueur4).cartePrison > 0)
    {
        joueurCartePrison = *joueur4;
    }
    else if ((*joueur5).cartePrison > 0)
    {
        joueurCartePrison = *joueur5;
    }
    else if ((*joueur6).cartePrison > 0)
    {
        joueurCartePrison = *joueur6;
    }
    else if ((*joueur7).cartePrison > 0)
    {
        joueurCartePrison = *joueur7;
    }
    else if ((*joueur8).cartePrison > 0)
    {
        joueurCartePrison = *joueur8;
    }
}


void trouverCarteSortiePrison2 (struct joueur *joueurActuel, struct joueur joueurCartePrison, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8)
{
    if ((*joueur2).cartePrison > 0)
    {
        echangeArgent(joueurCartePrison, *joueur2);
    }
    else if ((*joueur3).cartePrison > 0)
    {
        echangeArgent(joueurCartePrison, *joueur3);
    }
    else if ((*joueur4).cartePrison > 0)
    {
        echangeArgent(joueurCartePrison, *joueur4);
    }
    else if ((*joueur5).cartePrison > 0)
    {
        echangeArgent(joueurCartePrison, *joueur5);
    }
    else if ((*joueur6).cartePrison > 0)
    {
        echangeArgent(joueurCartePrison, *joueur6);
    }
    else if ((*joueur7).cartePrison > 0)
    {
        echangeArgent(joueurCartePrison, *joueur7);
    }
    else if ((*joueur8).cartePrison > 0)
    {
        echangeArgent(joueurCartePrison, *joueur8);
    }
}


void echangeArgent(struct joueur joueurCartePrison, struct joueur *joueur)
{
    *joueur = joueurCartePrison;
}



///------------------------------------------------------- Menu Prison --------------------------------------------------------

void menuPrison(struct joueur *joueurActuel, int *doubles, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8, struct proprietes *Gdynia, struct proprietes *Taipei, struct proprietes *Tokyo, struct proprietes *Barcelone, struct proprietes *Athenes, struct proprietes *Istanbul, struct proprietes *Kyiv, struct proprietes *Toronto, struct proprietes *Rome, struct proprietes *Shanghai, struct proprietes *Vancouver, struct proprietes *Sydney, struct proprietes *NewYork, struct proprietes *Londres, struct proprietes *Beijing, struct proprietes *HongKong, struct proprietes *Jerusalem, struct proprietes *Paris, struct proprietes *Belgrade, struct proprietes *LeCap, struct proprietes *Riga, struct proprietes *Montreal)
{
    char suite;
    int col = 130;
    struct joueur joueurCartePrison;
    trouverCarteSortiePrison(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
    resetDuPionQuiJoue((joueurActuel));
    (*joueurActuel).caseActuelle = 9;
    affichageDuPionQuiJoue((joueurActuel));
    gotoligcol(4,col);
    (*joueurActuel).nbrTours = (*joueurActuel).nbrTours + 1;
    printf("C'est votre tour numero %d en prison.", (*joueurActuel).nbrTours);
    int choix = 0;
    int choix2 = 0;
    int choix3 = 0;
    int choix4 = 0;
    int choix5 = 0;
    int choix6 = 0;
    int prix = 0;
    int detot = 0;

    ///---------------------------- /!\ tester quel joueur a la carte sortie de prison -------------------------------------
    ///---------------------------- /!\ faire menu payer apres que le joueur ai revendu des proprietes ---------------------
    ///---------------------------- /!\ verifier choix choix2 choix 3 avant menu tour < 3 ----------------------------------


///---------------------------------- Le joueur actuel possede au moins une carte prison ----------------------------------
    if ((*joueurActuel).cartePrison >= 1)
    {
        gotoligcol(6,col);
        printf("Vous etes en prison, vous avez 3 choix :");
        gotoligcol(7,col);
        printf("1. Payer une amende de 50 dollards.");
        if ((*joueurActuel).nbrTours < 3)
        {
            gotoligcol(8,col);
            printf("2. Lancer un double pour sortir.");
        }
        else if ((*joueurActuel).nbrTours == 3)
        {
            gotoligcol(8,col);
            printf("2. Lancer un double sur ce dernier tour.");
        }
        gotoligcol(9,col);
        printf("3. Utiliser une carte sortir de prison gratuitement.");
        gotoligcol(10,col);
        fflush(stdin);
        scanf("%d", &choix);
        while (choix < 1 || choix > 3)
        {
            gotoligcol(6,col);
            printf("Demande non valide, vous etes en prison, vous avez 3 choix :");
            gotoligcol(10,col);
            fflush(stdin);
            scanf("%d",&choix);
        }
        reset(4,10,col,col+80);
        if (choix == 1)
        {
            if ((*joueurActuel).argent >= 50)
            {

                gotoligcol(6,col);
                printf("Vous avez payer l'amende de 50 dollards. Vous etes libre !");
                (*joueurActuel).argent -= 50;
                (*joueurActuel).nbrTours = 0;
                gotoligcol(8,col);
                printf("Votre nouveau solde : %d", (*joueurActuel).argent);

            }
            else if ((*joueurActuel).argent < 50)
            {
                //hypotheque ou vendre des proprietes
                gotoligcol(6,col);
                printf("Vous n'avez pas assez d'argent, vous avez 3 choix :");
                if ((*joueurActuel).nbrTours < 3)
                {
                    gotoligcol(7,col);
                    printf("1. Lancer un double pour sortir.");
                }
                else if ((*joueurActuel).nbrTours == 3)
                {
                    gotoligcol(7,col);
                    printf("1. Lancer un double sur ce dernier tour.");
                }
                gotoligcol(8,col);
                printf("2. Vendre une propriete.");
                gotoligcol(9,col);
                printf("3. Utiliser une carte sortir de prison gratuitement.");
                gotoligcol(10,col);
                fflush(stdin);
                scanf("%d",&choix2);
                while (choix2 < 1 || choix2 > 3)
                {
                    gotoligcol(6,col);
                    printf("Demande non valide, vous n'avez pas assez d'argent, vous avez 3 choix :");
                    gotoligcol(10,col);
                    fflush(stdin);
                    scanf("%d",&choix2);
                    reset(10,10,col,col+50);
                }
                reset(4,11,col,col+80);
                if (choix2 == 1)
                {
                    doubles = lancerDesPrison(&doubles, 6);
                    if (doubles == 1)
                    {
                        gotoligcol(13,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                    }
                    else if (doubles == 0 && (*joueurActuel).nbrTours < 3)
                    {

                        gotoligcol(13,col);
                        printf("Dommage, vous restez en prison.");
                    }
                    else if (doubles == 0 && (*joueurActuel).nbrTours == 3)
                    {
                        gotoligcol(13,col);
                        printf("Dommage, vous n'avez pas fait de double, vous avez 2 choix :");
                        gotoligcol(14,col);
                        printf("1. Vendre une propriete.");
                        gotoligcol(15,col);
                        printf("2. Utiliser une carte sortir de prison gratuitement.");
                        gotoligcol(16,col);
                        fflush(stdin);
                        scanf("%d",&choix3);
                        while (choix3 < 1 || choix3 > 2)
                        {
                            gotoligcol(13,col);
                            printf("Demande non valide, dommage, vous n'avez pas fait de double, vous avez 2 choix :");
                            gotoligcol(16,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                            reset(16,16,col,col+50);
                        }
                        reset(4,16,col,col+80);
                        if (choix3 == 1)
                        {
                            menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                            //hypotheque
                            if ((*joueurActuel).argent >= 50)
                            {
                                gotoligcol(7,col);
                                printf("Vous  payez l'amende de 50 dollards. Vous etes libre !");
                                (*joueurActuel).argent -= 50;
                                (*joueurActuel).nbrTours = 0;
                                gotoligcol(9,col);
                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                            }
                            else if ((*joueurActuel).argent < 50)
                            {
                                gotoligcol(7,col);
                                printf("Dommage, vous n'avez pas assez d'argent, vous avez un choix :");
                                gotoligcol(8,col);
                                printf("1. Utiliser une carte sortir de prison gratuitement.");
                                gotoligcol(9,col);
                                fflush(stdin);
                                scanf("%d",&choix4);
                                while (choix4 < 1 || choix4 > 1)
                                {
                                    gotoligcol(7,col);
                                    printf("Demande non valide, dommage, vous n'avez pas assez d'argent, vous avez un choix :");
                                    gotoligcol(9,col);
                                    fflush(stdin);
                                    scanf("%d",&choix4);
                                    reset(9,9,col,col+50);
                                }
                                reset(4,9,col,col+80);
                                if (choix4 == 1)
                                {
                                    (*joueurActuel).cartePrison = (*joueurActuel).cartePrison - 1;
                                    gotoligcol(7,col);
                                    printf("Vous avez utilise votre carte sortie de prison.");
                                    gotoligcol(9,col);
                                    printf("Vous etes libre !");
                                    (*joueurActuel).nbrTours = 0;
                                    reset(7,9,col,col+80);
                                }

                            }
                        }
                    }
                }
                else if (choix2 == 2)
                {
                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                    //hypotheque
                    if ((*joueurActuel).argent >= 50)
                    {
                                gotoligcol(6,col);
                                printf("Vous  payez l'amende de 50 dollards. Vous etes libre !");
                                (*joueurActuel).argent -= 50;
                                (*joueurActuel).nbrTours = 0;
                                gotoligcol(8,col);
                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                    }
                    else if ((*joueurActuel).argent < 50)
                    {
                        gotoligcol(6,col);
                        printf("Dommage, vous n'avez pas assez d'argent, vous avez un choix :");
                        gotoligcol(7,col);
                        printf("1. Utiliser une carte sortir de prison gratuitement.");
                        gotoligcol(8,col);
                        fflush(stdin);
                        scanf("%d",&choix3);
                        while (choix3 < 1 || choix3 > 1)
                        {
                            reset(8,8,col,col+20);
                            printf("Demande non valide, dommage, vous n'avez pas assez d'argent, vous avez un choix :");
                            gotoligcol(8,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                        }
                        if (choix3 == 1)
                        {
                            (*joueurActuel).cartePrison = (*joueurActuel).cartePrison - 1;
                            gotoligcol(10,col);
                            printf("Vous avez utilise votre carte sortie de prison.");
                            gotoligcol(11,col);
                            printf("Vous etes libre !");
                            (*joueurActuel).nbrTours = 0;
                        }
                    }
                }
                else if (choix2 == 3)
                {
                    (*joueurActuel).cartePrison = (*joueurActuel).cartePrison - 1;
                    gotoligcol(10,col);
                    printf("Vous avez utilise votre carte sortie de prison.");
                    gotoligcol(11,col);
                    printf("Vous etes libre !");
                    (*joueurActuel).nbrTours = 0;
                }
            }
        }
        else if (choix == 2)
        {
            if ((*joueurActuel).nbrTours < 3)
            {
                doubles = lancerDes(&doubles, 6);
                if (doubles == 1)
                {
                    gotoligcol(13,col);
                    printf("Vous etes libre !");
                    (*joueurActuel).nbrTours = 0;
                }
                else if (doubles == 0)
                {
                    gotoligcol(13,col);
                    printf("Dommage, vous restez en prison.");
                }
            }
            else if ((*joueurActuel).nbrTours == 3)
            {
                doubles = lancerDes(&doubles, 6);
                if (doubles == 1)
                {
                    gotoligcol(13,col);
                    printf("Vous etes libre !");
                    (*joueurActuel).nbrTours = 0;
                }
                else if (doubles == 0)
                {
                    gotoligcol(13,col);
                    printf("Dommage vous n'avez pas fait de double, vous avez 2 choix :");
                    gotoligcol(14,col);
                    printf("1. Payer une amende de 50 dollards.");
                    gotoligcol(15,col);
                    printf("2. Utiliser une carte sortir de prison gratuitement.");
                   gotoligcol(16,col);
                    fflush(stdin);
                    scanf("%d", &choix2);
                    while (choix2 < 1 || choix2 > 2)
                    {
                        reset(16,16,col,col+50);
                        gotoligcol(13,col);
                        printf("Demande non valide, vous etes en prison dans votre dernier tour, vous avez 2 choix :");
                        gotoligcol(16,col);
                        fflush(stdin);
                        scanf("%d",&choix2);
                    }
                    reset(4,16,col,col+80);
                    if (choix2 == 1)
                    {
                        if ((*joueurActuel).argent >= 50)
                        {
                            gotoligcol(6,col);
                            printf("Vous avez payer l'amende de 50 dollards. Vous etes libre !");
                            (*joueurActuel).argent -= 50;
                            (*joueurActuel).nbrTours = 0;
                            gotoligcol(8,col);
                            printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                        }
                        else if ((*joueurActuel).argent < 50)
                        {
                            menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                            //hypotheque
                            if ((*joueurActuel).argent >= 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous  payez l'amende de 50 dollards. Vous etes libre !");
                                (*joueurActuel).argent -= 50;
                                (*joueurActuel).nbrTours = 0;
                                gotoligcol(8,col);
                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                            }
                            else if ((*joueurActuel).argent < 50)
                            {
                                gotoligcol(6,col);
                                printf("Dommage, vous n'avez pas assez d'argent, vous avez un choix :");
                                gotoligcol(7,col);
                                printf("1. Utiliser une carte sortir de prison gratuitement.");
                                gotoligcol(8,col);
                                fflush(stdin);
                                scanf("%d",&choix3);
                                while (choix3 < 1 || choix3 > 1)
                                {
                                    reset(8,8,col,col+50);
                                    gotoligcol(6,col);
                                    printf("Demande non valide, dommage, vous n'avez pas assez d'argent, vous avez un choix :");
                                    gotoligcol(8,col);
                                    fflush(stdin);
                                    scanf("%d",&choix3);
                                }
                                reset(4,8,col,col+80);
                                if (choix3 == 1)
                                {
                                    (*joueurActuel).cartePrison = (*joueurActuel).cartePrison - 1;
                                    gotoligcol(6,col);
                                    printf("Vous avez utilise votre carte sortie de prison.");
                                    gotoligcol(8,col);
                                    printf("Vous etes libre !");
                                    (*joueurActuel).nbrTours = 0;
                                }
                            }
                        }
                    }
                    else if (choix2 == 3)
                    {
                        gotoligcol(6,col);
                        (*joueurActuel).cartePrison = (*joueurActuel).cartePrison - 1;
                        printf("Vous avez utilise votre carte sortie de prison.");
                        gotoligcol(8,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                    }
                }
            }
        }
        else if (choix == 3)
        {
            (*joueurActuel).cartePrison = (*joueurActuel).cartePrison - 1;
            gotoligcol(6,col);
            printf("Vous avez utilise votre carte sortie de prison.");
            gotoligcol(8,col);
            printf("Vous etes libre !");
            (*joueurActuel).nbrTours = 0;
        }
        reset(4,25,col,col+80);
    }



 ///------------------------------- Le joueur actuel ne possede pas de carte prison cependant un autre joueur en possede une -------------------------------

    else if ((*joueurActuel).nbrTours < 3 && ((*joueur2).cartePrison == 1 || (*joueur3).cartePrison == 1 || (*joueur4).cartePrison == 1 || (*joueur5).cartePrison == 1 || (*joueur6).cartePrison == 1 || (*joueur7).cartePrison == 1))
    {
        gotoligcol(6,col);
        printf("Vous etes en prison, vous avez 3 choix :");
        gotoligcol(7,col);
        printf("1. Payer une amende de 50 dollards.");
        gotoligcol(8,col);
        printf("2. Lancer un double sur l'un du ou des tours suivants.");
        gotoligcol(9,col);
        printf("3. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
        gotoligcol(10,col);
        fflush(stdin);
        scanf("%d", &choix);
        while (choix < 1 || choix > 3)
        {
            reset(10,10,col,col+50);
            gotoligcol(6,col);
            printf("Demande non valide, ous etes en prison, vous avez 3 choix :");
            gotoligcol(10,col);
            fflush(stdin);
            scanf("%d",&choix);
        }
        reset(4,10,col,col+80);
        if (choix == 1)
        {
            if ((*joueurActuel).argent >= 50)
            {
                gotoligcol(6,col);
                printf("Vous avez payer l'amende de 50 dollards. Vous etes libre !");
                (*joueurActuel).argent -= 50;
                (*joueurActuel).nbrTours = 0;
                gotoligcol(8,col);
                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < 50)
            {
                //hypotheque ou vendre des proprietes
                gotoligcol(6,col);
                printf("Vous n'avez pas assez d'argent, vous avez 3 choix :");
                gotoligcol(7,col);
                printf("1. Lancer un double pour sortir.");
                gotoligcol(8,col);
                printf("2. Vendre une propriete.");
                gotoligcol(9,col);
                printf("3. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
                gotoligcol(10,col);
                fflush(stdin);
                scanf("%d",&choix2);
                while (choix2 < 1 || choix2 > 3)
                {
                    reset(10,10,col,col+50);
                    gotoligcol(6,col);
                    printf("Demande non valide, vous n'avez pas assez d'argent, vous avez 2 choix :");
                    gotoligcol(10,col);
                    fflush(stdin);
                    scanf("%d",&choix2);
                }
                reset(4,12,col,col+80);
                if (choix2 == 1)
                {
                    doubles = lancerDesPrison(&doubles, 6);
                    if (doubles == 1)
                    {
                        gotoligcol(13,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                    }
                    else if (doubles == 0)
                    {
                        gotoligcol(13,col);
                        printf("Dommage, vous restez en prison.");
                    }
                }
                else if (choix2 == 2)
                {
                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                    //hypotheque
                    if ((*joueurActuel).argent >= 50)
                    {
                        gotoligcol(6,col);
                        printf("Vous  payez l'amende de 50 dollards. Vous etes libre !");
                        (*joueurActuel).argent -= 50;
                        (*joueurActuel).nbrTours = 0;
                        gotoligcol(8,col);
                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                    }
                    else if ((*joueurActuel).argent < 50)
                    {
                        gotoligcol(6,col);
                        printf("Dommage, vous n'avez pas assez d'argent, vous restez en prison.");
                    }
                }
                else if (choix2 == 3)
                {
                    gotoligcol(6,col);
                    printf("Discutez du prix entre vous (oral).");
                    gotoligcol(10,col);
                    printf("Si vous avez un accord, saissez le montant de l'achat");
                    gotoligcol(10,col);
                    printf("Sinon saisissez un chiffre negatif");
                    gotoligcol(10,col);
                    fflush(stdin);
                    scanf("%d", &prix);
                    if (prix >= 0)
                    {
                        (*joueurActuel).argent = joueurCartePrison.argent - prix;
                        joueurCartePrison.argent = joueurCartePrison.argent + prix;
                        joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                        trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                        gotoligcol(12,col);
                        printf("Vous avez achete la carte sortie de prison pour %d dollards.", prix);
                        gotoligcol(14,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                    }
                    else if (prix < 0)
                    {
                        gotoligcol(12,col);
                        printf("Vous n'avez pas trouve d'accord, vous avez 2 choix :");
                        gotoligcol(13,col);
                        printf("1. Lancer un double sur l'un du ou des tours suivants.");
                        gotoligcol(14,col);
                        printf("2. Vendre une propriete. ");
                        gotoligcol(15,col);
                        fflush(stdin);
                        scanf("%d",&choix3);
                        while (choix3 < 1 || choix3 > 2)
                        {
                            reset(15,15,col,col+50);
                            gotoligcol(12,col);
                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                            gotoligcol(15,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                        }
                        reset(4,17,col,col+80);
                        if (choix3 == 1)
                        {
                            doubles = lancerDesPrison(&doubles, 6);
                            if (doubles == 1)
                            {
                                gotoligcol(6,col);
                                printf("Vous etes libre !");
                                (*joueurActuel).nbrTours = 0;

                            }
                            else if (doubles == 0)
                            {
                                gotoligcol(6,col);
                                printf("Dommage, vous restez en prison.");
                            }
                        }
                        else if (choix3 == 2)
                        {
                            menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                            //hypotheque
                            if ((*joueurActuel).argent >= 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous  payez l'amende de 50 dollards.");
                                gotoligcol(8,col);
                                printf("Vous etes libre !");
                                (*joueurActuel).argent -= 50;
                                (*joueurActuel).nbrTours = 0;
                                gotoligcol(10,col);
                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                            }
                            else if ((*joueurActuel).argent < 50)
                            {
                                gotoligcol(6,col);
                                printf("Dommage, vous n'avez pas assez d'argent, vous restez en prison.");
                            }
                        }
                    }
                }
            }
        }
        else if (choix == 2)
        {
            doubles = lancerDesPrison(&doubles, 6);
            if (doubles == 1)
            {
                gotoligcol(6,col);
                printf("Vous etes libre !");
                (*joueurActuel).nbrTours = 0;

            }
            else if (doubles == 0)
            {
                gotoligcol(6,col);
                printf("Dommage, vous restez en prison.");
            }
        }
        else if (choix == 3)
        {
            gotoligcol(6,col);
            printf("Discutez du prix entre vous. (oral)");
            gotoligcol(7,col);
            printf("Si vous avez un accord, saisissez le montant dez l'achat");
            gotoligcol(8,col);
            printf("Sinon saisissez un chiffre negatif");
            gotoligcol(9,col);
            fflush(stdin);
            scanf("%d", &prix);
            if (prix >= 0)
            {
                (*joueurActuel).argent = joueurCartePrison.argent - prix;
                joueurCartePrison.argent = joueurCartePrison.argent + prix;
                joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                gotoligcol(11,col);
                printf("Vous avez achete la carte sortie de prison pour %d dollards.", prix);
                gotoligcol(13,col);
                printf("Vous etes libre !");
                (*joueurActuel).nbrTours = 0;
            }
            else if (prix < 0)
            {
                gotoligcol(11,col);
                printf("Vous etes en prison, vous avez 2 choix :");
                gotoligcol(12,col);
                printf("1. Payer une amende de 50 dollards.");
                gotoligcol(13,col);
                printf("2. Lancer un double pour sortir.");
                gotoligcol(14,col);
                fflush(stdin);
                scanf("%d",&choix2);
                while (choix2 < 1 || choix2 > 2)
                {
                    reset(14,14,col,col+50);
                    gotoligcol(11,col);
                    printf("Demande non valide, vous etes en prison, vous avez 2 choix :");
                    gotoligcol(14,col);
                    fflush(stdin);
                    scanf("%d",&choix2);
                }
                reset(4,15,col,col+80);
                if (choix2 == 1)
                {
                    if ((*joueurActuel).argent >= 50)
                    {
                        gotoligcol(6,col);
                        printf("Vous avez payer l'amende de 50 dollards.");
                        gotoligcol(8,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).argent -= 50;
                        (*joueurActuel).nbrTours = 0;
                        gotoligcol(10,col);
                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                    }
                    else if ((*joueurActuel).argent < 50)
                    {
                        //---//////////////////////////////--- Si le joueur n'a pas assez d'argent ---//////////////////////////////---
                        menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                        //hypotheque ou vendre des proprietes
                        if ((*joueurActuel).argent >= 50)
                        {
                            gotoligcol(6,col);
                            printf("Vous  payez l'amende de 50 dollards.");
                            gotoligcol(8,col);
                            printf("Vous etes libre");
                            (*joueurActuel).argent -= 50;
                            (*joueurActuel).nbrTours = 0;
                            gotoligcol(10,col);
                            printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                        }
                        else if ((*joueurActuel).argent < 50)
                        {
                            gotoligcol(6,col);
                            printf("Dommage, vous n'avez pas assez d'argent, vous avez un choix :");
                            gotoligcol(7,col);
                            printf("1. Lancer un double pour sortir.");
                            gotoligcol(8,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                            while (choix3 < 1 || choix3 > 1)
                            {
                                reset(8,8,col,col+50);
                                gotoligcol(6,col);
                                printf("Demande non valide, dommage, vous n'avez pas assez d'argent, vous avez un choix :");
                                gotoligcol(8,col);
                                fflush(stdin);
                                scanf("%d",&choix3);
                            }
                            reset(4,18,col,col+80);
                            if (choix3 == 1)
                            {
                                doubles = lancerDesPrison(&doubles, 6);
                                if (doubles == 1)
                                {
                                    gotoligcol(6,col);
                                    printf("Vous etes libre !");
                                    (*joueurActuel).nbrTours = 0;
                                }
                                else if (doubles == 0)
                                {
                                    gotoligcol(6,col);
                                    printf("Dommage, vous restez en prison.");
                                }
                            }
                        }
                    }
                }
                else if (choix2 == 2)
                {
                    doubles = lancerDesPrison(&doubles, 6);
                    if (doubles == 1)
                    {
                        gotoligcol(6,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
                    }
                    else if (doubles == 0)
                    {
                        printf("Dommage, vous restez en prison.");
                    }
                }
            }
        }
        reset(4,25,col,col+80);
    }

 ///--------------------- Menu autre joueur carte sortie prison et dernier tour -------------------------

    else if ((*joueurActuel).nbrTours == 3 && ((*joueur2).cartePrison == 1 || (*joueur3).cartePrison == 1 || (*joueur4).cartePrison == 1 || (*joueur5).cartePrison == 1 || (*joueur6).cartePrison == 1 || (*joueur7).cartePrison == 1))
    {
        gotoligcol(6,col);
        printf("Vous etes en prison, vous avez 3 choix :");
        gotoligcol(7,col);
        printf("1. Payer une amende de 50 dollards.");
        gotoligcol(8,col);
        printf("2. Lancer un double sur le prochain tour.");
        gotoligcol(9,col);
        printf("3. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
        gotoligcol(10,col);
        fflush(stdin);
        scanf("%d", &choix);
        while (choix < 1 || choix > 3)
        {
            reset(10,10,col,col+50);
            gotoligcol(6,col);
            printf("Demande non valide, vous etes en prison, vous avez 3 choix :");
            gotoligcol(10,col);
            fflush(stdin);
            scanf("%d",&choix);
        }
        reset(4,12,col,col+80);
        ///payer/*
        if (choix == 1)
        {
            if ((*joueurActuel).argent >= 50)
            {
                gotoligcol(6,col);
                printf("Vous avez payer l'amende de 50 dollards.");
                gotoligcol(8,col);
                printf("Vous etes libre !");
                (*joueurActuel).argent -= 50;
                (*joueurActuel).nbrTours = 0;
                gotoligcol(10,col);
                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
            }
            else if ((*joueurActuel).argent < 50)
            {
                //hypotheque ou vendre des proprietes
                gotoligcol(6,col);
                printf("Vous n'avez pas assez d'argent, vous avez 3 choix :");
                gotoligcol(7,col);
                printf("1. Lancer un double pour sortir.");
                gotoligcol(8,col);
                printf("2. Vendre une propriete.");
                gotoligcol(9,col);
                printf("3. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
                gotoligcol(10,col);
                fflush(stdin);
                scanf("%d",&choix2);
                while (choix2 < 1 || choix2 > 3)
                {
                    reset(10,10,col,col+50);
                    gotoligcol(6,col);
                    printf("Demande non valide, vous n'avez pas assez d'argent, vous avez 2 choix :");
                    gotoligcol(10,col);
                    fflush(stdin);
                    scanf("%d",&choix2);
                }
                reset(4,15,col,col+80);
                ///lancer les des

                if (choix2 == 1)
                {
                    doubles = lancerDesPrison(&doubles, 6);
                    if (doubles == 1)
                    {
                        gotoligcol(6,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                    }
                    ///pas d'argent et pas de doubles
                    else if (doubles == 0)
                    {
                        gotoligcol(6,col);
                        printf("Dommage vous n'avez pas fait de double, vous avez 2 choix :");
                        gotoligcol(7,col);
                        printf("1. Vendre une propriete.");
                        gotoligcol(8,col);
                        printf("2. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
                        gotoligcol(9,col);
                        fflush(stdin);
                        scanf("%d", &choix3);
                        while (choix3 < 1 || choix3 > 2)
                        {
                            reset(9,9,col,col+50);
                            gotoligcol(6,col);
                            printf("Demande non valide, vous etes en prison dans votre dernier tour, vous avez 2 choix :");
                            gotoligcol(9,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                        }
                        reset(4,20,col,col+80);
                        ///pas d'argent et pas de doubles et vendre
                        if (choix3 == 1)
                    {
                                                menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                            //hypotheque ou vendre des proprietes
                            //hypotheque ou vendre des proprietes ou elimine
                            if ((*joueurActuel).argent >= 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous  payez l'amende de 50 dollards.");
                                gotoligcol(8,col);
                                printf("Vous etes libre");
                                (*joueurActuel).argent -= 50;
                                (*joueurActuel).nbrTours = 0;
                                gotoligcol(10,col);
                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                            }
                else {
                            gotoligcol(6,col);
                            printf("Vous n'avez pas assez d'argent, vous avez un choix :");
                            gotoligcol(7,col);
                            printf("1. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
                            gotoligcol(8,col);
                            fflush(stdin);
                            scanf("%d",&choix4);
                            while (choix4 < 1 || choix4 > 1)
                            {
                                reset(8,8,col,col+50);
                                gotoligcol(10,col);
                                printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                gotoligcol(10,col);
                                fflush(stdin);
                                scanf("%d",&choix4);
                            }
                            reset(4,15,col,col+80);
                            if (choix4 == 1)
                            {
                                gotoligcol(6,col);
                                printf("Discutez du prix entre vous. (oral)");
                                gotoligcol(7,col);
                                printf("Si vous avez un accord, saisissez le montant de l'achat");
                                gotoligcol(8,col);
                                printf("Sinon, saisissez un chiffre negatif");
                                gotoligcol(9,col);
                                fflush(stdin);
                                scanf("%d", &prix);
                                if (prix >= 0)
                                {
                                    (*joueurActuel).argent = joueurCartePrison.argent - prix;
                                    joueurCartePrison.argent = joueurCartePrison.argent + prix;
                                    joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                                    trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                                    gotoligcol(12,col);
                                    printf("Vous avez achete la carte sortie de prison pour %d dollards.", prix);
                                    gotoligcol(14,col);
                                    printf("Vous etes libre !");
                                    (*joueurActuel).nbrTours = 0;

                                }
                                ///pas d'argent et pas de double et pas de carte sortie
                                else if (prix < 0)
                                {
                                    gotoligcol(12,col);
                                    printf("Vous n'avez pas trouve d'accord, vous avez un choix :");
                                    gotoligcol(13,col);
                                    printf("1. Vendre une propriete.");
                                    gotoligcol(14,col);
                                    fflush(stdin);
                                    scanf("%d",&choix5);
                                    while (choix5 < 1 || choix5 > 1)
                                    {
                                        reset(14,14,col,col+50);
                                        gotoligcol(12,col);
                                        printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                        gotoligcol(14,col);
                                        fflush(stdin);
                                        scanf("%d",&choix5);
                                    }
                                    reset(4,20,col,col+80);
                                    if (choix5 == 1)
                                    {
                                        menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                        //hypotheque ou vendre des proprietes ou elimine
                                        if ((*joueurActuel).argent >= 50)
                                        {
                                            gotoligcol(6,col);
                                            printf("Vous  payez l'amende de 50 dollards.");
                                            gotoligcol(8,col);
                                            printf("Vous etes libre !");
                                            (*joueurActuel).argent -= 50;
                                            (*joueurActuel).nbrTours = 0;
                                            gotoligcol(10,col);
                                            printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                        }
                                        else if ((*joueurActuel).argent < 50)
                                        {
                                            //hypotheque ou vendre des proprietes ou elimine
                                        }
                                    }
                                }
                            }}

                        }
                        ///pas d'argent et pas de double et acheter une carte sortie
                        else if (choix3== 2)
                        {
                            gotoligcol(6,col);
                            printf("Discutez du prix entre vous. (oral)");
                            gotoligcol(7,col);
                            printf("Si vous avez un accord, saisissez le montant de l'achat");
                            gotoligcol(8,col);
                            printf("Sinon, saisissez un chiffre negatif");
                            gotoligcol(9,col);
                            fflush(stdin);
                            scanf("%d", &prix);
                            if (prix >= 0)
                            {
                                (*joueurActuel).argent = joueurCartePrison.argent - prix;
                                joueurCartePrison.argent = joueurCartePrison.argent + prix;
                                joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                                trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                                gotoligcol(12,col);
                                printf("Vous avez achete la carte sortie de prison pour %d dollards.", prix);
                                gotoligcol(13,col);
                                printf("Vous etes libre");
                                (*joueurActuel).nbrTours = 0;
                            }
                            ///pas d'argent et pas de double et pas de carte sortie
                            else if (prix < 0)
                            {
                                gotoligcol(12,col);
                                printf("Vous n'avez pas trouve d'accord, vous avez un choix :");
                                gotoligcol(13,col);
                                printf("1. Vendre une propriete.");
                                gotoligcol(14,col);
                                fflush(stdin);
                                scanf("%d",&choix4);
                                while (choix4 < 1 || choix4 > 1)
                                {
                                    reset(14,14,col,col+50);
                                    gotoligcol(12,col);
                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                    gotoligcol(14,col);
                                    fflush(stdin);
                                    scanf("%d",&choix4);
                                }
                                reset(4,20,col,col+80);
                                if (choix4 == 1)
                                {
                                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                    //hypotheque ou vendre des proprietes ou elimine
                                    if ((*joueurActuel).argent >= 50)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous  payez l'amende de 50 dollards.");
                                        gotoligcol(8,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).argent -= 50;
                                        (*joueurActuel).nbrTours = 0;
                                        gotoligcol(10,col);
                                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                    }
                                    else if ((*joueurActuel).argent < 50)
                                    {
                                        //hypotheque ou vendre des proprietes ou elimine
                                    }
                                }
                            }
                        }
                    }
                }
                ///vendre
                else if (choix2 == 2)
                {
                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                    //hypotheque
                    if ((*joueurActuel).argent >= 50)
                    {
                        gotoligcol(6,col);
                        printf("Vous  payez l'amende de 50 dollards.");
                        gotoligcol(8,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).argent -= 50;
                        (*joueurActuel).nbrTours = 0;
                        gotoligcol(10,col);
                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);                    }
                    else if ((*joueurActuel).argent < 50)
                    {
                        gotoligcol(6,col);
                        printf("Dommage vous n'avez pas assez d'argent, vous avez 2 choix :");
                        gotoligcol(7,col);
                        printf("1. Lancer un double sur le prochain tour.");
                        gotoligcol(8,col);
                        printf("2. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
                        gotoligcol(9,col);
                        fflush(stdin);
                        scanf("%d", &choix3);
                        while (choix3 < 1 || choix3 > 2)
                        {
                            reset(9,9,col,col+50);
                            gotoligcol(6,col);
                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez 2 choix :");
                            gotoligcol(9,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                        }
                        reset(4,15,col,col+80);
                        ///pas d'argent et pas de doubles et vendre
                        ///lancer les des
                        if (choix3 == 1)
                        {
                            doubles = lancerDesPrison(&doubles, 6);
                            if (doubles == 1)
                            {
                                gotoligcol(6,col);
                                printf("Vous etes libre !");
                                (*joueurActuel).nbrTours = 0;
                            }
                            else if (doubles == 0)
                            {
                                gotoligcol(6,col);
                                printf("Dommage vous n'avez pas fait de double, vous avez 2 choix :");
                                gotoligcol(7,col);
                                printf("1. Vendre une propriete.");
                                gotoligcol(8,col);
                                printf("2. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
                                gotoligcol(9,col);
                                fflush(stdin);
                                scanf("%d", &choix4);
                                while (choix4 < 1 || choix4 > 2)
                                {
                                    reset(9,9,col,col+50);
                                    gotoligcol(6,col);
                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez 2 choix :");
                                    gotoligcol(9,col);
                                    fflush(stdin);
                                    scanf("%d",&choix4);
                                }
                                reset(4,15,col,col+80);
                                if (choix4 == 1)
                                {
                                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                    //hypotheque ou vendre des proprietes ou elimine
                                    if ((*joueurActuel).argent >= 50)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous  payez l'amende de 50 dollards.");
                                        gotoligcol(8,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).argent -= 50;
                                        (*joueurActuel).nbrTours = 0;
                                        gotoligcol(10,col);
                                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                    }
                                    gotoligcol(6,col);
                                    printf("Dommage vous n'avez pas assez d'argent, vous avez un choix :");
                                    gotoligcol(7,col);
                                    printf("1. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
                                    gotoligcol(8,col);
                                    fflush(stdin);
                                    scanf("%d",&choix5);
                                    while (choix5 < 1 || choix5 > 1)
                                    {
                                        reset(8,8,col,col+50);
                                        gotoligcol(6,col);
                                        printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                        gotoligcol(8,col);
                                        fflush(stdin);
                                        scanf("%d",&choix5);
                                    }
                                    reset(4,15,col,col+80);
                                    if (choix5 == 1)
                                    {
                                        gotoligcol(6,col);
                                        printf("Discutez du prix entre vous. (oral)");
                                        gotoligcol(7,col);
                                        printf("Si vous avez un accord, saisissez le montant de l'achat");
                                        gotoligcol(8,col);
                                        printf("Sinon, saisissez un chiffre negatif");
                                        gotoligcol(9,col);
                                        fflush(stdin);
                                        scanf("%d", &prix);
                                        if (prix >= 0)
                                        {
                                            (*joueurActuel).argent = joueurCartePrison.argent - prix;
                                            joueurCartePrison.argent = joueurCartePrison.argent + prix;
                                            joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                                            trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                                            gotoligcol(12,col);
                                            printf("Vous avez achete la carte sortie de prison pour %d dollards.", prix);
                                            gotoligcol(13,col);
                                            printf("Vous etes libre");
                                            (*joueurActuel).nbrTours = 0;

                                        }
                                        ///pas d'argent et pas de double et pas de carte sortie
                                        else if (prix < 0)
                                        {
                                            gotoligcol(12,col);
                                            printf("Vous n'avez pas trouve d'accord, vous avez un choix :");
                                            gotoligcol(13,col);
                                            printf("1. Vendre une propriete.");
                                            gotoligcol(14,col);
                                            fflush(stdin);
                                            scanf("%d",&choix6);
                                            while (choix6 < 1 || choix6 > 1)
                                            {
                                                reset(14,14,col,col+50);
                                                gotoligcol(12,col);
                                                printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                                gotoligcol(14,col);
                                                fflush(stdin);
                                                scanf("%d",&choix6);
                                            }
                                            reset(4,20,col,col+50);
                                            if (choix6 == 1)
                                            {
                                                menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                                //hypotheque ou vendre des proprietes ou elimine
                                                if ((*joueurActuel).argent >= 50)
                                                {
                                                    gotoligcol(6,col);
                                                    printf("Vous  payez l'amende de 50 dollards.");
                                                    gotoligcol(8,col);
                                                    printf("Vous etes libre !");
                                                    (*joueurActuel).argent -= 50;
                                                    (*joueurActuel).nbrTours = 0;
                                                    gotoligcol(10,col);
                                                    printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                                }
                                                else if ((*joueurActuel).argent < 50)
                                                {
                                                    //hypotheque ou vendre des proprietes ou elimine
                                                }
                                            }
                                        }
                                    }
                                }
                                else if (choix4 == 2)
                                {
                                    gotoligcol(6,col);
                                    printf("Discutez du prix entre vous. (oral)");
                                    gotoligcol(7,col);
                                    printf("Si vous avez un accord, saisissez le montant de l'achat");
                                    gotoligcol(8,col);
                                    printf("Sinon, saisissez un chiffre negatif");
                                    gotoligcol(9,col);
                                    fflush(stdin);
                                    scanf("%d", &prix);
                                    if (prix >= 0)
                                    {
                                        (*joueurActuel).argent = joueurCartePrison.argent - prix;
                                        joueurCartePrison.argent = joueurCartePrison.argent + prix;
                                        joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                                        trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                                        gotoligcol(12,col);
                                        printf("Vous avez achete la carte sortie de prison pour %d dollards.", prix);
                                        gotoligcol(13,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).nbrTours = 0;
                                    }
                                    ///pas d'argent et pas de double et pas de carte sortie
                                    else if (prix < 0)
                                    {
                                        gotoligcol(12,col);
                                        printf("Vous n'avez pas trouve d'accord, vous avez un choix :");
                                        gotoligcol(13,col);
                                        printf("1. Vendre une propriete.");
                                        gotoligcol(14,col);
                                        fflush(stdin);
                                        scanf("%d",&choix5);
                                        while (choix5 < 1 || choix5 > 1)
                                        {
                                            reset(14,14,col,col+50);
                                            gotoligcol(12,col);
                                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                            gotoligcol(14,col);
                                            fflush(stdin);
                                            scanf("%d",&choix5);
                                        }
                                        reset(4,20,col,col+80);
                                        if (choix5 == 1)
                                        {
                                                menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                                //hypotheque ou vendre des proprietes ou elimine
                                                if ((*joueurActuel).argent >= 50)
                                                {
                                                    gotoligcol(6,col);
                                                    printf("Vous  payez l'amende de 50 dollards.");
                                                    gotoligcol(8,col);
                                                    printf("Vous etes libre !");
                                                    (*joueurActuel).argent -= 50;
                                                    (*joueurActuel).nbrTours = 0;
                                                    gotoligcol(10,col);
                                                    printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                                }
                                                else if ((*joueurActuel).argent < 50)
                                                {
                                                    //hypotheque ou vendre des proprietes ou elimine
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        ///pas d'argent et pas de double et acheter une carte sortie
                        else if (choix3== 2)
                        {
                            gotoligcol(6,col);
                            printf("Discutez du prix entre vous. (oral)");
                            gotoligcol(7,col);
                            printf("Si vous avez un accord, saisissez le montant de l'achat");
                            gotoligcol(8,col);
                            printf("Sinon, saisissez un chiffre negatif");
                            gotoligcol(9,col);
                            fflush(stdin);
                            scanf("%d", &prix);
                            if (prix >= 0)
                            {
                                (*joueurActuel).argent = joueurCartePrison.argent - prix;
                                joueurCartePrison.argent = joueurCartePrison.argent + prix;
                                joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                                trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                                gotoligcol(12,col);
                                printf("Vous avez achete la carte sortie de prison pour %d dollards.", prix);
                                gotoligcol(13,col);
                                printf("Vous etes libre !");                                (*joueurActuel).nbrTours = 0;

                            }
                            ///pas d'argent et pas de double et pas de carte sortie
                            else if (prix < 0)
                            {
                                gotoligcol(12,col);
                                printf("Vous n'avez pas trouve d'accord, vous avez un choix :");
                                gotoligcol(13,col);
                                printf("1. Vendre une propriete.");
                                gotoligcol(14,col);
                                printf("2. Lancer un double sur le prochain tour.");
                                gotoligcol(15,col);
                                fflush(stdin);
                                scanf("%d",&choix4);
                                while (choix4 < 1 || choix4 > 2)
                                {
                                    reset(15,15,col,col+50);
                                    gotoligcol(12,col);
                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez 2 choix :");
                                    gotoligcol(15,col);
                                    fflush(stdin);
                                    scanf("%d",&choix4);
                                }
                                reset(4,20,col,col+80);
                                if (choix4 == 1)
                                {
                                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                    //hypotheque ou vendre des proprietes ou elimine
                                    if ((*joueurActuel).argent >= 50)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous  payez l'amende de 50 dollards.");
                                        gotoligcol(8,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).argent -= 50;
                                        (*joueurActuel).nbrTours = 0;
                                        gotoligcol(10,col);
                                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                    }
                                    else if ((*joueurActuel).argent < 50)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous n'avez pas assez d'argent, vous avez un choix :");
                                        gotoligcol(7,col);
                                        printf("1. Lancer un double pour sortir.");
                                        gotoligcol(8,col);
                                        fflush(stdin);
                                        scanf("%d",&choix5);
                                        while (choix5 < 1 || choix5 > 1)
                                        {
                                            reset(8,8,col,col+50);
                                            gotoligcol(6,col);
                                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                            gotoligcol(8,col);
                                        }
                                        reset(4,15,col,col+80);
                                        if (choix5 == 1)
                                        {
                                            doubles = lancerDesPrison(&doubles, 6);
                                            if (doubles == 1)
                                            {
                                                gotoligcol(6,col);
                                                printf("Vous etes libre !");
                                                (*joueurActuel).nbrTours = 0;
                                            }
                                            else if (doubles == 0)
                                            {
                                                gotoligcol(12,col);
                                                printf("Dommage vous n'avez pas trouve d'accord, vous avez un choix :");
                                                gotoligcol(13,col);
                                                printf("1. Vendre une propriete.");
                                                gotoligcol(14,col);
                                                fflush(stdin);
                                                scanf("%d", &choix6);
                                                while (choix6 < 1 || choix6 > 2)
                                                {
                                                    reset(14,14,col,col+50);
                                                    gotoligcol(12,col);
                                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                                    gotoligcol(14,col);
                                                    fflush(stdin);
                                                    scanf("%d",&choix6);
                                                }
                                                reset(4,25,col,col+80);
                                                if (choix6 == 1)
                                                {
                                                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                                    //hypotheque ou vendre des proprietes ou elimine
                                                    if ((*joueurActuel).argent >= 50)
                                                    {
                                                        gotoligcol(6,col);
                                                        printf("Vous  payez l'amende de 50 dollards.");
                                                        gotoligcol(8,col);
                                                        printf("Vous etes libre !");
                                                        (*joueurActuel).argent -= 50;
                                                        (*joueurActuel).nbrTours = 0;
                                                        gotoligcol(10,col);
                                                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                                    }
                                                    else if ((*joueurActuel).argent < 50)
                                                    {
                                                        //hypotheque ou vendre des proprietes ou elimine
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                else if (choix4 == 2)
                                {
                                    doubles = lancerDesPrison(&doubles, 6);
                                    if (doubles == 1)
                                    {
                                        gotoligcol(13,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).nbrTours = 0;
                                    }
                                    else if (doubles == 0)
                                    {
                                        gotoligcol(13,col);
                                        printf("Dommage vous n'avez pas fait de double, vous avez un choix :");
                                        gotoligcol(14,col);
                                        printf("1. Vendre une propriete.");
                                        gotoligcol(15,col);
                                        fflush(stdin);
                                        scanf("%d", &choix5);
                                        while (choix5 < 1 || choix5 > 1)
                                        {
                                            reset(15,15,col,col+50);
                                            gotoligcol(13,col);
                                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                            gotoligcol(15,col);
                                            fflush(stdin);
                                            scanf("%d",&choix5);
                                        }
                                        reset(4,20,col,col+80);
                                        if (choix5 == 1)
                                                menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                                //hypotheque ou vendre des proprietes ou elimine
                                                if ((*joueurActuel).argent >= 50)
                                                {
                                                    gotoligcol(6,col);
                                                    printf("Vous  payez l'amende de 50 dollards.");
                                                    gotoligcol(8,col);
                                                    printf("Vous etes libre !");
                                                    (*joueurActuel).argent -= 50;
                                                    (*joueurActuel).nbrTours = 0;
                                                    gotoligcol(10,col);
                                                    printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                                }
                                                else if ((*joueurActuel).argent < 50)
                                                {
                                                    //hypotheque ou vendre des proprietes ou elimine
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }



                ///pas d'argent et acheter une carte
                else if (choix2 == 3)
                {
                    gotoligcol(6,col);
                    printf("Discutez du prix entre vous. (oral)");
                    gotoligcol(7,col);
                    printf("Si vous avez un accord, saisissez le montant de l'achat");
                    gotoligcol(8,col);
                    printf("Sinon, saisissez un chiffre negatif");
                    gotoligcol(9,col);
                    fflush(stdin);
                    scanf("%d", &prix);
                    if (prix >= 0)
                    {
                        (*joueurActuel).argent = joueurCartePrison.argent - prix;
                        joueurCartePrison.argent = joueurCartePrison.argent + prix;
                        joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                        trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                        gotoligcol(12,col);
                        printf("Vous avez achete la carte sortie de prison pour %d dollards.", prix);
                        gotoligcol(13,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                    }
                    ///pas d'argent et pas de carte sortie de prison
                    else if (prix < 0)
                    {
                        gotoligcol(12,col);
                        printf("Vous n'avez pas trouve d'accord, vous avez 2 choix :");
                        gotoligcol(13,col);
                        printf("1. Lancer un double pour sortir.");
                        gotoligcol(14,col);
                        printf("2. Vendre une propriete.");
                        gotoligcol(15,col);
                        fflush(stdin);
                        scanf("%d",&choix3);
                        while (choix3 < 1 || choix3 > 2)
                        {
                            reset(15,15,col,col+50);
                            gotoligcol(12,col);
                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez 2 choix :");
                            gotoligcol(15,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                        }
                        reset(4,25,col,col+80);
                        if (choix3 == 1)
                        {
                            doubles = lancerDesPrison(&doubles, 6);
                            if (doubles == 1)
                            {
                                gotoligcol(6,col);
                                printf("Vous etes libre !");
                                (*joueurActuel).nbrTours = 0;
                            }
                            else if (doubles == 0)
                            {
                                gotoligcol(6,col);
                                printf("Vous n'avez pas pas fait de double, vous avez un choix :");
                                gotoligcol(7,col);
                                printf("1. Vendre une propriete. ");
                                gotoligcol(8,col);
                                fflush(stdin);
                                scanf("%d",&choix4);
                                while (choix4 < 1 || choix4 > 1)
                                {
                                    reset(8,8,col,col+50);
                                    gotoligcol(6,col);
                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                    gotoligcol(8,col);
                                    fflush(stdin);
                                    scanf("%d",&choix4);
                                }
                                reset(4,20,col,col+80);
                                if (choix4 == 1)
                                {
                                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                    //hypotheque ou vendre des proprietes ou elimine
                                    if ((*joueurActuel).argent >= 50)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous  payez l'amende de 50 dollards.");
                                        gotoligcol(8,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).argent -= 50;
                                        (*joueurActuel).nbrTours = 0;
                                        gotoligcol(10,col);
                                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                    }
                                    else if ((*joueurActuel).argent < 50)
                                    {
                                        //hypotheque ou vendre des proprietes ou elimine
                                    }
                                }
                            }
                        }
                        }
                        else if (choix3 == 2)
                        {
                            menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                            //hypotheque
                            //lancer ?
                            if ((*joueurActuel).argent >= 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous  payez l'amende de 50 dollards.");
                                gotoligcol(8,col);
                                printf("Vous etes libre !");
                                (*joueurActuel).argent -= 50;
                                (*joueurActuel).nbrTours = 0;
                                gotoligcol(10,col);
                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                            }
                            else if ((*joueurActuel).argent < 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous n'avez pas assez d'argent, vous avez un choix :");
                                gotoligcol(7,col);
                                printf("1. Lancer un double sur le prochain tour.");
                                gotoligcol(8,col);
                                fflush(stdin);
                                scanf("%d",&choix4);
                                while (choix4 < 1 || choix4 > 2)
                                {
                                    reset(8,8,col,col+50);
                                    gotoligcol(6,col);
                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                    gotoligcol(8,col);
                                    fflush(stdin);
                                    scanf("%d",&choix4);
                                }
                                reset(4,20,col,col+80);
                                if (choix4 == 1)
                                {
                                    doubles = lancerDesPrison(&doubles, 6);
                                    if (doubles == 1)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).nbrTours = 0;
                                        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
                                    }
                                    else if (doubles == 0)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous n'avez pas pas fait de double, vous avez un choix :");
                                        gotoligcol(7,col);
                                        printf("1. Vendre une propriete. ");
                                        gotoligcol(8,col);
                                        fflush(stdin);
                                        scanf("%d",&choix4);
                                        while (choix4 < 1 || choix4 > 1)
                                        {
                                            reset(8,8,col,col+50);
                                            gotoligcol(6,col);
                                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                            gotoligcol(8,col);
                                            fflush(stdin);
                                            scanf("%d",&choix4);
                                        }
                                        reset(4,20,col,col+80);
                                        if (choix4 == 1)
                                        {
                                            menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                            //hypotheque ou vendre des proprietes ou elimine
                                            if ((*joueurActuel).argent >= 50)
                                            {
                                                gotoligcol(6,col);
                                                printf("Vous  payez l'amende de 50 dollards.");
                                                gotoligcol(8,col);
                                                printf("Vous etes libre !");
                                                (*joueurActuel).argent -= 50;
                                                (*joueurActuel).nbrTours = 0;
                                                gotoligcol(10,col);
                                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                            }
                                            else if ((*joueurActuel).argent < 50)
                                            {
                                                //hypotheque ou vendre des proprietes ou elimine
                                            }
                                        }

                                    }
                                }
                            }
                        }
                    }
                }




        ///lancer
        else if (choix == 2)
        {
            doubles = lancerDesPrison(&doubles, 6);
            if (doubles == 1)
            {
                gotoligcol(13,col);
                printf("Vous etes libre !");
                (*joueurActuel).nbrTours = 0;
                (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
            }
            ///pas de double
            else if (doubles == 0)
            {
                gotoligcol(13,col);
                printf("Dommage vous n'avez pas fait de double, vous avez 2 choix :");
                gotoligcol(14,col);
                printf("1. Payer une amende de 50 dollards.");
                gotoligcol(15,col);
                printf("2. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
                gotoligcol(16,col);
                fflush(stdin);
                scanf("%d", &choix2);
                while (choix2 < 1 || choix2 > 2)
                {
                    reset(16,16,col,col+50);
                    gotoligcol(13,col);
                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez 2 choix :");
                    gotoligcol(16,col);
                    fflush(stdin);
                    scanf("%d",&choix2);
                }
                reset(4,25,col,col+80);
                ///pas de double et payer
                if (choix2 == 1)
                {
                    if ((*joueurActuel).argent >= 50)
                    {
                        gotoligcol(6,col);
                        printf("Vous  payez l'amende de 50 dollards.");
                        gotoligcol(8,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).argent -= 50;
                        (*joueurActuel).nbrTours = 0;
                        gotoligcol(10,col);
                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                    }
                    ///pas de double et pas d'argent
                    else if ((*joueurActuel).argent < 50)
                    {
                        gotoligcol(6,col);
                        printf("Dommage vous n'avez pas assez d'argent, vous avez 2 choix :");
                        gotoligcol(7,col);
                        printf("1. Vendre une propriete.");
                        gotoligcol(8,col);
                        printf("2. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
                        gotoligcol(9,col);
                        fflush(stdin);
                        scanf("%d", &choix3);
                        while (choix3 < 1 || choix3 > 2)
                        {
                            reset(9,9,col,col+50);
                            gotoligcol(6,col);
                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez 2 choix :");
                            gotoligcol(9,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                        }
                        reset(4,20,col,col+80);
                        ///pas d'argent et pas de doubles et vendre
                        if (choix3 == 1)
                        {
                            menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                            //hypotheque ou vendre des proprietes
                            if ((*joueurActuel).argent >= 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous  payez l'amende de 50 dollards.");
                                gotoligcol(8,col);
                                printf("Vous etes libre !");
                                (*joueurActuel).argent -= 50;
                                (*joueurActuel).nbrTours = 0;
                                gotoligcol(10,col);
                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                            }
                            else if ((*joueurActuel).argent < 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous n'avez pas assez d'argent, vous avez un choix :");
                                gotoligcol(7,col);
                                printf("1. Acheter une carte sortir de prison a %s et l'utiliser.", (joueurCartePrison).prenom);
                                gotoligcol(8,col);
                                fflush(stdin);
                                scanf("%d",&choix5);
                                while (choix5 < 1 || choix5 > 1)
                                {
                                    reset(8,8,col,col+50);
                                    gotoligcol(6,col);
                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                    gotoligcol(8,col);
                                    fflush(stdin);
                                    scanf("%d",&choix5);
                                }
                                reset(4,15,col,col+80);
                                if (choix5 == 1)
                                {
                                    gotoligcol(6,col);
                                    printf("Discutez du prix entre vous. (oral)");
                                    gotoligcol(7,col);
                                    printf("Si vous avez un accord, saisissez le montant de l'achat");
                                    gotoligcol(8,col);
                                    printf("Sinon, saisissez un chiffre negatif");
                                    gotoligcol(9,col);
                                    fflush(stdin);
                                    scanf("%d", &prix);
                                    if (prix >= 0)
                                    {
                                        (*joueurActuel).argent = joueurCartePrison.argent - prix;
                                        joueurCartePrison.argent = joueurCartePrison.argent + prix;
                                        joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                                        trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                                        gotoligcol(12,col);
                                        printf("Vous avez achete la carte sortie de prison pour %d dollards.", prix);
                                        gotoligcol(13,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).nbrTours = 0;

                                    }
                                    ///pas d'argent et pas de double et pas de carte sortie
                                    else if (prix < 0)
                                    {
                                        gotoligcol(12,col);
                                        printf("Vous n'avez pas trouve d'accord, vous avez un choix :");
                                        gotoligcol(13,col);
                                        printf("1. Vendre une propriete.");
                                        gotoligcol(14,col);
                                        fflush(stdin);
                                        scanf("%d",&choix6);
                                        while (choix6 < 1 || choix6 > 1)
                                        {
                                            reset(14,14,col,col+50);
                                            gotoligcol(12,col);
                                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                            gotoligcol(14,col);
                                            fflush(stdin);
                                            scanf("%d",&choix6);
                                        }
                                        reset(4,20,col,col+80);
                                        if (choix6 == 1)
                                        {
                                            menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                            //hypotheque ou vendre des proprietes ou elimine
                                            if ((*joueurActuel).argent >= 50)
                                            {
                                                gotoligcol(6,col);
                                                printf("Vous  payez l'amende de 50 dollards.");
                                                gotoligcol(8,col);
                                                printf("Vous etes libre !");
                                                (*joueurActuel).argent -= 50;
                                                (*joueurActuel).nbrTours = 0;
                                                gotoligcol(10,col);
                                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                            }
                                            else if ((*joueurActuel).argent < 50)
                                            {
                                                //hypotheque ou vendre des proprietes ou elimine
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                        ///pas d'argent et pas de double et acheter une carte sortie
                        else if (choix3== 2)
                        {
                            gotoligcol(6,col);
                            printf("Discutez du prix entre vous. (oral)");
                            gotoligcol(7,col);
                            printf("Si vous avez un accord, saisissez le montant de l'achat");
                            gotoligcol(8,col);
                            printf("Sinon, saisissez un chiffre negatif");
                            gotoligcol(9,col);
                            fflush(stdin);
                            scanf("%d", &prix);
                            if (prix >= 0)
                            {
                                (*joueurActuel).argent = joueurCartePrison.argent - prix;
                                joueurCartePrison.argent = joueurCartePrison.argent + prix;
                                joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                                trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                                gotoligcol(12,col);
                                printf("Vous avez achete la carte sortie de prison pour %d dollards.", prix);
                                gotoligcol(13,col);
                                printf("Vous etes libre !");
                                (*joueurActuel).nbrTours = 0;

                            }
                            ///pas d'argent et pas de double et pas de carte sortie
                            else if (prix < 0)
                            {
                                gotoligcol(6,col);
                                printf("Vous n'avez pas trouve d'accord, vous avez un choix :");
                                gotoligcol(7,col);
                                printf("1. Vendre une propriete. ");
                                gotoligcol(8,col);
                                fflush(stdin);
                                scanf("%d",&choix4);
                                while (choix4 < 1 || choix4 > 1)
                                {
                                    reset(8,8,col,col+50);
                                    gotoligcol(6,col);
                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                    gotoligcol(8,col);
                                    fflush(stdin);
                                    scanf("%d",&choix4);
                                }
                                reset(4,10,col,col+80);
                                if (choix4 == 1)
                                {
                                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                    //hypotheque ou vendre des proprietes ou elimine
                                    if ((*joueurActuel).argent >= 50)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous  payez l'amende de 50 dollards.");
                                        gotoligcol(8,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).argent -= 50;
                                        (*joueurActuel).nbrTours = 0;
                                        gotoligcol(10,col);
                                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                    }
                                    else if ((*joueurActuel).argent < 50)
                                    {
                                        //hypotheque ou vendre des proprietes ou elimine
                                    }
                                }
                            }
                        }
                    }
                }
                ///pas de double et acheter carte sortie de prison
                else if (choix2 == 2)
                {
                    gotoligcol(6,col);
                    printf("Discutez du prix entre vous. (oral)");
                    gotoligcol(7,col);
                    printf("Si vous avez un accord, saisissez le montant de l'achat");
                    gotoligcol(8,col);
                    printf("Sinon, saisissez un chiffre negatif");
                    gotoligcol(9,col);
                    fflush(stdin);
                    scanf("%d", &prix);
                    if (prix >= 0)
                    {
                        (*joueurActuel).argent = joueurCartePrison.argent - prix;
                        joueurCartePrison.argent = joueurCartePrison.argent + prix;
                        joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                        trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                        gotoligcol(12,col);
                        printf("Vous avez achete la carte sortie de prison pour %d dollards.", prix);
                        gotoligcol(13,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                    }
                    else if (prix < 0)
                    {
                        gotoligcol(12,col);
                        printf("Vous n'avez pas trouve d'accord, vous avez un choix :");
                        gotoligcol(13,col);
                        printf("1. Payer une amende de 50 dollards.");
                        gotoligcol(14,col);
                        fflush(stdin);
                        scanf("%d",&choix3);
                        while (choix3 < 1 || choix3 > 1)
                        {
                            reset(14,14,col,col+50);
                            gotoligcol(12,col);
                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                            gotoligcol(14,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                        }
                        reset(4,20,col,col+80);
                        if (choix3 == 1)
                        {
                            if ((*joueurActuel).argent >= 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous  payez l'amende de 50 dollards.");
                                gotoligcol(8,col);
                                printf("Vous etes libre !");
                                (*joueurActuel).argent -= 50;
                                (*joueurActuel).nbrTours = 0;
                                gotoligcol(10,col);
                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                            }
                            else if ((*joueurActuel).argent < 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous n'avez pas trouve d'accord, vous avez un choix :");
                                gotoligcol(7,col);
                                printf("1. Vendre une propriete.");
                                gotoligcol(8,col);
                                fflush(stdin);
                                scanf("%d",&choix4);
                                while (choix4 < 1 || choix4 > 1)
                                {
                                    reset(8,8,col,col+50);
                                    gotoligcol(6,col);
                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                    gotoligcol(8,col);
                                    fflush(stdin);
                                    scanf("%d",&choix4);
                                }
                                if (choix4 == 1)
                                {
                                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                    //hypotheque ou vendre des proprietes ou elimine
                                    if ((*joueurActuel).argent >= 50)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous  payez l'amende de 50 dollards.");
                                        gotoligcol(8,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).argent -= 50;
                                        (*joueurActuel).nbrTours = 0;
                                        gotoligcol(10,col);
                                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                    }
                                    else if ((*joueurActuel).argent < 50)
                                    {
                                        //hypotheque ou vendre des proprietes ou elimine

                                }
                            }
                        }
                    }
                }
            }
        }        ///acheter carte sortie de prison
        else if (choix == 3)
        {
            gotoligcol(6,col);
            printf("Discutez du prix entre vous. (oral)");
            gotoligcol(7,col);
            printf("Si vous avez un accord, saisissez le montant de l'achat");
            gotoligcol(8,col);
            printf("Sinon, saisissez un chiffre negatif");
            gotoligcol(9,col);
            fflush(stdin);
            scanf("%d", &prix);
            if (prix >= 0)
            {
                (*joueurActuel).argent = joueurCartePrison.argent - prix;
                joueurCartePrison.argent = joueurCartePrison.argent + prix;
                joueurCartePrison.cartePrison = joueurCartePrison.cartePrison - 1;
                trouverCarteSortiePrison2(joueurActuel, joueurCartePrison, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);
                gotoligcol(12,col);
                printf("Vous  payez l'amende de 50 dollards.");
                gotoligcol(13,col);
                printf("Vous etes libre !");
                (*joueurActuel).argent -= 50;
                (*joueurActuel).nbrTours = 0;
                gotoligcol(15,col);
                printf("Votre nouveau solde : %d", (*joueurActuel).argent);                (*joueurActuel).nbrTours = 0;
            }
            ///pas de carte sortie de prison
            else if (prix < 0)
            {
                gotoligcol(12,col);
                printf("Vous etes en prison, vous avez 2 choix :");
                gotoligcol(13,col);
                printf("1. Payer une amende de 50 dollards.");
                gotoligcol(14,col);
                printf("2. Lancer un double sur le prochain tour.");
                gotoligcol(15,col);
                fflush(stdin);
                scanf("%d",&choix2);
                while (choix2 < 1 || choix2 > 2)
                {
                    reset(15,15,col,col+50);
                    gotoligcol(12,col);
                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez 2 choix :");
                    gotoligcol(15,col);
                    fflush(stdin);
                    scanf("%d",&choix2);
                }
                reset(4,20,col,col+80);
                if (choix2 == 1)
                {
                    if ((*joueurActuel).argent >= 50)
                    {
                       gotoligcol(6,col);
                        printf("Vous  payez l'amende de 50 dollards.");
                        gotoligcol(8,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).argent -= 50;
                        (*joueurActuel).nbrTours = 0;
                        gotoligcol(10,col);
                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                    }
                    else if ((*joueurActuel).argent < 50)
                    {
                        //---//////////////////////////////--- Si le joueur n'a pas assez d'argent ---//////////////////////////////---
                        //hypotheque ou vendre des proprietes
                       gotoligcol(6,col);
                        printf("\nVous n'avez pas assez d'argent, vous avez 2 choix :");
                        gotoligcol(7,col);
                        printf("\n1. Vendre une propriete.");
                        gotoligcol(8,col);
                        printf("2. Lancer un double pour sortir.");
                        gotoligcol(9,col);
                        fflush(stdin);
                        scanf("%d",&choix3);
                        while (choix3 < 1 || choix3 > 2)
                        {
                           reset(9,9,col,col+50);
                            gotoligcol(6,col);
                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez 2 choix :");
                            gotoligcol(9,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                        }
                        reset(4,15,col,col+80);
                        if (choix3 == 2)
                        {
                            doubles = lancerDesPrison(&doubles, 6);
                            if (doubles == 1)
                            {
                                gotoligcol(6,col);
                                printf("Vous etes libre !");
                                (*joueurActuel).nbrTours = 0;
                            }
                            else if (doubles == 0)
                            {
                                gotoligcol(6,col);
                                printf("Vous n'avez pas fait de double, vous avez un choix :");
                                gotoligcol(7,col);
                                printf("1. Vendre une propriete. \n");
                                gotoligcol(8,col);
                                fflush(stdin);
                                scanf("%d",&choix4);
                                while (choix4 < 1 || choix4 > 1)
                                {
                                    reset(8,8,col,col+50);
                                    gotoligcol(6,col);
                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                    gotoligcol(8,col);
                                    fflush(stdin);
                                    scanf("%d",&choix4);
                                }
                                reset(4,10,col,col+80);
                                if (choix4 == 1)
                                {
                                     menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                    //hypotheque ou vendre des proprietes ou elimine
                                    if ((*joueurActuel).argent >= 50)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous  payez l'amende de 50 dollards.");
                                        gotoligcol(8,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).argent -= 50;
                                        (*joueurActuel).nbrTours = 0;
                                        gotoligcol(10,col);
                                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                    }
                                    else if ((*joueurActuel).argent < 50)
                                    {
                                        //hypotheque ou vendre des proprietes ou elimine
                                    }
                                }
                            }
                        }
                        else if (choix3 == 1)
                        {
                            menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                            //hypotheque ou vendre des proprietes ou elimine
                            if ((*joueurActuel).argent >= 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous  payez l'amende de 50 dollards.");
                                gotoligcol(8,col);
                                printf("Vous etes libre !");
                                (*joueurActuel).argent -= 50;
                                (*joueurActuel).nbrTours = 0;
                                gotoligcol(10,col);
                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                            }
                            else if ((*joueurActuel).argent < 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous n'avez pas assez d'argent, vous avez un choix :");
                                gotoligcol(7,col);
                                printf("1. Lancer un double pour sortir.");
                                gotoligcol(8,col);
                                fflush(stdin);
                                scanf("%d",&choix4);
                                while (choix4 < 1 || choix4 > 1)
                                {
                                    reset(8,8,col,col+50);
                                    gotoligcol(6,col);
                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                    gotoligcol(8,col);
                                    fflush(stdin);
                                    scanf("%d",&choix4);
                                }
                                reset(4,12,col,col+80);
                                if (choix4 == 1)
                                {
                                    doubles = lancerDesPrison(&doubles, 6);
                                    if (doubles == 1)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).nbrTours = 0;
                                        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
                                    }
                                    else if (doubles == 0)
                                    {

                                        gotoligcol(6,col);
                                        printf("Vous n'avez pas fait de double, vous avez un choix :");
                                        gotoligcol(7,col);
                                        printf("1. Vendre une propriete. \n");
                                        gotoligcol(8,col);
                                        fflush(stdin);
                                        scanf("%d",&choix5);
                                        while (choix5 < 1 || choix5 > 1)
                                        {
                                            reset(8,8,col,col+50);
                                            gotoligcol(6,col);
                                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                            gotoligcol(8,col);
                                            fflush(stdin);
                                            scanf("%d",&choix5);
                                        }
                                        reset(4,10,col,col+80);
                                        if (choix5 == 1)
                                        {
                                             menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                            //hypotheque ou vendre des proprietes ou elimine
                                            if ((*joueurActuel).argent >= 50)
                                            {
                                                gotoligcol(6,col);
                                                printf("Vous  payez l'amende de 50 dollards.");
                                                gotoligcol(8,col);
                                                printf("Vous etes libre !");
                                                (*joueurActuel).argent -= 50;
                                                (*joueurActuel).nbrTours = 0;
                                                gotoligcol(10,col);
                                                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                            }
                                            else if ((*joueurActuel).argent < 50)
                                            {
                                                //hypotheque ou vendre des proprietes ou elimine
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else if (choix2 == 2)
                {
                    doubles = lancerDesPrison(&doubles, 6);
                    if (doubles == 1)
                    {
                        gotoligcol(13,col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                    }
                    else if (doubles == 0)
                    {
                        gotoligcol(12,col);
                        printf("Dommage vous n'avez pas fait de double, vous avez un choix :");
                        gotoligcol(13,col);
                        printf("1. Payer une amende de 50 dollards.");
                        gotoligcol(14,col);
                        fflush(stdin);
                        scanf("%d", &choix3);
                        while (choix3 < 1 || choix3 > 1)
                        {
                            reset(14,14,col,col+50);
                            gotoligcol(12,col);
                            printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                            gotoligcol(14,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                        }
                        reset(4,15,col,col+80);
                        if (choix3 == 1)
                        {
                            if ((*joueurActuel).argent >= 50)
                            {
                                gotoligcol(6,col);
                                        printf("Vous  payez l'amende de 50 dollards.");
                                        gotoligcol(8,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).argent -= 50;
                                        (*joueurActuel).nbrTours = 0;
                                        gotoligcol(10,col);
                                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                            }
                            else if ((*joueurActuel).argent < 50)
                            {
                                gotoligcol(6,col);
                                printf("Vous n'avez pas assez d'argent, vous avez un choix :");
                                gotoligcol(7,col);
                                printf("1. Vendre une propriete.");
                                gotoligcol(8,col);
                                fflush(stdin);
                                scanf("%d", &choix4);
                                while (choix4 < 1 || choix4 > 1)
                                {
                                    reset(8,8,col,col+50);
                                    gotoligcol(6,col);
                                    printf("Demande non valide, vous n'avez pas trouve d'accord, vous avez un choix :");
                                    gotoligcol(8,col);
                                    fflush(stdin);
                                    scanf("%d",&choix4);
                                }
                                reset(4,12,col,col+80);
                                ///pas d'argent et pas de doubles et vendre
                                if (choix4 == 1)
                                {
                                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                                    //hypotheque ou vendre des proprietes ou elimine
                                    if ((*joueurActuel).argent >= 50)
                                    {
                                        gotoligcol(6,col);
                                        printf("Vous  payez l'amende de 50 dollards.");
                                        gotoligcol(8,col);
                                        printf("Vous etes libre !");
                                        (*joueurActuel).argent -= 50;
                                        (*joueurActuel).nbrTours = 0;
                                        gotoligcol(10,col);
                                        printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                                    }
                                    else if ((*joueurActuel).argent < 50)
                                    {
                                        //hypotheque ou vendre des proprietes ou elimine
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }



///--------------------------------------- Menu joueur tour < 3 avec aucune carte chance----------------------------------------
    else if ((*joueurActuel).nbrTours < 3)
    {
        gotoligcol(6, col);
        printf("Vous etes en prison, vous avez 2 choix :");
        gotoligcol(7, col);
        printf("1. Payer une amende de 50 dollards.");
        gotoligcol(8, col);
        printf("2. Lancer un double.");
        gotoligcol(9, col);
        fflush(stdin);
        scanf("%d",&choix);
        while (choix < 1 || choix > 2)
        {
            reset(9,9,col,col+50);
            gotoligcol(6, col);
            printf("Demande non valide, vous etes en prison, vous avez 2 choix :");
            gotoligcol(9, col);
            fflush(stdin);
            scanf("%d",&choix);
        }
        reset(4,9,col,col+80);
        if (choix == 1)
        {
            if ((*joueurActuel).argent >= 50)
            {
                gotoligcol(6, col);
                printf("Vous avez payer l'amende de 50 dollards. Vous etes libre !");
                (*joueurActuel).argent -= 50;
                (*joueurActuel).nbrTours = 0;
                gotoligcol(8, col);
                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                while(suite != 32)
                {
                    gotoligcol(11, col);
                    printf("Appuyez sur espace pour continuer");
                    gotoligcol(12, col);
                    fflush(stdin);
                    scanf("%c", &suite);
                    reset(12,12,col,col+50);
                }


            }
            else if ((*joueurActuel).argent < 50)
            {
                //---//////////////////////////////--- Si le joueur n'a pas assez d'argent ---//////////////////////////////---
                    //hypotheque ou vendre des proprietes
                gotoligcol(6, col);
                printf("Vous n'avez pas assez d'argent, vous avez 2 choix :");
                gotoligcol(7, col);
                printf("1. Lancer un double sur l'un des tours suivants.");
                gotoligcol(8, col);
                printf("2. Vendre une propriete.");
                gotoligcol(9, col);
                fflush(stdin);
                scanf("%d",&choix2);
                while (choix2 < 1 || choix2 > 2)
                {
                    reset(9,9,col,col+50);
                    gotoligcol(6, col);
                    printf("Demande non valide, vous n'avez pas assez d'argent, vous avez 2 choix :");
                    gotoligcol(9, col);
                    fflush(stdin);
                    scanf("%d",&choix2);
                }
                reset(4,9,col,col+80);
                if (choix2 == 1)
                {
                    doubles = lancerDesPrison(&doubles, 6);
                    if (doubles == 1)
                    {
                        gotoligcol(11, col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                        resetDuPionQuiJoue((joueurActuel));
                        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
                        affichageDuPionQuiJoue((joueurActuel));
                        while(suite != 32)
                        {
                            gotoligcol(13, col);
                            printf("Appuyez sur espace pour continuer");
                            gotoligcol(14, col);
                            fflush(stdin);
                            scanf("%c", &suite);
                            reset(14,14,col,col+50);
                        }


                    }
                    else if (doubles == 0)
                    {
                        gotoligcol(11,col);
                        printf("Dommage, vous restez en prison.");
                        while(suite != 32)
                        {
                            gotoligcol(13, col);
                            printf("Appuyez sur espace pour continuer");
                            gotoligcol(14, col);
                            fflush(stdin);
                            scanf("%c", &suite);
                            reset(14,14,col,col+50);
                        }

                    }
                }
                else if (choix2 == 2)
                {
                    menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                    //hypotheque
                }
            }
        }
        else if (choix == 2)
        {
            suite = 0;
            doubles = lancerDesPrison(&doubles, 6);
            if (doubles == 1)
            {
                gotoligcol(11,col);
                printf("Vous etes libre !");
                (*joueurActuel).nbrTours = 0;
                while(suite != 32)
                {
                    gotoligcol(13, col);
                    printf("Appuyez sur espace pour continuer");
                    gotoligcol(14, col);
                    fflush(stdin);
                    scanf("%c", &suite);
                    reset(14,14,col,col+50);
                }

            }
            else if (doubles == 0)
            {
                gotoligcol(11,col);
                printf("Dommage, vous restez en prison.");
                while(suite != 32)
                {
                    gotoligcol(13, col);
                    printf("Appuyez sur espace pour continuer");
                    gotoligcol(14, col);
                    fflush(stdin);
                    scanf("%c", &suite);
                    reset(14,14,col,col+50);
                }

            }
        }
        reset(4,15,col,col+80);
    }



///--------------------------------------- Menu joueur tour = 3 ----------------------------------------

    else if ((*joueurActuel).nbrTours == 3)
    {
        gotoligcol(6, col);
        printf("Vous etes en prison, vous avez 2 choix :");
        gotoligcol(7, col);
        printf("1. Payer une amende de 50 dollards.");
        gotoligcol(8, col);
        printf("2. Lancer un double pour votre dernier tour.");
        gotoligcol(9, col);
        fflush(stdin);
        scanf("%d",&choix);
        while (choix < 1 || choix > 2)
        {
            reset(9,9,col,col+50);
            gotoligcol(6, col);
            printf("Demande non valide, vous etes en prison, vous avez 2 choix :");
            gotoligcol(9, col);
            fflush(stdin);
            scanf("%d",&choix);
        }
        reset(4,9,col,col+80);
        if (choix == 1)
        {
            if ((*joueurActuel).argent >= 50)
            {
                gotoligcol(6, col);
                printf("Vous avez payer l'amende de 50 dollards. Vous etes libre !");
                (*joueurActuel).argent -= 50;
                (*joueurActuel).nbrTours = 0;
                gotoligcol(8, col);
                printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                while(suite != 32)
                {
                    gotoligcol(11, col);
                    printf("Appuyez sur espace pour continuer");
                    gotoligcol(12, col);
                    fflush(stdin);
                    scanf("%c", &suite);
                    reset(12,12,col,col+50);
                }


            }
            else if ((*joueurActuel).argent < 50)
            {
                //---//////////////////////////////--- Si le joueur n'a pas assez d'argent ---//////////////////////////////---
                    //hypotheque ou vendre des proprietes
                gotoligcol(6, col);
                printf("Vous n'avez pas assez d'argent, vous avez 2 choix :");
                gotoligcol(7, col);
                printf("1. Lancer un double pour votre dernier tour.");
                gotoligcol(8, col);
                printf("2. Vendre une propriete.");
                gotoligcol(9, col);
                fflush(stdin);
                scanf("%d",&choix2);
                while (choix2 < 1 || choix2 > 2)
                {
                    reset(9,9,col,col+50);
                    gotoligcol(6, col);
                    printf("Demande non valide, vous n'avez pas assez d'argent, vous avez 2 choix :");
                    gotoligcol(9, col);
                    fflush(stdin);
                    scanf("%d",&choix2);
                }
                reset(4,9,col,col+80);
                if (choix2 == 1)
                {
                    doubles = lancerDesPrison(&doubles, 6);
                    if (doubles == 1)
                    {
                        gotoligcol(11, col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                        resetDuPionQuiJoue((joueurActuel));
                        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
                        affichageDuPionQuiJoue((joueurActuel));
                        while(suite != 32)
                        {
                            gotoligcol(13, col);
                            printf("Appuyez sur espace pour continuer");
                            gotoligcol(14, col);
                            fflush(stdin);
                            scanf("%c", &suite);
                            reset(14,14,col,col+50);
                        }


                    }
                    else if (doubles == 0)
                    {
                        gotoligcol(4,col);
                        printf("Dommage vous n'avez pas assez d'argent, vous avez un choix :");
                        gotoligcol(5,col);
                        printf("1. Vendre une propriete.");
                        gotoligcol(6,col);
                        fflush(stdin);
                        scanf("%d", &choix3);
                        while (choix3 < 1 || choix3 > 1)
                        {
                            reset(6,6,col,col+50);
                            gotoligcol(4,col);
                            printf("Demande non valide, dommage vous n'avez pas assez d'argent, vous avez un choix :");
                            gotoligcol(6,col);
                            fflush(stdin);
                            scanf("%d",&choix3);
                        }
                        reset(4,6,col,col+50);
                        if (choix3 == 1)
                        {
                            //menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                            //hypotheque ou vendre des proprietes ou elimine
                        }


                        }

                    }
                }
                else if (choix2 == 2)
                {
                    ////menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                    //hypotheque
                }
            }
        }
                else if (choix == 2)
                {
                    ////menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
                    //hypotheque ou vendre des proprietes ou elimine

                    detot = lancerDesPrison(&doubles, 6);
                    if (doubles == 1)
                    {
                        gotoligcol(11, col);
                        printf("Vous etes libre !");
                        (*joueurActuel).nbrTours = 0;
                        resetDuPionQuiJoue((joueurActuel));
                        (*joueurActuel).caseActuelle = (*joueurActuel).caseActuelle + detot;
                        affichageDuPionQuiJoue((joueurActuel));
                        while(suite != 32)
                        {
                            gotoligcol(13, col);
                            printf("Appuyez sur espace pour continuer");
                            gotoligcol(14, col);
                            fflush(stdin);
                            scanf("%c", &suite);
                            reset(14,14,col,col+50);
                        }


                    }
                    else if (doubles == 0)
                    {


                        if ((*joueurActuel).argent >= 50)
                        {
                            gotoligcol(11,col);
                            printf("Vous  devez payer l'amende de 50 dollards.");
                            gotoligcol(13,col);
                            printf("Vous etes enfin libre !");
                            (*joueurActuel).argent -= 50;
                            gotoligcol(13,col);
                            (*joueurActuel).nbrTours = 0;
                            printf("Votre nouveau solde : %d", (*joueurActuel).argent);
                        while(suite != 32)
                        {
                            gotoligcol(16, col);
                            printf("Appuyez sur espace pour continuer");
                            gotoligcol(17, col);
                            fflush(stdin);
                            scanf("%c", &suite);
                            reset(17,17,col,col+50);
                        }


                        }
                        else if ((*joueurActuel).argent < 50)
                        {
                            //hypotheque ou vendre des proprietes ou elimine
                        }
                    }
                }
                reset(4,15,col,col+80);



}

///----------------------------------- copier ca pour appeler--------------------------------
//menuPrison(joueurActuel, maxdouble, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
