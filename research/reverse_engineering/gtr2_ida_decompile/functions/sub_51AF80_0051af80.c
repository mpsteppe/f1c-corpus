int __thiscall sub_51AF80(_DWORD *this, float a2)
{
  int result; // eax
  float v4; // [esp+0h] [ebp-8h]

  v4 = a2 * 3.0;
  result = sub_4015C0(v4) << 22;
  this[1] = result | this[1] & 0xFF3FFFFF;
  return result;
}
