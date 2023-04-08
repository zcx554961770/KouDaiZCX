#include "pch.h"
#include "内存读写.h"
DWORD 内存读写::R4(UINT_PTR BASE)
{
	// TODO: 在此处添加实现代码.
	return *(DWORD*)BASE;
}
float 内存读写::R4F(UINT_PTR BASE)
{
	// TODO: 在此处添加实现代码.
	return *(float*)BASE;
}

