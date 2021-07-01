#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
  int answer = 0;
  priority_queue<int, vector<int>, greater<int>> p_que;

  // priority_queue에 삽입 (오름차순)
  for (auto i : scoville)
  {
    p_que.push(i);
  }

  while (true)
  {
    // 만들 수 없는 경우
    if (p_que.size() == 1 && p_que.top() < K)
    {
      answer = -1;
      break;
    }

    if (p_que.top() >= K)
    {
      break;
    }

    // 최소 2개 pop -> 최소 힙필요
    int min = p_que.top();
    p_que.pop();

    int min2 = p_que.top();
    p_que.pop();

    // 2개중 가장 작은 음식의 스코빌이 k보다 작다.
    if (min >= K)
    {
      continue;
    }

    // 새로운 음식 만들기
    int new_item = min + (min2 * 2);

    // 새로운 음식 push
    p_que.push(new_item);

    // 카운터 ++
    answer++;

    // 반복
  }

  return answer;
}

int main()
{
  vector<int> scoville = {1, 2, 3, 9, 10, 12};
  int K = 7;

  int a = solution(scoville, K);
  cout << a;
}