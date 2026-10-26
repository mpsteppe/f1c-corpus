int __stdcall sub_6460B4(const char *a1, int a2, _DWORD *a3)
{
  unsigned int v3; // edx
  int v5; // eax
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // [esp+0h] [ebp-4h]

  v3 = 0;
  if ( !a1 )
    return -2005530516;
  v5 = 44;
  v9 = 44;
  while ( 1 )
  {
    v6 = (v3 + v5) >> 1;
    v7 = strcmp((&off_736880)[3 * v6], a1);
    if ( !v7 )
      break;
    if ( v7 >= 0 )
      v9 = v6;
    else
      v3 = v6 + 1;
    v5 = v9;
    if ( v3 >= v9 )
      return -2147467259;
  }
  v8 = 3 * v6;
  if ( (a2 & dword_736888[v8]) != a2 )
    return -2147467259;
  if ( a3 )
  {
    *a3 = (&off_736880)[v8];
    a3[1] = (&off_736880)[v8 + 1];
    a3[2] = (&off_736880)[v8 + 2];
  }
  return 0;
}
