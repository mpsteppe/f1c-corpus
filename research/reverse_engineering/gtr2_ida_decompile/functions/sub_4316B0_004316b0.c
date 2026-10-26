double __thiscall sub_4316B0(_DWORD *this, int a2)
{
  int v2; // edx

  if ( a2 < 0 )
    return 0.0;
  if ( a2 >= this[2] )
    return 0.0;
  if ( *(int *)(this[3] + 8 * a2) <= 0 )
    return 0.0;
  v2 = this[4];
  if ( v2 <= 0 )
    return 0.0;
  else
    return (double)(this[5] * *(_DWORD *)(this[3] + 8 * a2 + 4)) / (double)(v2 * *(_DWORD *)(this[3] + 8 * a2));
}
