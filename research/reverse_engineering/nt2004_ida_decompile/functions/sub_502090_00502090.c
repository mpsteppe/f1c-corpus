int __thiscall sub_502090(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 == -1 )
  {
    this[6] = -1;
  }
  else if ( this[a2 + 7] )
  {
    if ( dword_767BA4 )
      this[6] = a2;
  }
  return result;
}
