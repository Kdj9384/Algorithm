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

> 해시를 사용하여 해결해보자.

##### 라빈-카프 알고리즘

- 해시를 사용해 문자열을 비교, 매칭 하는 알고리즘
- 자신 문자열(패턴) 과 대상 문자열의 해시값을 구한 뒤, 비교해보고, 같으면, 원래의 문자열을 직접 비교해 보는 방법.
- 문자열 전체에 대해 특정 패턴을 비교해 볼때 유용하다.

그러나, 우리의 문제는 접두어의 경우만 비교하고 있으므로 딱히 `라빈 핑거프린트` 알고리즘을 사용할 필요가 없다.

> 1. 각 문자열으리 char의 아스키 값을 적절히 조합한, hash_func을 직접 만들어보기.
> 2. 증명되어있는 rabin's fingerprint hash_func을 사용하기

1. 문자열의 길이를 오름차순으로 정렬한다.
2. 문자열 str에 대해, 문자열의 길이를 size, 해시 값을 hash_v 라고 할 때, str 보다 큰 문자열의, size 만큼 잘라낸 후, 해시 값을 구한다.
3. 큰 문자열의 앞에서 size만큼의 문자열의 해시값 중에 hash_v 와 일치하는 해시 값이 있는지 확인.
4. 모든 입력된 문자열에 대해 적용.

##### unordered_set, unordered_map 의 hash_function

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

##### 시간 초과
