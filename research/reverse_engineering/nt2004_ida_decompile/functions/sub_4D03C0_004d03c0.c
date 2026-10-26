unsigned int __thiscall sub_4D03C0(unsigned int *this, float a2)
{
  unsigned int result; // eax
  float v3; // [esp+8h] [ebp+4h]

  v3 = a2 * 63.0;
  result = *this & 0xFFFFFF80 | ((unsigned __int8)(int)v3 - 64) & 0x7F;
  *this = result;
  return result;
}
