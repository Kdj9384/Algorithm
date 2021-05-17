# 프로그래머스\_해시\_전화번호\_목록

Level 2

#### 문제 설명

> 전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
> 전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.
>
> 구조대 : 119
> 박준영 : 97 674 223
> 지영석 : 11 9552 4421
> 전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

#### 제한 사항

> 1. phone_book의 길이는 1 이상 1,000,000 이하입니다.
> 2. 각 전화번호의 길이는 1 이상 20 이하입니다.
> 3. 같은 전화번호가 중복해서 들어있지 않습니다.

#### 입출력 예제

| phone_book                        | return |
| --------------------------------- | :----: |
| ["119", "97674223", "1195524421"] | false  |
| ["123","456","789"]               |  true  |
| ["12","123","1235","567","88"]    | false  |

> 즉, phone_book내의 어느 한 번호가, 다른 어느 번호의 앞에 포함되어있으면 false.

#### 문제 풀이

##### 1. 라빈-카프 알고리즘

- 해시를 사용해 문자열을 비교, 매칭 하는 알고리즘
- 자신 문자열(패턴) 과 대상 문자열의 해시값을 구한 뒤, 비교해보고, 같으면, 원래의 문자열을 직접 비교해 보는 방법.
- 문자열 전체에 대해 특정 패턴을 비교해 볼때 유용하다.

그러나, 우리의 문제는 접두어의 경우만 비교하고 있으므로 딱히 `라빈 핑거프린트` 알고리즘을 사용할 필요가 없다.

##### 2. unordered_set, unordered_map 의 hash_function

```C++
// unordered_set::hash_function
#include <iostream>
#include <string>
#include <unordered_set>

typedef std::unordered_set<std::string> stringset;

int main ()
{
  stringset myset;

  stringset::hasher fn = myset.hash_function();

  std::cout << "that: " << fn ("that") << std::endl;
  std::cout << "than: " << fn ("than") << std::endl;

  return 0;
}
```

##### 3. 풀이 Case 1

1. 입력받은 벡터를 사전식으로 정렬한다.
2. 기준이 되는 i번째 string 의 크기로 이후의 문자열들을 모두 자른다.
3. 사전식으로 정렬했기 때문에, i 이후의 문자열은 모두 i 보다 같거나 크다.
4. i 와 i+1 번째 string을 비교해보았을 때, i+1번째 string이 i 보다 크다면, i+2, i+3, ... 이후로 i와 같은 문자열이 나올 수 없다. (사전식으로 정렬하였으므로)
5. 사전식 정렬을 적극 활용하여, 반복문을 한번만 사용하는 것이 핵심.

> 사전식 정렬 문제였던 것 같음. 문제를 풀기는 쉬우나, 효율성을 만족시키기 어려웠다.

```c++
bool solution(vector<string> phone_book)
{
  bool answer = true;
  int phone_book_len = phone_book.size();
  unordered_set<string> hash_set;

  sort(phone_book.begin(), phone_book.end());

  for (int i = 0; i < phone_book_len - 1; i++)
  {
    int size_v = phone_book[i].size();

    string target = phone_book[i + 1].substr(0, size_v);

    if (phone_book[i] == target)
    {
      answer = false;
      return answer;
    }
  }
  return answer;
}
```

##### 오답) 풀이 Case 2 [시간 초과]

> 해시를 이용해 해결해본 문제

1. i번째 string의 size를 기준으로, 이후의 string을 모두 자른뒤, `unordered_set`에 넣어 준다.
2. i번째 string을 key로 하여, 일치하는 해시 값이 있는지 확인해본다.
3. 단, 문제에서 일치하는 문자열은 없다고 제시하였기에 길이가 같은 문자열의 경우 무시한다.

```c++
bool compare(string begin, string end)
{
  return begin.size() < end.size();
}


bool solution(vector<string> phone_book)
{
  bool answer = true;
  int phone_book_len = phone_book.size();
  unordered_set<string> hash_set;

  // 문자열의 길이로 정렬
  sort(phone_book.begin(), phone_book.end(), compare);

  for (int i = 0; i < phone_book_len - 1; i++)
  {
    int size_v = phone_book[i].size();
    string target = phone_book[i + 1].substr(0, size_v);

    for (int j = i + 1; j < phone_book_len; j++)
    {
      if (size_v != phone_book[j].size())
        hash_set.insert(phone_book[j].substr(0, size_v));
    }

    if (hash_set.count(phone_book[i]))
    {
      answer = false;
      return answer;
    }
  }

  return answer;
}
```
