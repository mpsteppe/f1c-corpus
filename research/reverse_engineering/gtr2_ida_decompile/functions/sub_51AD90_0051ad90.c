int __thiscall sub_51AD90(_DWORD *this, float a2)
{
  int result; // eax
  float v4; // [esp+0h] [ebp-8h]

  v4 = a2 * 31.0;
  result = (*this ^ ((unsigned __int8)sub_4015C0(v4) << 12)) & 0x1F000;
  *this ^= result;
  return result;
}
