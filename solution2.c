#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "solution2.h"


int main() {

    T t = { "char" };
    ArrayList arrlist = { &t , 0, 10 };  // 초기에 자료형 T, size:0, capacity:10 세 가지 꼭 지정해주기!

    // 함수 포인터 구조체 function을 초기화합니다.
    function functions = { init, add, get, set, indexOf, lastindexOf, removeIndex, removeValue, contains, clear, isEmpty };// size

    //리스트 초기화
    init(&arrlist);

    //리스트에 값 할당
    for (int i = 0; i < 15; i++) {
        char c = 'A' + i;
        T t1 = { "char", &c };
        add(&arrlist, t1);
    }

    printf("\n");

    //확인을 위해 리스트 출력
    for (int i = 0; i < arrlist.size; i++) {
        T t2 = get(&arrlist, i);
        printf("%c, ", *(char*)t2.data);
    }

    printf("\n");

    char v = 'D';
    T t3 = { "char", &v };
    set(&arrlist, 3, t3);
    set(&arrlist, 5, t3);
    set(&arrlist, 7, t3);

    printf("\n");

    printf("3, 5, 7 인덱스에 똑같은 값을 set 합니다.\n\n");

    //확인을 위해 리스트 출력
    for (int i = 0; i < arrlist.size; i++) {
        T t2 = get(&arrlist, i);
        printf("%c, ", *(char*)t2.data);
    }

    printf("\n");

    int index = indexOf(&arrlist, t3);
    printf("\n%c의 첫 번째 index : %d\n", *(char*)t3.data, index);

    int lastIndex = lastindexOf(&arrlist, t3);
    printf("\n%c의 마지막 lastIndex : %d\n", *(char*)t3.data, lastIndex);


    printf("\n");

    removeIndex(&arrlist, 3);

    //확인을 위해 리스트 출력
    for (int i = 0; i < arrlist.size; i++) {
        T t2 = get(&arrlist, i);
        printf("%c, ", *(char*)t2.data);
    }

    printf("\n\n%c를 1개 삭제했습니다.\n\n", *(char*)t3.data);


    removeValue(&arrlist, t3);


    //확인을 위해 리스트 출력
    for (int i = 0; i < arrlist.size; i++) {
        T t2 = get(&arrlist, i);
        printf("%c, ", *(char*)t2.data);
    }

    printf("\n\n%c를 1개 삭제했습니다.\n\n", *(char*)t3.data);


    if (contains(&arrlist, t3)) {
        printf("%c(을)를 포함하고 있습니다.\n", *(char*)t3.data);
    }
    else {
        printf("%c(을)를 포함하지 않습니다.\n", *(char*)t3.data);
    }

    printf("\n");

    clear(&arrlist);

    printf("리스트를 clear 했습니다.\n\n");

    if (isEmpty(&arrlist)) {
        printf("리스트가 비어있습니다.\n");
    }
    else {
        printf("리스트가 비어있지 않습니다.\n");
    }

    free(arrlist.t);  // 동적 할당된 메모리 해제

    return 0;
}