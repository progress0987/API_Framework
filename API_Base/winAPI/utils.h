#pragma once

//���� ���� ������� ���� cMath ���̺귯�� �߰�
#include <cmath>

#define DEC_TO_RAD 0.017453f // 1���� ���� ���� ��
#define PI 3.141592654f
#define PI2 PI*2
#define FLOAT_EPSILON 0.001f // �Ǽ����� ���� ���� ����

namespace Util {
	//�Ÿ�
	float getDistance(float startX,float startY, float endX, float endY);
	//����
	float getAngle(float x1, float y1, float x2, float y2);
}


