#pragma once

#include "D2DFramework.h"
class Actor
{
protected :
	D2DFramework* mpFramework;
	ID2D1Bitmap* mpBitmap;

	float mX;
	float mY;
	float mOpacity;

public :

	// 생성자
	Actor() = delete;
	Actor(D2DFramework* pFramework, LPCWSTR filename);
	Actor(D2DFramework* pFramework, LPCWSTR filename, float x, float y, float opacity = 1.0f);

	// 소멸자
	virtual ~Actor();

	virtual void Draw();

private :
	void Draw(float x, float y, float opacity = 1.0f); // 외부에 쓰는 Draw를 간소화하게 이렇게 만들어서 private의 함수를 wrapping 할 수 있음.
};

