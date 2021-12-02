#pragma once
#include"pch.h"

bool vmtf_hook::setup(void* class_ptr) {


	if (class_ptr != nullptr && class_ptr != 0)
	{
		//m_class_pointer = (void***)class_ptr;
	
		m_old_vmt = *static_cast<void***>(class_ptr);

		//m_new_vmt = (*(void***)class_ptr);
		this->vFunc_num = estimate_vftbl_length((uintptr_t**)m_old_vmt);

		m_new_vmt = new void* [vFunc_num];


		if ( vFunc_num > 0)
		{
			memcpy(m_new_vmt, m_old_vmt, sizeof(void*) * vFunc_num);//±£´æ

		}

		*(void***)class_ptr=m_new_vmt;


		return true;
	}
	return false;



}





std::size_t vmtf_hook::estimate_vftbl_length(std::uintptr_t** vftbl_start)
{
	MEMORY_BASIC_INFORMATION memInfo = { NULL };
	int m_nSize = 0;
	do {
		m_nSize++;
		VirtualQuery(reinterpret_cast<LPCVOID>(vftbl_start[m_nSize]), &memInfo, sizeof(memInfo));

	} while (memInfo.Protect == PAGE_EXECUTE_READ || memInfo.Protect == PAGE_EXECUTE_READWRITE);

	return m_nSize;
}



bool vmtf_hook::d3d9GetpDevice() {

	return false;
};

