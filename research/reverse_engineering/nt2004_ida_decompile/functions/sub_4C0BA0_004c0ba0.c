int __thiscall sub_4C0BA0(_DWORD *this)
{
  int result; // eax
  int v2; // edx
  _DWORD *v3; // edi

  result = -1;
  v2 = 0;
  v3 = this + 199;
  while ( v2 < this[198] )
  {
    if ( *v3 > *(_DWORD *)(*this + 20848) && *v3 < dword_7D74B8 )
      return this[2 * v2 + 199];
    ++v2;
    v3 += 2;
    if ( v2 >= 3 )
      return result;
  }
  return result;
}
