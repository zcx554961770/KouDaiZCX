#pragma once
class 内存读写
{
public:
	内存读写();
	~内存读写();

private:

public:

	float R4F(UINT_PTR BASE);
	DWORD R4(UINT_PTR BASE);
};

内存读写::内存读写()
{
}

内存读写::~内存读写()
{
}

//读1字节内存数据
static BYTE R1(UINT_PTR Base)
{
	__try
	{
		return *(BYTE*)Base;
	}
	__except (1)
	{
		return 0;//出现异常执行这里的代码
	}

};
//读4字节内存数据
static DWORD R4(UINT_PTR Base)
{
	__try
	{
		return *(PDWORD)Base;
	}
	__except (1)
	{
		return 0;//出现异常执行这里的代码
	}

};

//写4字节内存数据
static BOOL W4(UINT_PTR Base, DWORD value)
{
	__try
	{
		*(PDWORD)Base = value;
		return true;
	}
	__except (1)
	{
		return false;//出现异常执行这里的代码
	}

};

