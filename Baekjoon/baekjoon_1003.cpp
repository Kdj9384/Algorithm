/**
 * @file baekjoon_1003.cpp
 * @brief 
 * 피보나치 수열을 DP로 구현하는 문제. + 피보나치 값 대신 문제에서 제시된 0과 1의 출력을 저장해나가면 된다.
 * 
 */

#include <iostream>
#include <string.h>
#include <string>
#include <vector>

typedef struct Fibo
{
  int fibo_value;
  int zero;
  int one;
} Fibo;

using std::cin;
using std::cout;

Fibo visited[50];

void fibo(int n)
{
  for (int i = 0; i <= n; i++)
  {
    if (i == 0) // fibo(0)
    {
      visited[i].fibo_value = 0;
      visited[i].one = 0;
      visited[i].zero = 1;
    }
    else if (i == 1)
    {
      visited[i].fibo_value = 1;
      visited[i].one = 1;
      visited[i].zero = 0;
    }
    else
    {
      visited[i].fibo_value = visited[i - 1].fibo_value + visited[i - 2].fibo_value;
      visited[i].one = visited[i - 1].one + visited[i - 2].one;
      visited[i].zero = visited[i - 1].zero + visited[i - 2].zero;
    }
  }
}

int main()
{
  int T, N;
  cin >> T;

  while (T--)
  {
    cin >> N;
    fibo(N);
    printf("%d %d\n", visited[N].zero, visited[N].one);

    memset(visited, 0, sizeof(Fibo) * 50);
  }
}