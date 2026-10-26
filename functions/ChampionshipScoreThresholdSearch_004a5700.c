int __thiscall sub_4A5700(_DWORD *this)
{
  int result; // eax
  int v2; // edx
  _DWORD *v3; // edi

  result = -1;
  v2 = 0;
  v3 = this + 89;
  while ( v2 < this[88] )
  {
    if ( *v3 > *(_DWORD *)(*this + 16444) && *v3 < dword_8ACF8C )
      return this[2 * v2 + 89];
    ++v2;
    v3 += 2;
    if ( v2 >= 3 )
      return result;
  }
  return result;
}
