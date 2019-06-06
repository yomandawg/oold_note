/*
메모리 관리는 매우 중요
프로그램이 정확하게 실행되기 위해서는 컴파일 시에 모든 변수의 주소값이 확정되어야 함
이를 위해 프로그램에 많은 제약이 따르게 때문에
프로그램 실행 시에 자유롭게 할당하고 해제할 수 있는 힙(heap) 공간이 있음

이전에 컴파일러에 의해 완벽히 확정되어 안정성이 보장되는 스택(stack)과는 다르게
힙은 사용자가 스스로 제어해야 하는 부분인 만큼 책임이 따름

C언어에서 malloc과 free를 통해 힙 상에서 메모리 할당을 지원했음
C++에서도 이를 사용할 수 있지만 new와 delete를 사용
*/

#include <iostream>

int main() {
    int *p = new int; // int 크기 공간을 할당하여 주소값을 p에 집어 넣었음
    *p = 10; // p 위치에 할당된 공간에 10을 집어넣는다

    std::cout << *p << std::endl;

    delete p; // 할당된 공간 해제 (지역 변수(힙이 아닌 것)를 무리하게 해제하면 당연히 오류)
    return 0;
}

int arr_new() {
    int arr_size; // 배열의 크기를 잡을 변수
    std::cout << "array size : ";
    std::cin >> arr_size;
    int *list = new int[arr_size]; // []이용해 배열의 크기만큼을 할당
    // list는 이제 arr_size인 int 배열을 갖게 됨
    // C와 다르게 아무대서나 변수를 선언할 수 있다(그 변수는 이를 포함하는 중괄호에서 빠져나갈때 소멸)
    // 컴파일러는 그 변수를 가장 가까운 범위(scope)부터 찾게 됨
    // 하지만 동일한 scope에서 두번 선언은 안돼
    for (int i = 0; i < arr_size; i++) { // 이 int i는 중괄호가 끝날 때 소멸(scope)
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
        std:: cout << i << "the element of list: " << list[i] << std::endl;
    }
    delete[] list; // delete []를 통해 해제하면 됨
    // new - delete가 짝을 이루고 new [] 와 delete []가 짝을 이룸
    return 0;
}