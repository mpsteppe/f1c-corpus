unsigned int __cdecl _control87(unsigned int NewValue, unsigned int Mask)
{
  unsigned int v2; // esi

  v2 = Mask & NewValue | ~Mask & _abstract_cw();
  _hw_cw(v2);
  return v2;
}
