double __thiscall sub_592490(int this, float *a2)
{
  double v2; // st7
  double result; // st7
  int v4; // eax
  double v5; // st6
  long double v6; // st6
  int v7; // eax
  double v8; // st6
  long double v9; // st6
  float v10; // [esp+0h] [ebp-24h]
  float v11; // [esp+4h] [ebp-20h]
  float v12; // [esp+8h] [ebp-1Ch]
  float v13; // [esp+18h] [ebp-Ch]
  float v14; // [esp+18h] [ebp-Ch]
  float v15; // [esp+1Ch] [ebp-8h]
  float v16; // [esp+1Ch] [ebp-8h]
  float v17; // [esp+20h] [ebp-4h]
  float v18; // [esp+20h] [ebp-4h]
  float v19; // [esp+28h] [ebp+4h]
  float v20; // [esp+28h] [ebp+4h]
  float v21; // [esp+28h] [ebp+4h]

  v10 = *a2 - *(float *)(this + 4);
  v11 = a2[1] - *(float *)(this + 8);
  v12 = a2[2] - *(float *)(this + 12);
  v2 = v12 * *(float *)(this + 44) + v11 * *(float *)(this + 40) + v10 * *(float *)(this + 36);
  if ( v2 >= 0.0 )
    result = v2 - *(float *)(this + 96);
  else
    result = -(v2 + *(float *)(this + 92));
  v4 = *(_DWORD *)(this + 276);
  v5 = *(float *)(v4 + 4);
  v4 += 4;
  v13 = v5 - *(float *)(this + 4);
  v15 = *(float *)(v4 + 4) - *(float *)(this + 8);
  v17 = *(float *)(v4 + 8) - *(float *)(this + 12);
  v6 = sqrt(v17 * v17 + v15 * v15 + v13 * v13);
  if ( v6 == 0.0 )
    return 10.0;
  v19 = v17 * (1.0 / v6) * v12 + v13 * (1.0 / v6) * v10 + v15 * (1.0 / v6) * v11 - v6;
  if ( result < v19 )
    result = v19;
  v7 = *(_DWORD *)(this + 272);
  v8 = *(float *)(v7 + 4);
  v7 += 4;
  v14 = v8 - *(float *)(this + 4);
  v16 = *(float *)(v7 + 4) - *(float *)(this + 8);
  v18 = *(float *)(v7 + 8) - *(float *)(this + 12);
  v9 = sqrt(v18 * v18 + v16 * v16 + v14 * v14);
  if ( v9 == 0.0 )
    return 10.0;
  v20 = v18 * (1.0 / v9) * v12 + v14 * (1.0 / v9) * v10 + v16 * (1.0 / v9) * v11 - v9;
  if ( result < v20 )
    result = v20;
  v21 = fabs(v11) - 3.0;
  if ( result < v21 )
    return v21;
  return result;
}
