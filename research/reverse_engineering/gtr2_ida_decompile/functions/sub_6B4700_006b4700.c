int __fastcall sub_6B4700(int a1, _DWORD *a2)
{
  _DWORD *v2; // ecx
  int result; // eax
  int v4; // edx

  if ( a2[19] || a2[76] || a2[10] != 3 || a2[9] != 3 || a2[11] != 2 || a2[30] != 3 )
    return 0;
  v2 = (_DWORD *)a2[55];
  if ( v2[2] != 2 )
    return 0;
  result = 1;
  if ( v2[23] != 1 )
    return 0;
  if ( v2[44] != 1 )
    return 0;
  if ( (int)v2[3] > 2 )
    return 0;
  if ( v2[24] != 1 )
    return 0;
  if ( v2[45] != 1 )
    return 0;
  v4 = a2[80];
  if ( v2[9] != v4 || v2[30] != v4 || v2[51] != v4 )
    return 0;
  return result;
}
