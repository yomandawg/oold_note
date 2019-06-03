/*
C표준 라이브러리 지원 메모리 관리 함수
memmove, memcpy, memcmp, memset 등
<string.h> 에 정의됨
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[50] = "I love Chewing C hahaha";
    char str2[50];
    char str3[50];

    // 메모리의 특정한 부분으로부터 얼마까지의 부분을 다른 메모리 영역으로 복사해주는 함수
    // 문자열 복사에 이용 가능 strcpy 와 비슷
    memcpy(str2, str, strlen(str) + 1); // str로부터 strlen(str)+1만큼 문자를 str2로 복사
    // string의 마지막 NULL문자는 세지 않으므로 +1해줘야함
    memcpy(str3, "hello", 6);

    printf("%s \n", str);
    printf("%s \n", str2);
    printf("%s \n", str3);


    
    memmove(str + 23, str + 17, 6); // str+17에서 6개의 문자를 str+23에 옮긴다
    // hahaha의 시작 부분에서 6개의 문자인 "hahaha"를 str의 맨 마지막 부분에 복사해 넣는다
    // memcpy와는 달리 메모리 공간이 겹쳐도 된다.
    printf("%s \n", str); // I love Chewing C hahahahahahaha

    
    int arr[10] = {1, 2, 3, 4, 5};
    int arr2[10] = {1, 2, 3, 4, 5};

    // arr과 arr2를 비교해서 처음 5바이트가 같다면 0 (5개의 원소가 아니라 5바이트!)
    // arr1과 arr2 전체를 비교하고 싶다면 sizeof(int) * 5
    if (memcmp(arr, arr2, 5) == 0) printf("arr과 arr2는 일치! \n");
    else printf("arr과 arr2는 다르다\n");
    // 메모리의 두 부분을 원하는 만큼 비교한다.
    // 같다면 0, 다르다면 0이 아닌 값을 리턴
    

    return 0;
}