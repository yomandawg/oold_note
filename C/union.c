/* Union
공용체
많이 사용하는 기능은 아니지만, 메모리 관리용
구조체와 달리 메모리를 공유하는 members로 이뤄짐
Union의 각 멤버들의 메모리 시작 주소는 모두 동일하다.
따라서 j 값을 변경함으로써 i값을 변경할 수 있고, 등등.
*/

#include <stdio.h>

union A {
    int i;
    char j;
};

int main() {
    union A a;
    a.i = 0x12345678;
    printf("%x", a.j); // 78
    return 0;
}

/*
0x12345678을 보관해서
0x12가 나와야하는 거 아니냐? ㄴㄴ

빅엔디안(Big Endian), 리틀 엔디안(Little Endian)
컴퓨터에서 메모리에 수를 저장할 때,
낮은 주소값에 상위 비트를 적는 방식 = Big Endian
높은 주소값에 상위 비트를 적는 방식 = Little Endian

x86프로세서는 Little Endian

즉 int i = 0x12345678 은

Big Endian방식에서

&i(시작점)     &i+3(포인터 주소값에 3을 더한것)
12 | 34 | 56 | 78
j

j = 0x12 가 된다


Little Endian 방식에서

&i            &i+3
78 | 56 | 34 | 12
j
               (이 때, 메모리에 1 바이트를 기준으로 배치된다)
               다시 말해 12 역시 역으로 21 처럼 보관되는 것은 아니다


1 바이트씩(16*16, 0x기준 00~FF) 역으로 보관한다.
즉, 출력한 j의 값은 0x78이 된다.

만약 j를 short형으로 지정했다면?
0x5678이 나온다!!!

Little Endian
&i
78 | 56 | 34 | 12
---j----

j가 short형(2바이트)이므로 위와 같이 2바이트를 차지하게 됨
j 값을 출력하면 0x5678이 나오는데
컴퓨터는 Little Endian 방식으로 저장한다는 사실을 알기 때문에
적절한 변환을 취해서 0x12345678이 나오는 것
j의 경우도 78 56 을 가리키지만 적절히 변환하여 0x5678을 출력
*/