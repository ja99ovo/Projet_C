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
<<<<<<< Updated upstream


struct Htree{
=======
#include <stdlib.h>
#include <math.h>
typedef struct Htree{
  char ch[1];
  int weight;
  struct Htree *parent_node;
  struct Htree *child_node_0;
  struct Htree *child_node_1;
} Htree ;

struct Htable{
  char ch;
  long code;
>>>>>>> Stashed changes

};
struct Freq{


};

<<<<<<< Updated upstream
int main(){
  


}
=======
>>>>>>> Stashed changes




char* Read_file(char* file_name){
  char* file_content;
  //
  return (file_content);
}
<<<<<<< Updated upstream

 struct Htree Compt_freq(char* file_content){
  
}

=======

//Hnode[] Compt_freq(char* file_content){



//}





Htree* Create_tree(Htree HT[],int length){
  if(length==1){
    return HT;
  }
  Htree *Hnode = (Htree*)malloc(sizeof(Htree));
  int min0=INFINITY;
  int min1=INFINITY;
  int min0_index,min1_index;
  Htree Hnode_min_1, Hnode_min_0;
  for(int i=0;i<length;i++)
  {
    if (HT[i].weight < min0){
      Hnode_min_0 = HT[i];
      min0=HT[i].weight;
      min0_index=i;
    }

  }
  for(int i=0;i<length;i++){
    if (HT[i].weight < min1&&HT[i].weight>Hnode_min_0.weight){
      Hnode_min_1 = HT[i];
      min1=HT[i].weight;
      min1_index=i;
    }
  }
    Hnode->parent_node=NULL;
    Htree *p_0=&Hnode_min_0;
    Htree *p_1=&Hnode_min_1;
    Hnode->child_node_0=p_0;
    Hnode->child_node_1=p_1;
    Hnode->weight=Hnode_min_1.weight+Hnode_min_0.weight;
    //printf("weight sum:%d\n",Hnode->weight);
    Htree new_tree[length-1];
    //printf("\nlength new:%d, length old: %d",sizeof(new_tree)/sizeof(new_tree[0]),length);
    for(int i=0;i<length-1;i++){
      if (i!=min0_index&&i!=min1_index){
        new_tree[i]=HT[i];
    }

    new_tree[length-2]=*Hnode;
    return Create_tree(new_tree,length-1);

  }
}



/*struct Htable[]*/void Create_table(Htree *Tree){
  Htree *next;
  Htree *p_child_1=Tree->child_node_1; 
  Htree *p_child_0=Tree->child_node_0; 
  if(p_child_1!=0){
    printf("1");
    next = p_child_1;
    Create_table(next);
  }
  if (p_child_0!=0)
  {
    printf("0");
    next = p_child_0;
    Create_table(next);
  }
  printf("%s\n",Tree->ch);

}
>>>>>>> Stashed changes


<<<<<<< Updated upstream
=======
}



int main(){
  Htree ht1={"a",50,NULL,NULL,NULL};
  Htree ht2={"b",8,NULL,NULL,NULL};
  Htree ht3={"c",13,NULL,NULL,NULL};
  Htree hts[3]={ht1,ht2,ht3};


  int length=sizeof(hts)/sizeof(hts[0]);
  
  Htree *head=Create_tree(hts,length);
  Create_table(&head[0]);

}
>>>>>>> Stashed changes
