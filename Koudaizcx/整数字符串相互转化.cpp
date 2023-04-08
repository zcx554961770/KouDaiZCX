#include "pch.h"
#include "整数字符串相互转化.h"
BOOL CharToHex(BYTE 整数, OUT char* szpBufHex)
{
	BYTE bLow = 0;
	BYTE bHigh = 0;
	//0x7 8 //7*16
	//0x1 7
	bLow = 整数 % 16; //取低位0..15
	bHigh = 整数 / 16; //取高位0..15
	//处理高位
	if (bHigh > 9) // A,B,C,D,E,F
	{
		//szpBufHex[0] = 'A' + bHigh - 10; //'B'
		szpBufHex[0] = bHigh + 55; // 'A'-10=55

	}
	else//0..9
	{
		szpBufHex[0] = bHigh + 48; //'0'+2='2'
	}

	//处理低位
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

//能转多个字节的
void 字节数组转字符串(IN BYTE* 数组, int 长度, OUT char* 返回16进制字符串 /*清0*/)
{
	for (int i = 0; i < 长度; i = i + 1)
	{
		char HexBuf[32] = { 0 };
		CharToHex(数组[i], HexBuf); // ",3F" //3F

		返回16进制字符串[i * 3 + 0] = HexBuf[0]; //i * 3+2
		返回16进制字符串[i * 3 + 1] = HexBuf[1]; //i * 3+2
		返回16进制字符串[i * 3 + 2] = ','; //i * 3+2
	}
	return;
}
BYTE 处理1字节(char* BStr)
{
	BYTE low = 0;
	BYTE high = 0;
	// "B2"
	// BStr[0]='B'
	// BStr[1]='2'
	//处理低位
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


	//处理高位
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
void 字符串转字节数组(IN char* hex进制字符串, OUT BYTE* 数组, int 数组长度)
{
	int len = strlen(hex进制字符串);
	char buf[3] = { 0 };
	int index = 0;
	for (int i = 0; i < len; i = i + 3, index++)
	{
		buf[0] = hex进制字符串[i + 0];
		buf[1] = hex进制字符串[i + 1];
		buf[2] = '\0'; //0 //字符串结束标志
		数组[index] = 处理1字节(buf);
	}

};