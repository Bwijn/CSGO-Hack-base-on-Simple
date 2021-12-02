#pragma once

//extern BYTE d3d9Device_42_bytes[7];
bool HookBytes(char* src, char* dst, int len, byte* stolen_bytes);


char* TrampHook(char* src, char* dst, unsigned int len);
void unhook(char* src, char* dst, unsigned int len);


