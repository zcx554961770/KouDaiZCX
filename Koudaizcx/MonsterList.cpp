#include "pch.h"
#include "MonsterList.h"
#include<locale.h>

int MonsterList::printObj(int i, UINT_PTR 对象)
{
	/*
	 +000 vftable 怪物对象大小3D8
	 +0DC //?

	+124 怪物id
	+138 当前血量
	+18c 血量上限
	+114 // ID  dword
	 3b8]+0xC]+0*4]+0] //名字 怪对象+??]+??]+??]+??
	 +003C //坐标
	 +025C //坐标
	 +02FC //坐标

	*/

	UINT_PTR vftable = R4(对象 + 0x00);
	//DWORD 等级 = R4(对象 + 0x120);
	DWORD 当前血量 = R4(对象 + 0x130);
	DWORD 血量上限 = R4(对象 + 0x150);
	DWORD ID = R4(对象 + 0x114);
	wchar_t* utf16le_name = (wchar_t*)RP(RP(RP(RP(对象 + 0x3b8) + 0x0c) + 0x00) + 0x00);
	//float x = R4F(对象 + 0x3C + 4 * 0);
	//float y = R4F(对象 + 0x3C + 4 * 1);
	//float z = R4F(对象 + 0x3C + 4 * 2);
	//setlocale(0, 0);
	setlocale(LC_CTYPE, "");
	//没有输出
	/*wprintf(L"i=%d,对象=%X vftable=%X 等级=%d 血量(%d/%d) ID=%X  utf16le_name=%s 坐标(%f,%f,%f) line=%d \r\n",
		i, 对象,
		vftable, 等级, 当前血量, 血量上限, ID, utf16le_name, x, y, z,
		__LINE__);*/
	wprintf(L"i=%d,对象=%X vftable=%X  血量(%d/%d) ID=%X  utf16le_name=%s \r\n",
		i, 对象,
		vftable, 当前血量, 血量上限, ID, utf16le_name,
		__LINE__);
	return 0;
}


void MonsterList::遍历数组()
{
	// [[[[0x00D0DF1C]+0x1c]+8]+1c+1*4]+58 // 数组地址？
	// [[[[0x00D0DF1C]+0x1c]+8]+1c+1*4]+5C // 数量 
	//[[[[[0x00D0DF1C]+0x1c]+8]+1c+1*4]+54+4]+0*4 是怪物对象数组

	int 总数量 = R4(RP(RP(RP(RP(0x00D0DF1C) + 0x1c) + 0x08) + 0x1c + 1 * 4) + 0x5C);
	// [[[[D79ADC] + C] + 20 + 4 * 1] + 54 + 4] + 4 * i //怪物数组
	UINT_PTR 怪物数组地址 = RP(RP(RP(RP(RP(0x00D0DF1C) + 0x1c) + 0x08) + 0x1C + 4 * 1) + 0x54 + 4);
	UINT_PTR* 怪物数组 = (UINT_PTR*)怪物数组地址;
	int i = 0;
	UINT_PTR 怪物对象 = R4(怪物数组地址 + i * 4);// 怪物数组[i]; //异常 出错的风险
	//i = i + 1; 
	while (i < 总数量 && R4(怪物对象)) // 怪物数组 +i*sizeof(void*) // R4(怪物数组地址+i*4) 等价于 怪物数组[i]
	{
		//循环 0
		printf("i=%d,怪物对象=%zx line=%d \r\n", i, 怪物对象, __LINE__);
		printObj(i, 怪物对象);//打印怪物对象信息

		i++; //指向下一个对象
		怪物对象 = R4(怪物数组地址 + i * 4);// 怪物数组[i];

	}

}
