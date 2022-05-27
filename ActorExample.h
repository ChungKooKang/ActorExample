#pragma once
#include "D2DFramework.h"
#include "Actor.h"

class ActorExample :
    public D2DFramework
{
    std::unique_ptr<Actor> mspBackground;
    std::unique_ptr<Actor> mspBug;
public :
    virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"Actor Example", UINT width = 1024, UINT height = 768) override
    {
        HRESULT hr;
        hr = D2DFramework::Initialize(hInstance, title, width, height);
        ThrowIfFailed(hr);

        // �������� �ʱ�ȭ �ʿ��� ��.
        mspBackground = std::make_unique<Actor>(this, L"Data/back1_1024.png", 0.0f, 0.0f);
        mspBug = std::make_unique<Actor>(this, L"Data/bug1_1.png", 0.0f, 0.0f);

        return S_OK;
    }

    virtual void Release() override
    {
        // �������� ����� ���� �޸� ����
        mspBug.reset();
        mspBackground.reset();

        D2DFramework::Release();

    }

    virtual void Render() override
    {
        HRESULT hr;

        mspRenderTarget->BeginDraw();
        mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

        // �������� �׸� �͵�
        mspBackground->Draw();
        mspBug->Draw();


        hr = mspRenderTarget->EndDraw();
        if (hr == D2DERR_RECREATE_TARGET)
        {
            CreateDeviceResources();
        }
    }
};

