#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Structures.h"



void carteCaisseCom(struct joueur *nom,int *nbCarte)
{
    int lig = 16;
    int col = 130;
    int suite;
    char suiteCommu;
    while(suiteCommu != 32)
    {
        gotoligcol(lig-2,col);
        printf("Voici votre carte : (appuyez sur espace pour la voir)");
        gotoligcol(lig-1,col);
        fflush(stdin);
        scanf("%c", &suiteCommu);
        reset(lig-1,lig-1,col,col+40);
    }


    if (*nbCarte == 1)
    {
        gotoligcol(lig+1,col);
        printf("L'etats vous reclame vos impots fonciers");
        gotoligcol(lig+2,col);
        printf("Payez 20 dollars par proprietes");
        (*nom).argent = (*nom).argent-20 * (*nom).nbrProprietes;
        gotoligcol(lig+4,col);
        printf("Vous possedez maintenant %d dollars", (*nom).argent);
        while(suite != 32)
        {
            gotoligcol(lig+7,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+8,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+8,lig+8,col,col+50);
        }
        reset(lig-3,lig+8,col,col+80);

    }
    if (*nbCarte==2)
    {
        gotoligcol(lig+1,col);
        printf("Vos usines de composants electroniques");
        gotoligcol(lig+2,col);
        printf(" %s CORPORATE",(*nom).prenom);
        printf("sont respectueuses de l'environnement ");
        gotoligcol(lig+3,col);
        printf("recevez 100 dollars de bonnus carbonne");
        (*nom).argent = (*nom).argent+100;
        gotoligcol(lig+5,col);
        printf("Vous possedez maintenant %d dollars", (*nom).argent);
        while(suite != 32)
        {
            gotoligcol(lig+8,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+9,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+9,lig+9,col,col+50);
        }
        reset(lig-3,lig+9,col,col+80);


    }
    if (*nbCarte==3)
    {
         int soltaniEnt;

        do
        {
             gotoligcol(lig+1,col);
             printf("La branche aeronautique de %s CORPORATE sort",(*nom).prenom);
             gotoligcol(lig+2,col);
             printf("un brevet revolutionnaire");
             gotoligcol(lig+3,col);
            printf("Votre concurent SOLTANI ENT tente de le racheter pour 100 dollars ");
            gotoligcol(lig+4,col);
            printf("Vendez le ou choisissez de l'exploiter pour un revenu aleatoire");
            gotoligcol(lig+5,col);
            printf("1.\tVendre votre brevet");
            gotoligcol(lig+6,col);
            printf("2.\tTenter votre chance en exploitant votre brevet");
            gotoligcol(lig+7,col);
             fflush(stdin);
             scanf("%d",&soltaniEnt);
             while(soltaniEnt < 1 || soltaniEnt > 2)
             {
                 reset(lig+7,lig+7,col,col+50);
                 gotoligcol(lig+7,col);
                 fflush(stdin);
                 scanf("%d", &soltaniEnt);
             }


             if(soltaniEnt==1)
             {
                 (*nom).argent = (*nom).argent+100;
                 gotoligcol(lig+9,col);
                printf("Vous possedez maintenant %d dollars", (*nom).argent);

                 /////soltaniEnt=0;
             }
             if(soltaniEnt==2)
             {
                 srand(time(NULL));
                 (*nom).argent = (*nom).argent+(20+rand()%(220-20));
                 gotoligcol(lig+9,col);
                 printf("Vous possedez maintenant %d dollars", (*nom).argent);

                 ////soltaniEnt=0;
             }

        }while (soltaniEnt<1 || soltaniEnt>2);
        while(suite != 32)
        {
            gotoligcol(lig+12,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+13,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+13,lig+13,col,col+50);
        }
        reset(lig-3,lig+13,col,col+80);



    }
    if (*nbCarte==4)
    {

        int MrRipou=0;

           gotoligcol(lig+1,col);
            printf("Le grand ministre MR RIPOU cherche a acquerir un de vos apartements parisien ");
            gotoligcol(lig+2,col);
            printf("Vous lui en vendez un pour 150 dollars");
             (*nom).argent = (*nom).argent+150;
             gotoligcol(lig+4,col);
            printf("Vous possedez maintenant %d dollars", (*nom).argent);

        while(suite != 32)
        {
            gotoligcol(lig+7,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+8,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+8,lig+8,col,col+50);
        }
        reset(lig-3,lig+8,col,col+80);



    }
    if (*nbCarte==5)
    {
        gotoligcol(lig+1,col);
        printf("Votre fils %s Junior participe a une course de rue avec",(*nom).prenom);
        gotoligcol(lig+2,col);
        printf("son cher ami Edourad FILSAPAPA");
        gotoligcol(lig+3,col);
        printf("Malheuresement le commissaire RIPOU le rattrape");
        gotoligcol(lig+4,col);
        printf("Vous regretez soudainement de lui avoir offert une Maserati pour ses 18 ans");
        gotoligcol(lig+5,col);
        printf("Payez la caution 200 dollars");
        (*nom).argent = (*nom).argent-200;
        gotoligcol(lig+7,col);
        printf("Vous possedez maintenant %d dollars", (*nom).argent);
        while(suite != 32)
        {
            gotoligcol(lig+10,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+11,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+11,lig+11,col,col+50);
        }
        reset(lig-3,lig+11,col,col+80);


    }
    if (*nbCarte==6)
    {
        gotoligcol(lig+1,col);
        printf("La situation sanitaire mondiale s'ameliore grandement");
        gotoligcol(lig+2,col);
        printf("Vos proprietes vous rapportent 25 dollars chacune");
        (*nom).argent = (*nom).argent+25 * (*nom).nbrProprietes;
        gotoligcol(lig+4,col);
        printf("Vous possedez maintenant %d dollars", (*nom).argent);

        while(suite != 32)
        {
            gotoligcol(lig+7,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+8,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+8,lig+8,col,col+50);
        }
        reset(lig-3,lig+8,col,col+80);


    }
    if (*nbCarte==7)
    {
        gotoligcol(lig+1,col);
        printf("Un seisme ravage la californie");
        gotoligcol(lig+2,col);
        printf("La maison de votre cousin est detruite");
        gotoligcol(lig+3,col);
        printf("Aidez le a hauteur de 100 dollars");
         (*nom).argent = (*nom).argent-100;
        gotoligcol(lig+5,col);
        printf("Vous possedez maintenant %d dollars", (*nom).argent);

        while(suite != 32)
        {
            gotoligcol(lig+8,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+9,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+9,lig+9,col,col+50);
        }
        reset(lig-3,lig+9,col,col+80);


    }
    if (*nbCarte==8)
    {

        int voyage=0;
        do
        {
            gotoligcol(lig+1,col);
            printf("Vos points de fidelites AIR Canada vous rapportent un voyage gratuit ");
            gotoligcol(lig+2,col);
            printf("Choisissez votre destination");
            gotoligcol(lig+3,col);
            printf("1: Toronto");
            gotoligcol(lig+4,col);
            printf("2: Vancouvert ");
            gotoligcol(lig+5,col);
            printf("3: Montreal");
            gotoligcol(lig+6,col);
             fflush(stdin);
            scanf("%d",&voyage);
            while(voyage < 1 || voyage > 3)
            {
                reset(lig+6,lig+6,col,col+50);
                gotoligcol(lig+6,col);
                fflush(stdin);
                scanf("%d", &voyage);
            }

            if (voyage ==1)
            {
                 gotoligcol(lig+8, col);
                 printf("BON VOYAGE!");
                resetDuPionQuiJoue((nom));
                 (*nom).caseActuelle=12 ;
                affichageDuPionQuiJoue((nom));

            }
            if (voyage==2)
            {
                 gotoligcol(lig+8, col);
                 printf("BON VOYAGE!");
                resetDuPionQuiJoue((nom));
                (*nom).caseActuelle= 16;
                affichageDuPionQuiJoue((nom));

            }
             if (voyage==3)
            {
                 gotoligcol(lig+8, col);
                 printf("BON VOYAGE!");
                resetDuPionQuiJoue((nom));
                 (*nom).caseActuelle= 32;
                affichageDuPionQuiJoue((nom));

            }
        }
        while (voyage< 1 || voyage >3);
        while(suite != 32)
        {
            gotoligcol(lig+11,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+12,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+13,lig+13,col,col+50);
        }
        reset(lig-3,lig+13,col,col+80);

     }
    if (*nbCarte==9)
    {


         int voyage=0;

        do
        {
            gotoligcol(lig+1,col);
            printf("Vos points de fidelites CHINA Airline vous rapportent un voyage gratuit");
            gotoligcol(lig+2,col);
            printf("Choisissez votre destination");
            gotoligcol(lig+3,col);
            printf("1: Shangai");
            gotoligcol(lig+4,col);
            printf("2: Beijin ");
            gotoligcol(lig+5,col);
            fflush(stdin);
            scanf("%d",&voyage);
            while(voyage < 1 || voyage > 2)
            {
                reset(lig+5,lig+5,col,col+50);
                gotoligcol(lig+5,col);
                fflush(stdin);
                scanf("%d", &voyage);
            }


            if (voyage ==1)
            {
                 gotoligcol(lig+7, col);
                 printf("BON VOYAGE!");
                resetDuPionQuiJoue((nom));
                (*nom).caseActuelle= 15;
                affichageDuPionQuiJoue((nom));
            }
            if (voyage==2)
            {
                 gotoligcol(lig+7, col);
                 printf("BON VOYAGE!");
                resetDuPionQuiJoue((nom));
                (*nom).caseActuelle= 22;
                affichageDuPionQuiJoue((nom));
            }

        }while (voyage<1 || voyage >2);
        while(suite != 32)
        {
            gotoligcol(lig+10,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+11,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+11,lig+11,col,col+50);
        }
        reset(lig-3,lig+11,col,col+80);



    }
    if (*nbCarte==10)
    {

        gotoligcol(lig+1,col);
        printf("Votre fils vous derobe votre carte de credit pendant votre  sommeil,");
        gotoligcol(lig+2,col);
        printf("la note du plaza Athenee indique : - 100 dollars\n");
        (*nom).argent = (*nom).argent-100;
        gotoligcol(lig+4,col);
        printf("Vous possedez maintenant %d dollars", (*nom).argent);

        while(suite != 32)
        {
            gotoligcol(lig+7,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+8,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+8,lig+8,col,col+50);
        }
        reset(lig-3,lig+8,col,col+80);



    }
    if (*nbCarte==11)
    {
        gotoligcol(lig+1,col);
        printf("Vous vendez votre collection de voitures vintages");
        gotoligcol(lig+2,col);
        printf("Vous gagnez 50 dollars");
        (*nom).argent = (*nom).argent+50;
        gotoligcol(lig+4,col);
        printf("Vous possedez maintenant %d dollars", (*nom).argent);

        while(suite != 32)
        {
            gotoligcol(lig+7,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+8,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+8,lig+8,col,col+50);
        }
        reset(lig-3,lig+8,col,col+80);

    }
    if (*nbCarte==12)
    {

          int voyage=0;

        do
        {
            gotoligcol(lig+1,col);
            printf("Votre jet prive tombe en panne ");
            printf("La reparation coute 200 dollars");
            gotoligcol(lig+2,col);
            printf("Choix 1 : Payez la reparation et avancez de 3 cases");
            gotoligcol(lig+3,col);
            printf("Choix 2 : Reculez de 5 cases");
            gotoligcol(lig+4,col);
            fflush(stdin);
            scanf("%d",&voyage);

            if (voyage ==1)
            {
                 resetDuPionQuiJoue((nom));
                 (*nom).caseActuelle=(*nom).caseActuelle+3 ;
                 affichageDuPionQuiJoue((nom));
                 (*nom).argent = (*nom).argent-200;
                gotoligcol(lig+6,col);
                printf("Vous possedez maintenant %d dollars", (*nom).argent);



            }
            if (voyage==2)
            {
                 resetDuPionQuiJoue((nom));
                 (*nom).caseActuelle= (*nom).caseActuelle-5;
                 affichageDuPionQuiJoue((nom));

            }

        }while (voyage<1 || voyage >2);
        while(suite != 32)
        {
            gotoligcol(lig+9,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+10,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+10,lig+10,col,col+50);
        }
        reset(lig-3,lig+10,col,col+80);



    }
    if (*nbCarte==13)
    {
        int voyage=0;

        do
        {
            gotoligcol(lig+1,col);
            printf("Votre ami Sam vous loue sa nouvelle ferrari");
            gotoligcol(lig+2,col);
            printf("Avancez du nombre de case du nombre de case choisi entre 1 et 20");
            gotoligcol(lig+3,col);
            printf("Payez 20 dollars par case");
            gotoligcol(lig+4,col);
            fflush(stdin);
            scanf("%d",&voyage);
            while(voyage < 1 || voyage > 20)

            resetDuPionQuiJoue((nom));
            (*nom).caseActuelle= (*nom).caseActuelle+voyage;
            affichageDuPionQuiJoue((nom));
            (*nom).argent = (*nom).argent-20*voyage;
            gotoligcol(lig+6,col);
            printf("Vous possedez maintenant %d dollars", (*nom).argent);


       //// voyage = 0;

        } while (voyage<1 || voyage >20);
        while(suite != 32)
        {
            gotoligcol(lig+9,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+10,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+10,lig+10,col,col+50);
        }
        reset(lig-3,lig+10,col,col+80);



    }
    if (*nbCarte==14)
    {
        gotoligcol(lig+1,col);
        printf("C'est votre anniversaire ");
        gotoligcol(lig+2,col);
        printf("Vous allez le feter a Barcelone");
        gotoligcol(lig+3,col);
        printf("Votre ami John MC SAM vous offre 50 dollars et une bouteille de champagne");
        resetDuPionQuiJoue((nom));
        (*nom).caseActuelle= 7;
        (*nom).argent = (*nom).argent+50;
        affichageDuPionQuiJoue((nom));
        gotoligcol(lig+5,col);
        printf("Vous possedez maintenant %d dollars", (*nom).argent);

        while(suite != 32)
        {
            gotoligcol(lig+8,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+9,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+9,lig+9,col,col+50);
        }
        reset(lig-3,lig+9,col,col+80);





    }
    if (*nbCarte==15)
    {
        gotoligcol(lig+1,col);
        printf("Vous faites un don de 100 a une association caritative Polonaise");
        gotoligcol(lig+2,col);
        printf("Vous etes invite a Gdynia pour inaugurer l'hopital que votre");
        gotoligcol(lig+3,col);
        printf("don a permis de construire");
        resetDuPionQuiJoue((nom));
        (*nom).caseActuelle= 2;
        (*nom).argent = (*nom).argent-100;
        affichageDuPionQuiJoue((nom));
        gotoligcol(lig+5,col);
        printf("Vous possedez maintenant %d dollars", (*nom).argent);

        while(suite != 32)
        {
            gotoligcol(lig+8,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+9,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+8,lig+10,col,col+50);
        }
        reset(lig-3,lig+8,col,col+80);


    }
    if (*nbCarte==16)
    {
        int a;
        gotoligcol(lig+1,col);
        printf(" Un lion s'echappe de votre zoo privee londonien");
        gotoligcol(lig+2,col);
        printf("C'est la panique");
        gotoligcol(lig+3,col);
        printf("Payez 100 dollars le meilleur chasseur de la ville avant que l'animal ne fasse des ravages");
        (*nom).argent = (*nom).argent-100;
        gotoligcol(lig+5,col);
        printf("Vous possedez maintenant %d dollars", (*nom).argent);
        while(suite != 32)
        {
            gotoligcol(lig+8,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+9,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+9,lig+9,col,col+50);
        }
        reset(lig-3,lig+9,col,col+80);


    }

}

