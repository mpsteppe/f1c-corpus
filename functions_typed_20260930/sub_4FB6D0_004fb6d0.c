double __thiscall sub_4FB6D0(void *this, float *a2)
{
  double v2; // st7
  double v3; // st7
  double result; // st7
  float *v5; // eax
  long double v6; // st6
  float *v7; // eax
  long double v8; // st6
  float v9; // [esp+0h] [ebp-24h]
  float v10; // [esp+0h] [ebp-24h]
  float v11; // [esp+4h] [ebp-20h]
  float v12; // [esp+4h] [ebp-20h]
  float v13; // [esp+8h] [ebp-1Ch]
  float v14; // [esp+8h] [ebp-1Ch]
  float v15; // [esp+Ch] [ebp-18h]
  float v16; // [esp+10h] [ebp-14h]
  float v17; // [esp+14h] [ebp-10h]
  float v18; // [esp+28h] [ebp+4h]
  float v19; // [esp+28h] [ebp+4h]
  float v20; // [esp+28h] [ebp+4h]

  v15 = *a2 - *(float *)this;
  v16 = a2[1] - *((float *)this + 1);
  v2 = a2[2] - *((float *)this + 2);
  v17 = v2;
  v3 = v2 * *((float *)this + 10) + v16 * *((float *)this + 9) + v15 * *((float *)this + 8);
  if ( v3 >= 0.0 )
    result = v3 - *((float *)this + 23);
  else
    result = -(v3 + *((float *)this + 22));
  v5 = (float *)*((_DWORD *)this + 68);
  v9 = *v5 - *(float *)this;
  v11 = v5[1] - *((float *)this + 1);
  v13 = v5[2] - *((float *)this + 2);
  v6 = sqrt(v13 * v13 + v11 * v11 + v9 * v9);
  if ( v6 == 0.0 )
    return 10.0;
  v18 = v13 * (1.0 / v6) * v17 + v11 * (1.0 / v6) * v16 + v9 * (1.0 / v6) * v15 - v6;
  if ( result < v18 )
    result = v18;
  v7 = (float *)*((_DWORD *)this + 67);
  v10 = *v7 - *(float *)this;
  v12 = v7[1] - *((float *)this + 1);
  v14 = v7[2] - *((float *)this + 2);
  v8 = sqrt(v14 * v14 + v12 * v12 + v10 * v10);
  if ( v8 == 0.0 )
    return 10.0;
  v19 = v14 * (1.0 / v8) * v17 + v12 * (1.0 / v8) * v16 + v10 * (1.0 / v8) * v15 - v8;
  if ( result < v19 )
    result = v19;
  v20 = fabs(v16) - 3.0;
  if ( result < v20 )
    return v20;
  return result;
}

