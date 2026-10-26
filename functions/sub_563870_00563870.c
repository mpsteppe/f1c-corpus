int __fastcall sub_563870(int a1, int a2, int a3)
{
  int v5; // eax
  int v6; // eax
  int v7; // ebp
  int v9; // eax
  int v10; // eax
  int v11; // ebp
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  _BYTE v17[13]; // [esp+1h] [ebp-4Dh]
  _BYTE v18[64]; // [esp+Eh] [ebp-40h] BYREF

  v5 = *(_DWORD *)(a1 + 1460);
  if ( !v5 )
  {
    v16 = PathBackslashCounter(3);
    v11 = v16;
    if ( v16 == -1 )
      return 0;
    if ( v16 < 12 )
      return -1;
    sub_587DD0(v18, a2 + 12, v16 - 12);
    v17[v11] = 0;
    dword_8CFA88 = SingleFunctionCallWrapper_7f59(v18);
    if ( dword_8CFA88 > 20 )
      return -1;
    *(_DWORD *)(a1 + 1460) = 1;
    if ( dword_8CFA88 > 0 )
      memset(dword_8CFA90, 0, 4 * dword_8CFA88);
    return v11 - 1;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    v10 = PathBackslashCounter(2);
    v11 = v10;
    if ( v10 == -1 )
      return 0;
    sub_587DD0(v18, a2 + 1, v10 - 2);
    v17[v11 + 11] = 0;
    v12 = StringMallocCopy(v18);
    v13 = *(_DWORD *)(a1 + 148);
    a3 = v12;
    FunctionPointerCallWithErrorHandling(v13, &a3);
    v14 = 0;
    if ( dword_8CFA88 <= 0 )
      return -1;
    while ( dword_8CFA90[v14] )
    {
      if ( ++v14 >= dword_8CFA88 )
        return -1;
    }
    v15 = dword_8CFA88 - 1;
    dword_8CFA90[v14] = a3;
    if ( v14 == v15 )
    {
      *(_DWORD *)(a1 + 1460) = 2;
      return v11 - 1;
    }
    return v11 - 1;
  }
  if ( v6 != 1 )
    return -1;
  v7 = PathBackslashCounter(dword_8CFA88 + 1);
  if ( v7 == -1 )
    return 0;
  v9 = QueryWithContextCleanup(dword_8CFA88, a2, *(_DWORD *)(a1 + 144));
  *(_BYTE *)(a2 + v7 - 1) = 92;
  (*(void (__cdecl **)(int, int, _DWORD, int, _DWORD))(a1 + 120))(a1, 2, *(_DWORD *)(a1 + 124), v9, 0);
  return v7 - 1;
}
