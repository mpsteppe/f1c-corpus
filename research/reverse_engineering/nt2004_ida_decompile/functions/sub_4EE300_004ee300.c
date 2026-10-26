void __thiscall sub_4EE300(_DWORD *this)
{
  int v1; // esi
  int v2; // eax

  v1 = this[6312];
  if ( v1 >= 48 )
  {
    if ( v1 != 48 )
      return;
    v2 = dword_6290FC;
    goto LABEL_8;
  }
  v2 = this[5221];
  if ( v2 >= 1 )
  {
LABEL_8:
    this[6316] = v2 - 1;
    this[6317] = 0;
    return;
  }
  if ( v1 >= v1 % 44 )
    v1 %= 44;
  this[6316] = v1;
  this[6317] = 0;
}
