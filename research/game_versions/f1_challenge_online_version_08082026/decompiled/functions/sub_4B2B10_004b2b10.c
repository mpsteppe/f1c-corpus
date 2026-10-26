unsigned int __thiscall sub_4B2B10(_DWORD *this, float a2)
{
  unsigned int result; // eax
  float v3; // [esp+8h] [ebp+4h]

  v3 = a2 * 3.0;
  result = ((int)v3 << 22) | this[12] & 0xFF3FFFFF;
  this[12] = result;
  return result;
}
