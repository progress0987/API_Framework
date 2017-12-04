#pragma once

//���� ���� ������� ���� cMath ���̺귯�� �߰�
#include <cmath>

#define DEG_TO_RAD 0.017435f //��׸� 1��(���Ȱ�)
#define PI 3.141592654f
#define PI2 (PI*2.f)

#define PI_2		(PI/2.f)
#define PI_4		float(PI/4.0f)
#define PI_8		float(PI/8.0f)
#define PI_16		float(PI/16.0f)
#define PI_32		float(PI/32.0f)

#define FLOAT_TO_INT(f1) static_cast<int>(f1)
#define FLOAT_EPSILON 0.001f // �Ǽ����� ���� ���� ����

namespace Util {
	//�Ÿ�
	float getDistance(float startX,float startY, float endX, float endY);
	//����
	float getAngle(float x1, float y1, float x2, float y2);
}


