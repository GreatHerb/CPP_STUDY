#include <iostream>
using namespace std;

// 객체지향 마무리

// 1) struct vs class

// c++ 에서는 struct 나 class나 종이 한 장 차이다.
// struct는 기본 접근 지정자가 public 이고 class는 private이다.
// 왜 이렇게 했을까? c++는 c언어에서 파상되어 발전했기 때문에, 호환성을 지키기 위함.
// struct -> 그냥 구조체 (데이더 묶음)표현 용도
// class -> 객체 지향 프로그래밍의 특징 나타내는 용도

struct Teststruct
{
public:
    int _a;
    int _b;
};

class Testclass
{
private:
    int _a;
    int _b;
};

// 2) static 변수, static 함수 (static = 정적 = 고정된) << 공용물건 같은 느낌

class Marin
{
public:
    // 특정 마린 객체에 종속적
    int _hp;

    void TakeDamage(int damage)
    {
        _hp -= damage;
    }

    static void SetAttack()
    {
        s_attack = 100;
    }

    // 특정 마린 객체와 무관
    // 마린이라는 '클래스'객체와 연관
    static int s_attack; // 설계도상으로만 존재
};

// static 변수는 어떤 메모리를 활용할까?
// 초기화 하면 .data
// 초기화 안 하면 .bss 
int Marin :: s_attack = 0;

class Player
{
public:
    int _id;
};

int Generateid()
{
    // 생명주기 : 프로그램 시작/종료 (메모리에 항상 올라가 있음)
    // 가시범위 : 

    // 정적 지역 객체
    static int s_id = 1;

    return s_id ++;
}

int main()
{
    Marin m1;
    m1._hp = 35;
    m1.TakeDamage(10);

    Marin :: s_attack = 6;
    //m1.s_attack = 6;

    Marin m2;
    m2._hp = 14;
    //m1.s_attack = 6;
    m2.TakeDamage(5);

    // 마린 공격력 업그레이드 완료!
    Marin :: s_attack = 7;
    Marin :: SetAttack();

    static int id = 100;
    int a = id;

    cout << Generateid() << endl;
    cout << Generateid() << endl;
    cout << Generateid() << endl;
    cout << Generateid() << endl;
    cout << Generateid() << endl;
    cout << Generateid() << endl;

    return 0;
}