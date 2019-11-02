#include <stdio.h>
#include <stdlib.h>
#define TRUE 1 
#define FALSE 0 

typedef int element; 
typedef struct ListNode {
	element data;  
	struct ListNode *link;    
} ListNode;  

// phead: ����Ʈ�� ��� �������� ������, new_node : ���Ե� ���  
void insert_node_first(ListNode **phead, ListNode *new_node)  
{  
	if( *phead == NULL ){		// ���鸮��Ʈ�� ���
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
	
	if( *phead == NULL ){		// ���鸮��Ʈ�� ���   
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
		printf("����Ʈ�� ��� ����\n");      
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
		printf("����Ʈ�� ����ֽ��ϴ�.\n");      
	else if ((*phead)->data == item) { // �����ؾ��ϴ� ��尡 ù��° ����̸�
           p = *phead;          
		   *phead = (*phead)->link;           
		   free(p);      
	}      
	else {           
		p = *phead;           
		do {                 
			prevp = p;                
			p = p->link;           
		} while (p != NULL && p->data != item);  // item�� ã�������� ����, p �ڿ� prevp 
		if (p != NULL) { // item �߰�!
                prevp->link = p->link; // �����Ϸ��� ����� �յڸ� ����                
				free(p);          
		}        
		else             
			printf("������ %d�� �����ϰ� ���� �ʽ��ϴ�.\n", item);  
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
		if( p->data == x ) return p;    // Ž�� ����  
		p = p->link;  
	}  
	return p;  // Ž�� ������ ��� NULL ��ȯ
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
	// ��ȸ �����ͷ� p, q, r�� ���   
	ListNode *p, *q, *r; 
	p = head;         // p�� �������� ���� ����Ʈ
	q = NULL;         // q�� �������� ���� ���  
	while (p != NULL){
       r = q;           // r�� �������� �� ����Ʈ.    r�� q, q�� p�� ���ʷ� ���󰣴�.
       q = p;       
	   p = p->link;     
	   q->link =r;      // q�� ��ũ ������ �ٲ۴�.     
	} 
	return q;  // q�� �������� �� ����Ʈ�� ��� ������ 
} 
 
ListNode *create_node(element data) {
 
     ListNode *new_node; 
 
     new_node = (ListNode *)malloc(sizeof(ListNode));     
	 if (new_node == NULL) {     
		 printf("�޸� �ҵ� ����.\n"); exit(1);   
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
		printf("����Ʈ�� ��� ����\n");
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
		printf("�ִ� ����<100kg> �ʰ��� ������ %d�� �߰��� �� ����\n", new_item);
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