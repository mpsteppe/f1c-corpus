int __thiscall sub_424E30(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  _DWORD *i; // ecx

  v2 = this[4396];
  v3 = 0;
  if ( v2 < 0 )
    return 0;
  for ( i = (_DWORD *)this[4394]; *i != a2; i += 2 )
  {
    if ( ++v3 > v2 )
      return 0;
  }
  return 1;
}
