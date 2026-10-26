int __thiscall sub_5E53C0(_DWORD *this, unsigned __int16 a2)
{
  int result; // eax

  result = (a2 ^ (unsigned __int16)*this) & 0x3004;
  *this ^= result;
  return result;
}
