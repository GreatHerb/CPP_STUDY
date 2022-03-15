#include <iostream>
using namespace std;

// [암시적(implicit) 생성자]
// 생성자를 명시적으로 만들지 않으면,
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐
// -> 그러나 우리가 명시적(explicit)으로 아무 생성자를 하나 만들면,
// 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어지지 않는다.
// 클래스는 일종의 설계도

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

    // [2] 복사 생성자 (자기 자신의 클래스 참조 타입을 인자로 받음)
    // 일반적으로 "똑같은" 데이터를 지닌 함수가 생성되기를 기대한다
    // 이것도 자동으로 만들어지긴함

    Knight(const Knight& Knight) // const는 거의 99.99% 사용한다.
    {
        _hp = Knight._hp;
        _attack = Knight._attack;
        _posX = Knight._posX;
        _posY = Knight._posY;
    }

    //// [3] 기타 생성자
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

    Knight(int hp, int attack, int posX, int posY)
    {
        _hp = hp;
        _attack = 10;
        _posX = posX;
        _posY = posY;        
    }
    // 소멸자 -> 오직 한개만 존재
    ~Knight()
    {
        cout << "Knight() 기본 소멸자가 호출" << endl;  
    }

    // 멤버 함수 선언
    void Move(int y, int x);
    void Attack();
    void Die()
    {
        _hp = 0;
        cout << "Die" << endl;
    }

public:
    // 멤버 변수
    int _hp;
    int _attack;
    int _posY;
    int _posX;
};

void Knight :: Move(int y, int x)
{
    _posY = y;
    _posX = x;
    cout << "Move" << endl;
}

void Knight :: Attack()
{
    cout << "Attack : " << _attack << endl;
}

void HelloKnight(Knight k)
{
    cout << "Hello Knight" << endl;
}

int main(void)
{
    Knight k1(100, 10, 0, 0);
    k1._hp = 100;
    k1._attack = 10;
    k1._posY = 0;
    k1._posX = 0;

    Knight k2(k1);  // 복사 생성자 호출
    Knight k3 = k1; // 복사 생성자 호출
    Knight k4;  // 생성자
    k4 = k1;    // 복사

    k1.Move(2, 2);
    k1.Attack();
    k1.Die();

    // 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
    int num = 1;

    float f = (float)num;   // 명시적 < 우리가 코드로 num을 float 바구니에 넣으라고 주문
    double d = num; // 암시적 < 컴파일러가 알아서 처리

    Knight k5;

    k5 = (Knight)1;

    HelloKnight((Knight)5);

    return 0;
} 
