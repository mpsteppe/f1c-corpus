double __thiscall sub_5738D0(float *this, float a2)
{
  double X; // st7
  int v4; // eax
  double v6; // st7
  float X_4; // [esp+4h] [ebp-Ch]
  float v8; // [esp+Ch] [ebp-4h]
  int v9; // [esp+14h] [ebp+4h]

  X = a2 * *this;
  v8 = X;
  X_4 = floor(X);
  v4 = sub_4015C0(X_4);
  v9 = v4;
  if ( v4 < 0 )
    return this[1];
  if ( v4 >= 14 )
  {
    v4 = 13;
    v9 = 13;
  }
  v6 = this[v4 + 1];
  return v6 + (this[v4 + 2] - v6) * (v8 - (double)v9);
}
