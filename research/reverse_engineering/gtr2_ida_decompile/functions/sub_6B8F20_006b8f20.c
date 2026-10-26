int __stdcall sub_6B8F20(int *a1, int a2)
{
  int v2; // esi
  unsigned int v3; // eax
  bool v4; // zf
  int v5; // edx
  unsigned int v6; // ecx
  unsigned int v7; // eax
  int v8; // ecx
  int v9; // ecx
  unsigned int v10; // edx
  int v11; // eax
  int v13; // esi
  int v14; // eax

  v2 = 0xFFFF;
  if ( (unsigned int)(a1[3] - 5) < 0xFFFF )
    v2 = a1[3] - 5;
  while ( 1 )
  {
    v3 = a1[27];
    if ( v3 <= 1 )
    {
      sub_6B8DC8((int)a1);
      v3 = a1[27];
      if ( !v3 )
        break;
    }
    v4 = v3 + a1[25] == 0;
    a1[25] += v3;
    v5 = a1[21];
    v6 = a1[25];
    a1[27] = 0;
    v7 = v5 + v2;
    if ( !v4 && v6 < v7
      || ((a1[27] = v6 - v7, a1[25] = v7, v5 < 0) ? (v8 = 0) : (v8 = v5 + a1[12]),
          sub_6DAAC0(a1, v8, v2, 0),
          a1[21] = a1[25],
          sub_6B88EE(*a1),
          *(_DWORD *)(*a1 + 16)) )
    {
      v9 = a1[21];
      v10 = a1[25] - v9;
      if ( v10 < a1[9] - 262 )
        continue;
      v11 = v9 < 0 ? 0 : v9 + a1[12];
      sub_6DAAC0(a1, v11, v10, 0);
      a1[21] = a1[25];
      sub_6B88EE(*a1);
      if ( *(_DWORD *)(*a1 + 16) )
        continue;
    }
    return 0;
  }
  if ( !a2 )
    return 0;
  v13 = a1[21];
  if ( v13 < 0 )
    v14 = 0;
  else
    v14 = v13 + a1[12];
  sub_6DAAC0(a1, v14, a1[25] - v13, a2 == 4);
  a1[21] = a1[25];
  sub_6B88EE(*a1);
  if ( !*(_DWORD *)(*a1 + 16) )
  {
    if ( a2 == 4 )
      return 2;
    return 0;
  }
  return 2 * (a2 == 4) + 1;
}
