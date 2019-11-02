#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element list[MAX_LIST_SIZE];
	int length;
}ArrayListType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType *L)
{
	L->length = 0;
}
int is_empty(ArrayListType *L)
{
	return L->length == 0;
}

int is_full(ArrayListType *L)
{
	return L->length == MAX_LIST_SIZE;
}

void display(ArrayListType *L)
{
	int i;
	for(i = 0; i < L->length; i++)
		printf("%d-->", L->list[i]);
	printf("리스트끝\n");
}

void add(ArrayListType *L, int position, element item)
{
	if(!is_full(L) && (position >= 0) && (position <= L->length)) {
		int i;
		for(i = L->length; i > position; i--)
			L->list[i] = L->list[i-1];
		L->list[position] = item;
		L->length++;
	}
}

element deleteItem(ArrayListType *L, int position) //delete를 함수이름으로 사용할 수 없어서 함수이름 변경함
{
	int i;
	element item;

	if(position < 0 || position >= L->length)
		error("위치 오류");
	item = L->list[position];
	for(i = position; i < L->length; i++)
		L->list[i] = L->list[i+1];
	L->length--;
	return item;
}

void clear(ArrayListType *L)
{
	L->length = 0;
}

void add_first(ArrayListType *L, element item)
{
	int i;
	for(i = L->length; i > 0; i--)
		L->list[i] = L->list[i-1];
	L->list[0] = item;
	L->length++;
}

void add_last(ArrayListType *L, element item)
{
	L->list[L->length] = item;
	L->length++;
}

int get_length(ArrayListType *L)
{
	return L->length;
}

element get_entry(ArrayListType *L, int pos)
{
	return L->list[pos];
}

void replace(ArrayListType *L, int pos, element item)
{
	L->list[pos] = item;
}

int is_in_list(ArrayListType *L, element item)
{
	int i;
	for(i = 0; i < L->length; i++)
		if(L->list[i] == item)
			return 1;
	return 0;
}

void delete_by_key(ArrayListType *L, element key)
{
	int i, keyIndex = 0;
	for(i = 0; i < L->length; i++) {
		if(L->list[i] == key) {
			keyIndex = i;
			break;
		}
	}

	if(keyIndex == 0)
		printf("삭제하려는 key값 %d은 리스트에 없습니다\n", key);
	else
		deleteItem(L, keyIndex);
}

int main(void)
{
	ArrayListType list1;
	ArrayListType *plist;

	init(&list1);
	add(&list1, 0, 10);
	add(&list1, 0, 20);
	add(&list1, 0, 30);
	display(&list1);

	plist = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(plist);
	add(plist, 0, 10);
	add(plist, 0, 20);
	add(plist, 0, 30);
	display(plist);

     printf("-이 이후는 HW1_1에서 추가한 함수들 테스트-\n");
     
     clear(&list1); display(&list1);

     add_first(plist, 35); display(plist);
     add_last(plist, 5); display(plist);

     printf("길이는 %d\n", get_length(plist));
     printf("3번째 데이타는 %d\n", get_entry(plist, 2));
     replace(plist, 2, 22); display(plist);
     printf("20은 리스트에 %s\n", is_in_list(plist, 20)? "있습니다": "없습니다");
     printf("22는 리스트에 %s\n", is_in_list(plist, 22)? "있습니다": "없습니다");
     
     delete_by_key(plist, 20); display(plist);
     delete_by_key(plist, 22); display(plist);
}