void __thiscall sub_567120(float *this, float *a2, int a3)
{
  float *v4; // ecx
  long double v5; // st4
  __int16 v6; // fps
  bool v7; // c0
  char v8; // c2
  bool v9; // c3
  long double v10; // st7
  long double v11; // st6
  long double v12; // rt0
  long double v13; // st7
  long double v14; // st7
  int v15; // eax
  float *v16; // edx
  double v17; // st5
  double v18; // st4
  double v19; // st3
  double v20; // st7
  long double v21; // st7
  float v22; // [esp+4h] [ebp-54h]
  float v23; // [esp+8h] [ebp-50h]
  float v24; // [esp+Ch] [ebp-4Ch]
  float v25; // [esp+10h] [ebp-48h]
  float v26; // [esp+14h] [ebp-44h]
  float v27; // [esp+18h] [ebp-40h]
  float v28; // [esp+1Ch] [ebp-3Ch]
  float v29; // [esp+20h] [ebp-38h]
  float v30; // [esp+24h] [ebp-34h]
  float v31; // [esp+28h] [ebp-30h]
  float v32; // [esp+2Ch] [ebp-2Ch]
  float v33; // [esp+34h] [ebp-24h]
  float v34; // [esp+38h] [ebp-20h]
  float v35; // [esp+3Ch] [ebp-1Ch]
  float v36; // [esp+40h] [ebp-18h]
  float v37; // [esp+44h] [ebp-14h]
  float v38; // [esp+48h] [ebp-10h]
  float v39; // [esp+4Ch] [ebp-Ch]
  float v40; // [esp+5Ch] [ebp+4h]

  v4 = a2;
  v5 = *a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2];
  v7 = v5 < 0.0;
  v8 = 0;
  v9 = v5 == 0.0;
  if ( (v6 & 0x4100) == 0 )
  {
    v10 = sqrt(v5);
    v31 = -1.0 / v10 * *a2;
    v32 = -1.0 / v10 * a2[1];
    v11 = -1.0 / v10 * a2[2];
    v12 = sin(v10);
    v40 = cos(v10);
    v22 = 1.0 - v40;
    v29 = v31 * v12;
    v28 = v32 * v12;
    v25 = v12 * v11;
    v24 = v32 * v31 * v22;
    v27 = v31 * v11 * v22;
    v13 = v11 * v32 * v22;
    v38 = v29 + v13;
    v14 = v13 - v29;
    v15 = 0;
    v16 = this + 2;
    v4 = this + 1;
    do
    {
      v17 = this[v15];
      v18 = *v4;
      v19 = *v16;
      v36 = v24 - v25;
      v15 += 3;
      v4 += 3;
      v16 += 3;
      v23 = v31 * v31;
      v33 = (1.0 - v23) * v40 + v23;
      v39 = v27 + v28;
      this[v15 - 3] = v39 * v19 + v18 * v36 + v17 * v33;
      v34 = v24 + v25;
      v26 = v32 * v32;
      v37 = (1.0 - v26) * v40 + v26;
      this[v15 - 2] = v19 * v14 + v18 * v37 + v17 * v34;
      v35 = v27 - v28;
      v30 = v11 * v11;
      this[v15 - 1] = v19 * ((1.0 - v30) * v40 + v30) + v18 * v38 + v17 * v35;
    }
    while ( v15 < 9 );
  }
  v20 = this[5];
  FloatConvertWrapper(v4);
  *(float *)a3 = -v20;
  if ( fabs(this[5]) == 1.0 )
  {
    v21 = atan2(-this[6], *this);
    *(_DWORD *)(a3 + 8) = 0;
    *(float *)(a3 + 4) = v21;
  }
  else
  {
    *(float *)(a3 + 4) = atan2(this[2], this[8]);
    *(float *)(a3 + 8) = atan2(this[3], this[4]);
  }
}

