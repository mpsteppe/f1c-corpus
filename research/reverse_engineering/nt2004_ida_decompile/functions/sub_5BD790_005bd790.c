int __cdecl sub_5BD790(int *a1, int *a2)
{
  int v2; // esi
  __int16 v3; // fps
  double v4; // st7
  bool v5; // c0
  char v6; // c2
  bool v7; // c3
  double v9; // [esp+4h] [ebp-8h]

  v2 = *a2;
  v9 = sub_5BA1E0(*a1, *(_DWORD *)(dword_7FEFE0 + 1160), 0.0);
  v4 = v9 - sub_5BA1E0(v2, *(_DWORD *)(dword_7FEFE0 + 1160), 0.0);
  if ( !*(_DWORD *)(dword_7FEFE0 + 1164) )
    v4 = -v4;
  v5 = v4 < 0.0;
  v6 = 0;
  v7 = v4 == 0.0;
  if ( (v3 & 0x4100) == 0 )
    return 1;
  if ( v4 >= 0.0 )
    return 0;
  return -1;
}
