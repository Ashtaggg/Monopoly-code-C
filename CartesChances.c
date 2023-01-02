#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Structures.h"




void cartechance(struct joueur *nom) //Sous programme d'appel des cartes chances de manière aleatoire et en fonction de la carte affichage de ce qu'il se passe
{
    srand(time(NULL));
    int col = 130;
    int lig = 17;
    int suite;
    char suiteChance;
    int nbCarte =1 + rand()%(16-1);
    while(suiteChance != 32)
    {
        gotoligcol(lig-2,col);
        printf("Voici votre carte : (appuyez sur espace pour la voir)");
        gotoligcol(lig-1,col);
        fflush(stdin);
        scanf("%c", &suiteChance);
        reset(lig-1,lig-1,col,col+40);
    }


///----------------------------A FAIRE---------------------------------------------
    if (nbCarte==1)     //Si la carte 1 est tirée
    {
        gotoligcol(lig+1,col);
        printf("Vous avancez de 3 cases");
        resetDuPionQuiJoue((nom));
        (*nom).caseActuelle =(*nom).caseActuelle+3 ; ///avancer de 3 cases
        affichageDuPionQuiJoue((nom));
        gotoligcol(lig+3,col);
        affichageCaseActuelle((*nom).caseActuelle);
        gotoligcol(lig+4,col);
        printf("Cependant, vous ne pouvez effectuer aucune demarche sur celle ci");
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
    if (nbCarte==2)     //Si la carte 2 est tirée
    {
        (*nom).cartePrison =(*nom).cartePrison+1 ;///gagnge une carte sortie de prison
        gotoligcol(lig+1,col);
        printf("Vous avez gagner une carte sortie de prison !");
        while(suite != 32)
        {
            gotoligcol(lig+4,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+5,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+5,lig+5,col,col+50);
        }
        reset(lig-3,lig+5,col,col+80);


    }
     if (nbCarte==3)     //Si la carte 3 est tirée
    {
        int choix;

        gotoligcol(lig+1,col);
        printf("Vous etes invite a diner par votre ami Kanye West afin de discuter de sa");
        gotoligcol(lig+2,col);
        printf("discographie autour d'une table a 100 dollar ");
        gotoligcol(lig+3,col);
        printf("Rendez vous a NYC et tirer a pile ou face pour savoir qui");
        gotoligcol(lig+4,col);
        printf("reglera l'addition. Que choisissez vous ?");
        gotoligcol(lig+5,col);
        printf("1.\tPile");
        gotoligcol(lig+6,col);
        (*nom).caseActuelle = 19;///avance NYC
        printf("2.\tFace");
        gotoligcol(lig+7,col);
        fflush(stdin);
        scanf("%d", &choix);
        while(1 < choix && choix > 2)
        {
            reset(lig+7,lig+7,col,col+20);
            gotoligcol(lig+7,col);
            fflush(stdin);
            scanf("%d", &choix);
        }




        int PileFace = rand()%(2);

        if (PileFace==0 && choix == 2)
        {
            gotoligcol(lig+9,col);
            printf("FACE");
            gotoligcol(lig+10,col);
            printf("Felicitation Kanye regle l'addition");
        }
        if (PileFace==1 && choix == 1)
        {
            gotoligcol(lig+9,col);
            printf("PILE");
            gotoligcol(lig+10,col);
            printf("Felicitation Kanye regle l'addition");
        }
        else if(PileFace==1 && choix == 2)
        {
            gotoligcol(lig+9,col);
            printf("PILE");
            gotoligcol(lig+10,col);
            printf("Dommage vous reglez l'addition");
            (*nom).argent = (*nom).argent-100;
            gotoligcol(lig+11,col);
            printf("Vous possedez maintenant %d dollars", (*nom).argent);
        }
        else if(PileFace==0 && choix == 1)
        {
            gotoligcol(lig+9,col);
            printf("FACE");
            gotoligcol(lig+10,col);
            printf("Dommage vous reglez l'addition");
            (*nom).argent = (*nom).argent-100;
            gotoligcol(lig+11,col);
            printf("Vous possedez maintenant %d dollars", (*nom).argent);
        }
        while(suite != 32)
        {
            gotoligcol(lig+14,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+15,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+15,lig+15,col,col+50);
        }
        reset(lig-3,lig+15,col,col+80);


    }
     if (nbCarte==4)     //Si la carte 4 est tirée
    {
        gotoligcol(lig+1,col);
        printf("Vous etes convoque par la police des finances. Rendez vous a Paris.");
        gotoligcol(lig+2,col);
        printf("Selon le Commissaire RAPIA vous avez frode 200 dollars a l'etat francais");
        (*nom).caseActuelle = 26;
        affichageDuPionQuiJoue((nom));
        (*nom).argent = (*nom).argent-200;
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
     if (nbCarte==5)     //Si la carte 5 est tirée
     {
         gotoligcol(lig+1,col);
         printf("Crazy night in Las Vegas ");
         gotoligcol(lig+2,col);
         printf("La roulette russe du Cesear Palace est votre meilleur ami");
         gotoligcol(lig+3,col);
         printf("Vous gagnez 150 dollars");
         (*nom).argent = (*nom).argent+150;
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
      if (nbCarte==6)     //Si la carte 6 est tirée
      {
        gotoligcol(lig+1,col);
        printf("Harvard Buisness school vous invite a donnez une conferrence sur votre");
        gotoligcol(lig+2,col);
        printf("reussite en tant que mania de l'immobilier");
        gotoligcol(lig+3,col);
        printf("Vous etes paye 50 pour votre prestation");
        gotoligcol(lig+5,col);
        printf("Cependant votre limousine se fait rentre dedans par un semi remorque");
        gotoligcol(lig+6,col);
        printf("lors de votre trajet retour");
        gotoligcol(lig+7,col);
        printf("La note de frais d'hopital est 2 fois superieur a votre salaire ");
        (*nom).argent = (*nom).argent-100;
        gotoligcol(lig+9,col);
        printf("Vous possedez maintenant %d dollars", (*nom).argent);
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
       if (nbCarte==7)     //Si la carte 7 est tirée
       {
           gotoligcol(lig+1,col);
           printf("Dommage votre parrain est decede en australie mange par son");
           gotoligcol(lig+2,col);
           printf("crocodile de compagnie");
           gotoligcol(lig+3,col);
           printf("Rendez vous a sidney pour ses funeraille ");
           (*nom).caseActuelle = 18;
           affichageDuPionQuiJoue(nom);
           gotoligcol(lig+5,col);
           printf("FELICITATION ,vous etes l'unique beneficiaire de sa fortune");
           gotoligcol(lig+6,col);
           printf("collossale de 400 dollars ");
           (*nom).argent = (*nom).argent+400;
            gotoligcol(lig+8,col);
           printf("Vous possedez maintenant %d dollars", (*nom).argent);
        while(suite != 32)
        {
            gotoligcol(lig+11,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+12,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+12,lig+12,col,col+50);
        }
        reset(lig-3,lig+12,col,col+80);

       }
       if (nbCarte==8)     //Si la carte 8 est tirée
       {
           gotoligcol(lig+1,col);
           printf("De retour au casino vous misez 100 dollars sur une table de blackjack");
           gotoligcol(lig+2,col);
           printf("Vous lancez un regard provocateur au croupier");
           int BJplayer= 11+ rand()%(26-11);
           int BJcroupier=17+rand()%(25-17);
            gotoligcol(lig+4,col);
           printf("Le croupier tire une tete et place sa deuxieme carte face cache...");
           gotoligcol(lig+5,col);
           printf("Vous jouez et obtenez :%d",BJplayer);
           if (BJplayer==21)
           {
               gotoligcol(lig+6,col);
               printf("BLACKJACK!!!!!!! Vous gagnez 2,5 fois votre mise");
                (*nom).argent = (*nom).argent+150;
                gotoligcol(lig+7,col);
                printf("Vous possedez maintenant %d dollars", (*nom).argent);
           }
           if (BJplayer>21)
           {
               gotoligcol(lig+6,col);
               printf("BUST... Vous perdez votre mise et rentrez tristement a l'hotel");
               (*nom).argent = (*nom).argent-100;
               gotoligcol(lig+7,col);
               printf("Vous possedez maintenant %d dollars", (*nom).argent);
           }
           if (BJplayer==BJcroupier && BJplayer<21)
           {
               gotoligcol(lig+6,col);
               printf("Le croupier fait :%d",BJcroupier);
               gotoligcol(lig+7,col);
               printf("DRAW... vous recuperez votre mise ");
               gotoligcol(lig+8,col);
               printf("Vous possedez maintenant %d dollars", (*nom).argent);
           }
            if (BJplayer<BJcroupier && BJplayer<21&&BJcroupier<=21)
            {
                gotoligcol(lig+6,col);
                printf("le croupier fait :%d",BJcroupier);
                gotoligcol(lig+7,col);
                printf("Dommage vous perdez votre mise");
                (*nom).argent = (*nom).argent-100;
                gotoligcol(lig+8,col);
                printf("Vous possedez maintenant %d dollars", (*nom).argent);

            }
            if (BJplayer>BJcroupier && BJplayer<21&& BJcroupier<=21)
            {
                gotoligcol(lig+6,col);
                printf("Le croupier fait :%d",BJcroupier);
                gotoligcol(lig+7,col);
                printf("FELICITATION vous gagnez le double de votre mise ");
                (*nom).argent = (*nom).argent+100;
                gotoligcol(lig+8,col);
                printf("Vous possedez maintenant %d dollars", (*nom).argent);
            }
            if (BJcroupier>21 && BJplayer<21)
            {
                gotoligcol(lig+6,col);
                printf("Le croupier fait :%d",BJcroupier);
                gotoligcol(lig+7,col);
                printf("FELICITATION le croupier Bust vous gagnez le double de votre mise");
                (*nom).argent = (*nom).argent+100;
                gotoligcol(lig+8,col);
                printf("Vous possedez maintenant %d dollars", (*nom).argent);

            }
        while(suite != 32)
        {
            gotoligcol(lig+11,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+12,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+12,lig+12,col,col+50);
        }
        reset(lig-3,lig+12,col,col+80);


             }
             if (nbCarte==9)     //Si la carte 9 est tirée
             {
                 gotoligcol(lig+1,col);
                 printf("Vous faites des investisments risques en bourses");
                 gotoligcol(lig+2,col);
                 printf("Vous investisez 100 dollars");
                 int taux = -3 + rand()%(3+3);
                 gotoligcol(lig+3,col);
                 printf("Votre investisment vous rapporte %d fois la somme investit",taux);
                 (*nom).argent = (*nom).argent+100*taux;
                 if(taux>0)
                 {
                     gotoligcol(lig+4,col);
                     printf("GENIAL");
                 }
                  if(taux<=0)
                  {
                      gotoligcol(lig+4,col);
                      printf("DOMMAGE");
                  }
                 gotoligcol(lig+6,col);
                 printf("Vous possedez maintenant %d dollars", (*nom).argent);
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




            if (nbCarte==10)     //Si la carte 10 est tirée
            {
                gotoligcol(lig+1,col);
                printf("Du a la crise sanitaire vos revenus touristiques sont au plus bas ");
                gotoligcol(lig+2,col);
                printf("Payez 25 dollars par proprietees possedees");
                (*nom).argent = (*nom).argent - (25 * (*nom).nbrProprietes);
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
            if (nbCarte==11)     //Si la carte 11 est tirée
            {
                gotoligcol(lig+1,col);
                printf("Votre cher ami Mr ESCROT doit passer 3 ans en prison pour fraude fiscale");
                gotoligcol(lig+2,col);
                printf("Rendez lui visite au parloir");
                (*nom).caseActuelle = 9;
                affichageDuPionQuiJoue(nom);
                gotoligcol(lig+4,col);
                printf("Dans votre extreme altruisme vous lui donnez 100 dollars pour");
                gotoligcol(lig+5,col);
                printf("surmonter cette periode difficile");
                (*nom).argent = (*nom).argent-100;
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
            if (nbCarte==12)     //Si la carte 12 est tirée
            {
                gotoligcol(lig+1,col);
                printf("Vous etes invite a un chic derby londonien");
                gotoligcol(lig+2,col);
                printf("Rendez vous a Londres");
                (*nom).caseActuelle = 20;
                affichageDuPionQuiJoue(nom);
                gotoligcol(lig+4,col);
                printf("Vous achetez un cheval 50 dollars et percevez des revenus en fonction");
                gotoligcol(lig+5,col);
                printf("de ses performances");
                int cheval=1+rand()%(5-1);
                cheval=cheval*50;
                (*nom).argent = (*nom).argent-50;
                (*nom).argent = (*nom).argent+cheval;
                gotoligcol(lig+7,col);
                printf("Felicitation vous gagnez %d dollars",cheval);
                gotoligcol(lig+9,col);
                printf("Vous possedez maintenant %d dollars", (*nom).argent);
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
            if (nbCarte==13)     //Si la carte 13 est tirée
            {
                gotoligcol(lig+1,col);
                printf("Rendez vous a la case depart");
                resetDuPionQuiJoue((nom));
                (*nom).caseActuelle = 1;
                affichageDuPionQuiJoue(nom);
                gotoligcol(lig+3,col);
                printf("Vous gagnez 200 dollars");
                (*nom).argent = (*nom).argent + 200;
                gotoligcol(lig+5,col);
                printf("Vous possedez maintenant %d dollars", (*nom).argent);
        while(suite != 32)
        {
            gotoligcol(lig+8,col);
            printf("Appuyez sur la touche espace pour continuer");
            gotoligcol(lig+9,col);
            fflush(stdin);
            scanf("%c", &suite);
            reset(lig+5,lig+9,col,col+50);
        }
        reset(lig-3,lig+9,col,col+80);



            }
            if (nbCarte==14)     //Si la carte 14 est tirée
            {
                gotoligcol(lig+1,col);
                printf("Vous pariez 50 sur la victoire des bleus face a l'italie");
                int cote= 2+ rand()%(3-2);
                gotoligcol(lig+2,col);
                printf("La cote est a : %d",cote);
                int PileFace = rand()%(2);

        if (PileFace==0)
        {
            gotoligcol(lig+4,col);
            printf("VICTOIRE des bleues sur un double de Mbappe");
            (*nom).argent = (*nom).argent+50*cote;
            gotoligcol(lig+6,col);
            printf("Vous possedez maintenant %d dollars", (*nom).argent);

        }
        else if(PileFace==1)
        {
            gotoligcol(lig+4,col);
            printf("Defaite... votre equipe nationale vous aura coute 50 dollars");
           (*nom).argent = (*nom).argent-50;
           gotoligcol(lig+6,col);
           printf("Vous possedez maintenant %d dollars", (*nom).argent);
        }
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
            if (nbCarte==15)     //Si la carte 15 est tirée
            {
                gotoligcol(lig+1,col);
                printf("Vous renversez votre cafe sur votre nouveau costume Paul Smith");
                gotoligcol(lig+2,col);
                printf("Vous en rachetez 1 pour 50 dollars");
                (*nom).argent = (*nom).argent-50;
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
             if (nbCarte==16)     //Si la carte 16 est tirée
             {
                gotoligcol(lig+1,col);
                 printf("Vous vendez votre collection de monocle et de haut de forme ");
                 gotoligcol(lig+2,col);
                 printf("Gagnez 130 dollars ");
                 (*nom).argent = (*nom).argent+130;
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

}
