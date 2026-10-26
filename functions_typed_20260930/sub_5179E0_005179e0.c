int __cdecl sub_5179E0(_DWORD *a1, int a2, _BYTE *a3, int a4)
{
  bool v4; // zf
  int v5; // eax
  int v6; // ecx
  int v7; // edi
  int v10; // [esp-4h] [ebp-10h]

  if ( !a3 || *a3 != 49 || a4 != 56 )
    return -6;
  if ( !a1 )
    return -2;
  v4 = a1[8] == 0;
  a1[6] = 0;
  if ( v4 )
  {
    a1[8] = DelegationWrapper_803a;
    a1[10] = 0;
  }
  if ( !a1[9] )
    a1[9] = FreeWrapper_9351;
  v5 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1[10], 1, 24);
  a1[7] = v5;
  if ( v5 )
  {
    v6 = a2;
    *(_DWORD *)(v5 + 20) = 0;
    *(_DWORD *)(a1[7] + 12) = 0;
    if ( a2 < 0 )
    {
      v6 = -a2;
      *(_DWORD *)(a1[7] + 12) = 1;
    }
    if ( v6 < 8 || v6 > 15 )
    {
      v10 = -2;
    }
    else
    {
      *(_DWORD *)(a1[7] + 16) = v6;
      *(_DWORD *)(a1[7] + 20) = sub_5276C5(a1, *(_DWORD *)(a1[7] + 12) == 0 ? ChecksumCRCComputation : 0, 1 << v6);
      if ( *(_DWORD *)(a1[7] + 20) )
      {
        ResourceResetWithCounter(a1);
        return 0;
      }
      v10 = -4;
    }
    v7 = v10;
    sub_5179A2(a1);
    return v7;
  }
  return -4;
}

