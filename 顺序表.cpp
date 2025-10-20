# include<stdio.h>
# include<stdlib.h>
# define# 定义 MAXSIZE 100
typedeftypedef int ElemType;int ElemType;
//创建结构体变量:
typedeftypedef struct {struct {
	ElemType* data;ElemType* data;
	int length;int length;
}Seqlist}Seqlist;

//动态内存分配(堆内存)及初始化顺序表:
SeqlistSeqlist* initlist() {initlist() {
	Seqlist* L = (Seqlist*)malloc(sizeof(Seqlist));Seqlist* L = (Seqlist*)malloc(sizeof(Seqlist));
	L->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	L->length = 0;length = 0;
	返回 L;return L;
}

//在顺序表尾部增添元素:
intint appendElem(Seqlist* L, ElemType e) {appendElem(Seqlist* L, ElemType e) {
	//判断顺序表中是否可以增添元素://判断顺序表中是否可以增添元素:
	if (L->length > MAXSIZE) {if (L->length > MAXSIZE) {
		printf("ADD ERROR!!!\n");printf("ADD ERROR!!!\n");
		return 0;return 0;
	}}

	//若可以增加，则进入主程序://若可以增加,则进入主程序:
	L->data[L->length] = e;data[L->length] = e;
	L->length++;length++;
	return 1;return 1;
}

//遍历顺序表中的元素:
voidvoid listElem(Seqlist* L) {listElem(Seqlist* L) {
	//判断顺序表是否为空://判断顺序表是否为空:
	if (L->length == 0) {if (L->length == 0) {
		printf("NULL\n");
	}

	if (L->length <= MAXSIZE) {
		for (int i = 0; i < L->length; i++) {
			printf("%d ", L->data[i]);
		}
	}
	printf("\n");
}

//删除顺序表中的元素:
int deletElem(Seqlist* L, int pos, ElemType* e) {
	//将顺序表中要删除位置的元素赋值给ElemType *e;
	*e = L->data[pos - 1];

	//判断顺序表中是否可删除元素:
	if (L->length<0 || pos>L->length) {
		printf("DELET ERROR!!!\n");
		return 0;
	}

	//如果可删除元素,则进入主程序:
	if (pos < L->length) {
		for (int i = pos; i < L->length; i++) {
			L->data[i-1] = L->data[i];
		}
	}
	L->length--;
	return 1;
}


//查找顺序表中的元素:
int findElem(Seqlist* L, ElemType e) {
	//判断顺序表是否为空表:
	if (L->length == 0) {
		printf("NULL\n");
		return 0;
	}

	//判断顺序表中的元素是否可查找:
	if (L->length > MAXSIZE) {
		printf("FIND ERROR!!!\n");
		return 0;
	}

	//如果可查找,则进入主程序:
	if (L->length < MAXSIZE) {
		for (int i = 0; i < L->length; i++) {
			if (L->data[i] == e) {
				return i + 1;
			}
		}
	}
	return 1;
}

//向顺序表中插入元素:
int insertElem(Seqlist* L, int pos, ElemType e) {
	//判断顺序表中是否可以插入元素:
	if (L->length > MAXSIZE||pos > L->length) {
		printf("INSERT ERROR!!!\n");
		return 0;
	}

	//如果可以插入,则进入主程序:
	if (pos <= L->length) {
		for (int i = L->length-1; i >= pos-1; i--) {
			L->data[i+1] = L->data[i];
		}
	}
	L->data[pos - 1] = e;
	L->length++;
	return 1;
}

//进入主程序:
int main() {
	//创建顺序表并初始化(调用initlist函数):
	Seqlist* list = initlist();

	//为顺序表尾部增添元素(调用appendElem函数,传入顺序表和要增添的元素值):
	//由于是动态内存分配,创建了一个list类型的指针,所以在调用函数时直接传入list,不用传入&list
	appendElem(list, 11);
	appendElem(list, 2006);
	appendElem(list, 14);
	appendElem(list, 25);

	//遍历顺序表(调用listElem函数0):
	listElem(list);

	//向顺序表中插入新元素(调用insertElem函数,传入顺序表和要插入的位置以及要插入的元素值):
	insertElem(list, 3, 7);

	//插入元素后重新遍历顺序表(调用listElem函数):
	listElem(list);

	//删除顺序表中元素(调用deleElem函数,传入list和用来接收删除位置元素的变量地址deldata):
	ElemType deldata;
	deletElem(list,1 ,&deldata);
	printf("删除的元素是:%d\n", deldata);

	//删除元素后重新遍历顺序表(调用listElem函数):
	listElem(list);

	//查询顺序表中的元素(调用findElem函数,传入顺序表和要查找的元素值):
	findElem(list, 14);
	printf("要查询的元素在顺序表中的第%d个位置\n", findElem(list, 14));


	return 0;
}







