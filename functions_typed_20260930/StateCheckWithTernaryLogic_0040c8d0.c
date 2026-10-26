int __thiscall sub_40C8D0(_DWORD *this)
{
  int v1; // eax
  int v2; // eax

  v1 = this[3];
  if ( !v1 )
  {
    v1 = *(_DWORD *)(this[6] + 52);
    if ( !v1 )
      return 3;
  }
  v2 = v1 - 1;
  if ( !v2 )
    return 1;
  if ( v2 == 1 )
    return dword_7CFCC8 == 0;
  return 0;
}

