int __stdcall sub_67B06D(int a1, void *a2, void *a3)
{
  int v3; // edi
  int v4; // esi
  int result; // eax
  int v6; // edx
  int v7; // esi
  _BYTE v8[64]; // [esp+Ch] [ebp-40h] BYREF

  v3 = 0;
  if ( a2 )
    sub_67A097(a1, a2);
  if ( a3 )
    sub_67A097(a1, a3);
  sub_6B72A2(a1, *(void **)(a1 + 156));
  sub_6B72A2(a1, *(void **)(a1 + 220));
  sub_6B72A2(a1, *(void **)(a1 + 216));
  sub_6B72A2(a1, *(void **)(a1 + 372));
  sub_6B72A2(a1, *(void **)(a1 + 376));
  sub_6B72A2(a1, *(void **)(a1 + 312));
  if ( (*(_BYTE *)(a1 + 93) & 0x10) != 0 )
    sub_67A02E(a1, *(void **)(a1 + 260));
  if ( (*(_BYTE *)(a1 + 93) & 0x20) != 0 )
    sub_6B72A2(a1, *(void **)(a1 + 348));
  if ( *(_DWORD *)(a1 + 324) )
  {
    v4 = 1 << (8 - *(_BYTE *)(a1 + 300));
    if ( v4 > 0 )
    {
      do
        sub_6B72A2(a1, *(void **)(*(_DWORD *)(a1 + 324) + 4 * v3++));
      while ( v3 < v4 );
    }
    sub_6B72A2(a1, *(void **)(a1 + 324));
  }
  sub_6B98E8(a1 + 100);
  result = *(_DWORD *)(a1 + 72);
  v6 = *(_DWORD *)(a1 + 64);
  qmemcpy(v8, (const void *)a1, sizeof(v8));
  v7 = *(_DWORD *)(a1 + 68);
  memset((void *)a1, 0, 0x19Cu);
  *(_DWORD *)(a1 + 68) = v7;
  qmemcpy((void *)a1, v8, 0x40u);
  *(_DWORD *)(a1 + 64) = v6;
  *(_DWORD *)(a1 + 72) = result;
  return result;
}
