#pragma once
#include"gameNode.h"
//������ �⺻ ���� Ŭ����
class monster :public gameNode
{
protected:
	int MaxHp;
	int NowHp;
	int Atk;
	int Def;
	RECT body;
	RECT colBody;
	POINT pt;
	bool dead;
	bool moveDir;//true - ������
	int bodyW, bodyH;


	Camera* cam;
public:

	monster();
	~monster();
	//����
	HRESULT init(int Hp, int Atk, int Def, POINT position, int Width, int height);

	bool hit(void);				//���ݴ��Ѱ� Ȯ��
	void MonsterMoving(int move);	//���� �¿� ������


	void MonsterDown(int Down);	//���� �߷°� �ֱ�

	void left(int way);	//���� ������ ����

	void Setbody(int i);//�ȼ��浹�� ���� ��Ʈ ����

	void SetCam(Camera* c) { cam = c; }//ī�޶� ����

};
//Harp�� ���� Ŭ����
class Harp :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 255;
public:
	Harp();
	~Harp();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
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
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};