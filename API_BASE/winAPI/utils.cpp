#include "stdafx.h"
#include "utils.h"

namespace Util {
	//�Ÿ�
	float getDistance(float startX, float startY, float endX, float endY) {
		float x = (endX - startX) / 2;
		float y = (endY - startY) / 2;
		return sqrtf(x*x + y*y);
	}
	//����
	float getAngle(float x1, float y1, float x2, float y2) {
		float x = x2 - x1;
		float y = y2 - y1;
		float dist = sqrtf(x*x + y*y);
		//ź��Ʈ ����
		float angle = atanf(y / x);

		//�ڻ��ξ������
		/*if(y2 > y1) {
			angle = PI * 2 - angle;
		}*/
		return angle;
	}
}
