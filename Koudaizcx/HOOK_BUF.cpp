#include "pch.h"
#include "HOOK_BUF.h"
//0067D4E0 | 6A FF | push FFFFFFFF | 
//0067D4E2 | 68 085FBB00 | push <elementclient.sub_BB5F08> |
//0067D4E7 | 64:A1 00000000 | mov eax, dword ptr fs : [0] |-------------从这里jmp 因此 记录这一步
//0067D4ED | 50 | push eax |跳到这里
//0067D4EE | 64 : 8925 00000000 | mov dword ptr fs : [0] , esp |

UINT_PTR jmp地址 = 0x0067D4ED;//0067D4E2 | 68 085FBB00 | push <elementclient.sub_BB5F08> |跳到这里
bool __stdcall 原明文发包功能CALL(UINT_PTR 包地址, int 包长度)
{ // ecx 参数
	__asm
	{
		//mov ecx, 0x0D75DB8 // [0x0D75DB8]+20	
		mov ecx, dword ptr ds : [0x00D0DF1C]
		mov ecx, [ecx + 0x20]  // ecx 可能存在多个

		pop ebp
		//mov eax, dword ptr fs : [0]
		/*push 0xFFFFFFFF*/
		mov eax, dword ptr fs : [0]
		jmp jmp地址
	}//跳转到 006F6DD6
}

bool __stdcall Hook取包内容(UINT_PTR 包地址, int 包长度)  // 0CA116D0  // jmp 0CA116D0  // jmp 7B4616D0
{

	//printf("包地址=%X,包长度=%d\n",包地址,包长度); //ecx 问题出在这里 破坏了ecx的值
	//调用原有明文组包功能 bak_6F6DD0
	//bak_6F6DD0(包地址,包长度);
	return 原明文发包功能CALL(包地址, 包长度); // add esp,8
}

char HexBuf[0x1000 * 6];// 给输出的包内数据一个大的初始化
void __stdcall 输出包内容(UINT_PTR 包地址, int 包长度, UINT_PTR 返回地址)
{
	{
		UINT_PTR CALL引用地址 = 返回地址 - 5;
		memset(HexBuf, 0, 6 * 包长度);
		字节数组转字符串((byte*)包地址, 包长度, HexBuf);
		char szline[1024 * 8] = { 0 };
		sprintf_s(szline, "引用地址=%08X 包地址=%08X  长度=%03X 包内容=%s\r\n", CALL引用地址, 包地址, 包长度, HexBuf); //异步
		printf(szline);//输出到控制台
		追加行(szline);
		//ret 8
	}
}

bool __declspec(naked) naked_Hook取包内容(UINT_PTR 包地址, int 包长度)  // 0CA116D0  // jmp 0CA116D0  // jmp 7B4616D0
{
	//参数1 esp+4 参数2 esp+8  // [esp]-5 = 调用 sub_6F6DD0 引用地址
	__asm
	{ // call的下一条指令 在栈顶 [esp+4]
		push ecx //esp-4 // pushad  //esp=esp-4
		//push edx
		push dword ptr[esp + 0x0C] //参数3  call 地址
		push dword ptr[esp + 0x14 + 4] //参数2  esp+8+4*3		 
		push dword ptr[esp + 0x14 + 4] //参数1  esp+4+4*4
		call 输出包内容
		;//调用原有的发包功能
		//pop edx
		pop ecx //popad
		//恢复原有功能代码			
		//mov eax, dword ptr fs : [0]
			mov eax, dword ptr fs : [0]
			jmp jmp地址
			ret
			ret

	}
}



void 追加行(char* csLine)
{
	HWND h = g_窗口2句柄;//page2窗口句柄
	if (g_窗口2句柄) SendMessageA(h, WM_USER + 150, 0, (LPARAM)csLine);//等待page2窗口过程 处理此消息完成 才继续下一步 这样就达到同步的目的
}