#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

struct stack_entry {
  char *data;
  struct stack_entry *next;
};


struct stack_t {
  struct stack_entry *head;
  size_t stackSize; 
};


struct stack_t *newStack(void) {
  struct stack_t *stack = malloc(sizeof *stack);
  if (stack)
  {
    stack->head = NULL;
    stack->stackSize = 0;
  }
  return stack;
}

char *copyString(char *str)
{
  char *tmp = malloc(strlen(str) + 1);
  if (tmp)
    strcpy(tmp, str);
  return tmp;
}

void push(struct stack_t *theStack, char* value)
{
  struct stack_entry *entry = malloc(sizeof *entry); 
  if (entry)
  {
    entry->data = copyString(value);
    entry->next = theStack->head;
    theStack->head = entry;
    theStack->stackSize++;
  }
  else
  {
    // handle error here
  }
}


char *top(struct stack_t *theStack)
{
  if (theStack && theStack->head)
    return theStack->head->data;
  else
    return NULL;
}

void pop(struct stack_t *theStack)
{
  if (theStack->head != NULL)
  {
    struct stack_entry *tmp = theStack->head;
    theStack->head = theStack->head->next;
    free(tmp->data);
    free(tmp);
    theStack->stackSize--;
  }
}


void clear (struct stack_t *theStack)
{
  while (theStack->head != NULL)
    pop(theStack);
}

void destroyStack(struct stack_t **theStack)
{
  clear(*theStack);
  free(*theStack);
  *theStack = NULL;
}

int change(char* word, int** matrix, char** words, int lenght, int len, int pos){ 
	//se verifica daca valoarea incep cu ! si daca da se scoate din string primul caracter si se cauta valoarea lui si se neaga
	//verificam daca valoarea se afla in vectorul de cuvinte
	//se cauta valoarea cuvantului in matricea binara la pozitia pos data ca parametru ce reprezinta fisierul in care se cauta (in main)
	//se returneaza 0 sau 1
}
int apply_op(int val1, int val2, char* op, int** matrix, int lenght, int len, int pos, char** words){
	//se scrie un switch pt operatii 
	//se calculeaza operatia binara AND sau OR intre cele 2 valori binare ale cuvintelor si se returneaza valoarea 0 sau 1
	
}
int evaluate(char* exp, int lenght, int len, int** matrix, int pos, char** words){
	//stive
	struct stack_t* ops = newStack();
	struct stack_t* values = newStack(); // nu e bine, folosim alt tip de stiva
	char* ptr; char delim[]={' '};

	ptr = strtok(exp, delim);
	while(ptr != NULL){
		if(!strcmp(ptr, "(")){
			push(ops, ptr);
		}
		else if(!strcmp(ptr, "||")){
			push(ops, ptr);
		}
		else if(!strcmp(ptr, "&&")){
			push(ops, ptr);
		}
		else if(!strcmp(ptr, ")")){
			while(top(ops) != NULL && strcmp(top(ops), "(") != 0){
				int val2 = top(values);
				pop(values);
				
				int val1 = top(values);
				pop(values);

				char* op = top(ops);
				pop(ops);
				//o sa folosim pt stiva values stiva de ints
				push(values, apply_op(val1, val2, op, matrix, lenght, len, pos, words));
			}
			if(top(ops) != NULL){
				pop(ops);
			}
		}
		else{
			char *word = strdup(ptr);
			int val = change(word, matrix, words, lenght, len, pos);
			push(values, val);	
		}

		while(top(ops) != NULL){
			int val2 = top(values);
			pop(values);
			int val1 = top(values);
			pop(values);
			char* op = top(ops);
			pop(ops);
			push(values, apply_op(val1, val2, op, matrix, lenght, len, pos));

	}
		return top(values);
}



int cmp(const void *a, const void *b){
	return strcmp( *(const char **)a, *(const char**)b );
}
int check_in_file(FILE *fp, char *word){
	char buf[100];
	while(!feof(fp)){
		fscanf(fp, "%s", buf);
		if(strcmp(word, buf) == 0){
			return 1;
		}
	}
	return 0;
}
int main(){
	struct dirent *de; int i= 0;
	char *files[100], *words[10000];
	DIR *dr = opendir(".");
	if(dr == NULL){
		printf("nop");
		return 0;
	}
	while((de = readdir(dr)) != NULL){
		if(strcmp(de->d_name, ".") && strcmp(de->d_name, ".git") && strcmp(de->d_name, "..") && strcmp(de->d_name, "invindx.c") && strcmp(de->d_name, "invindx")){
			files[i] = de->d_name;
			i++;	
		//	printf("%s\n", de->d_name);
		}
	}
//	int bmatrix[1000][1000] = {0};	
	int lenght;
	char *ptr; int j=0;
	char delim[] = " .";
	for(lenght=0;files[lenght]; lenght++);
	FILE *fp; char buf[100];
	qsort(files, lenght, sizeof(files[0]), cmp);	
	for(int i =0; i<lenght; i++){
		fp = fopen(files[i], "r");
		if(fp == NULL) continue;	
		while(!feof(fp)){
			fscanf(fp, "%s", buf);
		//	printf("%s ", buf);
			words[j] = strdup(buf);
			j++;
			
			}
		
		fclose(fp);
	
		}
		
	int len;
	for(len =0; words[len]; len++);

	qsort(words, len, sizeof(words[0]), cmp);
	for(int i=0; i<len; i++){
		for(int j=i+1; j<len; j++){
			if(strcmp(words[i], words[j]) == 0){
				for(int k=j; k<len; k++){
					words[k] = words[k+1];
				}
				len--;
				j--;
			}
		}

	}

	for(int i=0; i<len; i++){
//		printf("%s\n", words[i]);
	}
	printf("\n");
	for(int i=0; i<lenght; i++){
//		printf("%s\n", files[i]);
	}
	int bmatrix[lenght][len];
	
	for(int i=0; i<lenght; i++){
		for(int j=0; j<len; j++){
			fp = fopen(files[i], "r");
			if(check_in_file(fp, words[j]) == 1){
				bmatrix[i][j] = 1;
			}else{
				bmatrix[i][j] =0;
			}
		} 
	}
	for(int i=0; i<lenght; i++){
		for(int j=0; j<len; j++){
				printf("%d ",bmatrix[i][j]);
			}
		printf("\n");
		}
	char line[500]; 
	fgets(line, 500, stdin);
	for(int i=0; i<lenght;i++){
		int results[i] = evaluate(line,lenght,len, bmatrix, i, words);
	}
	int results[100];
	for(int i=0; i<lenght; i++){
		if(results[i] == 1){
			printf("%s\n", files[i]);
		}
	}

	closedir(dr);
	return 0;
}
