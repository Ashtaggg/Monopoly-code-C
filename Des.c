#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


///affichage contour d'un dé en généram
void de(int x, int y)
{
    gotoligcol(x,y);
    int i, j;
    printf("%c", 0xDA);
    for (i = 0; i <= 8; i++)
    {
        printf("%c", 0xC4);
    }
    printf("%c", 0xBF);
    for (i = 1; i <= 3; i++)
    {
        gotoligcol((x+i), y);
        printf("%c", 0xB3);
        for(j = 9; j >= 1; j--)
        {
            printf(" ");
        }
        printf("%c", 0xB3);
    }
    gotoligcol(x+4,y);
    printf("%c", 0xC0);
    for (i = 0; i <= 8; i++)
    {
        printf("%c", 0xC4);
    }
    printf("%c", 0xD9);
}


///dé1 affichage
void den1(int x, int y)
{
    de(x,y);
    gotoligcol((x+2),(y+5));
    printf("*");
}


///dé2 affichage
void den2(int x, int y)
{
    de(x,y);
    gotoligcol((x+1),(y+8));
    printf("*");
    gotoligcol((x+3),(y+2));
    printf("*");
}


///dé3 affichage
void den3(int x, int y)
{
    de(x,y);
    gotoligcol((x+1),(y+8));
    printf("*");
    gotoligcol((x+2),(y+5));
    printf("*");
    gotoligcol((x+3),(y+2));
    printf("*");
}


///dé4 affichage
void den4(int x, int y)
{
    de(x,y);
    gotoligcol((x+1),(y+2));
    printf("*     *");
    gotoligcol((x+3),(y+2));
    printf("*     *");
}


///dé5 affichage
void den5(int x, int y)
{
    de(x,y);
    gotoligcol((x+1),(y+2));
    printf("*     *");
    gotoligcol((x+2),(y+5));
    printf("*");
    gotoligcol((x+3),(y+2));
    printf("*     *");
}


///dé6 affichage
void den6(int x, int y)
{
    de(x,y);
    gotoligcol((x+1),(y+2));
    printf("*     *");
    gotoligcol((x+2),(y+2));
    printf("*     *");
    gotoligcol((x+3),(y+2));
    printf("*     *");
}

///Chiffre aléatoire entre 1 et 6 pour chacun des dés puis affichage
void dealeatoire(int* de1, int* de2, int x, int y)
{
    srand(time(NULL));
    *de1 = 6 - rand()%(1 - 6);           ///chiffre aléatoire dé1
    *de2 = 6 - rand()%(0 - 6);           ///chiffre aléatoire dé2

    switch(*de1)                         ///affichage premier dé en fonction du nombre aleatoire que l'on aura tiré
    {
        case 1 :
        {
            den1(x,y);
            break;
        }
        case 2 :
        {
            den2(x,y);
            break;
        }
        case 3 :
        {
            den3(x,y);
            break;
        }
        case 4 :
        {
            den4(x,y);
            break;
        }
        case 5 :
        {
            den5(x,y);
            break;
        }
        case 6 :
        {
            den6(x,y);
        break;
        }
    }
    switch (*de2)                       ///idem avec le deuxieme dé
    {
        case 1 :
        {
            den1(x,y+14);
            break;
            }
        case 2 :
        {
            den2(x,y+14);
            break;
        }
        case 3 :
        {
            den3(x,y+14);
            break;
        }
        case 4 :
        {
            den4(x,y+14);
            break;
        }
        case 5 :
        {
            den5(x,y+14);
            break;
        }
        case 6 :
        {
            den6(x,y+14);
            break;
        }
    }

}











///fonction pour lancer les dés
int lancer(int detot, int* maxdouble, int lig)
{
    int de1, de2;
    int col = 150;
    char fin;
    //blindage
    while (fin != 32)
    {
        gotoligcol(lig-3, col-20);
        printf("Pour lancer les des appuyer sur la touche espace puis entree !");
        gotoligcol(lig-2, col-20);
        fflush(stdin);
        scanf("%c", &fin);
        reset(lig-2,lig-2,col-20,col+20);

    }
    if (fin == 32)
    {
        dealeatoire(&de1, &de2, lig-1,col);     //sous programme qui créé des dés aléatoirement puis les affiche

    }
    detot = de1 + de2;


    //si il y a des doubles (au maximun on aura le droit de faire 3 double sous peine d'aller en prison)
    if (de1 == de2 && *maxdouble <= 2)
    {
        *maxdouble = *maxdouble + 1;
    }
    return detot;//retourne le total de tous les des qu'on a lancé
}




int mainDes(int* maxdouble, int lig)
{
    int detot = 0;
    int col = 130;
    detot = lancer(detot, maxdouble, lig);
    gotoligcol(lig+5,col);
    printf("Vous allez avancer de %d cases, ", detot);
    if(detot <= 6)
    {
        printf("dommage...");
    }
    else if(detot >= 12)
    {
        printf("quelle chance !!!");
    }
    else
    {
        printf("pas mal.");
    }
    return detot;
}







int lancerDesPrison(int detot, int lig)
{
    int de1, de2;
    int col = 150;
    char fin;
    //blindage
    while (fin != 32)
    {
        gotoligcol(lig-3, col-20);
        printf("Pour lancer les des appuyer sur la touche espace puis entree !");
        gotoligcol(lig-2, col-20);
        fflush(stdin);
        scanf("%c", &fin);
        reset(lig-2,lig-2,col-20,col+20);

    }
    if (fin == 32)
    {
        dealeatoire(&de1, &de2, lig-1,col);

    }

    if (de1 == de2)
    {
        detot = 1;
    }
    else
    {
        detot = 0;
    }

    return detot;//retourne le total de tous les des qu'on a lancé
}
