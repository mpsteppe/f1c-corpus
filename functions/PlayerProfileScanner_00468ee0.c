int __thiscall sub_468EE0(_DWORD *this, int a2)
{
  int v3; // esi
  LPVOID **v4; // edi
  bool v5; // zf
  char *v6; // eax
  const char *i; // eax
  const char *v8; // ecx
  int v9; // eax
  char v10; // cl
  int v11; // ecx
  char *v12; // eax
  int v13; // eax
  char v14; // cl
  int v15; // eax
  char *j; // eax
  _DWORD *v17; // esi
  int v18; // eax
  char v20[1024]; // [esp+14h] [ebp-800h] BYREF
  char v21[1024]; // [esp+414h] [ebp-400h] BYREF

  LinkedListDestructionWithVTableCall();
  v3 = this[273];
  while ( v3 )
  {
    v4 = (LPVOID **)v3;
    v5 = *(_BYTE *)(v3 + 8) == 0;
    v3 = *(_DWORD *)(v3 + 4);
    if ( !v5 && *v4 )
      ConditionalFreeWithBit0Flag(*v4, 1);
    FreeWrapper_7bcf(v4);
  }
  this[273] = 0;
  this[274] = 0;
  this[275] = 0;
  this[276] = 0;
  v6 = (char *)dword_5EC440;
  if ( !dword_5EC440 )
    v6 = byte_5EA438;
  sub_565F80(aPlr_0, 1, (int)v6, 1);
  sub_566380(2);
  for ( i = (const char *)DirectoryEntryIterator(&unk_8AD3B0); i; i = (const char *)DirectoryEntryIterator(&unk_8AD3B0) )
  {
    v8 = (const char *)dword_5EC440;
    if ( !dword_5EC440 )
      v8 = byte_5EA438;
    StringFormatWithBufferOverflowCheck(v21, "%s%s", v8, i);
    v9 = 0;
    do
    {
      v10 = v21[v9];
      v20[v9++] = v10;
    }
    while ( v10 );
    v11 = strlen(v20);
    if ( v11 > 0 )
    {
      v12 = &v20[v11];
      while ( v12 >= v20 )
      {
        if ( *v12 == 92 )
          break;
        *v12 = 0;
        if ( v12 > v20 )
          --v12;
      }
    }
    if ( BinarySearchInStringTable(byte_5EC4C0, aProfileiconBmp, byte_5EC4CC) )
    {
      v13 = 0;
      do
      {
        v14 = aProfileiconBmp[v13];
        byte_5EC4CC[v13++] = v14;
      }
      while ( v14 );
    }
    strcat(v20, byte_5EC4CC);
    v15 = sub_497AD0(v20, 0);
    if ( !v15 )
      v15 = sub_497AD0(aProfileiconDft, 0);
    LinkedListNodeAppend(v15);
    for ( j = &v21[strlen(v21)]; j > v21; --j )
    {
      if ( *j == 92 )
        break;
    }
    v17 = (_DWORD *)OperatorNewNhMallocWrapper(8);
    if ( v17 )
    {
      *v17 = 0;
      v17[1] = -1;
      StringCopyWithBufferRealloc(v21);
      v18 = OperatorNewNhMallocWrapper(12);
      if ( v18 )
      {
        *(_DWORD *)v18 = v17;
        *(_DWORD *)(v18 + 4) = 0;
        *(_BYTE *)(v18 + 8) = 1;
      }
      else
      {
        v18 = 0;
      }
      if ( this[273] )
      {
        *(_DWORD *)(this[274] + 4) = v18;
      }
      else
      {
        this[273] = v18;
        this[275] = v18;
      }
      this[274] = v18;
      ++this[276];
    }
    LinkedListNodePeek(&unk_8AD3B0);
  }
  sub_565EB0(&unk_8AD3B0);
  if ( (int)this[276] <= 0 )
    this[275] = 0;
  else
    this[275] = this[273];
  return SetupFileLoadAndFinalize(this);
}
