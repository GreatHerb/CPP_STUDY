#include <iostream>
using namespace std;

// 상속성

// 객체지향 (OOP: Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다양성

// 메모리
// [ [ Player ] ] 12byte
// [   Knight   ] 4byte


// 상속(inheritance) ? 부모 -> 자식에게 유산을 물려주는 것

// 생성자(N)/소멸자(1)

// 생성자는 탄생을 기념해서 호출되는 함수?
// ~Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택! -> 둘 다 호출하자!!

// GameObject
// - Creature
// -- Player, Monster, Npc, Pet
// - Projectile
// -- Arrow, Fireball
// - Env(채집물)


// Item
// - Weapon
// -- Sword, Bow
// - Armor
// -- Helmet, Boots, Armor
// - Comsumable
// -- Potion, Scroll
class GameObject
{
public:
    int _objectid;
};

class Player : public GameObject
{
public:
    Player()
    {
        _hp = 0;
        _attack = 0;
        _defence = 0;
        cout << "Player() 기본 생성자 호출" << endl; 
    }

    Player(int hp)
    {
        _hp = hp;
        _attack = 0;
        _defence = 0;
        cout << "Player(int hp) 기본 생성자 호출" << endl;
    }

    ~Player()
    {
        cout << "~Player() 기본 소멸자 호출" << endl; 
    }

    void Move() { cout << "Player Move 호출" << endl;  }
    void Attack() { cout << "Player Attack 호출" << endl; }
    void Die() { cout << "Player Die 호출" << endl;  }

public:
    int _hp;
    int _attack;
    int _defence;
};

// class 는 일종의 설계도
class Knight : public Player
{
public:
    Knight()
        /* 
        선(먼저)처리 영역
        - 여기서 Player()의 생성자를 호출
        */
    {
        _stamina = 100;
        cout << "Knight() 기본 생성자 호출" << endl; 
    }

    Knight(int stamina) : Player(100) // 생성자 지정 (지정 하지 않으면 기본 생성자만 만들어짐)
        /* 
        선(먼저)처리 영역
        - 여기서 Player(int hp)의 생성자를 호출
        */
    {
        _stamina = stamina;
        cout << "Knight(int stamina) 기본 생성자 호출" << endl; 
    }

    ~Knight()
    {
        cout << "~Knight() 기본 소멸자 호출" << endl; 
    }
        /* 
        후(나중에)처리 영역
        - 여기서 ~Player()의 소멸자를 호출
        */

    // 재정의 : 부모님의 유산을 거부하고 새로운 이름으로 만든 ?
    void Move() { cout << "Player Move1 호출" << endl; }
public:
    int _stamina;
};

class Mage : public Player
{
public:

public:
    int _mp;
};

int main(void)
{
    Knight k(100);

    k._hp = 100;
    k._attack = 10;
    k._defence = 5;
    k._stamina = 50;                                            

    k.Move();
    // k.Player :: Move(); // 사용빈도 거의 0%

    k.Attack();
    k.Die();
    return 0;
}
