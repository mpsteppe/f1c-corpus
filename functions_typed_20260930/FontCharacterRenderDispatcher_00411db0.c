int __stdcall sub_411DB0(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v6; // ebx
  int v8; // ebx
  int v9; // ebx
  char *v10; // eax
  int v11; // edi

  v5 = *(_DWORD *)(a2 + 8);
  if ( v5 == 9875 )
  {
    if ( a5 == 397 || a5 == 426 )
    {
      v6 = sub_412490(a4, 1, *(_DWORD *)(a3 + 20), 0, 0);
      DecrementCounterWithFloorAtZero(a4);
      return v6;
    }
    return -1;
  }
  if ( v5 == 9876 )
  {
    if ( a5 > 0 && a5 <= 2 )
    {
      v8 = EnumValueTranslation(a4, *(_DWORD *)(a3 + 20));
      DecrementCounterWithFloorAtZero(a4);
      return v8;
    }
    return -1;
  }
  v9 = GlobalFieldSelectorByIndex(a1);
  if ( v9 < 0 )
    return -1;
  v10 = *(char **)a2;
  if ( !*(_DWORD *)a2 )
    v10 = &byte_5EA438;
  v11 = *(_DWORD *)(a2 + 8);
  StringCopyWithBufferRealloc(v10);
  *(_DWORD *)(a4 + 8) = v11;
  *(_DWORD *)(a4 + 12) = v9;
  *(_BYTE *)(a4 + 16) = 0;
  return 1;
}

