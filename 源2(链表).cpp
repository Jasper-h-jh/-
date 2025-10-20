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
Node * initList() {
	Node* head = (Node*)malloc(sizeof(Node));
	//判断链表head是否为空:
	if (head == NULL) {
		//链表head为NULL,初始化失败,返回NULL:
		return NULL;
	}
	head->data = 0;
	head->next = NULL;
	return head;
}

//链表的头插法:
int insertHead(Node* L, ElemType e) {
	//判断L是否为空:
	if (L == NULL) {
		//链表L为空,插入失败;
		return NULL;
	}
	//创建一个新的节点,并动态分配内存;
	Node* p = (Node*)malloc(sizeof(Node));
	//判断链表p是否为空:
	if (p == NULL) {
		printf("INSERT ERROR!!!\n");
		return 0;
	}
	p->data = e;
	p->next = L->next;
	L->next = p;
	return 1;
}

//遍历链表
void listNode(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("\n");
}

/*链表的尾插法:*/
//step1:先创建get_tail函数来获取链表尾部:
Node *get_tail(Node* L) {
	//创建一个空节点p:
	Node* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}

//step2:尾插法:
Node* insertTail(Node* tail, ElemType e) {
	
	//创建一个空节点p并动态分配内存:
	Node* p = (Node*)malloc(sizeof(Node));
	
	//判断p节点是否为空:
	if (p == NULL) {
		printf("INSERT ERROR!!!\n");
		return 0;
	}
	
	//将要插入的元素e赋给p->data;
	p->data = e;
	//将p赋给tail节点的next;
	tail->next = p;
	//将p节点的后记设置为NULL;
	p->next = NULL;
	return p;
}

//在链表的指定位置插入数据:
int insertNode(Node* L, int pos, ElemType e) {
	//首先获取要插入位置的前驱节点:
	//创建一个空间点p用来存储前驱节点:
	Node* p = L;
	int i = 0;
	//从首节点开始一次向后找,直到找到要插入位置的前驱节点;
	while (i < pos-1) {
		p = p->next;
		i++;
		if (p == NULL) {
			return 0;
		}
	}

	//创建要插入的新节点并动态分配内存;
	Node* q = (Node*)malloc(sizeof(Node));
	
	//将要插入的元素赋给q->data;
	q->data = e;
	//将要插入位置的前驱节点的next赋给要插入节点的next;
	q->next = p->next;
	//将要插入的节点赋给前驱节点;
	p->next = q;
	return 1;
}

//删除链表指定位置的元素:
int deletNode(Node* L, int pos) {
	//首先找到要删除节点的前驱节点:
	//创建节点p来存放L;
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		//每次循环i自加一:
		i++;
		if (p == NULL) {
			return 0;
		}
	}
	//判断是否可删除:
	if (p->next == NULL) {
		printf("DELET ERROR!!!\n");
		return 0;
	}

	//创建一个节点q来存放要删除的节点(p是要删除节点的前驱,所以p->next指向的是要删除的节点,将p->next赋给q,就相当于此时q是要删除的节点):
	Node* q = p->next;
	//将要删除节点q的next赋给其前驱的next,此时要删除节点的前驱指向要删除节点的后继;
	p->next = q->next;
	//释放删除节点的内存空间;
	free(q);
	return 1;
}

//获取链表长度:
int listLength(Node* L) {
	//创建一个p来存放L;
	Node* p = L;
	int len = 0;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

//释放链表:
void freeList(Node* L) {
	//创建一个p节点来存储头节点L的后继:
	Node* p = L->next;
	//创建一个节点q来记录p的后继节点:
	Node* q;
	//从头节点的后继开始依次释放链表:
	while (p != NULL) {
		//将头节点后继的next赋给q,此时q指向头节点后继的后继;
		q = p->next;
		//释放头节点的后继;
		free(p);
		//释放完成后再将q赋给p;循环释放;
		p = q;
	}
	L->next = NULL;
}

int main() {
	//创建一个Node类型的名为list的头节点并初始化:
	Node* list = initList();

	//在链表中使用头插法插入元素:
	insertHead(list, 25);
	insertHead(list, 14);
	insertHead(list, 7);
	insertHead(list, 001);

	//使用头插法插入元素之后遍历链表:
	listNode(list);
	
	//使用链表的尾插法插入元素:
	//先创建tail变量获取尾节点:
	Node* tail = get_tail(list);

	//用tail来接受返回的尾节点,这样可以省去再次用尾插法时重新调用get_tail函数来获取尾节点的步骤:
	tail = insertTail(tail, 2006);
	tail = insertTail(tail, 11);

	//使用尾插法插入元素后重新遍历链表:
	listNode(list);

	//在链表的特定位置插入元素:
	insertNode(list, 4, 520);

	//在指定位置插入元素后重新遍历链表:
	listNode(list);

	//删除节点:
	deletNode(list, 1);
	deletNode(list, 6);

	//删除节点后重新遍历链表:
	listNode(list);
	
	//调用listLength函数获取当前链表长度:
	printf("当前链表的长度是%d\n", listLength(list));

	//释放链表:
	freeList(list);

	//释放链表后查询链表当前长度:
	printf("当前链表的长度是%d\n", listLength(list));

	return 0;
}