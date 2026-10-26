int __thiscall sub_4C3A00(const char **this, _DWORD *a2)
{
  int v3; // eax
  char v4; // cl
  const char *v5; // ecx
  int v6; // ecx
  int *v7; // eax
  int v8; // eax
  char *v9; // eax
  int v10; // eax
  int v11; // ecx
  char *i; // eax
  int v13; // edx
  signed int v14; // ecx
  char *v15; // eax
  int v16; // edx
  char v17; // cl
  _DWORD *v18; // esi
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  char v24[4]; // [esp+Ch] [ebp-524h] BYREF
  CHAR FileName[32]; // [esp+10h] [ebp-520h] BYREF
  char v26[127]; // [esp+30h] [ebp-500h] BYREF
  char v27; // [esp+AFh] [ebp-481h]
  char v28[128]; // [esp+B0h] [ebp-480h] BYREF
  char v29[511]; // [esp+130h] [ebp-400h] BYREF
  char v30; // [esp+32Fh] [ebp-201h] BYREF
  char v31[512]; // [esp+330h] [ebp-200h] BYREF

  AllocateStructWithDefaultValues(v24);
  v3 = 0;
  do
  {
    v4 = byte_5D3074[v3];
    FileName[v3++] = v4;
  }
  while ( v4 );
  v5 = *this;
  if ( !*this )
    v5 = byte_5EA438;
  strcpy(v31, v5);
  v6 = strlen(v31);
  if ( v6 > 0 )
  {
    v7 = (int *)&v31[v6 - 1];
    if ( &v31[v6 - 1] >= v31 )
    {
      do
      {
        if ( *(_BYTE *)v7 == 92 )
          break;
        *(_BYTE *)v7 = 0;
        v7 = (int *)((char *)v7 - 1);
      }
      while ( v7 >= (int *)v31 );
    }
  }
  sub_565EB0(v24);
  sub_565F80(FileName, 1, (int)v31, 0);
  sub_566380(0);
  LinkedListPopFront_5f50(v24);
  while ( DirectoryEntryIterator(v24) )
  {
    v8 = ReversePathSearchForBackslashSeparator(v24);
    sub_587DD0(v26, v8, 127);
    v27 = 0;
    v9 = &v26[strlen(v26)];
    if ( v9 > v26 )
    {
      while ( *v9 != 46 )
      {
        if ( --v9 <= v26 )
          goto LABEL_15;
      }
      *v9 = 0;
    }
LABEL_15:
    v10 = DirectoryEntryIterator(v24);
    sub_587DD0(v29, v10, 511);
    v30 = 0;
    v11 = strlen(v29);
    if ( v11 > 0 )
    {
      for ( i = &v28[v11 + 127]; i >= v29; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    if ( !strlen(v29) )
      goto LABEL_54;
    v13 = 0;
    v14 = strlen(v29) - 1;
    if ( v14 < 0 )
      goto LABEL_54;
    while ( 1 )
    {
      if ( v29[v14] == 92 )
        ++v13;
      if ( v13 == 2 || !v14 )
        break;
      if ( --v14 < 0 )
        goto LABEL_54;
    }
    v15 = &v29[v14 + 1];
    v16 = v28 - &v29[v14 + 1];
    do
    {
      v17 = *v15;
      v15[v16] = *v15;
      ++v15;
    }
    while ( v17 );
    if ( v26[strlen(v28) + 127] == 92 )
      v28[strlen(v28) - 1] = 0;
    if ( sub_588410(v26, v28) )
      goto LABEL_54;
    v18 = (_DWORD *)OperatorNewNhMallocWrapper(8);
    if ( v18 )
    {
      v19 = DirectoryEntryIterator(v24);
      *v18 = 0;
      v18[1] = -1;
      StringCopyWithBufferRealloc(v19);
    }
    else
    {
      v18 = 0;
    }
    v20 = sub_566810(v29, v31);
    if ( !v20 || sub_588410(v20, v31) )
    {
      if ( v18 )
      {
        v22 = OperatorNewNhMallocWrapper(12);
        if ( v22 )
        {
          *(_DWORD *)v22 = v18;
          *(_DWORD *)(v22 + 4) = 0;
          *(_BYTE *)(v22 + 8) = 1;
        }
        else
        {
          v22 = 0;
        }
        if ( *a2 )
        {
          *(_DWORD *)(a2[1] + 4) = v22;
        }
        else
        {
          *a2 = v22;
          a2[2] = v22;
        }
        a2[1] = v22;
        goto LABEL_53;
      }
    }
    else if ( v18 )
    {
      v21 = OperatorNewNhMallocWrapper(12);
      if ( v21 )
      {
        *(_DWORD *)v21 = v18;
        *(_DWORD *)(v21 + 4) = 0;
        *(_BYTE *)(v21 + 8) = 1;
      }
      else
      {
        v21 = 0;
      }
      if ( *a2 )
      {
        *(_DWORD *)(v21 + 4) = *a2;
      }
      else
      {
        a2[1] = v21;
        a2[2] = v21;
      }
      *a2 = v21;
LABEL_53:
      ++a2[3];
    }
LABEL_54:
    LinkedListNodePeek(v24);
  }
  return LinkedListDestructorWithChildCleanup(v24);
}
