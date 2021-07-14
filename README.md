# push_swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

스택 a에 중복 없는 랜덤 정수를 인자로 넣어준 상태에서, 스택 a와 b를 이용하여 인자로 들어온 숫자들을 오름차순으로 스택 a에 정렬하는 과제

<가능한 기능>
sa : 스택 a의 맨 위 두 요소를 스왑한다.
sb : 스택 b의 맨 위 두 요소를 스왑한다.
ss : sa와 sb를 동시에 실행한다.
pa : 스택 b의 가장 위의 요소를 a의 가장 위에 넣어준다.
pb : 스택 a의 가장 위의 요소를 b의 가장 위에 넣어준다.
ra : 스택 a의 모든 요소를 위로 한칸씩 올린다. 첫번째 요소는 맨 마지막 요소가 된다.
rb : 스택 b "
rr : ra와 rb를 동시에 실행한다.
rra : 스택 b의 모든 요소를 위로 한칸씩 내린다. 마지막 요소는 맨 처음 요소가 된다.
rrb : 스택 a "
rrr : rra와 rrb를 동시에 실행한다.

<점수>
요소 3개 기준 -> 3회 이하
요소 5개 기준 -> 12회 이하
요소 100개 기준 -> 700회보다 작게 (5점), 900회보다 작게 (4점), ...
요소 500개 기준 -> 5500회보다 작게 (5점), 7000회보다 작게 (4점), ...

### commit-name : edit errors & simple and similar bubble_sort
1) 제일 큰 수와 제일 작은 수를 제외하고, B스택 수가 A스택 수보다 많아지거나 A스택을 한바퀴 돌 때까지 A스택의 값을 B 스택으로 넘긴다.
 - 2,3,4번은 A와 B 같은 동작
2) 피봇을 하나 정하고, 그 피봇을 자기보다 바로 다음 큰 수 위까지 옮긴다.
3) 반복
4) 각 스택이 정렬 완료 되면, B스택의 숫자를 A스택에 적절히 끼워넣는다.

100개 기준 -> 대략 48000회

: 한 기준점이 큰 수 위에 붙고 또 큰 수가 기준점이되어 자기보다 큰 수 위에 붙는 식이기 때문에, 한쪽에 쌓이는 것이 아니라, 계속해서 꼬리잡기하다가 겨우겨우 정렬되는 것.
-> 한 기준을 중심으로 모이면 횟수가 더 줄지 않을까 싶다.

### commit-name : Improved similar Bubble Sorts
1) 위와 동일 ( devide_num 함수)
2) 'simple and similar bubble_sort' 에서는 start_pivot이 dest_pivot에 붙는 형태였다면, 이번 알고리즘은 dest_pivot을 정하고 start_pivot을 찾아와서 붙여주는 형식으로 동작한다.
3) start_pivot을 정한 뒤, 그보다 한단계 큰 수를 dest_pivot으로 정한다.(처음 1회만)
4) --while--
5) start_pivot을 찾아 간 뒤, dest_pivot 위에 옮긴다.
6) dest_pivot을 start_pivot으로 재지정 해주고, 재지정한 dest_pivot보다 하나 작은 수를 찾아서 start_pivot으로 재지정 해준다.
7) 반복
8) 각 스택이 정렬 완료 되면, B스택의 숫자를 A스택에 적절히 끼워넣는다.

100개 기준 -> 2500회 - 3000회
500개 기준 -> 대략 64000회

이 코드 자체를 좀 더 최적화하면 더 빨라질 수는 있겠지만, 통과 기준에는 한참 못 미칠 것 같다.
다음에는 퀵정렬을 좀 섞어서 해볼 생각이다.
