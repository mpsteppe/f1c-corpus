int __thiscall sub_4D0340(_DWORD *this, float a2)
{
  int result; // eax
  float v3; // [esp+8h] [ebp+4h]

  v3 = a2 * 15.0;
  result = ((unsigned __int16)*this ^ (unsigned __int16)((unsigned __int8)(int)v3 << 12)) & 0xF000;
  *this ^= result;
  return result;
}
