int __thiscall sub_544F00(int this, float *a2, float *a3, float a4, int a5, float *a6)
{
  int result; // eax
  int v8; // edi
  double v9; // st7
  double v10; // st7
  long double v11; // st6
  float v12; // ecx
  float v13; // eax
  double v14; // st7
  double v15; // st7
  int v16; // eax
  double v17; // st7
  unsigned int v18; // eax
  int v19; // eax
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st7
  int v24; // esi
  float v25; // [esp+0h] [ebp-44h]
  int v26; // [esp+0h] [ebp-44h]
  int v27; // [esp+0h] [ebp-44h]
  float v28; // [esp+14h] [ebp-30h] BYREF
  float v29; // [esp+18h] [ebp-2Ch]
  float v30; // [esp+1Ch] [ebp-28h]
  float v31; // [esp+20h] [ebp-24h] BYREF
  float v32; // [esp+24h] [ebp-20h]
  float v33; // [esp+28h] [ebp-1Ch]
  float v34; // [esp+2Ch] [ebp-18h]
  float v35; // [esp+30h] [ebp-14h]
  float v36; // [esp+34h] [ebp-10h]
  float v37; // [esp+38h] [ebp-Ch]
  float v38; // [esp+3Ch] [ebp-8h]
  float v39; // [esp+40h] [ebp-4h]

  result = *(_DWORD *)(this + 96);
  if ( result > 0 )
  {
    v8 = sub_5424A0();
    if ( dword_BE1204 == 2 )
      v9 = sub_5210A0(&dword_BE120C);
    else
      v9 = dbl_FB1D18;
    *(float *)(v8 + 8) = v9;
    *(_DWORD *)(v8 + 12) = 2139095039;
    if ( a6 )
    {
      v12 = *a6;
      v13 = a6[2];
      v29 = a6[1];
      v10 = v29;
      v28 = v12;
      v30 = v13;
    }
    else
    {
      v10 = 0.0;
      v28 = 0.0;
      v11 = a3[1];
      v30 = 0.0;
      if ( fabs(v11) <= 0.99000001 )
        v10 = 1.0;
      else
        v28 = 1.0;
    }
    v34 = v10 * a3[2] - v30 * a3[1];
    v31 = v34;
    v35 = v30 * *a3 - v28 * a3[2];
    v32 = v35;
    v36 = v28 * a3[1] - v10 * *a3;
    v33 = v36;
    sub_409390(&v31);
    v14 = *(float *)(this + 12) * 0.5;
    v31 = v31 * v14;
    v32 = v32 * v14;
    v33 = v33 * v14;
    v34 = v33 * a3[1] - v32 * a3[2];
    v28 = v34;
    v35 = v31 * a3[2] - v33 * *a3;
    v29 = v35;
    v36 = v32 * *a3 - v31 * a3[1];
    v30 = v36;
    sub_409390(&v28);
    v15 = *(float *)(this + 16) * 0.5;
    v28 = v28 * v15;
    v29 = v29 * v15;
    v30 = v15 * v30;
    v25 = a4 * 254.0;
    v16 = sub_4015C0(v25);
    v17 = v31;
    v18 = (unsigned int)byte_FFFFFF & a5 | (v16 << 24);
    *(_DWORD *)(v8 + 96) = v18;
    v26 = v18;
    v19 = *(_DWORD *)v8;
    v34 = v17 + *a2;
    v37 = v34;
    v35 = v32 + a2[1];
    v38 = v35;
    v36 = v33 + a2[2];
    v39 = v36;
    v34 = v34 + v28;
    v35 = v35 + v29;
    v36 = v36 + v30;
    sub_5FCE00(v19, 0, v34, v35, v36, v26);
    v37 = v31 + *a2;
    v34 = v37;
    v38 = v32 + a2[1];
    v35 = v38;
    v39 = v33 + a2[2];
    v36 = v39;
    v37 = v37 - v28;
    v38 = v38 - v29;
    v39 = v39 - v30;
    sub_5FCE00(*(_DWORD *)v8, 1, v37, v38, v39, *(_DWORD *)(v8 + 96));
    v27 = *(_DWORD *)(v8 + 96);
    v37 = *a2 - v31;
    v20 = a2[1];
    v34 = v37;
    v38 = v20 - v32;
    v21 = a2[2];
    v35 = v38;
    v39 = v21 - v33;
    v36 = v39;
    v37 = v37 - v28;
    v38 = v38 - v29;
    v39 = v39 - v30;
    sub_5FCE00(*(_DWORD *)v8, 2, v37, v38, v39, v27);
    v37 = *a2 - v31;
    v22 = a2[1];
    v34 = v37;
    v38 = v22 - v32;
    v23 = a2[2];
    v24 = *(_DWORD *)(v8 + 96);
    v35 = v38;
    v39 = v23 - v33;
    v36 = v39;
    v37 = v37 + v28;
    v38 = v38 + v29;
    v39 = v39 + v30;
    return sub_5FCE00(*(_DWORD *)v8, 3, v37, v38, v39, v24);
  }
  return result;
}
