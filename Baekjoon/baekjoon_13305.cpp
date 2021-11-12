/*
* 앞에서부터 순서대로 주유소를 몇번 이용할 것인지 확인하면 됨. -> 전형적인 Greedy 문제.
*/

#include <iostream>
#include <vector>

int main()
{
  int N;
  long long result = 0, curr_length = 0;
  int start = 0;
  std::cin >> N;

  std::vector<int> length(N - 1);
  std::vector<int> price(N);

  for (int i = 0; i < N - 1; i++)
  {
    std::cin >> length[i];
  }
  for (int i = 0; i < N; i++)
  {
    std::cin >> price[i];
  }

  start = 0;
  curr_length = length[start];
  for (int j = start + 1; j < N - 1; j++)
  {
    if (price[start] <= price[j])
    {
      // 다음노드의 가격확인
      curr_length += length[j];
    }
    else
    {
      result += curr_length * price[start];
      curr_length = length[j];
      start = j;
    }
  }
  result += curr_length * price[start];
  std::cout << result;
  return 0;
}