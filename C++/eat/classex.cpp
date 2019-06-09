#include <iostream>

class Date {
    int year;
    int month;
    int day;

    public:
        void set_date(int _year, int _month, int _date);
        void add_day(int inc);
        void add_month(int inc);
        void add_year(int inc);
        void show_date();

        // default 생성자
        Date() {
            year = 2012;
            month = 7;
            day = 12;
        }

        // 생성자 오버로딩

        // <생성자> 객체 생성시 자동으로 호출되는 함수
        // 이 때 자동으로 호출되며 객체를 초기화해주는 역할
        Date(int _year, int _month, int _day) {
            year = _year;
            month = _month;
            day = _day;
        }
};


// Date:: 을 함수 이름 앞에 붙여주게 되면 이 함수가
// Date 클래스에 정의된 함수
void Date::set_date(int _year, int _month, int _day) {
    year = _year;
    month = _month;
    day = _day;
}
// 보통 간단한 함수를 제외하면 대부분 함수는 클래스 바깥에서 정의함
// 클래스 내부에 쓸 경우 클래스 크기가 길어져 보기 안좋다
// 클래스 자체만 따로 헤더 파일로 뺄 수도 있다.

void Date::add_day(int inc) {
    int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = month;

    if (month_day[i - 1] - day >= inc) {
        day += inc;
        return;
    } else {
        add_month(1);
        day = 1;

        inc = inc - (month_day[i - 1] - day) - 1;
        i++;
    }
    while (true) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            month_day[1] = 29; // 윤년
        } else {
            month_day[1] = 28;
        }

        // 만약 그 달을 추가할 수 있다면
        if (inc - month_day[i - 1] >= 0) {
            add_month(1);
            inc -= month_day[i - 1];
        } else if (inc - month_day[i - 1] < 0) {
            day += inc;
            break;
        }

        i++;
        if (i > 12) i -= 12;
    }
}

void Date::add_month(int inc) {
    add_year((inc + month - 1) / 12);
    month = month + inc % 12;
    month = (month == 12 ? 12 : month % 12);
}

void Date::add_year(int inc) { year += inc; }

void Date::show_date() {
    std::cout << "Today is " << year << month << day << std::endl;
}

int main() {
    // Date day; // dat 인스턴스 생성
    // // 클래스 변수 초기화함수! 중요
    // // 이 과정 없이 메소드 호출하면 쓰레기 값이 나오겠지!
    // // 클래스 인스턴스 생성 -> 변수 초기화 단계 기억!
    // day.set_date(2011, 3, 1);

    Date day(2011, 3, 1);
    // 위와 같은 문제를 해결하기 위해 생성자 함수 사용
    // 정의한 인자에 맞게 함수 호출하며 객체를 생성하면
    // 정의한 값으로 초기화되며 객체 생성

    Date day2 = Date(2012, 3, 1);
    // 위와 같이 객체를 생성하고 생성자(함수)를 호출해서
    // 객체를 생성해도 같은 방식으로 적용됨!

    // 객체를 생성하는 방법 두가지 
    // Date day(2011, 3, 1); // 암시적 방법(implicit)
    // 마치 함수를 호출하듯이 사용하는 것
    // Date day = Date(2012, 3, 1); // 명시적 방법(explicit)
    // 명시적으로 생성자를 호출하는 것을 보여주는 것


    day.show_date();

    day.add_year(10);
    day.show_date();
    return 0;
}


int test() {
    // 처음에 단순히 set_date 함수를 이용해서 객체를 초기화 하였을 때
    // 생성자를 명시하지 않았다. 즉, 처음에 생성자 정의를 하지 않은 채
    Date day; // 로 했을 때, 생성자가 호출 되는가? YES!
    // default constructor 생성자가 호출된다.
    // 이는 인자를 하나도 가지지 않은 생성자인데, 클래스에서 사용자가 어떠한 생성자도
    // 명시적으로 정의하지 않을 경우 컴파일러가 자동으로 추가해주는 생성자
    // 사용자가 어떤 다른 생성자를 추가한 순간 컴파일러는 자동으로 다폴트 생성자를
    // 삽입하지 않는다
    // 물론 자동 생성시 쓰레기값이 나온다 - 그래서 디폴트 정의해야함

    Date day2(); // 이렇게 ()를 하면 디폴트 생성자 객체를 생성하는 게 아니라
    // 리턴값이 Date이고 인자가 없는 함수 day3을 정의하게 된 것으로 인식
    // 이는 암시적 표현으로 객체 선언시 염두해야함
}


int test2() {
    // 생성자 오버로딩을 통해 사용자가원하는 생성자를 호출할 수 있다.
    Date day = Date(); // default constructor
    Date day2(2012, 10, 31); // custom constructor
}