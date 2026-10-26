int __stdcall sub_4122C0(int a1, int a2, int a3, char a4, char a5)
{
  int v5; // eax
  int v6; // ebx
  int v7; // ecx
  int v8; // esi
  char *v9; // eax
  const char *v10; // eax
  int v11; // eax
  int v14; // [esp+10h] [ebp-1Ch]
  char v15; // [esp+38h] [ebp+Ch]

  v14 = -1;
  v5 = LinkedListIndexedAccessor(a3);
  v6 = 0;
  v15 = 0;
  if ( v5 )
  {
    if ( !dword_7D0398 && (*(_BYTE *)(v5 + 12) || dword_7D0410 == 5) )
    {
      v7 = dword_8AC394 + 1060 * *(_DWORD *)(v5 + 8);
      if ( v7 )
      {
        v6 = v7 + 124;
        v15 = 1;
        goto LABEL_22;
      }
    }
    if ( a2 )
    {
      if ( a2 != 1 )
        goto LABEL_22;
      if ( a5 )
      {
        v8 = v5 + 96;
        if ( !a4 )
          v8 = v5 + 116;
      }
      else
      {
        v8 = v5 + 136;
        if ( !a4 )
          v8 = v5 + 156;
      }
    }
    else if ( a5 )
    {
      v8 = v5 + 16;
      if ( !a4 )
        v8 = v5 + 36;
    }
    else
    {
      v8 = v5 + 56;
      if ( !a4 )
        v8 = v5 + 76;
    }
    v9 = *(char **)v8;
    if ( !*(_DWORD *)v8 )
      v9 = &byte_5EA438;
    StringCopyWithBufferRealloc(v9);
    *(_DWORD *)(a1 + 8) = *(_DWORD *)(v8 + 8);
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v8 + 12);
    *(_BYTE *)(a1 + 16) = *(_BYTE *)(v8 + 16);
  }
LABEL_22:
  StringCopyWithBufferRealloc(&byte_5EA438);
  v10 = *(const char **)a1;
  if ( !*(_DWORD *)a1 )
    v10 = &byte_5EA438;
  if ( strcmp(v10, &byte_5EA438) || *(_DWORD *)(a1 + 8) != -1 || *(_DWORD *)(a1 + 12) != -1 || *(_BYTE *)(a1 + 16) )
    return 1;
  if ( !v15 )
    return v14;
  v11 = LinkedListIndexScannerWithValidation(v6);
  return TextAttributeLookup_34d0(a1, a2, v11, a4);
}

