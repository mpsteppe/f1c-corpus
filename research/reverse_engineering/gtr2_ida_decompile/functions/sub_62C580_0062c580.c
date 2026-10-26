int __fastcall sub_62C580(_DWORD *a1, int a2, _BYTE *a3, int a4)
{
  bool v6; // zf
  int v7; // eax

  if ( !a3 || *a3 != 49 || a4 != 56 )
    return -6;
  if ( !a1 )
    return -2;
  v6 = a1[8] == 0;
  a1[6] = 0;
  if ( v6 )
  {
    a1[8] = &sub_62CBD0;
    a1[10] = 0;
  }
  if ( !a1[9] )
    a1[9] = &sub_62CBF0;
  v7 = ((int (__fastcall *)(_DWORD, int, int))a1[8])(a1[10], 1, 24);
  a1[7] = v7;
  if ( !v7 )
    return -4;
  *(_DWORD *)(v7 + 20) = 0;
  *(_DWORD *)(a1[7] + 12) = 0;
  if ( a2 < 0 )
  {
    a2 = -a2;
    *(_DWORD *)(a1[7] + 12) = 1;
  }
  if ( a2 < 8 || a2 > 15 )
  {
    sub_62C540(a1);
    return -2;
  }
  *(_DWORD *)(a1[7] + 16) = a2;
  *(_DWORD *)(a1[7] + 20) = sub_62E780(1 << a2);
  if ( !*(_DWORD *)(a1[7] + 20) )
  {
    sub_62C540(a1);
    return -4;
  }
  sub_62C500(a1);
  return 0;
}
