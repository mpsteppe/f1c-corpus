// f1c  0x0050d0c2  size=909
int __stdcall sub_50D0C2(float *a1, float *a2, float *a3)
{
  double v4; // st7
  double v5; // st6
  double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st5
  double v10; // st4
  double v11; // st3
  double v12; // st2
  double v13; // st7
  double v14; // st6
  double v15; // st5
  double v16; // st3
  double v17; // st4
  double v18; // st3
  double v19; // st2
  double v20; // st7
  int result; // eax
  float v22; // [esp+8h] [ebp-54h]
  float v23; // [esp+Ch] [ebp-50h]
  float v24; // [esp+10h] [ebp-4Ch]
  float v25; // [esp+14h] [ebp-48h]
  float v26; // [esp+18h] [ebp-44h]
  float v27; // [esp+1Ch] [ebp-40h]
  float v28; // [esp+20h] [ebp-3Ch]
  float v29; // [esp+24h] [ebp-38h]
  float v30; // [esp+28h] [ebp-34h]
  float v31; // [esp+28h] [ebp-34h]
  float v32; // [esp+2Ch] [ebp-30h]
  float v33; // [esp+2Ch] [ebp-30h]
  float v34; // [esp+30h] [ebp-2Ch]
  float v35; // [esp+30h] [ebp-2Ch]
  float v36; // [esp+34h] [ebp-28h]
  float v37; // [esp+34h] [ebp-28h]
  float v38; // [esp+38h] [ebp-24h]
  float v39; // [esp+38h] [ebp-24h]
  float v40; // [esp+3Ch] [ebp-20h]
  float v41; // [esp+3Ch] [ebp-20h]
  float v42; // [esp+3Ch] [ebp-20h]
  float v43; // [esp+40h] [ebp-1Ch]
  float v44; // [esp+40h] [ebp-1Ch]
  float v45; // [esp+44h] [ebp-18h]
  float v46; // [esp+44h] [ebp-18h]
  float v47; // [esp+48h] [ebp-14h]
  float v48; // [esp+48h] [ebp-14h]
  float v49; // [esp+4Ch] [ebp-10h]
  float v50; // [esp+4Ch] [ebp-10h]
  float v51; // [esp+50h] [ebp-Ch]
  float v52; // [esp+50h] [ebp-Ch]
  float v53; // [esp+54h] [ebp-8h]
  float v54; // [esp+54h] [ebp-8h]
  float v55; // [esp+54h] [ebp-8h]
  float v56; // [esp+58h] [ebp-4h]
  float v57; // [esp+58h] [ebp-4h]
  float v58; // [esp+58h] [ebp-4h]
  float v59; // [esp+58h] [ebp-4h]
  float v60; // [esp+6Ch] [ebp+10h]
  float v61; // [esp+6Ch] [ebp+10h]
  float v62; // [esp+6Ch] [ebp+10h]
  float v63; // [esp+6Ch] [ebp+10h]

  v4 = *a3;
  v5 = a3[1];
  v43 = a3[4];
  v40 = a3[5];
  v45 = a3[8];
  v56 = a3[9];
  v47 = a3[12];
  v60 = a3[13];
  v51 = v40 * v4 - v43 * v5;
  v49 = a3[14];
  v53 = v56 * v4 - v45 * v5;
  v34 = v60 * v4 - v47 * v5;
  v29 = v56 * v43 - v45 * v40;
  v30 = v60 * v43 - v47 * v40;
  v6 = v60;
  v61 = a3[15];
  v32 = v6 * v45 - v47 * v56;
  v7 = a3[2];
  v8 = a3[3];
  v9 = a3[6];
  v36 = a3[6];
  v10 = a3[7];
  v41 = a3[7];
  v11 = a3[10];
  v38 = a3[10];
  v12 = a3[11];
  v57 = a3[11];
  v22 = v7 * v29 - v9 * v53 + v11 * v51;
  v23 = v9 * v34 - v49 * v51 - v7 * v30;
  v24 = v7 * v32 - v11 * v34 + v49 * v53;
  v25 = v11 * v30 - v49 * v29 - v9 * v32;
  v26 = v53 * v10 - v51 * v12 - v29 * v8;
  v27 = v30 * v8 - v34 * v10 + v51 * v61;
  v28 = v34 * v12 - v53 * v61 - v32 * v8;
  v35 = v32 * v10 - v30 * v12 + v29 * v61;
  v52 = v7 * v10 - v9 * v8;
  v54 = v7 * v57 - v38 * v8;
  v13 = v7 * v61 - v49 * v8;
  v44 = a3[4];
  v46 = a3[8];
  v14 = v36 * v57 - v38 * v41;
  v15 = v36 * v61 - v49 * v41;
  v16 = v49 * v57;
  v58 = a3[9];
  v48 = a3[12];
  v17 = v38 * v61 - v16;
  v18 = a3[1];
  v19 = a3[5];
  v62 = a3[13];
  v50 = v54 * v19 - v52 * v58 - v14 * v18;
  v39 = v15 * v18 - v13 * v19 + v52 * v62;
  v37 = v13 * v58 - v54 * v62 - v17 * v18;
  v31 = v17 * v19 - v15 * v58 + v14 * v62;
  v63 = v14 * *a3 - v54 * v44 + v52 * v46;
  v59 = v13 * v44 - v52 * v48 - v15 * *a3;
  v42 = *a3 * v17 - v13 * v46 + v54 * v48;
  v20 = v50 * v48 + v39 * v46 + v37 * v44 + v31 * *a3;
  if ( a2 )
    *a2 = v20;
  v55 = 1.0 / v20;
  result = sub_58A88F(COERCE_UNSIGNED_INT64(v55), HIDWORD(COERCE_UNSIGNED_INT64(v55)));
  if ( result )
  {
    result = (int)a1;
    *a1 = v31 * v55;
    a1[1] = v37 * v55;
    a1[2] = v39 * v55;
    a1[3] = v50 * v55;
    v33 = v15 * v46 - v14 * v48 - v17 * v44;
    a1[4] = v33 * v55;
    a1[5] = v42 * v55;
    a1[6] = v59 * v55;
    a1[7] = v63 * v55;
    a1[8] = v35 * v55;
    a1[9] = v28 * v55;
    a1[10] = v27 * v55;
    a1[11] = v26 * v55;
    a1[12] = v25 * v55;
    a1[13] = v24 * v55;
    a1[14] = v23 * v55;
    a1[15] = v22 * v55;
  }
  return result;
}
