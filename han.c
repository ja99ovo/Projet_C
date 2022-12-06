#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define TRUE 1
#define abccc 1
#define FALSE 0

 typedef struct personne {
 char * nom;
 char * prenom;
 bool homme;
 } Personne;



 typedef struct membreRonde {
 Personne * personne;
 struct membreRonde * voisinGauche;
 struct membreRonde * voisinDroit;
 } MembreRonde;


 void afficherPersonne( Personne * ptrPersonne){
   if (ptrPersonne != NULL)
    { if(ptrPersonne->homme)
         printf ("这是一个男的\n");

   else printf ("这是一个女的\n");
   }
   printf ("%s, %s",ptrPersonne->nom,ptrPersonne->prenom);
 }
 void afficherRonde( MembreRonde * ptrMembreRonde){
   afficherPersonne(ptrMembreRonde->personne);
   //printf("name: %s\n",ptrMembreRonde->personne->nom);
   if(ptrMembreRonde->voisinGauche){
    afficherRonde(ptrMembreRonde->voisinGauche);
   }
    
 }
 MembreRonde * creerRondeSolitaire( Personne * ptrPersonne){
    MembreRonde* first_personne=(MembreRonde*)malloc(sizeof(MembreRonde));
    first_personne->personne=ptrPersonne;
    first_personne->voisinDroit=first_personne;
    first_personne->voisinGauche=first_personne;
    return first_personne;
 }


 MembreRonde* insererAGaucheDe( MembreRonde * ptrMembreRonde, Personne * ptrPersonne){
    if(ptrMembreRonde){
    MembreRonde *ptrNouveau=malloc(sizeof(MembreRonde));
    ptrNouveau->personne=ptrPersonne;
    ptrNouveau->voisinGauche=ptrMembreRonde->voisinGauche;
    ptrNouveau->voisinDroit=ptrMembreRonde;
    ptrMembreRonde->voisinGauche=ptrNouveau;
    ptrMembreRonde->voisinGauche->voisinDroit;
    return ptrNouveau;

    }

 }
 void insererADroiteDe( MembreRonde * ptrMembreRonde, Personne * ptrPersonne){

 }
 int main() {

 Personne p1 = {"Fzefzef", "Roger", abccc };
 Personne p2 = {"Williams", "Serena", FALSE };
 Personne p3 = {"Nadal", "Rafael", 1 };
 Personne p4 = {"Dementieva", "Elena", FALSE };




 MembreRonde * ptrChefDeRonde = creerRondeSolitaire(&p1);
 //afficherRonde(ptrChefDeRonde);
 //printf("\n\n");
 MembreRonde* new;
 new=insererAGaucheDe(ptrChefDeRonde, &p3);
 //afficherRonde(new);
 //printf("\n\n");
 new=insererAGaucheDe(ptrChefDeRonde, &p2);
 insererAGaucheDe(ptrChefDeRonde, &p4);
 afficherRonde(ptrChefDeRonde);
 printf("\n\n");
 /*
 insererADroiteDe(ptrChefDeRonde, &p4);
 afficherRonde(ptrChefDeRonde);
 printf("\n\n");*/
 getchar();
 }
