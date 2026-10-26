int __thiscall sub_463B80(void *this)
{
  int v2; // edx
  int result; // eax
  _DWORD *i; // ecx

  v2 = sub_56A540(*(_DWORD *)(*(_DWORD *)this + 6708));
  result = 0;
  for ( i = (_DWORD *)(*(_DWORD *)this + 6516); *i != v2; ++i )
  {
    if ( ++result >= 48 )
      return -1;
  }
  return result;
}
