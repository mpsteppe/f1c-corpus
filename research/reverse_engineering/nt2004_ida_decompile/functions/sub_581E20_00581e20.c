double __thiscall sub_581E20(int *this, double a2)
{
  double result; // st7
  int v4; // ebx
  int v5; // edi
  double v6; // st7
  double v7; // [esp+Ch] [ebp-8h]

  result = 1.0;
  v7 = 1.0;
  v4 = 0;
  if ( *this > 0 )
  {
    v5 = 0;
    do
    {
      v6 = sub_57CB70(v5 + this[1], a2);
      if ( v6 < v7 )
        v7 = v6;
      ++v4;
      v5 += 580;
    }
    while ( v4 < *this );
    return v7;
  }
  return result;
}
