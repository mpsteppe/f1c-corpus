int __thiscall sub_567F10(_DWORD *this)
{
  int i; // esi
  int result; // eax

  for ( i = 0; i < 9; ++i )
  {
    result = this[i];
    if ( result )
      result = sub_567CC0((_DWORD *)this[i]);
    this[i] = 0;
  }
  return result;
}

