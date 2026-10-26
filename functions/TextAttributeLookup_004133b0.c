int __stdcall sub_4133B0(int a1, int a2, int a3, char a4)
{
  int v4; // eax
  int v5; // esi
  char *v6; // eax
  const char *v7; // eax

  v4 = LinkedListIndexedAccessor_5680(a3);
  if ( v4 )
  {
    if ( a2 )
    {
      if ( a2 != 1 )
        goto LABEL_11;
      v5 = v4 + 92;
      if ( !a4 )
        v5 = v4 + 112;
    }
    else
    {
      v5 = v4 + 12;
      if ( !a4 )
        v5 = v4 + 32;
    }
    v6 = *(char **)v5;
    if ( !*(_DWORD *)v5 )
      v6 = &byte_5EA438;
    StringCopyWithBufferRealloc(v6);
    *(_DWORD *)(a1 + 8) = *(_DWORD *)(v5 + 8);
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v5 + 12);
    *(_BYTE *)(a1 + 16) = *(_BYTE *)(v5 + 16);
  }
LABEL_11:
  StringCopyWithBufferRealloc(&byte_5EA438);
  v7 = *(const char **)a1;
  if ( !*(_DWORD *)a1 )
    v7 = &byte_5EA438;
  if ( !strcmp(v7, &byte_5EA438) && *(_DWORD *)(a1 + 8) == -1 && *(_DWORD *)(a1 + 12) == -1 && !*(_BYTE *)(a1 + 16) )
    return -1;
  else
    return 1;
}
