// f1c  0x004b2930  size=68
int __thiscall sub_4B2930(_DWORD *this, float a2)
{
  int v2; // eax
  int result; // eax
  float v4; // [esp+8h] [ebp+4h]

  v4 = a2 * 10.0;
  v2 = (int)v4;
  if ( v2 >= 0 )
  {
    if ( v2 > 0x7FFF )
      v2 = 0x7FFF;
  }
  else
  {
    v2 = 0;
  }
  result = v2 << 17;
  this[11] = result | this[11] & 0x1FFFF;
  return result;
}
