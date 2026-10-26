int __thiscall sub_4D02B0(int *this, float a2)
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
    result = v2 << 17;
    *this = result | *this & 0x1FFFF;
  }
  else
  {
    result = 0;
    *this &= 0x1FFFFu;
  }
  return result;
}
