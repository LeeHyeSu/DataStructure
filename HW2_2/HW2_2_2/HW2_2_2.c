#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>　 

typedef int element;
	
typedef struct StackNode { 
	element item;
	char str[10];
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

void push(LinkedStackType *s, element item, char str[])
{ 
   StackNode *temp=(StackNode *)malloc(sizeof(StackNode));
   if( temp == NULL ){
      fprintf(stderr, "메모리 할당에러\n");
      return;
   }
   else{
      temp->item = item;
	  strcpy(temp->str, str);
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

void stack_print(LinkedStackType *s)
{
	StackNode *temp;

	if( is_empty(s) ) {
		printf("<empty>\n--\n");
		return;
	}
	else {
		temp = s->top;
		printf("[%d, %s] <- top\n", temp->item, temp->str);
		temp = temp->link;
		while(temp != NULL) {
			printf("[%d, %s]\n", temp->item, temp->str);
			temp = temp->link;
		}
		printf("--\n");
	}
}

void main()
{
	LinkedStackType s;

	init(&s);
	stack_print(&s);

	push(&s,10, "ten");
	stack_print(&s);
	push(&s,20, "twenty");
	stack_print(&s);
	push(&s,30, "thirty");
	stack_print(&s);

	push(&s, 40, "forty");
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	push(&s, 50, "fifty");
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
}