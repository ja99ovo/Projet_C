/*interface

choisir le fonctionnement
  1. compresser
      function 1 : read file (char* file_name) return char* file_content
      function 2 : compter fréquence (char* file_content) return struct fréq(char caractère, int fois)
      function 3 : générer l'arbre (struct fréq ) return struct Htree arbre
      function 4 : générer le tableau de codage (Htree arbre) return tableau
      function 5 : coder la texte et sauvgarder en txt (char* file_content, Htree arbre) return void
  2. décompresser
      indéterminé
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Htree{
  char ch[1];
  int weight;
  char code; 
  struct Htree *parent_node;
  struct Htree *child_node_0;
  struct Htree *child_node_1;
} Htree ;

typedef struct Htable{
  char ch[1];
  char* code;
  } Htable;

char* Read_file(char* file_name){
  char* file_content;
  //
  return (file_content);
}


Htree * Create_tree(Htree HT[],int length,int cycle){
  if(length==1){
    return HT;
  }

  int min0=INFINITY;
  int min1=INFINITY;
  int min0_index,min1_index;
  Htree Hnode_min_1, Hnode_min_0;
  for(int i=0;i<cycle;i++)
  {
    if (HT[i].weight < min0){
      Hnode_min_0 = HT[i];
      min0=HT[i].weight;
      min0_index=i;
    }

  }
  for(int i=0;i<cycle;i++){
    if (HT[i].weight < min1&&HT[i].weight>Hnode_min_0.weight){
      Hnode_min_1 = HT[i];
      min1=HT[i].weight;
      min1_index=i;
    }
  }

    Htree * p_0=&Hnode_min_0;
    Htree * p_1=&Hnode_min_1;

    HT[cycle].child_node_0=&HT[min0_index];
    HT[min0_index].parent_node=&HT[cycle];
    HT[min0_index].code='0';
    HT[min1_index].parent_node=&HT[cycle];
    HT[min1_index].code='1';
    HT[cycle].child_node_1=&HT[min1_index];
    HT[cycle].parent_node=NULL;
    HT[cycle].weight=Hnode_min_1.weight+Hnode_min_0.weight;
    HT[min0_index].weight=INFINITY;
    HT[min1_index].weight=INFINITY;
    Htree * new_tree = (Htree*)malloc(sizeof(Htree)*(length-1));
    return Create_tree(HT,length-1,cycle+1);  
}


char* Create_table(Htree *hnode,int cycle,char* code){
  if(hnode->parent_node){
    code[cycle]=hnode->code;
    return Create_table(hnode->parent_node,cycle+1,code);
  }
  return code;
}

int main(){
  Htree ht1={'a',50,NULL,NULL, NULL,NULL};
  Htree ht2={'b',8,NULL,NULL,NULL,NULL};
  Htree ht3={'c',13,NULL,NULL,NULL,NULL};
  Htree ht4={'d',3,NULL,NULL,NULL,NULL};
  Htree ht5={'e',32,NULL,NULL,NULL,NULL};
  Htree ht6={'f',23,NULL,NULL,NULL,NULL};
  Htree hts[6]={ht1,ht2,ht3,ht4,ht5,ht6};
  int length=sizeof(hts)/sizeof(hts[0]);
  Htree * Hnode_tree = (Htree*)malloc(sizeof(Htree)*(length+length-1));
  for(int i=0;i<length;i++){
    Hnode_tree[i]=hts[i];
  }
  

  Htree *head=Create_tree(Hnode_tree,length,length);

  Htable htable[length];
  for(int i=0;i<length;i++){
      htable[i].ch[0]=head[i].ch[0];
      char code[50]={};
      htable[i].code=Create_table(&head[i],0,&code);
      printf("%s:%c\n",htable[i].code,htable[i].ch[0]);

  }
  

}