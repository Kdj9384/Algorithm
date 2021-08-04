#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // cin.eof() EOF

  int C, N, tmp;
  cin >> C;

  // 테스트 케이스
  for (int i = 0; i < C; i++)
  {
    int sum = 0, cnt = 0;
    float mean;
    cin >> N;

    vector<int> vec;

    // 입력
    for (int j = 0; j < N; j++)
    {
      cin >> tmp;
      vec.push_back(tmp);
      sum += tmp;
    }

    // 평균구하기
    mean = sum / N;

    // 평균 넘는 학생 수 구하기
    for (auto i : vec)
    {
      if (i > mean)
      {
        cnt++;
      }
    }

    // 확률 출력
    printf("%.3f%%\n", static_cast<float>(cnt) / N * 100);
  }
}