//#include "stdafx.h"
//#include "mem.h"
#include"pch.h"
//BYTE d3d9Device_42_bytes[7] ;

 bool HookBytes(char* src, char* dst, int len,byte*stolen_bytes)
{
	if (len < 5) return false;

	DWORD curProtection;

	VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &curProtection);

	//将要stolen 的几个字节复制出来备份，以后要unhook用
	memcpy(stolen_bytes, src, len);
	memset(src, 0x90, len);// 0x90 = nop 这几个字节全部用Nop填充

	uintptr_t relativeAddress = (uintptr_t)(dst- src - 5);//计算jmp的地址 relativeAddress


	//把原函数头几个字节换成 '跳转到我们自己的函数的' 几个字节 Example : jmp xxxx | 0xE9 xx xx xx xx
	*src = (char)0xE9; //
	*(uintptr_t*)(src + 1) = (uintptr_t)relativeAddress; // jmp E9 硬编码后面的地址

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

	// Get the gateway to destination addy   计算jmp 的跳转地址 jmp 后跟的地址 = 真正要跳转的地址-（E8这条指令的地址+5）
	uintptr_t gateJmpAddy = (uintptr_t)(src - gateway - 5);

	// Add the jmp opcode to the end of the gateway
	*(gateway + len) = (char)0xE9; //因为jmp xxxx 是在最后一句汇编,所以是gateway + len

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
	//if (hmodule) {// 不返回null 就成功
	//	FreeLibraryAndExitThread(hmodule, 0);

	//};
	//恢复hook
	//int src_size =sizeof(d3d9Device_42_bytes);
	DWORD oldProtect = 0x0, temp = 0x0;
	VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &oldProtect);

	//memcpy(src,dst, sizeof(d3d9Device_42_bytes));


	VirtualProtect(src, len, oldProtect, &temp);

	
	//FreeLibraryAndExitThread(hModule, 0);
}