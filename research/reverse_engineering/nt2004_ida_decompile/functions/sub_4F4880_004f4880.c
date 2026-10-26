int __thiscall sub_4F4880(float *this)
{
  float *v1; // ebx
  int *v2; // eax
  double v3; // st7
  double v4; // st7
  int result; // eax
  int v6; // ebp
  int v7; // edx
  float *v8; // esi
  float *v9; // edi
  double v10; // st7
  double v11; // st7
  double v12; // st6
  double v13; // st7
  double v14; // st7
  double v15; // st6
  double v17; // st7
  char v18; // c0
  double v19; // st7
  long double v20; // st7
  int v21; // edx
  float *v22; // ebx
  int j; // ebp
  float v24; // ecx
  long double v25; // st7
  float v26; // edx
  double v27; // st7
  double v28; // st6
  float v29; // [esp+0h] [ebp-CCh]
  float v30; // [esp+1Ch] [ebp-B0h]
  int i; // [esp+20h] [ebp-ACh]
  float v33; // [esp+28h] [ebp-A4h]
  int v34; // [esp+2Ch] [ebp-A0h] BYREF
  float v35; // [esp+30h] [ebp-9Ch]
  float v36; // [esp+34h] [ebp-98h]
  float v37; // [esp+38h] [ebp-94h]
  float v38; // [esp+3Ch] [ebp-90h] BYREF
  float v39; // [esp+40h] [ebp-8Ch]
  float v40; // [esp+44h] [ebp-88h]
  float v41; // [esp+48h] [ebp-84h]
  float v42; // [esp+4Ch] [ebp-80h]
  float v43; // [esp+50h] [ebp-7Ch]
  float v44; // [esp+54h] [ebp-78h]
  float v45; // [esp+58h] [ebp-74h]
  float v46; // [esp+5Ch] [ebp-70h]
  float v47; // [esp+60h] [ebp-6Ch]
  float v48; // [esp+64h] [ebp-68h]
  float v49; // [esp+68h] [ebp-64h]
  float v50; // [esp+6Ch] [ebp-60h]
  int v51; // [esp+70h] [ebp-5Ch]
  float v52; // [esp+74h] [ebp-58h]
  float v53; // [esp+78h] [ebp-54h]
  int v54; // [esp+7Ch] [ebp-50h]
  float v55; // [esp+80h] [ebp-4Ch]
  float v56; // [esp+88h] [ebp-44h]
  float v57; // [esp+8Ch] [ebp-40h]
  float v58[4]; // [esp+90h] [ebp-3Ch] BYREF
  float v59; // [esp+A0h] [ebp-2Ch]
  float v60; // [esp+A4h] [ebp-28h]
  float v61[3]; // [esp+A8h] [ebp-24h] BYREF
  float v62[5]; // [esp+B4h] [ebp-18h] BYREF
  float v63; // [esp+C8h] [ebp-4h]

  v1 = this;
  v2 = (int *)sub_40C460(&dword_6291CC);
  if ( v2 )
  {
    sub_459BE0(v2, &v38);
  }
  else
  {
    v38 = 0.0;
    v39 = 0.0;
    v40 = 0.0;
  }
  if ( dword_7D5DA4 == 2 )
  {
    if ( sub_4DA080(&dword_7D5DAC) == 5 )
    {
      v30 = 0.0;
      goto LABEL_10;
    }
    v3 = sub_4D9E30(&dword_7D5DAC);
  }
  else
  {
    v3 = dbl_7DA9C8;
  }
  v30 = v3;
LABEL_10:
  if ( dword_7D5DA4 == 2 )
    v4 = sub_4D9E20(&dword_7D5DAC);
  else
    v4 = dbl_7DA9D0;
  result = *((_DWORD *)v1 + 27);
  v6 = 0;
  v33 = v4;
  for ( i = 0; v6 < result; i = v6 )
  {
    v7 = *((_DWORD *)v1 + 28);
    v8 = *(float **)(v7 + 4 * v6);
    if ( v33 > (double)v8[3] || v33 < (double)v8[2] )
    {
      sub_4F2B40(v1, *(_DWORD **)(v7 + 4 * v6--));
    }
    else
    {
      v9 = v8 + 11;
      v8[11] = v30 * v8[14] + v8[11];
      v8[12] = v30 * v8[15] + v8[12];
      v8[13] = v30 * v8[16] + v8[13];
      v8[15] = v8[15] - fabs(v30) * 9.8100004;
      v10 = v8[13] * v8[23] + v8[12] * v8[22] + v8[11] * v8[21];
      if ( v10 < v8[25] )
      {
        v11 = v8[25] - v10;
        v12 = v11 * v8[21];
        v56 = v11 * v8[22];
        v57 = v11 * v8[23];
        *v9 = v12 + *v9;
        v8[12] = v56 + v8[12];
        v8[13] = v57 + v8[13];
        v13 = v8[16] * v8[23] + v8[15] * v8[22] + v8[14] * v8[21];
        v14 = v13 + v13;
        v15 = v14 * v8[21];
        v59 = v14 * v8[22];
        v60 = v14 * v8[23];
        v8[14] = v8[14] - v15;
        v8[15] = v8[15] - v59;
        v8[16] = v8[16] - v60;
        v17 = v8[14];
        if ( v18 )
        {
          v8[14] = v17 + v17;
          v8[15] = v8[15] + v8[15];
          v19 = v8[16] + v8[16];
        }
        else
        {
          v8[14] = v17 * 0.5;
          v8[15] = v8[15] * 0.5;
          v19 = v8[16] * 0.5;
        }
        v8[16] = v19;
      }
      if ( (dword_767E44 & 3) != 0 )
      {
        v35 = v8[14] * 0.03125;
        v36 = v8[15] * 0.03125;
        v37 = v8[16] * 0.03125;
        if ( dword_767E44 == 1 )
        {
          if ( dword_75AAC4 )
          {
            v50 = *(float *)(dword_75AAC4 + 1976);
            v20 = v50 - *v9;
            v21 = *(_DWORD *)(dword_75AAC4 + 1980);
            v52 = *(float *)(dword_75AAC4 + 1984);
            v51 = v21;
            if ( fabs(v20) < 4.0 && fabs(v52 - v8[13]) < 4.0 )
            {
              v47 = v35 + *v9;
              v62[0] = v47;
              v48 = v36 + v8[12];
              v62[1] = v48;
              v49 = v37 + v8[13];
              v62[2] = v49;
              sub_4F3550(v62, v8 + 11, (float *)(dword_75AAC4 + 1892));
            }
          }
        }
        else
        {
          v29 = *v9 + v8[13];
          v22 = sub_4F1080(flt_7D6BD0, v29, 5.6568542, &v34);
          for ( j = 0; j < v34; ++j )
          {
            v24 = v22[j];
            v53 = *(float *)(LODWORD(v24) + 1892);
            v25 = v53 - *v9;
            v26 = *(float *)(LODWORD(v24) + 1900);
            v54 = *(_DWORD *)(LODWORD(v24) + 1896);
            v55 = v26;
            if ( fabs(v25) < 4.0
              && fabs(v55 - v8[13]) < 4.0
              && ((dword_767E44 & 1) != 0 || *(_DWORD *)(LODWORD(v24) + 4) != dword_75AAC0) )
            {
              v41 = v35 + *v9;
              v58[0] = v41;
              v42 = v36 + v8[12];
              v58[1] = v42;
              v43 = v37 + v8[13];
              v58[2] = v43;
              sub_4F3550(v58, v8 + 11, (float *)(LODWORD(v24) + 1808));
            }
          }
          v6 = i;
          v1 = this;
        }
      }
      v27 = v8[14] - v38;
      v28 = v8[15] - v39;
      v63 = v8[16] - v40;
      v44 = v27 * 0.03125;
      v61[0] = v44;
      v45 = v28 * 0.03125;
      v61[1] = v45;
      v46 = v63 * 0.03125;
      v61[2] = v46;
      sub_4F3B10(v1, v8, v61);
    }
    result = *((_DWORD *)v1 + 27);
    ++v6;
  }
  return result;
}
