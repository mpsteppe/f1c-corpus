void __cdecl __noreturn __crtExitProcess(UINT uExitCode)
{
  HMODULE ModuleHandleA; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleA = GetModuleHandleA("mscoree.dll");
  if ( ModuleHandleA )
  {
    CorExitProcess = GetProcAddress(ModuleHandleA, "CorExitProcess");
    if ( CorExitProcess )
      ((void (__stdcall *)(UINT))CorExitProcess)(uExitCode);
  }
  ExitProcess(uExitCode);
}
