int __thiscall sub_5E82A0(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  v2 = a2;
  if ( a2 == 99 )
    v2 = this[63];
  v3 = v2 - 1;
  if ( !v3 )
    return this[67];
  v4 = v3 - 1;
  if ( !v4 )
    return this[134];
  if ( v4 == 1 )
    return this[201];
  return 0;
}
