#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR_PER_LINE 100

typedef struct element {
	char line[MAX_CHAR_PER_LINE];
} element;

typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

void display_te(ListNode *head) 
{  
	ListNode *p=head;
	int lineNb = 1;
	printf("----------text edited----------\n");
	while( p != NULL ){   
		printf("(%d) %s", lineNb, p->data.line);
		p = p->link; 
		lineNb++;
	} 
} 

void insert_node_first(ListNode **phead, ListNode *new_node)  
{  
	if( *phead == NULL ){		// 공백리스트인 경우
		new_node->link = NULL;    
		*phead = new_node;        
	}  
	else {
		new_node->link = *phead;   
		*phead = new_node;       
	} 
} 

void insert_node_last(ListNode **phead, ListNode *new_node)  
{  
	ListNode *p;  
	
	if( *phead == NULL ){		// 공백리스트인 경우   
		new_node->link = NULL;    
		*phead = new_node;   
	}  
	else {
		p = *phead;               
		while (p->link != NULL)    
			p = p->link;     
		p->link = new_node;  
	} 
} 

void insert_node_at(ListNode **phead, int pos, ListNode *new_node)
{
	ListNode *p;
	int i;

	if (pos < 0 || pos > get_length(*phead)) {
		printf("삽입 위치 오류\n");
		return;
	}

	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (pos == 0) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else { //pos >= 1
		p = *phead;
		for (i = 0; i < pos-1; i++)
			p = p->link;
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node_first(ListNode **phead)  
{     
	ListNode *p; 
   
	if (*phead == NULL)           
		printf("리스트가 비어 있음\n");      
	else {
        p = *phead;                                 
		*phead = (*phead)->link;            
		free(p);      
	} 
} 

void remove_node(ListNode **phead, element item) 
{      
	ListNode *p, *prevp;            
	
	if (*phead == NULL)           
		printf("리스트는 비어있습니다.\n");      
	else if (strcmp((*phead)->data.line, item.line) == 0) { // 삭제해야하는 노드가 첫번째 노드이면
           p = *phead;          
		   *phead = (*phead)->link;           
		   free(p);      
	}      
	else {           
		p = *phead;           
		do {                 
			prevp = p;                
			p = p->link;           
		} while (p != NULL && strcmp(p->data.line, item.line) != 0);  // item을 찾을때까지 전진, p 뒤에 prevp 
		if (p != NULL) { // item 발견!
                prevp->link = p->link; // 삭제하려는 노드의 앞뒤를 연결                
				free(p);          
		}        
		else             
			printf("%d은 리스트에 없음\n", item);  
	}
} 

ListNode *search(ListNode *head, element x)
{ 
	ListNode *p; 
	p = head; 
	while( p != NULL ){
		if( !strcmp(p->data.line, x.line) ) return p;    // 탐색 성공  
		p = p->link;  
	}  
	return p;  // 탐색 실패일 경우 NULL 반환
} 

ListNode *concat(ListNode *head1, ListNode *head2)
{ 
	ListNode *p;  
	if( head1 == NULL ) return head2; 
	else if( head2 == NULL ) return head1; 
	else {
		p = head1;              
		while( p->link != NULL )   
			p = p->link;      
		p->link = head2;        
		return head1;        
	} 
} 

ListNode *reverse(ListNode *head)
{  
	// 순회 포인터로 p, q, r을 사용   
	ListNode *p, *q, *r; 
	p = head;         // p는 역순으로 만들 리스트
	q = NULL;         // q는 역순으로 만들 노드  
	while (p != NULL){
       r = q;           // r은 역순으로 된 리스트.    r은 q, q는 p를 차례로 따라간다.
       q = p;       
	   p = p->link;     
	   q->link =r;      // q의 링크 방향을 바꾼다.     
	} 
	return q;  // q는 역순으로 된 리스트의 헤드 포인터 
} 
 
ListNode *create_node(element data) {
 
     ListNode *new_node; 
 
     new_node = (ListNode *)malloc(sizeof(ListNode));     
	 if (new_node == NULL) {     
		 printf("메모리 할딩 에러.\n"); exit(1);   
	 }                                  
	 new_node->data = data;           
	 new_node->link = NULL;  
	 
	 return(new_node);      
} 

int is_in_list(ListNode *head, element data)
{
	ListNode *p;
	p = head;
	while(p != NULL) {
		if(!strcmp(p->data.line, data.line))
			return 1;
		p = p->link;
	}
	return 0;
}
 
int get_length(ListNode *head) 
{
	ListNode *p = head;
	int length = 0;
	while(p != NULL) {
		length++;
		p = p->link;
	}
	return length;
}  

element get_entry(ListNode *head, int pos) 
{
	ListNode *p = head;
	int i;
	for(i = 0; i < pos; i++) {
		p = p->link;
	}
	return p->data;
} 

void remove_node_at(ListNode **phead, int pos)
{
	ListNode *p, *temp;
	int i;

	if (pos < 0 || pos >= get_length(*phead)) {
		printf("삭제 위치 오류\n");
		return;
	}

	if(*phead == NULL)
		printf("리스트는 비어있습니다\n");
	else if(pos == 0) {
		p = *phead;
		*phead = (*phead)->link;
		free(p);
	}
	else { //pos >= 1
		p = *phead;
		for(i = 0; i < pos - 1; i++) {
			p = p->link;
		}

		temp = p->link;
		p->link = p->link->link;
		free(temp);
	}
}

char askChoice(void) 
{  
	char choice; 
	printf("-------------------------------\n");
	printf("a: 텍스트 끝에 라인 추가\n"); 
	printf("i: 라인 번호로 라인 추가\n");
	printf("d: 라인 번호로 라인 삭제\n");
	printf("v: 라인 번호로 해당 라인 출력\n"); 
	printf("p: 전체 텍스트 출력\n");
	printf("q: 끝\n"); 
 
	printf("메뉴 선택:"); 
	scanf("%c", &choice);
	return choice;
} 

int main(void)
{
	ListNode *list = NULL;
	char choice;  
	int lineNb; 
	element newElement;

    while ((choice = askChoice()) != 'q') {        
		switch (choice) {        		
			case 'a':
				printf("텍스트 끝에 삽입할 라인: ");
				fflush(stdin);  
				fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);

				insert_node_last(&list, create_node(newElement));
				display_te(list);
				break;         
			case 'i': 
				printf("삽입할 라인 번호: ");
				scanf("%d", &lineNb);    
				printf("삽입할 라인: ");
				fflush(stdin);
				fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);

				insert_node_at(&list, lineNb-1, create_node(newElement));
				display_te(list);
				break;               
			case 'd':
				printf("삭제할 라인 번호: ");
				scanf("%d", &lineNb);  

				remove_node_at(&list, lineNb-1);
				display_te(list);
				break;
			case 'v':
				printf("출력할 라인 번호: "); 
				scanf("%d", &lineNb);

				printf("(%d) %s", lineNb, get_entry(list, lineNb-1).line);
				break;  
			case 'p':   
				display_te(list);     
		}        
		while (getchar() != '\n'); // fflush 대신에 사용한다    
	}
} 