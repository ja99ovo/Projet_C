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

#include <math.h>
typedef struct Htree{
  char ch[1];
  int weight;
  struct Htree *parent_node;
  struct Htree *child_node_0;
  struct Htree *child_node_1;
} Htree,Hnode;

struct Htable{
  char ch;
  long code;

};



int main(){
  
Hnode ht1={"a",5,&ht1,&ht1,&ht1};
Hnode ht2={"b",3,&ht1,&ht1,&ht1};
Hnode ht3={"c",1,&ht1,&ht1,&ht1};

Hnode hts[3]={ht1,ht2,ht3};

}




char* Read_file(char* file_name){
  char* file_content;
  //
  return (file_content);
};

//Hnode[] Compt_freq(char* file_content){



//}





Htree Create_tree(Htree Hnode[],int length){

  Htree *HT = (Htree*)malloc(sizeof(Htree)*(length+1));
  int min0 = INFINITY;
  int min1 = INFINITY;
  Hnode Hnode_min_1,Hnode_min_0;
  for(int i=0;i<length;i++)
  {
    if (Hnode[i]->weight < min1){
      Hnode_min_0 = Hnode[i];
      Hnode[i]->height=INFINITY;
    }
  }

  for(int i=0;i<length;i++){
    if (Hnode[i]->weight < min0){
      Hnode_min_1 = Hnode[i];
      Hnode[i]->height=INFINITY;
    }
  }
    
  

}

struct Htable Create_table(){


}

void Codage(){

}