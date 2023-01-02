#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>



#include "Structures.h"


///------------------------------------------------------------- PION --------------------------------------------------------------------
//permet de retourner le charactere spécial (pion) en fonction du chiffre choisi qui correspondant à ce pion (choix)
char choix(choix, pion)
{
    switch (choix)
    {
    case 1 :
        {
            pion = 0x01;
            break;
        }
    case 2 :
        {
            pion = 0x02;
            break;
        }
    case 3 :
        {
            pion = 0x03;
            break;
        }
    case 4 :
        {
            pion = 0x04;
            break;
        }
    case 5 :
        {
            pion = 0x05;
            break;
        }
    case 6 :
        {
            pion = 0x06;
            break;
        }
    case 7 :
        {
            pion = 0x0B;
            break;
        }
    case 8 :
        {
            pion = 0x0C;
            break;
        }
    case 9 :
        {
            pion = 0x0F;
            break;
        }

    }
    return pion;


}





///----------------CHOISIR SON PION------------------


char choisirPion(int nbrJoueur, struct joueur *joueur1, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8)
{   //Sous programme de choix du pion
    int choixx = 0;
    char pion1 = 0, pion2 = 0, pion3 = 0, pion4 = 0, pion5 = 0, pion6 = 0, pion7 = 0, pion8 = 0;
    int colx, coly, ligne;
    //du premier au denier joueur faire
    for(int i = 1; i <= nbrJoueur; i++)
    {
            //faciliter l'affichage...
            if (i == 1)
            {
                Color(1,0);
                ligne = 18;
                colx = 10;
                coly = 50;
                gotoligcol(18,10);
                printf("%s", (*joueur1).prenom);

            }
            else if (i == 2)
            {
                Color(2,0);
                ligne = 18;
                colx = 60;
                coly = 100;
                gotoligcol(18,60);
                printf("%s", (*joueur2).prenom);
            }
            else if (i == 3)
            {
                Color(3,0);
                ligne = 18;
                colx = 110;
                coly = 150;
                gotoligcol(18,110);
                printf("%s", (*joueur3).prenom);
            }
            else if (i == 4)
            {
                Color(4,0);
                ligne = 18;
                colx = 160;
                coly = 200;
                gotoligcol(18,160);
                printf("%s", (*joueur4).prenom);
            }
            else if (i == 5)
            {
                Color(5,0);
                ligne = 38;
                colx = 10;
                coly = 50;
                gotoligcol(38,10);
                printf("%s", (*joueur5).prenom);
            }
            else if (i == 6)
            {
                Color(6,0);
                ligne = 38;
                colx = 60;
                coly = 100;
                gotoligcol(38,60);
                printf("s", (*joueur6).prenom);
            }
            else if (i == 7)
            {
                Color(7,0);
                ligne = 38;
                colx = 110;
                coly = 150;
                gotoligcol(38,110);
                printf("%s", (*joueur7).prenom);
            }
            else if (i == 8)
            {
                Color(8,0);
                ligne = 38;
                colx = 160;
                coly = 200;
                gotoligcol(38,160);
                printf("%s", (*joueur8).prenom);
            }


            //affichage pour proposer les pions disponibles à l'utilisateur
            printf(" veuillez choisir votre pion :");
            gotoligcol((ligne+1),colx);
            printf("1.\t%c", 0x01);
            gotoligcol((ligne+2),colx);
            printf("2.\t%c", 0x02);
            gotoligcol((ligne+3),colx);
            printf("3.\t%c", 0x03);
            gotoligcol((ligne+4),colx);
            printf("4.\t%c", 0x04);
            gotoligcol((ligne+5),colx);
            printf("5.\t%c", 0x05);
            gotoligcol((ligne+6),colx);
            printf("6.\t%c", 0x06);
            gotoligcol((ligne+7),colx);
            printf("7.\t%c", 0x0B);
            gotoligcol((ligne+8),colx);
            printf("8.\t%c", 0x0C);
            gotoligcol((ligne+9),colx);
            printf("9.\t%c", 0x0F);
            gotoligcol((ligne+10),colx);
            fflush(stdin);
            scanf("%d", &choixx);
            //blindage pion n'existe pas
            while(choixx <= 0 || choixx >= 10)
            {
                reset((ligne+10),(ligne+10),colx,coly);
                gotoligcol((ligne-1),colx);
                printf("Ce pion est indisponible");
                gotoligcol((ligne+10),colx);
                fflush(stdin);
                scanf("%d", &choixx);
            }

            //blindage pion deja utilise
            while ((*joueur1).pion == choixx || (*joueur2).pion == choixx || (*joueur3).pion == choixx || (*joueur4).pion == choixx || (*joueur5).pion == choixx || (*joueur6).pion == choixx || (*joueur7).pion == choixx)
            {
                reset((ligne+10),(ligne+10),colx,coly);
                gotoligcol((ligne-1),colx);
                printf("Ce pion est indisponible");
                gotoligcol((ligne+10),colx);
                fflush(stdin);
                scanf("%d", &choixx);
                //blindage pion n'existe pas
                while(choixx <= 0 || choixx >= 10)
                {
                    reset((ligne+10),(ligne+10),colx,coly);
                    gotoligcol((ligne+10),colx);
                    fflush(stdin);
                    scanf("%d", &choixx);
                }


            }

        //pour permettre à tous les joueurs de la partie que leur pion choisi aille dans la structure de leur joueur
        switch (i)
        {
            case 1 :
            {
                pion1 = choix(choixx, pion1);
                (*joueur1).pion = pion1;
                break;
            }
            case 2 :
            {
                pion2 = choix(choixx, pion2);
                (*joueur2).pion = pion2;
                break;
            }
            case 3 :
            {
                pion3 = choix(choixx, pion3);
                (*joueur3).pion = pion3;
                break;
            }
            case 4:
            {
                pion4 = choix(choixx, pion4);
                (*joueur4).pion = pion4;
                break;
            }
            case 5 :
            {
                pion5 = choix(choixx, pion5);
                (*joueur5).pion = pion5;
                break;
            }
            case 6:
            {
                pion6 = choix(choixx, pion6);
                (*joueur6).pion = pion6;
                break;
            }
            case 7:
            {
                pion7 = choix(choixx, pion7);
                (*joueur7).pion = pion7;
                break;
            }
            case 8 :
            {
                pion8 = choix(choixx, pion8);
                (*joueur8).pion = pion8;
                break;
            }

        }
    }
    Color(15,0);

}







///----------------------------------------- REMPLISSAGE ---------------------------------------------


struct joueur remplissage(struct joueur *nom, int numeroPassage, char prenom [15])
{ //Sous programme de remplissage de structures joueurs au debut de la partie
    strcpy((*nom).prenom, prenom);
    (*nom).argent = 1500;
    (*nom).nbrProprietes = 0;
    (*nom).cartePrison = 0;
    (*nom).OrdreDePassage = numeroPassage;
    (*nom).caseActuelle = 1;
    (*nom).enJeu = 1;
    (*nom).nbrTours = 0;
};





///--------------------------------------- AFFICHAGE -------------------------------------------------
//case actuelle
void affichageCaseActuelle (int caseActuelle)
{   //Sous programme d'affichage de la case actuelle d'un joueur a tout moment de la partie
    if (caseActuelle == 1)
    {
        printf("Case Actuelle : Case depart");
    }
    else if (caseActuelle == 2)
    {
        printf("Case Actuelle : Gdynia");
    }
    else if (caseActuelle == 3)
    {
        printf("Case Actuelle : Impot sur le revenu");
    }
    else if (caseActuelle == 4)
    {
        printf("Case Actuelle : Taipei");
    }
    else if (caseActuelle == 5)
    {
        printf("Case Actuelle : Case chance numero 1");
    }
    else if (caseActuelle == 6)
    {
        printf("Case Actuelle : Tokyo");
    }
    else if (caseActuelle == 7)
    {
        printf("Case Actuelle : Barcelone");
    }
    else if (caseActuelle == 8)
    {
        printf("Case Actuelle : Athene");
    }
    else if (caseActuelle == 9)
    {
        printf("Case Actuelle : Prison et visite simple");
    }
    else if (caseActuelle == 10)
    {
        printf("Case Actuelle : Istanbul");
    }
    else if (caseActuelle == 11)
    {
        printf("Case Actuelle : Kyiv");
    }
    else if (caseActuelle == 12)
    {
        printf("Case Actuelle : Toronto");
    }
    else if (caseActuelle == 13)
    {
        printf("Case Actuelle : Case caisse de communaute numero 1");
    }
    else if (caseActuelle == 14)
    {
        printf("Case Actuelle : Rome");
    }
    else if (caseActuelle == 15)
    {
        printf("Case Actuelle : Shanghai");
    }
    else if (caseActuelle == 16)
    {
        printf("Case Actuelle : Vancouver");
    }
    else if (caseActuelle == 17)
    {
        printf("Case Actuelle : Parc gratuit");
    }
    else if (caseActuelle == 18)
    {
        printf("Case Actuelle : Sydney");
    }
    else if (caseActuelle == 19)
    {
        printf("Case Actuelle : New York");
    }
    else if (caseActuelle == 20)
    {
        printf("Case Actuelle : Londres");
    }
    else if (caseActuelle == 21)
    {
        printf("Case Actuelle : Case chance numero 2");
    }
    else if (caseActuelle == 22)
    {
        printf("Case Actuelle : Beijing");
    }
    else if (caseActuelle == 23)
    {
        printf("Case Actuelle : Hong Kong");
    }
    else if (caseActuelle == 24)
    {
        printf("Case Actuelle : Jerusalem");
    }
    else if (caseActuelle == 25)
    {
        printf("Case Actuelle : Aller en prison");
    }
    else if (caseActuelle == 26)
    {
        printf("Case Actuelle : Paris");
    }
    else if (caseActuelle == 27)
    {
        printf("Case Actuelle : Belgrade");
    }
    else if (caseActuelle == 28)
    {
        printf("Case Actuelle : Le Cap");
    }
    else if (caseActuelle == 29)
    {
        printf("Case Actuelle : Case caisse de communaute numero 2");
    }
    else if (caseActuelle == 30)
    {
        printf("Case Actuelle : Riga");
    }
    else if (caseActuelle == 31)
    {
        printf("Case Actuelle : Taxe de Luxe");
    }
    else if (caseActuelle == 32)
    {
        printf("Case Actuelle : Montreal");
    }
}


//propriétés du joueurs
void affichageJoueur (struct joueur *nom)   //Sous programme d'affichage de la structure joueur
{   
    int col = 130;
    gotoligcol(4,col);
    printf("Prenom : %s",(*nom).prenom);
    gotoligcol(5,col);
    printf("Argent : %d dollars",(*nom).argent);
    gotoligcol(6,col);
    printf("Nombre de proprietes : %d",(*nom).nbrProprietes);
    gotoligcol(7,col);
    printf("Nombre de carte sortie de prison : %d\n",(*nom).cartePrison);
    gotoligcol(8,col);
    affichageCaseActuelle((*nom).caseActuelle);
}

///---------------------------------------- FIN DU JEU-----------------------------------------------------------













///---------------------------------------------------------------------------------------------------



//pour completer la structure de tous les joueurs présents
void structureJoueur(int nbrJoueurs)
{
    struct joueur joueur1;      //Creation des structures joueurs
    struct joueur joueur2;
    struct joueur joueur3;
    struct joueur joueur4;
    struct joueur joueur5;
    struct joueur joueur6;
    struct joueur joueur7;
    struct joueur joueur8;


    //Generation aleatoire de l'ordre de jeu
    srand(time(NULL));  
    int numeroPassage = rand()%(nbrJoueurs)+1;





    char banque [15] = "Banque";    //Variables pour le blindage du choix du nom du joueur
    char prenom1 [15];
    char prenom2 [15];
    char prenom3 [15];
    char prenom4 [15];
    char prenom5 [15];
    char prenom6 [15];
    char prenom7 [15];
    char prenom8 [15];

    int comparer = 0;
    int comparer1 = 0;
    int comparer2 = 0;
    int comparer3 = 0;
    int comparer4 = 0;
    int comparer5 = 0;
    int comparer6 = 0;
    int comparer7 = 0;




    //du premier au denier joueur
    for(int i=0;i<nbrJoueurs;i++)       //Blindage du choix du nom de tous les joueur en jeu
    {
        if (i == 0)
        {
            Color(1,0);
            gotoligcol(14,10);
            printf("Quel est le pseudo du joueur ?");
            gotoligcol(15,10);
            fflush(stdin);
            scanf("%s",&prenom1);
            comparer = strcmp(banque, prenom1);
            while(comparer == 0)
            {
                reset(15,15,10,50);
                gotoligcol(13,10);
                printf("Pseudo deja choisi !");
                gotoligcol(15,10);
                fflush(stdin);
                scanf("%s",&prenom1);
                comparer = strcmp(banque, prenom1);
            }
            remplissage(&joueur1, numeroPassage, prenom1);
        }
        else if (i == 1)
        {
            Color(2,0);
            if (numeroPassage == nbrJoueurs)
            {
                numeroPassage = 1;
            }
            else if (numeroPassage < nbrJoueurs)
            {
                numeroPassage = numeroPassage + 1;
            }
            gotoligcol(14,60);
            printf("Quel est le pseudo du joueur ?");
            gotoligcol(15,60);
            fflush(stdin);
            scanf("%s",&prenom2);
            comparer1 = strcmp(prenom1, prenom2);
            comparer = strcmp(banque, prenom2);
            while(comparer1 == 0 || comparer == 0)
            {
                reset(15,15,60,100);
                gotoligcol(13,60);
                printf("Pseudo deja choisi !");
                gotoligcol(15,60);
                fflush(stdin);
                scanf("%s",&prenom2);
                comparer1 = strcmp(prenom1, prenom2);
                comparer = strcmp(banque, prenom2);
            }
            remplissage(&joueur2, numeroPassage, prenom2);
        }
        else if (i == 2)
        {
            Color(3,0);
            if (numeroPassage == nbrJoueurs)
            {
                numeroPassage = 1;
            }
            else if (numeroPassage < nbrJoueurs)
            {
                numeroPassage = numeroPassage + 1;
            }
            gotoligcol(14,110);
            printf("Quel est le pseudo du joueur ?");
            gotoligcol(15,110);
            fflush(stdin);
            scanf("%s",&prenom3);
            comparer1 = strcmp(prenom1, prenom3);
            comparer2 = strcmp(prenom2, prenom3);
            comparer = strcmp(banque, prenom3);
            while(comparer1 == 0 || comparer2 == 0 || comparer == 0)
            {
                reset(15,15,110,150);
                gotoligcol(13,110);
                printf("Pseudo deja choisi !");
                gotoligcol(15,110);
                fflush(stdin);
                scanf("%s",&prenom3);
                comparer1 = strcmp(prenom1, prenom3);
                comparer2 = strcmp(prenom2, prenom3);
                comparer = strcmp(banque, prenom3);
            }
            remplissage(&joueur3, numeroPassage, prenom3);
        }
        else if (i == 3)
        {
            Color(4,0);
            if (numeroPassage == nbrJoueurs)
            {
                numeroPassage = 1;
            }
            else if (numeroPassage < nbrJoueurs)
            {
                numeroPassage = numeroPassage + 1;
            }
            gotoligcol(14,160);
            printf("Quel est le pseudo du joueur ?");
            gotoligcol(15,160);
            fflush(stdin);
            scanf("%s",&prenom4);
            comparer1 = strcmp(prenom1, prenom4);
            comparer2 = strcmp(prenom2, prenom4);
            comparer3 = strcmp(prenom3, prenom4);
            comparer = strcmp(banque, prenom4);
            while(comparer1 == 0 || comparer2 == 0 || comparer3 ==0 || comparer == 0)
            {
                reset(15,15,160,200);
                gotoligcol(13,160);
                printf("Pseudo deja choisi !");
                gotoligcol(15,160);
                fflush(stdin);
                scanf("%s",&prenom4);
                comparer1 = strcmp(prenom1, prenom4);
                comparer2 = strcmp(prenom2, prenom4);
                comparer3 = strcmp(prenom3, prenom4);
                comparer = strcmp(banque, prenom4);
            }
            remplissage(&joueur4, numeroPassage, prenom4);
        }
        else if (i == 4)
        {
            Color(5,0);
            if (numeroPassage == nbrJoueurs)
            {
                numeroPassage = 1;
            }
            else if (numeroPassage < nbrJoueurs)
            {
                numeroPassage = numeroPassage + 1;
            }
            gotoligcol(34,10);
            printf("Quel est le pseudo du joueur ?");
            gotoligcol(35,10);
            fflush(stdin);
            scanf("%s",&prenom5);
            comparer1 = strcmp(prenom1, prenom5);
            comparer2 = strcmp(prenom2, prenom5);
            comparer3 = strcmp(prenom3, prenom5);
            comparer4 = strcmp(prenom4, prenom5);
            comparer = strcmp(banque, prenom5);
            while(comparer1 == 0 || comparer2 == 0 || comparer3 ==0 || comparer4 == 0|| comparer == 0)
            {
                reset(35,35,10,50);
                gotoligcol(33,10);
                printf("Pseudo deja choisi !");
                gotoligcol(35,10);
                scanf("%s",&prenom5);
                comparer1 = strcmp(prenom1, prenom5);
                comparer2 = strcmp(prenom2, prenom5);
                comparer3 = strcmp(prenom3, prenom5);
                comparer4 = strcmp(prenom4, prenom5);
                comparer = strcmp(banque, prenom5);
            }
            remplissage(&joueur5, numeroPassage, prenom5);
        }
        else if (i == 5)
        {
            Color(6,0);
            if (numeroPassage == nbrJoueurs)
            {
                numeroPassage = 1;
            }
            else if (numeroPassage < nbrJoueurs)
            {
                numeroPassage = numeroPassage + 1;
            }
            gotoligcol(34,60);
            printf("Quel est le pseudo du joueur ?");
            gotoligcol(35,60);
            fflush(stdin);
            scanf("%s",&prenom6);
            comparer1 = strcmp(prenom1, prenom6);
            comparer2 = strcmp(prenom2, prenom6);
            comparer3 = strcmp(prenom3, prenom6);
            comparer4 = strcmp(prenom4, prenom6);
            comparer5 = strcmp(prenom5, prenom6);
            comparer = strcmp(banque, prenom6);
            while(comparer1 == 0 || comparer2 == 0 || comparer3 ==0 || comparer4 == 0 || comparer5 == 0|| comparer == 0)
            {
                reset(35,35,60,100);
                gotoligcol(33,60);
                printf("Pseudo deja choisi !");
                gotoligcol(35,60);
                fflush(stdin);
                scanf("%s",&prenom6);
                comparer1 = strcmp(prenom1, prenom6);
                comparer2 = strcmp(prenom2, prenom6);
                comparer3 = strcmp(prenom3, prenom6);
                comparer4 = strcmp(prenom4, prenom6);
                comparer5 = strcmp(prenom5, prenom6);
                comparer = strcmp(banque, prenom6);
            }
            remplissage(&joueur6, numeroPassage, prenom6);
        }
        else if (i == 6)
        {
            Color(7,0);
            if (numeroPassage == nbrJoueurs)
            {
                numeroPassage = 1;
            }
            else if (numeroPassage < nbrJoueurs)
            {
                numeroPassage = numeroPassage + 1;
            }
            gotoligcol(34,110);
            printf("Quel est le pseudo du joueur ?");
            gotoligcol(35,110);
            fflush(stdin);
            scanf("%s",&prenom7);
            comparer1 = strcmp(prenom1, prenom7);
            comparer2 = strcmp(prenom2, prenom7);
            comparer3 = strcmp(prenom3, prenom7);
            comparer4 = strcmp(prenom4, prenom7);
            comparer5 = strcmp(prenom5, prenom7);
            comparer6 = strcmp(prenom6, prenom7);
            comparer = strcmp(banque, prenom7);
            while(comparer1 == 0 || comparer2 == 0 || comparer3 ==0 || comparer4 == 0 || comparer5 == 0 || comparer6 == 0 || comparer == 0)
            {
                reset(35,35,110,150);
                gotoligcol(33,110);
                printf("Pseudo deja choisi !");
                gotoligcol(35,110);
                fflush(stdin);
                scanf("%s",&prenom7);
                comparer1 = strcmp(prenom1, prenom7);
                comparer2 = strcmp(prenom2, prenom7);
                comparer3 = strcmp(prenom3, prenom7);
                comparer4 = strcmp(prenom4, prenom7);
                comparer5 = strcmp(prenom5, prenom7);
                comparer6 = strcmp(prenom6, prenom7);
                comparer = strcmp(banque, prenom7);
            }
            remplissage(&joueur7, numeroPassage, prenom7);
        }
        else if (i == 7)
        {
            Color(8,0);
            if (numeroPassage == nbrJoueurs)
            {
                numeroPassage = 1;
            }
            else if (numeroPassage < nbrJoueurs)
            {
                numeroPassage = numeroPassage + 1;
            }
            gotoligcol(34,160);
            printf("Quel est le pseudo du joueur ?");
            gotoligcol(35,160);
            fflush(stdin);
            scanf("%s",&prenom8);
            comparer1 = strcmp(prenom1, prenom8);
            comparer2 = strcmp(prenom2, prenom8);
            comparer3 = strcmp(prenom3, prenom8);
            comparer4 = strcmp(prenom4, prenom8);
            comparer5 = strcmp(prenom5, prenom8);
            comparer6 = strcmp(prenom6, prenom8);
            comparer7 = strcmp(prenom7, prenom8);
            comparer = strcmp(banque, prenom8);
            while(comparer1 == 0 || comparer2 == 0 || comparer3 ==0 || comparer4 == 0 || comparer5 == 0 || comparer6 == 0 || comparer7 == 0 || comparer == 0)
            {
                reset(35,35,160,200);
                gotoligcol(33,160);
                printf("Pseudo deja choisi !");
                gotoligcol(35,160);
                fflush(stdin);
                scanf("%s",&prenom8);
                comparer1 = strcmp(prenom1, prenom8);
                comparer2 = strcmp(prenom2, prenom8);
                comparer3 = strcmp(prenom3, prenom8);
                comparer4 = strcmp(prenom4, prenom8);
                comparer5 = strcmp(prenom5, prenom8);
                comparer6 = strcmp(prenom6, prenom8);
                comparer7 = strcmp(prenom7, prenom8);
                comparer = strcmp(banque, prenom8);
            }
            remplissage(&joueur8, numeroPassage, prenom8);
        }
        Color(15,0);
    }



    //Creation et remplissage de toutes les structures proprietes
    struct proprietes Gdynia    = {"Gdynia",     2, 60, 2, 10, 30, 90, 160, 250, 30, 50, "Banque", "Marron", 0, 0};
    struct proprietes Taipei    = {"Taipei",     4, 60, 4, 20, 60, 180, 320, 450, 30, 50, "Banque", "Marron", 0, 0};
    struct proprietes Tokyo     = {"Tokyo",      6, 100, 6, 30, 90, 270, 400, 550, 50, 50, "Banque", "BleuCiel",0, 0};
    struct proprietes Barcelone = {"Barcelone",  7, 100, 6, 30, 90, 270, 400, 550, 50, 50, "Banque", "BleuCiel", 0, 0};
    struct proprietes Athenes   = {"Athene",     8, 120, 8, 40, 100, 300, 450, 600, 60, 50, "Banque", "BleuCiel",0, 0};
    struct proprietes Istanbul  = {"Istanbul",   10, 140, 10, 50, 150, 450, 625, 750, 70, 100, "Banque", "Rose", 0,0};
    struct proprietes Kyiv      = {"Kyiv",       11, 140, 10, 50, 150, 450, 625, 750, 70, 100, "Banque", "Rose", 0,0};
    struct proprietes Toronto   = {"Toronto",    12, 160, 12, 60, 180, 500, 700, 900, 80, 100, "Banque", "Rose", 0,0};
    struct proprietes Rome      = {"Rome",       14, 180, 14, 70, 200, 550, 750, 950, 90, 100, "Banque", "Orange", 0,0};
    struct proprietes Shanghai  = {"Shanghai",   15, 180, 14, 70, 200, 550, 750, 950, 90, 100, "Banque", "Orange", 0,0};
    struct proprietes Vancouver = {"Vancouver",  16, 200, 16, 80, 220, 600, 800, 1000, 100, 100, "Banque", "Orange", 0,0};
    struct proprietes Sydney    = {"Sydney",     18, 220, 18, 90, 250, 700, 875, 1050, 110, 150, "Banque", "Rouge", 0,0};
    struct proprietes NewYork   = {"NewYork",   19, 220, 18, 90, 250, 700, 875, 1050, 110, 150, "Banque", "Rouge", 0,0};
    struct proprietes Londres   = {"Londres",    20, 240, 20, 100, 300, 750, 925, 1100, 120, 150, "Banque", "Rouge", 0,0};
    struct proprietes Beijing   = {"Beijing",    22, 260, 22, 110, 330, 800, 975, 1150, 130, 150, "Banque", "Jaune", 0,0};
    struct proprietes HongKong  = {"HongKong",  23, 260, 22, 110, 330, 800, 975, 1150, 130, 150, "Banque", "Jaune", 0,0};
    struct proprietes Jerusalem = {"Jerusalem",  24, 280, 24, 120, 360, 850, 1025, 1200, 140, 150, "Banque", "Jaune", 0,0};
    struct proprietes Paris     = {"Paris",      26, 300, 26, 130, 390, 900, 1100, 1275, 150, 200, "Banque", "Verte", 0,0};
    struct proprietes Belgrade  = {"Belgrade",   27, 300, 26, 130, 390, 900, 1100, 1275, 150, 200, "Banque", "Verte", 0,0};
    struct proprietes LeCap     = {"LeCap",     28, 320, 28, 150, 450, 1000, 1200, 1400, 160, 200, "Banque", "Verte", 0,0};
    struct proprietes Riga      = {"Riga",       30, 350, 35, 175, 500, 1100, 1300, 1500, 175, 200, "Banque", "Bleu", 0,0};
    struct proprietes Montreal  = {"Montreal",   32, 400, 50, 200, 600, 1400, 1700, 2000, 200, 200, "Banque", "Bleu", 0,0};










    ////finJeu(nbrJoueurs, joueur1, joueur2, joueur3, joueur4, joueur5, joueur6, joueur7, joueur8);



    choisirPion(nbrJoueurs, &joueur1, &joueur2, &joueur3, &joueur4, &joueur5, &joueur6, &joueur7, &joueur8);


    reset(0,100,0,210);     //Reset de l'ecran
    
    
    int tour = 0;           //Initialisation de variables utiles pour certaines fonctionnalitées du jeu
    int NbHotels = 0;
    int NbMaisons = 0;
    int quitter = 0;


        for(int i=1;i<nbrJoueurs+1;i++)      //On appelle le sous programme du menu de jeu en fonction de l'ordre de passage de chaque joueur
        {
            if (joueur1.OrdreDePassage == i)
            {
                quitter = MenuJoueur(&NbHotels, &NbMaisons, tour, nbrJoueurs, &joueur1, &joueur1, &joueur2, &joueur3, &joueur4, &joueur5, &joueur6, &joueur7, &joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur2.OrdreDePassage == i)
            {
                quitter = MenuJoueur(&NbHotels, &NbMaisons, tour, nbrJoueurs, &joueur2, &joueur1,&joueur2, &joueur3, &joueur4, &joueur5, &joueur6, &joueur7, &joueur8,&Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur3.OrdreDePassage == i)
            {
                quitter = MenuJoueur(&NbHotels, &NbMaisons, tour, nbrJoueurs, &joueur3, &joueur1, &joueur2, &joueur3,&joueur4, &joueur5, &joueur6, &joueur7, &joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur4.OrdreDePassage == i)
            {
                quitter = MenuJoueur(&NbHotels, &NbMaisons, tour, nbrJoueurs, &joueur4, &joueur1, &joueur2, &joueur3, &joueur4,&joueur5, &joueur6, &joueur7, &joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur5.OrdreDePassage == i)
            {
                quitter = MenuJoueur(&NbHotels, &NbMaisons, tour, nbrJoueurs, &joueur5, &joueur1, &joueur2, &joueur3, &joueur4, &joueur5,&joueur6, &joueur7, &joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur6.OrdreDePassage == i)
            {
                quitter = MenuJoueur(&NbHotels, &NbMaisons, tour, nbrJoueurs, &joueur6, &joueur1, &joueur2, &joueur3, &joueur4, &joueur5, &joueur6,&joueur7, &joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur7.OrdreDePassage == i)
            {
                quitter = MenuJoueur(&NbHotels, &NbMaisons, tour, nbrJoueurs, &joueur7, &joueur1, &joueur2, &joueur3, &joueur4, &joueur5, &joueur6, &joueur7,&joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            else if (joueur8.OrdreDePassage == i)
            {
                quitter = MenuJoueur(&NbHotels, &NbMaisons, tour, nbrJoueurs, &joueur8, &joueur1, &joueur2, &joueur3, &joueur4, &joueur5, &joueur6, &joueur7,&joueur8, &Gdynia, &Taipei, &Tokyo, &Barcelone, &Athenes, &Istanbul, &Kyiv, &Toronto, &Rome, &Shanghai, &Vancouver, &Sydney, &NewYork, &Londres, &Beijing, &HongKong, &Jerusalem, &Paris, &Belgrade, &LeCap, &Riga, &Montreal);
                if (quitter == 1)
                {
                    return 0;
                }
            }
            tour = tour + 1;
        }
}









//permet de reset toutes les positions possibles ou peut être situé n'importe quel pion au cours de la partie
void resetPion()
{
    //case 1
    gotoligcol(4,1);
    printf("           ");
    //case 2
    gotoligcol(3,14);
    printf("           ");
    //case 3
    gotoligcol(4,27);
    printf("           ");
    //case 4
    gotoligcol(3,40);
    printf("           ");
    //case 5
    gotoligcol(4,53);
    printf("           ");
    //case 6
    gotoligcol(3,66);
    printf("           ");
    //case 7
    gotoligcol(3,79);
    printf("           ");
    //case 8
    gotoligcol(3,92);
    printf("           ");
    //case 9
    gotoligcol(4,105);
    printf("           ");
    //case 10
    gotoligcol(8,105);
    printf("           ");
    //case 11
    gotoligcol(13,105);
    printf("           ");
    //case 12
    gotoligcol(18,105);
    printf("           ");
    //case 13
    gotoligcol(24,105);
    printf("           ");
    //case 14
    gotoligcol(28,105);
    printf("           ");
    //case 15
    gotoligcol(33,105);
    printf("           ");
    //case 16
    gotoligcol(38,105);
    printf("           ");
    //case 17
    gotoligcol(44,105);
    printf("           ");
    //case 18
    gotoligcol(43,92);
    printf("           ");
    //case 19
    gotoligcol(43,79);
    printf("           ");
    //case 20
    gotoligcol(43,66);
    printf("           ");
    //case 21
    gotoligcol(44,53);
    printf("           ");
    //case 22
    gotoligcol(43,40);
    printf("           ");
    //case 23
    gotoligcol(43,27);
    printf("           ");
    //case 24
    gotoligcol(43,14);
    printf("           ");
    //case 25
    gotoligcol(44,1);
    printf("           ");
    //case 26
    gotoligcol(38,1);
    printf("           ");
    //case 27
    gotoligcol(32,1);
    printf("           ");
     //case 28
    gotoligcol(28,1);
    printf("           ");
    //case 29
    gotoligcol(24,1);
    printf("           ");
    //case 30
    gotoligcol(18,1);
    printf("           ");
    //case 31
    gotoligcol(14,1);
    printf("           ");
    //case 32
    gotoligcol(8,1);
    printf("           ");

}
