#include <stdio.h>
#include <stdlib.h>
#include <time.h> // srand() 함수를 사용하기 위해 필요한 헤더 파일

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
        // 지원되지 않는 자료형일 경우 NULL 반환
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
        // 지원되지 않는 자료형일 경우 NULL 반환
        return NULL;
    }
}


void* get(void* data, int sizeofdata, int getIndex) {
    // sizeofdata는 데이터 자체의 크기를 나타냄 (바이트 단위)
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
        // 지원되지 않는 자료형일 경우 NULL 반환
        return NULL;
    }
}


int main() {


    ArrayList intList = { NULL, sizeof(int), -1, NULL }; // ArrayList 초기화

    intList.size = MAX_ARRAY_SIZE;

    // create 함수를 호출하여 동적으로 메모리를 할당하고 해당 메모리의 주소를 intList.data에 할당
    intList.data = create(intList.size, intList.sizeofdata);

    // intList.data가 NULL인 경우 처리
    if (intList.data == NULL) {
        // 메모리 할당 실패
        return -1;
    }

    // 자바에서의 ArrayList.set(i, v); 을 해보겠다.
    // 난수 생성 시드 설정
    srand(time(NULL));
    // 1 이상 100 이하의 난수 생성
    for (int i = 0; i < intList.size; i++) {
        intList.setIndex = i;
        int setv = rand() % 100 + 1;
        intList.setValue = &setv;
        // set 함수 호출
        void* result = set(intList.data, intList.sizeofdata, intList.setIndex, intList.setValue);
    }

    // 자바에서의 ArrayList.get(i); 을 해보겠다.
    // 데이터 가져오기
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

    // 자바에서의 ArrayList.add(value); 을 해보겠다.
    for (int i = 0; i < intList.size; i++) {
        intList.size = intList.size + 1;
        int addv = rand() % 100 + 1;
        intList.addValue = &addv;
        // set 함수 호출
        void* result = set(intList.data, intList.size, intList.sizeofdata, intList.addValue);
    }
    
    // 할당된 메모리 해제
    free(intList.data);

	return 0;
}
