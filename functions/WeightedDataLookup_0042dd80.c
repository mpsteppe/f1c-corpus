double __thiscall sub_42DD80(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // esi
  int v4; // edx
  int v5; // eax

  if ( a2 < 0 )
    return 0.0;
  if ( a2 >= this[2] )
    return 0.0;
  v2 = this[3];
  v3 = *(_DWORD *)(v2 + 8 * a2);
  v4 = v2 + 8 * a2;
  if ( v3 <= 0 )
    return 0.0;
  v5 = this[4];
  if ( v5 <= 0 )
    return 0.0;
  else
    return (double)(this[5] * *(_DWORD *)(v4 + 4)) / (double)(v3 * v5);
}
