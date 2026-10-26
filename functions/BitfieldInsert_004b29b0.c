int __thiscall sub_4B29B0(_DWORD *this, float a2)
{
  int v2; // edx
  int result; // eax
  float v4; // [esp+8h] [ebp+4h]

  v4 = a2 * 31.0;
  v2 = this[11];
  result = (v2 ^ ((unsigned __int8)(int)v4 << 12)) & 0x1F000;
  this[11] = result ^ v2;
  return result;
}
