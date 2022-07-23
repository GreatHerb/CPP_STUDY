# <객체지향 문법 정리> 

Class와 Static에 관해서
-----
Class   


    클래스(Class)는 일종의 "설계도"
    c++에서의 class는 struct문법과 종이 한 장 차이이다
    
| | **class** | **struct** |
| --- | :---: | :---: |
| 기본 접근 지정자 | private | public |
| 차이점 | 객체 지향 프로그래밍의 표현 용도 | 구조체(데이더 묶음) 표현 용도 |
| c언어에서 | - | 데이터만 저장가능, 초기화 불가 |

Static 

    static = 정적 = 고정된 <- 공용물건 같은 느낌
    "class라는 설계도 안에 포함 되어 있지만 설계도상으로만 존재 할게요!"
* 특정 객체와는 무관하고, 클레스 객체와 연관되어 있다.   
* class 내에서 종속적인 변수들은 하나 하나 건드릴 수 있지만,,   
* static 변수 선언을 하면 한번의 동작으로 모든 class 객체에 접근할 수 있다   


생성자와 소멸자
------
    
__암시적(implicit) 생성자__

    생성자를 명시적으로 만들지 않으면, 컴파일러에 의해 아무인자도 받지 않는 [기본생성자]가 자동으로 만들어짐
    
__명시적(explicit) 생성자__
    
    명시적으로 생성자를 만들게되면, 자동으로 만들어지던 [기본생성자]는 더 이상 만들어지지 않는다
    
__복사 생성자__

    자기 자신의 클래스 참조 타입을 인자로 받고, 일반적으로 "똑같은" 데이터를 지닌 함수가 생성되기를 기대한다
    
__소멸자__

    오직 하나만 존재한고, 생성자와 같이 명시적으로 만들지 않으면 컴파일러에 의해 자동으로 만들어진다
    
------------

```c++
class Knight
{
public:
    // [1] 기본 생성자 (인자가 없음) 
    Knight()
    {
        cout << "Knight() 기본 생성자가 호출" << endl;

        _hp = 100;
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }
    
    // [2] 복사 생성자
    Knight(const Knight& Knight) // const는 거의 99.99% 사용한다.
    {
        _hp = Knight._hp;
        _attack = Knight._attack;
        _posX = Knight._posX;
        _posY = Knight._posY;
    }
    
    // [3] 기타 생성자
    // 이 중에서 인자를 1개만 받는 [기타 생성자]를,
    // [타입 변환 생성자]라고 부르기도 함

    // 명시적인 용도로만 사용할 것
    
    explicit Knight(int hp)
    {
        cout << "Knight(int) 생성자가 호출" << endl;
        _hp = hp;
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }
    
    // 소멸자 -> 오직 한개만 존재
    ~Knight()
    {
        cout << "Knight() 기본 소멸자가 호출" << endl;  
    }
    
public:
    int _hp;
    int _attack;
    int _posY;
    int _posX;
};

```


상속성
-----
* __상속(inheritance)__ : 부모 -> 자식에게 유산을 물려주는 것    
    * 객체(자손) 위의 객체(부모)가 존재할 수 있다    
    * 자손 객체는 부모 객체의 모든것(public요소들)을 기본적으로 가진다

```c++
class Mother
{
public:
    Mother()
    {
        cout << "Mother의 기본 생성자 호출" << endl;
    }
    
    ~Mother()
    {
        cout << "~Mother의 기본 소멸자 호출" << endl;
    }
    
    void Move() { cout << "Move()호출" << endl; }
    
public:
    int _id;
};

class Son : public Mother
{
public:
    Son()
    {
        cout << "Son의 기본 생성자 호출" << endl;
    }
    
    ~Son()
    {
        cout << "~Son의 기본 소멸자 호출" << endl;
    }
};

int main()
{
    Son t1;
    t1.Move();

    return 0;
}

```

##### 결과값

    Mother의 기본 생성자 호출    
    Son의 기본 생성자 호출    
    Move()호출    
    ~Son의 기본 소멸자 호출    
    ~Mother의 기본 소멸자 호출    
   


은닉성
------
### 은닉성 = 캡슐화 -> 몰라도 되는 것은 깔끔하게 숨기겠다!    

__캡슐화를 하는 이유?__

    1) 정말 위험하고 건드리면 안되는 경우    
    2) 다른 경로로 접근하길 원하는 경우    
    
    
## 접근 지정자

| | public | protected | private |
| :---: | :---: | :---: | :---: | 
| 의미 | 누구나 사용하세요~ | 나의 자손들한테만 허락! | 나만 사용할꺼!(클래스 내부에서만) |
| 상속 | 부모님의 유산 설계 그대로 | 내 자손들한테만 물러줄꺼야 | 나까지만 잘 쓰고 자손들한테는 아예 안 물러줄꺼야 |
| 사용 빈도 | 굿 | 거의 안씀 | 거의 안씀 |

```c++
class Berserker
{
public:

    int GetHp() { return _hp; }

    // 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동(광폭화)
    void SetHp(int hp)
    {
        _hp = hp;
        if(hp <= 50)
            SetBerserkerMode(); // class 내부에서만 쓸 수 있음
    }
    
private:
    void SetBerserkerMode()
    {
        cout << "매우 강해짐!" << endl;
    }

private:
    int _hp = 100;
};

int main(void)
{
    Berserker b;
    b.SetHp(20);
    
    return 0;
}

```

##### 결과값

    매우 강해짐!    


다형성
-----

* 다형성
    * 다형성(Polymorphism = Poly + morph) : 겉은 똑같은데 기능이 다르게 동작한다  
    
    
* 오버로딩 vs 오버라이딩


| | overloading | overriding |
| :---: | :---: | :---: | 
| 상속 | 상관 없이 사용가능 | 상속관게 일 때만 사용가능 | 
| 정의방법 | 반환값의 자료형은 동일, 매개변수는 달라야 한다 | 함수의 반환 값, 매개변수, 이름 모두 동일해야 함 | 
| 쓰는 이유 | 같은 함수지만 다른 일을 시키고 싶을 때 | 부모/자식 클래스에 있는 함수가 맘에 안들 때 |



* 바인딩
    * 정적 바인딩(Static Binding) : 컴파일 시점에 결정
    
        * 일반 함수는 정적 바인딩을 사용   
        
    * 동적 바인딩(Dynamic Binding) : __실행 시점에 결정__
    
        * 동적 바인딩 사용을 원한다면 -> 가상 함수(virtual function) 사용
     
* 가상 함수 테이블
    * 실제 객체가 어떤 타입인지 어떻게 알고 알아서 가상함수를 호출해줄까?? -> 가상 함수 테이블

* 순수 가상 함수
    * 구현은 없고 __인터페이스__ 만 전달하는 용도로 사용하고 싶을 경우

* 추상 클래스
    * 순수 가상 함수가 1개 이상 포함되면 추상 클래스로 간주 -> 직접적으로 객체를 만들 수 없게됨

``` c++

class Player
{
public:
    Player()
    {
        int _hp = 100;
    }

    void Move() { cout << "Move Player!" << endl; }
    void Move(int a) { cout << "Move Player !" << endl; } // 오버 로딩

    virtual void VMove() { cout << "VMove Player!" << endl; }
    virtual void VDie() { cout << "VDie Player!" << endl; }

    virtual void VAttack() = 0; // 순수 가상 함수
public:
    int _hp;
};

class Knight : public Player
{
public:

    Knight()
    {
        _stamina = 100;
    }

    void Move() { cout << "Move Knight !!" << endl; }

    // 가상 함수는 재정의를 하더라도 가상 함수다!
    virtual void VMove() { cout << "VMove Knight!" << endl; }
    virtual void VDie() { cout << "VDie Knight!" << endl; }

    virtual void VAttack() { cout << "VAttack Knight" << endl; } 

public:
    int _stamina;
};

// [ [ Player ] ]
// [   Knight   ]

void MovePlayer(Player* player) // 이 경우 가상 함수를 이용하여 해결 [이정표를 들고 있다고 생각하면 편하다]
{
    player -> VMove();
    player -> VDie();
}

int main()
{
    // Player p;
    // MovePlayer(&p); // 플레이어는 플레어다? Yes
    // MoveKnight(&p); // 플레이어는 기사다? No

    Knight k;
    // MoveKnight(&k); // 기사는 기사다? Yes
    MovePlayer(&k); // 기사는 플레이어다? Yes


    return 0;
}

```

##### 결과값
    VMove Knight!
    VDie Knight!

-------------

* 순수 가상 함수 vs 가상 함수
    * 추가 예정입니다
 


```c++

virtual void VAttack() = 0;  

-> 이렇게 생긴 아이들을 순수 가상 함수라고 한다     
   함수가 정의된게 아니라 선언만 된것이다     
   이녀석들은 객체로 만들지 못하고 상속으로만 사용된다

```
    
```c++

void MovePlayer(Player* player) // 이 함수를 쓰는 이유 추가 예정 (공부 더 해오겠습니다)
{
    player -> VMove();
    player -> VDie();
}

-> 부모 클래스의 주소값을 받음으로써, 자식클래스에 맞는 함수를 실행하도록 해준다.

```
    
  

초기화 리스트
------

* 초기화 왜 해야할까? 
   * 버그 예방에 중요
   * 포인터 등 주소값이 연루되어 있을 경우

* 초기화 방법
   * 생성자 내에서
   * 초기화 리스트
   * c++ 11 문법

* 초기화 리스트
   * 일단 상속 관계에서 원하는 부모 생성자 호출할 때 필요하다
   * 생성자 내에서 초기화 vs 초기화 리스트
   * 일반 변수는 별 차이 없음
   * 멤버 타입이 클래스인 경우 차이가 난다
   * 정의함과 동시에 초기화가 필요한 경우(참조 타입, Const 타입)

#### Is - A? Has - A?
    Is - A 가 자연스럽다 -> 상속 관계
    Has - A 가 자연스럽다 -> 포함 관계
    
```c++
class Inventory
{
public:
    Inventory() { cout << "Inventory()" << endl; }
    Inventory(int size) { cout << "Inventory(int size)" << endl; _size = size; }

    ~Inventory() { cout << "~Inventory()" << endl; }

public:
    int _size = 10; // c++ 11 문법

};

class Player
{
public:
    Player() { }
    Player(int id) { }
};

class Knight : public Player
{
public:
    Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100) // << 1) 이렇게 초기화 해도 되고
        /*
        선처리 영역


        */
    {
        _hp = 100; // << 2) 이렇게 초기화 해도 된다
        // _inventory = Inventory(20);
        // 이 경우는 선처리영역에서 Inventory() -> inventory(int size) 생성 후 다시 생성하기 때문에
        // 여러번 생성된다
    }
    // 초기화를 하지 않으면 쓰레기값으로 초기화가 된다

public:
    int _hp; // 쓰레기 값으로 초기화
    Inventory _inventory; // Knight 가 Inventory 를 포함

    int& _hpRef = _hp;
    const int _hpConst = 100;
};

// night Is - A Player? 기산는 플레이어다) OK -> 상속관계
// Knight Has - A Inventory? 기사는 인벤토리를 포함하고 있다, 갖고있다) OK -> 포함관계

int main()
{
    Knight k;

    cout << k._hp << endl;

    return 0;
}

```
----------
##### 결과값
    Inventory(int size)
    100
    ~Inventory()
    


연산자 오버로딩
------

    준비중


