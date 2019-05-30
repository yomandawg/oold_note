/*
문자열(string): 문자의 나열
문자들의 배열 char배열: string

실질적으로 메모리에 저장된 값은 각 문자에 해당하는 ASCII값
문자로 생각하냐 숫자로 생각하냐 상관없음

문자열은 문자들이 하나로 뭉쳐서 다니는 것이기 떄문에
문자열을 이용할 때마다 문자열의 길이를 알아야 한다면 매우 불편할 것
=> 문자열의 끝에, 여기까지가 문자열이라고 알려주는 종료 문자를 넣는다
=> ascii값이 0 == '\0' 으로도 나타냄 (문자 0 이 아님!)

즉, <널 - 종료 문자열 (Null-terminated string)> (Null)이라고 부름
Null로 끝나는 문자 => 문자열

Null 문자가 들어갈 공간이 있어야 하기 떄문에 3글자라고 해도,
배열은 4칸이 필요하게 됨
=> 널 종료 문자로 컴퓨터는 문자열의 끝을 쉽게 구할 수 있다
*/

#include <stdio.h>

int main() {
    // 아래 3개는 모두 동일
    char null_1 = '\0'; // Null문자
    char null_2 = 0; // 빈 값 == Null
    // char null_3 = (char)NULL; // 모두 대문자로 써야함

    char not_null = '0'; // '0'과 착각 ㄴㄴ

    printf("%d, %d \n", null_1, null_2);
    printf("'0'의 값: %d \n", not_null);


    char test_1[3] = {'P', 's', 'i'}; // 이상한 값 at the end
    char test_2[3] = {"Psi"}; // 배열의 사이즈를 null값 포함시켜야해
    printf("test_1 : %s \n", test_1);
    printf("test_2 : %s \n", test_2);

    char sentence_1[4] = {'P', 's', 'i', '\0'}; // 종료문자 필수
    char sentence_2[4] = {'P', 's', 'i', 0};
    // char sentence_3[4] = {'P', 's', 'i', (char)NULL};
    char sentence_4[4] = {"Psi"};
    // 쌍따옴표로 묶어주면 알아서 각각의 문자로 넣어줌

    printf("sentence_1 : %s \n", sentence_1); // %s 를 통해서 문자열을 출력한다.
    printf("sentence_2 : %s \n", sentence_2);
    // printf("sentence_3 : %s \n", sentence_3);
    printf("sentence_4 : %s \n", sentence_4);

    return 0;
}


int charptr() {
    char word[30] = {"long sentence"}; // 배열(string)
    char *str = word; // char*을 이용해서 char 배열을 가리킬 수 있다

    printf("%s \n", str); // str이 가리키는 것을 문자열로 출력

    return 0;
}


int swap_words() {
    char word[] = {"long sentence"};
    // 원소 개수를 지정하지 않았지만 [] 빈칸 자체가 컴파일러가 알아서
    // 원소의 수를 세어서 빈칸을 채워 넣으라는 뜻

    printf("이전: %s \n", word);

    word[0] = 'a';
    word[1] = 'b';
    word[2] = 'c';
    word[3] = 'd';

    printf("이후: %s \n", word);

    return 0;
}


int length(char *str) {
    int i = 0;
    while (str[i]) i++; // str[i]가 0이 될때까지
    return i; // 마지막 NULL 문자를 제외한 나머지 문자들의 총 개수
    // 예: string\0
    // s0 t1 r2 i3 n4 g5 \0 end; => len == 5
}

int input_string() {
    char words[30]; // 최대 29글자, 마지막 NULL
    scanf("%s\n", words); // string 입력 형식 %s
    // &를 붙이지 않는 이유는 words 라는 배열 자체가 배열을 가리키고 있는
    // 포인터이기 떄문; words의 값을 전달함으로써 배열의 (시작)주소값을 전달

    char *str = "abcdef"; // 배열 할당 없이 문자열 지정 가능
    // words라는 배열 이름 자체가 배열을 가리키고 있는 포인터이기 때문에

    printf("%s\n", words);
    return 0;
}