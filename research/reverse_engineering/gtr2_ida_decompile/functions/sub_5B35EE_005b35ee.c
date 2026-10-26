float *__stdcall sub_5B35EE(float *a1, float *a2)
{
  double v3; // st7
  float *result; // eax
  long double v5; // st6
  double v6; // st7
  float v7; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // edi
  int v11; // esi
  double v12; // st7
  double v13; // st7
  long double v14; // st6
  long double v15; // st7
  double v16; // st6
  int v17; // ebx
  int v18; // edi
  int v19; // edx
  int v20; // esi
  double v21; // st6
  int v22; // edx
  int v23; // edi
  float v24; // [esp+0h] [ebp-14h]
  float v25; // [esp+4h] [ebp-10h]
  float v26; // [esp+8h] [ebp-Ch]
  int v27; // [esp+Ch] [ebp-8h]
  int v28; // [esp+10h] [ebp-4h]
  int v29; // [esp+20h] [ebp+Ch]

  v3 = a2[5] + *a2 + a2[10];
  if ( v3 <= 0.0 )
  {
    v6 = *a2;
    v25 = a2[5];
    v7 = a2[10];
    v24 = v6;
    v26 = v7;
    v8 = v6 < v25;
    v29 = v8;
    if ( *(&v24 + v8) < (double)v7 )
    {
      v8 = 2;
      v29 = 2;
    }
    v9 = v8;
    v10 = dword_729380[v8];
    v11 = v10;
    v12 = *(&v24 + v8) - *(&v24 + v10);
    v28 = dword_729380[v10];
    v13 = v12 - *(&v24 + v28);
    result = a1;
    v27 = v10;
    v14 = sqrt(v13 + 1.0) * 0.5;
    a1[v9] = v14;
    v15 = 0.25 / v14;
    v16 = a2[4 * v10 + v8] + a2[4 * v8 + v10];
    v17 = 4 * v28 + v29;
    v18 = v28;
    v19 = v28 + v9 * 4;
    a1[v11] = v16 * v15;
    v20 = v18 + v11 * 4;
    v21 = a2[v17] + a2[v19];
    v22 = v18;
    v23 = v27;
    v22 *= 4;
    *(float *)((char *)a1 + v22) = v21 * v15;
    a1[3] = (a2[v20] - a2[v23 + v22]) * v15;
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
