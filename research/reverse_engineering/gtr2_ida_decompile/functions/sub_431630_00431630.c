double __thiscall sub_431630(int *this, int a2, int a3)
{
  int v3; // esi

  if ( a2 < 0 )
    return 0.0;
  if ( a2 >= *this )
    return 0.0;
  if ( a3 < 0 )
    return 0.0;
  if ( a3 >= this[2] )
    return 0.0;
  if ( *(int *)(this[1] + 8 * a2) <= 0 )
    return 0.0;
  if ( *(int *)(this[3] + 8 * a3) <= 0 )
    return 0.0;
  v3 = this[4];
  if ( v3 <= 0 )
    return 0.0;
  else
    return (double)(this[5] * *(_DWORD *)(this[1] + 8 * a2 + 4) * *(_DWORD *)(this[3] + 8 * a3 + 4))
         / (double)(v3 * *(_DWORD *)(this[3] + 8 * a3) * *(_DWORD *)(this[1] + 8 * a2));
}
