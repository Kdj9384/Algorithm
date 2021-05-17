#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

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
  int phone_book_len = phone_book.size();
  unordered_set<string> hash_set;

  //Case 1
  sort(phone_book.begin(), phone_book.end());
  // end Case 1

  // Case 2
  // sort(phone_book.begin(), phone_book.end(), compare);
  // end Case 2

  // 2. 어느 문자열의 size_v 와 hash_v 구하기.
  for (int i = 0; i < phone_book_len - 1; i++)
  {
    int size_v = phone_book[i].size();

    string target = phone_book[i + 1].substr(0, size_v);

    // Case 1
    if (phone_book[i] == target)
    {
      answer = false;
      return answer;
    }
    // end Case 1

    // Case 2
    // for (int j = i + 1; j < phone_book_len; j++)
    // {
    //   if (size_v != phone_book[j].size())
    //     hash_set.insert(phone_book[j].substr(0, size_v));
    // }

    // if (hash_set.count(phone_book[i]))
    // {
    //   answer = false;
    //   return answer;
    // }
    // end Case 2
  }

  return answer;
}

int main(void)
{
  vector<string> tmp = {"97674223", "119", "1195524421"};
  cout << solution(tmp);
}