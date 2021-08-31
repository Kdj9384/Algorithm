#include <iostream>

using namespace std;

int main()
{
  // 입, 출력 시간 단축
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //

  int N;
  int start = 1666;
  int answer = 1;
  string target;
  cin >> N;

  if (N == 1)
  {
    cout << "666" << endl;
    return 0;
  }

  while (answer != N)
  {
    // s를 string으로 변환
    string s = to_string(start);

    // "666" 을 포함하는지 확인
    if (s.find("666") != string::npos)
    {
      // 포함하면 answer++ &
      answer++;
      if (answer == N)
      // N과 일치하면 target에 저장
      {
        target = s;
        break;
      }
    }
    start++;
  }

  cout << target;
}