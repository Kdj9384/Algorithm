#define _CASE_1_
// #define _CASE_2_

/*
* CASE 1 : 문제에서 정의한 범위인 0 ~ 20 까지 '모든' w값을 삼중반복문을 통해 저장한 후, 꺼내어 계산 -> if(arr[a][b][c] != 0) 필요 없음
* CASE 2 : 재귀를 통해 값을 구하면서, 이전에 구했던 값을 저장해 놓고 사용. (필요한 값만 계산) -> if(arr[a][b][c] != 0) 필요
*/

#include <iostream>
#include <algorithm>

int arr[22][22][22];

int w(int a, int b, int c)
{
  if (a <= 0 || b <= 0 || c <= 0)
  {
    return 1;
  }

  else if (a > 20 || b > 20 || c > 20)
  {
    return arr[20][20][20];
  }

#ifdef _CASE_1_
  else if (a < b && b < c)
  {
    return arr[a][b][c - 1] + arr[a][b - 1][c - 1] - arr[a][b - 1][c];
  }

  else
  {
    return arr[a - 1][b][c] + arr[a - 1][b - 1][c] + arr[a - 1][b][c - 1] - arr[a - 1][b - 1][c - 1];
  }
#endif

#ifdef _CASE_2_
  else if (arr[a][b][c] != 0)
  {
    return arr[a][b][c];
  }

  else if (a < b && b < c)
  {
    return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  }

  else
  {
    return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  }
#endif
}

int main()
{
  int a, b, c;

#ifdef _CASE_1_
  for (int i = 0; i <= 20; i++)
  {
    for (int j = 0; j <= 20; j++)
    {
      for (int k = 0; k <= 20; k++)
      {
        arr[i][j][k] = w(i, j, k);
      }
    }
  }
#endif

  while (true)
  {
    std::cin >> a >> b >> c;

    if (a == -1 && b == -1 && c == -1)
    {
      break;
    }

    printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
  }
}