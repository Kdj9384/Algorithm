#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct
{
  int time;
  long long currDelay;
  long long expDelay;
} WaitNode;

struct cmp
{
  bool operator()(WaitNode a, WaitNode b)
  {
    return a.expDelay > b.expDelay;
  }
};

long long solution(int n, vector<int> times)
{
  long long answer = 0;
  priority_queue<WaitNode, vector<WaitNode>, cmp> waitq;

  for (auto i : times)
  {
    WaitNode tmp;
    tmp.time = i;
    tmp.currDelay = 0;
    tmp.expDelay = i;

    waitq.push(tmp);
  }

  while (n > 0)
  {
    // 기대 대기시간이 가장 작은 심사관을 pop
    WaitNode a = waitq.top();
    waitq.pop();

    // 현재 대기시간, 기대 대기시간 추가.
    a.currDelay += a.time;
    a.expDelay += a.time;

    waitq.push(a);
    n--;
  }

  vector<long long> get_curr;
  vector<long long>::iterator iter;

  while (!waitq.empty())
  {
    WaitNode a = waitq.top();
    waitq.pop();

    get_curr.push_back(a.currDelay);
  }

  iter = max_element(get_curr.begin(), get_curr.end());
  answer = *iter;

  return answer;
}

int main()
{
  int n = 6;
  vector<int> times = {7, 10};

  int a = solution(n, times);
  cout << a;
}