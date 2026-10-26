// f1c  0x0045e5b0  size=26
int __thiscall sub_45E5B0(_DWORD *this)
{
  int result; // eax
  _DWORD *i; // ecx

  result = 0;
  for ( i = this + 117; *i != -1; ++i )
  {
    if ( ++result >= 104 )
      return -1;
  }
  return result;
}
