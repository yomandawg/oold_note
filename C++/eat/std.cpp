#include <iostream>
#include <string>


class Employee {
    std::string name;
    int age;
    std::string position;
    int rank;

    public:
        Employee(std::string name, int age, std::string position, int rank) : name(name), age(age), position(position), rank(rank) {}

        Employee(const Employee& employee) {
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }

        Employee() {}

        void print_info() {
            std::cout << name << position << age << calculate_pay() << std::endl;
        }
        int calculate_pay() { return 200 + rank * 50; }
};


int main() {
    std::string s = "abc";
    std::cout << s << std::endl;

    return 0;

    // "abc"는 컴파일러 상에서 C형식 문자열로 인식된다.
    // 즉 string클래스의 인자를 const char *로 받는 생성자를 호출한 것으로 볼 수 있다.

    std::string t = "def";
    std::string s2 = s;
    
    std::cout << s << s.length() << std::endl;
    std::cout << s << t << s + t << std::endl;
    
    if (s == s2) std::cout << s << s2 << std::endl;
    if (s != t) std::cout << s << t << std::endl;

    return 0;
}