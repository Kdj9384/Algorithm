/**
 * @file baekjoon_if_1.cpp
 * @author Kang, Dongjin
 * @brief 
 *  
 * @version 0.1
 * @date 2021-07-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// 윤년이면 1, 아니면 0 출력
// 윤년은,
// 4의 배수이면서 100의 배수가 아닐때
// 400의 배수일때

#include <iostream>

using std::cin;
using std::cout;

int main()
{
  int h, m;

  cin >> h;
  cin >> m;

  m -= 45;

  if (m < 0)
  {
    m += 60;
    h--;

    if (h < 0)
    {
      h = 23;
    }

    cout << h << std::endl;
    cout << m;
  }
  else
  {
    cout << h << std::endl;
    cout << m;
  }
}