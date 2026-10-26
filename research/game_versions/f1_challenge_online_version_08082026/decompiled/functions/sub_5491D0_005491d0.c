int __thiscall sub_5491D0(_DWORD *this, int a2)
{
  int v3; // esi
  int v4; // eax
  int result; // eax
  int i; // eax
  int v7; // eax

  v3 = this[60];
  if ( v3 )
  {
    for ( i = *(_DWORD *)(v3 + 52); i; i = *(_DWORD *)(i + 52) )
      v3 = i;
    v7 = sub_587C03(56);
    if ( v7 )
    {
      result = sub_55D200(v7);
      *(_DWORD *)(v3 + 52) = result;
    }
    else
    {
      result = 0;
      *(_DWORD *)(v3 + 52) = 0;
    }
  }
  else
  {
    v4 = sub_587C03(56);
    if ( v4 )
    {
      result = sub_55D200(v4);
      this[60] = result;
    }
    else
    {
      result = 0;
      this[60] = 0;
    }
  }
  return result;
}
