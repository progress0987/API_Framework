#pragma once
#include"gameNode.h"
#include"progressBar.h"
//������ �⺻ ���� Ŭ����
class monster :public gameNode
{
protected:
	progressBar* Hpbar;
	int MaxHp;
	int NowHp;
	int Atk;
	int Def;
	RECT body;
	RECT colBody;
	RECT playerBody;
	RECT SkillTwoRect[4];
	POINT pt;
	POINT GenPoint;
	bool dead;
	bool moveDir;//true - ������
	int bodyW, bodyH;
	int MyIndex;
	int Gentime=50;

	Camera* cam;
public:

	monster();
	~monster();
	//����
	HRESULT init(int Hp, int Atk, int Def, POINT position, int Width, int height);
	virtual void update();
	virtual void render();
	virtual void collRect(RECT player, int demage);
	virtual RECT getbody(void);//���� üũ ��Ʈ ��������
	bool hit(void);				//���ݴ��Ѱ� Ȯ��
	void MonsterMoving(int move);	//���� �¿� ������
	bool ZeroHp(void);				//ü���� 0 �������� Ȯ��
	void SharePlayer(RECT PlayerBase);

	void MonsterDown(int Down);	//���� �߷°� �ֱ�

	void left(int way);	//���� ������ ����

	void Setbody(int i);//�ȼ��浹�� ���� ��Ʈ ����

	void SetCam(Camera* c) { cam = c; }//ī�޶� ����

	int getIndex(void) { return MyIndex; }//�ε��� ��������

	void HpbarInit(void);//hp�� �����
	void Hpbarupdate(void);//hp�� ������Ʈ
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
	int alpha = 250;
public:
	Harp();
	~Harp();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};
//Grupin�� ���� Ŭ����
class Grupin :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Grupin();
	~Grupin();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};

class Cellion :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Cellion();
	~Cellion();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};

class Lioner :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Lioner();
	~Lioner();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};

class Lucida :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Lucida();
	~Lucida();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};

class JrYeti :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	JrYeti();
	~JrYeti();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};

class PePe :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	PePe();
	~PePe();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};

class Sheep :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Sheep();
	~Sheep();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};

class JCellion :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	JCellion();
	~JCellion();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};

class JGrupin :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	JGrupin();
	~JGrupin();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};

class JLioner :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	JLioner();
	~JLioner();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};

class JLucida :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	JLucida();
	~JLucida();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
};

class Eliza :public monster
{
	int Timer = 0;
	int frame = 0;
	int SkillOneF = 0;
	int SkillTwoF = 0;
	int SkillTwoCount = 0;
	POINT DemagePoint[4];
	bool SkillOne;
	bool SkillTwo;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
	int SkillTime = 0;
	RECT PlayerBase;
	int PlayerDamge;
	JLucida* setJLucida;
	Lucida* setLucida;
public:
	Eliza();
	~Eliza();
	//���� �׸�, ü�� �� ����
	HRESULT init(POINT position);
	//�̵��ϴ� �Լ�
	void moving(void);
	//���Ϳ��� ������ �ֱ�
	void SubHp(int Atk);
	//����
	void dead(void);
	void update(void);
	void render(void);
	//���Ͱ� �÷��̾�� ���ݴ��ߴ°�(���ݷµ� �Է����ּž� �մϴ�)
	void collRect(RECT player, int demage);
	void skill2(void);
//	void SetCam(Camera* c);
};