// f1c  0x0050db5c  size=308
float *__stdcall sub_50DB5C(float *a1, float *a2)
{
  double v3; // st7
  float *result; // eax
  long double v5; // st6
  double v6; // st7
  double v7; // st6
  int v8; // ebx
  int v9; // edx
  int v10; // edi
  int v11; // esi
  long double v12; // st7
  long double v13; // st6
  long double v14; // st7
  double v15; // st6
  int v16; // ebx
  int v17; // edi
  int v18; // esi
  double v19; // st6
  int v20; // edi
  _DWORD v21[3]; // [esp+0h] [ebp-1Ch]
  float v22; // [esp+Ch] [ebp-10h]
  float v23; // [esp+10h] [ebp-Ch]
  float v24; // [esp+14h] [ebp-8h]
  int v25; // [esp+18h] [ebp-4h]
  int v26; // [esp+24h] [ebp+8h]
  int v27; // [esp+28h] [ebp+Ch]

  v3 = a2[5] + *a2 + a2[10];
  if ( v3 <= 0.0 )
  {
    v21[2] = 0;
    v6 = *a2 - a2[5] - a2[10];
    v22 = v6;
    v21[0] = 1;
    v7 = a2[5];
    v21[1] = 2;
    v23 = v7 - *a2 - a2[10];
    v24 = a2[10] - (a2[5] + *a2);
    v8 = v6 < v23;
    v27 = v8;
    if ( *(&v22 + v8) < (double)v24 )
    {
      v8 = 2;
      v27 = 2;
    }
    v9 = v8;
    result = a1;
    v11 = v21[v8];
    v12 = sqrt(*(&v22 + v8) + 1.0);
    v25 = v21[v8];
    v10 = v25;
    v13 = v12 * 0.5;
    a1[v9] = v13;
    v14 = 0.25 / v13;
    v15 = a2[v11 * 4 + v8] + a2[4 * v8 + v10];
    v16 = 4 * v21[v11] + v27;
    v26 = v21[v11];
    v17 = v21[v11];
    result[v11] = v15 * v14;
    v18 = v17 + v11 * 4;
    v19 = a2[v16] + a2[v17 + v9 * 4];
    v20 = v25;
    result[v26] = v19 * v14;
    result[3] = (a2[v18] - a2[v20 + v26 * 4]) * v14;
  }
  else
  {
    result = a1;
    v5 = sqrt(v3 + 1.0) * 0.5;
    a1[3] = v5;
    *a1 = (a2[6] - a2[9]) * (0.25 / v5);
    a1[1] = (a2[8] - a2[2]) * (0.25 / v5);
    a1[2] = (a2[1] - a2[4]) * (0.25 / v5);
  }
  return result;
}
