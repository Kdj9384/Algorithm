# Algorithm with C++

## 씹어먹는 C++

참고 ::
https://modoocode.com/

### 1. `namespace` 의 이해

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
