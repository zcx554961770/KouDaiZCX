#include "pch.h"
#include "�����ַ����໥ת��.h"
BOOL CharToHex(BYTE ����, OUT char* szpBufHex)
{
	BYTE bLow = 0;
	BYTE bHigh = 0;
	//0x7 8 //7*16
	//0x1 7
	bLow = ���� % 16; //ȡ��λ0..15
	bHigh = ���� / 16; //ȡ��λ0..15
	//�����λ
	if (bHigh > 9) // A,B,C,D,E,F
	{
		//szpBufHex[0] = 'A' + bHigh - 10; //'B'
		szpBufHex[0] = bHigh + 55; // 'A'-10=55

	}
	else//0..9
	{
		szpBufHex[0] = bHigh + 48; //'0'+2='2'
	}

	//�����λ
	if (bLow > 9) // A,B,C,D,E,F
	{
		szpBufHex[1] = 55 + bLow; //'B'
	}
	else//0..9
	{
		szpBufHex[1] = 48 + bLow; //'0'+2='2'
	}
	szpBufHex[2] = 0;//0
	return TRUE;
}

//��ת����ֽڵ�
void �ֽ�����ת�ַ���(IN BYTE* ����, int ����, OUT char* ����16�����ַ��� /*��0*/)
{
	for (int i = 0; i < ����; i = i + 1)
	{
		char HexBuf[32] = { 0 };
		CharToHex(����[i], HexBuf); // ",3F" //3F

		����16�����ַ���[i * 3 + 0] = HexBuf[0]; //i * 3+2
		����16�����ַ���[i * 3 + 1] = HexBuf[1]; //i * 3+2
		����16�����ַ���[i * 3 + 2] = ','; //i * 3+2
	}
	return;
}
BYTE ����1�ֽ�(char* BStr)
{
	BYTE low = 0;
	BYTE high = 0;
	// "B2"
	// BStr[0]='B'
	// BStr[1]='2'
	//�����λ
	if (BStr[1] > '9') // A,B,C,D,E,F //
	{
		low = BStr[1] - 55;
		//szpBufHex[1] = bLow + 55; //'B'

	}
	else//0..9
	{
		//szpBufHex[1] = bLow + 48; //'0'+2='2'
		low = BStr[1] - 48;
	}


	//�����λ
	if (BStr[0] > '9') // A,B,C,D,E,F //
	{
		high = BStr[0] - 55;
		//szpBufHex[1] = bLow + 55; //'B'

	}
	else//0..9
	{
		//szpBufHex[1] = bLow + 48; //'0'+2='2'
		high = BStr[0] - 48;
	}

	return high * 16 + low;
}
// "07,00,B2,81,40,43,EB,0E,74,43,75,4C,63,C3"
void �ַ���ת�ֽ�����(IN char* hex�����ַ���, OUT BYTE* ����, int ���鳤��)
{
	int len = strlen(hex�����ַ���);
	char buf[3] = { 0 };
	int index = 0;
	for (int i = 0; i < len; i = i + 3, index++)
	{
		buf[0] = hex�����ַ���[i + 0];
		buf[1] = hex�����ַ���[i + 1];
		buf[2] = '\0'; //0 //�ַ���������־
		����[index] = ����1�ֽ�(buf);
	}

};