#include <iostream>

class Marine {
    int hp; // 마린 체력
    int coord_x, coord_y; // 마린 위치
    int damage;
    bool is_dead;

    const int default_damage; // 기본 공격력
    // 실수를 막기 위해 기본공격력 상수 도입 후 고정시켜서 함
    // 상수의 경우 생성자에서 초기화 리스트 도입해서 생성과 동시에 초기화해야함
    // 중요 값들은 상수로 처리하는게 유용 - 다른 프로그래머가 이 클래스를 사용하면서 실수로 건드리면 컴파일 오류!
    // 디버깅 효율적으로 가능

    public:
        Marine(); // 기본 생성자
        Marine(int x, int y); // x, y 좌표에 마린 생성
        Marine(int x, int y, int default_damage);

        int attack(); // 데미지 리턴
        void be_attacked(int damage_earn); // 입는 데미지
        void move(int x, int y); // 새로운 위치

        void show_status(); // 상태를 보여준다.
};

// (생성자 이름) : var1(arg1), var2(arg2) {}
// 기존 생성자와 다르게 함수 내부에 내용이 없다
// 내부에서 하던 멤버 변수들의 초기화 작업들을 대신해서 하고 있는 것.
// 초기화 리스트(initializer list) 라 함 - 생성자 호출과 동시에 멤버 변수들을 초기화해주게 됨
Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false), default_damage(5) {}
Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false), default_damage(5) {}
// var들은 클래스 멤버 변수들 지칭, arg는 멤버 변수를 무엇으로 초기화할지 지칭
// var과 arg의 이름이 같아도 정상적으로 작동 var은 멤버변수 지칭이고 arg는 받는 인자 지칭
// 원래 방식으론 컴파일러가 두 coord_x 모두 같은거로 구분해서 오류!
// coord_x = coord_x; 오류!

// 왜 초기화 리스트를 사용하는가?
// 생성과 초기화를 동시에 하기 때문!!!
// 초기화 리스트 사용 않는다면 생성 후 그 다음에 대입한다.
// 즉, initializer list는 int a = 10;과 같고, => int 대신 클래스면 복사 생성자가 바로 호출
// 원래 방식은 int a; a = 10; 과 같다 => 디폴트 생성자 호출 뒤 대입 수행 => 작업량 증가

// 반드시 생성과 동시에 초기화 되어야 하는 것 => 레퍼런스, 상수 등
// const int a = 3;
// int& ref = c;
// 클래스 내부에 레퍼런스 변수나 상수를 넣고 싶다면 이들을 생성자에서 무조건 초기화 리스트를 사용해서 초기화해야함

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) {}
// 상수인자에 초기화 리스트로 전달해도 초기화하는건 마찬가지이기 때문에 괜찮다


void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3, 10); // 좌표만 정의하고 나머지는 initializer list 통해 초기화
    Marine marine2(3, 5, 10);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1이 마린 2를 공격!" << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}