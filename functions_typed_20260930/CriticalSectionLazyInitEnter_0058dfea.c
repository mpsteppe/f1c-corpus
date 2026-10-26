void __cdecl sub_58DFEA(int a1)
{
  struct _RTL_CRITICAL_SECTION *v1; // edi

  if ( !*(&dword_5E6C80 + a1) )
  {
    v1 = (struct _RTL_CRITICAL_SECTION *)MallocWrapperForNhMalloc(24);
    if ( !v1 )
      CRTAmsgExit(0x11u);
    CriticalSectionLazyInitEnter(17);
    if ( *(&dword_5E6C80 + a1) )
    {
      sub_58AA6F(v1);
    }
    else
    {
      InitializeCriticalSection(v1);
      *(&dword_5E6C80 + a1) = v1;
    }
    CritSectLeave(17);
  }
  EnterCriticalSection(*(&dword_5E6C80 + a1));
}

