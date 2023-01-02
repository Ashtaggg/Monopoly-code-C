
///-------------------------------------------------------- Menu Vente --------------------------------------------------------


void vente(struct joueur *joueurActuel, struct proprietes *proprieteAVendre)
{
    int col = 130;
    reset(4,50,col,col+80);
    int choix = 0;
    int prixTotal = 0;
    switch ((*proprieteAVendre).nbrMaisons)
    {
        ///------------------------------------------------ 0 maison ------------------------------------------------
        case 0 :
            (*joueurActuel).nbrProprietes -= 1;
            (*joueurActuel).argent += (*proprieteAVendre).prix  / 2;
            strcpy((*proprieteAVendre).proprietaire, "Banque");
            break;

        ///------------------------------------------------ 1 maison ------------------------------------------------
        case 1 :
            prixTotal = (*proprieteAVendre).prix  / 2 + (*proprieteAVendre).prix_maison  / 2;
            gotoligcol(6,col);
            printf("Selectionnez ce que vous voulez faire :");
            gotoligcol(7,col);
            printf("1. Vendre la maison et la propriete pour %d dollards.", prixTotal);
            gotoligcol(8,col);
            printf("2. Vendre uniquement la maison.", (*proprieteAVendre).prix_maison  / 2);
            gotoligcol(9,col);
            fflush(stdin);
            scanf("%d", &choix);
            while (choix < 1 || choix > 2)
            {
                reset(9,9,col,col+50);
                gotoligcol(6,col);
                printf("Demande non valide, selectionnez ce que vous voulez faire :");
                gotoligcol(9,col);
                fflush(stdin);
                scanf("%d",&choix);
            }
            if (choix == 1)
            {
                (*joueurActuel).nbrProprietes -= 1;
                (*proprieteAVendre).nbrMaisons = 0;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                strcpy((*proprieteAVendre).proprietaire, "Banque");
                (*joueurActuel).argent += prixTotal;
                gotoligcol(11,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if (choix == 2)
            {
                (*proprieteAVendre).nbrMaisons -= 1;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison  / 2;
                gotoligcol(11,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            break;

        ///------------------------------------------------ 2 maisons ------------------------------------------------
        case 2 :
            prixTotal = (*proprieteAVendre).prix  / 2 + (*proprieteAVendre).prix_maison;
            gotoligcol(6,col);
            printf("Selectionnez ce que vous voulez faire :");
            gotoligcol(7,col);
            printf("1. Vendre les maisons et la propriete pour %d dollards.", prixTotal);
            gotoligcol(8,col);
            printf("2. Vendre une maison pour %d dollards.", (*proprieteAVendre).prix_maison  / 2);
            gotoligcol(9,col);
            printf("3. Vendre 2 maisons pour %d dollards.", (*proprieteAVendre).prix_maison);
            gotoligcol(10,col);
            fflush(stdin);
            scanf("%d", &choix);
            while (choix < 1 || choix > 3)
            {
                reset(10,10,col,col+50);
                gotoligcol(6,col);
                printf("Demande non valide, selectionnez ce que vous voulez faire :");
                gotoligcol(10,col);
                fflush(stdin);
                scanf("%d", &choix);
            }
            if (choix == 1)
            {
                (*joueurActuel).nbrProprietes -= 1;
                (*proprieteAVendre).nbrMaisons = 0;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                strcpy((*proprieteAVendre).proprietaire, "Banque");
                (*joueurActuel).argent += prixTotal;
                gotoligcol(12,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if (choix == 2)
            {
                (*proprieteAVendre).nbrMaisons -= 1;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                maison1((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison  / 2;
                gotoligcol(12,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if(choix == 3)
            {
                (*proprieteAVendre).nbrMaisons -= 2;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison;
                gotoligcol(12,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            break;

        ///------------------------------------------------ 3 maisons ------------------------------------------------
        case 3 :
            prixTotal = (*proprieteAVendre).prix  / 2 + (*proprieteAVendre).prix_maison*3/2;
            gotoligcol(6,col);
            printf("Selectionnez ce que vous voulez faire :\n");
            gotoligcol(7,col);
            printf("1. Vendre les maisons et la propriete pour %d dollards.", prixTotal);
            gotoligcol(8,col);
            printf("2. Vendre une maison pour %d dollards.\n", (*proprieteAVendre).prix_maison  / 2);
            gotoligcol(9,col);
            printf("3. Vendre 2 maisons pour %d dollards.\n", (*proprieteAVendre).prix_maison);
            gotoligcol(10,col);
            printf("4. Vendre 3 maisons pour %d dollards.\n", (*proprieteAVendre).prix_maison * 3 / 2);
            gotoligcol(11,col);
            fflush(stdin);
            scanf("%d", &choix);
            while (choix < 1 || choix > 4)
            {
                reset(11,11,col,col+50);
                gotoligcol(6,col);
                printf("Demande non valide, selectionnez ce que vous voulez faire :");
                gotoligcol(11,col);
                fflush(stdin);
                scanf("%d", &choix);
            }
            if (choix == 1)
            {
                (*joueurActuel).nbrProprietes -= 1;
                (*proprieteAVendre).nbrMaisons = 0;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                strcpy((*proprieteAVendre).proprietaire, "Banque");
                (*joueurActuel).argent += prixTotal;
                gotoligcol(13,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if (choix == 2)
            {
                (*proprieteAVendre).nbrMaisons -= 1;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                maison2((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison  / 2;
                gotoligcol(13,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if(choix == 3)
            {
                (*proprieteAVendre).nbrMaisons -= 2;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                maison1((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison;
                gotoligcol(13,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if(choix == 4)
            {
                (*proprieteAVendre).nbrMaisons -= 3;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison*3/2;
                gotoligcol(13,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            break;

        ///------------------------------------------------ 4 maisons ------------------------------------------------
        case 4 :
            prixTotal = (*proprieteAVendre).prix  / 2 + (*proprieteAVendre).prix_maison*3/2;
            gotoligcol(6,col);
            printf("Selectionnez ce que vous voulez faire :");
            gotoligcol(7,col);
            printf("1. Vendre les maisons et la propriete pour %d dollards.", prixTotal);
            gotoligcol(8,col);
            printf("2. Vendre une maison pour %d dollards.", (*proprieteAVendre).prix_maison  / 2);
            gotoligcol(9,col);
            printf("3. Vendre 2 maisons pour %d dollards.", (*proprieteAVendre).prix_maison);
            gotoligcol(10,col);
            printf("4. Vendre 3 maisons pour %d dollards.", (*proprieteAVendre).prix_maison * 3 / 2);
            gotoligcol(11,col);
            printf("5. Vendre 4 maisons pour %d dollards.", (*proprieteAVendre).prix_maison * 2);
            gotoligcol(12,col);
            fflush(stdin);
            scanf("%d", &choix);
            while (choix < 1 || choix > 4)
            {
                reset(12,12,col,col+50);
                gotoligcol(6,col);
                printf("Demande non valide, selectionnez ce que vous voulez faire :");
                gotoligcol(14,col);
                fflush(stdin);
                scanf("%d", &choix);
            }
            if (choix == 1)
            {
                (*joueurActuel).nbrProprietes -= 1;
                (*proprieteAVendre).nbrMaisons = 0;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                strcpy((*proprieteAVendre).proprietaire, "Banque");
                (*joueurActuel).argent += prixTotal;
                gotoligcol(14,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if (choix == 2)
            {
                (*proprieteAVendre).nbrMaisons -= 1;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                maison3((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison  / 2;
                gotoligcol(11,col);
                printf("%d", (*proprieteAVendre).numPlateau);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);
                scanf("%d", &col);

            }
            else if(choix == 3)
            {
                (*proprieteAVendre).nbrMaisons -= 2;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                maison2((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison;
                gotoligcol(14,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if(choix == 4)
            {
                (*proprieteAVendre).nbrMaisons -= 3;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                maison1((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison*3/2;
                gotoligcol(14,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if(choix == 5)
            {
                (*proprieteAVendre).nbrMaisons -= 4;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                EnleverBatiment((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison * 2;
                gotoligcol(14,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            break;

        ///------------------------------------------- 4 maisons + un hotel ------------------------------------------
        case 5 :
            prixTotal = (*proprieteAVendre).prix  / 2 + (*proprieteAVendre).prix_maison*5/2;
            gotoligcol(6,col);
            printf("Selectionnez ce que vous voulez faire :");
            gotoligcol(7,col);
            printf("1. Vendre l'hotel, les maisons et la propriete pour %d dollards.", prixTotal);
            gotoligcol(8,col);
            printf("2. Vendre une maison et un hotel pour %d dollards.\n", (*proprieteAVendre).prix_maison);
            gotoligcol(9,col);
            printf("3. Vendre 2 maisons et un hotel pour %d dollards.\n", (*proprieteAVendre).prix_maison * 3 / 2);
            gotoligcol(10,col);
            printf("4. Vendre 3 maisons  et un hotel pour %d dollards.\n", (*proprieteAVendre).prix_maison * 2);
            gotoligcol(11,col);
            printf("5. Vendre 4 maisons  et un hotel pour %d dollards.\n", (*proprieteAVendre).prix_maison * 5 / 2);
            gotoligcol(12,col);
            printf("6. Vendre un hotel pour %d dollards.\n", (*proprieteAVendre).prix_maison / 2);
            gotoligcol(13,col);
            fflush(stdin);
            scanf("%d", &choix);
            while (choix < 1 || choix > 4)
            {
                reset(13,13,col,col+50);
                gotoligcol(6,col);
                printf("Demande non valide, selectionnez ce que vous voulez faire :");
                gotoligcol(13,col);
                fflush(stdin);
                scanf("%d", &choix);
            }
            if (choix == 1)
            {
                (*joueurActuel).nbrProprietes -= 1;
                (*proprieteAVendre).nbrMaisons = 0;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                strcpy((*proprieteAVendre).proprietaire, "Banque");
                (*joueurActuel).argent += prixTotal;
                gotoligcol(15,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if (choix == 2)
            {
                (*proprieteAVendre).nbrMaisons -= 1;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                maison3((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison  / 2;
                gotoligcol(15,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if(choix == 3)
            {
                (*proprieteAVendre).nbrMaisons -= 2;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                maison2((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison;
                gotoligcol(15,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if(choix == 4)
            {
                (*proprieteAVendre).nbrMaisons -= 3;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                maison1((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison*3/2;
                gotoligcol(15,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if(choix == 5)
            {
                (*proprieteAVendre).nbrMaisons -= 4;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison * 2;
                gotoligcol(15,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            else if(choix == 6)
            {
                (*proprieteAVendre).nbrMaisons -= 5;
                EnleverBatiment((*proprieteAVendre).numPlateau);
                maison4((*proprieteAVendre).numPlateau);
                (*joueurActuel).argent += (*proprieteAVendre).prix_maison * 5 / 2;
                gotoligcol(15,col);
                printf("%s possede maintenant %d dollars",(*joueurActuel).prenom, (*joueurActuel).argent);

            }
            break;

    }
    reset(4,40,col,col+80);
}











void menuVente(struct joueur *joueurActuel, struct proprietes *Gdynia, struct proprietes *Taipei, struct proprietes *Tokyo, struct proprietes *Barcelone, struct proprietes *Athenes, struct proprietes *Istanbul, struct proprietes *Kyiv, struct proprietes *Toronto, struct proprietes *Rome, struct proprietes *Shanghai, struct proprietes *Vancouver, struct proprietes *Sydney, struct proprietes *NewYork, struct proprietes *Londres, struct proprietes *Beijing, struct proprietes *HongKong, struct proprietes *Jerusalem, struct proprietes *Paris, struct proprietes *Belgrade, struct proprietes *LeCap, struct proprietes *Riga, struct proprietes *Montreal)
{

    int comparer1 = 1;
    int comparer2 = 1;
    int comparer3 = 1;
    int comparer4 = 1;
    int comparer5 = 1;
    int comparer6 = 1;
    int comparer7 = 1;
    int comparer8 = 1;
    int comparer9 = 1;
    int comparer10 = 1;
    int comparer11 = 1;
    int comparer12 = 1;
    int comparer13 = 1;
    int comparer14 = 1;
    int comparer15 = 1;
    int comparer16 = 1;
    int comparer17 = 1;
    int comparer18 = 1;
    int comparer19 = 1;
    int comparer20 = 1;
    int comparer21 = 1;
    int comparer22 = 1;

    comparer1 = strcmp((*joueurActuel).prenom, (*Gdynia).proprietaire);
    comparer2 = strcmp((*joueurActuel).prenom, (*Taipei).proprietaire);
    comparer3 = strcmp((*joueurActuel).prenom, (*Tokyo).proprietaire);
    comparer4 = strcmp((*joueurActuel).prenom, (*Barcelone).proprietaire);
    comparer5 = strcmp((*joueurActuel).prenom, (*Athenes).proprietaire);
    comparer6 = strcmp((*joueurActuel).prenom, (*Istanbul).proprietaire);
    comparer7 = strcmp((*joueurActuel).prenom, (*Kyiv).proprietaire);
    comparer8 = strcmp((*joueurActuel).prenom, (*Toronto).proprietaire);
    comparer9 = strcmp((*joueurActuel).prenom, (*Rome).proprietaire);
    comparer10 = strcmp((*joueurActuel).prenom, (*Shanghai).proprietaire);
    comparer11 = strcmp((*joueurActuel).prenom, (*Vancouver).proprietaire);
    comparer12 = strcmp((*joueurActuel).prenom, (*Sydney).proprietaire);
    comparer13 = strcmp((*joueurActuel).prenom, (*NewYork).proprietaire);
    comparer14 = strcmp((*joueurActuel).prenom, (*Londres).proprietaire);
    comparer15 = strcmp((*joueurActuel).prenom, (*Beijing).proprietaire);
    comparer16 = strcmp((*joueurActuel).prenom, (*HongKong).proprietaire);
    comparer17 = strcmp((*joueurActuel).prenom, (*Jerusalem).proprietaire);
    comparer18 = strcmp((*joueurActuel).prenom, (*Paris).proprietaire);
    comparer19 = strcmp((*joueurActuel).prenom, (*Belgrade).proprietaire);
    comparer20 = strcmp((*joueurActuel).prenom, (*LeCap).proprietaire);
    comparer21 = strcmp((*joueurActuel).prenom, (*Riga).proprietaire);
    comparer22 = strcmp((*joueurActuel).prenom, (*Montreal).proprietaire);




    affichageProprietesJoueurAvecNumero(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);///Affichage des proprietes

    //affichage des proprietes en menu aves des numeros des cases

    int col = 130;
    int choix = 0;
    gotoligcol(10 + (*joueurActuel).nbrProprietes ,col);
    printf("Saisissez le numero de la case de la propriete que vous voulez vendre :");
    gotoligcol(11 + (*joueurActuel).nbrProprietes,col);
    fflush(stdin);
    scanf("%d", &choix);
    while (choix < 2 || choix > 32 && choix != 4 && choix != 5 && choix != 9 && choix != 13 && choix != 17 && choix != 21 && choix != 25 && choix != 29 && choix != 31)
    {
        reset(11,11,col,col+80);
        gotoligcol(10 + (*joueurActuel).nbrProprietes,col);
        printf("Demande non valide, saisissez le numero de la case de la propriete que vous voulez vendre : ");
        gotoligcol(11 + (*joueurActuel).nbrProprietes,col);
        fflush(stdin);
        scanf("%d", &choix);
    }
    switch (choix)
    {
        case 2 :
            if (comparer1 == 0)
            {
                vente(joueurActuel, Gdynia);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;
        case 3:
            if (comparer2 == 0)
            {
                vente(joueurActuel, Taipei);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 6:
            if (comparer3 == 0)
            {
                vente(joueurActuel, Tokyo);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 7:
            if (comparer4 == 0)
            {
                vente(joueurActuel, Barcelone);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");

            }
            break;

        case 8:
            if (comparer5 == 0)
            {
                vente(joueurActuel, Athenes);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");

            }
            break;

        case 10:
            if (comparer6 == 0)
            {
                vente(joueurActuel, Istanbul);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne passez pas cette propriete.");
            }
            break;

        case 11:
            if (comparer7 == 0)
            {
                vente(joueurActuel, Kyiv);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 12:
            if (comparer8 == 0)
            {
                vente(joueurActuel, Toronto);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 14:
            if (comparer9 == 0)
            {
                vente(joueurActuel, Rome);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 15:
            if (comparer10 == 0)
            {
                vente(joueurActuel, Shanghai);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 16:
            if (comparer11 == 0)
            {
                vente(joueurActuel, Vancouver);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 18:
            if (comparer12 == 0)
            {
                vente(joueurActuel, Sydney);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }

            break;

        case 19:
            if (comparer13 == 0)
            {
                vente(joueurActuel, NewYork);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 20:
            if (comparer14 == 0)
            {
                vente(joueurActuel, Londres);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 22:
            if (comparer15 == 0)
            {
                vente(joueurActuel, Beijing);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 23:
            if (comparer16 == 0)
            {
                vente(joueurActuel, HongKong);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 24:
            if (comparer17 == 0)
            {
                vente(joueurActuel, Jerusalem);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 26:
            if (comparer18 == 0)
            {
                vente(joueurActuel, Paris);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 27:
            if (comparer19 == 0)
            {
                vente(joueurActuel, Belgrade);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 28:
            if (comparer20 == 0)
            {
                vente(joueurActuel, LeCap);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 30:
            if (comparer21 == 0)
            {
                vente(joueurActuel, Riga);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;

        case 32:
            if (comparer22 == 0)
            {
                vente(joueurActuel, Montreal);
            }
            else
            {
                gotoligcol(10,col);
                printf("Vous ne possedez pas cette propriete.");
            }
            break;
    }
}













///----------------------------------------MENU FAILLITE-----------------------------------------------------


void faillite(struct joueur *joueurActuel, struct proprietes *Gdynia, struct proprietes *Taipei, struct proprietes *Tokyo, struct proprietes *Barcelone, struct proprietes *Athenes, struct proprietes *Istanbul, struct proprietes *Kyiv, struct proprietes *Toronto, struct proprietes *Rome, struct proprietes *Shanghai, struct proprietes *Vancouver, struct proprietes *Sydney, struct proprietes *NewYork, struct proprietes *Londres, struct proprietes *Beijing, struct proprietes *HongKong, struct proprietes *Jerusalem, struct proprietes *Paris, struct proprietes *Belgrade, struct proprietes *LeCap, struct proprietes *Riga, struct proprietes *Montreal)
{
    int col = 130;
    int choix = 0;
    gotoligcol(6, col);
    printf("Que voulez vous faire ?");
    gotoligcol(7, col);
    printf("1.\tHypothequer");
    gotoligcol(8, col);
    printf("2.\tVendre");
    gotoligcol(9, col);
    printf("3.\tRacheter une propriete hypothequee");
    gotoligcol(10, col);
    fflush(stdin);
    scanf("%d", &choix);
    while(choix < 1 || choix > 3)
    {
        reset(10,10,col,col+30);
        gotoligcol(6, col);
        printf("Que voulez vous faire ?");
        gotoligcol(7, col);
        printf("1.\tHypothequer");
        gotoligcol(8, col);
        printf("2.\tVendre");
        gotoligcol(9, col);
        printf("3.\tRacheter une propriete hypothequee");
        gotoligcol(10, col);
        fflush(stdin);
        scanf("%d", &choix);
    }
    if (choix == 1)
    {
        reset(4,50,col,col+80);
        miseEnHypoteque(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
    }
    else if (choix == 2)
    {
        reset(4,50,col,col+80);
        menuVente(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
    }
    else if (choix == 3)
    {
        reset(4,50,col,col+80);
        RachatHypoteque(joueurActuel, Gdynia, Taipei, Tokyo, Barcelone, Athenes, Istanbul, Kyiv, Toronto, Rome, Shanghai, Vancouver, Sydney, NewYork, Londres, Beijing, HongKong, Jerusalem, Paris, Belgrade, LeCap, Riga, Montreal);
    }
    if ((*joueurActuel).argent <= 0 && (*joueurActuel).nbrProprietes == 0)
    {
        reset(4,50,col,col+80);
        gotoligcol(5,col);
        printf("Vous n'avez plus de proprietes");
        gotoligcol(6,col);
        printf("Vous etes donc elimine !");
        (*joueurActuel).enJeu = 0;
    }





}
