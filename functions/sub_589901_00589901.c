LPCSTR __cdecl sub_589901(CHAR *lpSrcStr)
{
  LPCSTR result; // eax
  CHAR *j; // edx
  char v3; // cl
  CHAR *i; // edx
  char v5; // cl
  int v6; // eax
  int v7; // ebx
  CHAR *v8; // eax
  CHAR *lpMem; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]

  lpMem = 0;
  if ( dword_8D3F38 )
  {
    InterlockedIncrement(&dword_8D5A5C);
    if ( dword_8D5A58 )
    {
      InterlockedDecrement(&dword_8D5A5C);
      CriticalSectionLazyInitEnter(19);
      v10 = 1;
    }
    else
    {
      v10 = 0;
    }
    if ( dword_8D3F38 )
    {
      v6 = sub_591FA1(dword_8D3F38, 0x200u, lpSrcStr, -1, 0, 0, 0, 1);
      v7 = v6;
      if ( v6 )
      {
        v8 = (CHAR *)MallocWrapperForNhMalloc(v6);
        lpMem = v8;
        if ( v8 )
        {
          if ( sub_591FA1(dword_8D3F38, 0x200u, lpSrcStr, -1, v8, v7, 0, 1) )
            sub_58FCA0(lpSrcStr);
        }
      }
      if ( v10 )
        CritSectLeave(19);
      else
        InterlockedDecrement(&dword_8D5A5C);
      sub_58AA6F(lpMem);
      return lpSrcStr;
    }
    else
    {
      if ( v10 )
        CritSectLeave(19);
      else
        InterlockedDecrement(&dword_8D5A5C);
      result = lpSrcStr;
      for ( i = lpSrcStr; *i; ++i )
      {
        v5 = *i;
        if ( *i >= 97 && v5 <= 122 )
          *i = v5 - 32;
      }
    }
  }
  else
  {
    result = lpSrcStr;
    for ( j = lpSrcStr; *j; ++j )
    {
      v3 = *j;
      if ( *j >= 97 && v3 <= 122 )
        *j = v3 - 32;
    }
  }
  return result;
}
