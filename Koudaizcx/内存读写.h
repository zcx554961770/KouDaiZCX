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
//x86 ָ����4�ֽ�
//x64 ָ����8�ֽ�
static UINT_PTR RP(UINT_PTR Base)
{
	__try
	{
		return *(UINT_PTR*)Base;
	}
	__except (1)
	{
		return 0;//�����쳣ִ������Ĵ���
	}

};
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
static float R4F(UINT_PTR Base)
{
	return *(float*)Base;
	//return *(������ָ��)Base; ���ϱ�һ�� �ȼ�
}
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

