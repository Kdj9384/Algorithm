# Algorithm with C++

## 씹어먹는 C++

참고 ::
https://modoocode.com/

## 1. `namespace` 의 이해

#### 정의

- 어떤 정의된 객체에 대해, 어디 소속인지 지정해 주는 것으로 같은 이름의 함수여도, 다른 namespace에 속한다면, 다른 함수로 인식한다.

- 중복된 함수, 변수를 처리하기 용이하다.

#### 사용

`namespace이름::객체이름` 형식으로 사용할 수 있으며, 해당 `namespace`가 포함된 파일을 `include` 해주어야 사용가능하다.

&emsp;&ensp; Ex) `std::cin >> input; ` , `std::cout << "hello";` ...

```c++
namespace name {
  // namespace 내부에서는 'name::' 없이 사용 가능
  int foo();
  void bar();
}

// name::foo 로 사용해야한다.
```

#### `::` 범위 확인 연산자

```
namespaceA::x // namespaceA 안의 x
::x // global(전역) 에서 x == 메인함수 밖의 x
```

#### 이름없는 namespace

```c++
namespace {
  int foo();
  void bar();
}
```

이름없는 namespace의 경우, 선언된 "파일" 내부에서만 사용가능하다.
만약, 다른 파일에 `include` 되어도, 사용할 수 없다.

#### 편의

- `using` 을 사용하면 `namespace::` 을 생략할 수 있다.

예를 들어, 파일 내에서 std namespace 내부의 cout만 사용할 것이라면,
다음과 같의 `std::`를 생략할 수 있다.

```c++
using std::cout;

cout << "hello";
```

더 나아가서, std namespace의 모든 객체를 사용하고자 할때는,
다음과 같은 방법을 사용한다.

```c++
using namespace std;

cout << "hello";
```

<b> 그러나, 위와 같이 `namespace` 전체를 `using` 하는 것은 충돌위험때문에 권장하지 않는다. </b>
프로그램을 만들때 나만의 namespace를 만들어 충돌없이 객체를 관리하는 것을 권장한다.

---

## 2. 참조자 (reference)

```c++
int a = 3;
int& a2 = a; // 참조자
// a2 와 a는 동치이다.
```

- a의 또다른 이름으로 a2가 있다는 것을 알려준다.

- 포인터와 참조자는 상당히 유사한 개념이지만 차이점도 명백히 존재한다.

#### 특징

1. 참조자는 정의할때 초기화도 같이 해주어야한다.
   `int& a; // 불가능`
2. 한번 정의가 되면, 변경이 불가능하다.
3. 참조자는 대부분의 경우 메모리 상에 존재하지 않는다.

```c++
int a = 1;
int& a2 = a;
int *p = &a2; // 불가능,,
```

4. 참조자의 참조자는 존재하지 않고, 원본을 참조하는 참조자가 2개 생긴다.
5. 리터럴도 참조 가능하나, 일반적인 방법으로는 불가능하다.

```c++
int& reff = 4; // 불가능
// reff = 1; 등을 사용하여 리터럴을 변경할 수 있기 때문..

const int& ref = 4; // 가능
int a = ref; // int a = 4; 와 동치이다.
```

6. 참조자의 배열은 불가능하나, 배열의 참조자는 가능.

```c++
int& arr[10]; // 불가능
// 참조자는 메모리 공간을 차지하지 않는 경우가 대부분이기 때문에

int arr[3] = {1, 2, 3}; // 가능
int (&ref)[3] = arr;
// ref[0] == arr[0], ref[1] == arr[1] ...
```

7. 함수에서 참조자를 리턴하는 경우.

- 함수내의 지역변수를 리턴하는 것은 오류발생

```c++
int a = int f(); // 가능
int& a = int f(); // 불가
const int& a = int f(); // 가능

int a = int& f(); // 가능, int a= int f(); 와 동치
int &a = int& f(); // 가능
const int & a = int& f(); // 가능.
```

8. 스코프 밖에서 참조자가 사용될때 메모리가 할당된다.

---

## 3. new, delete

- 동적 할당을 위한 키워드로, `malloc == new`, `free == delete` 의 역할을 수행한다.
- `malloc` 과는 다르게 `new`를 사용하면, 객체의 경우 생성자를 호출해 준다.

#### 사용

```c++
T* pointer = new T; // T 만큼의 공간을 동적 할당 (heap에)
delete pointer;  // 동적 할당한 포인터를 free;

T* pointer = new T[size];
delete[] pointer;
```

---

## 4. Class, 객체지향

- 구조체를 사용하는 경우

```c++
typedef struct Animal {
  string name;
  int age;
  ...
} Animal;

Animal temp;
temp.name = "";
temp.age = 10;

play(temp);
```

- 클래스를 사용하는 경우

```c++
Animal temp; // 초기화

temp.play() // 가능.
```

즉, `Animal`이 `play()` 하는 것이 더 적합

#### 클래스의 구조

```c++
class Animal {
  private:
    int food;
    int weight;

  public:
    void set_animal(int _food, int _weight) {
      food = _food;
      weight = _weight;
    }
}; // 주의!!
```

1. `private` 으로 지정된 멤버들은 클래스 밖에서 접근이 불가하다.
   `animal.food = 10; // 불가능`
2. `private` 라고 지정해 주지 않아도 `default`로 `private`가 지정되어있음.
3. 캡슐화를 위해 보통, 멤버 변수들은 `private`에, 멤버 함수들은 `public`에 배치하여, 멤버 함수를 통해 멤버 변수를 통제한다.
4. 클래스 또한 마지막 중괄호 뒤에 세미콜론을 붙인다.
5. 클래스 내부에는 보통 변수나 함수의 원형만을 추상화 하여 적어 놓고, 클래스 밖에서 구현한다.

#### 멤버 함수의 사용

- 클래스 밖에서 멤버 함수를 선언하여 사용한다. (클래스가 너무 길어지기 때문)
- 함수 이름 앞에 `classname::` 을 붙여 해당 클래스의 멤버 함수임을 알려준다.
- 클래스 내부에 해당 함수의 원형을 명시해주어야한다.
- 멤버 변수에 바로 접근 가능.

```c++
class Date {
  int day;

  public:
    void ShowData(); // 원형 명시
};

void Date::ShowData() {
  day = 10; // 클래스 밖임에도 멤버 변수에 바로 접근
}
```

#### 생성자

- 클래스의 객체를 초기화해주지 않으면 오류가 발생한다. 따라서 객체를 생성하자마자 초기화 해주기 위해 생성자 도입.
- 클래스 내부에서, `classname(parameter){}` 형태로 구성된다.
- 객체를 생성할때 자동으로 실행됨.

```c++
class Date {
  Date(int a, int b, ...) {
    // 생성자
  }
};

int main() {
  Date day(1, 1, ...); // 암시적
  Date day = Date(1,1,...); // 명시적
}
```

#### 디폴트 생성자

- 객체를 `Date day; or Date day = Day();`처럼 생성하게 되면 디폴트 생성자가 호출되어 초기화를 해준다.

```c++
class Date {
  Date() = default; // 디폴트 생성자 1.
  Date() { }// 디폴트 생성자 2.
}
```

#### 생성자 오버로딩

- 생성자도 함수이므로, 오버로딩이 가능하다.

```c++
class Date {
  Date() = default;
  Date(int a) {} // 생성자 1
  Date(int a, int b){} // 생성자 2
  Date(double a, double b) // 생성자 3
}
```

#### 소멸자

- 소멸자는 파라미터를 가지지 않음 -> 오버로딩 불가
- 객체가 소멸될때, 자동으로 호출됨.

```c++
class Date {
  Date() = default;
  ~Date() {}; // 소멸자
}
```

#### 복사 생성자

- `T(const T& a);` 복사생성자의 표준 정의.
- a의 값을 변경하지 않고 새로운 객체에 복사하기 위해 `const`를 사용.
- 복사 생성자는 새로운 객체를 생성시에만 호출된다.

```c++
T a();
T b(a); // 복사 생성자 호출
T b = a; // 복사 생성자 호출

T c(); // 이미 생성됨.
c = a; // 복사 생성자 X, 그냥 대입연산.
```

#### 얕은 복사(shallow) & 깊은 복사 (deep)

- 얕은 복사 : 같은 메모리 공간을 공유.
- 깊은 복사 : 독립된 메모리 공간에 값을 복사하여 클론을 만드는 행위.
- 디폴트 복사 생성자는 1대 1 복사를 수행한다.
  ```c++
  T (const T&a)
  {
    hp = a.hp;
    name = a.name;
    ...
  }
  ```
  - `name`이 문자열을 가리키는 포인터인 경우, `name`의 주소가 복사되어 `a`와 새로운 객체의 `name`이 같은 메모리 영역을 가리키게 된다. (옅은 복사)
- 깊은 복사를 위해서는 복사 생성자를 만들고, 복사 생성자에서 동적으로 새로운 메모리를 할당해 주어야 한다.
  ```c++
  T (const T&a)
  {
    hp = a.hp
    // 깊은 복사.
    name = new char[10];
    strcpy(name, a.name);
  }
  ```

#### 초기화 리스트

```c++
class Marine {
  int x_;
  int y_;
  const int z_; // 선언된 것이 아니라 원형만 표기한 것.

  public:
    Marine(int x, int y);
}
// 기존의 생성자
Marine::Marine(int x, int y, int z) {
  x_ = x;
  y_ = y;
  z_ = z; // 불가능
}

// 초기화 리스트
Marine::Marine(int x, int y) : x_(x), y_(y), z_(z){} // 가능
```

초기화 리스트는
` (생성자 이름) : var1(arg1), var2(arg2) {}` 의 형태를 가진다.

- 차이점
  초기화 리스트 : 선언과 초기화를 동시에 수행
  생성자 : 선언 후, 대입연산자를 통해 초기화를 수행힌다.
  ** 참조자나 상수(리터럴) ** 과 같은 경우는 반드시 "선언과 동시에 초기화" 되어야한다. 따라서 **클래스 내부에서 참조자나 리터럴를 사용할때 반드시 초기화 리스트를 통해 생성해 주어야 한다.**

#### static 변수, static 함수

- `static` 클래스 내부에서 공유하는 변수나 함수를 지칭함.
- `static` 은 객체를 만들지 않아도 사용 가능 -> 어떤 객체에도 속해있지 않는다.
- 따라서 `static` 변수나 함수끼리만 직접 접근 가능하다.

```c++
// static 변수
int Marine::static_var_name = 0; // static 변수 초기화

// static 함수
Marine::static_fuc_name(); // static 함수 호출
```

#### this

- 객체 자신을 가리키는 포인터.
- 모든 멤버 함수 내부에서 this 키워드가 정의되어있음
- this를 사용할 수 없는 클래스 내부 함수는 static함수 뿐이다.

#### 클래스에서 참조자를 리턴하는 경우

```c++
class A {
  int x;

  A(int x) : x(x){}

  int get_x();
  int& acc_x();
}

A a(3);
int a1 = a.get_x(); // a.x의 값을 복사하여 리턴. a.x객체와 독립적
int a11 = a.acc_x(); // 위와 동일한 동작으로 수행.

int& a2 = a.acc_x(); // a의 멤버 변수인 x를 리턴. a2는 a.x객체를 참조하고 있음.
int& a22 = a.get_x(); // Error:a.x의 값을 복사한 변수는 임시 변수이므로 참조자를 가질 수 없다.
```

#### const 함수

- 상수 멤버 함수를 정의함으로서, 이 함수는 다른 멤버 변수의 값을 바꾸지 않는 함수라고 알리는 것.
- 상수함수 내부에서는 객체의 "읽기"만 가능하며, 상수 함수에서는 다른 상수함수만 호출할 수 있다.
- **객체의 값을 변경하지 않는 함수나 파라미터에 "모두" cont를 붙이는 것을 권장**

```c++
  int attack() const;
  int Marine::attack() const;
  int Marine::get_value(const int a) const;
  // (기존 함수의 정의) const; 형태로 선언가능.
```

#### explicit, mutable

- explicit : 암시적 형변환이나, 복사 생성자를 통한 생성자를 막아준다.

```c++
explicit Marine() {}
explicit get_val(int b) {}
get_val(double aa) {}

Marine s = "abc" //  불가능
Marine s("abc"); // 가능
Marine s = Marine("abc"); // 가능
```

- mutable : const 함수에서 객체 내부의 mutable 객체를 변경할 수 있다.

```c++
class tmp {
  int k;
  mutable int kk;
  int erase(int a) const {
    k = 10; // 불가
    kk = 10; // 가능
  }
}
```

---

## 5. 함수의 오버로딩 (overloading)

- c++ 에서는 함수의 이름이 같더라도, 인자가 다르면 다른함수라고 판단한다.
- 정확히 일치하는 타입이 없는 경우, 점차 포괄적으로 형변환을 통해 일치하는 함수를 찾는다.
  `char`, `short` -> `int`
  `unsigned short` -> `int` or `unsigned int`
  `float` -> `double`
  `Enum` -> `int`

- 마지막으로 유저 정의된 타입변환으로 일치하는 함수를 찾는다.
- 찾는 과정에서 일치하는 함수를 찾지 못하거나, 2개 이상 일치하는 함수를 찾을 경우 오류발생한다.

```c++
void print(int x);
void print(char x);
void printf(double x, int y);
// 3가지 함수 모두 다른 함수라고 인지
```

---

## 6. 연산자 오버로딩 (overloading)

#### 정의

- 연산자 오버로딩을 위해서, 오버로딩을 원하는 연산자 함수를 제작하면 된다.

  `(리턴 타입) operator(연산자) (연산자가 받는 인자)` 의 구조를 가진다.

  ```c++
  // a == b
  bool operator==(const MyString& str) const;
  ```

  이제 MyString 타입의 `str1 == str2` 연산을 수행하게 되면, 내부적으로 `str1.operator==(str2)` 와 동일한 동작을 수행하게 된다.
  <br>

- 임의의 연산자 `@`에 대하여 `a@b` 에 대하여, 컴파일러는 아래 중 하나를 선택하여 실행한다.

  ```c++
  *a.operator@(b); // 멤버 함수, @가 단항 연산자, 동등하지 않는 이항연산자 일때
  *operator@(a, b); // 외부 함수 , @가 동등한 이항 연산자 일때
  // 위와 같은 규칙을 고려하여 연산자 함수를 정의해야한다.
  ```

- 같은 연산자도 오버로딩을 통해 여러 동작을 가질 수 있다.

  ```c++
  T operator+(const char * p) const; // T + "" 인 경우
  T operator+(const T& a) const; // T + T 인 경우
  // 같은 "+" 연산자에 대해, 다른 동작을 부여함.
  ```

- 생성자만 있다면 컴파일러가 알아서 컴파일 해준다. 따라서 생성자만 있다면, 위에서 정의한 타입별 연산자 함수가 필요없어진다.

  ```c++
  // 연산자
  T operator+(const T& a) {}
  // 생성자
  T() {}
  T(const char* p) {}

  //
  T a();
  T b();
  const char *p = "hello";

  a + b // => a.operator+(b)
  a + p // => a.operator+(T(p))

  //p 가 리터럴 이므로 T(p) 도 리터럴이다. -> const T& 로 받아야함.
  ```

#### friend

- class A내부에서 `friend class B;` 라고 명시하게된다면, B에서 A의 private에 접근할 수 있다. `friend void func();` 도 가능하다.

  ```c++
  class A {
    private:
    int a;
    friend class B;
  }

  class B {
    private :
    B () {
      A a();
      a.a = 10; // 가능
    }
  }
  ```

#### Wrapper class

- 기본자료형들을 객체로서 다뤄야 할때, 기본 자료형들을 클래스로 포장하여 사용하는데, 이때 wrapper 클래스로 포장하여 사용하게 된다.

- 타입 변환 연산자를 통해 Wrapper class도 기본 자료형 처럼 사용할 수 있게 한다

  ```c++
  // operator (변환하고자 하는 타입) () {}
  class Int {
    int data;
    public :
      Int(int data) : data(data){}
      operator int() {return data;} // wrapper class를 읽을 때 int로 읽는다.
      ...
  }
  ```

### 캐스팅

C와는 다르게 어떤 목적으로 캐스팅 하였는지 구분할 수 있게 4가지 캐스팅을 제공한다.

`static_cast` : 기본적인 언어적 차원의 일반적인 타입변환
`const_cast` : const 제거. const int -> int
`dynamic_cast` : 다운 캐스팅
`reinterpret_cast` : 관련 없는 포인터 사이의 캐스팅

```c++
//(캐스팅 종류) <바꾸려는 타입> (대상); 형태를 가진다.
double d;
static_cast <int> (d); // d은 int형이 되었음.
```

### 상속

```c++
class A : public B { // A가 B를 "public" 으로 상속받음
  int a;

  // A는 B에 의존하고있으므로, B를 먼저 생성해줘야 의존성이 만족된다.
  A(int a) : B(), a(a) {}

}
```

#### protected

`private` : 자신과 friend만 접근 가능
`protected` : 자신과 friend + 자식 접근 가능
`public` : 모두 접근 가능

`class A : private B {}` 의 경우, A에서 B의 public, protected scope의 객체에 접근할 수 있지만,
외부에서 A 중에 상속받은 객체에 접근하고자 한다면, private로 받았기 때문에 접근이 불가하다.

즉, 외부 -> A -> B 구조일때,
외부 -> A : A 고유의 public만 접근 가능 ( 상속 받은 것들은 모두 private 처리됨)
A -> B : 상속받았으므로, B의 public, protected까지 접근 가능하다.

#### 오버라이딩

- 클래스 내에서 상속받은 함수를 재정의 하는 것.

```c++
class A {
  void fuc(int a) {}
}

class B : public A {
  void fuc(int a) override {} // fuc를 오버라이딩함.
}
```

상속관계의 두 클래스 포인터에 대해 캐스팅 하는 것을
각각 업 캐스팅, 다운 캐스팅이라고 하며, dynamic_cast를 통해 할 수 있다.

---
