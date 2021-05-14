#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

// 문자열 길이 순으로 정렬
// 문자열 선택
// 해당 문자열의 길이와 해시 값 구하기
//

bool solution(vector<string> phone_book)
{
  unordered_set<string> hash_set;

  bool answer = true;
  int phone_num[phone_book.size()];

  for (auto i = 0; i < phone_book.size(); i++)
  {
    hash_set.insert(phone_book[i]);
    phone_num[i] = hash_set.find(phone_book[i]).operator->()
  }

  return answer;
}

int main(void)
{
  cout << solution({"119", "97674223", "1195524421"});
}