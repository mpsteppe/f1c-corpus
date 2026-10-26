int __thiscall sub_462330(void *this)
{
  int v2; // edx
  int result; // eax
  _DWORD *i; // ecx

  v2 = sub_57A810(*(_DWORD *)(*(_DWORD *)this + 16312));
  result = 0;
  for ( i = (_DWORD *)(*(_DWORD *)this + 15896); *i != v2; ++i )
  {
    if ( ++result >= 104 )
      return -1;
  }
  return result;
}
