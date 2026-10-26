int __thiscall sub_57AC20(_DWORD *this)
{
  int i; // esi
  int result; // eax

  for ( i = 0; i < 9; ++i )
  {
    result = this[i];
    if ( result )
      result = sub_57A9D0((_DWORD *)this[i]);
    this[i] = 0;
  }
  return result;
}
