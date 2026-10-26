// f1c  0x0042aeb0  size=47
int __thiscall sub_42AEB0(_DWORD *this, int a2)
{
  int v2; // eax
  _DWORD *i; // edx

  v2 = 0;
  for ( i = this + 4177; *i != a2; i += 2 )
  {
    if ( ++v2 >= 5 )
      return -1;
  }
  return this[2 * v2 + 4178];
}
