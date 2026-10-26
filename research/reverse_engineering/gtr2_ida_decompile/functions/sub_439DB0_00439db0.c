double __thiscall sub_439DB0(float *this, float a2, float a3)
{
  double X; // st7
  int v5; // eax
  double v6; // st7
  double v7; // st6
  float *v8; // eax
  double v9; // st7
  float v11; // [esp+Ch] [ebp-4h]
  float v12; // [esp+14h] [ebp+4h]

  X = a2 * 0.03125;
  v12 = X;
  v11 = floor(X);
  v5 = sub_4015C0(v11);
  v6 = v12 - v11;
  v7 = *(float *)(*(_DWORD *)this + 8 * v5 + 8);
  v8 = (float *)(*(_DWORD *)this + 8 * v5);
  this[1] = (v7 - *v8) * v6 + *v8;
  v9 = v6 * (v8[3] - v8[1]) + v8[1];
  this[2] = v9;
  return v9 * a3 + this[1];
}
