#include <iostream>
#include <vector>

int N;
int visited[21];
int arr[21][21];
int min = INT32_MAX;

int getAnswer(int depth)
{
  if (depth == N / 2)
  {
    // 방문한 것들 모두 더하기
    // 상대편 스콕어 구하기

    // 차이 구하고 min과 비교하여 저장
  }

  for (int i = 0; i < N; i++)
  {
    if (visited[i] != 1)
    {
      visited[i] = 1;
      getAnswer(depth + 1);

      visited[i] = 0;
    }
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int tmp;

  std::cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      std::cin >> tmp;
      arr[i][j] = tmp;
    }
  }

  getAnswer(1);
}