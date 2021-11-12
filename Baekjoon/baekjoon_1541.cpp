#include <iostream>
#include <string>

int main()
{
  std::string str;
  int temp_pos = 0, end_pos, minus_pos;
  int sum = 0;
  std::cin >> str;

  minus_pos = str.find("-");
  // '-'가 없는 경우.
  if (minus_pos == std::string::npos)
  {
    minus_pos = 2100000000;
  }
  // '-'있는 경우.
  else
  {
    // '-' 뒤의 '-'를 모두 '+'로 바꿈.
    temp_pos = minus_pos;
    while (true)
    {
      temp_pos = str.find("-", temp_pos);
      if (temp_pos == std::string::npos)
        break;
      str[temp_pos] = '+';
    }
  }

  temp_pos = 0;
  while (true)
  {
    end_pos = str.find("+", temp_pos);
    if (end_pos == std::string::npos)
      break;

    if (end_pos <= minus_pos)
    {
      sum += std::stoi(str.substr(temp_pos, end_pos - temp_pos));
    }
    else
    {
      sum -= std::stoi(str.substr(temp_pos, end_pos - temp_pos));
    }
    temp_pos = end_pos + 1;
  }

  if (minus_pos == 2100000000)
    sum += std::stoi(str.substr(temp_pos, str.size() - temp_pos));
  else
    sum -= std::stoi(str.substr(temp_pos, str.size() - temp_pos));

  std::cout << sum;

  return 0;
}