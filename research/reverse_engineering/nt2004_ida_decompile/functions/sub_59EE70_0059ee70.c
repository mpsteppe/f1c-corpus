int __thiscall sub_59EE70(_DWORD *this, int a2, int a3)
{
  int result; // eax

  if ( a3 )
  {
    result = a2;
    this[14] |= a2;
  }
  else
  {
    result = ~a2 & this[14];
    this[14] = result;
  }
  return result;
}
