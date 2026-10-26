int __cdecl sub_4F8A50(unsigned __int8 *a1, unsigned __int8 *a2)
{
  float *v2; // edx
  char *v3; // ecx
  int v4; // esi
  int v5; // eax
  int v6; // esi
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c2

  v2 = (float *)((char *)&unk_6310CC + 25304 * *a1);
  v3 = (char *)&unk_6310CC + 25304 * *a2;
  v4 = *((_DWORD *)v3 + 14);
  if ( *((_DWORD *)v2 + 14) == 3 )
  {
    if ( v4 != 3 )
      return 1;
  }
  else
  {
    if ( v4 == 3 )
      return -1;
    if ( v9 | v10 )
    {
      if ( v2[31] >= 0.0 )
        return -1;
    }
    else
    {
      if ( v2[31] < 0.0 )
        return 1;
      if ( *((float *)v3 + 31) > (double)v2[31] )
        return -1;
      if ( *((float *)v3 + 31) < (double)v2[31] )
        return 1;
    }
  }
  v5 = *((_DWORD *)v3 + 12);
  v6 = *((_DWORD *)v2 + 12);
  if ( v6 < v5 )
    return -1;
  if ( v6 > v5 )
    return 1;
  return v2 < (float *)v3 ? -1 : 1;
}
