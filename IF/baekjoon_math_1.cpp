#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int N, M;
  int sum = 0, max = -1;

  vector<int> arr;

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    int tmp;
    cin >> tmp;

    if (tmp < M)
    {
      arr.push_back(tmp);
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      for (int k = j + 1; k < N; k++)
      {
        sum = arr[i] + arr[j] + arr[k];

        if (sum > max && sum <= M)
        {
          max = sum;
        }
      }
    }
  }

  cout << max;
}