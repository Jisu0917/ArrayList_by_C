#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "solution2.h"


int main() {

    T t = { "char" };
    ArrayList arrlist = { &t , 0, 10 };  // �ʱ⿡ �ڷ��� T, size:0, capacity:10 �� ���� �� �������ֱ�!

    // �Լ� ������ ����ü function�� �ʱ�ȭ�մϴ�.
    function functions = { init, add, get, set, indexOf, lastindexOf, removeIndex, removeValue, contains, clear, isEmpty };// size

    //����Ʈ �ʱ�ȭ
    init(&arrlist);

    //����Ʈ�� �� �Ҵ�
    for (int i = 0; i < 15; i++) {
        char c = 'A' + i;
        T t1 = { "char", &c };
        add(&arrlist, t1);
    }

    printf("\n");

    //Ȯ���� ���� ����Ʈ ���
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

    printf("3, 5, 7 �ε����� �Ȱ��� ���� set �մϴ�.\n\n");

    //Ȯ���� ���� ����Ʈ ���
    for (int i = 0; i < arrlist.size; i++) {
        T t2 = get(&arrlist, i);
        printf("%c, ", *(char*)t2.data);
    }

    printf("\n");

    int index = indexOf(&arrlist, t3);
    printf("\n%c�� ù ��° index : %d\n", *(char*)t3.data, index);

    int lastIndex = lastindexOf(&arrlist, t3);
    printf("\n%c�� ������ lastIndex : %d\n", *(char*)t3.data, lastIndex);


    printf("\n");

    removeIndex(&arrlist, 3);

    //Ȯ���� ���� ����Ʈ ���
    for (int i = 0; i < arrlist.size; i++) {
        T t2 = get(&arrlist, i);
        printf("%c, ", *(char*)t2.data);
    }

    printf("\n\n%c�� 1�� �����߽��ϴ�.\n\n", *(char*)t3.data);


    removeValue(&arrlist, t3);


    //Ȯ���� ���� ����Ʈ ���
    for (int i = 0; i < arrlist.size; i++) {
        T t2 = get(&arrlist, i);
        printf("%c, ", *(char*)t2.data);
    }

    printf("\n\n%c�� 1�� �����߽��ϴ�.\n\n", *(char*)t3.data);


    if (contains(&arrlist, t3)) {
        printf("%c(��)�� �����ϰ� �ֽ��ϴ�.\n", *(char*)t3.data);
    }
    else {
        printf("%c(��)�� �������� �ʽ��ϴ�.\n", *(char*)t3.data);
    }

    printf("\n");

    clear(&arrlist);

    printf("����Ʈ�� clear �߽��ϴ�.\n\n");

    if (isEmpty(&arrlist)) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
    }
    else {
        printf("����Ʈ�� ������� �ʽ��ϴ�.\n");
    }

    free(arrlist.t);  // ���� �Ҵ�� �޸� ����

    return 0;
}