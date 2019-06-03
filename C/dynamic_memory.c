/*
배열의 크기를 자유자재로 다룰 수 있으면 얼마나 좋을까?
배열을 정할 때 크기는 언제나 컴파일 시간에 확정됨
즉 컴파일러가 배열의 크기를 추측할 필요 없이 명확하게 나타나 있어야 한다.
따라서 배열을 충분히 크게 잡게 되는데 메모리 낭비가 심하다. => 비효율
만약 학생 수를 입력 받고 그만큼 배열의 크기를 지정하면 얼마나 좋을까? => 동적 메모리 할당

동적==가변 가능, 할당 == 배열에 맞는 메모리의 특정한 공간이 배열을 나타내는 것처럼 메모리의 특정부분을 사용 가능
할당되지 않는 메모리는 이용할 수 없다.
*/

#include <stdio.h>
#include <stdlib.h> // malloc 정의

// malloc은 메모리의 힙(heap)영역에 할당함
// stack, data segment, read-only data부분은 malloc이 건드릴 수 없는 부분
// => 컴파일 때 정해지는 영역들
// 힙의 경우는 자유롭게 할당 해제 가능 (malloc)
// => 자유로운 만큼 제대로 사용해야함, 공간낭비 주의

int main(int argc, char **argv) {
    int sizeOfArray;
    int *arr;

    printf("%d", &sizeOfArray); 

    // memory allocation
    arr = (int *)malloc(sizeof(int) * sizeOfArray); // int arr[sizeOfArray]와 동일한 크기의 배열 생성
    // sizeof()를 통해 type 크기만큼 지정(컴퓨터마다 형 크기가 다르기 때문)
    // sizeof(int)*sizeOfArray를 통해 4*sizeOfArray 바이트 크기만큼 malloc
    // malloc은 자신이 할당한 메모리의 시작 주소를 리턴함
    // void * 형으로 리턴하므로 (int *)형으로 형변환하여 arr에 넣어주면 배열과 같게 됨
    free(arr); // 메모리 영역을 다시 컴퓨터에게 돌려주는 역할(해제)
    // free제대로 안하면 메모리 누수(memory leak) 자원 낭비



    int student;
    int i, input;
    int *score;
    int sum = 0;

    scanf("%d", &student); // 학생 수
    score = (int *)malloc(student * sizeof(int)); // 원소 개수가 student인 int형 배열 생성
    // malloc return void형이므로 포인터 형지시를 통해 int형 배열처럼 만듦

    for (i = 0; i < student; i++) {
        scanf("%d", &input); // 학생의 점수
        score[i] = input;
    }
    for (i = 0; i < student; i++) sum += score[i];

    printf("%d\n", sum/student); // 전체 학생 평균 점수
    
    free(score);




    // 2차원 배열 동적 할당
    int x, y;
    int **arr; // arr[x][y]를 위해 더블 포인터
    // int arr[3]이란 배열을 만들었다면 arr의 형은 int *와 같다
    // 즉, int * arr[10] 이란 배열을 만들었다면 arr의 형은 int **arr이다.

    scanf("%d %d", &x, &x);
    arr = (int **)malloc(sizeof(int *) * x); // int* 형의 원소를 x개 가지는 1차원 배열 생성
    // int * 형 배열을 동적 할당
    
    // 0   <= arr
    // 1   각각의 타입은 int * 이므로 4byte 차지
    // 2
    // ...
    // x-1

    // arr 배열의 각각 원소들은 int *형이므로 다른 int배열을 가리킬 수 있다
    for (i = 0; i < x; i++) arr[i] = (int *)malloc(sizeof(int) * y);
    // 각각의 원소들에 대해 메모리 공간을 짝지어주기
    // arr의 하나의 원소가 크기가 y인 배열을 가리키고 있는데
    // arr의 원소가 x개이므로 전체적으로 x*y의 배열을 갖는다
    // 이는 정확히 2차원 배열이라 말할 수는 없는데
    // 기존의 배열은 메모리에 연속적으로 존재하기 때문
    // 하지만 동적 할당 배열은 연달아 존재하지 않는다.
    // 또한 int array(int **arr);와 같이 함수의 인자로 넘길 수 있다!
    // 이가 가능한 이유는 우리가 만든 배열이 1차원 배열이지 2차원 배열이 아니기 때문
    // arr은 단순히 int *형 원소들을 갖는 1차원 배열
    // 1차원 배열을 인자로 넘겨줄 때는 크기를 써주지 않아도 된다
    // main의 인자인 argv 역시 이와 같은 성격을 띔
    // 하지만 2차원 배열처럼 arr[3][4]와 같이 원소접근 가능
    // arr[3][4] == *(*(arr+3)+4)이므로 포인터적으로 접근 가능

    for (i = 0; i < x; i++) free(arr[i]); // 이거부터 해서 2차원 배열을 해제해야함
    free(arr); // 이거 먼저 하면 arr[i]들이 가리키고 있던 int배열들을 해제할 수 없게 된다.


    return 0;
}