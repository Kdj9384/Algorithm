#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

bool cmp(int a, int b)
{
  return a > b;
}

int solution(vector<int> priorities, int location)
{
  int answer = 0;
  int pri_idx = 0;
  queue<int> que;

  /**
   * @brief 
   * 1. 순서대로 큐에 삽입
   * 2. priorities를 내림차순 정렬 
   * 3. 큐에서 pop하여, priorities의 i번째 인덱스와 같은지 확인 
   * 4. 다르면, 큐에 다시 삽입
   * 5. 같다면, i를 1 증가.
   * 6. 같다면, 
   * 
   */

  for (auto i : priorities)
  {
    que.push(i);
  }

  sort(priorities.begin(), priorities.end(), cmp);

  while (!que.empty())
  {
    int temp;
    temp = que.front();

    if (temp == priorities[pri_idx])
    {
      if (location == 0)
      {
        return answer + 1;
      }

      pri_idx++;
      que.pop();
      location--;
      answer++;
    }
    else
    {
      if (location == 0)
      {
        location = que.size();
      }
      que.pop();
      que.push(temp);
      location--;
    }
  }

  return answer;
}

int main()
{
  vector<int> priorities = {2, 1, 3, 2};

  // 원하는 문서의 인덱스
  int location = 2;

  int a = solution(priorities, location);
  cout << a;
}