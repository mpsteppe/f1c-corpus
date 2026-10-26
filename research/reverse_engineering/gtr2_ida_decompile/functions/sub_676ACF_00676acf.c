int __stdcall sub_676ACF(_DWORD *a1, int a2, _DWORD *a3, unsigned int *a4)
{
  _DWORD *v4; // ebx
  unsigned int *v5; // edi
  int result; // eax
  int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // esi
  int i; // eax
  int v11; // ecx

  v4 = a3;
  v5 = a4;
  if ( !a3 && !a4 )
    return -2005530516;
  if ( a2 >= 0 )
  {
    result = sub_6768C8(a1, a2, &a3);
    if ( result < 0 )
      return result;
    v7 = (int)a3;
  }
  else
  {
    v7 = -a2;
  }
  v8 = 0;
  v9 = 1;
  for ( i = v7; i; ++v8 )
    i = *(_DWORD *)(i + 36);
  if ( v5 )
  {
    if ( *v5 )
      v9 = *v5;
    if ( v9 > v8 )
      v9 = v8;
    *v5 = v8;
  }
  if ( v4 )
  {
    while ( v7 && v9 )
    {
      result = sub_673626((_DWORD *)v7, v4);
      if ( result < 0 )
        return result;
      v7 = *(_DWORD *)(v11 + 36);
      v4 += 12;
      --v9;
    }
  }
  return 0;
}
