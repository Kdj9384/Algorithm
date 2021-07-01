#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
  // 시간
  int answer = 0;
  int remain_truck_idx = 0;
  queue<int> que;

  do
  {
    // 종료 조건
    if (remain_truck_idx == truck_weights.size())
    {
      answer += bridge_length;
      break;
    }
    // 다리 길이 체크
    if (que.size() >= bridge_length)
    {
      weight += que.front();
      que.pop();
    }

    // 무게 체크
    if (truck_weights[remain_truck_idx] > weight)
    {
      que.push(0);
    }

    // 올라갈 수 있다면 올라가기
    if (truck_weights[remain_truck_idx] <= weight && que.size() < bridge_length)
    {
      que.push(truck_weights[remain_truck_idx]);
      weight -= truck_weights[remain_truck_idx];

      remain_truck_idx++;
    }

    answer++;
  } while (true);

  return answer;
}

int main()
{
  int bridge_length = 2;
  int weight = 10;
  vector<int> truck_weights = {7, 4, 5, 6};

  int a = solution(bridge_length, weight, truck_weights);
  cout << a;
}