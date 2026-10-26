double __thiscall sub_561420(float *this, float a2, int *a3)
{
  double v3; // st7
  int v5; // eax
  double result; // st7
  float v7; // [esp+0h] [ebp-4h]

  v3 = a2;
  if ( a2 < 0.0 )
  {
    do
      v3 = v3 + this[9];
    while ( v3 < 0.0 );
    a2 = v3;
  }
  v7 = this[9];
  if ( v3 > v7 )
  {
    do
      v3 = v3 - this[9];
    while ( v3 > v7 );
    a2 = v3;
  }
  v5 = sub_561390(this, a2);
  result = (a2 - this[v5 + 6]) / (this[v5 + 9] - this[v5 + 6]);
  if ( a3 )
    *a3 = v5;
  return result;
}
