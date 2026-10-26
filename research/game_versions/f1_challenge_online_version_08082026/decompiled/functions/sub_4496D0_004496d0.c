int __thiscall sub_4496D0(int *this)
{
  int result; // eax
  int v2; // esi
  int v3; // eax

  result = *this;
  if ( *this )
  {
    v2 = 0;
    if ( result - 1 > 0 )
    {
      v3 = 0;
      do
      {
        *(_DWORD *)(v3 + this[2] + 28) = v3 + this[2] + 32;
        ++v2;
        v3 += 32;
      }
      while ( v2 < *this - 1 );
    }
    return this[2];
  }
  return result;
}
