/* 노드
변수 나열을 막기 위해 배열
배열 기능 한계를 위해 구조체
구조체 나열을 막기 위해 구조체 배열

기존 구조체 말고 한개의 입력을 더 받고 싶다면?
=> 새롭게 동적할당을 하면 되지만 1000개의 데이터가 있는데 1개의 추가를 위해 1001를 새로 잡으면 비효율
=> 노드로 해결!

|데이터|다음 노드를 가리키는 포인터|

배열의 경우 원소 접근을 연산(index)로 할 수 있지만
노드의 경우 헤드부터 쭉 찾아가야한다.

즉, N개의 노드가 있다면 최악의 경우 O(N)동안 찾아야함
배열의 경우 O(1) 상수 시간 내 -> 배열이 월등히 빠르다

노드의 경우 데이터를 위한 공간 외에 노드를 가리키기 위한 4바이트가 더 필요하기 때문에
메모리(공간)적으로도 손해

노드의 경우 추가/삭제/삽입이 일어나는 경우 용이
*/


#include <stdio.h>
#include <stdlib.h>

struct Node* InsertNode(struct Node* current, int data);
void DestroyNode(struct Node *destroy, struct Node *head);
struct Node* CreateNode(int data);
void PrintNodeFrom(struct Node* from);

struct Node {
    int data; // 데이터
    struct Node* nextNode; // 다음 노드를 가리키는 부분
};
// |123|포인터| -> |456|포인터| -> ...

// 첫번째 노드가 다음 노드를 가리키면 다음 노드는 그 다음 노드 가리킨다 ...
// 마지막 노드는 아무것도 가리키지 않는다
// 기존의 배열에서 불가능한 작업임 배열 중간에 새 원소 집어넣기가 가능함.

int main() {
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);
    /* Node 2 뒤에 Node4 넣기 */
    struct Node* Node4 = InsertNode(Node2, 400);

    PrintNodeFrom(Node1);
    return 0;
}

// from이 NULL일 때까지, 즉 끝 부분에 도달할 때까지 출력
void PrintNodeFrom(struct Node* from) {
    while (from) {
        printf("노드의 데이터: %d \n", from->data);
        from = from->nextNode;
    }
}

// 새 노드를 만드는 함수
struct Node* CreateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = NULL;

    return newNode;
}

// 새로운 노드를 끼워 넣는 함수
struct Node* InsertNode(struct Node* current, int data) {
    // current 노드가 가리키고 있던 다음 노드가 after
    struct Node* after = current->nextNode;

    // 새로운 노드 생성
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // 새 노드에 값을 넣어준다.
    newNode->data = data;
    newNode->nextNode = after;

    // current는 이제 newNode를 가리키게 된다
    current->nextNode = newNode;

    return newNode;
}

// 노드 파괴 함수 - 파괴할 노드의 이전 노드가 필요한데 이를 찾으려면 처음 노드가 필요
void DestroyNode(struct Node *destroy, struct Node *head) { // 파괴할 노드, 처음 노드
    // 다음 노드를 가리킬 포인터
    struct Node *next = head;

    // head를 파괴하려 한다면
    if (destroy == head) {
        free(destroy);
        return;
    }

    // head 노드로부터 하나 씩 다음 노드와 비교하면서 찾아나간다.
    // 만일 next가 NULL이면 종료
    while (next) {
        // 만일 next 다음 노드가 destroy라면 next가 destroy 앞 노드
        if (next->nextNode == destroy) next->nextNode = destroy->nextNode;
        // next는 다음 노드를 가리킨다
        next = next->nextNode;
    }
    free(destroy);
}