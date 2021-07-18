#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int Answer;
// 실패
// char a[50001];
// char b[50001];

// 만점..?
char a[100001];
char b[100001];

int main(int argc, char **argv)
{
  int T, test_case;

  freopen("sample_input.txt", "r", stdin);

  cin >> T;

  for (test_case = 0; test_case < T; test_case++)
  {
    Answer = 0;
    ////////////////////////////////////////////////////////////////////////
    int n, t;
    string b_raw;

    cin >> n;
    cin >> t;
    cin >> b_raw;

    // int a[n+1];
    // int b[n + 1];

    for (int i = 0; i < n; i++)
    {
      b[i + 1] = b_raw.at(i);
      a[i + 1] = '2';
    }

    // b[i] == 0
    for (int i = 1; i <= n; i++)
    {
      if (b[i] == '1')
      {
        continue;
      }

      if (i < t + 1)
      {
        // i+t 만 확인
        a[i + t] = '0';
      }
      else if (t + 1 <= i && i <= n - t)
      {
        // i-t, i+t 둘다 확인
        a[i - t] = '0';
        a[i + t] = '0';
      }
      else
      {
        // i-t만 확인
        a[i - t] = '0';
      }
    }

    // b[i] == 1
    for (int i = 1; i <= n; i++)
    {
      if (b[i] == '0')
      {
        continue;
      }

      if (i < t + 1)
      {
        // i+t 만 확인
        a[i + t] = '1';
      }
      else if (t + 1 <= i && i <= n - t)
      {
        // i-t, i+t 둘다 확인
        if (a[i - t] == '0')
        {
          a[i + t] = '1';
        }

        if (a[i + t] == '0')
        {
          a[i - t] = '1';
        }
      }
      else
      {
        // i-t만 확인
        a[i - t] = '1';
      }
    }

    // 최소조건
    for (int i = 1; i <= n; i++)
    {
      if (a[i] == '2')
      {
        a[i] = '0';
        if (i + (2 * t) <= n)
        {
          a[i + (2 * t)] = '1';
        }
      }
    }

    ////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    // cout << Answer << endl;

    for (int i = 1; i <= n; i++)
    {
      cout << a[i];
    }
    cout << endl;
  }

  return 0; //Your program should return 0 on normal termination.
}
