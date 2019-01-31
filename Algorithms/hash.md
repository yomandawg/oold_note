# Hash

CPU, memory 등 시스템 자원을 덜 소모하는 searching 방법

같은 입력값에 대해 같은 출력값 보장

출력값은 고른 범위에 균일하게 분포함



## Hash Function (Hashing)

임의의 길이를 갖는 임의의 데이터에 대해 고정된 길이의 데이터로 매핑하는 함수

* 해시 함수를 적용하여 나온 고정된 길이의 값을 **Hash value** 또는 **Hash code**라 함

1. 원본 데이터 값: **key**
2. 매핑 후 데이터 값: **hash value**
3. 매핑 과정: **hashing**



## Hash Table

1. Key를 hash값으로 매핑
2. hash값의 index 주소에 hash value와 key를 함께 저장
   * 데이터 저장되는 곳을bucket(slot)이라 함



## Hash Collision

* 같은생일 찾기 예: 365일에 50명만 넘어도 collision 확률 50% 이상

### Open Addressing

1. 한 버킷당 엔트리 하나
2. 다른 address에 저장 가능
   * 메모리 문제는 발생하지 않으나 해시 충돌이 여전히 생김



### Chaining

1. 해시 충돌 방지
2. 한 버킷당 들어갈 수 있는 엔트리에 제한이 없음
3. 충돌해도 계속 체인처럼 노드를 추가하여 다음 노드를 가리키는 연결리스트를 생성
   * 메모리 문제





