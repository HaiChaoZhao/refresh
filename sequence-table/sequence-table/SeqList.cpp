#define MaxSize 50

typedef struct {
	//elemType data[MaxSize];
	int data[MaxSize];
	int length;
}SeqList;

/*
@param index Î»Ğò
*/
bool ListInsert(SeqList &L, int index, int e) {
	if (index < 1 || index > L.length + 1) {
		return false;
	}
	if (L.length > MaxSize) {
		return false;
	}
	for (int i = L.length; i >= index; i--) {
		L.data[i] = L.data[i - 1];
	}
	L.data[index] = e;
	L.length++;
	return true;
}

bool ListDelet(SeqList& L, int index, int &e) {
	if (index < 1 || index >= L.length) {
		return false;
	}
	e = L.data[index - 1]; //É¾³ıµÄÔªËØ[ ][ ][ ][ ][ ]
						   //           0  1  2  3  4
	                       //           1  2  3  4  5
	for (int start = index; start <= L.length; start++) {
		L.data[start - 1] = L.data[start];
	}
	L.length--;
	return true;
}

int GetElem(SeqList L, int index) {
	if (index < 1 || index > L.length) {
		return -1;
	}
	return L.data[index - 1];
}

int LocateElem(SeqList L, int e) {
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		} 
	}
	return 0;
}