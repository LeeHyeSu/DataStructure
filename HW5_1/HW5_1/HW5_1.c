#include<stdio.h>
#define MAX_ELEMENT 200
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void init(HeapType *h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	while((i != 1) && (item.key > h->heap[i/2].key)) {
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while( child <= h->heap_size ) {
		// 현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다.
		if( (child < h->heap_size) && (h->heap[child].key) < h->heap[child+1].key)
			child++;
		if( temp.key >= h->heap[child].key ) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void preorder(HeapType *h, int root)
{
	if(root <= h->heap_size) {
		printf("%d ", h->heap[root]);
		preorder(h, root*2);
		preorder(h, root*2+1);
	}
}

void print_heap(HeapType *h)
{
	int i, k=1;

	for(i = 1; i <= h->heap_size; i++) {
		printf("%d ", h->heap[i]);
		if(i == (2*k)-1) {
			printf("\n");
			k *= 2;
		}
	}
	printf("\n");
}

int find(HeapType *h, int root, int key)
{
	if(root <= h->heap_size) {
		if(h->heap[root].key == key)
			return root;
		else {
			find(h, root*2, key);
			find(h, root*2+1, key);
		}
	}
}

int find2(HeapType *h, int key)
{
	int i;

	for(i = 1; i <= h->heap_size; i++) {
		if(h->heap[i].key == key)
			return i;
	}
}

void print_sorted_value(HeapType *h) 
{
	int i;
	HeapType htmp;

	init(&htmp);
	for(i = 1; i <= h->heap_size; i++) {
		insert_max_heap(&htmp, h->heap[i]);
	}
	for(i = 1; i <= h->heap_size; i++) {
		printf("%d ", delete_max_heap(&htmp));
	}
	printf("\n");
}

void main()
{
	element e1={10}, e2={5}, e3={30};
	element m1={9}, m2={19}, m3={39};
	element e4, e5, e6;
	HeapType heap;
	init(&heap);

	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, m1);
	insert_max_heap(&heap, m2);
	insert_max_heap(&heap, m3);
	print_heap(&heap);
	preorder(&heap, 1);
	printf("\n");

	printf("%d\n", find(&heap, 1, 30));
	printf("%d\n", find2(&heap, 19));
	print_sorted_value(&heap);

	e4 = delete_max_heap(&heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(&heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(&heap);
	printf("< %d > \n", e6.key);
}