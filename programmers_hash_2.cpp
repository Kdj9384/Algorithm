#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 문자열 길이 순으로 정렬
// 문자열 선택
// 해당 문자열의 길이와 해시 값 구하기
//

int hash_func(string str, int size_v)
{
  int hash = 0;

  if (str.size() != size_v)
  {
    // str에서 앞에서 부터 size_v 만큼 자르기
    string substring = str.substr(size_v);

    // substring 사용

  } else {
    // str 사용
  }

  // 해시값 리턴하기
  return hash;
}

bool solution(vector<string> phone_book)
{
  bool answer = true;

  // 1. 입력된 문자열을 오름차순으로 정렬.
  sort(phone_book.begin(), phone_book.end());

  // 2. 어느 문자열의 size_v 와 hash_v 구하기.
  string temp = phone_book[0];
  int size_v = temp.size();
  int hash_v = hash_func(temp, size_v);

  for (int i = 0; i < phone_book.size() - 1; i++)
  {
    int size_v = phone_book[i].size();
    int hash_v = hash_func(phone_book[i], size_v);

    for (int j = i + 1; j < phone_book.size(); j++)
    {
      // size_v 만큼 앞에서 잘라서 해시 값을 구함.
      int hash_v_tmp = hash_func(phone_book[j], size_v);

      if (hash_v == hash_v_tmp)
      {
        answer = false;
        return answer;
      }
    }
  }

  return answer;
}

int main(void)
{
  vector<string> tmp = {"119", "97674223", "1195524421"};
  cout << solution(tmp);
}