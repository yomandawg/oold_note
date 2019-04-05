# Python 유용한 라이브러리 소개

어떤 분께 요청을 받아서.. 파이썬으로 소프트웨어 검정 시험에 응시할 때

유용한 라이브러리를 소개하려고 합니다!

**경고 : 각 라이브러리마다 사용 예제를 첨부했는데 이게 약간 스포일러가 될 수 있습니다!**

## 1) Deque

```python
from collections import deque
```

기본적으로 파이썬의 리스트는 큐(queue) 자료구조로 사용하기에 적합하지 않습니다.

리스트 원소가 많아질수록 리스트의 가장 왼쪽 원소를 pop하기 위한 시간이 많이 들기 때문인데요,

이럴 때 deque 라이브러리를 사용하면 **매우 좋은 성능의 큐 자료구조**를 이용할 수 있습니다.

1. [사용방법 링크](<https://docs.python.org/3/library/collections.html#collections.deque>)

2. 예제 (SWEA Course 6 연산 문제)

   ```python
   from collections import deque
   
   def bfs(N, M):
       q = deque()
       q.append((N, 1))
       visited[N] = 1
   
       while len(q):
           num, cnt = q.popleft()
   
           diff = num - M
           if not diff:
               return cnt - 1
           else:
               for next_num in [num-1, num+1, num*2, num-10]:
                   if 0 <= next_num <= MAX_NUM and not visited[next_num]:
                       visited[next_num] = 1
                       q.append((next_num, cnt+1))
   
   MAX_NUM = 1000000
   T = int(input())
   for tc in range(1, T + 1):
       visited = [0 for _ in range(1000001)]
       N, M = map(int, input().split())
       print(f"#{tc} {bfs(N, M)}")
   ```



## 2) Heapq

```python
import heapq
```

우선순위큐는 다익스트라 알고리즘이나, Kruskal 알고리즘, 그리고 효율적으로(logn 시간복잡도) 최소, 최댓값을 구하기 위해서 필요한 자료구조입니다.

보통 우선순위큐를 구현하기 위해서 이진힙(binary heap)을 많이들 사용하는데요,

이것을 구현하는데도 상당한 시간이 들기 때문에 heapq 라이브러리를 통해서 효율적으로 사용할 수 있습니다.

heapq 라이브러리는 파이썬의 list 자료구조를 우선순위큐처럼 쓸 수 있게 해주는 좋은 라이브러리입니다.

1. [사용방법 링크](<https://docs.python.org/3.7/library/heapq.html>)

2. 예시 (SWEA Course 7 최소비용문제)

   ```python
   import heapq
   MAX_NUM = 11111
   move_x = [-1, 1, 0, 0]
   move_y = [0, 0, -1, 1]
   
   T = int(input())
   for tc in range(1, T+1):
       N = int(input())
       heights = [list(map(int, input().split())) for _ in range(N)]
       min_cost = [[MAX_NUM for _ in range(N)] for _ in range(N)]
       min_cost[0][0] = 0
   
       def bfs():
           # w, y, x
           q = [(0, 0, 0)]
   
           while len(q):
               w, y, x = heapq.heappop(q)
               ch = heights[y][x]
   
               for i in range(4):
                   new_y = y + move_y[i]
                   new_x = x + move_x[i]
                   if 0 <= new_y < N and 0 <= new_x < N:
                       nh = heights[new_y][new_x]
                       cost = w + 1
                       if nh > ch:
                           cost += nh - ch
   
                       if cost < min_cost[new_y][new_x]:
                           min_cost[new_y][new_x] = cost
                           heapq.heappush(q, (cost, new_y, new_x))
   
       bfs()
   
       print(f"#{tc} {min_cost[N-1][N-1]}")
   ```

   w, y, x 순서대로 놓은 이유는 heapq 라이브러리가 정렬 우선순위를 앞에 있는 원소로 설정하기 때문입니다.



## 3) Random

다들 아시는 라이브러리이지만 생각보다 랜덤 라이브러리가 중요한 역할을 합니다.

이 라이브러리를 통해 다량의 인풋을 간단하게 만들 수 있는데요, 

내가 구현한 코드가 정확히 맞는지는 알 수 없지만, 적어도 시간초과가 발생하는지는 판단할 수 있습니다.

1. 예시 ( 월말평가 - 로봇 과자 먹기 문제)

   ```python
   import sys
   import random
   
   sys.stdout = open('robot_test.txt',"w")
   
   T = N = 10
   print(T)
   for tc in range(1, 11):
       print(N)
       snacks = [random.randint(0, 100) for _ in range(2*N)]
       robots = [random.randint(0, 100) for _ in range(2*N)]
       print(*snacks)
       print(*robots)
   ```

   

