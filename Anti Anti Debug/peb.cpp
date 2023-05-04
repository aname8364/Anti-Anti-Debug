#pragma once
#include "pch.h"
#include <Windows.h>
#include <winternl.h>
#include <VersionHelpers.h>
#include "peb.h"

PPEB getPEB() {
	return reinterpret_cast<PPEB>(__readgsqword(0x60));
}

void peb::bypassDebugged(PPEB peb) {
	peb->BeingDebugged = FALSE;
}

void peb::bypassGlobal(PPEB peb) {
	BYTE* byte_ptr = reinterpret_cast<BYTE*>(peb);
	DWORD* global_flags_ptr = reinterpret_cast<DWORD*>(byte_ptr + 0xBC);
	*global_flags_ptr = FALSE;
}

void peb::bypass() {
	PPEB peb = getPEB();
	peb::bypassDebugged(peb);
	peb::bypassGlobal(peb);
}