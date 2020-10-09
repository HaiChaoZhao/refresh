#include <cstddef>
#include <malloc.h>
typedef struct LNode {
	//ElemType data;
	int data;
	struct LNode* next;
}LNode, *LinkList;

//无头结点
bool InitList(LinkList &L) {
	L = NULL;
	return true;
}

bool Empty(LinkList &L) {
	return (L == NULL);
}

bool InitHeadList(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}

bool InsertNextNode(LNode* p, int e) {
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

LNode* GetElem(LinkList& L, int i) {
	if (i < 0) { //0认为是头节点
		return NULL;
	}
	LNode* p;
	p = L;
	int j = 0;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

bool ListHeadInsert(LinkList &L, int i, int e) {
	if (i < 1) {
		return false;
	}
	LNode *node; //指针node指向当前结点
	int j = 0; //指针node指向的是第几个结点
	node = L;  //先将node作为头节点，头节点不存数据
	while (node!=NULL && j < i-1) 
	{
		node = node->next;
		j++;
	}
	return InsertNextNode(node, e);
}

LinkList reverseLinkList(LinkList& L) {
	if (L->next == NULL) { return L; }
	LNode* pre, * next, *temp;
	pre = L;
	next = L->next;
	pre->next = NULL;
	while (next != NULL) {
		temp = next->next;
		next->next = pre;
		pre = next;
		next = temp;
	}
}

void main() {
	LinkList L= (LinkList)malloc(sizeof(LNode));
	L->next = NULL;

}