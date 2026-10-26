void __cdecl _lock(int a1)
{
  struct _RTL_CRITICAL_SECTION *v1; // edi

  if ( !*(&dword_625940 + a1) )
  {
    v1 = (struct _RTL_CRITICAL_SECTION *)malloc(0x18u);
    if ( !v1 )
      _amsg_exit(0x11u);
    _lock(17);
    if ( *(&dword_625940 + a1) )
    {
      sub_5C1B88(v1);
    }
    else
    {
      InitializeCriticalSection(v1);
      *(&dword_625940 + a1) = v1;
    }
    _unlock(17);
  }
  EnterCriticalSection(*(&dword_625940 + a1));
}
