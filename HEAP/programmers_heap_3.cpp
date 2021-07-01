#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

vector<int> solution(vector<string> operations)
{
  vector<int> answer(2);
  deque<int> deq;

  for (auto i : operations)
  {
    // 파싱
    char command = i.front();

    // I 인지 D 인지 확인
    if (command == 'I')
    {
      string remain = i.substr(2);
      int a = stoi(remain);

      // I이면, deq에 추가 + 오름차순 정렬
      deq.push_back(a);
      sort(deq.begin(), deq.end());
    }
    else
    {
      string remain = i.substr(2);
      int a = stoi(remain);

      // 비어있는 경우, 무시
      if (deq.empty())
      {
        continue;
      }

      // D1이면, deq.front, D-1이면, deq.back을 pop 함.
      if (a > 0)
      {
        deq.pop_back();
      }
      else
      {
        deq.pop_front();
      }
    }
  }

  if (deq.empty())
  {
    // 비어있으면 -> [0,0];
    answer.at(0) = 0;
    answer.at(1) = 0;
  }
  else
  {
    // 비어있지 않으면 -> [front, back];
    answer.at(0) = deq.back();
    answer.at(1) = deq.front();
  }

  return answer;
}

int main()
{
  vector<string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
  vector<int> a = solution(operations);

  for (auto i : a)
  {
    cout << i << " ";
  }
}