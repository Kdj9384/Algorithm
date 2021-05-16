#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 문자열 길이 순으로 정렬
// 문자열 선택
// 해당 문자열의 길이와 해시 값 구하기
//

int hash_func(string str)
{
  int hash = 0;
  unordered_set<string> hash_set;

  unordered_set<string>::hasher fn = hash_set.hash_function();

  hash = fn(str);

  // 해시값 리턴하기
  return hash;
}

bool compare(string begin, string end)
{
  return begin.size() < end.size();
}

bool solution(vector<string> phone_book)
{
  bool answer = true;

  // 1. 입력된 문자열을 오름차순으로 정렬.
  sort(phone_book.begin(), phone_book.end());

  // 2. 어느 문자열의 size_v 와 hash_v 구하기.
  for (int i = 0; i < phone_book.size() - 1; i++)
  {
    int size_v = phone_book[i].size();
    int hash_v = hash_func(phone_book[i]);

    for (int j = 0; j < phone_book.size(); j++)
    {
      // 같은 문자열 비교하지 않는다.
      if (i == j)
      {
        continue;
      }

      string str = phone_book[j];
      int size_v_str = str.size();

      if (size_v_str > size_v)
      {
        str = str.substr(0, size_v);
      }
      else if (size_v_str < size_v)
      {
        continue;
      }
      else
      {
        // 두 문자열의 길이가 같은 경우.
      }

      if (phone_book[i] < str)
      {
        break;
      }

      // size_v 만큼 앞에서 잘라서 해시 값을 구함.
      int hash_v_tmp = hash_func(str);

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
  vector<string> tmp = {"97674223", "119", "1195524421"};
  cout << solution(tmp);
}