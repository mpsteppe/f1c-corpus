int __cdecl doexit(UINT uExitCode, int a2, int a3)
{
  HANDLE CurrentProcess; // eax
  void (**v4)(void); // esi

  _lockexit();
  if ( dword_7FF158 == 1 )
  {
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(CurrentProcess, uExitCode);
  }
  dword_7FF154 = 1;
  byte_7FF150 = a3;
  if ( !a2 )
  {
    if ( dword_801514 )
    {
      v4 = (void (**)(void))(dword_801510 - 4);
      if ( dword_801510 - 4 >= (unsigned int)dword_801514 )
      {
        do
        {
          if ( *v4 )
            (*v4)();
          --v4;
        }
        while ( v4 >= dword_801514 );
      }
    }
    _initterm(&dword_5FB460, &dword_5FB468);
  }
  _initterm(&dword_5FB46C, &dword_5FB474);
  if ( !a3 )
  {
    dword_7FF158 = 1;
    ExitProcess(uExitCode);
  }
  return _unlockexit();
}
