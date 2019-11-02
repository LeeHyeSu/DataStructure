#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 3

typedef struct {
	int data;
	char str[10];
} element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType *s)
{
	s->top = -1;
}

int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, int item, char str[])
{ 
    if( is_full(s) ) { 
		fprintf(stderr,"���� ��ȭ ����\n");
		return; 		 
	} 
	else {
		s->stack[++(s->top)].data = item;
		strcpy(s->stack[s->top].str, str);
	}
}

int pop(StackType *s) 
{ 
   	if( is_empty(s) ) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1); 		
	}
	else 
		return s->stack[(s->top)--].data; 
} 

int peek(StackType *s) 
{ 
   	if( is_empty(s) ) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1); 		
	}
	else 
		return s->stack[s->top].data; 
}

void stack_print(StackType *s)
{
	int i;
	if(is_empty(s)) {
		printf("<empty>\n--\n");
		return;
	}
	else {
		printf("[%d, %s] <- top\n", s->stack[s->top].data, s->stack[s->top].str);
		for(i = s->top-1; i >= 0; i--)
			printf("[%d, %s]\n", s->stack[i].data, s->stack[i].str);
		printf("--\n");
	}
}

void main(void)
{
	StackType s;

	init(&s);
	stack_print(&s);
	push(&s, 10, "ten");
	stack_print(&s);
	push(&s, 20, "twenty");
	stack_print(&s);
	push(&s, 30, "thirty");
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

