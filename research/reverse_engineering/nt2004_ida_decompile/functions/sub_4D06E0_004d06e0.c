int __thiscall sub_4D06E0(_WORD *this, float a2)
{
  int result; // eax
  float v3; // [esp+8h] [ebp+4h]

  v3 = a2 * 10.185916;
  result = (int)v3;
  this[6] ^= (*((_BYTE *)this + 12) ^ (unsigned __int8)(4 * result)) & 0xFC;
  return result;
}
