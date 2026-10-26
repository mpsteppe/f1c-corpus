int __stdcall sub_597090(_DWORD *a1, int a2)
{
  int v2; // eax
  int v4; // eax
  int v5; // esi

  v2 = a1[17];
  if ( v2 && sub_597090(v2, 1) )
    return -1;
  v4 = a1[19];
  if ( v4 && a2 && sub_597090(v4, 1) )
    return -1;
  v5 = a1[129];
  if ( v5 )
  {
    while ( !sub_59B9D0(v5) )
    {
      v5 = *(_DWORD *)(v5 + 16);
      if ( !v5 )
        return 0;
    }
    return -1;
  }
  return 0;
}
