double __thiscall sub_573930(_DWORD *this, float a2, float a3)
{
  double X; // st7
  int v5; // eax
  double v6; // st6
  float *v7; // eax
  float v9; // [esp+Ch] [ebp-4h]
  float v10; // [esp+14h] [ebp+4h]

  X = a2 * 0.03125;
  v10 = X;
  v9 = floor(X);
  v5 = sub_4015C0(v9);
  v6 = *(float *)(*this + 8 * v5 + 12);
  v7 = (float *)(*this + 8 * v5);
  return ((v6 - v7[1]) * (v10 - v9) + v7[1]) * a3 + (v7[2] - *v7) * (v10 - v9) + *v7;
}
