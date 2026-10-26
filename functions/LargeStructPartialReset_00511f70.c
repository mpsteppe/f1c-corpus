int __cdecl sub_511F70(int a1, int a2, int a3)
{
  int v3; // edi
  int v4; // esi
  int result; // eax
  int v6; // edx
  int v7; // esi
  _BYTE v8[64]; // [esp+Ch] [ebp-40h] BYREF

  v3 = 0;
  if ( a2 )
    ShortComputation_3d2f(a1, a2);
  if ( a3 )
    ShortComputation_3d2f(a1, a3);
  ConditionalCall_7ec8(a1, *(LPVOID *)(a1 + 156));
  ConditionalCall_7ec8(a1, *(LPVOID *)(a1 + 220));
  ConditionalCall_7ec8(a1, *(LPVOID *)(a1 + 216));
  ConditionalCall_7ec8(a1, *(LPVOID *)(a1 + 372));
  ConditionalCall_7ec8(a1, *(LPVOID *)(a1 + 376));
  ConditionalCall_7ec8(a1, *(LPVOID *)(a1 + 312));
  if ( (*(_BYTE *)(a1 + 93) & 0x10) != 0 )
    SafeDeleteGuardForThunkFUN00517ec8(a1, *(LPVOID *)(a1 + 260));
  if ( (*(_BYTE *)(a1 + 93) & 0x20) != 0 )
    ConditionalCall_7ec8(a1, *(LPVOID *)(a1 + 348));
  if ( *(_DWORD *)(a1 + 324) )
  {
    v4 = 1 << (8 - *(_BYTE *)(a1 + 300));
    if ( v4 > 0 )
    {
      do
        ConditionalCall_7ec8(a1, *(LPVOID *)(*(_DWORD *)(a1 + 324) + 4 * v3++));
      while ( v3 < v4 );
    }
    ConditionalCall_7ec8(a1, *(LPVOID *)(a1 + 324));
  }
  sub_5179A2(a1 + 100);
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
