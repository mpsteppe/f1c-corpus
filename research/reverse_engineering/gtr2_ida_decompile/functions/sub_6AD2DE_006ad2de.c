int __thiscall sub_6AD2DE(_DWORD *this)
{
  int v2; // ecx
  int result; // eax

  v2 = this[139];
  if ( !v2 || !this[136] )
    return sub_6ACF7B(this, this[140], this[137]);
  if ( (unsigned __int16)this[50] != 260 )
    return -2147467259;
  sub_6ACF7B(this, v2, this[136]);
  result = sub_6CB0CE(65533);
  if ( result >= 0 )
  {
    result = sub_6C64E6(this);
    if ( result >= 0 )
      return sub_6ACF7B(this, this[140], this[137]);
  }
  return result;
}
