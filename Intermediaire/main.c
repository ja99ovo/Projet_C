#include <stdio.h>
#include<stdlib.h>

int ordi(int al, int diff){
    if(diff==1){
      int al_pris=rand()%3 +1;
        if(al_pris>=al) 
            return al;
        else
            return al_pris;
    }
    else if(diff==2)
    {
        if (al==2|al==6|al==10|al==14|al==18|al==22|al==26|al==30)
            return 1;
        else if (al==3|al==7|al==11|al==15|al==19|al==23|al==27)
            return 2;
        else if(al==4|al==8|al==12|al==16|al==20|al==24|al==28)
            return 3;
        else if (al==5|al==9|al==13|al==17|al==21|al==25|al==29)
            return rand()%3 +1;
        else if(al==1)
            return 1;
    }
}

void jouer(int al,int mode, int diff){
    printf("Nb d’allumettes restantes : %d\n",al);
    for(int i=0;i<al;i++){
        printf("|");
    }
    printf("\nAu tour de joueur 1:\nCombien prenez-vous d’allumettes ?  ");
    int j1_nb
    [1];
    scanf("%d",j1_nb);
    while(j1_nb[0]>3||j1_nb[0]<1){
        printf("\nPrise invalide : %d\n",j1_nb[0]);
        scanf("%d",j1_nb);
    }
    if(al-j1_nb[0]<=0){
        printf("\njoueur1 a perdu!\n");
        return NULL;
    }
    else{
        al-=j1_nb[0];
    }
    
    printf("Nb d’allumettes restantes : %d\n",al);
    for(int i=0;i<al;i++){
        printf("|");
    }

    switch (mode)
    {
    case 1:
        printf("\nAu tour de joueur 2:\nCombien prenez-vous d’allumettes ?  ");
        int j2_nb[1];
        scanf("%d",j2_nb);
        while(j2_nb[0]>3||j2_nb[0]<1){
            printf("\nPrise invalide : %d\n",j2_nb[0]);
            scanf("%d",j2_nb);
        }
        if(al-j2_nb[0]<=0){
            printf("\njoueur2 a perdu!\n");
            return NULL;
        }
        else{
            jouer(al-j2_nb[0],mode,diff);
        }
        
    case 2:
        int ord_nb=ordi(al, diff);
        printf("\nAu tour d'ordinateur.\nOrdinateur prned %d allumette(s)\n", ord_nb);
        if(ord_nb-al==0){
            printf("\nordinateur a perdu\n");
            return NULL;
        }
        else {
            jouer(al-ord_nb,mode,diff);
        }
        
    }

}

void menu(){
    printf("Que faire?\n1 - jouer\n2 - Voir les regles du jeu\n3 - Voir les credits\n4 - Quitter\n");
    int s[1];
    scanf( "%d", s);
    printf("votre choix : %d\n",s[0]);
    switch (s[0]){
        case 1:
            printf("jouer avec? 1 - joueur   2 - ordi\n");
            int mode[1];
            scanf( "%d", mode);
            printf("votre choix : %d\n",mode[0]);
            switch(mode[0]){                                        //choisir mode jouer
                case 1: jouer(30,1,0);break;                        //si jouer avec joueur
                case 2:
                    int diff[1];
                    printf("niveau:\n1 - facile\n2 - difficile\n");
                    scanf("%d",diff);
                    switch (diff[0])                                //choisir nivo
                    {
                        case 1:
                            jouer(30,2,1);
                            break;
                        case 2:
                            jouer(30,2,2);
                            break;
                    }
        }
        break;
        case 2:
            printf("afficher les reglès\n");
        break;
}
}

int main(){
printf("jeu des allumets\n");
printf("bonjour\n");
while(1)menu();

}