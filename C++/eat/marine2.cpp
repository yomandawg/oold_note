// Marine의 수를 알아내기 위한 코드를 짠다!
// 1. 어떤 배열에 Marine을 보관해 놓고, 생성된 마린의 개수를 모두 센다.
// 2. 어떤 변수를 만들어서 Marine 생성시 1을 추가, 소멸시 1 감소

// 1번의 경우 vector 자료형 이용하면 쉽지만... 따로 크기가 자유자재로 변할 수 있는 배열을
// 따로 만들어야 하는 문제점
// 2번의 경우 어떤 함수 내에서 이런 변수를 정의하였다면 다른 함수에서도 그 값을 이용하기 위해 인자로 계속 전달해야 하는 귀찮음
// 전역 변수로 만들 경우 프로젝트가 커질 술고실수로 인해 겹쳐서 오류가 날 가능성이 커진다
// 필요한 경우가 아니면 전역 변수는 지양
// C++에서는 전역 변수 같지만 클래스 하나에만 종속되는 변수인 static 멤버 변수 사용

// C언어의 static 변수가 지역 변수들처럼 함수가 종료될 때 소멸되는게 아니라 프로그램이 종료될 때, 소멸
// 어 떤 class의 static 멤버 변수의 경우, 멤버 변수들처럼 객체가 소멸될 때 소멸되는 것이 아닌,
// 프로그램이 종료될 때 소멸
// 이 static 멤버 변수의 경우, 클래스의 모둔 객체들이 공유하는 변수
// 객체 별로 따로 존재하는 멤버 변수들과는 달리 모든 객체들이 하나의 멤버 변수를 사용

#include <iostream>


class Marine {
    static int total_marine_num; // 클래스 static 변수
    // 모든 전역 및 static 변수들은 정의와 동시에 값이 자동으로 0으로 초기화되기 때문에 초기화 필요 없음
    // 이 안에서 멤버 변수들은 안에서 초기화시키지 못하는 것처럼 static 변ㅅ ㅜ역시 클래스 내부에서 위와 같이 초기화 하는 것은 불가능
    // const static int x = 0; 의 경우 가능하긴 함 (상수 static 변수 클래스 내부에서 초기화 가능)
    const static int i = 0;

    int hp; // 마린 체력
    int coord_x, coord_y; // 마린 위치
    bool is_dead;

    const int default_damage; // 기본 공격력


    public:
        Marine(); // 기본 생성자
        Marine(int x, int y); // x, y 좌표에 마린 생성
        Marine(int x, int y, int default_damage); // 기본 공격력까지

        int attack() const; // 데미지 리턴
        void be_attacked(int damage_earn); // 입는 데미지
        void move(int x, int y); // 새로운 위치

        void show_status(); // 상태 표시

        static void show_total_marine(); // static 함수 inside 클래스 - 특정 객체에 종속되는 것이 아니라
        // 클래스 전체에 딱 1개 존재하는 함수
        // static함수의 경우 객체가 없어도 클래스 자체에서 호출할 수 있다!!!


        Marine& be_attacked2(int damage_earn); // 입는 데미지

        ~Marine() { total_marine_num--; } // 소멸자
};
int Marine::total_marine_num = 0; // 클래스 static 변수 초기화하는 방법

// 생성될 때 (생성자에서) 또는 소멸자에서 클래서 static 변수 조작 가능
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) { total_marine_num++; }
Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) { total_marine_num++; }
Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) { total_marine_num++; }

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() const { return default_damage; } // const 함수 - 상수 멤버 함수
// 상수 함수로 정의함으로써, 이 함수는 다른 변수의 값을 바꾸지 않는 함수라고 명시
// 상수 함수 내에서는 객체들의 읽기만 수행되며, 상수 함수 내에서 호출할 수 있는 함수는 다른 상수 함수밖에 없다
// 사실 많은 경우 클래스를 설계할 때, 멤버 변수들은 모두 private에 넣고, 이 변수들을 값에 접근하는 방법으로
// get_x 함수 처럼 함수를 public에 넣어 이 함수를 이용해 리턴받는 형식을 사용
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
    Marine marine3(10, 10, 4);
    marine3.show_status();
    Marine::show_total_marine();
}

void Marine::show_total_marine() {
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
    // std::cout << default_damage << std::endl; // default_damage는 멤버 변수이므로
    // 누구의 default_damage인지 모른다. => static 함수에서 사용 불가능
}


Marine& Marine::be_attacked2(int damage_earn) {
    hp -= damage_earn;
    if(hp <= 0) is_dead = true;

    return *this; // C++ 언어에서 정의된 키워드
    // 객체 자신을 가리키는 포인터 역할 - 멤버 함수를 호출하는 객체 자신을 가리키는 것

    // Marine& 타입을 리턴하게 되는데(*this) 객체 자신을 의미함 - 이렇게 하지 않으면 .을 연쇄적으로 붙일 때
    // 엉뚱한 임시 객체에 대해 호출된다.
}

// Marine& Marine::sameasabove(int damage_earn) {
//     this->hp -= damage_earn;
//     if (this->hp <= 0) this->is_dead = true;

//     return *this;
// }

// 실제로 모든 멤버 함수 내엔 this 키워드가 정의되어 있으며 클래스 안에서 정의된 함수 중에도 this
// 키워드가 없는 함수는 static함수 뿐


int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();
    Marine::show_total_marine(); // static 클래스 함수의 경우 객체에 종속되는 것이 아니라
    // 클래스에 종속되는 것이므로 (클래스)::(static 함수) 형식으로 호출
    // 어떠한 객체도 이 함수를 소유하고 있지 않기 때문.
    // => static 함수 내에서는 클래스의 static 변수만을 이용할 수밖에 없다.

    Marine marine2(3, 5, 10 );
    marine2.show_status();
    Marine::show_total_marine();

    create_marine(); // 지역 객체인 marine3은 create_marine()이 끝난 후 소멸
    
    std::cout << std::endl << "마린 1이 마린 2를 공격!" << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status(); // 총 마린 수 표시할 때 2명으로 나오겠지
    marine2.show_status();

    marine2.be_attacked2(marine1.attack()).be_attacked2(marine1.attack()); // 두 번 공격
}





class A {
    int x;

    public:
        A(int c) : x(c) {}

        int& access_x() { return x; } // x의 레퍼런스 리턴
        int get_x() { return x; } // x의 값 리턴
        void show_x() { std::cout << x << std::endl; }
};

int main() {
    A a(5); 
    a.show_x(); // 5

    int& c = a.access_x(); // c는 x의 레퍼런스, 즉 x의 별명을 받는다 (int &c = x; 와 동일)
    c = 4;
    a.show_x(); // 4로 바뀌었다!

    int d = a.access_x(); // x의 별명을 전달함 - 그냥 int변수이므로 값의 복사가 일어난다
    d = 3; // x의 값은 바뀌지 않는다
    a.show_x(); // 4

    // int& e = a.get_x(); // 임시로 x의 내용을 복사한 int 변수가 생성
    // e = 2;  // 이 임시 객체는 int 문장이 끝나면 소멸되므로 레퍼런스를 가질 수 없다!
    // a.show_x();
    // 이는 오류 - 레퍼런스가 아닌 타입을 리턴하는 경우는 '값'의 복사가 이뤄지기 떄문에
    // 임시 객체가 생성되는데 임시객체의 레퍼런스를 가질 수 없다! (임시 객체는 문장이 끝나면 소멸)

    // x'는 문장이 끝날 때 자동으로 소멸되는 임시 객체이기 때문에 레퍼런스를 만들 수 없다
    // 만약 어떻게 해서 레퍼런스를 만들어도 존재하지 않는 것에 대한 별명이므로 접근하면 오류!

    int f = a.get_x();
    f = 1; // 이는 실제 객체 a의 x에 영향을 끼칠 수 없다
    a.show_x();

    a.access_x() = 3; // 이 문장은 오류가 아니다! 와이?!
    // 레퍼런스를 리턴하는 함수는 그 함수 부분을 리턴하는 원래 변수로 치환해도 된다
    // a.x = 3; // 즉 이 말과 같은 말이다!

    // a.get_x() = 3; 은 오류다 왜냐면 이것이 러턴하면서 생성되는 임시 객체 x' 로 치환되어
    // 임시객체에 대입하게 되는 모순
}