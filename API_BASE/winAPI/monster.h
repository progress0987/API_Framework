#pragma once
#include"gameNode.h"
//������ �⺻ ���� Ŭ����
class monster :public gameNode
{
	int MaxHp;
	int NowHp;
	int Atk;
	int Def;
	RECT body;
	bool dead;
	bool Left;
public:
	
	monster();
	~monster();
	//����
	HRESULT init(int Hp, int Atk, int Def, POINT position, int Width, int height);
	//���ݷ� ��������
	int getAtk(void);
	//ü�� ���
	void SubHp(int Atk);
	//ü�� 0 Ȯ���ϱ�
	bool ZeroHp(void);
	//���ݴ��Ѱ� Ȯ��
	bool hit(void);
	//���� �¿� ������
	void MonsterMoving(int move);
	//���� �߷°� �ֱ�
	void MonsterDown(int Down);
	//���� ������ ����
	void left(int way);
	//�������� ���������� Ȯ���ϴ� �Լ�
	bool way(void);
	//�ȼ��浹�� ���� ��Ʈ ����
	void Setbody(int i);
	RECT Base(void);
};
//Harp�� ���� Ŭ����
class Harp :public gameNode
{
	int Timer=0;
	POINT generator;
	monster* harp;
	RECT player;
	int fream = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Harp();
	~Harp();
	//���� �׸�, ü�� �� ����
	HRESULT init(void);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���ݷ� ��������
	int getAtk(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���� ��ǥ ����
	void SetPoint(POINT position);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};