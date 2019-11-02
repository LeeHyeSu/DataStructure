#include <stdio.h>
#include <stdlib.h>
#define TRUE 1 
#define FALSE 0 

typedef int element; 
typedef struct ListNode {
	element data;  
	struct ListNode *link;    
} ListNode;  

// phead: 리스트의 헤드 포인터의 포인터, new_node : 삽입될 노드  
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
	else if ((*phead)->data == item) { // 삭제해야하는 노드가 첫번째 노드이면
           p = *phead;          
		   *phead = (*phead)->link;           
		   free(p);      
	}      
	else {           
		p = *phead;           
		do {                 
			prevp = p;                
			p = p->link;           
		} while (p != NULL && p->data != item);  // item을 찾을때까지 전진, p 뒤에 prevp 
		if (p != NULL) { // item 발견!
                prevp->link = p->link; // 삭제하려는 노드의 앞뒤를 연결                
				free(p);          
		}        
		else             
			printf("아이템 %d는 보유하고 있지 않습니다.\n", item);  
	}
} 

void display(ListNode *head) 
{  
	ListNode *p=head;  
	printf("<");
	while( p != NULL ){   
		printf(" %d ", p->data); 
		p = p->link;     
	} 
	printf(">\n"); 
} 

ListNode *search(ListNode *head, int x)
{ 
	ListNode *p; 
	p = head; 
	while( p != NULL ){
		if( p->data == x ) return p;    // 탐색 성공  
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
		if(p->data = data)
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

int get_total(ListNode *head)
{
	ListNode *p = head;
	int total = 0;
	while(p != NULL) {
		total = total + p->data;
		p = p->link;
	}
	return total;
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

void remove_node_last(ListNode **phead)
{
	ListNode *p, *prevp = NULL;

	if(*phead == NULL)
		printf("리스트가 비어 있음\n");
	else if((*phead)->link = NULL) {
		p = *phead;
		*phead = NULL;
		free(p);
	}
	else {
		p = *phead;
		while(p->link != NULL) {
			prevp = p;
			p = p->link;
		}
		prevp->link = NULL;
		free(p);
	}
}

void add_item(ListNode **phead, element new_item)
{
	ListNode *newNode;
	ListNode *p = *phead;

	if( get_total(*phead) + new_item > 100 )
		printf("최대 무게<100kg> 초과로 아이템 %d를 추가할 수 없음\n", new_item);
	else if( *phead == NULL ) {
		newNode = create_node(new_item);
		*phead = newNode;
	}
	else {
		newNode = create_node(new_item);
		newNode->link = *phead;
		*phead = newNode;
	}
}

int main(void)
{
	ListNode *list = NULL;
	char choice;
	element item;

	while(1) {
		printf("enter a<dd>, d<elete> or q(uit):");
		scanf("%c", &choice);
		if( choice == 'a' ) {
			printf("enter the weight of the item:");
			scanf("%d", &item);
			add_item(&list, item);
			display(list);
		}
		else if( choice == 'd' ) {
			printf("enter the weight of the item:");
			scanf("%d", &item);
			remove_node(&list, item);
			display(list);
		}
		else if( choice == 'q' )
			break;
		fflush(stdin);
	}
}