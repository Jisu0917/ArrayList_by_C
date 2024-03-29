#include <stdio.h>
#include <stdlib.h>
#include <time.h> // srand() �Լ��� ����ϱ� ���� �ʿ��� ��� ����

#define MAX_ARRAY_SIZE 10000

typedef struct ArrayList {
    void* data;
	int sizeofdata;
	int setIndex;
	void* setValue;
	int getIndex;
    void* addValue;
	void* (*create)(size, sizeofdata);
    void* (*add)(data, size, sizeofdata, addValue);
	void* (*set)(data, sizeofdata, setIndex, setValue);
	void* (*get)(data, sizeofdata, getIndex);
    int size;
} ArrayList;

void* create(int size, int sizeofdata) {

	if (sizeofdata == sizeof(char)) {
		char* clist = (char*)malloc(size * sizeof(char));
		return clist;
	}
	else if (sizeofdata == sizeof(int)) {
		int* ilist = (int*)malloc(size * sizeof(int));
		return ilist;
	}
	else if (sizeofdata == sizeof(float)) {
		float* flist = (float*)malloc(size * sizeof(float));
		return flist;
	}
	else if (sizeofdata == sizeof(double)) {
		double* dlist = (double*)malloc(size * sizeof(double));
		return dlist;
	}
	return NULL;
}

void* add(void* data, int size, int sizeofdata, void* addValue) {

    if (sizeofdata == sizeof(char)) {
        char* ch = (char*)data;
        if (ch == NULL) {
            return NULL;
        }
        ch[size] = *((char*)addValue);
        return data;
    }
    else if (sizeofdata == sizeof(int)) {
        int* i = (int*)data;
        if (i == NULL) {
            return NULL;
        }
        i[size] = *((int*)addValue);
        return data;
    }
    else if (sizeofdata == sizeof(float)) {
        float* f = (float*)data;
        if (f == NULL) {
            return NULL;
        }
        f[size] = *((float*)addValue);
        return data;
    }
    else if (sizeofdata == sizeof(double)) {
        double* d = (double*)data;
        if (d == NULL) {
            return NULL;
        }
        d[size] = *((double*)addValue);
        return data;
    }
    else {
        // �������� �ʴ� �ڷ����� ��� NULL ��ȯ
        return NULL;
    }
}

void* set(void* data, int sizeofdata, int setIndex, void* setValue) {

    if (sizeofdata == sizeof(char)) {
        char* ch = (char*)data;
        if (ch == NULL) {
            return NULL;
        }
        ch[setIndex] = *((char*)setValue);
        return data;
    }
    else if (sizeofdata == sizeof(int)) {
        int* i = (int*)data;
        if (i == NULL) {
            return NULL;
        }
        i[setIndex] = *((int*)setValue);
        return data;
    }
    else if (sizeofdata == sizeof(float)) {
        float* f = (float*)data;
        if (f == NULL) {
            return NULL;
        }
        f[setIndex] = *((float*)setValue);
        return data;
    }
    else if (sizeofdata == sizeof(double)) {
        double* d = (double*)data;
        if (d == NULL) {
            return NULL;
        }
        d[setIndex] = *((double*)setValue);
        return data;
    }
    else {
        // �������� �ʴ� �ڷ����� ��� NULL ��ȯ
        return NULL;
    }
}


void* get(void* data, int sizeofdata, int getIndex) {
    // sizeofdata�� ������ ��ü�� ũ�⸦ ��Ÿ�� (����Ʈ ����)
    if (sizeofdata == sizeof(char)) {
        char* ch = (char*)data;
        if (ch == NULL || getIndex < 0) {
            return NULL;
        }
        return &ch[getIndex];
    }
    else if (sizeofdata == sizeof(int)) {
        int* i = (int*)data;
        if (i == NULL || getIndex < 0) {
            return NULL;
        }
        return &i[getIndex];
    }
    else if (sizeofdata == sizeof(float)) {
        float* f = (float*)data;
        if (f == NULL || getIndex < 0) {
            return NULL;
        }
        return &f[getIndex];
    }
    else if (sizeofdata == sizeof(double)) {
        double* d = (double*)data;
        if (d == NULL || getIndex < 0) {
            return NULL;
        }
        return &d[getIndex];
    }
    else {
        // �������� �ʴ� �ڷ����� ��� NULL ��ȯ
        return NULL;
    }
}


int main() {


    ArrayList intList = { NULL, sizeof(int), -1, NULL }; // ArrayList �ʱ�ȭ

    intList.size = MAX_ARRAY_SIZE;

    // create �Լ��� ȣ���Ͽ� �������� �޸𸮸� �Ҵ��ϰ� �ش� �޸��� �ּҸ� intList.data�� �Ҵ�
    intList.data = create(intList.size, intList.sizeofdata);

    // intList.data�� NULL�� ��� ó��
    if (intList.data == NULL) {
        // �޸� �Ҵ� ����
        return -1;
    }

    // �ڹٿ����� ArrayList.set(i, v); �� �غ��ڴ�.
    // ���� ���� �õ� ����
    srand(time(NULL));
    // 1 �̻� 100 ������ ���� ����
    for (int i = 0; i < intList.size; i++) {
        intList.setIndex = i;
        int setv = rand() % 100 + 1;
        intList.setValue = &setv;
        // set �Լ� ȣ��
        void* result = set(intList.data, intList.sizeofdata, intList.setIndex, intList.setValue);
    }

    // �ڹٿ����� ArrayList.get(i); �� �غ��ڴ�.
    // ������ ��������
    for (int i = 0; i < intList.size; i++) {
        int getIndex = i;
        int* getValue = (int*)get(intList.data, intList.sizeofdata, getIndex);
        if (getValue != NULL) {
            printf("Value at index %d: %d\n", getIndex, *getValue);
        }
        else {
            printf("Failed to get value.\n");
        }
    }

    // �ڹٿ����� ArrayList.add(value); �� �غ��ڴ�.
    for (int i = 0; i < intList.size; i++) {
        intList.size = intList.size + 1;
        int addv = rand() % 100 + 1;
        intList.addValue = &addv;
        // set �Լ� ȣ��
        void* result = set(intList.data, intList.size, intList.sizeofdata, intList.addValue);
    }
    
    // �Ҵ�� �޸� ����
    free(intList.data);

	return 0;
}
