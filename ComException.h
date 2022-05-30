#pragma once
#include <Windows.h>
#include <exception>
#include <string>
#include <sstream>


	class com_exception : public std::exception
	{
	private:
		HRESULT mResult;
		std::string mDescription;

	public:
		com_exception(HRESULT hr) : mResult{ hr }
		{
		}
		com_exception(HRESULT hr, std::string msg) : mResult{ hr }, mDescription{ msg }
		{

		}

		virtual const char* what() const override
		{
			std::stringstream ss;
			ss << "Failure with Code : " << mResult << std::endl << mDescription << std::endl;

			return ss.str().c_str();
		}
	};

	inline void ThrowIfFailed(HRESULT hr, std::string msg = "") // inline은 함수호출스텍을 줄여서 성능을 증가시키는 것이다. 
										  // 함수의 코드를 해당줄에 붙여서 호출스텍을 사용하지 않게 하는 것이다.
										  // 이것은 compiler가 판단해서 하는데 이것을 우리가 원해도 거부할 수도 있다.
	{
		if (FAILED(hr))
		{
			throw com_exception(hr, msg);
		}
	}

