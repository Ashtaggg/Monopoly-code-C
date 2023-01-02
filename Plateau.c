#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


#include "Structures.h"


///fonction couleur, donné par les professeurs
/*
0 : Noir
1 : Bleu foncé
2 : Vert foncé
3 : Turquoise
4 : Rouge foncé
5 : Violet
6 : Vert caca d'oie
7 : Gris clair
8 : Gris foncé
9 : Bleu fluo
10 : Vert fluo
11 : Turquoise
12 : Rouge fluo
13 : Violet 2
14 : Jaune
15 : Blanc
*/
void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}




///fonction case de base
//permet d'afficher une case (les contours)
void Case(int x, int y)
{
    gotoligcol(x,y);  //curseur
    int i, j;
    printf("%c", 0xDA);  //affichage angle gauche haut
    for (i = 0; i <= 11; i++)
    {
        printf("%c", 0xC4);  //affichage haut case
    }
    printf("%c", 0xBF);  //affichage angle droit haut
    for (i = 1; i <= 4; i++)
    {
        gotoligcol((x+i), y);
        printf("%c", 0xB3); // affichage cote gauche
        for(j = 12; j >= 1; j--)
        {
            printf(" ");  //affichage milieu case
        }
        printf("%c", 0xB3);  //affichage cote droit
    }
    gotoligcol(x+5,y);  //affichage angle gauche bas
    printf("%c", 0xC0);
    for (i = 0; i <= 11; i++)
    {
        printf("%c", 0xC4);  //affichage bas case
    }
    printf("%c", 0xD9);  //affichage angle droit bas

}



///--------------------------------------------------AFFICHAGE DES 32 CASES-------------------------------------------------------------------

//reutilisation du contour de la case puis ajout des elements necessaires à l'interieur meme de cette case

void case1()
{
    Case(0,0);
    gotoligcol(1,4);
    printf("DEPART");
    gotoligcol(2,3);
    printf("========>");
    gotoligcol(0,13);
    printf("%c", 0xC2);
    gotoligcol(5,13);
    printf("%c", 0xC5);
    gotoligcol(5,0);
    printf("%c", 0xC3);


}

void case2()
{
    Case(0,13);
    gotoligcol(0,13);
    printf("%c", 0xC2);
    gotoligcol(5,13);
    printf("%c", 0xC5);
    gotoligcol(0,26);
    printf("%c", 0xC2);
    gotoligcol(5,26);
    printf("%c", 0xC1);




    for(int i = 14; i <= 25; i++)
    {
        gotoligcol(1,i);
        Color(13,0);
        printf("%c", 0xDB);
    }
    Color(15,13);
    gotoligcol(1,17);
    printf("Gdynia");
    Color(15,0);


}

void case3()
{
    Case(0,26);
    gotoligcol(0,26);
    printf("%c", 0xC2);
    gotoligcol(5,26);
    printf("%c", 0xC1);
    gotoligcol(0,39);
    printf("%c", 0xC2);
    gotoligcol(5,39);
    printf("%c", 0xC1);
    gotoligcol(1,28);
    printf("IMPOT SUR");
    gotoligcol(2,28);
    printf("LE REVENU");



}

void case4()
{
    Case(0,39);
    gotoligcol(0,39);
    printf("%c", 0xC2);
    gotoligcol(5,39);
    printf("%c", 0xC1);
    gotoligcol(0,52);
    printf("%c", 0xC2);
    gotoligcol(5,52);
    printf("%c", 0xC1);
    for(int i = 40; i <= 51; i++)
    {
        gotoligcol(1,i);
        Color(13,0);
        printf("%c", 0xDB);
    }
    gotoligcol(1,43);
    Color(15,13);
    printf("Taipei");
    Color(15,0);


}

void case5()
{
    Case(0,52);
    gotoligcol(0,52);
    printf("%c", 0xC2);
    gotoligcol(5,52);
    printf("%c", 0xC1);
    gotoligcol(0,65);
    printf("%c", 0xC2);
    gotoligcol(5,65);
    printf("%c", 0xC1);

    gotoligcol(1,56);
    printf("CHANCE");
    gotoligcol(2,53);
    printf(" ? ? ? ? ? ?");



}

void case6()
{
    Case(0,65);
    gotoligcol(0,65);
    printf("%c", 0xC2);
    gotoligcol(5,65);
    printf("%c", 0xC1);
    gotoligcol(0,78);
    printf("%c", 0xC2);
    gotoligcol(5,78);
    printf("%c", 0xC1);
    for(int i = 66; i <= 77; i++)
    {
        gotoligcol(1,i);
        Color(11,0);
        printf("%c", 0xDB);
    }
    gotoligcol(1,69);
    Color(0,11);
    printf("Tokyo");
    Color(15,0);

}

void case7()
{
    Case(0,78);
    gotoligcol(0,78);
    printf("%c", 0xC2);
    gotoligcol(5,78);
    printf("%c", 0xC1);
    gotoligcol(0,91);
    printf("%c", 0xC2);
    gotoligcol(5,91);
    printf("%c", 0xC1);
    for(int i = 79; i <= 90; i++)
    {
        gotoligcol(1,i);
        Color(11,0);
        printf("%c", 0xDB);
        Color(15,0);
    }
    gotoligcol(1,80);
    Color(0,11);
    printf("Barcelone");
    Color(15,0);

}

void case8()
{
    Case(0,91);
    gotoligcol(0,91);
    printf("%c", 0xC2);
    gotoligcol(5,91);
    printf("%c", 0xC1);
    gotoligcol(0,104);
    printf("%c", 0xC2);
    gotoligcol(5,104);
    printf("%c", 0xC5);
    for(int i = 92; i <= 103; i++)
    {
        gotoligcol(1,i);
        Color(11,0);
        printf("%c", 0xDB);
        Color(15,0);
    }
    gotoligcol(1,95);
    Color(0,11);
    printf("Athenes");
    Color(15,0);

}

void case9()
{
    Case(0,104);
    gotoligcol(0,104);
    printf("%c", 0xC2);
    gotoligcol(5,104);
    printf("%c", 0xC5);
    gotoligcol(5,117);
    printf("%c", 0xB4);

    gotoligcol(2,105);
    printf("%c", 0xDA);
    for(int i = 0; i < 10; i++)
    {
        printf("%c", 0xC2);
    }
    printf("%c", 0xBF);



    gotoligcol(3,105);
    printf("%c", 0xC0);
    for(int i = 0; i < 10; i++)
    {
        printf("%c", 0xC1);
    }
    printf("%c", 0xD9);

    gotoligcol(1,106);
    printf("EN PRISON");
}

void case10()
{
    Case(5,104);
    gotoligcol(5,104);
    printf("%c", 0xC5);
    gotoligcol(5,117);
    printf("%c", 0xB4);
    gotoligcol(10,104);
    printf("%c", 0xC3);
    gotoligcol(10,117);
    printf("%c", 0xB4);
    for(int i = 105; i <= 116; i++)
    {
        Color(5,0);
        gotoligcol(6,i);
        printf("%c", 0xDB);
    }
    gotoligcol(6,107);
    Color(15,5);
    printf("Istanbul");
    Color(15,0);

}

void case11()
{
    Case(10,104);
    gotoligcol(10,104);
    printf("%c", 0xC3);
    gotoligcol(10,117);
    printf("%c", 0xB4);
    gotoligcol(15,104);
    printf("%c", 0xC3);
    gotoligcol(15,117);
    printf("%c", 0xB4);
    for(int i = 105; i <= 116; i++)
    {
        Color(5,0);
        gotoligcol(11,i);
        printf("%c", 0xDB);
    }
    gotoligcol(11,109);
    Color(15,5);
    printf("Kyiv");
    Color(15,0);

}

void case12()
{
    Case(15,104);
    gotoligcol(15,104);
    printf("%c", 0xC3);
    gotoligcol(15,117);
    printf("%c", 0xB4);
    gotoligcol(20,104);
    printf("%c", 0xC3);
    gotoligcol(20,117);
    printf("%c", 0xB4);
    for(int i = 105; i <= 116; i++)
    {
        Color(5,0);
        gotoligcol(16,i);
        printf("%c", 0xDB);
    }
    gotoligcol(16,108);
    Color(15,5);
    printf("Toronto");
    Color(15,0);

}

void case13()
{
    Case(20,104);
    gotoligcol(20,104);
    printf("%c", 0xC3);
    gotoligcol(20,117);
    printf("%c", 0xB4);
    gotoligcol(25,104);
    printf("%c", 0xC3);
    gotoligcol(25,117);
    printf("%c", 0xB4);

    gotoligcol(21,106);
    printf("COMMUNAUTE");
    gotoligcol(22,106);
    printf("%c %c %c %c %c %c", 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E);

}

void case14()
{
    Case(25,104);
    gotoligcol(25,104);
    printf("%c", 0xC3);
    gotoligcol(25,117);
    printf("%c", 0xB4);
    gotoligcol(30,104);
    printf("%c", 0xC3);
    gotoligcol(30,117);
    printf("%c", 0xB4);
    for(int i = 105; i <= 116; i++)
    {
        Color(6,0);
        gotoligcol(26,i);
        printf("%c", 0xDB);
    }
    gotoligcol(26,109);
    Color(15,6);
    printf("Rome");
    Color(15,0);

}

void case15()
{
    Case(30,104);
    gotoligcol(30,104);
    printf("%c", 0xC3);
    gotoligcol(30,117);
    printf("%c", 0xB4);
    gotoligcol(35,104);
    printf("%c", 0xC3);
    gotoligcol(35,117);
    printf("%c", 0xB4);
    for(int i = 105; i <= 116; i++)
    {
        Color(6,0);
        gotoligcol(31,i);
        printf("%c", 0xDB);
    }
    gotoligcol(31,108);
    Color(15,6);
    printf("Shangai");
    Color(15,0);

}

void case16()
{
    Case(35,104);
    gotoligcol(35,104);
    printf("%c", 0xC3);
    gotoligcol(35,117);
    printf("%c", 0xB4);
    gotoligcol(40,104);
    printf("%c", 0xC5);
    gotoligcol(40,117);
    printf("%c", 0xB4);
    for(int i = 105; i <= 116; i++)
    {
        Color(6,0);
        gotoligcol(36,i);
        printf("%c", 0xDB);
    }
    gotoligcol(36,107);
    Color(15,6);
    printf("Vancouver");
    Color(15,0);

}

void case17()
{
    Case(40,104);
    gotoligcol(40,104);
    printf("%c", 0xC5);
    gotoligcol(40,117);
    printf("%c", 0xB4);
    gotoligcol(45,104);
    printf("%c", 0xC1);

    gotoligcol(41,109);
    printf("PARC");
    gotoligcol(42,108);
    printf("GRATUIT");

}

void case18()
{
    Case(40,91);
    gotoligcol(40,104);
    printf("%c", 0xC5);
    gotoligcol(45,104);
    printf("%c", 0xC1);
    gotoligcol(40,91);
    printf("%c", 0xC2);
    gotoligcol(45,91);
    printf("%c", 0xC1);
    for(int i = 92; i <= 103; i++)
    {
        gotoligcol(41,i);
        Color(4,0);
        printf("%c", 0xDB);
    }
    gotoligcol(41,95);
    Color(15,4);
    printf("Sydney");
    Color(15,0);
}

void case19()
{
    Case(40,78);
    gotoligcol(40,91);
    printf("%c", 0xC2);
    gotoligcol(45,91);
    printf("%c", 0xC1);
    gotoligcol(40,78);
    printf("%c", 0xC2);
    gotoligcol(45,78);
    printf("%c", 0xC1);
    for(int i = 79; i <= 90; i++)
    {
        gotoligcol(41,i);
        Color(4,0);
        printf("%c", 0xDB);
    }
    gotoligcol(41,81);
    Color(15,4);
    printf("New York");
    Color(15,0);
}

void case20()
{
    Case(40,65);
    gotoligcol(40,78);
    printf("%c", 0xC2);
    gotoligcol(45,78);
    printf("%c", 0xC1);
    gotoligcol(40,65);
    printf("%c", 0xC2);
    gotoligcol(45,65);
    printf("%c", 0xC1);
    for(int i = 66; i <= 77; i++)
    {
        gotoligcol(41,i);
        Color(4,0);
        printf("%c", 0xDB);
    }
    gotoligcol(41,69);
    Color(15,4);
    printf("Londres");
    Color(15,0);
}

void case21()
{
    Case(40,52);
    gotoligcol(40,65);
    printf("%c", 0xC2);
    gotoligcol(45,65);
    printf("%c", 0xC1);
    gotoligcol(40,52);
    printf("%c", 0xC2);
    gotoligcol(45,52);
    printf("%c", 0xC1);

    gotoligcol(41,56);
    printf("CHANCE");
    gotoligcol(42,53);
    printf(" ? ? ? ? ? ?");


}

void case22()
{
    Case(40,39);
    gotoligcol(40,52);
    printf("%c", 0xC2);
    gotoligcol(45,52);
    printf("%c", 0xC1);
    gotoligcol(40,39);
    printf("%c", 0xC2);
    gotoligcol(45,39);
    printf("%c", 0xC1);
    for(int i = 40; i <= 51; i++)
    {
        gotoligcol(41,i);
        Color(14,0);
        printf("%c", 0xDB);
    }
    gotoligcol(41,43);
    Color(0,14);
    printf("Beijing");
    Color(15,0);
}

void case23()
{
    Case(40,26);
    gotoligcol(40,39);
    printf("%c", 0xC2);
    gotoligcol(45,39);
    printf("%c", 0xC1);
    gotoligcol(40,26);
    printf("%c", 0xC2);
    gotoligcol(45,26);
    printf("%c", 0xC1);
    for(int i = 27; i <= 38; i++)
    {
        gotoligcol(41,i);
        Color(14,0);
        printf("%c", 0xDB);
    }
    gotoligcol(41,29);
    Color(0,14);
    printf("Hong Kong");
    Color(15,0);
}

void case24()
{
    Case(40,13);
    gotoligcol(40,26);
    printf("%c", 0xC2);
    gotoligcol(45,26);
    printf("%c", 0xC1);
    gotoligcol(40,13);
    printf("%c", 0xC5);
    gotoligcol(45,13);
    printf("%c", 0xC1);
    for(int i = 14; i <= 25; i++)
    {
        gotoligcol(41,i);
        Color(14,0);
        printf("%c", 0xDB);
    }
    gotoligcol(41,15);
    Color(0,14);
    printf("Jerusalem");
    Color(15,0);
}

void case25()
{
    Case(40,0);
    gotoligcol(40,13);
    printf("%c", 0xC5);
    gotoligcol(45,13);
    printf("%c", 0xC1);
    gotoligcol(40,0);
    printf("%c", 0xC3);

    gotoligcol(41,2);
    printf("ALLEZ EN");
    gotoligcol(42,2);
    printf("PRISON %c %c", 0x1A, 0x1A);

}

void case26()
{
    Case(35,0);
    gotoligcol(35,0);
    printf("%c", 0xC3);
    gotoligcol(35,13);
    printf("%c", 0xB4);
    gotoligcol(40,0);
    printf("%c", 0xC3);
    gotoligcol(40,13);
    printf("%c", 0xC5);
    for(int i = 1; i <= 12; i++)
    {
        gotoligcol(36,i);
        Color(10,0);
        printf("%c", 0xDB);
    }
    gotoligcol(36,4);
    Color(15,10);
    printf("Paris");
    Color(15,0);
}

void case27()
{
    Case(30,0);
    gotoligcol(30,0);
    printf("%c", 0xC3);
    gotoligcol(30,13);
    printf("%c", 0xB4);
    gotoligcol(35,0);
    printf("%c", 0xC3);
    gotoligcol(35,13);
    printf("%c", 0xB4);
    for(int i = 1; i <= 12; i++)
    {
        gotoligcol(31,i);
        Color(10,0);
        printf("%c", 0xDB);
    }
    gotoligcol(31,3);
    Color(15,10);
    printf("Belgrade");
    Color(15,0);
}

void case28()
{
    Case(25,0);
    gotoligcol(25,0);
    printf("%c", 0xC3);
    gotoligcol(25,13);
    printf("%c", 0xB4);
    gotoligcol(30,0);
    printf("%c", 0xC3);
    gotoligcol(30,13);
    printf("%c", 0xB4);
    for(int i = 1; i <= 12; i++)
    {
        gotoligcol(26,i);
        Color(10,0);
        printf("%c", 0xDB);
    }
    gotoligcol(26,4);
    Color(15,10);
    printf("Le Cap");
    Color(15,0);
}


void case29()
{
    Case(20,0);
    gotoligcol(20,0);
    printf("%c", 0xC3);
    gotoligcol(20,13);
    printf("%c", 0xB4);
    gotoligcol(25,0);
    printf("%c", 0xC3);
    gotoligcol(25,13);
    printf("%c", 0xB4);

    gotoligcol(21,2);
    printf("COMMUNAUTE");
    gotoligcol(22,2);
    printf("%c %c %c %c %c %c", 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E);
}

void case30()
{
    Case(15,0);
    gotoligcol(15,0);
    printf("%c", 0xC3);
    gotoligcol(15,13);
    printf("%c", 0xB4);
    gotoligcol(20,0);
    printf("%c", 0xC3);
    gotoligcol(20,13);
    printf("%c", 0xB4);
    for(int i = 1; i <= 12; i++)
    {
        gotoligcol(16,i);
        Color(1,0);
        printf("%c", 0xDB);
    }
    gotoligcol(16, 5);
    Color(15,1);
    printf("Riga");
    Color(15,0);
}


void case31()
{
    Case(10,0);
    gotoligcol(10,0);
    printf("%c", 0xC3);
    gotoligcol(10,13);
    printf("%c", 0xB4);
    gotoligcol(15,0);
    printf("%c", 0xC3);
    gotoligcol(15,13);
    printf("%c", 0xB4);
    gotoligcol(11,3);
    printf("TAXE  DE");
    gotoligcol(12,5);
    printf("LUXE");

}


void case32()
{
    Case(5,0);
    gotoligcol(5,0);
    printf("%c", 0xC3);
    gotoligcol(5,13);
    printf("%c", 0xC5);
    gotoligcol(10,0);
    printf("%c", 0xC3);
    gotoligcol(10,13);
    printf("%c", 0xB4);
    for(int i = 1; i <= 12; i++)
    {
        Color(1,0);
        gotoligcol(6,i);
        printf("%c", 0xDB);
    }
    gotoligcol(6,3);
    Color(15,1);
    printf("Montreal");
    Color(15,0);
}


///-----------------------------------------AFFICHAGE DE LA GLOBALITE DU PLATEAU DE JEU------------------------------------------------------------

//affiche les 32 cases de facon a qu'elle se surperpose pour former un plateau
//les cases avaient prealablement été placé à un endroit stratégique sur la console d'application


void plateau()
{
    monopoly();         //ecris monopoly a l'interieur du plateau
    chance();              //affichage emplacement carte chance
    communaute();           //affichage emplacement carte communauté
    Color(15,0);
    case1();
    case2();
    case3();
    case4();
    case5();
    case6();
    case7();
    case8();
    case9();
    case10();
    case11();
    case12();
    case13();
    case14();
    case15();
    case16();
    case17();
    case18();
    case19();
    case20();
    case21();
    case22();
    case23();
    case24();
    case25();
    case26();
    case27();
    case28();
    case29();
    case30();
    case31();
    case32();
}


///fonction qui écrit monopoly au milieu du plateau
void monopoly ()
{
    int a = 7;
    int b = 17;
    Color(4,0);
    /// M
    gotoligcol(a+1,b);
    printf("%c%c%c   //%c", 0xBA, 0x5C, 0x5C, 0xBA);
    gotoligcol(a+2,b);
    printf("%c %c%c // %c", 0xBA, 0x5C, 0x5C, 0xBA);
    gotoligcol(a+3,b);
    printf("%c  %cv/  %c", 0xBA, 0x5C, 0xBA);
    gotoligcol(a+4,b);
    printf("%c       %c", 0xBA, 0xBA);
    gotoligcol(a+5,b);
    printf("%c       %c", 0xBA, 0xBA);

    /// 0
    gotoligcol(a+4,b+11);
    printf("%c%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+5,b+11);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+6,b+11);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+7,b+11);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+8,b+11);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+9,b+11);
    printf("%c%c%c%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);

    /// N
    gotoligcol(a+8,b+22);
    printf("%c%c%c      %c", 0xBA, 0x5C, 0x5C, 0xBA);
    gotoligcol(a+9,b+22);
    printf("%c %c%c     %c", 0xBA, 0x5C, 0x5C, 0xBA);
    gotoligcol(a+10,b+22);
    printf("%c   %c%c   %c", 0xBA, 0x5C, 0x5C, 0xBA);
    gotoligcol(a+11,b+22);
    printf("%c     %c%c %c", 0xBA, 0x5C, 0x5C, 0xBA);
    gotoligcol(a+12,b+22);
    printf("%c      %c%c%c", 0xBA, 0x5C, 0x5C, 0xBA);

    /// 0
    gotoligcol(a+11,b+33);
    printf("%c%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+12,b+33);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+13,b+33);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+14,b+33);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+15,b+33);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+16,b+33);
    printf("%c%c%c%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);

    /// P
    gotoligcol(a+15,b+44);
    printf("%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+16,b+44);
    printf("%c       %c", 0xBA, 0xBA);
    gotoligcol(a+17,b+44);
    printf("%c       %c", 0xBA, 0xBA);
    gotoligcol(a+18,b+44);
    printf("%c%c%c%c%c%c%c%c%c", 0xCC, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);
    gotoligcol(a+19,b+44);
    printf("%c", 0xBA);
    gotoligcol(a+20,b+44);
    printf("%c", 0xBA);

    /// 0
    gotoligcol(a+19,b+54);
    printf("%c%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+20,b+54);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+21,b+54);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+22,b+54);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+23,b+54);
    printf("%c        %c", 0xBA, 0xBA);
    gotoligcol(a+24,b+54);
    printf("%c%c%c%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);

    /// L
    gotoligcol(a+23,b+66);
    printf("%c", 0xBA);
    gotoligcol(a+24,b+66);
    printf("%c", 0xBA);
    gotoligcol(a+25,b+66);
    printf("%c", 0xBA);
    gotoligcol(a+26,b+66);
    printf("%c", 0xBA);
    gotoligcol(a+27,b+66);
    printf("%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD);

    /// Y
    gotoligcol(a+26,b+76);
    printf(" %c%c   // ", 0x5C, 0x5C);
    gotoligcol(a+27,b+76);
    printf("  %c%c //  ", 0x5C, 0x5C);
    gotoligcol(a+28,b+76);
    printf("   %cv/    ", 0x5C);
    gotoligcol(a+29,b+80);
    printf("%c", 0xBA);
    gotoligcol(a+30,b+80);
    printf("%c", 0XBA);

}

///fonction qui affiche l'emplacement de la carte chance
void chance()
{
    Color(1,0);
    gotoligcol(7,75);
    int i, j;
    printf("%c", 0xC9);
    for (i = 0; i <= 22; i++)
    {
        printf("%c", 0xCD);
    }
    printf("%c", 0xBB);
    for (i = 1; i <= 6; i++)
    {
        gotoligcol((7+i), 75);
        printf("%c", 0xBA);
        for(j = 23; j >= 1; j--)
        {
            printf(" ");
        }
        printf("%c", 0xBA);
    }
    gotoligcol(8,77);
    printf("CHANCE");

    gotoligcol(13,75);
    printf("%c", 0xC8);
    for (i = 0; i <= 22; i++)
    {
        printf("%c", 0xCD);
    }
    printf("%c", 0xBC);
}

///fonction qui affiche l'emplacement de la carte communauté

void communaute()
{
    Color(11,0);
    gotoligcol(32,18);
    int i, j;
    printf("%c", 0xC9);
    for (i = 0; i <= 22; i++)
    {
        printf("%c", 0xCD);
    }
    printf("%c", 0xBB);
    for (i = 1; i <= 6; i++)
    {
        gotoligcol((32+i), 18);
        printf("%c", 0xBA);
        for(j = 23; j >= 1; j--)
        {
            printf(" ");
        }
        printf("%c", 0xBA);
    }
    gotoligcol(33,20);
    printf("COMMUNAUTE");

    gotoligcol(38,18);
    printf("%c", 0xC8);
    for (i = 0; i <= 22; i++)
    {
        printf("%c", 0xCD);
    }
    printf("%c", 0xBC);
}



///afficher un hotel sur le plateau
//en appelant ce sous programme, il suffit de rentrer la case actuelle du joueur concerné
//cela permettra d'afficher directement l'hotel à la case concerné.
void hotel(int x)
{
    Color(15,2); //fond vert, ecirture blanche
    switch (x)
    {
        case 2 :
            {
                gotoligcol(4,14);
                printf(" H O T E L  ");
                break;
            }
        case 4 :
            {
                gotoligcol(4,40);
                printf(" H O T E L  ");
                break;
            }
        case 6 :
            {
                gotoligcol(4,66);
                printf(" H O T E L  ");
                break;
            }
        case 7 :
            {
                gotoligcol(4,79);
                printf(" H O T E L  ");
                break;
            }
        case 8 :
            {
                gotoligcol(4,92);
                printf(" H O T E L  ");
                break;
            }
        case 10 :
            {
                gotoligcol(9,105);
                printf(" H O T E L  ");
                break;
            }
        case 11 :
            {
                gotoligcol(14,105);
                printf(" H O T E L  ");
                break;
            }
        case 12 :
            {
                gotoligcol(19,105);
                printf(" H O T E L  ");
                break;
            }
        case 14 :
            {
                gotoligcol(29,105);
                printf(" H O T E L  ");
                break;
            }
        case 15 :
            {
                gotoligcol(34,105);
                printf(" H O T E L  ");
                break;
            }
        case 16 :
            {
                gotoligcol(39,105);
                printf(" H O T E L  ");
                break;
            }
        case 18 :
            {
                gotoligcol(44,92);
                printf(" H O T E L  ");
                break;
            }
        case 19 :
            {
                gotoligcol(44,79);
                printf(" H O T E L  ");
                break;
            }
        case 20 :
            {
                gotoligcol(44,66);
                printf(" H O T E L  ");
                break;
            }
        case 22 :
            {
                gotoligcol(44,40);
                printf(" H O T E L  ");
                break;
            }
        case 23 :
            {
                gotoligcol(44,27);
                printf(" H O T E L  ");
                break;
            }
        case 24 :
            {
                gotoligcol(44,14);
                printf(" H O T E L  ");
                break;
            }
        case 26 :
            {
                gotoligcol(39,1);
                printf(" H O T E L  ");
                break;
            }
        case 27 :
            {
                gotoligcol(34,1);
                printf(" H O T E L  ");
                break;
            }
        case 28 :
            {
                gotoligcol(29,1);
                printf(" H O T E L  ");
                break;
            }
        case 30 :
            {
                gotoligcol(19,1);
                printf(" H O T E L  ");
                break;
            }
        case 32 :
            {
                gotoligcol(9,1);
                printf(" H O T E L  ");

                break;
            }

    }

    Color(15,0);

}





///afficher une maisno sur le plateau
//en appelant ce sous programme, il suffit de rentrer la case actuelle du joueur concerné
//cela permettra d'afficher directement une maison à la case concerné.

void maison1(int x)
{
    Color(15,4);
    switch (x)
    {
        case 2 :
            {
                gotoligcol(4,14);
                printf("M ");
                break;
            }
        case 4 :
            {
                gotoligcol(4,40);
                printf("M ");
                break;
            }
        case 6 :
            {
                gotoligcol(4,66);
                printf("M ");
                break;
            }
        case 7 :
            {
                gotoligcol(4,79);
                printf("M ");
                break;
            }
        case 8 :
            {
                gotoligcol(4,92);
                printf("M ");
                break;
            }
        case 10 :
            {
                gotoligcol(9,105);
                printf("M ");
                break;
            }
        case 11 :
            {
                gotoligcol(14,105);
                printf("M ");
                break;
            }
        case 12 :
            {
                gotoligcol(19,105);
                printf("M ");
                break;
            }
        case 14 :
            {
                gotoligcol(29,105);
                printf("M ");
                break;
            }
        case 15 :
            {
                gotoligcol(34,105);
                printf("M ");
                break;
            }
        case 16 :
            {
                gotoligcol(39,105);
                printf("M ");
                break;
            }
        case 18 :
            {
                gotoligcol(44,92);
                printf("M ");
                break;
            }
        case 19 :
            {
                gotoligcol(44,79);
                printf("M ");
                break;
            }
        case 20 :
            {
                gotoligcol(44,66);
                printf("M ");
                break;
            }
        case 22 :
            {
                gotoligcol(44,40);
                printf("M ");
                break;
            }
        case 23 :
            {
                gotoligcol(44,27);
                printf("M ");
                break;
            }
        case 24 :
            {
                gotoligcol(44,14);
                printf("M ");
                break;
            }
        case 26 :
            {
                gotoligcol(39,1);
                printf("M ");
                break;
            }
        case 27 :
            {
                gotoligcol(34,1);
                printf("M ");
                break;
            }
        case 28 :
            {
                gotoligcol(29,1);
                printf("M ");
                break;
            }
        case 30 :
            {
                gotoligcol(19,1);
                printf("M ");
                break;
            }
        case 32 :
            {
                gotoligcol(9,1);
                printf("M ");

                break;
            }

    }

    Color(15,0);

}


///afficher deux maisons sur le plateau
//en appelant ce sous programme, il suffit de rentrer la case actuelle du joueur concerné
//cela permettra d'afficher directement deux maisons à la case concerné.

void maison2(int x)
{

    Color(15,4);
    switch (x)
    {
        case 2 :
            {
                gotoligcol(4,14);
                printf("M  M ");
                break;
            }
        case 4 :
            {
                gotoligcol(4,40);
                printf("M  M ");
                break;
            }
        case 6 :
            {
                gotoligcol(4,66);
                printf("M  M ");
                break;
            }
        case 7 :
            {
                gotoligcol(4,79);
                printf("M  M ");
                break;
            }
        case 8 :
            {
                gotoligcol(4,92);
                printf("M  M ");
                break;
            }
        case 10 :
            {
                gotoligcol(9,105);
                printf("M  M ");
                break;
            }
        case 11 :
            {
                gotoligcol(14,105);
                printf("M  M ");
                break;
            }
        case 12 :
            {
                gotoligcol(19,105);
                printf("M  M ");
                break;
            }
        case 14 :
            {
                gotoligcol(29,105);
                printf("M  M ");
                break;
            }
        case 15 :
            {
                gotoligcol(34,105);
                printf("M  M ");
                break;
            }
        case 16 :
            {
                gotoligcol(39,105);
                printf("M  M ");
                break;
            }
        case 18 :
            {
                gotoligcol(44,92);
                printf("M  M ");
                break;
            }
        case 19 :
            {
                gotoligcol(44,79);
                printf("M  M ");
                break;
            }
        case 20 :
            {
                gotoligcol(44,66);
                printf("M  M ");
                break;
            }
        case 22 :
            {
                gotoligcol(44,40);
                printf("M  M ");
                break;
            }
        case 23 :
            {
                gotoligcol(44,27);
                printf("M  M ");
                break;
            }
        case 24 :
            {
                gotoligcol(44,14);
                printf("M  M ");
                break;
            }
        case 26 :
            {
                gotoligcol(39,1);
                printf("M  M ");
                break;
            }
        case 27 :
            {
                gotoligcol(34,1);
                printf("M  M ");
                break;
            }
        case 28 :
            {
                gotoligcol(29,1);
                printf("M  M ");
                break;
            }
        case 30 :
            {
                gotoligcol(19,1);
                printf("M  M ");
                break;
            }
        case 32 :
            {
                gotoligcol(9,1);
                printf("M  M ");

                break;
            }

    }

    Color(15,0);

}


///afficher trois maisons sur le plateau
//en appelant ce sous programme, il suffit de rentrer la case actuelle du joueur concerné
//cela permettra d'afficher directement trois maisons à la case concerné.

void maison3(int x)
{

    Color(15,4);
    switch (x)
    {
        case 2 :
            {
                gotoligcol(4,14);
                printf("M  M  M ");
                break;
            }
        case 4 :
            {
                gotoligcol(4,40);
                printf("M  M  M ");
                break;
            }
        case 6 :
            {
                gotoligcol(4,66);
                printf("M  M  M ");
                break;
            }
        case 7 :
            {
                gotoligcol(4,79);
                printf("M  M  M ");
                break;
            }
        case 8 :
            {
                gotoligcol(4,92);
                printf("M  M  M ");
                break;
            }
        case 10 :
            {
                gotoligcol(9,105);
                printf("M  M  M ");
                break;
            }
        case 11 :
            {
                gotoligcol(14,105);
                printf("M  M  M ");
                break;
            }
        case 12 :
            {
                gotoligcol(19,105);
                printf("M  M  M ");
                break;
            }
        case 14 :
            {
                gotoligcol(29,105);
                printf("M  M  M ");
                break;
            }
        case 15 :
            {
                gotoligcol(34,105);
                printf("M  M  M ");
                break;
            }
        case 16 :
            {
                gotoligcol(39,105);
                printf("M  M  M ");
                break;
            }
        case 18 :
            {
                gotoligcol(44,92);
                printf("M  M  M ");
                break;
            }
        case 19 :
            {
                gotoligcol(44,79);
                printf("M  M  M ");
                break;
            }
        case 20 :
            {
                gotoligcol(44,66);
                printf("M  M  M ");
                break;
            }
        case 22 :
            {
                gotoligcol(44,40);
                printf("M  M  M ");
                break;
            }
        case 23 :
            {
                gotoligcol(44,27);
                printf("M  M  M ");
                break;
            }
        case 24 :
            {
                gotoligcol(44,14);
                printf("M  M  M ");
                break;
            }
        case 26 :
            {
                gotoligcol(39,1);
                printf("M  M  M ");
                break;
            }
        case 27 :
            {
                gotoligcol(34,1);
                printf("M  M  M ");
                break;
            }
        case 28 :
            {
                gotoligcol(29,1);
                printf("M  M  M ");
                break;
            }
        case 30 :
            {
                gotoligcol(19,1);
                printf("M  M  M ");
                break;
            }
        case 32 :
            {
                gotoligcol(9,1);
                printf("M  M  M ");

                break;
            }

    }
    Color(15,0);

}


///afficher quatres maisons sur le plateau
//en appelant ce sous programme, il suffit de rentrer la case actuelle du joueur concerné
//cela permettra d'afficher directement quatres maisons à la case concerné.

void maison4(int x)
{
    Color(15,4);
    switch (x)
    {
        case 2 :
            {
                gotoligcol(4,14);
                printf("M  M  M  M  ");
                break;
            }
        case 4 :
            {
                gotoligcol(4,40);
                printf("M  M  M  M  ");
                break;
            }
        case 6 :
            {
                gotoligcol(4,66);
                printf("M  M  M  M  ");
                break;
            }
        case 7 :
            {
                gotoligcol(4,79);
                printf("M  M  M  M  ");
                break;
            }
        case 8 :
            {
                gotoligcol(4,92);
                printf("M  M  M  M  ");
                break;
            }
        case 10 :
            {
                gotoligcol(9,105);
                printf("M  M  M  M  ");
                break;
            }
        case 11 :
            {
                gotoligcol(14,105);
                printf("M  M  M  M  ");
                break;
            }
        case 12 :
            {
                gotoligcol(19,105);
                printf("M  M  M  M  ");
                break;
            }
        case 14 :
            {
                gotoligcol(29,105);
                printf("M  M  M  M  ");
                break;
            }
        case 15 :
            {
                gotoligcol(34,105);
                printf("M  M  M  M  ");
                break;
            }
        case 16 :
            {
                gotoligcol(39,105);
                printf("M  M  M  M  ");
                break;
            }
        case 18 :
            {
                gotoligcol(44,92);
                printf("M  M  M  M  ");
                break;
            }
        case 19 :
            {
                gotoligcol(44,79);
                printf("M  M  M  M  ");
                break;
            }
        case 20 :
            {
                gotoligcol(44,66);
                printf("M  M  M  M  ");
                break;
            }
        case 22 :
            {
                gotoligcol(44,40);
                printf("M  M  M  M  ");
                break;
            }
        case 23 :
            {
                gotoligcol(44,27);
                printf("M  M  M  M  ");
                break;
            }
        case 24 :
            {
                gotoligcol(44,14);
                printf("M  M  M  M  ");
                break;
            }
        case 26 :
            {
                gotoligcol(39,1);
                printf("M  M  M  M  ");
                break;
            }
        case 27 :
            {
                gotoligcol(34,1);
                printf("M  M  M  M  ");
                break;
            }
        case 28 :
            {
                gotoligcol(29,1);
                printf("M  M  M  M  ");
                break;
            }
        case 30 :
            {
                gotoligcol(19,1);
                printf("M  M  M  M  ");
                break;
            }
        case 32 :
            {
                gotoligcol(9,1);
                printf("M  M  M  M  ");

                break;
            }

    }
    Color(15,0);

}




void EnleverBatiment(int x)
{
    Color(15,0);
    switch (x)
    {
        case 2 :
            {
                gotoligcol(4,14);
                printf("            ");
                break;
            }
        case 4 :
            {
                gotoligcol(4,40);
                printf("            ");
                break;
            }
        case 6 :
            {
                gotoligcol(4,66);
                printf("            ");
                break;
            }
        case 7 :
            {
                gotoligcol(4,79);
                printf("            ");
                break;
            }
        case 8 :
            {
                gotoligcol(4,92);
                printf("            ");
                break;
            }
        case 10 :
            {
                gotoligcol(9,105);
                printf("            ");
                break;
            }
        case 11 :
            {
                gotoligcol(14,105);
                printf("            ");
                break;
            }
        case 12 :
            {
                gotoligcol(19,105);
                printf("            ");
                break;
            }
        case 14 :
            {
                gotoligcol(29,105);
                printf("            ");
                break;
            }
        case 15 :
            {
                gotoligcol(34,105);
                printf("            ");
                break;
            }
        case 16 :
            {
                gotoligcol(39,105);
                printf("            ");
                break;
            }
        case 18 :
            {
                gotoligcol(44,92);
                printf("            ");
                break;
            }
        case 19 :
            {
                gotoligcol(44,79);
                printf("            ");
                break;
            }
        case 20 :
            {
                gotoligcol(44,66);
                printf("            ");
                break;
            }
        case 22 :
            {
                gotoligcol(44,40);
                printf("            ");
                break;
            }
        case 23 :
            {
                gotoligcol(44,27);
                printf("            ");
                break;
            }
        case 24 :
            {
                gotoligcol(44,14);
                printf("            ");
                break;
            }
        case 26 :
            {
                gotoligcol(39,1);
                printf("            ");
                break;
            }
        case 27 :
            {
                gotoligcol(34,1);
                printf("            ");
                break;
            }
        case 28 :
            {
                gotoligcol(29,1);
                printf("            ");
                break;
            }
        case 30 :
            {
                gotoligcol(19,1);
                printf("            ");
                break;
            }
        case 32 :
            {
                gotoligcol(9,1);
                printf("            ");

                break;
            }

    }

}








///--------------------------------AFFICHAGE DE LA POSITION DE TOUS LES PIONS SUR LE PLATEAU------------------------------------


//pour cela on appelle le nombre de joueur et la structure de tous les joueurs
void positionDuPion(int nbrJoueurs, struct joueur *joueur1, struct joueur *joueur2, struct joueur *joueur3, struct joueur *joueur4, struct joueur *joueur5, struct joueur *joueur6, struct joueur *joueur7, struct joueur *joueur8)
{

    //la case actuelle de chaque joueur est attribuée à une variable
    int casej1 = (*joueur1).caseActuelle;
    int casej2 = (*joueur2).caseActuelle;
    int casej3 = (*joueur3).caseActuelle;
    int casej4 = (*joueur4).caseActuelle;
    int casej5 = (*joueur5).caseActuelle;
    int casej6 = (*joueur6).caseActuelle;
    int casej7 = (*joueur7).caseActuelle;
    int casej8 = (*joueur8).caseActuelle;


    //du premier au dernier joueur
    for(int i = 1; i <= nbrJoueurs; i++)
    {
        //on pourra donc allé uniquement aux joueuurs qui sont dans la partie et aisni les aficcher sur le plateau
        switch (i)
        {
            case 1 :
                {

                    affichageDuPion(casej1, (*joueur1).pion, (*joueur1).OrdreDePassage);
                    break;
                }
            case 2 :
                {
                    affichageDuPion(casej2, (*joueur2).pion, (*joueur2).OrdreDePassage);
                    break;
                }
            case 3 :
                {
                    affichageDuPion(casej3, (*joueur3).pion, (*joueur3).OrdreDePassage);
                    break;
                }
            case 4 :
                {
                    affichageDuPion(casej4, (*joueur4).pion, (*joueur4).OrdreDePassage);
                    break;
                }
            case 5 :
                {
                    affichageDuPion(casej5, (*joueur5).pion, (*joueur5).OrdreDePassage);
                    break;
                }
            case 6 :
                {
                    affichageDuPion(casej6, (*joueur6).pion, (*joueur6).OrdreDePassage);
                    break;
                }
            case 7 :
                {
                    affichageDuPion(casej7, (*joueur7).pion, (*joueur7).OrdreDePassage);
                    break;
                }
            case 8 :
                {
                    affichageDuPion(casej8, (*joueur8).pion, (*joueur8).OrdreDePassage);
                    break;
                }

        }
    }
}


void affichageDuPion(int caseactuelle, char pion, int i)
{
    //variable qui permettre à optimiser la place des pions sur le plateau de facon à qu'elles soient à coté et non empiler(donc on ne verrait qu'un pion au final)
    //ainsi en fonction de l'ordre du joueur, il sera placé differement
    int a = 3;
    int aa = 1;
    switch (i)
    {
        case 0:
        {
           aa = aa + 1;
           break;
        }
        case 1 :
        {
            aa = aa + 2;
            break;
        }
        case 2 :
        {
            aa = aa + 3;
            break;
        }
        case 3 :
        {
            aa = aa + 4;
            break;
        }
        case 4 :
        {
            aa = aa + 5;
            break;
        }
        case 5 :
        {
            aa = aa+ 6;
            break;
        }
        case 6 :
        {
            aa = aa+ 7;
            break;
        }
        case 7 :
        {
            aa = aa + 1;
            break;
        }
    }
    //en fonction de la case actuelle du joueur, son pion va etre directement affiché sur celle ci
    switch (caseactuelle)
    {
        case 1 :
            {
                gotoligcol((a+1),(aa));
                printf("%c", pion);
                break;
            }
        case 2 :
            {
                gotoligcol(a,aa+13);
                printf("%c", pion);
                break;
            }
        case 3 :
            {
                gotoligcol((a+1),aa+26);
                printf("%c", pion);
                break;
            }
        case 4 :
            {
                gotoligcol(a,aa+39);
                printf("%c", pion);
                break;
            }
        case 5 :
            {
                gotoligcol(a+1,aa+52);
                printf("%c", pion);
                break;
            }
        case 6 :
            {
                gotoligcol(a,aa+65);
                printf("%c", pion);
                break;
            }
        case 7 :
            {
                gotoligcol(a,aa+78);
                printf("%c", pion);
                break;
            }
        case 8 :
            {
                gotoligcol(a,aa+91);
                printf("%c", pion);
                break;
            }
        case 9 :
            {
                gotoligcol(a+1,aa+104);
                printf("%c", pion);
                break;
            }
        case 10 :
            {
                gotoligcol(a+5,aa+104);
                printf("%c", pion);
                break;
            }
        case 11 :
            {
                gotoligcol(a+10,aa+104);
                printf("%c", pion);
                break;
            }
        case 12 :
            {
                gotoligcol(a+15,aa+104);
                printf("%c", pion);
                break;
            }
        case 13 :
            {
                gotoligcol(a+21,aa+104);
                printf("%c", pion);
                break;
            }
        case 14 :
            {
                gotoligcol(a+25,aa+104);
                printf("%c", pion);
                break;
            }
        case 15 :
            {
                gotoligcol(a+30,aa+104);
                printf("%c", pion);
                break;
            }
        case 16 :
            {
                gotoligcol(a+35,aa+104);
                printf("%c", pion);
                break;
            }
        case 17 :
            {
                gotoligcol(a+41,aa+104);
                printf("%c", pion);
                break;
            }
        case 18 :
            {
                gotoligcol(a+40,aa+91);
                printf("%c", pion);
                break;
            }
        case 19 :
            {
                gotoligcol(a+40,aa+78);
                printf("%c", pion);
                break;
            }
        case 20 :
            {
                gotoligcol(a+40,aa+65);
                printf("%c", pion);
                break;
            }
        case 21 :
            {
                gotoligcol(a+41,aa+52);
                printf("%c", pion);
                break;
            }
        case 22 :
            {
                gotoligcol(a+40,aa+39);
                printf("%c", pion);
                break;
            }
        case 23 :
            {
                gotoligcol(a+40,a+26);
                printf("%c", pion);
                break;
            }
        case 24 :
            {
                gotoligcol(a+40,aa+13);
                printf("%c", pion);
                break;
            }
        case 25 :
            {
                gotoligcol(a+41,aa);
                printf("%c", pion);
                break;
            }
        case 26 :
            {
                gotoligcol(a+35,aa);
                printf("%c", pion);
                break;
            }
        case 27 :
            {
                gotoligcol(a+30,aa);
                printf("%c", pion);
                break;
            }
        case 28 :
            {
                gotoligcol(a+25,aa);
                printf("%c", pion);
                break;
            }
        case 29 :
            {
                gotoligcol(a+21,aa);
                printf("%c", pion);
                break;
            }
        case 30 :
            {
                gotoligcol(a+15,aa);
                printf("%c", pion);
                break;
            }
        case 31 :
            {
                gotoligcol(a+11,aa);
                printf("%c", pion);
                break;
            }
        case 32 :
            {
                gotoligcol(a+5,aa);
                printf("%c", pion);
                break;
            }


    }

}


void affichageDuPionQuiJoue(struct joueur *joueurActuel)
{
    //variable qui permettre à optimiser la place des pions sur le plateau de facon à qu'elles soient à coté et non empiler(donc on ne verrait qu'un pion au final)
    //ainsi en fonction de l'ordre du joueur, il sera placé differement
    char pion = (*joueurActuel).pion;
    int caseactuelle = (*joueurActuel).caseActuelle;
    int i = (*joueurActuel).OrdreDePassage;
    int a = 3;
    int aa = 1;
    switch (i)
    {
        case 0:
        {
           aa = aa + 1;
           break;
        }
        case 1 :
        {
            aa = aa + 2;
            break;
        }
        case 2 :
        {
            aa = aa + 3;
            break;
        }
        case 3 :
        {
            aa = aa + 4;
            break;
        }
        case 4 :
        {
            aa = aa + 5;
            break;
        }
        case 5 :
        {
            aa = aa+ 6;
            break;
        }
        case 6 :
        {
            aa = aa+ 7;
            break;
        }
        case 7 :
        {
            aa = aa + 1;
            break;
        }
    }
    //en fonction de la case actuelle du joueur, son pion va etre directement affiché sur celle ci
    switch (caseactuelle)
    {
        case 1 :
            {
                gotoligcol((a+1),(aa));
                printf("%c", pion);
                break;
            }
        case 2 :
            {
                gotoligcol(a,aa+13);
                printf("%c", pion);
                break;
            }
        case 3 :
            {
                gotoligcol((a+1),aa+26);
                printf("%c", pion);
                break;
            }
        case 4 :
            {
                gotoligcol(a,aa+39);
                printf("%c", pion);
                break;
            }
        case 5 :
            {
                gotoligcol(a+1,aa+52);
                printf("%c", pion);
                break;
            }
        case 6 :
            {
                gotoligcol(a,aa+65);
                printf("%c", pion);
                break;
            }
        case 7 :
            {
                gotoligcol(a,aa+78);
                printf("%c", pion);
                break;
            }
        case 8 :
            {
                gotoligcol(a,aa+91);
                printf("%c", pion);
                break;
            }
        case 9 :
            {
                gotoligcol(a+1,aa+104);
                printf("%c", pion);
                break;
            }
        case 10 :
            {
                gotoligcol(a+5,aa+104);
                printf("%c", pion);
                break;
            }
        case 11 :
            {
                gotoligcol(a+10,aa+104);
                printf("%c", pion);
                break;
            }
        case 12 :
            {
                gotoligcol(a+15,aa+104);
                printf("%c", pion);
                break;
            }
        case 13 :
            {
                gotoligcol(a+21,aa+104);
                printf("%c", pion);
                break;
            }
        case 14 :
            {
                gotoligcol(a+25,aa+104);
                printf("%c", pion);
                break;
            }
        case 15 :
            {
                gotoligcol(a+30,aa+104);
                printf("%c", pion);
                break;
            }
        case 16 :
            {
                gotoligcol(a+35,aa+104);
                printf("%c", pion);
                break;
            }
        case 17 :
            {
                gotoligcol(a+41,aa+104);
                printf("%c", pion);
                break;
            }
        case 18 :
            {
                gotoligcol(a+40,aa+91);
                printf("%c", pion);
                break;
            }
        case 19 :
            {
                gotoligcol(a+40,aa+78);
                printf("%c", pion);
                break;
            }
        case 20 :
            {
                gotoligcol(a+40,aa+65);
                printf("%c", pion);
                break;
            }
        case 21 :
            {
                gotoligcol(a+41,aa+52);
                printf("%c", pion);
                break;
            }
        case 22 :
            {
                gotoligcol(a+40,aa+39);
                printf("%c", pion);
                break;
            }
        case 23 :
            {
                gotoligcol(a+40,a+26);
                printf("%c", pion);
                break;
            }
        case 24 :
            {
                gotoligcol(a+40,aa+13);
                printf("%c", pion);
                break;
            }
        case 25 :
            {
                gotoligcol(a+41,aa);
                printf("%c", pion);
                break;
            }
        case 26 :
            {
                gotoligcol(a+35,aa);
                printf("%c", pion);
                break;
            }
        case 27 :
            {
                gotoligcol(a+30,aa);
                printf("%c", pion);
                break;
            }
        case 28 :
            {
                gotoligcol(a+25,aa);
                printf("%c", pion);
                break;
            }
        case 29 :
            {
                gotoligcol(a+21,aa);
                printf("%c", pion);
                break;
            }
        case 30 :
            {
                gotoligcol(a+15,aa);
                printf("%c", pion);
                break;
            }
        case 31 :
            {
                gotoligcol(a+11,aa);
                printf("%c", pion);
                break;
            }
        case 32 :
            {
                gotoligcol(a+5,aa);
                printf("%c", pion);
                break;
            }


    }

}


void resetDuPionQuiJoue(struct joueur *joueurActuel)
{
    int caseactuelle = (*joueurActuel).caseActuelle;
    int i = (*joueurActuel).OrdreDePassage;
    int a = 3;
    int aa = 1;
    switch (i)
    {
        case 1 :
        {
            aa = aa + 2;
            break;
        }
        case 2 :
        {
            aa = aa + 3;
            break;
        }
        case 3 :
        {
            aa = aa + 4;
            break;
        }
        case 4 :
        {
            aa = aa + 5;
            break;
        }
        case 5 :
        {
            aa = aa+ 6;
            break;
        }
        case 6 :
        {
            aa = aa+ 7;
            break;
        }
        case 7 :
        {
            aa = aa + 1;
            break;
        }
    }
    switch (caseactuelle)
    {
        case 1 :
            {
                gotoligcol((a+1),(aa-1));
                printf(" ");
                break;
            }
        case 2 :
            {
                gotoligcol(a,aa+13);
                printf(" ");
                break;
            }
        case 3 :
            {
                gotoligcol((a+1),aa+26);
                printf(" ");
                break;
            }
        case 4 :
            {
                gotoligcol(a,aa+39);
                printf(" ");
                break;
            }
        case 5 :
            {
                gotoligcol(a+1,aa+52);
                printf(" ");
                break;
            }
        case 6 :
            {
                gotoligcol(a,aa+65);
                printf(" ");
                break;
            }
        case 7 :
            {
                gotoligcol(a,aa+78);
                printf(" ");
                break;
            }
        case 8 :
            {
                gotoligcol(a,aa+91);
                printf(" ");
                break;
            }
        case 9 :
            {
                gotoligcol(a+1,aa+10);
                printf(" ");
                break;
            }
        case 10 :
            {
                gotoligcol(a+5,aa+104);
                printf(" ");
                break;
            }
        case 11 :
            {
                gotoligcol(a+10,aa+104);
                printf(" ");
                break;
            }
        case 12 :
            {
                gotoligcol(a+15,aa+104);
                printf(" ");
                break;
            }
        case 13 :
            {
                gotoligcol(a+21,aa+104);
                printf(" ");
                break;
            }
        case 14 :
            {
                gotoligcol(a+25,aa+104);
                printf(" ");
                break;
            }
        case 15 :
            {
                gotoligcol(a+30,aa+104);
                printf(" ");
                break;
            }
        case 16 :
            {
                gotoligcol(a+65,aa+104);
                printf(" ");
                break;
            }
        case 17 :
            {
                gotoligcol(a+41,aa+104);
                printf(" ");
                break;
            }
        case 18 :
            {
                gotoligcol(a+40,aa+91);
                printf(" ");
                break;
            }
        case 19 :
            {
                gotoligcol(a+40,aa+78);
                printf(" ");
                break;
            }
        case 20 :
            {
                gotoligcol(a+40,aa+65);
                printf(" ");
                break;
            }
        case 21 :
            {
                gotoligcol(a+41,aa+52);
                printf(" ");
                break;
            }
        case 22 :
            {
                gotoligcol(a+40,aa+39);
                printf(" ");
                break;
            }
        case 23 :
            {
                gotoligcol(a+40,a+26);
                printf(" ");
                break;
            }
        case 24 :
            {
                gotoligcol(a+40,aa+13);
                printf(" ");
                break;
            }
        case 25 :
            {
                gotoligcol(a+41,aa);
                printf(" ");
                break;
            }
        case 26 :
            {
                gotoligcol(a+35,aa);
                printf(" ");
                break;
            }
        case 27 :
            {
                gotoligcol(a+30,aa);
                printf(" ");
                break;
            }
        case 28 :
            {
                gotoligcol(a+25,aa);
                printf(" ");
                break;
            }
        case 29 :
            {
                gotoligcol(a+21,aa);
                printf(" ");
                break;
            }
        case 30 :
            {
                gotoligcol(a+15,aa);
                printf(" ");
                break;
            }
        case 31 :
            {
                gotoligcol(a+11,aa);
                printf(" ");
                break;
            }
        case 32 :
            {
                gotoligcol(a+5,aa);
                printf(" ");
                break;
            }


    }

}




///fonction pour effacer la partie du moniteur que l'on souhaite
///de la ligne i jusqu'à la ligne k
///de la colone j jusqu'à la colone l
void reset(int i, int j, int k, int l)
{

    int f = k;
    for(i; i <= j; i++)
    {
        for(k ; k <= l; k++)
        {
            gotoligcol(i,k);
            printf(" ");
        }
        k = f;
    }
}









///fonction curseur
//donné par les professeurs
void gotoligcol( int lig, int col ) {


COORD mycoord;

mycoord.X = col;

mycoord.Y = lig;

SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}




























///----------------------------------PAGE DE GARDE----------------------------------------------------
void monop()
 {
    char go = 0;
    gotoligcol(0,0);
    printf("Pour lancer le monopoly, mettez la page en grand ecran, appuyer sur la touche ' m ' puis entree.\n");
    fflush(stdin);
    scanf("%c", &go);
    //blindage
    while(go != 'm')
    {
        reset(0,2,0,200);
        gotoligcol(0,50);
        printf("Pour lancer le monopoly, mettez la page en grand ecran, appuyer sur la touche ' m ' puis entree.\n");
        fflush(stdin);
        scanf("%c", &go);
    }
    reset(0,2,0,200);
    int a = 15;
    int b = 20;

    ///contour rectangle en blanc
    Color(15,15);
    reset(13,13,4,201);
    reset(27,27,4,201);
    int chepa = 4;
    for(int i = 14; i <= 26; i++)
    {
        gotoligcol(i,chepa);
        printf(" ");
    }
    chepa = 201;
    for(int i = 14; i <= 26; i++)
    {
        gotoligcol(i,chepa);
        printf(" ");
    }

    Color(15,4);

    ///rectangle rouge
    reset(14, 26, 5, 200);


    ///----------M O N O P O L Y---------------///

    /// affichage du m
    gotoligcol(a+1,b-12);
    printf("%c%c%c%c          ///%c", 0xBA, 0x5C, 0x5C, 0x5C, 0xBA);
    gotoligcol(a+2,b-12);
    printf("%c %c%c%c        /// %c", 0xBA, 0x5C, 0x5C, 0x5C, 0xBA);
    gotoligcol(a+3,b-12);
    printf("%c  %c%c%c      ///  %c", 0xBA, 0x5C, 0x5C, 0x5C, 0xBA);
    gotoligcol(a+4,b-12);
    printf("%c %c %c%c%c    /// %c %c", 0xBA, 0xBA, 0x5C, 0x5C, 0x5C, 0xBA, 0xBA);
    gotoligcol(a+5,b-12);
    printf("%c %c  %c%c%c  ///  %c %c", 0xBA, 0xBA, 0x5C, 0x5C, 0x5C, 0xBA, 0xBA);
    gotoligcol(a+6,b-12);
    printf("%c %c   %c%c%c///   %c %c", 0xBA, 0xBA, 0x5C, 0x5C, 0x5C, 0xBA, 0xBA);
    gotoligcol(a+7,b-12);
    printf("%c %c            %c %c", 0xBA, 0xBA, 0xBA, 0xBA);
    gotoligcol(a+8,b-12);
    printf("%c %c            %c %c", 0xBA, 0xBA, 0xBA, 0xBA);
    gotoligcol(a+9,b-12);
    printf("%c %c            %c %c", 0xBA, 0xBA, 0xBA, 0xBA);
    gotoligcol(a+10,b-12);
    printf("%c%c%c            %c%c%c", 0xC8, 0xCD, 0xBC, 0xC8, 0xCD, 0xBC);



    /// affichage du 0
    gotoligcol(a+0,b+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+1,b+15);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+2,b+15);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+3,b+15);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+4,b+15);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+5,b+15);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+6,b+15);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+7,b+15);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+8,b+15);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+9,b+15);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+10,b+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);

    gotoligcol(a+1,b+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+2,b+17);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+3,b+17);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+4,b+17);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+5,b+17);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+6,b+17);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+7,b+17);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+8,b+17);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+9,b+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);





    /// affichage du N
    gotoligcol(a+1,b+40);
    printf("%c %c%c%c%c         %c %c", 0xBA, 0xBA, 0x5C, 0x5C, 0x5C, 0xBA, 0xBA);
    gotoligcol(a+2,b+40);
    printf("%c %c %c%c%c        %c %c", 0xBA, 0xBA, 0x5C,  0x5C, 0x5C, 0xBA, 0xBA);
    gotoligcol(a+3,b+40);
    printf("%c %c  %c%c%c       %c %c", 0xBA, 0xBA, 0x5C,  0x5C, 0x5C, 0xBA, 0xBA);
    gotoligcol(a+4,b+40);
    printf("%c %c   %c%c%c      %c %c", 0xBA, 0xBA, 0x5C, 0x5C,  0x5C, 0xBA, 0xBA);
    gotoligcol(a+5,b+40);
    printf("%c %c    %c%c%c     %c %c", 0xBA, 0xBA, 0x5C,  0x5C, 0x5C, 0xBA, 0xBA);
    gotoligcol(a+6,b+40);
    printf("%c %c     %c%c%c    %c %c", 0xBA, 0xBA, 0x5C, 0x5C,  0x5C, 0xBA, 0xBA);
    gotoligcol(a+7,b+40);
    printf("%c %c      %c%c%c   %c %c", 0xBA, 0xBA, 0x5C, 0x5C,  0x5C, 0xBA, 0xBA);
    gotoligcol(a+8,b+40);
    printf("%c %c       %c%c%c  %c %c", 0xBA, 0xBA, 0x5C, 0x5C,  0x5C, 0xBA, 0xBA);
    gotoligcol(a+9,b+40);
    printf("%c %c        %c%c%c %c %c", 0xBA, 0xBA, 0x5C, 0x5C,  0x5C, 0xBA, 0xBA);
    gotoligcol(a+10,b+40);
    printf("%c %c         %c%c%c%c %c", 0xBA, 0xBA, 0x5C,  0x5C, 0x5C, 0xBA, 0xBA);




    /// affichage du 0
    gotoligcol(a+0,b+68);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+1,b+68);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+2,b+68);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+3,b+68);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+4,b+68);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+5,b+68);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+6,b+68);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+7,b+68);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+8,b+68);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+9,b+68);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+10,b+68);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);

    gotoligcol(a+1,b+70);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+2,b+70);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+3,b+70);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+4,b+70);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+5,b+70);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+6,b+70);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+7,b+70);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+8,b+70);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+9,b+70);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);



    /// affichage du P
    gotoligcol(a,b+93);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+1,b+93);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+2,b+93);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+3,b+93);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+4,b+93);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+5,b+93);
    printf("%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xBA, 0xC9, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xBC);
    gotoligcol(a+6,b+93);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+7,b+93);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+8,b+93);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+9,b+93);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+10,b+93);
    printf("%c%c%c", 0xC8, 0xCD, 0xBC);


    gotoligcol(a+1,b+95);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+2,b+95);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+3,b+95);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+4,b+95);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);








    /// affichage du 0
    gotoligcol(a+0,b+118);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+1,b+118);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+2,b+118);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+3,b+118);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+4,b+118);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+5,b+118);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+6,b+118);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+7,b+118);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+8,b+118);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+9,b+118);
    printf("%c                %c", 0xBA, 0xBA);
    gotoligcol(a+10,b+118);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);

    gotoligcol(a+1,b+120);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC9, 0xCD, 0xCD,  0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+2,b+120);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+3,b+120);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+4,b+120);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+5,b+120);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+6,b+120);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+7,b+120);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+8,b+120);
    printf("%c            %c", 0xBA, 0xBA);
    gotoligcol(a+9,b+120);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);

    /// affichage du L
    gotoligcol(a,b+143);
    printf("%c%c%c", 0xC9, 0xCD, 0xBB);
    gotoligcol(a+1,b+143);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+2,b+143);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+3,b+143);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+4,b+143);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+5,b+143);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+6,b+143);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+7,b+143);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+8,b+143);
    printf("%c %c", 0xBA, 0xBA);
    gotoligcol(a+9,b+143);
    printf("%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xBA, 0xC8, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    gotoligcol(a+10,b+143);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xC8, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);

    /// affichage du Y
    gotoligcol(a,b+165);
    printf("%c%c%c        ///", 0x5C, 0x5C, 0x5C);
    gotoligcol(a+1,b+165);
    printf(" %c%c%c      /// ", 0x5C, 0x5C, 0x5C);
    gotoligcol(a+2,b+165);
    printf("  %c%c%c    ///  ", 0x5C, 0x5C, 0x5C);
    gotoligcol(a+3,b+165);
    printf("   %c%c%c  ///   ", 0x5C, 0x5C, 0x5C);
    gotoligcol(a+4,b+165);
    printf("    %c%c%c///    ", 0x5C, 0x5C, 0x5C);
    gotoligcol(a+5,b+170);
    printf("%c  %c", 0XBA, 0xBA);
    gotoligcol(a+6,b+170);
    printf("%c  %c", 0XBA, 0xBA);
    gotoligcol(a+7,b+170);
    printf("%c  %c", 0XBA, 0xBA);
    gotoligcol(a+8,b+170);
    printf("%c  %c", 0XBA, 0xBA);
    gotoligcol(a+9,b+170);
    printf("%c  %c", 0XBA, 0xBA);
    gotoligcol(a+10,b+170);
    printf("%c%c%c%c", 0XC8, 0xCD, 0xCD, 0xBC);


    Color(15,0);
    ///crateur
    gotoligcol(35,100);
    printf("CREATE BY");
    gotoligcol(37,88);
    printf("Alexis   Thaddee   Ludovic   Hugo");

    int fin;
    //blindage
    while (fin != 32)
    {
        Color(0,15);
        gotoligcol(44,77);
        printf("Appuyer sur la touche espace pour commencer, puis entrer");
        Color(15,0);
        gotoligcol(46,0);
        fflush(stdin);
        scanf("%c", &fin);
        reset(45,48,0,50);

    }
    //une fois la touche espace entrez tout l'ecran va s'effacer
    //il y a donc une impression qu'on change de page
    reset(0,100,0,250);

 }

