int __stdcall sub_417460(int a1, float *a2, float *a3, float *a4, float a5, int a6)
{
  double v6; // st7
  float v7; // edx
  double v8; // st7
  double v9; // st7
  float v10; // edx
  float v11; // ecx
  double v12; // st7
  float v14; // [esp+0h] [ebp-3Ch]
  int v15; // [esp+Ch] [ebp-30h] BYREF
  float v16; // [esp+10h] [ebp-2Ch]
  float v17; // [esp+14h] [ebp-28h]
  int v18; // [esp+18h] [ebp-24h]
  float v19; // [esp+1Ch] [ebp-20h]
  float v20; // [esp+20h] [ebp-1Ch]
  int v21; // [esp+24h] [ebp-18h] BYREF
  float v22; // [esp+28h] [ebp-14h]
  float v23; // [esp+2Ch] [ebp-10h]
  int v24[3]; // [esp+30h] [ebp-Ch] BYREF

  *(float *)&v15 = *a2 * 0.89999998;
  v16 = a2[1] * 0.89999998;
  v6 = a2[2] * 0.89999998;
  v21 = v15;
  v22 = v16;
  v17 = v6;
  v23 = v17;
  sub_416420((float *)(a1 + 15936), (float *)(a1 + 2776), (float *)&v21, (float *)v24);
  v15 = *(int *)(a1 + 76);
  v7 = *(float *)(a1 + 80);
  v17 = *(float *)(a1 + 84);
  v8 = v17 * a4[2];
  v16 = v7;
  v9 = v8 + *(float *)&v15 * *a4 + v7 * a4[1];
  if ( a6 == 9 || a6 == 10 )
  {
    *(float *)&v18 = v9 * *a4;
    v21 = v18;
    v19 = v9 * a4[1];
    v22 = v19;
    v20 = v9 * a4[2];
    v23 = v20;
    *(float *)&v18 = *(float *)&v15 - *(float *)&v18;
    v15 = v18;
    v19 = v16 - v19;
    v10 = v19;
    v20 = v17 - v20;
    v11 = v20;
  }
  else
  {
    v15 = *(int *)(a1 + 76);
    v10 = *(float *)(a1 + 80);
    v11 = *(float *)(a1 + 84);
  }
  v17 = v11;
  v12 = a3[2];
  v16 = v10;
  v14 = sqrt(*a3 * *a3 + a3[1] * a3[1] + v12 * v12) + 0.5;
  return sub_546320((int)v24, (int)&v15, (int)a4, a5, v14, *(_DWORD *)(a1 + 14796));
}
