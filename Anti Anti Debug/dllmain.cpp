#include "pch.h"
#include "peb.h"

void start() {
    MessageBoxW(0, L"Bypassing PEB", L"Anti Anti-Debugging", MB_OK);
    peb::bypass();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(start), 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

