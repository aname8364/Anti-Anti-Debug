#pragma once
#include <Windows.h>
#include <winternl.h>

namespace peb {
	void bypassDebugged(PPEB peb);
	void bypassGlobal(PPEB peb);
	void bypassHeap(PPEB peb);

	void bypass();
}
