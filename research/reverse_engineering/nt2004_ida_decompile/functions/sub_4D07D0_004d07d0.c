int __thiscall sub_4D07D0(_WORD *this, float a2)
{
  int result; // eax
  float v3; // [esp+8h] [ebp+4h]

  v3 = a2 * 0.02;
  result = ((int)v3 << 10) | this[6] & 0x3FF;
  this[6] = result;
  return result;
}
