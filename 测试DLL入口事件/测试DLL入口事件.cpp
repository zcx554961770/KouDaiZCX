// 测试DLL入口事件.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<Windows.h>

int main()
{
	//多字节  字符集  LoadLibraryA   // "Dll1.dll"
	//Unicode 字符集  LoadLibraryW   // L"Dll1.dll"

	HMODULE hdll = LoadLibrary(L"koudaizcx.dll");
	printf("hdll=%p line=%d \n", hdll, __LINE__);
	getchar();
	{
		//  hdll = LoadLibraryA("Dll1.dll");
		printf("hdll=%p line=%d \n", hdll, __LINE__);
		BOOL 释放结果 = FreeLibrary(hdll);
		printf("hdll=%p 释放结果=%d line=%d \n", hdll, 释放结果, __LINE__);
	}

	{
		hdll = LoadLibraryA("koudaizcx.dll");
		printf("hdll=%p line=%d \n", hdll, __LINE__);
		BOOL 释放结果 = FreeLibrary(hdll);
		printf("hdll=%p 释放结果=%d line=%d \n", hdll, 释放结果, __LINE__);
	}
	//MessageBoxW(0, L"内容", L"W", 0);
	//MessageBoxA(0,  "内容",  "W", 0);
	getchar();

}

