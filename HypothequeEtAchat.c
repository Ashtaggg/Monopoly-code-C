#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "Structures.h"


void miseEnHypoteque (struct joueur *joueurActuel, struct proprietes *Gdynia, struct proprietes *Taipei, struct proprietes *Tokyo, struct proprietes *Barcelone, struct proprietes *Athenes, struct proprietes *Istanbul, struct proprietes *Kyiv, struct proprietes *Toronto, struct proprietes *Rome, struct proprietes *Shanghai, struct proprietes *Vancouver, struct proprietes *Sydney, struct proprietes *NewYork, struct proprietes *Londres, struct proprietes *Beijing, struct proprietes *HongKong, struct proprietes *Jerusalem, struct proprietes *Paris, struct proprietes *Belgrade, struct proprietes *LeCap, struct proprietes *Riga, struct proprietes *Montreal)
{
   p tableauProp[22];
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
       if ((strcmp((tableauProp[i]).proprietaire, (*joueurActuel).prenom)==0))
       {
           int choix =0;
           do
           {
               printf("Choissisez 1 pour hypotequer cette propriete\n ");
               printf("Choissisez 2 pour ne pas hypotequer cette propriete\n ");
               fflush(stdin);
               scanf("%d",&choix);
               if(choix==1)
               {
                   (tableauProp[i]).valHypotheque=1;
                   (*joueurActuel).argent= (*joueurActuel).argent+(tableauProp[i].valeur_hypotheque);
               }


           }while(choix<1||choix>2);

   }

}

}
void RachatHypoteque (struct joueur *joueurActuel, struct proprietes *Gdynia, struct proprietes *Taipei, struct proprietes *Tokyo, struct proprietes *Barcelone, struct proprietes *Athenes, struct proprietes *Istanbul, struct proprietes *Kyiv, struct proprietes *Toronto, struct proprietes *Rome, struct proprietes *Shanghai, struct proprietes *Vancouver, struct proprietes *Sydney, struct proprietes *NewYork, struct proprietes *Londres, struct proprietes *Beijing, struct proprietes *HongKong, struct proprietes *Jerusalem, struct proprietes *Paris, struct proprietes *Belgrade, struct proprietes *LeCap, struct proprietes *Riga, struct proprietes *Montreal)
 {
      p tableauProp[22];
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
       if ((strcmp((tableauProp[i]).proprietaire, (*joueurActuel).prenom)==0))
       {
           if((tableauProp[i]).valHypotheque==1);
           {
            int choix =0;
           do
           {
               printf("Choissisez 1 pour racheter\n ");
               printf("Choissisez 2 sinon\n ");
               fflush(stdin);
               scanf("%d",&choix);
               if(choix==1)
               {

                   (*joueurActuel).argent= (*joueurActuel).argent-1.1*(tableauProp[i].valeur_hypotheque);
                   (tableauProp[i]).valHypotheque=0;
               }


           }while(choix<1||choix>2);
           }


       }

    }
}
