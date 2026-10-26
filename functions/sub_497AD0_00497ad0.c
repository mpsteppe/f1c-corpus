int __thiscall sub_497AD0(_DWORD *this, const char *a2, char a3)
{
  int v4; // edi
  int result; // eax
  int v7; // esi
  int v8; // eax
  int i; // eax
  const char *v10; // [esp+10h] [ebp+4h]

  v4 = 0;
  if ( !a2 )
    return 0;
  result = sub_497BA0(a2);
  if ( !result )
  {
    v10 = HashTableIDResolution(a2);
    if ( !v10 )
    {
      if ( !a3 )
        return 0;
      StringFormatWithBufferOverflowCheck(&unk_7CDE38, "Unable to load surface \"%s\"", a2);
      sub_4986D0(&unk_7CDE38);
    }
    v7 = this[65];
    v8 = OperatorNewNhMallocWrapper(20);
    if ( v8 )
    {
      *(_DWORD *)(v8 + 4) = 0;
      *(_DWORD *)(v8 + 8) = -1;
      *(_DWORD *)(v8 + 12) = 0;
      *(_DWORD *)(v8 + 16) = 0;
      *(_BYTE *)v8 = 1;
      v4 = v8;
    }
    *(_DWORD *)(v4 + 12) = v10;
    StringCopyWithBufferRealloc(a2);
    if ( v7 )
    {
      for ( i = *(_DWORD *)(v7 + 16); i; i = *(_DWORD *)(i + 16) )
        v7 = i;
      *(_DWORD *)(v7 + 16) = v4;
    }
    else
    {
      this[65] = v4;
    }
    ++this[66];
    return v4;
  }
  return result;
}
