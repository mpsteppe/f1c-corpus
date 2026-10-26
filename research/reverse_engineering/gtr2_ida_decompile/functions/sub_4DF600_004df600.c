char __thiscall sub_4DF600(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  v2 = this[16];
  if ( v2 )
  {
    while ( v2 != a2 )
    {
      v2 = *(_DWORD *)(v2 + 140);
      if ( !v2 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v3 = this[17];
    if ( !v3 )
      return 0;
    v4 = *(_DWORD *)(v3 + 52);
    if ( !v4 )
      return 0;
    while ( v4 != a2 )
    {
      v4 = *(_DWORD *)(v4 + 140);
      if ( !v4 )
        return 0;
    }
  }
  return 1;
}
