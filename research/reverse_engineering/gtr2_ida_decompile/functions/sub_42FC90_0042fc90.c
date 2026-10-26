int __thiscall sub_42FC90(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // esi
  int i; // ecx

  v2 = this[111];
  v3 = 0;
  if ( v2 <= 0 )
    return 0;
  v4 = this[113];
  for ( i = v4; *(_DWORD *)(*(_DWORD *)i + 400) != a2; i += 4 )
  {
    if ( ++v3 >= v2 )
      return 0;
  }
  return *(_DWORD *)(v4 + 4 * v3);
}
