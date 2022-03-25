#include <iostream>
using namespace std;

// 초기화 리스트

// 멤버 변수 초기화 ? 다양한 무넙이 존재

// 초기화 왜 해야할까? 
// - 버그 예방에 중요
// - 포인터 등 주소값이 연루되어 있을 경우

// 초기화 방법
// - 생성자 내에서
// - 초기화 리스트
// - c++ 11 문법

// 초기화 리스트
// - 일단 상속 관계에서 원하는 부모 생성자 호출할 때 필요하다
// - 생성자 내에서 초기화 vs 초기화 리스트
// -- 일반 변수는 별 차이 없음
// -- 멤버 타입이 클래스인 경우 차이가 난다
// -- 정의함과 동시에 초기화가 필요한 경우(참조 타입, Const 타입)


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

// Is - A (Knight Is - A Player? 기산는 플레이어다) OK -> 상속관계

// Has - A (Knight Has - A Inventory? 기사는 인벤토리를 포함하고 있다, 갖고있다) OK -> 포함관계

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
    int _hp; // 쓰레기 값
    Inventory _inventory; // Knight 가 Inventory 를 포함

    int& _hpRef = _hp;
    const int _hpConst = 100;
};

int main()
{
    Knight k;

    cout << k._hp << endl;

    if(k._hp < 0)
    {
        cout << "Knight is Dead" << endl;
    }

    return 0;
}