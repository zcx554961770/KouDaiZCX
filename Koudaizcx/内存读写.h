#pragma once
class �ڴ��д
{
public:
	�ڴ��д();
	~�ڴ��д();

private:

public:

	float R4F(UINT_PTR BASE);
	DWORD R4(UINT_PTR BASE);
};

�ڴ��д::�ڴ��д()
{
}

�ڴ��д::~�ڴ��д()
{
}

//��1�ֽ��ڴ�����
static BYTE R1(UINT_PTR Base)
{
	__try
	{
		return *(BYTE*)Base;
	}
	__except (1)
	{
		return 0;//�����쳣ִ������Ĵ���
	}

};
//��4�ֽ��ڴ�����
static DWORD R4(UINT_PTR Base)
{
	__try
	{
		return *(PDWORD)Base;
	}
	__except (1)
	{
		return 0;//�����쳣ִ������Ĵ���
	}

};

//д4�ֽ��ڴ�����
static BOOL W4(UINT_PTR Base, DWORD value)
{
	__try
	{
		*(PDWORD)Base = value;
		return true;
	}
	__except (1)
	{
		return false;//�����쳣ִ������Ĵ���
	}

};

