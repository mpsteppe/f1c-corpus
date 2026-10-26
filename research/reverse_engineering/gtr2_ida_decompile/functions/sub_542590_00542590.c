int __thiscall sub_542590(float *this, int a2, float *a3)
{
  long double v3; // st7
  long double v4; // st7
  float v6; // [esp+10h] [ebp-24h]
  float v7; // [esp+14h] [ebp-20h]
  float v8; // [esp+18h] [ebp-1Ch]
  float v9; // [esp+1Ch] [ebp-18h]
  float v10; // [esp+1Ch] [ebp-18h]
  float v11; // [esp+1Ch] [ebp-18h]
  float v12; // [esp+20h] [ebp-14h]
  float v13; // [esp+20h] [ebp-14h]
  float v14; // [esp+20h] [ebp-14h]
  float v15; // [esp+24h] [ebp-10h]
  float v16; // [esp+24h] [ebp-10h]
  float v17; // [esp+24h] [ebp-10h]
  float v18; // [esp+28h] [ebp-Ch]
  float v19; // [esp+28h] [ebp-Ch]
  float v20; // [esp+2Ch] [ebp-8h]
  float v21; // [esp+2Ch] [ebp-8h]
  float v22; // [esp+30h] [ebp-4h]
  float v23; // [esp+30h] [ebp-4h]

  v9 = a3[1] * *(float *)(a2 + 80) - a3[2] * *(float *)(a2 + 76);
  v12 = a3[2] * *(float *)(a2 + 72) - *(float *)(a2 + 80) * *a3;
  v15 = *(float *)(a2 + 76) * *a3 - a3[1] * *(float *)(a2 + 72);
  v3 = v15 * v15 + v12 * v12 + v9 * v9;
  if ( v3 > 0.0 )
  {
    v4 = this[4] / sqrt(v3) * 0.5;
    v6 = v9 * v4;
    v7 = v12 * v4;
    v8 = v15 * v4;
  }
  else
  {
    v6 = 0.0;
    v8 = 0.0;
    v7 = this[4] * 0.5;
  }
  v18 = v6 + *(float *)(a2 + 44);
  v20 = v7 + *(float *)(a2 + 48);
  v22 = v8 + *(float *)(a2 + 52);
  sub_5FCE00(*(_DWORD *)a2, 1, v18, v20, v22, *(_DWORD *)(a2 + 96));
  v10 = v18 - *a3;
  v13 = v20 - a3[1];
  v16 = v22 - a3[2];
  sub_5FCE00(*(_DWORD *)a2, 2, v10, v13, v16, *(_DWORD *)(a2 + 96));
  v19 = *(float *)(a2 + 44) - v6;
  v21 = *(float *)(a2 + 48) - v7;
  v23 = *(float *)(a2 + 52) - v8;
  sub_5FCE00(*(_DWORD *)a2, 0, v19, v21, v23, *(_DWORD *)(a2 + 96));
  v11 = v19 - *a3;
  v14 = v21 - a3[1];
  v17 = v23 - a3[2];
  return sub_5FCE00(*(_DWORD *)a2, 3, v11, v14, v17, *(_DWORD *)(a2 + 96));
}
