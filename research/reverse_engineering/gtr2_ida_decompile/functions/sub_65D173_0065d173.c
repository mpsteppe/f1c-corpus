int __thiscall sub_65D173(_DWORD *this, int a2, int a3, void **a4, int a5)
{
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  int result; // eax

  v6 = operator new(0x70u);
  if ( v6 )
    v7 = sub_659CD8(v6);
  else
    v7 = 0;
  this[154] = v7;
  if ( !v7 )
    return -2147024882;
  result = sub_659F38(v7, a2, a3, (int)this, (int)(this + 6));
  if ( result >= 0 )
  {
    result = sub_65C578((int)this, a4);
    if ( result >= 0 )
    {
      this[155] = this[154];
      this[156] = a5;
      return 0;
    }
  }
  return result;
}
