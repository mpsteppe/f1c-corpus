unsigned int __thiscall sub_618040(_DWORD *this, unsigned int a2, int a3)
{
  unsigned int result; // eax
  _BYTE *v4; // esi
  char v5; // dl

  for ( result = a2; result < a2 + a3; *v4 &= v5 )
  {
    v4 = (_BYTE *)(*this + (result >> 3));
    v5 = ~(1 << (result++ & 7));
  }
  return result;
}
