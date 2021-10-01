
#include <iostream>
#include <algorithm>
#include <vector>
#define N 9

int arr[N][N];
int run = 0;
std::vector<std::pair<int, int>> blank;

bool validCheck(int blank_idx)
{
  auto a = blank[blank_idx]; // arr 에서 blank의 좌표

  // expect_value와 동일한 값이 있는지 체크
  for (int i = 0; i < N; i++)
  {
    if (arr[a.first][a.second] == arr[a.first][i] && i != a.second)
    {
      return false;
    }

    if (arr[a.first][a.second] == arr[i][a.second] && i != a.first)
    {
      return false;
    }
  }

  // 격자 체크
  int i_idx = (a.first / 3) * 3;
  int j_idx = (a.second / 3) * 3;

  for (int i = i_idx; i < i_idx + 3; i++)
  {
    for (int j = j_idx; j < j_idx + 3; j++)
    {
      if (arr[i][j] == arr[a.first][a.second] && i != a.first && j != a.second)
      {
        return false;
      }
    }
  }

  // 성공
  return true;
}

void dfs(int depth)
{

  if (depth == blank.size())
  {
    // 출력
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        std::cout << arr[i][j] << " ";
      }
      std::cout << "\n";
    }
    run = 1;
    return;
  }

  for (int i = 1; i <= 9; i++)
  {
    if (run)
    {
      return;
    }
    arr[blank[depth].first][blank[depth].second] = i;
    if (validCheck(depth))
    {
      dfs(depth + 1);
    }
  }

  // 1 ~ 9 모두 실패 -> 되돌아 가기
  arr[blank[depth].first][blank[depth].second] = 0;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int input;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      std::cin >> input;
      arr[i][j] = input;
      if (input == 0)
        blank.push_back(std::make_pair(i, j));
    }
  }

  // 백트래킹 수행
  dfs(0);
}