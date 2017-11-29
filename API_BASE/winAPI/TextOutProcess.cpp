#include "stdafx.h"
#include "UserInterface.h"

void UserInterface::showLevel(void)
{
	//레벨이 세자리인경우
	if (Level >= 100)
	{
		//100자리
		switch (Level / 100)
		{
		case 1:
			l1->setX(_form->getX() + 45);
			l1->setY(_form->getY() + 7);
			l1->render(getMemDC());
			break;
		case 2:
			l2->setX(_form->getX() + 45);
			l2->setY(_form->getY() + 7);
			l2->render(getMemDC());
			break;
		case 3:
			l3->setX(_form->getX() + 45);
			l3->setY(_form->getY() + 7);
			l3->render(getMemDC());
			break;
		case 4:
			l4->setX(_form->getX() + 45);
			l4->setY(_form->getY() + 7);
			l4->render(getMemDC());
			break;
		case 5:
			l5->setX(_form->getX() + 45);
			l5->setY(_form->getY() + 7);
			l5->render(getMemDC());
			break;
		case 6:
			l6->setX(_form->getX() + 45);
			l6->setY(_form->getY() + 7);
			l6->render(getMemDC());
			break;
		case 7:
			l7->setX(_form->getX() + 45);
			l7->setY(_form->getY() + 7);
			l7->render(getMemDC());
			break;
		case 8:
			l8->setX(_form->getX() + 45);
			l8->setY(_form->getY() + 7);
			l8->render(getMemDC());
			break;
		case 9:
			l9->setX(_form->getX() + 45);
			l9->setY(_form->getY() + 7);
			l9->render(getMemDC());
			break;
		}


		//10자리
		switch ((Level % 100) / 10)
		{
		case 0:
			l00->setX(_form->getX() + 53);
			l00->setY(_form->getY() + 7);
			l00->render(getMemDC());
			break;
		case 1:
			l01->setX(_form->getX() + 53);
			l01->setY(_form->getY() + 7);
			l01->render(getMemDC());
			break;
		case 2:
			l02->setX(_form->getX() + 53);
			l02->setY(_form->getY() + 7);
			l02->render(getMemDC());
			break;
		case 3:
			l03->setX(_form->getX() + 53);
			l03->setY(_form->getY() + 7);
			l03->render(getMemDC());
			break;
		case 4:
			l04->setX(_form->getX() + 53);
			l04->setY(_form->getY() + 7);
			l04->render(getMemDC());
			break;
		case 5:
			l05->setX(_form->getX() + 53);
			l05->setY(_form->getY() + 7);
			l05->render(getMemDC());
			break;
		case 6:
			l06->setX(_form->getX() + 53);
			l06->setY(_form->getY() + 7);
			l06->render(getMemDC());
			break;
		case 7:
			l07->setX(_form->getX() + 53);
			l07->setY(_form->getY() + 7);
			l07->render(getMemDC());
			break;
		case 8:
			l08->setX(_form->getX() + 53);
			l08->setY(_form->getY() + 7);
			l08->render(getMemDC());
			break;
		case 9:
			l09->setX(_form->getX() + 53);
			l09->setY(_form->getY() + 7);
			l09->render(getMemDC());
			break;
		}

		//1자리
		switch (Level % 10)
		{
		case 0:
			l000->setX(_form->getX() + 61);
			l000->setY(_form->getY() + 7);
			l000->render(getMemDC());
			break;
		case 1:
			l001->setX(_form->getX() + 61);
			l001->setY(_form->getY() + 7);
			l001->render(getMemDC());
			break;
		case 2:
			l002->setX(_form->getX() + 61);
			l002->setY(_form->getY() + 7);
			l002->render(getMemDC());
			break;
		case 3:
			l003->setX(_form->getX() + 61);
			l003->setY(_form->getY() + 7);
			l003->render(getMemDC());
			break;
		case 4:
			l004->setX(_form->getX() + 61);
			l004->setY(_form->getY() + 7);
			l004->render(getMemDC());
			break;
		case 5:
			l005->setX(_form->getX() + 61);
			l005->setY(_form->getY() + 7);
			l005->render(getMemDC());
			break;
		case 6:
			l006->setX(_form->getX() + 61);
			l006->setY(_form->getY() + 7);
			l006->render(getMemDC());
			break;
		case 7:
			l007->setX(_form->getX() + 61);
			l007->setY(_form->getY() + 7);
			l007->render(getMemDC());
			break;
		case 8:
			l008->setX(_form->getX() + 61);
			l008->setY(_form->getY() + 7);
			l008->render(getMemDC());
			break;
		case 9:
			l009->setX(_form->getX() + 61);
			l009->setY(_form->getY() + 7);
			l009->render(getMemDC());
			break;

		}

	}

	else //레벨이 두자리인경우
		if (Level >= 10)
		{

			//10자리
			switch (Level / 10)
			{
			case 1:
				l1->setX(_form->getX() + 45);
				l1->setY(_form->getY() + 7);
				l1->render(getMemDC());
				break;
			case 2:
				l2->setX(_form->getX() + 45);
				l2->setY(_form->getY() + 7);
				l2->render(getMemDC());
				break;
			case 3:
				l3->setX(_form->getX() + 45);
				l3->setY(_form->getY() + 7);
				l3->render(getMemDC());
				break;
			case 4:
				l4->setX(_form->getX() + 45);
				l4->setY(_form->getY() + 7);
				l4->render(getMemDC());
				break;
			case 5:
				l5->setX(_form->getX() + 45);
				l5->setY(_form->getY() + 7);
				l5->render(getMemDC());
				break;
			case 6:
				l6->setX(_form->getX() + 45);
				l6->setY(_form->getY() + 7);
				l6->render(getMemDC());
				break;
			case 7:
				l7->setX(_form->getX() + 45);
				l7->setY(_form->getY() + 7);
				l7->render(getMemDC());
				break;
			case 8:
				l8->setX(_form->getX() + 45);
				l8->setY(_form->getY() + 7);
				l8->render(getMemDC());
				break;
			case 9:
				l9->setX(_form->getX() + 45);
				l9->setY(_form->getY() + 7);
				l9->render(getMemDC());
				break;
			}

			//1자리
			switch (Level % 10)
			{
			case 0:
				l00->setX(_form->getX() + 53);
				l00->setY(_form->getY() + 7);
				l00->render(getMemDC());
				break;
			case 1:
				l01->setX(_form->getX() + 53);
				l01->setY(_form->getY() + 7);
				l00->render(getMemDC());
				break;
			case 2:
				l02->setX(_form->getX() + 53);
				l02->setY(_form->getY() + 7);
				l00->render(getMemDC());
				break;
			case 3:
				l03->setX(_form->getX() + 53);
				l03->setY(_form->getY() + 7);
				l00->render(getMemDC());
				break;
			case 4:
				l04->setX(_form->getX() + 53);
				l04->setY(_form->getY() + 7);
				l00->render(getMemDC());
				break;
			case 5:
				l05->setX(_form->getX() + 53);
				l05->setY(_form->getY() + 7);
				l00->render(getMemDC());
				break;
			case 6:
				l06->setX(_form->getX() + 53);
				l06->setY(_form->getY() + 7);
				l00->render(getMemDC());
				break;
			case 7:
				l07->setX(_form->getX() + 53);
				l07->setY(_form->getY() + 7);
				l00->render(getMemDC());
				break;
			case 8:
				l08->setX(_form->getX() + 53);
				l08->setY(_form->getY() + 7);
				l00->render(getMemDC());
				break;
			case 9:
				l09->setX(_form->getX() + 53);
				l09->setY(_form->getY() + 7);
				l00->render(getMemDC());
				break;

			}

		}
		else
			//레벨이 한자리인경우
			//1자리
			switch (Level)
			{
			case 1:
				l1->setX(_form->getX() + 45);
				l1->setY(_form->getY() + 7);
				l1->render(getMemDC());
				break;
			case 2:
				l2->setX(_form->getX() + 45);
				l2->setY(_form->getY() + 7);
				l2->render(getMemDC());
				break;
			case 3:
				l3->setX(_form->getX() + 45);
				l3->setY(_form->getY() + 7);
				l3->render(getMemDC());
				break;
			case 4:
				l4->setX(_form->getX() + 45);
				l4->setY(_form->getY() + 7);
				l4->render(getMemDC());
				break;
			case 5:
				l5->setX(_form->getX() + 45);
				l5->setY(_form->getY() + 7);
				l5->render(getMemDC());
				break;
			case 6:
				l6->setX(_form->getX() + 45);
				l6->setY(_form->getY() + 7);
				l6->render(getMemDC());
				break;
			case 7:
				l7->setX(_form->getX() + 45);
				l7->setY(_form->getY() + 7);
				l7->render(getMemDC());
				break;
			case 8:
				l8->setX(_form->getX() + 45);
				l8->setY(_form->getY() + 7);
				l8->render(getMemDC());
				break;
			case 9:
				l9->setX(_form->getX() + 45);
				l9->setY(_form->getY() + 7);
				l9->render(getMemDC());
				break;

			}
}

void UserInterface::showStatement(void)
{
	//hp정보!!!
	_rs->render(getMemDC(), _form->getX() + 105, _form->getY() + 29); // 슬래쉬!!!

																	  //오른쪽(최대hp)!!
	if (MaxHp >= 100000)
	{
		switch (MaxHp / 100000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		}

		switch ((MaxHp % 100000) / 10000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		}

		switch ((MaxHp % 10000) / 1000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		}

		switch ((MaxHp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		}

		switch ((MaxHp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		}

		switch (MaxHp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 147, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 147, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 147, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 147, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 147, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 147, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 147, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 147, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 147, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 147, _form->getY() + 30);
			break;
		}
	}
	//5자리수인 경우
	else if (MaxHp >= 10000)
	{
		switch (MaxHp / 10000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		}

		switch ((MaxHp % 10000) / 1000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		}

		switch ((MaxHp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		}

		switch ((MaxHp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		}

		switch (MaxHp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 140, _form->getY() + 30);
			break;
		}
	}

	//4자리인 경우
	else if (MaxHp >= 1000)
	{
		switch (MaxHp / 1000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		}

		switch ((MaxHp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		}

		switch ((MaxHp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		}

		switch (MaxHp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 133, _form->getY() + 30);
			break;
		}

	}

	//세자리인 경우
	else if (MaxHp >= 100)
	{
		switch (MaxHp / 100)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		}

		switch ((MaxHp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		}

		switch (MaxHp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 126, _form->getY() + 30);
			break;
		}

	}
	else if (MaxHp >= 10)
	{
		switch (MaxHp / 10)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		}

		switch (MaxHp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 119, _form->getY() + 30);
			break;
		}
	}
	else
	{
		switch (MaxHp)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 30);
			break;
		}
	}


	//--------------------------------playerHP정보---------------------------------------

	if (playerHp >= 100000)
	{
		switch (playerHp / 100000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 63, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 63, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 63, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 63, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 63, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 63, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 63, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 63, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 63, _form->getY() + 30);
			break;
		}

		switch ((playerHp % 100000) / 10000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		}

		switch ((playerHp % 10000) / 1000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		}

		switch ((playerHp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		}

		switch ((playerHp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		}

		switch (playerHp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		}
	}
	//5자리수인 경우
	else if (playerHp >= 10000)
	{
		switch (playerHp / 10000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 70, _form->getY() + 30);
			break;
		}

		switch ((playerHp % 10000) / 1000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		}

		switch ((playerHp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		}

		switch ((playerHp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		}

		switch (playerHp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		}
	}

	//4자리인 경우
	else if (playerHp >= 1000)
	{
		switch (playerHp / 1000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 77, _form->getY() + 30);
			break;
		}

		switch ((playerHp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		}

		switch ((playerHp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		}

		switch (playerHp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		}

	}

	//세자리인 경우
	else if (playerHp >= 100)
	{
		switch (playerHp / 100)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 84, _form->getY() + 30);
			break;
		}

		switch ((playerHp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		}

		switch (playerHp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		}

	}
	else if (playerHp >= 10)
	{
		switch (playerHp / 10)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 91, _form->getY() + 30);
			break;
		}

		switch (playerHp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		}
	}
	else
	{
		switch (playerHp)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 30);
			break;
		}
	}


	//-----------------------------------------------mp정보!!!!--------------------------------------------------
	_rs->render(getMemDC(), _form->getX() + 105, _form->getY() + 46); // 슬래쉬!!!

																	  //오른쪽(최대mp)!!
	if (MaxMp >= 100000)
	{
		switch (MaxMp / 100000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		}

		switch ((MaxMp % 100000) / 10000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		}

		switch ((MaxMp % 10000) / 1000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		}

		switch ((MaxMp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		}

		switch ((MaxMp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		}

		switch (MaxMp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 147, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 147, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 147, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 147, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 147, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 147, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 147, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 147, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 147, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 147, _form->getY() + 47);
			break;
		}
	}
	//5자리수인 경우
	else if (MaxMp >= 10000)
	{
		switch (MaxMp / 10000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		}

		switch ((MaxMp % 10000) / 1000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		}

		switch ((MaxMp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		}

		switch ((MaxMp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		}

		switch (MaxMp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 140, _form->getY() + 47);
			break;
		}
	}

	//4자리인 경우
	else if (MaxMp >= 1000)
	{
		switch (MaxMp / 1000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		}

		switch ((MaxMp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		}

		switch ((MaxMp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		}

		switch (MaxMp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 133, _form->getY() + 47);
			break;
		}

	}

	//세자리인 경우
	else if (MaxMp >= 100)
	{
		switch (MaxMp / 100)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		}

		switch ((MaxMp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		}

		switch (MaxMp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 126, _form->getY() + 47);
			break;
		}

	}
	else if (MaxMp >= 10)
	{
		switch (MaxMp / 10)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		}

		switch (MaxMp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 119, _form->getY() + 47);
			break;
		}
	}
	else
	{
		switch (MaxMp)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 112, _form->getY() + 47);
			break;
		}
	}


	//--------------------------------playerMP정보---------------------------------------

	if (playerMp >= 100000)
	{
		switch (playerMp / 100000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 63, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 63, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 63, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 63, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 63, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 63, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 63, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 63, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 63, _form->getY() + 47);
			break;
		}

		switch ((playerMp % 100000) / 10000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		}

		switch ((playerMp % 10000) / 1000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		}

		switch ((playerMp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		}

		switch ((playerMp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		}

		switch (playerMp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		}
	}
	//5자리수인 경우
	else if (playerMp >= 10000)
	{
		switch (playerMp / 10000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 70, _form->getY() + 47);
			break;
		}

		switch ((playerMp % 10000) / 1000)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		}

		switch ((playerMp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		}

		switch ((playerMp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		}

		switch (playerMp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		}
	}

	//4자리인 경우
	else if (playerMp >= 1000)
	{
		switch (playerMp / 1000)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 77, _form->getY() + 47);
			break;
		}

		switch ((playerMp % 1000) / 100)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		}

		switch ((playerMp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		}

		switch (playerMp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		}

	}

	//세자리인 경우
	else if (playerMp >= 100)
	{
		switch (playerMp / 100)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 84, _form->getY() + 47);
			break;
		}

		switch ((playerMp % 100) / 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		}

		switch (playerMp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		}

	}
	else if (playerMp >= 10)
	{
		switch (playerMp / 10)
		{
		case 1:
			_1->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 91, _form->getY() + 47);
			break;
		}

		switch (playerMp % 10)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		}
	}
	else
	{
		switch (playerMp)
		{
		case 0:
			_0->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 1:
			_1->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 2:
			_2->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 3:
			_3->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 4:
			_4->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 5:
			_5->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 6:
			_6->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 7:
			_7->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 8:
			_8->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		case 9:
			_9->render(getMemDC(), _form->getX() + 98, _form->getY() + 47);
			break;
		}
	}




	//==========================================경험치!!!====================================================

	//-------------------------------오른쪽 퍼센트 출력------------------------------------------

	_Lc->render(getMemDC(), expGuage->getX() + 680, expBackground->getY());
	jeongsu = (_exp / LvExp) * 100;
	sosu = (((_exp / LvExp) * 100) - jeongsu) * 100;

	switch (jeongsu / 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 686, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 686, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 686, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 686, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 686, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 686, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 686, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 686, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 686, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 686, expBackground->getY() + 1);
		break;
	}
	switch (jeongsu % 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 693, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 693, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 693, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 693, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 693, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 693, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 693, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 693, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 693, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 693, expBackground->getY() + 1);
		break;
	}

	_dot->render(getMemDC(), expGuage->getX() + 703, expBackground->getY() + 7);

	switch (sosu / 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 707, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 707, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 707, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 707, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 707, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 707, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 707, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 707, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 707, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 707, expBackground->getY() + 1);
		break;
	}
	switch (sosu % 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 714, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 714, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 714, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 714, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 714, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 714, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 714, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 714, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 714, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 714, expBackground->getY() + 1);
		break;
	}
	_percent->render(getMemDC(), expGuage->getX() + 723, expBackground->getY() + 1);
	_Rc->render(getMemDC(), expGuage->getX() + 733, expBackground->getY());

	//-------------------------------------------퍼센트출력 끝---------------------------------------------

	//------------------------------------------현재 내 경험치 출력----------------------------------

	//1의자리
	switch (_exp % 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 670, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 670, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 670, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 670, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 670, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 670, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 670, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 670, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 670, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 670, expBackground->getY() + 1);
		break;
	}

	//2의자리
	if (_exp / 10 == 0)
		return;
	//더이상 할거 없으면 아웃!!!!!

	//2의자리
	switch ((_exp / 10) % 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 663, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 663, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 663, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 663, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 663, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 663, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 663, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 663, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 663, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 663, expBackground->getY() + 1);
		break;
	}

	//3의자리
	if (_exp / 100 == 0)
		return;
	//더이상 할거 없으면 아웃!!!!!

	//2의자리
	switch ((_exp / 100) % 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 656, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 656, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 656, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 656, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 656, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 656, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 656, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 656, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 656, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 656, expBackground->getY() + 1);
		break;
	}

	//4의자리
	if (_exp / 1000 == 0)
		return;
	//더이상 할거 없으면 아웃!!!!!

	//4의자리
	switch ((_exp / 1000) % 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 649, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 649, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 649, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 649, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 649, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 649, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 649, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 649, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 649, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 649, expBackground->getY() + 1);
		break;
	}

	//5의자리
	if (_exp / 10000 == 0)
		return;
	//더이상 할거 없으면 아웃!!!!!

	//5의자리
	switch ((_exp / 10000) % 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 642, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 642, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 642, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 642, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 642, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 642, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 642, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 642, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 642, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 642, expBackground->getY() + 1);
		break;
	}

	//6의자리
	if (_exp / 100000 == 0)
		return;
	//더이상 할거 없으면 아웃!!!!!

	//6의자리
	switch ((_exp / 100000) % 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 635, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 635, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 635, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 635, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 635, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 635, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 635, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 635, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 635, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 635, expBackground->getY() + 1);
		break;
	}

	//7의자리
	if (_exp / 1000000 == 0)
		return;
	//더이상 할거 없으면 아웃!!!!!

	//7의자리
	switch ((_exp / 1000000) % 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 628, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 628, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 628, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 628, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 628, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 628, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 628, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 628, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 628, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 628, expBackground->getY() + 1);
		break;
	}

	//8의자리
	if (_exp / 10000000 == 0)
		return;
	//더이상 할거 없으면 아웃!!!!!

	//8의자리
	switch ((_exp / 10000000) % 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 621, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 621, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 621, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 621, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 621, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 621, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 621, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 621, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 621, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 621, expBackground->getY() + 1);
		break;
	}

	//9의자리
	if (_exp / 100000000 == 0)
		return;
	//더이상 할거 없으면 아웃!!!!!

	//9의자리
	switch ((_exp / 100000000) % 10)
	{
	case 0:
		_0->render(getMemDC(), expGuage->getX() + 614, expBackground->getY() + 1);
		break;
	case 1:
		_1->render(getMemDC(), expGuage->getX() + 614, expBackground->getY() + 1);
		break;
	case 2:
		_2->render(getMemDC(), expGuage->getX() + 614, expBackground->getY() + 1);
		break;
	case 3:
		_3->render(getMemDC(), expGuage->getX() + 614, expBackground->getY() + 1);
		break;
	case 4:
		_4->render(getMemDC(), expGuage->getX() + 614, expBackground->getY() + 1);
		break;
	case 5:
		_5->render(getMemDC(), expGuage->getX() + 614, expBackground->getY() + 1);
		break;
	case 6:
		_6->render(getMemDC(), expGuage->getX() + 614, expBackground->getY() + 1);
		break;
	case 7:
		_7->render(getMemDC(), expGuage->getX() + 614, expBackground->getY() + 1);
		break;
	case 8:
		_8->render(getMemDC(), expGuage->getX() + 614, expBackground->getY() + 1);
		break;
	case 9:
		_9->render(getMemDC(), expGuage->getX() + 614, expBackground->getY() + 1);
		break;
	}


	//여기까지 도달했으면 그냥 종료시켜버려라.
	return;

}
