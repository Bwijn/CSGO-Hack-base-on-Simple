#pragma once
#include"pch.h"

class vmtf_hook {

public:
	//vmtf_hook() {};

	bool	setup(void* class_ptr);

	template<typename fn>
	bool hookByIndex(uintptr_t index, fn hkFunc) {
		if (index > this->vFunc_num)
			return false;


		SIZE_T ulOldProtect = 0;
		VirtualProtect(&m_new_vmt[index], sizeof(void*), PAGE_EXECUTE_READWRITE, &ulOldProtect);
		auto address = m_new_vmt[index];//调试看地址用的 实际没用的语句
		m_new_vmt[index] = hkFunc;//hkFunc;
		VirtualProtect(&m_new_vmt[index], sizeof(void*), ulOldProtect, &ulOldProtect);

		return true;
	}

	template<typename T>
	T get_original(int index)
	{
		return (T)m_old_vmt[index];
	}

	template<typename T>
	T get_original_byDetours()
	{
		return (T)oFunc;
	}

	std::size_t	estimate_vftbl_length(std::uintptr_t** vftbl_start);

	template<typename T>
	T hookByDetours(char* dst, int index, int len) {
		stolen_bytes = new byte[len];
		auto oFunc = (T)::TrampHook((char*)m_new_vmt[index], (char*)dst, len);
		::HookBytes((char*)m_new_vmt[index], dst, len, stolen_bytes);
		this->oFunc = oFunc;
		return oFunc;


	};

private:
	bool d3d9GetpDevice();

	byte* stolen_bytes = nullptr;
	void* oFunc=nullptr;

	void*** m_class_pointer = nullptr;
	void** m_old_vmt = nullptr;
	void** m_new_vmt = nullptr;
	uintptr_t vFunc_num = 0;


};


//class  
