int __thiscall sub_52E2A0(int *this, int a2)
{
  int result; // eax

  result = *this;
  if ( *(_DWORD *)(*this + 14820) != 1 )
  {
    result = dword_B704D4;
    if ( dword_B704D4 )
      return sub_52C870(a2, 0);
  }
  return result;
}
