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

        // 예제에서 초기화 필요한 것.
        mspBackground = std::make_unique<Actor>(this, L"Data/back1_1024.png", 0.0f, 0.0f);
        mspBug = std::make_unique<Actor>(this, L"Data/bug1_1.png", 0.0f, 0.0f);

        return S_OK;
    }

    virtual void Release() override
    {
        // 예제에서 사용한 동적 메모리 해제
        mspBug.reset();
        mspBackground.reset();

        D2DFramework::Release();

    }

    virtual void Render() override
    {
        HRESULT hr;

        mspRenderTarget->BeginDraw();
        mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

        // 예제에서 그릴 것들
        mspBackground->Draw();
        mspBug->Draw();


        hr = mspRenderTarget->EndDraw();
        if (hr == D2DERR_RECREATE_TARGET)
        {
            CreateDeviceResources();
        }
    }
};

