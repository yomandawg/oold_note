/* mutable
이전에 배운 const 멤버 함수 내부에서는 멤버 변수들의 값을 바꾸는 것이 불가능함
하지만, 만약에 멤버 변수를 mutable로 선언한다면 const 함수에서도 이들 값을 바꿀 수 있다.
 */

#include <iostream>

class A {
    mutable int data_;

    public:
        A(int data) : data_(data) {}
        void DoSomething(int x) const { data_ = x; } // 불가능! => mutable이면 가능!
        // const 함수 안에서 멤버 변수에 값을 대입하면 오류
        // 왜 굳이 mutable 키워드를 만들었을까?
        // 먼저 멤버 변수를 왜 const로 선언하는지 생각해보면, 클래스의 멤버 함수들은
        // 이 객체는 이러이러한 일을 할 수 있다. 라는 의미를 나타내고 있다.
        // 그리고 멤버 함수를 const로 선언하는 의미는 이 함수는 객체의 내부 상태에 영향을 주지 않습니다.
        // 라는 것을 표현하는 방법. 대표적인 예로 읽기 작업을 수행하는 함수들.

        // 대부분의 경우 의미상 상수 작업을 하는 경우, 실제로도 상수 작업을 하게 된다.
        // 하지만, 실제로 꼭 그렇지만은 않다!

        void PrintData() const { std::cout << "data:" << data_ << std::endl; }
};


// 예를 들어 아래와 같은 서버프로그램을 만든다면..
class Server {
    // ... 생략 ...

    mutable Cache cahce; // 캐쉬
    // 이렇게 mutbale 키워드는 const 함수 안에서 해당 멤버 변수에 
    // const가 아닌 작업을 할 수 있게 한다.

    // 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다.
    User GetUserInfo(const int user_id) const {
        // 1. 캐쉬에서 user_id 를 검색
        Data user_data = cache.find(user_id);

        // 2. 하지만 캐쉬에 데이터가 없다면 데이터베이스에 요청)
        if (!user_data) {
            user_data = Database.find(user_id);

            // 그 후 캐쉬에 user_data 등록
            cache.update(user_id, user_data); // 불가능!
            // 문제는 GetUserInfo가 const함수라는 점!!
            // 따라서 이를 업데이트 하는 작업을 수행할 수 없다
            // 캐쉬를 업데이트 한다는 것은 캐쉬 내부의 정보를 바꾸는 것이므로.
            // 따라서 update함수는 const 함수가 아니다
            
            // 그런데 GetUserInfo에서 const를 떼기도 뭐한게, 이 함수를 사용하는
            // 사용자의 입장에선 당연히 const로 정의되어야 하는 함수이기 때문
            // 따라서 Cache를 mutable로 선언한다!
        }
        // // 1. 데이터베이스에 user_id를 검색
        // Data user_data = Database.find(user_id);

        // 2. 리턴된 정보로 User 객체 생성
        return User(user_data);
    }
};
// 이 서버에는 GetUserInfo 라는 함수가 있는데 입력받은 user_id로 데이터베이스에서
// 해당 유저를 조히해서 그 유저의 정보를 리턴하는 함수
// 당연히 데이터베이스를 업데이트 하지도않고, 무언가를 수정하는 작업도 없기 때문에 const 함수로 선언
// 그런데 대개 데이터베이스에 요청한 후 받아오는 작업은 꽤나 오래 걸린다.
// 그래서 보통 서버의 경우 메모리에 캐쉬(cache)를 만들어서 자주 요청되는 데이터를
// 굳이 데이터베이스까지 가서 찾지 않아도 메모리에서 빠르게 조회할 수 있도록 합니다.

// 물론 캐쉬는 데이터베이스만큼 크지 않기 때문에 일부 유저들 정보 밖에 포함하지 않습니다.
// 따라서 캐쉬에 해당 유저가 없다면 (이를 캐쉬 미스-cache miss),
// 데이터베이스에 직접 요청해야지요. 대신 데이터베이스에서 유저 정보를 받으면
// 캐쉬에 저장해놓아서 다음에 요청할 때는 빠르게 받을 수 있게 됩니다.
// (보통 한 번 요청된 정보는 계속해서 요청될 확률이 높기 때문에 캐쉬에 넣는다
// 물론 캐쉬 크기는 한정적이니깐 이전에 오래된 캐쉬부터 지운다.)


int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}