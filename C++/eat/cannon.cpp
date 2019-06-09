#include <string.h>
#include <iostream>

class PhotonCannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char *name;

    public:
        PhotonCannon(const PhotonCannon& pc); // 복사 생성자 - 복사 생성자의 표준적 정의
        // 복사 생성자는 어떤 클래스 T가 있다면
        // T(const T& a); 라고 정의하는게 표준
        // 즉, 다른 T의 객체 a를 상수 레퍼런스로 받는다
        // a가 const(상수)이기 떄문에 복사 생성자 내부에서 a의 데이터를 변경할 수 없고,
        // 오직 새롭게 초기화되는 인스턴스변수들에게 '복사'만 할 수있게 된다.
        PhotonCannon(int x, int y);
        PhotonCannon(int x, int y, const char *cannon_name); // 이름을 추가할 수 있게 한다면?
        ~PhotonCannon(); // 소멸자

        void show_status();
};
// 사실 이것이 default 복사 생성자의 예시다!
// 이와 같이 간단한 클래스의 경우 복사생성자를 써주지 않고도
// 디폴트 복사 생성자만 이용해 복사 생성을 쉽게 처리할 수 있다.
PhotonCannon::PhotonCannon(const PhotonCannon& pc) {
    // 즉, 위와 같이 복사 생성자 내부에서 pc의 인스턴스 변수들에 접근해
    // 객체의 인자들을 초기화할 수 있지만
    // pc.coord_x = 3;처럼 값 자체는 변경할 수 없다 (const로 받기 때문)
    // 중요한 점은 함수 내부에서 받은 인자의 값을 변화시키는 일이 없다면 꼭 const를 붙여준다.
    // 인자로 받은 pc의 값을 변경할 일이 없기 때문에.
    // 후에 발생할 수 있는 실수를 막을 수 있다.
    std::cout << "복사 생성자 호출!" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    // name = pc.name; // 이것은 오류다! - 런타임 에러!
    // name이 같은 값 - 즉 두 개의 포인터가 같은 값을 가진다는 것은
    // 같은 주소값을 가리킨다는 말이 됨! (name은 배열을 가리키니 포인터)
    // pc1의 name이 동적으로 할당받아서 가리키고 있던 메모리를 pc2도 가리키게 되는것
    // 이 상태는 별 문제가 아니지만
    // 객체 파괴에서 소멸자 호출에서
    // pc1이 파괴되면 포인터가 가리킨 메모리까지 delete하게 된다
    // 문제는 pc2의 name이 해제된 메모리를 가리키는 것!

    // default copy constructor 한계 문제 해결
    name = new char[strlen(pc.name) + 1];
    strcopy(name, pc.name);
}
PhotonCannon::PhotonCannon(int x, int y) {
    std::cout << "생성자 호출!" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = NULL;
}
void PhotonCannon::show_status() {
    std::cout << "Photon Cannon" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}


// 이름추가할 때 overloading 메소드
PhotonCannon::PhotonCannon(int x, int y, const char *cannon_name) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    
    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}
// 소멸자에서도 메모리 해제시 각기 다른 메모리를 해제하는 것이므로 문제 발생 x

PhotonCannon::~PhotonCannon() {
    // 0이 아닌 값은 if문에서 true로 처리되므로
    // 0인가 아닌가를 비교할 때 그냥 if(name) 하면
    // if(name != 0)과 동일한 의미
    if (name) delete[] name;
    // pc2에서 일단 name은 NULL이 아니므로 delete [] name이 수행되고
    // 해제된 메모리에 접근해 다시 해제하려고 했기 때문에
    // 접근 자체도 오류지만 또 해제하는 부분에서 런타임 오류

    // 이 문제를 해결하기 위해 복사 생성자에서 name을 그대로 복사하지 말고
    // 다른 메모리에 동적 할당을 해서 그 내용만 복사하면 된다!
    // 이 메모리를 새로 할당해서 복사하는 것을 깊은 복사(deep copy)
    // 단순히 대입만 해주는 것을 얕은 복사(shallow copy)라고 함
    // 컴파일러가 생성하는 디폴트 복사 생성자의 경우 얕은 복사이므로
    // 깊은 복사를 위해 직접 복사 생성자를 만들어야 함! - default copy constructor의 한계
}


int main() {
    PhotonCannon pc1(3, 3, "Cannon"); // x, y를 인자로 가져오는 생성자가 오버로딩
    PhotonCannon pc2(pc1); // pc1을 넘겼으므로 복사 생성자 호출
    PhotonCannon pc3 = pc2; // 이것 역시 복사 생성자, 위와 동일하게 해석한다
    // pc3 = pc2; 는 평범한 대입 연산이지만,
    // 생성시에 대입하는 연산, 즉 위와 같이 한다면 복사 생성자 호출
    // 직관적이고 깔끔한 프로그래밍
    // 복사 생성자는 오직 생성시에만 호출된다는 것을 명심!
    // 근데 C++은 default 복사 생성지를 지원한다!

    pc1.show_status();
    pc2.show_status();
}