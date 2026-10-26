char __thiscall sub_4AF0B0(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // edx
  int v5; // eax

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
    v3 = sub_4AEF90(this);
    if ( !v3 )
      return 0;
    v5 = *(_DWORD *)(v3 + 52);
    if ( !v5 )
      return 0;
    while ( v5 != v4 )
    {
      v5 = *(_DWORD *)(v5 + 140);
      if ( !v5 )
        return 0;
    }
  }
  return 1;
}
