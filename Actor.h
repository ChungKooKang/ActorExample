#pragma once

#include "D2DFramework.h"
class Actor
{
protected :
	D2DFramework* mpFramework;
	Microsoft::WRL::ComPtr<ID2D1Bitmap> mspBitmap;

	float mX;
	float mY;
	float mOpacity;

public :

	// ������
	Actor() = delete;
	Actor(D2DFramework* pFramework, LPCWSTR filename);
	Actor(D2DFramework* pFramework, LPCWSTR filename, float x, float y, float opacity = 1.0f);

	// �Ҹ���
	virtual ~Actor();

	virtual void Draw();

private :

	HRESULT LoadWICImage(LPCWSTR filename);
	void Draw(float x, float y, float opacity = 1.0f); // �ܺο� ���� Draw�� ����ȭ�ϰ� �̷��� ���� private�� �Լ��� wrapping �� �� ����.
};

