float *__thiscall sub_5E8F00(float *this, float *a2, char a3, int a4)
{
  double v5; // st7
  float *result; // eax
  float v7[3]; // [esp+4h] [ebp-Ch] BYREF

  v5 = -a2[54];
  if ( a3 )
  {
    v7[0] = v5;
    v7[1] = -a2[55];
    v7[2] = -a2[56];
    sub_5D7810(v7, this + 42, (float *)(a4 + 4));
    return this + 34;
  }
  else
  {
    this[42] = v5;
    this[43] = -a2[55];
    result = this + 34;
    this[44] = -a2[56];
  }
  return result;
}
