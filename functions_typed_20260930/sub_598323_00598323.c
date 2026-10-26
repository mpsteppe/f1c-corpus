int __cdecl sub_598323(CHAR *lpString1, int a2)
{
  const CHAR *v2; // eax
  const CHAR *v3; // esi
  void *v4; // eax
  BOOL v5; // ebx
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  int v10; // eax
  int v11; // esi
  _DWORD *v12; // edi
  void *v13; // eax
  char *v14; // eax
  CHAR *v15; // esi
  const CHAR *v16; // eax
  void *v17; // [esp-4h] [ebp-18h]
  const CHAR *v18; // [esp+Ch] [ebp-8h]
  _DWORD *lpMem; // [esp+10h] [ebp-4h]

  if ( !lpString1 )
    return -1;
  v2 = (const CHAR *)sub_598569(lpString1, 61);
  v3 = v2;
  v18 = v2;
  if ( !v2 || lpString1 == v2 )
    return -1;
  v4 = dword_8D3E90;
  v5 = v3[1] == 0;
  if ( dword_8D3E90 == (LPVOID)dword_8D3E94 )
  {
    v4 = (void *)NullTerminatedIntArrayCopyWithAlloc(dword_8D3E90);
    dword_8D3E90 = v4;
  }
  if ( !v4 )
  {
    if ( a2 && dword_8D3E98 )
    {
      if ( WideCharMultiByteStringConversionWithAllocLoop() )
        return -1;
    }
    else
    {
      if ( v5 )
        return 0;
      v7 = (_DWORD *)MallocWrapperForNhMalloc(4);
      dword_8D3E90 = v7;
      if ( !v7 )
        return -1;
      *v7 = 0;
      if ( !dword_8D3E98 )
      {
        v8 = (_DWORD *)MallocWrapperForNhMalloc(4);
        dword_8D3E98 = (int)v8;
        if ( !v8 )
          return -1;
        *v8 = 0;
      }
    }
  }
  v9 = dword_8D3E90;
  lpMem = dword_8D3E90;
  v10 = CaseInsensitiveStringTableLookup(lpString1, v3 - lpString1);
  v11 = v10;
  if ( v10 >= 0 && *v9 )
  {
    if ( !v5 )
    {
      v9[v10] = lpString1;
      goto LABEL_31;
    }
    v17 = (void *)v9[v10];
    v12 = &v9[v10];
    sub_58AA6F(v17);
    while ( *v12 )
    {
      ++v11;
      *v12 = v12[1];
      ++v12;
    }
    v13 = sub_58B5D4(lpMem, 4 * v11);
    if ( !v13 )
    {
LABEL_31:
      if ( a2 )
      {
        v14 = Strlen(lpString1);
        v15 = (CHAR *)MallocWrapperForNhMalloc((int)(v14 + 2));
        if ( v15 )
        {
          sub_58FCA0();
          v16 = &v18[v15 - lpString1];
          *v16 = 0;
          SetEnvironmentVariableA(v15, !v5 ? v16 + 1 : 0);
          sub_58AA6F(v15);
        }
      }
      return 0;
    }
LABEL_30:
    dword_8D3E90 = v13;
    goto LABEL_31;
  }
  if ( !v5 )
  {
    if ( v10 < 0 )
      v11 = -v10;
    v13 = sub_58B5D4(v9, 4 * v11 + 8);
    if ( !v13 )
      return -1;
    *((_DWORD *)v13 + v11) = lpString1;
    *((_DWORD *)v13 + v11 + 1) = 0;
    goto LABEL_30;
  }
  return 0;
}

