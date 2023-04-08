#pragma once
class 整数字符串相互转化
{
};
void 字节数组转字符串(IN BYTE* 数组, int 长度, OUT char* 返回16进制字符串);
//void 字节数组转字符串(IN BYTE* 数组, int 长度, OUT char* 返回16进制字符串 /*清0*/);
void 字符串转字节数组(IN char* hex进制字符串, OUT BYTE* 数组, int 数组长度);