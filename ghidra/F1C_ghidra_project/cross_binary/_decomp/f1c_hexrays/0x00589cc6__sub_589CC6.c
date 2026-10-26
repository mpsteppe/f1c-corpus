// f1c  0x00589cc6  size=163
int __cdecl sub_589CC6(UINT uExitCode, int a2, int a3)
{
  HANDLE CurrentProcess; // eax
  void (**v4)(void); // esi

  sub_589D6B();
  if ( dword_8D3EB0 == 1 )
  {
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(CurrentProcess, uExitCode);
  }
  dword_8D3EAC = 1;
  byte_8D3EA8 = a3;
  if ( !a2 )
  {
    if ( dword_8D5A54 )
    {
      v4 = (void (**)(void))(dword_8D5A50 - 4);
      if ( dword_8D5A50 - 4 >= (unsigned int)dword_8D5A54 )
      {
        do
        {
          if ( *v4 )
            (*v4)();
          --v4;
        }
        while ( v4 >= dword_8D5A54 );
      }
    }
    sub_589D7D(&unk_5BE3DC, &unk_5BE3E4);
  }
  sub_589D7D(&unk_5BE3E8, &unk_5BE3F0);
  if ( !a3 )
  {
    dword_8D3EB0 = 1;
    ExitProcess(uExitCode);
  }
  return sub_589D74();
}
