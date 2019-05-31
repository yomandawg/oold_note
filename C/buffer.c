#include <stdio.h>


int example();

int main() {

    example();


    int num;
    char c;

    scanf("%d", &num);
    scanf("%c", &c);
    // 컴퓨터에게 abcde를 입력하면, 각 문자를 입력받을 때마다 처리한다면 (a, b, c..) cpu 사용량 높아진다
    // 문자를 다른곳에 잠시 보관해 놓았다가 입력이 끝난다면 보관한 정보를 한꺼번에 처리한다면 더 빠르다
    // 이 '양동이'에 해당하는 부분이 buffer(버퍼)
    // 키보드 입력을 처리하는 버퍼는(입력버퍼) stdin(입력 스트림 stream)
    // 모든 정보는 일시적으로 stdin에 저장되었다가 나중에 입력이 종료되면 한꺼번에 처리
    // 입력 종료 == enter(\n 개행문자)
    // 하지만 \n까지 버퍼에 저장하게 됨
    // 입력을 끝냈다면 scanf함수를 이용해 stdin으로부터 숫자를 얻어옴
    // scanf는 ' ', '\n' '\t'(tab)를 만날 떄까지 stdin에서 데이터를 얻어온다
    
    // %d 계열은(수를 입력받는 형식)은 수가 아닌 데이터가 와도 입력을 종료함
    // 즉 a를 입력했다면 num에는 아무런 값이 들어가지 않아 치명적인 결과를 야기
    // 공백문자가 나타나면 수가 나타날 때까지 입력을 계속 받게 됨(엔터를 아무리 쳐도 넘어가지 않는다)
    // 즉 scanf는 공백문자를 만나기 전까지 stdin에서 데이터를 가져간 후 버퍼에서 삭제

    // %c는 이유불문 stdin에서 한 개의 문자만을 가져옴
    // 하지만 \n을 버퍼에 남겨놓았기 떄문에 scanf는 이를 c에 집어넣음
    // 즉, c에는 사용자 입력을 받지도 않고 '\n'을 집어넣는 것

    // 만일 printf("%c 출력", c); 해보면 '출력'이 한 칸(엔터가 쳐져서) 나타나게 된다
    printf("%c output", c);

    char str[30];
    int i;
    scanf("%d", &i); // 수를 받게 되면 stdin에는 \n이 남아있게 됨
    scanf("%s", str); // 실질적인 데이터가 나오기 전까지 버퍼에 남아있는 문자들은 무시함
    // 그 다음에 \n 추가함
    printf("str: %s\n", str); // %c와는 달리 %s의 경우 컴퓨터가 사용자 입력을 잘 받음
    
    // %c를 이용할 때는 버퍼에 무엇이 남아있지 잘 고려해야함


    return 0;
}


int example() {
    char str1[10], str2[10];

    scanf("%s", str1);
    printf("string: %s \n", str1);

    scanf("%s", str2);
    printf("string: %s \n", str2);

    // 만약 hello baby를 입력하면 두번째 scanf를 무시함
    // hello baby를 입력했을 때 stdin에는 "hello baby\n"
    // scanf 함수는 stdin으로부터 의미가 있는 문자(공백 문자 등)을 제외한 나머지 문자가 나올 때까지
    // 모든 공백문자들을 무시함
    // 위의 경우 stdin에서 처음에 공백문자가 하나도 없으므로 바로 stdin으로부터 데이터를 가져오고
    // 가져오다가 공백 문자를 만나면 입력을 중지함
    // 위의 경우 ' '이 공백 문자의 역할을 하기 때문에 str1에는 hello까지만 입력이 됨

    // scanf 함수를 지나치면 stdin의 모습은 " baby\n"

    // 끝나고 메모리에는 \n만 남아있음

    return 0;
}


int clrbuffer() {
    int num;
    char c;
    scanf("%d", &num);

    fflush(stdin); // visual stdio계열의 컴파일러(MS)에서만 됨, gcc에선 안됨
    // stdin을 비워라 - 버퍼를 비워라(버퍼에 남아있던 \n이 사라짐)
    // VS2015부터는 표준을 따라 위가 작동하지 않음

    scanf("%c", &c); // 이 상태에서 scanf 호출하면 %c는 버퍼에 아무것도 남아있는 것이 없으므로
    // 다음 입력을 기다리게 되고, c에 원하는 값을 넣을 수 있음
    return 0;
}

int getchar_example() {
    int num;
    int c;

    scanf("%d", &num); // 후에 \n이 남아있게 됨

    getchar(); // stdin에서 한 문자를 읽어와 그 값을 return

    scanf("%c", &c);

    // 만약 123abc 를 넣으면 
    // %d에서 a가 들어올때 숫자가 아니기 때문에 stdin에서 그만 읽어온다
    // 그 다음에 남은 stdin 상태: abc\n
    // getchar); 후 a를 받아오므로 상태: bc\n - 버퍼가 깔끔하게 비워지지 않았으므로
    // 그 다음 scanf의 %c에선 b가 입력
    // 팁! %s로 문자열을 받아온 후 첫번째 문자를 가져오자!
}