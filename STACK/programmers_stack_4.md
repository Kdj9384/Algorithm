# programmers_stack_4

> #### 문제 설명

초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

> #### 제한 사항

- prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
- prices의 길이는 2 이상 100,000 이하입니다.

> #### 예시

| prices          | return          |
| --------------- | --------------- |
| [1, 2, 3, 2, 3] | [4, 3, 1, 1, 0] |

- 1초 시점의 ₩1은 끝까지 가격이 떨어지지 않았습니다.
- 2초 시점의 ₩2은 끝까지 가격이 떨어지지 않았습니다.
- 3초 시점의 ₩3은 1초뒤에 가격이 떨어집니다. 따라서 1초간 가격이 떨어지지 않은 것으로 봅니다.
- 4초 시점의 ₩2은 1초간 가격이 떨어지지 않았습니다.
- 5초 시점의 ₩3은 0초간 가격이 떨어지지 않았습니다.

> #### 풀이

- 각각의 가격에서 이후에 가격이 감소하는 부분이 있는지 확인하는 문제로 이중반복문을 통해 모든 경우를 조사하여 해결하였다.

- 스택을 이용하여 해결할 수 도 있다.
  --> 스택에 넣고, 남은 값들을 스택에 넣은 값과 비교
  --> 스택에 넣은 값보다 작은 값이 있다면, 인덱스를 이용하여 시간계산후 answer에 저장
  --> 작은 값이 없다면, 다음 값을 스택에 저장하고 위의 동작을 반복.
  --> 모든 주식을 스택에 넣고, 스택에 남아있는 주식(값)은 끝까지 가격이 떨어지지 않으므로, 각각에 대해 size - index - 1를 저장해 준다.