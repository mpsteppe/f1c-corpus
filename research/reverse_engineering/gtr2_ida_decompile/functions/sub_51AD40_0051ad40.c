int __thiscall sub_51AD40(int *this, float a2)
{
  int v3; // eax
  int result; // eax
  float v5; // [esp+0h] [ebp-8h]

  v5 = a2 * 7.0;
  v3 = sub_4015C0(v5);
  if ( v3 >= 0 )
  {
    if ( v3 > 0x3FFF )
      v3 = 0x3FFF;
    result = v3 << 18;
    *this = result | *this & 0x3FFFF;
  }
  else
  {
    result = 0;
    *this &= 0x3FFFFu;
  }
  return result;
}
