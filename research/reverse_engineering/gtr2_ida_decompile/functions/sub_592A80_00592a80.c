double __thiscall sub_592A80(float *this, float a2)
{
  double X; // st7
  double v5; // st7
  double v6; // st6
  float v7; // [esp+10h] [ebp+4h]

  if ( a2 >= 3.75 )
    return this[43];
  X = a2 * 4.0;
  v7 = X;
  v5 = floor(X);
  v6 = this[(unsigned int)(unsigned __int64)v5 + 28];
  return (this[(unsigned int)(unsigned __int64)v5 + 29] - v6) * (v7 - v5) + v6;
}
