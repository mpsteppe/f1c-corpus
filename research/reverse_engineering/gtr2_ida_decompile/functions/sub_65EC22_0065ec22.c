int __thiscall sub_65EC22(_DWORD *this, int a2)
{
  int v2; // edx
  unsigned int i; // esi
  int result; // eax

  v2 = 0;
  for ( i = 0; i < 7; ++i )
  {
    result = this[i];
    while ( result )
    {
      *(_DWORD *)(a2 + 4 * v2) = result;
      result = *(_DWORD *)(result + 32);
      ++v2;
    }
  }
  return result;
}
