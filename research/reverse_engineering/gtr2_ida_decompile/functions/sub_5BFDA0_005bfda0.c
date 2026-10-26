int __thiscall sub_5BFDA0(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // esi
  _DWORD *i; // ecx

  v2 = this[87];
  v3 = 0;
  if ( v2 <= 0 )
    return 0;
  v4 = this[89];
  for ( i = (_DWORD *)(v4 + 4); *i != a2; i += 2 )
  {
    if ( ++v3 >= v2 )
      return 0;
  }
  return v4 + 8 * v3;
}
