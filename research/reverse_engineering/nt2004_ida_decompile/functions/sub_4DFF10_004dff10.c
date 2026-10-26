char __thiscall sub_4DFF10(float **this, float *a2)
{
  float *v2; // ecx
  float *v3; // eax
  double v4; // st7
  char result; // al
  float v6; // [esp+4h] [ebp-Ch]
  float v7; // [esp+8h] [ebp-8h]
  float v8; // [esp+Ch] [ebp-4h]

  v2 = *this;
  v6 = *a2 - v2[4401];
  v7 = a2[1] - v2[4402];
  v8 = a2[2] - v2[4403];
  v3 = (float *)sub_427FF0((int)v2);
  if ( !v3 )
    return 0;
  v4 = v8 * v3[13] + v7 * v3[12] + v6 * v3[11];
  result = 1;
  if ( v4 <= 0.0 )
    return 0;
  return result;
}
