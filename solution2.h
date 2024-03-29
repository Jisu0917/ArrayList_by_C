typedef struct {
	char datatype[7];  //"bool", "char", "int", "float", "double"
	void* data;
} T;

typedef struct {
	T* t;  //초기 기본값 = 10
	int size;
	int capacity;  //초기 기본값 = 10
} ArrayList;

typedef struct {
	void (*init)(arrlist);
	void (*add)(arrlist, val);
	T(*get)(arrlist, index);
	void (*set)(arrlist, index, val);
	int (*indexOf)(arrlist, val);
	int (*lastindexOf)(arrlist, val);
	void (*removeIndex)(arrlist, index);
	void (*removeValue)(arrlist, val);
	bool (*contains)(arrlist, val);
	void (*clear)(arrlist);
	bool (*isEmpty)(arrlist);
	//int (*size)(arrlist);
} function;



/* 함수 구현 */

void init(ArrayList* arrlist) {
	arrlist->t = (T*)malloc(arrlist->capacity * sizeof(T));
	arrlist->size = 0;
}

// 순서대로 리스트를 추가, 배열 사이즈 초과 시 초기 설정된 사이즈만큼 자동으로 사이즈가 증가함, 인덱스를 추가로 지정해주면 해당 인덱스에 값을 삽입
void add(ArrayList* arrlist, T val) {
	if (arrlist->size >= arrlist->capacity) {
		// 용량을 두 배로 늘린다.
		arrlist->capacity *= 2;
		arrlist->t = (T*)realloc(arrlist->t, arrlist->capacity * sizeof(T));
		if (arrlist->t == NULL) {
			printf("Memory reallocation failed\n");
			exit(1);
		}
	}

	// 데이터를 복사하여 저장한다.
	arrlist->t[arrlist->size].data = malloc(sizeof(T)); // 새로운 메모리 공간 할당
	if (arrlist->t[arrlist->size].data == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}

	memcpy(arrlist->t[arrlist->size].data, val.data, sizeof(T)); // 데이터 복사
	strcpy_s(arrlist->t[arrlist->size].datatype, sizeof(arrlist->t[arrlist->size].datatype), val.datatype);

	arrlist->size++;
}


// 해당 인덱스의 값 반환
T get(ArrayList* arrlist, int index) {
	T tNull = { "", NULL };  // 유효하지 않은 값으로 초기화합니다.

	// 인덱스가 유효한지 확인합니다.
	if (index < 0 || index >= arrlist->size) {
		printf("인덱스가 유효하지 않습니다.\n");
		return tNull;  // 유효하지 않은 경우에는 유효하지 않은 값을 반환합니다.
	}

	return arrlist->t[index];
}

// 인덱스로 값 변경
void set(ArrayList* arrlist, int index, T val) {
	// 인덱스가 기존 배열의 범위를 벗어날 때
	if (index > arrlist->size) {
		arrlist->size++;

		if (arrlist->size >= arrlist->capacity) {
			// 용량을 두 배로 늘린다.
			arrlist->capacity *= 2;
			arrlist->t = (T*)realloc(arrlist->t, arrlist->capacity * sizeof(T));
			if (arrlist->t == NULL) {
				printf("Memory reallocation failed\n");
				exit(1);
			}
		}
	}

	// 데이터를 복사하여 저장한다.
	arrlist->t[index].data = malloc(sizeof(T)); // 새로운 메모리 공간 할당
	if (arrlist->t[index].data == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}

	memcpy(arrlist->t[index].data, val.data, sizeof(T)); // 데이터 복사
	strcpy_s(arrlist->t[index].datatype, sizeof(arrlist->t[index].datatype), val.datatype);

}

// 값을 제공하면 해당 값의 첫번째 인덱스를 반환
int indexOf(ArrayList* arrlist, T val) {
	// 첫 번째로 나오는 value 값을 반환한다.
	for (int i = 0; i < arrlist->size; i++) {
		if (arrlist->t[i].data != NULL) {
			// 포인터가 아닌 값을 비교해야 함
			if (strcmp(arrlist->t->datatype, "bool") == 0) {
				if (*(bool*)arrlist->t[i].data == *(bool*)val.data) {
					return i;
				}
			} else if (strcmp(arrlist->t->datatype, "char") == 0) {
				if (*(char*)arrlist->t[i].data == *(char*)val.data) {
					return i;
				}
			}
			else if (strcmp(arrlist->t->datatype, "int") == 0) {
				if (*(int*)arrlist->t[i].data == *(int*)val.data) {
					return i;
				}
			}
			else if (strcmp(arrlist->t->datatype, "float") == 0) {
				if (*(float*)arrlist->t[i].data == *(float*)val.data) {
					return i;
				}
			}
			else if (strcmp(arrlist->t->datatype, "double") == 0) {
				if (*(double*)arrlist->t[i].data == *(double*)val.data) {
					return i;
				}
			}
		}
	}
	return -1;  //못 찾은 경우 -1을 반환
}

// 해당 값의 마지막 인덱스 반환
int lastindexOf(ArrayList* arrlist, T val) {
	// 마지막으로 나오는 value 값을 반환한다.
	for (int i = arrlist->size - 1; i >= 0; i--) {
		if (arrlist->t[i].data != NULL) {
			// 포인터가 아닌 값을 비교해야 함
			if (strcmp(arrlist->t->datatype, "bool") == 0) {
				if (*(bool*)arrlist->t[i].data == *(bool*)val.data) {
					return i;
				}
			}
			else if (strcmp(arrlist->t->datatype, "char") == 0) {
				if (*(char*)arrlist->t[i].data == *(char*)val.data) {
					return i;
				}
			}
			else if (strcmp(arrlist->t->datatype, "int") == 0) {
				if (*(int*)arrlist->t[i].data == *(int*)val.data) {
					return i;
				}
			}
			else if (strcmp(arrlist->t->datatype, "float") == 0) {
				if (*(float*)arrlist->t[i].data == *(float*)val.data) {
					return i;
				}
			}
			else if (strcmp(arrlist->t->datatype, "double") == 0) {
				if (*(double*)arrlist->t[i].data == *(double*)val.data) {
					return i;
				}
			}
		}
	}
	return -1;  //못 찾은 경우 -1을 반환
}

// 해당 인덱스의 값 삭제
void removeIndex(ArrayList* arrlist, int index) {
	arrlist->t[index].data = NULL;
	for (int i = index; i < arrlist->size - 1; i++) {
		//인덱스 뒤의 데이터를 이어붙이기
		arrlist->t[i].data = arrlist->t[i + 1].data;
	}
	arrlist->size--;
}

// 해당 값 중 첫번째 값 삭제
void removeValue(ArrayList* arrlist, T val) {
	// val에 해당하는 index 찾기
	int index = indexOf(arrlist, val);
	arrlist->t[index].data = NULL;
	for (int i = index; i < arrlist->size - 1; i++) {
		//인덱스 뒤의 데이터를 이어붙이기
		arrlist->t[i].data = arrlist->t[i + 1].data;
	}
	arrlist->size--;
}

// 해당 값이 배열에 있는지 검색해서 true / false 반환
bool contains(ArrayList* arrlist, T val) {
	for (int i = arrlist->size - 1; i >= 0; i--) {
		if (arrlist->t[i].data != NULL) {
			// 포인터가 아닌 값을 비교해야 함
			if (strcmp(arrlist->t->datatype, "bool") == 0) {
				if (*(bool*)arrlist->t[i].data == *(bool*)val.data) {
					return true;
				}
			}
			else if (strcmp(arrlist->t->datatype, "char") == 0) {
				if (*(char*)arrlist->t[i].data == *(char*)val.data) {
					return true;
				}
			}
			else if (strcmp(arrlist->t->datatype, "int") == 0) {
				if (*(int*)arrlist->t[i].data == *(int*)val.data) {
					return true;
				}
			}
			else if (strcmp(arrlist->t->datatype, "float") == 0) {
				if (*(float*)arrlist->t[i].data == *(float*)val.data) {
					return true;
				}
			}
			else if (strcmp(arrlist->t->datatype, "double") == 0) {
				if (*(double*)arrlist->t[i].data == *(double*)val.data) {
					return true;
				}
			}
		}
	}
	return false;  // 못 찾은 경우 false를 반환
}

// 값 모두 삭제
void clear(ArrayList* arrlist) {
	for (int i = arrlist->size - 1; i >= 0; i--) {
		arrlist->t[i].data = NULL;
	}
	arrlist->size = 0;
}

// 비었으면 true, 하나라도 값이 있으면 false 반환
bool isEmpty(ArrayList* arrlist) {
	if (arrlist->size == 0) {
		return true;
	}
	else {
		return false;
	}
}