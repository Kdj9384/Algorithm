#include <iostream>
#include <vector>
#include <math.h>

int N;
int visited[21];
int arr[21][21];
int min = INT32_MAX;

void getAnswer(int depth, int idx)
{
  if (depth == N / 2)
  {
    int sel_sum = 0, opp_sum = 0;
    int diff = 0;

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (visited[i] == 1 && visited[j] == 1)
        {
          sel_sum += arr[i][j];
        }

        if (visited[i] == 0 && visited[j] == 0)
        {
          opp_sum += arr[i][j];
        }
      }
    }

    diff = abs(sel_sum - opp_sum);
    if (diff < min)
      min = diff;

    return;
  }

  for (int i = idx; i < N; i++)
  {
    if (visited[i] != 1)
    {
      visited[i] = 1;
      getAnswer(depth + 1, i + 1);

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

  getAnswer(0, 0);
  std::cout << min;
}