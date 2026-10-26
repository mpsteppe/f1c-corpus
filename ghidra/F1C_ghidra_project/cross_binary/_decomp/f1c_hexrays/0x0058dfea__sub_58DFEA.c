// f1c  0x0058dfea  size=97
void __cdecl sub_58DFEA(int a1)
{
  struct _RTL_CRITICAL_SECTION *v1; // edi

  if ( !*(&dword_5E6C80 + a1) )
  {
    v1 = (struct _RTL_CRITICAL_SECTION *)sub_58A935(24);
    if ( !v1 )
      sub_58A2A6(0x11u);
    sub_58DFEA(17);
    if ( *(&dword_5E6C80 + a1) )
    {
      sub_58AA6F(v1);
    }
    else
    {
      InitializeCriticalSection(v1);
      *(&dword_5E6C80 + a1) = v1;
    }
    sub_58E04B(17);
  }
  EnterCriticalSection(*(&dword_5E6C80 + a1));
}
