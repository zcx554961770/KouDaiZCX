#include "pch.h"
#include "HOOK_BUF.h"
//0067D4E0 | 6A FF | push FFFFFFFF | 
//0067D4E2 | 68 085FBB00 | push <elementclient.sub_BB5F08> |
//0067D4E7 | 64:A1 00000000 | mov eax, dword ptr fs : [0] |-------------������jmp ��� ��¼��һ��
//0067D4ED | 50 | push eax |��������
//0067D4EE | 64 : 8925 00000000 | mov dword ptr fs : [0] , esp |

UINT_PTR jmp��ַ = 0x0067D4ED;//0067D4E2 | 68 085FBB00 | push <elementclient.sub_BB5F08> |��������
bool __stdcall ԭ���ķ�������CALL(UINT_PTR ����ַ, int ������)
{ // ecx ����
	__asm
	{
		//mov ecx, 0x0D75DB8 // [0x0D75DB8]+20	
		mov ecx, dword ptr ds : [0x00D0DF1C]
		mov ecx, [ecx + 0x20]  // ecx ���ܴ��ڶ��

		pop ebp
		//mov eax, dword ptr fs : [0]
		/*push 0xFFFFFFFF*/
		mov eax, dword ptr fs : [0]
		jmp jmp��ַ
	}//��ת�� 006F6DD6
}

bool __stdcall Hookȡ������(UINT_PTR ����ַ, int ������)  // 0CA116D0  // jmp 0CA116D0  // jmp 7B4616D0
{

	//printf("����ַ=%X,������=%d\n",����ַ,������); //ecx ����������� �ƻ���ecx��ֵ
	//����ԭ������������� bak_6F6DD0
	//bak_6F6DD0(����ַ,������);
	return ԭ���ķ�������CALL(����ַ, ������); // add esp,8
}

char HexBuf[0x1000 * 6];// ������İ�������һ����ĳ�ʼ��
void __stdcall ���������(UINT_PTR ����ַ, int ������, UINT_PTR ���ص�ַ)
{
	{
		UINT_PTR CALL���õ�ַ = ���ص�ַ - 5;
		memset(HexBuf, 0, 6 * ������);
		�ֽ�����ת�ַ���((byte*)����ַ, ������, HexBuf);
		char szline[1024 * 8] = { 0 };
		sprintf_s(szline, "���õ�ַ=%08X ����ַ=%08X  ����=%03X ������=%s\r\n", CALL���õ�ַ, ����ַ, ������, HexBuf); //�첽
		printf(szline);//���������̨
		׷����(szline);
		//ret 8
	}
}

bool __declspec(naked) naked_Hookȡ������(UINT_PTR ����ַ, int ������)  // 0CA116D0  // jmp 0CA116D0  // jmp 7B4616D0
{
	//����1 esp+4 ����2 esp+8  // [esp]-5 = ���� sub_6F6DD0 ���õ�ַ
	__asm
	{ // call����һ��ָ�� ��ջ�� [esp+4]
		push ecx //esp-4 // pushad  //esp=esp-4
		//push edx
		push dword ptr[esp + 0x0C] //����3  call ��ַ
		push dword ptr[esp + 0x14 + 4] //����2  esp+8+4*3		 
		push dword ptr[esp + 0x14 + 4] //����1  esp+4+4*4
		call ���������
		;//����ԭ�еķ�������
		//pop edx
		pop ecx //popad
		//�ָ�ԭ�й��ܴ���			
		//mov eax, dword ptr fs : [0]
			mov eax, dword ptr fs : [0]
			jmp jmp��ַ
			ret
			ret

	}
}



void ׷����(char* csLine)
{
	HWND h = g_����2���;//page2���ھ��
	if (g_����2���) SendMessageA(h, WM_USER + 150, 0, (LPARAM)csLine);//�ȴ�page2���ڹ��� �������Ϣ��� �ż�����һ�� �����ʹﵽͬ����Ŀ��
}