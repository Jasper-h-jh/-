# include<stdio.h>
# include<stdlib.h>
# define MAXSIZE 100
typedef int ElemType;
//�����ṹ�����:
typedef struct {
	ElemType* data;
	int length;
}Seqlist;

//��̬�ڴ����(���ڴ�)����ʼ��˳���:
Seqlist* initlist() {
	Seqlist* L = (Seqlist*)malloc(sizeof(Seqlist));
	L->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	L->length = 0;
	return L;
}

//��˳���β������Ԫ��:
int appendElem(Seqlist* L, ElemType e) {
	//�ж�˳������Ƿ��������Ԫ��:
	if (L->length > MAXSIZE) {
		printf("ADD ERROR!!!\n");
		return 0;
	}

	//����������,�����������:
	L->data[L->length] = e;
	L->length++;
	return 1;
}

//����˳����е�Ԫ��:
void listElem(Seqlist* L) {
	//�ж�˳����Ƿ�Ϊ��:
	if (L->length == 0) {
		printf("NULL\n");
	}

	if (L->length <= MAXSIZE) {
		for (int i = 0; i < L->length; i++) {
			printf("%d ", L->data[i]);
		}
	}
	printf("\n");
}

//ɾ��˳����е�Ԫ��:
int deletElem(Seqlist* L, int pos, ElemType* e) {
	//��˳�����Ҫɾ��λ�õ�Ԫ�ظ�ֵ��ElemType *e;
	*e = L->data[pos - 1];

	//�ж�˳������Ƿ��ɾ��Ԫ��:
	if (L->length<0 || pos>L->length) {
		printf("DELET ERROR!!!\n");
		return 0;
	}

	//�����ɾ��Ԫ��,�����������:
	if (pos < L->length) {
		for (int i = pos; i < L->length; i++) {
			L->data[i-1] = L->data[i];
		}
	}
	L->length--;
	return 1;
}


//����˳����е�Ԫ��:
int findElem(Seqlist* L, ElemType e) {
	//�ж�˳����Ƿ�Ϊ�ձ�:
	if (L->length == 0) {
		printf("NULL\n");
		return 0;
	}

	//�ж�˳����е�Ԫ���Ƿ�ɲ���:
	if (L->length > MAXSIZE) {
		printf("FIND ERROR!!!\n");
		return 0;
	}

	//����ɲ���,�����������:
	if (L->length < MAXSIZE) {
		for (int i = 0; i < L->length; i++) {
			if (L->data[i] == e) {
				return i + 1;
			}
		}
	}
	return 1;
}

//��˳����в���Ԫ��:
int insertElem(Seqlist* L, int pos, ElemType e) {
	//�ж�˳������Ƿ���Բ���Ԫ��:
	if (L->length > MAXSIZE||pos > L->length) {
		printf("INSERT ERROR!!!\n");
		return 0;
	}

	//������Բ���,�����������:
	if (pos <= L->length) {
		for (int i = L->length-1; i >= pos-1; i--) {
			L->data[i+1] = L->data[i];
		}
	}
	L->data[pos - 1] = e;
	L->length++;
	return 1;
}

//����������:
int main() {
	//����˳�����ʼ��(����initlist����):
	Seqlist* list = initlist();

	//Ϊ˳���β������Ԫ��(����appendElem����,����˳����Ҫ�����Ԫ��ֵ):
	//�����Ƕ�̬�ڴ����,������һ��list���͵�ָ��,�����ڵ��ú���ʱֱ�Ӵ���list,���ô���&list
	appendElem(list, 11);
	appendElem(list, 2006);
	appendElem(list, 14);
	appendElem(list, 25);

	//����˳���(����listElem����0):
	listElem(list);

	//��˳����в�����Ԫ��(����insertElem����,����˳����Ҫ�����λ���Լ�Ҫ�����Ԫ��ֵ):
	insertElem(list, 3, 7);

	//����Ԫ�غ����±���˳���(����listElem����):
	listElem(list);

	//ɾ��˳�����Ԫ��(����deleElem����,����list����������ɾ��λ��Ԫ�صı�����ַdeldata):
	ElemType deldata;
	deletElem(list,1 ,&deldata);
	printf("ɾ����Ԫ����:%d\n", deldata);

	//ɾ��Ԫ�غ����±���˳���(����listElem����):
	listElem(list);

	//��ѯ˳����е�Ԫ��(����findElem����,����˳����Ҫ���ҵ�Ԫ��ֵ):
	findElem(list, 14);
	printf("Ҫ��ѯ��Ԫ����˳����еĵ�%d��λ��\n", findElem(list, 14));


	return 0;
}






