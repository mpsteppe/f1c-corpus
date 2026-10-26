int __thiscall sub_428090(_DWORD *this, int a2)
{
  int v2; // eax
  _DWORD *i; // edx

  v2 = 0;
  for ( i = this + 5302; *i != a2; i += 2 )
  {
    if ( ++v2 >= 5 )
      return -1;
  }
  return this[2 * v2 + 5303];
}
