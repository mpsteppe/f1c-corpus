int __thiscall sub_5E5610(_DWORD *this, int a2, char a3)
{
  int result; // eax

  if ( a3 )
  {
    result = a2;
    this[36] |= a2;
  }
  else
  {
    result = ~a2 & this[36];
    this[36] = result;
  }
  return result;
}
