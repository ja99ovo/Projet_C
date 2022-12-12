#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Htree{
  char ch[1];
  int weight;
  char code; 
  struct Htree* parent_node;
  struct Htree* child_node_0;
  struct Htree* child_node_1;
} Htree ;

typedef struct Htable{
  char ch[1];
  char* code;
  int len_code;
  } Htable;

int File_len(char* file_name){
FILE *fp;
	if ((fp = fopen(file_name, "rb")) == NULL)
	{
		exit(0);
	}
	fseek(fp, 0, SEEK_END);
	int fileLen = ftell(fp);

  return fileLen;
}


void Write_file(char* file_name,char str){
    FILE* output_file = fopen(file_name, "a");
    if (!output_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fputc(str, output_file);

    fclose(output_file);
    exit(EXIT_SUCCESS);
}


char* Read_file(char* file_name){
  FILE *fp;
	if ((fp = fopen(file_name, "rb")) == NULL)
	{
		exit(0);
	}
	fseek(fp, 0, SEEK_END);
	int fileLen = ftell(fp);
	char *file_content = (char *) malloc(sizeof(char) * (fileLen+1));
	fseek(fp, 0, SEEK_SET);
	fread(file_content, fileLen, sizeof(char), fp);
	fclose(fp);

  file_content[fileLen]='\0';
  //printf("file len:%d\n",fileLen);
  return file_content;
}

Htree* cal_freq(char* file_content){
  Htree* char_list=(Htree*)malloc(sizeof(Htree)*50);
  for(int i=0;i<50;i++){
    char_list[i].ch[0]=NULL;
  }
  int char_index=0;
  int ccc=strlen(file_content);
  for(int i =0;i<strlen(file_content);i++){
    bool found=false;
    for(int ii=0;ii<50;ii++){
      if(char_list[ii].ch[0]==file_content[i]){
        char_list[ii].weight++;
        found=true;
        break;
      }
    }
    if(!found){
    char_list[char_index].ch[0]=file_content[i];
    char_list[char_index].weight=1;
    char_list[char_index].parent_node=NULL;
    char_list[char_index].child_node_0=NULL;
    char_list[char_index].child_node_1=NULL;
    char_list[char_index].code=NULL;
    char_index++;
    }
  }

  Htree* final_char_list=(Htree*)malloc(sizeof(Htree)*char_index);
  for(int i=0;i<char_index;i++){
    final_char_list[i]=char_list[i];
    printf("%c : %d\n",char_list[i].ch[0],char_list[i].weight);
  }
  return final_char_list;
}

Htree* Create_tree(Htree HT[],int length,int cycle){
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

    Htree* p_0=&Hnode_min_0;
    Htree* p_1=&Hnode_min_1;

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
    Htree* new_tree = (Htree*)malloc(sizeof(Htree)*(length-1));
    return Create_tree(HT,length-1,cycle+1);  
}


char* Get_code(Htree* hnode,int cycle,char* code){
  if(hnode->parent_node){
    code[cycle]=hnode->code;
    return Get_code(hnode->parent_node,cycle+1,code);
  }
  code = (char*)realloc(code, cycle+1);
  code[cycle]='\0';
  return code;
}


Htable* Create_Table(Htree* head,int length){
  Htable* htable=(Htable*)malloc(sizeof(Htable)*length);

  for(int i=0;i<length;i++){
      htable[i].code = (char*)malloc(sizeof(char)*50);
      htable[i].ch[0]=head[i].ch[0];
      htable[i].code=Get_code(&head[i],0,htable[i].code);
      int iii=0;
      while(htable[i].code[iii]!='\0'){
        iii++;
      }
      htable[i].len_code=iii;
      char code_re[50];
      for(int iiii=0;iiii<htable[i].len_code;iiii++){
        code_re[htable[i].len_code-iiii-1]=htable[i].code[iiii];
      }
      for(int iiii=0;iiii<htable[i].len_code;iiii++){
        htable[i].code[iiii]=code_re[iiii];
      }
      
      iii=0;
      while(htable[i].code[iii]!='\0'){
        printf("%c",htable[i].code[iii]);
        iii++;
      }
      printf(":%c\n",htable[i].ch[0]);
      
  }

  return htable;
}


void Encoder(char* file_content,Htable* table,int length){
  FILE* output_file = fopen("bbb","a");
  while(*file_content>0){
    for(int i=0;i<length;i++){
      if(table[i].ch[0]==*file_content){
        int iii=0;
        while(table[i].code[iii]!='\0'){
        printf("%c",table[i].code[iii]);
        fputc(table[i].code[iii], output_file);
        //Write_file("bbb",table[i].code[iii]);
        iii++;
      }
        file_content++;
        break;
      }
    }
  }

  fclose(output_file);
    printf("\nLength of file compresseé: %d\n",File_len("bbb"));
}

void Decoder(int length,int nb_char,Htable* table){
  char* file_content=Read_file("bbb");
  int index=0;
  char* code_in=(char*)malloc(sizeof(char)*2);
  for(int i=0;i<length;i++){
    
    code_in[index]=file_content[i];
    code_in[index+1]='\0';
    bool found=false;
    for(int ii=0;ii<nb_char;ii++){
      bool cccc=table[ii].code==code_in;
      int dddd=strcmp(code_in,table[ii].code);
      if(strcmp(code_in,table[ii].code)==0){
        printf("%c",table[ii].ch[0]);
        index=0;
        free(code_in);
        code_in=(char*)malloc(sizeof(char)*20);
        found=true;
        break;
      }
    }
    if(!found){
      index++;
      code_in=realloc(code_in,index+2);
      code_in[index+1]='\0';
    }
  }

}

int main(){
  char* file_content=Read_file("aaa");
  printf("Length of file origine: %d\n",File_len("aaa"));
  int len_text=strlen(file_content);
  Htree* Hnode_tree=cal_freq(file_content);
  int length=0;
  for(int i=0;i<50;i++){
    if(Hnode_tree[i].weight<0){
      break;
    }
    else length++;
  }

  printf("nb ch:%d\n",length);
  Htree* head=Create_tree(Hnode_tree,length,length);
  Htable* table=Create_Table(head,length);
  Encoder(Read_file("aaa"),table,length);
  Decoder(File_len("bbb"),length,table);
  getchar();
}