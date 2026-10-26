unsigned int __cdecl _control87(unsigned int NewValue, unsigned int Mask)
{
  unsigned int v2; // ebx
  __int16 v4; // [esp+4h] [ebp-4h]

  v2 = Mask & NewValue | ~Mask & _abstract_cw(v4);
  _hw_cw(v2);
  return v2;
}
