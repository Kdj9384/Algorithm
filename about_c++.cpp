#include <iostream>
#include <string.h>

using std::cout, std::endl;

class Marine
{
  int hp;
  int coord_x, coord_y;
  int damage;
  bool is_dead;

public:
  Marine();
  Marine(int x, int y);
  int attack();
  void be_attacked(int damage_earn);
  void move(int x, int y);

  void show_status();
};

Marine::Marine()
{
}

Marine::Marine(int x, int y)
{
}

class String
{
private:
  char *p;
  int len;

public:
  // 생성자.
  String(const char x)
  {
    p = new char[1];
    strcpy(p, &x);

    len = strlen(p);
  }
  String(const char *x)
  {
    p = new char[(int)strlen(x)];
    strcpy(p, x);

    len = strlen(p);
  }

  // 복사 생성자
  String(const String &x)
  {
  }

  // 소멸자
  ~String()
  {
    delete[] p;
  }

  String find(String &b)
  {
  }

  //
  int get_size() const
  {
    return strlen(p);
  }

  char *get_string() const
  {
    return p;
  }

  int compare(String &b)
  {
    int small = strlen(p) < strlen(b.p) ? strlen(p) : strlen(b.p);
    // a가 크면 1, b가 크면 -1, 같으면 0;
    for (int i = 0; i < small; i++)
    {
      if (*(p + i) > *(b.p + i))
      {
        return 1;
      }
      else if (*(p + i) < *(b.p + i))
      {
        return -1;
      }
    }

    if (strlen(p) == strlen(b.p))
    {
      return 0;
    }
    else if (strlen(p) > strlen(b.p))
    {
      return -1;
    }
    else
    {
      return 1;
    }
  }

  String &str_cat(String &b)
  {
    char *tmp = new char[strlen(p)];
    strcpy(tmp, p);
    p = new char[strlen(p) + strlen(b.p)];
    strcpy(p, tmp);
    strcpy(p + strlen(p), b.p);
    return *this;
  }
};

int main()
{
  String string_a("hihi");
  String string_b("hihi");

  cout << string_a.compare(string_b) << endl;

  cout << string_a.get_size() << endl;

  string_a.str_cat(string_b);

  cout << string_a.get_string() << endl;
}