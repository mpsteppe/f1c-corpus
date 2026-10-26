double __thiscall sub_5143A0(float *this, float a2, float a3)
{
  double X; // st7
  int v5; // eax
  double result; // st7
  double v7; // st7
  float v8; // [esp+Ch] [ebp-8h]
  float v9; // [esp+18h] [ebp+4h]
  int v10; // [esp+18h] [ebp+4h]

  X = 1.0 / a2 * this[4905];
  v8 = X;
  v9 = floor(X);
  v5 = (int)v9;
  v10 = v5;
  if ( v5 >= 0 )
  {
    if ( v5 >= 14 )
    {
      v5 = 13;
      v10 = 13;
    }
    v7 = this[v5 + 4906];
    result = v7 + (this[v5 + 4907] - v7) * (v8 - (double)v10);
  }
  else
  {
    result = this[4906];
  }
  if ( a3 != 1.0 )
    return result * sqrt(a3);
  return result;
}
