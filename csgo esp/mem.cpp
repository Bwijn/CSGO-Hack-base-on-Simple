//#include "stdafx.h"
//#include "mem.h"
#include"pch.h"
//BYTE d3d9Device_42_bytes[7] ;

 bool HookBytes(char* src, char* dst, int len,byte*stolen_bytes)
{
	if (len < 5) return false;

	DWORD curProtection;

	VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &curProtection);

	//��Ҫstolen �ļ����ֽڸ��Ƴ������ݣ��Ժ�Ҫunhook��
	memcpy(stolen_bytes, src, len);
	memset(src, 0x90, len);// 0x90 = nop �⼸���ֽ�ȫ����Nop���

	uintptr_t relativeAddress = (uintptr_t)(dst- src - 5);//����jmp�ĵ�ַ relativeAddress


	//��ԭ����ͷ�����ֽڻ��� '��ת�������Լ��ĺ�����' �����ֽ� Example : jmp xxxx | 0xE9 xx xx xx xx
	*src = (char)0xE9; //
	*(uintptr_t*)(src + 1) = (uintptr_t)relativeAddress; // jmp E9 Ӳ�������ĵ�ַ

	DWORD temp;
	VirtualProtect(src, len, curProtection, &temp);

	return true;
}

char* TrampHook(char* src, char* dst, unsigned int len)
{
	if (len < 5) return 0;

	// Create the gateway (len + 5 for the overwritten bytes + the jmp)
	char* gateway = (char*)VirtualAlloc(0, len + 5, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	// Put the bytes that will be overwritten in the gateway
	memcpy(gateway, src, len);

	// Get the gateway to destination addy   ����jmp ����ת��ַ jmp ����ĵ�ַ = ����Ҫ��ת�ĵ�ַ-��E8����ָ��ĵ�ַ+5��
	uintptr_t gateJmpAddy = (uintptr_t)(src - gateway - 5);

	// Add the jmp opcode to the end of the gateway
	*(gateway + len) = (char)0xE9; //��Ϊjmp xxxx �������һ����,������gateway + len

	// Add the address to the jmp
	*(uintptr_t*)(gateway + len + 1) = gateJmpAddy;

	// Place the hook at the destination
	//if (Hook(src, dst, len))
	//{
		return gateway;
	//}
	//else return nullptr;
}

void unhook(char* src, char* dst, unsigned int len) {
	//HMODULE  hmodule = GetModuleHandle(L"csgo esp.dll");
	//if (hmodule) {// ������null �ͳɹ�
	//	FreeLibraryAndExitThread(hmodule, 0);

	//};
	//�ָ�hook
	//int src_size =sizeof(d3d9Device_42_bytes);
	DWORD oldProtect = 0x0, temp = 0x0;
	VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &oldProtect);

	//memcpy(src,dst, sizeof(d3d9Device_42_bytes));


	VirtualProtect(src, len, oldProtect, &temp);

	
	//FreeLibraryAndExitThread(hModule, 0);
}