float *__stdcall sub_50E19E(float *a1, float *a2, float *a3, float a4)
{
  double v5; // st7
  double v7; // st6
  double v8; // st5
  long double v9; // st6
  long double v10; // st6
  long double v11; // st6
  float *result; // eax
  float v13; // [esp+0h] [ebp-4h]
  float v14; // [esp+10h] [ebp+Ch]
  float v15; // [esp+14h] [ebp+10h]
  float v16; // [esp+14h] [ebp+10h]

  v5 = 1.0 - a4;
  v7 = *a2 * *a3 + a3[2] * a2[2] + a3[1] * a2[1] + a3[3] * a2[3];
  if ( v7 < 0.0 )
    v14 = -1.0;
  else
    v14 = 1.0;
  v8 = v14 * v7;
  if ( 1.0 - v8 <= 0.00000011920929 )
  {
    v10 = a4;
  }
  else
  {
    v9 = sqrt(1.0 - v8 * v8);
    v15 = v8;
    v16 = atan2(v9, v15);
    v13 = 1.0 / v9;
    v5 = sin(v16 * v5) * v13;
    v10 = sin(v16 * a4) * v13;
  }
  v11 = v10 * v14;
  result = a1;
  *a1 = v5 * *a2 + v11 * *a3;
  a1[1] = v11 * a3[1] + v5 * a2[1];
  a1[2] = v11 * a3[2] + v5 * a2[2];
  a1[3] = v11 * a3[3] + v5 * a2[3];
  return result;
}
