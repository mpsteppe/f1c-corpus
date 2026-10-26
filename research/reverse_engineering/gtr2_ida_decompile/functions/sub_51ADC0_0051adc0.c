int __thiscall sub_51ADC0(_DWORD *this, float a2)
{
  int result; // eax
  float v4; // [esp+0h] [ebp-8h]

  v4 = a2 * 63.0;
  result = ((unsigned __int8)*this ^ (unsigned __int8)(sub_4015C0(v4) + 64)) & 0x7F;
  *this ^= result;
  return result;
}
