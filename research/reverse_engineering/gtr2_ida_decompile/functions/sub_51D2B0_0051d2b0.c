int __stdcall sub_51D2B0(float *a1, float *a2, int a3)
{
  long double v3; // st7
  double v4; // st7
  long double v5; // st7
  float v7; // [esp+4h] [ebp-24h]
  float v8; // [esp+8h] [ebp-20h]
  float v9; // [esp+Ch] [ebp-1Ch]
  float v10; // [esp+10h] [ebp-18h]
  float v11; // [esp+10h] [ebp-18h]
  float v12; // [esp+14h] [ebp-14h]
  float v13; // [esp+14h] [ebp-14h]
  float v14; // [esp+18h] [ebp-10h]
  float v15; // [esp+18h] [ebp-10h]
  float v16; // [esp+1Ch] [ebp-Ch]
  float v17; // [esp+20h] [ebp-8h]
  float v18; // [esp+24h] [ebp-4h]

  v10 = *a2 - *a1;
  v12 = a2[1] - a1[1];
  v14 = a2[2] - a1[2];
  v3 = 1.0 / sqrt(v14 * v14 + v12 * v12 + v10 * v10);
  v7 = v10 * v3;
  v8 = v12 * v3;
  v9 = v14 * v3;
  v4 = v8 * 0.0;
  v16 = v9 - v4;
  v17 = v7 * 0.0 - v9 * 0.0;
  v18 = v4 - v7;
  v5 = 1.0 / sqrt(v18 * v18 + v17 * v17 + v16 * v16);
  v11 = v16 * v5;
  v13 = v17 * v5;
  v15 = v18 * v5;
  sub_5D8280(a3);
  *(float *)(a3 + 4) = v11;
  *(float *)(a3 + 8) = v13;
  *(float *)(a3 + 12) = v15;
  *(_DWORD *)(a3 + 20) = 0;
  *(_DWORD *)(a3 + 28) = 0;
  *(_DWORD *)(a3 + 24) = 1065353216;
  *(float *)(a3 + 40) = v8;
  *(float *)(a3 + 36) = v7;
  *(float *)(a3 + 44) = v9;
  return sub_5D8B90(a3);
}
