int __thiscall sub_59CB40(_DWORD *this, int a2)
{
  int v2; // ebp
  int v3; // edx
  int result; // eax
  int v5; // esi
  int i; // edi

  v2 = this[70];
  v3 = 0;
  result = 0;
  v5 = 0;
  if ( v2 > 0 )
  {
    for ( i = 0; a2 < v3 || a2 >= v3 + *(_DWORD *)(this[71] + i + 8); i += 64 )
    {
      v3 += *(_DWORD *)(this[71] + i + 8);
      if ( ++v5 >= v2 )
        return 0;
    }
    return *(_DWORD *)(this[71] + (v5 << 6) + 12) + 48 * (a2 - v3);
  }
  return result;
}
