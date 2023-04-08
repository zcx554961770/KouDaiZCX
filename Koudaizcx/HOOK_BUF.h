#pragma once

#include "整数字符串相互转化.h"
bool __stdcall Hook取包内容(UINT_PTR 包地址, int 包长度);
bool naked_Hook取包内容(UINT_PTR 包地址, int 包长度);
//把包内容格式化转换成字符串 显示出来
void 追加行(char* csLine);