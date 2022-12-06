#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define TRUE 1
#define FALSE 0

 typedef struct personne { 
 char * nom;
 char * prenom;
 bool homme;
 } Personne;

 typedef struct membreRonde {  //结构体
 Personne * personne;  
 struct membreRonde * voisinGauche;
 struct membreRonde * voisinDroit;
 } MembreRonde;




 void afficherPersonne( Personne * ptrPersonne){
       if (ptrPersonne != NUll)
       { if(ptrPersonne->homme==TRUE)
              printf ("这是一个男的");
       
       else   printf ("这是一个女的");
       }
   printf ("%s, %s",ptrPersonne->nom,ptrPersonne->prenom);
              
     }
       







 }






        
 void afficherRonde( MembreRonde * ptrMembreRonde);
 MembreRonde * creerRondeSolitaire( Personne * ptrPersonne);
2
 void insererAGaucheDe( MembreRonde * ptrMembreRonde, Personne * ptrPersonne);
 void insererADroiteDe( MembreRonde * ptrMembreRonde, Personne * ptrPersonne);





 main() {

 Personne p1 = {"Federer", "Roger", TRUE };
 Personne p2 = {"Williams", "Serena", FALSE };
 Personne p3 = {"Nadal", "Rafael", TRUE };
 Personne p4 = {"Dementieva", "Elena", FALSE };

 MembreRonde * ptrChefDeRonde = creerRondeSolitaire(&p1);
 afficherRonde(ptrChefDeRonde);
 printf("\n\n");
 insererAGaucheDe(ptrChefDeRonde, &p3);
 afficherRonde(ptrChefDeRonde);
 printf("\n\n");
 insererAGaucheDe(ptrChefDeRonde, &p2);
 afficherRonde(ptrChefDeRonde);
 printf("\n\n");
 insererADroiteDe(ptrChefDeRonde, &p4);
 afficherRonde(ptrChefDeRonde);
 printf("\n\n");

 }
