int __thiscall sub_544D30(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v6; // eax
  int v7; // esi

  v3 = a2[17];
  if ( v3 && sub_544D30(v3, 1) )
    return -1;
  v6 = a2[19];
  if ( v6 && a3 && sub_544D30(v6, 1) )
    return -1;
  v7 = a2[129];
  if ( v7 )
  {
    while ( !sub_54C6C0(this[59] & 4) )
    {
      v7 = *(_DWORD *)(v7 + 16);
      if ( !v7 )
        return 0;
    }
    return -1;
  }
  return 0;
}
