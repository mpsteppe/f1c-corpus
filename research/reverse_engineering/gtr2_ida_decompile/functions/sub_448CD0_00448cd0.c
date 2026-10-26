char __thiscall sub_448CD0(int this)
{
  double v2; // st7
  double v3; // st7
  float v4; // ecx
  float v5; // edx
  double *v6; // eax
  double *v7; // eax
  double v8; // st5
  double v9; // rt2
  double *v10; // ecx
  double v11; // st7
  double v12; // st6
  double v13; // st7
  double v14; // st7
  long double v15; // st7
  long double v16; // st7
  double *v17; // ecx
  long double v18; // st7
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  double v22; // st7
  int v23; // eax
  int v24; // eax
  int v25; // ecx
  double *v26; // esi
  double v27; // st7
  double v28; // st6
  double v30; // [esp+18h] [ebp-F0h]
  double v31; // [esp+18h] [ebp-F0h]
  double v32; // [esp+20h] [ebp-E8h]
  long double v33; // [esp+28h] [ebp-E0h] BYREF
  double v34; // [esp+30h] [ebp-D8h]
  double v35; // [esp+38h] [ebp-D0h]
  double v36; // [esp+40h] [ebp-C8h] BYREF
  double v37; // [esp+48h] [ebp-C0h]
  double v38; // [esp+50h] [ebp-B8h]
  double v39; // [esp+58h] [ebp-B0h]
  double v40; // [esp+60h] [ebp-A8h] BYREF
  double v41; // [esp+68h] [ebp-A0h]
  double v42; // [esp+70h] [ebp-98h]
  double v43; // [esp+78h] [ebp-90h] BYREF
  double v44; // [esp+80h] [ebp-88h]
  double v45; // [esp+88h] [ebp-80h]
  double v46; // [esp+90h] [ebp-78h] BYREF
  double v47; // [esp+98h] [ebp-70h]
  double v48; // [esp+A0h] [ebp-68h]
  double v49; // [esp+A8h] [ebp-60h] BYREF
  double v50; // [esp+B0h] [ebp-58h]
  double v51; // [esp+B8h] [ebp-50h]
  double v52[3]; // [esp+C0h] [ebp-48h] BYREF
  double v53[3]; // [esp+D8h] [ebp-30h] BYREF
  double v54[2]; // [esp+F0h] [ebp-18h] BYREF
  double v55; // [esp+100h] [ebp-8h]

  v30 = (*(double *)(this + 6904) + *(double *)(this + 6912)) * 0.5;
  v2 = *(double *)(this + 8184);
  if ( v30 >= 0.0 )
  {
    if ( v30 > v2 )
      v30 = v2;
  }
  else
  {
    v30 = 0.0;
  }
  v32 = (*(double *)(this + 6920) + *(double *)(this + 6928)) * 0.5;
  v3 = *(double *)(this + 8184);
  if ( v32 >= 0.0 )
  {
    if ( v32 > v3 )
      v32 = v3;
  }
  else
  {
    v32 = 0.0;
  }
  v4 = *(float *)(*(_DWORD *)(this + 9392) + 17424);
  v5 = *(float *)(*(_DWORD *)(this + 9392) + 17428);
  LODWORD(v41) = *(_DWORD *)(*(_DWORD *)(this + 9392) + 17432);
  v6 = (double *)(*(_DWORD *)(this + 6312) + 32);
  v40 = COERCE_DOUBLE(__PAIR64__(LODWORD(v5), LODWORD(v4)));
  v46 = *(float *)&v41 * v6[6] + v5 * v6[3] + v4 * *v6;
  v47 = *(float *)&v41 * v6[7] + v5 * v6[4] + v4 * v6[1];
  v48 = *(float *)&v41 * v6[8] + v5 * v6[5] + v4 * v6[2];
  *(long double *)(this + 8352) = fabs(v30 - v32) * *(double *)(this + 8176)
                                + (v32 + v30) * *(double *)(this + 8168) * 0.5
                                + *(double *)(this + 8160);
  v7 = *(double **)(this + 6312);
  v52[0] = v7[6] * *(double *)(this + 8208) + v7[5] * *(double *)(this + 8200) + *(double *)(this + 0x2000) * v7[4];
  v52[1] = v7[9] * *(double *)(this + 8208) + v7[8] * *(double *)(this + 8200) + v7[7] * *(double *)(this + 0x2000);
  v52[2] = v7[12] * *(double *)(this + 8208) + v7[11] * *(double *)(this + 8200) + v7[10] * *(double *)(this + 0x2000);
  v8 = v7[6] * v7[13] + v7[12] * v7[15] + v7[9] * v7[14];
  v9 = v7[5] * v7[13] + v7[11] * v7[15] + v7[8] * v7[14];
  v33 = v7[10] * v7[15] + v7[7] * v7[14] + v7[13] * v7[4] - v46;
  v34 = v9 - v47;
  v35 = v8 - v48;
  v53[0] = v7[10] * v7[18] + v7[7] * v7[17] + v7[4] * v7[16];
  v53[1] = v7[5] * v7[16] + v7[11] * v7[18] + v7[8] * v7[17];
  v53[2] = v7[6] * v7[16] + v7[12] * v7[18] + v7[9] * v7[17];
  sub_43B8D0((double *)(this + 8216), &v33, v53, &v43, &v36);
  v10 = *(double **)(this + 6312);
  v49 = v45 * v10[6] + v44 * v10[5] + v43 * v10[4];
  v50 = v45 * v10[9] + v44 * v10[8] + v43 * v10[7];
  v51 = v45 * v10[12] + v44 * v10[11] + v43 * v10[10];
  sub_619450(v52, &v49);
  if ( *(_BYTE *)(this + 8384) && v35 < 0.0 )
  {
    if ( v32 >= *(double *)(this + 8416) )
      v11 = *(double *)(this + 8416);
    else
      v11 = v32;
    v12 = v32 - v30 - *(double *)(this + 8432);
    v40 = *(double *)(this + 8456);
    v39 = -*(double *)(this + 8456);
    if ( v12 >= v39 )
    {
      if ( v12 > v40 )
        v12 = v40;
    }
    else
    {
      v12 = v39;
    }
    v39 = v12 * *(double *)(this + 8448) * v12
        + v11 * *(double *)(this + 8408) * v11
        + v12 * *(double *)(this + 8440)
        + v11 * *(double *)(this + 8400)
        + v30 * *(double *)(this + 8424)
        + *(double *)(this + 8392);
    if ( *(double *)(this + 8464) != 0.0 )
    {
      v13 = v30 >= v32 ? v32 : v30;
      v31 = ((*(double *)(this + 6920) + *(double *)(this + 6928) + *(double *)(this + 6904) + *(double *)(this + 6912))
           * 0.25
           - v13)
          * *(double *)(this + 8488)
          + v13;
      if ( v31 < *(double *)(this + 8464) )
      {
        if ( v31 > 0.0 )
          v14 = v31 * *(double *)(this + 8480) * v31 + v31 * *(double *)(this + 8472);
        else
          v14 = 0.0;
        v39 = (v14 + *(double *)(this + 8496)) * v39;
      }
    }
    v15 = sub_439470((double *)(this + 8504), v33, v35);
    v16 = v15 * v39;
    if ( v16 < 0.0 )
    {
      v17 = *(double **)(this + 6312);
      v18 = v16 * v35 * v35;
      v49 = v18 * v17[5];
      v50 = v18 * v17[8];
      v51 = v18 * v17[11];
      sub_43A4D0(v17, (double *)(this + 8536), v52);
      sub_619450(v52, &v49);
    }
  }
  sub_448B50((_DWORD *)this, this + 7376, &v46);
  sub_448B50((_DWORD *)this, this + 7504, &v46);
  if ( *(_BYTE *)(this + 7632) )
  {
    v19 = *(_DWORD *)(this + 9392);
    v20 = *(_DWORD *)(v19 + 4352);
    v21 = v19 + 4352;
    if ( !v20 || *(_BYTE *)(v21 + 64) )
    {
      sub_43A590(*(double **)(this + 6312), (double *)(this + 7656), v54);
      sub_43A530(*(double **)(this + 6312), v54, &v33);
      v33 = v33 - v46;
      v34 = v34 - v47;
      v35 = v35 - v48;
      if ( *(double *)(this + 7640) >= 0.0 )
      {
        if ( *(double *)(this + 7640) <= *(double *)(this + 7648) )
        {
LABEL_37:
          *(long double *)(this + 7880) = sub_439470((double *)(this + 7696), v33, v35)
                                        * (*(double *)(this + 7688) * *(double *)(this + 7640) + *(double *)(this + 7680));
          sub_43B8D0((double *)(this + 7752), &v33, v53, &v43, &v40);
          sub_43A4D0(*(double **)(this + 6312), &v43, &v49);
          sub_619450(this + 7656, &v49);
          v36 = v36 + v40;
          v37 = v41 + v37;
          v38 = v42 + v38;
          goto LABEL_38;
        }
        v22 = *(double *)(this + 7648);
      }
      else
      {
        v22 = 0.0;
      }
      *(double *)(this + 7640) = v22;
      goto LABEL_37;
    }
  }
LABEL_38:
  LOBYTE(v23) = *(_BYTE *)(this + 7920);
  if ( (_BYTE)v23 )
  {
    v24 = *(_DWORD *)(this + 9392);
    v25 = *(_DWORD *)(v24 + 4420);
    v23 = v24 + 4420;
    if ( !v25 || *(_BYTE *)(v23 + 64) )
    {
      sub_43A4D0(*(double **)(this + 6312), (double *)(this + 7968), v52);
      sub_43A590(*(double **)(this + 6312), v52, v54);
      sub_43A530(*(double **)(this + 6312), v54, &v33);
      v33 = v33 - v46;
      v34 = v34 - v47;
      v35 = v35 - v48;
      *(long double *)(this + 8120) = sub_439470((double *)(this + 7936), v33, v35) * *(double *)(this + 7928);
      sub_43B8D0((double *)(this + 7992), &v33, v53, &v43, &v40);
      sub_43A4D0(*(double **)(this + 6312), &v43, &v49);
      LOBYTE(v23) = sub_619450(v52, &v49);
      v36 = v36 + v40;
      v37 = v41 + v37;
      v38 = v42 + v38;
    }
  }
  v26 = *(double **)(this + 6312);
  v27 = v38 * v26[6] + v37 * v26[5] + v36 * v26[4];
  v28 = v38 * v26[9] + v37 * v26[8] + v36 * v26[7];
  v55 = v38 * v26[12] + v37 * v26[11] + v36 * v26[10];
  v26[42] = v27 + v26[42];
  v26[43] = v28 + v26[43];
  v26[44] = v55 + v26[44];
  return v23;
}
