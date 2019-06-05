/* OOP
프로그램이 거대해지자 절차지향으로 버틸 수 없어 생긴 패러다임

C++, Java, Python, C# 등 대부분의 현대 언어들은 객체지향
*/

#include <iostream>

// 절차지향의 문제점
typedef struct Animal {
    char name[30];
    int age;
    int health;
    int food;
    int clean;
} Animal;

int play(Animal *animal) {
    return 0;
}

int main() {
    int play_with = 0;
    Animal *list[10];
    play(list[play_with]); // play 함수에 인자로 전달하는 것이 매우 불편해 보임
    // 마치 play가 Animal을 합니다! 라는 뜻으로 보임
    // 즉, Animal 자체가 play하는 것이지 반대가 아님
}


// Aniaml은 작신의 상태를 알려주는 변수(variable)과 행동(method)로 이뤄졌다 봐도 된다.
// 즉, 객체란 변수들과 참고 자료들로 이뤄진 소프트웨어 덩어리이다.
// 이 때 객체가 현실 세계에서의 존재하는 것들을 나타내기 위해 추상화(abstaction)이라는 과정이 필요
// 적절하게 컴퓨터가 처리할 수 있도록 현실세계 요소들을 바꾸는 것인데
// 행동들을 함수로 추상화시키고, 상태를 변수로 추상화시킴

// 이러한 객체의 변수나 함수들을 보통 인스턴스 변수(instance variable)
// 인스턴스 메소드(instance method)라고 부른다

// 변수들고 메소드가 외부로부터 '보호'되고 있기 떄문에, 즉, 외부에서 어떠한 객체의
// 인스턴스 변수 값을 바꾸지 못하고 오직 객체의 인스턴스 함수를 통해서만 가능
// (사용자가 조절할 수 있긴 함)

// 예)
// Animal anima;
// 초기화 과정
// animal.food += 100; // 불가능
// animal.increase_food(100); // 가능

// 이와 같이 외부에서 직접 인스턴스 변수 값을 바꿀 수 없고 항상 인스턴스 메소드를 통해
// 간접적으로 조절하는 것을 캡슐화(encapsulation)이라고 부름
// 이런 개념을 간단하게 객체가 내부적으로 어떻게 작동하는지 몰라도 사용할 수 있게 되는 것으로
// 볼 수 있다.

// 대형 프로젝트에선 객체를 설계하는 것이 아니기 때문에 다른 사람이 작성한 것을 이해해야함

// 화면의 글자를 띄우는 행위도 my_computer.keyboard_hit('a')같은 작업임


/* 클래스
클래스(설계도) 객체를 만들 수 있는 장치
클래스를 이용해서 만들어진 객체를 인스턴스라 함
*/

class Animal {
    // 접근 지시자들
    private: // 객체 외부에서 접근 할 수 없음
        int food;
        int weight;
    
    public: // 객체 함수 호출로 접근
        void set_animal(int _food, int _weight) { // 객체 내부에서 변수로 private 접근 가능
            food = _food;
            weight = _weight;
        }
        void increase_food(int inc) {
            food += inc;
            weight += (inc / 3);
        }
        void view_stat() {
            std::cout << "이 동물의 food : " << food << std::endl;
            std::cout << "이 동물의 weight : " << weight << std::endl;
        }
}; // semicolon 필수

int tryman() {
    Animal animal; // 구주체 변수를 생성할 때와 동일하게 클래스 만듦(앞에 struct 필요없고)
    animal.set_animal(100, 50);
    animal.increase_food(30);
    animal.view_stat();
    return 0;
}

