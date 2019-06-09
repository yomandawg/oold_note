// 생성자를 통해 이전에 C프로그래밍 시 변수를 초기화하지 않아서 생겼던
// 수많은 오류들을 효과적으로 없앨 수 있었다.

// C++에서 새로 도입된 함수 오버로딩 덕분에 함수 이름을 따로 지정하지 않더라도
// 성공적으로 인자들의 타입에 따라 원하는 함수들만 호출할 수 있게 되었다.
// C였다면 인자의 타입에 따라서 함수의 이름들을 외워야했지만, C++에서는 그럴필욕 전혀 없게 되었다는 것

#include <string.h>
#include <iostream>

class Marine {
    // 객체의 내부적 성질, 상태 등 관련 변수는 private 범주
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name; // 각각 마린에 이름 부여

    // 객체가 외부에 아는 행동들은 함수로 구현하여 public 범주
    public:
        Marine(); // default constructor
        Marine(int x, int y, const char* marine_name); // 이름 지정 constructor
        Marine(int x, int y); // custom constructor
        ~Marine();

        int attack(); // damage return
        void be_attacked(int damage_earn); // 입는 데미지
        void move(int x, int y);    // 새로운 위치

        void show_status(); // return status
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    // 이 동적 할당 문자열의 delete는 언제 이루어지나?
    // 자동 delete는 없다! 객체를 그냥 delete하면 name은 메모리 누수가 됨
    // 가끔 몇몇 프로그램들이 비정상적으로 많은 메모리를 점유하는 것이 이것
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
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
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1이 마린 2를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}


int test() {
    Marine* marines[100];

    marines[0] = new Marine(2, 3, "Marine 2"); // new의 경우 malloc과 다르게 객체를 동적으로 생성하면서 동시에 자동으로 생성자도 호출해준다
    marines[1] = new Marine(3, 5, "Marine 1");

    marines[0]->show_status(); // Marine들의 포인터를 가리키는 배열이기 때문에 메소드를 호출할 때 . 이 아니라 ->를 사용
    marines[1]->show_status();

    std::cout << std::endl << "마린 1이 마린 2를 공격!" << std::endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0]; // 동적 할당 메모리는 언제나 해제해야함
    delete marines[1];

    // Main함수 끝에 marine이 delete될 때, (생성한 객체가 소멸될 때 자동으로 호출되는 함수)
    // 소멸자 Destructor!
}