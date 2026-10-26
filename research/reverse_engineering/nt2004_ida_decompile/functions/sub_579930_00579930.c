void __thiscall sub_579930(float *this, float *a2, int a3)
{
  long double v4; // st4
  __int16 v5; // fps
  bool v6; // c0
  char v7; // c2
  bool v8; // c3
  long double v9; // st7
  long double v10; // st6
  long double v11; // rt0
  long double v12; // st7
  long double v13; // st7
  int v14; // eax
  float *v15; // edx
  float *v16; // ecx
  double v17; // st5
  double v18; // st4
  double v19; // st3
  long double v20; // st7
  float v21; // [esp+4h] [ebp-54h]
  float v22; // [esp+8h] [ebp-50h]
  float v23; // [esp+Ch] [ebp-4Ch]
  float v24; // [esp+10h] [ebp-48h]
  float v25; // [esp+14h] [ebp-44h]
  float v26; // [esp+18h] [ebp-40h]
  float v27; // [esp+1Ch] [ebp-3Ch]
  float v28; // [esp+20h] [ebp-38h]
  float v29; // [esp+24h] [ebp-34h]
  float v30; // [esp+28h] [ebp-30h]
  float v31; // [esp+2Ch] [ebp-2Ch]
  float v32; // [esp+34h] [ebp-24h]
  float v33; // [esp+38h] [ebp-20h]
  float v34; // [esp+3Ch] [ebp-1Ch]
  float v35; // [esp+40h] [ebp-18h]
  float v36; // [esp+44h] [ebp-14h]
  float v37; // [esp+48h] [ebp-10h]
  float v38; // [esp+4Ch] [ebp-Ch]
  float v39; // [esp+5Ch] [ebp+4h]

  v4 = *a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2];
  v6 = v4 < 0.0;
  v7 = 0;
  v8 = v4 == 0.0;
  if ( (v5 & 0x4100) == 0 )
  {
    v9 = sqrt(v4);
    v30 = -1.0 / v9 * *a2;
    v31 = -1.0 / v9 * a2[1];
    v10 = -1.0 / v9 * a2[2];
    v11 = sin(v9);
    v39 = cos(v9);
    v21 = 1.0 - v39;
    v28 = v30 * v11;
    v27 = v31 * v11;
    v24 = v11 * v10;
    v23 = v31 * v30 * v21;
    v26 = v30 * v10 * v21;
    v12 = v10 * v31 * v21;
    v37 = v28 + v12;
    v13 = v12 - v28;
    v14 = 0;
    v15 = this + 2;
    v16 = this + 1;
    do
    {
      v17 = this[v14];
      v18 = *v16;
      v19 = *v15;
      v35 = v23 - v24;
      v14 += 3;
      v16 += 3;
      v15 += 3;
      v22 = v30 * v30;
      v32 = (1.0 - v22) * v39 + v22;
      v38 = v26 + v27;
      this[v14 - 3] = v38 * v19 + v18 * v35 + v17 * v32;
      v33 = v23 + v24;
      v25 = v31 * v31;
      v36 = (1.0 - v25) * v39 + v25;
      this[v14 - 2] = v19 * v13 + v18 * v36 + v17 * v33;
      v34 = v26 - v27;
      v29 = v10 * v10;
      this[v14 - 1] = v19 * ((1.0 - v29) * v39 + v29) + v18 * v37 + v17 * v34;
    }
    while ( v14 < 9 );
  }
  *(float *)a3 = -asin(this[5]);
  if ( fabs(this[5]) == 1.0 )
  {
    v20 = atan2(-this[6], *this);
    *(_DWORD *)(a3 + 8) = 0;
    *(float *)(a3 + 4) = v20;
  }
  else
  {
    *(float *)(a3 + 4) = atan2(this[2], this[8]);
    *(float *)(a3 + 8) = atan2(this[3], this[4]);
  }
}
