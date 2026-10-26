int __thiscall sub_5BFD60(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // esi
  int i; // ecx

  v2 = this[87];
  v3 = 0;
  if ( v2 <= 0 )
    return 0;
  v4 = this[89];
  for ( i = v4 + 4; *(_DWORD *)(*(_DWORD *)i + 60) != a2; i += 8 )
  {
    if ( ++v3 >= v2 )
      return 0;
  }
  return v4 + 8 * v3;
}
