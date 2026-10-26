void __thiscall sub_4039C0(float *this, float *a2, float *a3, int a4)
{
  float *v4; // eax
  double v5; // st7
  float *v6; // edx
  double v7; // st7
  float v8; // edi
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  float *v15; // edi
  double v16; // st7
  int v17; // eax
  int v18; // eax
  double v19; // st7
  double v20; // st7
  double v21; // st6
  double v22; // st6
  double v23; // st6
  float v24; // [esp+8h] [ebp-60h]
  float v25; // [esp+Ch] [ebp-5Ch]
  float v26; // [esp+10h] [ebp-58h]
  float v27; // [esp+14h] [ebp-54h]
  float v28; // [esp+18h] [ebp-50h]
  float v29; // [esp+18h] [ebp-50h]
  float v30; // [esp+1Ch] [ebp-4Ch]
  float v31; // [esp+1Ch] [ebp-4Ch]
  float v32; // [esp+20h] [ebp-48h]
  float v33; // [esp+20h] [ebp-48h]
  float v34; // [esp+24h] [ebp-44h]
  float v35; // [esp+24h] [ebp-44h]
  float v36; // [esp+24h] [ebp-44h]
  float v37; // [esp+24h] [ebp-44h]
  float v38; // [esp+24h] [ebp-44h]
  float v39; // [esp+28h] [ebp-40h]
  float v40; // [esp+28h] [ebp-40h]
  float v41; // [esp+28h] [ebp-40h]
  float v42; // [esp+28h] [ebp-40h]
  float v43; // [esp+28h] [ebp-40h]
  float v44; // [esp+2Ch] [ebp-3Ch]
  float v45; // [esp+2Ch] [ebp-3Ch]
  float v46; // [esp+2Ch] [ebp-3Ch]
  float v47; // [esp+2Ch] [ebp-3Ch]
  float v48; // [esp+2Ch] [ebp-3Ch]
  double v49; // [esp+30h] [ebp-38h] BYREF
  double v50; // [esp+38h] [ebp-30h]
  double v51; // [esp+40h] [ebp-28h]
  double v52; // [esp+48h] [ebp-20h]
  double v53; // [esp+50h] [ebp-18h]
  double v54; // [esp+58h] [ebp-10h]
  int v55; // [esp+60h] [ebp-8h]

  if ( a4 )
  {
    v4 = a2;
    if ( a4 == 1 )
    {
      v9 = a2[8];
      v34 = v9 * a2[9];
      v39 = v9 * a2[10];
      v44 = v9 * a2[11];
      v35 = v34 + a2[1];
      v40 = v39 + a2[2];
      v10 = v44 + a2[3];
      *a3 = v35;
      a3[1] = v40;
      v45 = v10;
      a3[2] = v45;
      v11 = this[2];
      goto LABEL_7;
    }
    v12 = a2[7];
    v36 = v12 * a2[9];
    v41 = v12 * a2[10];
    v46 = v12 * a2[11];
    v6 = a3;
    v37 = v36 + a2[1];
    v42 = v41 + a2[2];
    v13 = v46 + a2[3];
    *a3 = v37;
    a3[1] = v42;
    v47 = v13;
    v8 = v47;
  }
  else
  {
    v4 = a2;
    v5 = a2[72] + a2[7];
    v28 = v5 * a2[9];
    v30 = v5 * a2[10];
    v32 = v5 * a2[11];
    v6 = a3;
    v29 = v28 + a2[1];
    v31 = v30 + a2[2];
    v7 = v32 + a2[3];
    *a3 = v29;
    a3[1] = v31;
    v33 = v7;
    v8 = v33;
  }
  v6[2] = v8;
  v11 = this[1];
LABEL_7:
  v14 = v11 * 0.5;
  v15 = a3 + 3;
  v55 = 0;
  v38 = v14 * v4[9];
  v43 = v14 * v4[10];
  v16 = v14 * v4[11];
  a3[3] = v38;
  a3[4] = v43;
  v48 = v16;
  v49 = *a3;
  a3[5] = v48;
  v50 = a3[1];
  v51 = a3[2];
  v52 = 1.0;
  v53 = 9.999999933815813e36;
  v17 = sub_45D190(&v49);
  if ( v17 )
  {
    v55 = v17;
    v24 = v54;
    v49 = *a3 - *v15;
    v50 = a3[1];
    v51 = a3[2] - a3[5];
    v52 = 5.0;
    v53 = 9.999999933815813e36;
    v18 = sub_45D190(&v49);
    if ( v18 )
      v25 = v54;
    else
      v25 = v24;
    v19 = *a3 + *v15;
    v55 = v18;
    v49 = v19;
    v50 = a3[1];
    v51 = a3[5] + a3[2];
    v52 = 5.0;
    v53 = 9.999999933815813e36;
    if ( sub_45D190(&v49) )
      v20 = v54;
    else
      v20 = v24;
    v21 = v24 + v24;
    v26 = v21;
    v22 = v21 - v25;
    if ( v20 > v22 + 0.34999999 || v20 < v22 - 0.34999999 )
    {
      if ( fabs(v25 - v24) >= fabs(v20 - v24) )
      {
        v25 = v26 - v20;
      }
      else
      {
        v27 = v22;
        v20 = v27;
      }
    }
    v23 = (v25 + v20) * 0.5;
    if ( v24 > v23 )
      v23 = v24;
    a3[1] = flt_B715F0 + v23;
    a3[4] = (v20 - v25) * 0.5;
  }
}
