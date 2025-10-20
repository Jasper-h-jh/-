# include<stdio.h>
# include<stdlib.h>
//定义ElemType数据类型:
typedef int ElemType;
//定义链表结构体变量:
typedef struct node {
	ElemType data;
	struct node* next;
}Node;

//链表的动态内存分配和初始化:
Node * initlist() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

//链表的头插法:
int initHead(Node* L, ElemType e) {
	//首先创建一个新的节点,并动态分配内存;
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = L->next;
	L->next = p;
}

//遍历链表
void listNode(Node* L) {
	Node* p = L->next;
	if (p != NULL) {
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}


int main() {
	//创建一个Node类型的名为list的头节点并初始化:
	Node* list = initlist();

	//在链表中使用头插法插入元素:
	initHead(list, 25);
	initHead(list, 14);
	initHead(list, 7);

	//遍历链表:
	listNode(list);

	return 1;
}