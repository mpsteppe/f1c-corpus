double __thiscall sub_61E0D0(int *this, double a2)
{
  double result; // st7
  int v4; // edi
  int v5; // ebx
  double v6; // st7
  double v7; // [esp+18h] [ebp-8h]

  result = 1.0;
  v7 = 1.0;
  v4 = 0;
  if ( *this > 0 )
  {
    v5 = 0;
    do
    {
      v6 = sub_619760((double *)(v5 + this[1]), a2);
      if ( v6 < v7 )
        v7 = v6;
      ++v4;
      v5 += 584;
    }
    while ( v4 < *this );
    return v7;
  }
  return result;
}
