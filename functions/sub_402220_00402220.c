void __thiscall sub_402220(float *this, float *a2, float *a3, int a4)
{
  float *v4; // eax
  double v5; // st7
  float *v6; // esi
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  float *v11; // edi
  double v12; // st6
  double v13; // st7
  double v14; // st7
  int v15; // eax
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  int v20; // eax
  double v21; // st7
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st6
  double v27; // st6
  double v28; // st6
  float v29; // [esp+Ch] [ebp-5Ch]
  float v30; // [esp+10h] [ebp-58h]
  float v31; // [esp+14h] [ebp-54h]
  float v32; // [esp+18h] [ebp-50h]
  float v33; // [esp+1Ch] [ebp-4Ch]
  float v34; // [esp+1Ch] [ebp-4Ch]
  float v35; // [esp+1Ch] [ebp-4Ch]
  float v36; // [esp+20h] [ebp-48h]
  float v37; // [esp+20h] [ebp-48h]
  float v38; // [esp+20h] [ebp-48h]
  float v39; // [esp+24h] [ebp-44h]
  float v40; // [esp+24h] [ebp-44h]
  float v41; // [esp+24h] [ebp-44h]
  float v42; // [esp+2Ch] [ebp-3Ch]
  float v43; // [esp+2Ch] [ebp-3Ch]
  float v44; // [esp+30h] [ebp-38h]
  float v45; // [esp+30h] [ebp-38h]
  double v46; // [esp+34h] [ebp-34h] BYREF
  double v47; // [esp+3Ch] [ebp-2Ch]
  double v48; // [esp+44h] [ebp-24h]
  int v49; // [esp+4Ch] [ebp-1Ch]
  int v50; // [esp+50h] [ebp-18h]
  int v51; // [esp+54h] [ebp-14h]
  int v52; // [esp+58h] [ebp-10h]
  double v53; // [esp+5Ch] [ebp-Ch]
  int v54; // [esp+64h] [ebp-4h]

  if ( a4 )
  {
    v4 = a2;
    if ( a4 == 1 )
    {
      v6 = a3;
      v42 = a2[7] * a2[9];
      v44 = a2[7] * a2[10];
      v33 = a2[7] * a2[8] + *a2;
      v36 = v42 + a2[1];
      v7 = v44 + a2[2];
      *a3 = v33;
      a3[1] = v36;
      v39 = v7;
      a3[2] = v39;
      v8 = this[1];
      goto LABEL_7;
    }
    v5 = a2[6];
  }
  else
  {
    v4 = a2;
    v5 = a2[71] + a2[6];
  }
  v6 = a3;
  v43 = v5 * v4[9];
  v45 = v5 * v4[10];
  v34 = v5 * v4[8] + *v4;
  v37 = v43 + v4[1];
  v9 = v45 + v4[2];
  *a3 = v34;
  a3[1] = v37;
  v40 = v9;
  a3[2] = v40;
  v8 = *this;
LABEL_7:
  v10 = v8 * 0.5;
  v11 = v6 + 3;
  v49 = 0;
  v50 = 1072693248;
  v51 = 0x40000000;
  v12 = v10 * v4[8];
  v52 = 1201543096;
  v54 = 0;
  v35 = v12;
  v38 = v10 * v4[9];
  v13 = v10 * v4[10];
  v6[3] = v35;
  v6[4] = v38;
  v41 = v13;
  v46 = *v6;
  v14 = v6[1];
  v6[5] = v41;
  v47 = v14;
  v48 = v6[2];
  v15 = SpatialGridQuery(&v46);
  if ( v15 )
  {
    v54 = v15;
    v29 = v53;
    v16 = *v6 - *v11;
    v49 = 0;
    v46 = v16;
    v17 = v6[1];
    v50 = 1075052544;
    v47 = v17;
    v18 = v6[2];
    v51 = 0x40000000;
    v19 = v18 - v6[5];
    v52 = 1201543096;
    v48 = v19;
    v20 = SpatialGridQuery(&v46);
    if ( v20 )
      v30 = v53;
    else
      v30 = v29;
    v21 = *v11 + *v6;
    v49 = 0;
    v46 = v21;
    v22 = v6[1];
    v50 = 1075052544;
    v47 = v22;
    v23 = v6[5];
    v51 = 0x40000000;
    v24 = v23 + v6[2];
    v52 = 1201543096;
    v54 = v20;
    v48 = v24;
    if ( SpatialGridQuery(&v46) )
      v25 = v53;
    else
      v25 = v29;
    v26 = v29 + v29;
    v31 = v26;
    v27 = v26 - v30;
    if ( v25 > v27 + 0.34999999 || v25 < v27 - 0.34999999 )
    {
      if ( fabs(v30 - v29) >= fabs(v25 - v29) )
      {
        v30 = v31 - v25;
      }
      else
      {
        v32 = v27;
        v25 = v32;
      }
    }
    v28 = (v30 + v25) * 0.5;
    if ( v29 > v28 )
      v28 = v29;
    v6[1] = v28 + 0.059999999;
    v6[4] = (v25 - v30) * 0.5;
  }
}
