int __thiscall sub_593AF0(_DWORD *this, unsigned __int16 a2)
{
  int result; // eax

  result = (a2 ^ (unsigned __int16)this[32]) & 0x3C5;
  this[32] ^= result;
  return result;
}
