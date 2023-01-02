#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Structures.h"

void regles()   //Affichage des règles du jeu
{
    gotoligcol(15,0);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t______DEBUT DE PARTIE______\n");        //On affiche les règles
    printf("\t\t\t\t\t\t\t\t\t\tUne partie de monopoly peut se jouer de 2 a 8 joueur\n");
    printf("\t\t\t\t\t\t\t\t\t\tL'ordre de passage des joueur est aleatoire\n");
    printf("\t\t\t\t\t\t\t\t\t\tChaque joueur devra inscrire son nom et choisir son pion\n");
    printf("\t\t\t\t\t\t\t\t\t\tChaque joueur commence a la case depart \n");
    printf("\t\t\t\t\t\t\t\t\t\tChacun des joueurs se voient atribuer 1500 dollars\n");
    printf("\t\t\t\t\t\t\t\t\t\tEt toute les cartes sont en possession de la banque\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t______DEROULEMENT D'UN TOUR______\n");
    printf("\t\t\t\t\t\t\t\t\t\tEn debut de tour le joueur tire les des\n");
    printf("\t\t\t\t\t\t\t\t\t\tIl avnace ensuite son pion du nombre de cases inscrit sur les des\n");
    printf("\t\t\t\t\t\t\t\t\t\tSi le joueur fait un double  \n ");
    printf("\t\t\t\t\t\t\t\t\t\tIl est assujetti à tous les privilèges ou pénalités relatifs à la case\n");
    printf("\t\t\t\t\t\t\t\t\t\tPuis il relance les des\n");
    printf("\t\t\t\t\t\t\t\t\t\tEn fonction de la case d'arrive le joueur a differentes possiblilites\n");
    printf("\t\t\t\t\t\t\t\t\t\tDeux ou plus de deux joueur.euses peuvent etre sur la même cases\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t______CASE PROPRIETE_______\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t-----Acheter une propriete-----\n");
    printf("\t\t\t\t\t\t\t\t\t\tSi le proprietaire de la case est la banque\n");
    printf("\t\t\t\t\t\t\t\t\t\tLe joueur peut l'acheter a son prix d'achat\n");
    printf("\t\t\t\t\t\t\t\t\t\tIl en sera alors le nouveau proprietaire \n");
    printf("\t\t\t\t\t\t\t\t\t\tIl pourra percevoir un loyer lorsqu'un joueur tombe sur la case\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t     -----Loyers-----\n");
    printf("\t\t\t\t\t\t\t\t\t\tLorsqu'un joueur tombe sur une case d'un autre\n");
    printf("\t\t\t\t\t\t\t\t\t\tIl doit alors verser le montant du loyer au proprietaire\n");
    printf("\t\t\t\t\t\t\t\t\t\tSi le proprietaire possedent toute les cartes d'une couleur\n");
    printf("\t\t\t\t\t\t\t\t\t\tLe loyer est alors double\n");
    printf("\t\t\t\t\t\t\t\t\t\tLe loyer augmente aussi en placant des maisons et hotels sur une case \n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t_____CHANCE ET CAISSE DE COMMUNAUTE______\n");
    printf("\t\t\t\t\t\t\t\t\t\tLorsqu'un joueur tombe sur Chance ou Caisse de communaute\n");
    printf("\t\t\t\t\t\t\t\t\t\tIl tire la carte du haut et la remet au fond du paquet\n");
    printf("\t\t\t\t\t\t\t\t\t\tCette derniere agit en bonus ou en malus sur:\n");
    printf("\t\t\t\t\t\t\t\t\t\tSon argent\n");
    printf("\t\t\t\t\t\t\t\t\t\tSa position sur le plateau\n");
    printf("\t\t\t\t\t\t\t\t\t\tLe nombre de carte sortie de prison en sa possession\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t______IMPOT SUR LE REVENU______\n");
    printf("\t\t\t\t\t\t\t\t\t\tLorsqu'un.e joueur.euse atterrit sur Impot sur le revenu\n");
    printf("\t\t\t\t\t\t\t\t\t\tIl doit payer l'impôt de 200 € à la Banque. \n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t______STATIONNEMENT GRATUIT______\n");
    printf("\t\t\t\t\t\t\t\t\t\tRien ne se passe\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t______MAISON HOTEL______\n");
    printf("\t\t\t\t\t\t\t\t\t\tLorsequ'un joueur tombe sur une de ses propriete\n");
    printf("\t\t\t\t\t\t\t\t\t\tIl peut acheter une maison au prix indique\n");
    printf("\t\t\t\t\t\t\t\t\t\tSi il en possede deja 4\n");
    printf("\t\t\t\t\t\t\t\t\t\tIl peux acheter un hotel unique par case\n");
    printf("\t\t\t\t\t\t\t\t\t\tLes maisons sont alors rendus a la banque\n");
    printf("\t\t\t\t\t\t\t\t\t\tLes maisons ou hotels peuvent etre vendu a moitie du prix d'achat\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t______HYPOTEQUE______\n");
    printf("\t\t\t\t\t\t\t\t\t\tLes propriete peuvent etre hypotequer a la banque au prix d'hypoteque\n");
    printf("\t\t\t\t\t\t\t\t\t\tLe joueur possede alors toujours la case \n");
    printf("\t\t\t\t\t\t\t\t\t\tIl ne percois alors plus les loyers de la case\n");
    printf("\t\t\t\t\t\t\t\t\t\tCe dernier peut tout de meme racheter la propriete\n");
    printf("\t\t\t\t\t\t\t\t\t\tCette derniere coutera 10% plus cher que son prix d'hypoteque\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t______FAILLITE______\n");
    printf("\t\t\t\t\t\t\t\t\t\tLorsqu'un joueur fait faillite et doit de l'argent a un autre joueur\n");
    printf("\t\t\t\t\t\t\t\t\t\tIl doit remettre à ce joueur tout ce qu'il a de valeur et se retirer du jeu. \n");
    printf("\t\t\t\t\t\t\t\t\t\tS'il est propriétaire de maisons ou d'hotels, il doit les restituer à la Banque \n");
    printf("\t\t\t\t\t\t\t\t\t\tS'il a hypotheque un bien, il remet également son bien à ce creancier\n");
    printf("\t\t\t\t\t\t\t\t\t\tLe nouveau proprietaire doit payer immédiatement à la Banque le montant des intérets \n");
    printf("\t\t\t\t\t\t\t\t\t\tSi un.e joueur.euse doit à la Banque, au lieu d'un autre joueur\n");
    printf("\t\t\t\t\t\t\t\t\t\tEt que par vente de maison ou hypoteque ne peut toujours pas rembourser\n");
    printf("\t\t\t\t\t\t\t\t\t\tIl doit remettre tout ses biens a la banque et se retirer du jeu\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t______FIN DE LA PARTIE______\n");
    printf("\t\t\t\t\t\t\t\t\t\tLa partie se termine quand il ne reste qu'un joueur avec de l'argent\n");
    printf("\n");
}





















int MenuMonopoly ()     //Menu de demande de ce qu'on veut faire
{
    int choix = 0;
    int choix2 = 0;
    int nbrJoueurs = 0;
    monop();
    gotoligcol(2,0);
    printf("----------------------------------------------------------------------------------------- BIENVENUE DANS LE MONOPOLY MONDE !!! ------------------------------------------------------------------------------------");
    gotoligcol(7,90);
    printf("Que voulez vous faire ?");  //Demande des choix possible
    gotoligcol(8,90);
    printf("1.\tCreer une nouvelle partie");
    gotoligcol(9,90);
    printf("2.\tContinuer une ancienne partie");
    gotoligcol(10,90);
    printf("3.\tLire les regles");
    gotoligcol(11,90);
    printf("4.\tQuiter");
    gotoligcol(12,90);
    fflush(stdin);
    scanf("%d",&choix);
    while(choix < 1 || choix > 4)       //Blindage des choix possible
    {
        reset(12,12,0,200);
        gotoligcol(7,90);
        printf("Demande non valide, que voulez vous faire ?");
        gotoligcol(12,90);
        fflush(stdin);
        scanf("%d",&choix);
    }
    if (choix == 1) //On commence une partie
    {
        reset(7,12,0,200);
        gotoligcol(7,90);
        printf("Combien il y a de joueurs ?");
        gotoligcol(8,103);
        fflush(stdin);
        scanf("%d",&nbrJoueurs);
        while (nbrJoueurs < 2 || nbrJoueurs > 8)    //Blindage pour le nombre de joueurs
        {
            reset(7,8,60,150);
            gotoligcol(7,60);
            printf("Nombre de joueur non valide (entre 2 et 8 joueurs), combien il y a de joueurs ?");
            gotoligcol(8,100);
            fflush(stdin);
            scanf("%d",&nbrJoueurs);
        }
        structureJoueur(nbrJoueurs);    //On va dans le sous programme structures joueur, pour crer et remplir toutes les structures
    }
    else if (choix == 2)    //On recupère le fichier d'une partie deja commencé
    {
        ouvrirUneSauvegarde();
    }
    else if (choix == 3)    //On reset l'ecran puis on affiche les règles
    {
        reset(0,20,0,210);

        regles();


        gotoligcol(0,0);
        printf("----------------------------------------------------------------------------------------- BIENVENUE DANS LE MONOPOLY MONDE !!! ------------------------------------------------------------------------------------");
        gotoligcol(5,90);
        printf("Que voulez vous faire ?");  //Demande des choix possible
        gotoligcol(6,90);
        printf("1.\tCreer une nouvelle partie");
        gotoligcol(7,90);
        printf("2.\tContinuer une ancienne partie");
        gotoligcol(8,90);
        printf("3.\tQuiter");
        gotoligcol(10,90);
        fflush(stdin);
        scanf("%d",&choix2);
        while(choix2 < 1 || choix2 > 3)       //Blindage des choix possible
        {
            reset(10,10,0,200);
            gotoligcol(5,90);
            printf("Demande non valide, que voulez vous faire ?");
            gotoligcol(10,90);
            fflush(stdin);
            scanf("%d",&choix2);
        }


        reset(0,200,0,210);


        if (choix2 == 1) //On commence une partie
        {
        reset(5,10,0,200);
        gotoligcol(7,90);
        printf("Combien il y a de joueurs ?");
        gotoligcol(8,103);
        fflush(stdin);
        scanf("%d",&nbrJoueurs);
        while (nbrJoueurs < 2 || nbrJoueurs > 8)    //Blindage pour le nombre de joueurs
        {
            reset(7,8,60,150);
            gotoligcol(7,60);
            printf("Nombre de joueur non valide (entre 2 et 8 joueurs), combien il y a de joueurs ?");
            gotoligcol(8,100);
            fflush(stdin);
            scanf("%d",&nbrJoueurs);
        }
        structureJoueur(nbrJoueurs);    //On va dans le sous programme structures joueur, pour crer et remplir toutes les structures
        }
        else if (choix2 == 2)    //On appel un sous programme pour recupèrer le fichier d'une partie deja commencé
        {
            ouvrirUneSauvegarde();
        }
    }
    else if(choix == 4) //On quitte le programme
    {
        return 0;
    }
}
