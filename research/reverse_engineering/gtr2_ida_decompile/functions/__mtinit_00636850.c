int _mtinit()
{
  HMODULE ModuleHandleA; // eax
  HMODULE v1; // edi
  DWORD *v2; // eax
  DWORD *v3; // esi
  DWORD CurrentThreadId; // eax

  if ( !_mtinitlocks() )
    goto LABEL_9;
  ModuleHandleA = GetModuleHandleA("kernel32.dll");
  v1 = ModuleHandleA;
  if ( ModuleHandleA )
  {
    FlsAlloc = (DWORD (__stdcall *)(PFLS_CALLBACK_FUNCTION))GetProcAddress(ModuleHandleA, "FlsAlloc");
    FlsGetValue = (PVOID (__stdcall *)(DWORD))GetProcAddress(v1, "FlsGetValue");
    FlsSetValue = (BOOL (__stdcall *)(DWORD, PVOID))GetProcAddress(v1, "FlsSetValue");
    FlsFree = (BOOL (__stdcall *)(DWORD))GetProcAddress(v1, "FlsFree");
    if ( !FlsGetValue )
    {
      FlsGetValue = TlsGetValue;
      FlsSetValue = TlsSetValue;
      FlsAlloc = (DWORD (__stdcall *)(PFLS_CALLBACK_FUNCTION))__crtTlsAlloc;
      FlsFree = TlsFree;
    }
  }
  dword_912CA0 = FlsAlloc((PFLS_CALLBACK_FUNCTION)_freefls);
  if ( dword_912CA0 != -1 && (v2 = (DWORD *)calloc(1u, 0x8Cu), (v3 = v2) != 0) && FlsSetValue(dword_912CA0, v2) )
  {
    v3[21] = (DWORD)&unk_913618;
    v3[5] = 1;
    CurrentThreadId = GetCurrentThreadId();
    v3[1] = -1;
    *v3 = CurrentThreadId;
    return 1;
  }
  else
  {
LABEL_9:
    _mtterm();
    return 0;
  }
}
