#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <math.h>
using namespace std;

int main()
{
  // 입, 출력 시간 단축
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //

  int N, M, tmp;
  int answer = 0;
  vector<int> vec;
  vector<int> mode;

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> M;
    vec.push_back(M);
    answer += M;
  }

  sort(vec.begin(), vec.end());

  // 산술 평균 소숫점 첫재짜리 반올리
  cout << floor(static_cast<double>(answer) / N) << "\n";

  // 중앙값
  cout << vec[N / 2 + 1] << "\n";

  // 최빈값 여러개일 경우, 두번째로 작은 값
  for (auto i : vec)
  {
  }

  // 범위
  cout << vec.back() - vec.front() << "\n";
}