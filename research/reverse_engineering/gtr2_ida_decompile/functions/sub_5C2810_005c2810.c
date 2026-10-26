void __stdcall sub_5C2810(float *a1, float *a2, float *a3, float *a4, float *a5, float *a6, float *a7, float *a8)
{
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // st5
  long double v15; // st4
  double v16; // st4
  double v17; // st3
  double v18; // st4
  long double v19; // st3
  double v20; // st4
  double v21; // rt0
  double v22; // st7
  long double v23; // st6
  long double v24; // st7
  long double v25; // st7
  long double v26; // st7
  long double v27; // st7
  double v28; // st6
  double v29; // st7
  float v30; // [esp+4h] [ebp-30h]
  float v31; // [esp+8h] [ebp-2Ch]
  float v32; // [esp+Ch] [ebp-28h]
  float v33; // [esp+10h] [ebp-24h]
  float v34; // [esp+18h] [ebp-1Ch]
  float v35; // [esp+1Ch] [ebp-18h]
  float v36; // [esp+24h] [ebp-10h]
  float v37; // [esp+28h] [ebp-Ch]
  float v38; // [esp+28h] [ebp-Ch]
  float v39; // [esp+2Ch] [ebp-8h]
  float v40; // [esp+2Ch] [ebp-8h]
  float v41; // [esp+30h] [ebp-4h]
  float v42; // [esp+38h] [ebp+4h]
  float v43; // [esp+3Ch] [ebp+8h]
  float v44; // [esp+44h] [ebp+10h]
  float v45; // [esp+48h] [ebp+14h]
  float v46; // [esp+50h] [ebp+1Ch]
  float v47; // [esp+54h] [ebp+20h]

  *a7 = 0.0;
  a7[1] = 0.0;
  a7[2] = 0.0;
  if ( a8 )
  {
    *a8 = 0.0;
    a8[1] = 0.0;
    a8[2] = 0.0;
  }
  v46 = 0.0;
  v33 = *a2 - *a1;
  v11 = *a5 - *a4;
  v34 = a5[1] - a4[1];
  v35 = *a3 - *a1;
  v12 = *a6 - *a4;
  v13 = a6[1] - a4[1];
  v36 = v13;
  v14 = v13 * v11 - v12 * v34;
  v30 = v14;
  v31 = v35 * v34 - v36 * v33;
  v32 = v12 * v33 - v35 * v11;
  v15 = fabs(v30);
  if ( v15 > 0.0000099999997 )
    v46 = -1.0 / v30 * v31;
  v42 = 0.0;
  if ( v15 > 0.0000099999997 )
    v42 = -(v32 / v30);
  v47 = 0.0;
  v16 = a2[1] - a1[1];
  v17 = a3[1] - a1[1];
  v37 = v14;
  v39 = v34 * v17 - v36 * v16;
  v18 = v16 * v12 - v17 * v11;
  v19 = fabs(v37);
  if ( v19 > 0.0000099999997 )
    v47 = -1.0 / v37 * v39;
  v45 = 0.0;
  if ( v19 > 0.0000099999997 )
    v45 = -(v18 / v37);
  v20 = a2[2] - a1[2];
  v43 = 0.0;
  v21 = a3[2] - a1[2];
  v38 = v14;
  v40 = v34 * v21 - v36 * v20;
  v22 = v12 * v20 - v21 * v11;
  v23 = fabs(v38);
  if ( v23 > 0.0000099999997 )
    v43 = -1.0 / v38 * v40;
  v44 = 0.0;
  if ( v23 > 0.0000099999997 )
    v44 = -(v22 / v38);
  *a7 = v46;
  a7[2] = v43;
  a7[1] = v47;
  v24 = sqrt(v43 * v43 + v47 * v47 + v46 * v46);
  if ( v24 <= 0.0000099999997 )
  {
    *a7 = 0.0;
    a7[1] = 0.0;
    a7[2] = 1.0;
  }
  else
  {
    v25 = 1.0 / v24;
    *a7 = v46 * v25;
    a7[1] = v47 * v25;
    a7[2] = v25 * v43;
  }
  if ( a8 )
  {
    *a8 = v42;
    a8[1] = v45;
    a8[2] = v44;
    v26 = sqrt(v44 * v44 + v45 * v45 + v42 * v42);
    if ( v26 <= 0.0000099999997 )
    {
      v41 = v31 * *a7 - v30 * a7[1];
      v28 = v32 * a7[1] - v31 * a7[2];
      v29 = v30 * a7[2] - v32 * *a7;
      a8[2] = v41;
      *a8 = v28;
      a8[1] = v29;
    }
    else
    {
      v27 = 1.0 / v26;
      *a8 = v42 * v27;
      a8[1] = v45 * v27;
      a8[2] = v27 * v44;
    }
  }
}
