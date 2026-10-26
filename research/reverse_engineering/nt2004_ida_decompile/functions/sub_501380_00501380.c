double __thiscall sub_501380(float *this, float a2, int *a3)
{
  double v3; // st7
  double v5; // st6
  int v6; // ecx
  double v7; // st6
  double result; // st7
  float v9; // [esp+0h] [ebp-4h]

  v3 = a2;
  if ( a2 < 0.0 )
  {
    do
      v3 = v3 + this[16];
    while ( v3 < 0.0 );
    a2 = v3;
  }
  v5 = this[16];
  if ( v3 > v5 )
  {
    do
      v3 = v3 - v5;
    while ( v3 > v5 );
    a2 = v3;
  }
  v6 = sub_5012C0(this, a2);
  if ( v6 == -1 || *(_DWORD *)this > 2u )
  {
    result = -1.0;
  }
  else if ( v6 == 5 )
  {
    v9 = this[16] - this[6];
    if ( a2 >= (double)this[12] )
      v7 = a2 - this[6];
    else
      v7 = v9 + a2;
    result = v7 / (this[12] + v9);
  }
  else
  {
    result = (a2 - this[v6 + 1]) / (this[v6 + 7] - this[v6 + 1]);
  }
  if ( a3 )
    *a3 = v6;
  return result;
}
