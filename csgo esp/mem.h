#pragma once

//extern BYTE d3d9Device_42_bytes[7];
bool HookBytes(char* src, char* dst, int len, byte* stolen_bytes);


bool InstallBack(void* src, void* byteList, unsigned int bytesLen);

char* TrampHook(char* src, unsigned int len);

//bool InstallBack(void* dst, void* byteList);


