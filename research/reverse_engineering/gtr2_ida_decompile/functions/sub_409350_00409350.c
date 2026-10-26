float *__thiscall sub_409350(float *this, float *a2)
{
  float *result; // eax
  double v3; // st7
  float v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+4h] [ebp-8h]
  float v6; // [esp+8h] [ebp-4h]

  result = a2;
  v4 = -*this;
  v5 = -this[1];
  v3 = this[2];
  *a2 = v4;
  v6 = -v3;
  a2[1] = v5;
  a2[2] = v6;
  return result;
}
