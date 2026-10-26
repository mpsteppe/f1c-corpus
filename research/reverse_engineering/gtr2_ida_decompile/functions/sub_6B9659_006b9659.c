int __stdcall sub_6B9659(_DWORD *a1)
{
  _DWORD *v1; // esi
  bool v2; // sf
  int v3; // edx
  int v4; // ecx

  if ( !a1 )
    return -2;
  v1 = (_DWORD *)a1[7];
  if ( !v1 || !a1[8] || !a1[9] )
    return -2;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  a1[11] = 2;
  v2 = (int)v1[6] < 0;
  v3 = v1[2];
  v1[5] = 0;
  v1[4] = v3;
  if ( v2 )
    v1[6] = 0;
  v1[1] = v1[6] != 0 ? 113 : 42;
  a1[12] = 1;
  v1[8] = 0;
  sub_6DA557(v1);
  sub_6B8BF9(v4, (int)v1);
  return 0;
}
