#include <stdio.h>
#include <stdlib.h>

void get_avg(int **arr, int numStudent, int numSubject);

int main(int argc, char **argv) {
    int i, j, input, sum = 0;
    int subjects, students;
    int **arr; // arr[subject][students]

    scanf("%d", &subjects);
    scanf("%d", &students);

    arr = (int **)malloc(sizeof(int *) * subjects); // 포인터 메모리할당: 2차원 배열처럼 보이기
    for (i = 0; i < subjects; i++) {
        arr[i] = (int *)malloc(sizeof(int) * students); // 각 요소에 메모리 할당: 2차원 배열
        for (j = 0; j < students; j++) {
            scanf("%d", &input);
            arr[i][j] = input;
        }
    }

    get_avg(arr, students, subjects);

    for (i = 0; i < subjects; i++) free(arr[i]);
    free(arr);

    return 0;
}

// void형 함수 리턴값 없음
void get_avg(int **arr, int students, int subjects) {
    // arr은 2차원 배열처럼 보이지만 원소가 int *형이기 때문에 **로 2차원처럼 활용 가능
    // int (*arr)[3]처럼 보임
    int i, j, sum;

    for (i = 0; i < subjects; i++) {
        sum = 0;
        for (j = 0; j < students; j++) sum += arr[i][j];
        printf("%d과목 평균 점수: %d\n", i, sum/students);
    }
    
}