# include<stdio.h>
# include<stdlib.h>
//����ElemType��������:
typedef int ElemType;
//��������ṹ�����:
typedef struct node {
	ElemType data;
	struct node* next;
}Node;

//����Ķ�̬�ڴ����ͳ�ʼ��:
Node * initList() {
	Node* head = (Node*)malloc(sizeof(Node));
	//�ж�����head�Ƿ�Ϊ��:
	if (head == NULL) {
		//����headΪNULL,��ʼ��ʧ��,����NULL:
		return NULL;
	}
	head->data = 0;
	head->next = NULL;
	return head;
}

//�����ͷ�巨:
int insertHead(Node* L, ElemType e) {
	//�ж�L�Ƿ�Ϊ��:
	if (L == NULL) {
		//����LΪ��,����ʧ��;
		return NULL;
	}
	//����һ���µĽڵ�,����̬�����ڴ�;
	Node* p = (Node*)malloc(sizeof(Node));
	//�ж�����p�Ƿ�Ϊ��:
	if (p == NULL) {
		printf("INSERT ERROR!!!\n");
		return 0;
	}
	p->data = e;
	p->next = L->next;
	L->next = p;
	return 1;
}

//��������
void listNode(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("\n");
}

/*�����β�巨:*/
//step1:�ȴ���get_tail��������ȡ����β��:
Node *get_tail(Node* L) {
	//����һ���սڵ�p:
	Node* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}

//step2:β�巨:
Node* insertTail(Node* tail, ElemType e) {
	
	//����һ���սڵ�p����̬�����ڴ�:
	Node* p = (Node*)malloc(sizeof(Node));
	
	//�ж�p�ڵ��Ƿ�Ϊ��:
	if (p == NULL) {
		printf("INSERT ERROR!!!\n");
		return 0;
	}
	
	//��Ҫ�����Ԫ��e����p->data;
	p->data = e;
	//��p����tail�ڵ��next;
	tail->next = p;
	//��p�ڵ�ĺ������ΪNULL;
	p->next = NULL;
	return p;
}

//�������ָ��λ�ò�������:
int insertNode(Node* L, int pos, ElemType e) {
	//���Ȼ�ȡҪ����λ�õ�ǰ���ڵ�:
	//����һ���ռ��p�����洢ǰ���ڵ�:
	Node* p = L;
	int i = 0;
	//���׽ڵ㿪ʼһ�������,ֱ���ҵ�Ҫ����λ�õ�ǰ���ڵ�;
	while (i < pos-1) {
		p = p->next;
		i++;
		if (p == NULL) {
			return 0;
		}
	}

	//����Ҫ������½ڵ㲢��̬�����ڴ�;
	Node* q = (Node*)malloc(sizeof(Node));
	
	//��Ҫ�����Ԫ�ظ���q->data;
	q->data = e;
	//��Ҫ����λ�õ�ǰ���ڵ��next����Ҫ����ڵ��next;
	q->next = p->next;
	//��Ҫ����Ľڵ㸳��ǰ���ڵ�;
	p->next = q;
	return 1;
}

//ɾ������ָ��λ�õ�Ԫ��:
int deletNode(Node* L, int pos) {
	//�����ҵ�Ҫɾ���ڵ��ǰ���ڵ�:
	//�����ڵ�p�����L;
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		//ÿ��ѭ��i�Լ�һ:
		i++;
		if (p == NULL) {
			return 0;
		}
	}
	//�ж��Ƿ��ɾ��:
	if (p->next == NULL) {
		printf("DELET ERROR!!!\n");
		return 0;
	}

	//����һ���ڵ�q�����Ҫɾ���Ľڵ�(p��Ҫɾ���ڵ��ǰ��,����p->nextָ�����Ҫɾ���Ľڵ�,��p->next����q,���൱�ڴ�ʱq��Ҫɾ���Ľڵ�):
	Node* q = p->next;
	//��Ҫɾ���ڵ�q��next������ǰ����next,��ʱҪɾ���ڵ��ǰ��ָ��Ҫɾ���ڵ�ĺ��;
	p->next = q->next;
	//�ͷ�ɾ���ڵ���ڴ�ռ�;
	free(q);
	return 1;
}

//��ȡ������:
int listLength(Node* L) {
	//����һ��p�����L;
	Node* p = L;
	int len = 0;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

//�ͷ�����:
void freeList(Node* L) {
	//����һ��p�ڵ����洢ͷ�ڵ�L�ĺ��:
	Node* p = L->next;
	//����һ���ڵ�q����¼p�ĺ�̽ڵ�:
	Node* q;
	//��ͷ�ڵ�ĺ�̿�ʼ�����ͷ�����:
	while (p != NULL) {
		//��ͷ�ڵ��̵�next����q,��ʱqָ��ͷ�ڵ��̵ĺ��;
		q = p->next;
		//�ͷ�ͷ�ڵ�ĺ��;
		free(p);
		//�ͷ���ɺ��ٽ�q����p;ѭ���ͷ�;
		p = q;
	}
	L->next = NULL;
}

int main() {
	//����һ��Node���͵���Ϊlist��ͷ�ڵ㲢��ʼ��:
	Node* list = initList();

	//��������ʹ��ͷ�巨����Ԫ��:
	insertHead(list, 25);
	insertHead(list, 14);
	insertHead(list, 7);
	insertHead(list, 001);

	//ʹ��ͷ�巨����Ԫ��֮���������:
	listNode(list);
	
	//ʹ�������β�巨����Ԫ��:
	//�ȴ���tail������ȡβ�ڵ�:
	Node* tail = get_tail(list);

	//��tail�����ܷ��ص�β�ڵ�,��������ʡȥ�ٴ���β�巨ʱ���µ���get_tail��������ȡβ�ڵ�Ĳ���:
	tail = insertTail(tail, 2006);
	tail = insertTail(tail, 11);

	//ʹ��β�巨����Ԫ�غ����±�������:
	listNode(list);

	//��������ض�λ�ò���Ԫ��:
	insertNode(list, 4, 520);

	//��ָ��λ�ò���Ԫ�غ����±�������:
	listNode(list);

	//ɾ���ڵ�:
	deletNode(list, 1);
	deletNode(list, 6);

	//ɾ���ڵ�����±�������:
	listNode(list);
	
	//����listLength������ȡ��ǰ������:
	printf("��ǰ����ĳ�����%d\n", listLength(list));

	//�ͷ�����:
	freeList(list);

	//�ͷ�������ѯ����ǰ����:
	printf("��ǰ����ĳ�����%d\n", listLength(list));

	return 0;
}