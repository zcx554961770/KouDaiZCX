#include "pch.h"
#include "MonsterList.h"
#include<locale.h>

int MonsterList::printObj(int i, UINT_PTR ����)
{
	/*
	 +000 vftable ��������С3D8
	 +0DC //?

	+124 ����id
	+138 ��ǰѪ��
	+18c Ѫ������
	+114 // ID  dword
	 3b8]+0xC]+0*4]+0] //���� �ֶ���+??]+??]+??]+??
	 +003C //����
	 +025C //����
	 +02FC //����

	*/

	UINT_PTR vftable = R4(���� + 0x00);
	//DWORD �ȼ� = R4(���� + 0x120);
	DWORD ��ǰѪ�� = R4(���� + 0x130);
	DWORD Ѫ������ = R4(���� + 0x150);
	DWORD ID = R4(���� + 0x114);
	wchar_t* utf16le_name = (wchar_t*)RP(RP(RP(RP(���� + 0x3b8) + 0x0c) + 0x00) + 0x00);
	//float x = R4F(���� + 0x3C + 4 * 0);
	//float y = R4F(���� + 0x3C + 4 * 1);
	//float z = R4F(���� + 0x3C + 4 * 2);
	//setlocale(0, 0);
	setlocale(LC_CTYPE, "");
	//û�����
	/*wprintf(L"i=%d,����=%X vftable=%X �ȼ�=%d Ѫ��(%d/%d) ID=%X  utf16le_name=%s ����(%f,%f,%f) line=%d \r\n",
		i, ����,
		vftable, �ȼ�, ��ǰѪ��, Ѫ������, ID, utf16le_name, x, y, z,
		__LINE__);*/
	wprintf(L"i=%d,����=%X vftable=%X  Ѫ��(%d/%d) ID=%X  utf16le_name=%s \r\n",
		i, ����,
		vftable, ��ǰѪ��, Ѫ������, ID, utf16le_name,
		__LINE__);
	return 0;
}


void MonsterList::��������()
{
	// [[[[0x00D0DF1C]+0x1c]+8]+1c+1*4]+58 // �����ַ��
	// [[[[0x00D0DF1C]+0x1c]+8]+1c+1*4]+5C // ���� 
	//[[[[[0x00D0DF1C]+0x1c]+8]+1c+1*4]+54+4]+0*4 �ǹ����������

	int ������ = R4(RP(RP(RP(RP(0x00D0DF1C) + 0x1c) + 0x08) + 0x1c + 1 * 4) + 0x5C);
	// [[[[D79ADC] + C] + 20 + 4 * 1] + 54 + 4] + 4 * i //��������
	UINT_PTR ���������ַ = RP(RP(RP(RP(RP(0x00D0DF1C) + 0x1c) + 0x08) + 0x1C + 4 * 1) + 0x54 + 4);
	UINT_PTR* �������� = (UINT_PTR*)���������ַ;
	int i = 0;
	UINT_PTR ������� = R4(���������ַ + i * 4);// ��������[i]; //�쳣 ����ķ���
	//i = i + 1; 
	while (i < ������ && R4(�������)) // �������� +i*sizeof(void*) // R4(���������ַ+i*4) �ȼ��� ��������[i]
	{
		//ѭ�� 0
		printf("i=%d,�������=%zx line=%d \r\n", i, �������, __LINE__);
		printObj(i, �������);//��ӡ���������Ϣ

		i++; //ָ����һ������
		������� = R4(���������ַ + i * 4);// ��������[i];

	}

}
