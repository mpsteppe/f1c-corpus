char __thiscall sub_4F5E80(_DWORD *this, float *a2)
{
  int v2; // esi
  int v3; // edx
  _DWORD *i; // ecx
  int v5; // eax
  int v6; // eax
  double v7; // st7

  v2 = this[14];
  v3 = 0;
  if ( v2 <= 0 )
    return 0;
  for ( i = this + 15; ; ++i )
  {
    v5 = *(_DWORD *)(*i + 4);
    if ( !v5 )
      break;
    v6 = v5 - 2;
    if ( !v6 )
    {
      v7 = a2[10];
      goto LABEL_9;
    }
    if ( v6 == 3 )
    {
      v7 = a2[12];
      goto LABEL_9;
    }
LABEL_10:
    if ( ++v3 >= v2 )
      return 0;
  }
  v7 = a2[11];
LABEL_9:
  if ( v7 == 0.0 )
    goto LABEL_10;
  return 1;
}
