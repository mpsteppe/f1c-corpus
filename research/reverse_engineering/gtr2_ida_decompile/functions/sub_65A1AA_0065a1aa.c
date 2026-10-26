int __usercall sub_65A1AA@<eax>(int a1@<ecx>, char a2@<bl>)
{
  _DWORD *v3; // edi
  int result; // eax
  unsigned int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // edi
  CHAR FileName[260]; // [esp+8h] [ebp-218h] BYREF
  CHAR Buffer[260]; // [esp+10Ch] [ebp-114h] BYREF
  LPSTR FilePart; // [esp+210h] [ebp-10h] BYREF
  int v14; // [esp+214h] [ebp-Ch]
  int v15; // [esp+218h] [ebp-8h]
  LPCSTR lpFileName; // [esp+21Ch] [ebp-4h]

  v3 = (_DWORD *)(a1 + 632);
  result = sub_65E7A1(*(_DWORD *)(a1 + 664) | 0xC, a1 + 632);
  v5 = 0;
  if ( result >= 0 )
  {
    if ( *v3 == 10 )
    {
      v15 = 0;
    }
    else
    {
      if ( *v3 != 11 )
      {
        sub_65A0B7((_DWORD *)a1, "syntax error");
        return -2147467259;
      }
      v15 = 1;
    }
    v6 = *(_DWORD *)(a1 + 624);
    lpFileName = *(LPCSTR *)(a1 + 640);
    if ( !v6 && !*(_DWORD *)(*(_DWORD *)(a1 + 620) + 24) )
    {
      sub_65DD1F(a1 + 24, a1 + 632, 1505, "include interface required to support #include from resource or memory", a2);
LABEL_15:
      *(_DWORD *)(a1 + 72) = 1;
      *(_DWORD *)(a1 + 68) = 1;
      return -2147467259;
    }
    v7 = *(_DWORD *)(a1 + 616);
    if ( v7 )
    {
      do
      {
        v7 = *(_DWORD *)(v7 + 108);
        ++v5;
      }
      while ( v7 );
      if ( v5 >= 0x20 )
      {
        sub_65DD1F(a1 + 24, a1 + 632, 1506, "too many nested #includes", a2);
        goto LABEL_15;
      }
    }
    if ( !v6 )
    {
      GetFullPathNameA(lpFileName, 0x104u, Buffer, &FilePart);
      if ( strcmp(lpFileName, Buffer) )
      {
        sub_632041((int)FileName, 260, "%s%s", *(const char **)(*(_DWORD *)(a1 + 616) + 96), lpFileName);
        GetFullPathNameA(FileName, 0x104u, Buffer, &FilePart);
      }
      lpFileName = Buffer;
    }
    v8 = *(_DWORD *)(a1 + 616);
    if ( v8 && *(_DWORD *)(v8 + 88) )
      v14 = *(_DWORD *)(v8 + 100);
    else
      v14 = 0;
    v9 = operator new(0x70u);
    if ( v9 )
      v10 = sub_659CD8(v9);
    else
      v10 = 0;
    if ( v10 )
    {
      v15 = sub_659D87((int)v10, (LPCWCH)lpFileName, 0, a1, a1 + 632, a1 + 24, *(_DWORD *)(a1 + 624), v15, v14);
      if ( v15 >= 0 )
      {
        v10[27] = *(_DWORD *)(a1 + 616);
        *(_DWORD *)(a1 + 616) = v10;
        return 0;
      }
      else
      {
        *(_DWORD *)(a1 + 72) = 1;
        *(_DWORD *)(a1 + 68) = 1;
        sub_659D66(v10, 1);
        return v15;
      }
    }
    else
    {
      return -2147024882;
    }
  }
  return result;
}
