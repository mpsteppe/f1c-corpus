int __thiscall sub_4A2120(_DWORD *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ecx
  int result; // eax

  v2 = sub_48F410();
  v3 = this[80];
  v4 = v2 - 1;
  if ( v3 )
    this[70] = (v4 * this[79] + v3 / 2) / v3;
  else
    this[70] = 0;
  result = this[70];
  if ( result >= 0 )
  {
    if ( result > v4 )
      this[70] = v4;
  }
  else
  {
    this[70] = 0;
  }
  if ( v4 < this[80] )
    return sub_4A20B0();
  return result;
}
