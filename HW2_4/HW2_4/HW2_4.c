#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>　 
#define MAX_STRING 100

typedef char element;
	
typedef struct StackNode { 
	element item;
	struct StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s)
{
	s->top = NULL;
}

int is_empty(LinkedStackType *s)
{
	return (s->top == NULL);
}

int is_full(LinkedStackType *s)
{
	return 0;
}

void push(LinkedStackType *s, element item)
{ 
   StackNode *temp=(StackNode *)malloc(sizeof(StackNode));
   if( temp == NULL ){
      fprintf(stderr, "메모리 할당에러\n");
      return;
   }
   else{
      temp->item = item;
      temp->link = s->top;
      s->top = temp;
   }
}


element pop(LinkedStackType *s) 
{ 
   	if( is_empty(s) ) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else{
		StackNode *temp=s->top;
		int item = temp->item; 
		s->top = s->top->link;
		free(temp); 
		return item;
	}
} 

element peek(LinkedStackType *s) 
{ 
   	if( is_empty(s) ) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else{
		return s->top->item;
	}
}

int palindrome(char str[])
{
	LinkedStackType s;
	int i, index = 1;

	init(&s);

	for(i = 0; str[i] != NULL; i++)
		push(&s, str[i]);
	
	for(i = 0; str[i] != NULL; i++)
		if(str[i] != pop(&s))
			return 0;
	return 1;
}

int main(void)
{
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf("%s", word);
	
	if(palindrome(word))
		printf("palindrome 입니다\n");
	else
		printf("palindrome 이 아닙니다.\n");
}