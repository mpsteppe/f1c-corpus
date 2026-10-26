int __fastcall sub_563A70(_BYTE *a1, int a2, int a3)
{
  int v3; // esi
  _BYTE *v4; // eax
  _BYTE *v5; // edx

  v3 = a3;
  v4 = a1;
  if ( !a3 )
    return v4 - a1;
  v5 = &a1[a2];
  while ( v4 != v5 )
  {
    if ( *v4 == 92 )
      --v3;
    ++v4;
    if ( !v3 )
      return v4 - a1;
  }
  if ( v3 )
    return -1;
  else
    return v4 - a1;
}
