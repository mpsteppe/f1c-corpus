char __thiscall sub_4485E0(int this)
{
  double *v2; // edi
  int v3; // edx
  double *v4; // eax
  double *v5; // ecx
  double v6; // st7
  double v7; // st6
  double *v8; // ecx
  double v9; // st7
  double v10; // st6
  double v11; // st7
  double v12; // st7
  double v13; // st6
  double v14; // st7
  double v15; // st6
  double v16; // st5
  double v17; // st7
  long double v18; // st6
  double v19; // rt1
  double v20; // st6
  double v21; // st7
  double *v22; // eax
  double v23; // st4
  double v24; // st6
  double v25; // st7
  char v26; // al
  double v27; // st7
  double v28; // st7
  char v29; // al
  double v30; // st7
  double v31; // st7
  double *v32; // ebx
  int v33; // edi
  int v34; // ebp
  char result; // al
  double v36; // st7
  long double v37; // [esp+20h] [ebp-B8h]
  double v38; // [esp+20h] [ebp-B8h]
  double v39; // [esp+20h] [ebp-B8h]
  int v40; // [esp+28h] [ebp-B0h]
  double v41; // [esp+28h] [ebp-B0h]
  double v42; // [esp+28h] [ebp-B0h]
  double v43; // [esp+40h] [ebp-98h]
  double v44; // [esp+40h] [ebp-98h]
  double v45; // [esp+48h] [ebp-90h]
  long double v46; // [esp+48h] [ebp-90h]
  long double v47; // [esp+50h] [ebp-88h]
  double v48; // [esp+58h] [ebp-80h]
  long double v49; // [esp+58h] [ebp-80h]
  double v50; // [esp+60h] [ebp-78h] BYREF
  double v51; // [esp+68h] [ebp-70h]
  double v52; // [esp+70h] [ebp-68h]
  char v53; // [esp+78h] [ebp-60h] BYREF
  char v54; // [esp+88h] [ebp-50h] BYREF

  v2 = (double *)&v53;
  v3 = this + 1080;
  v40 = 4;
  do
  {
    if ( !*(_BYTE *)(v3 + 152) )
    {
      v4 = *(double **)(v3 - 12);
      if ( !v4 )
        v4 = *(double **)(this + 5832);
      *(double *)(v3 + 16) = v4[6] * *(double *)(v3 + 8) + v4[5] * *(double *)v3 + v4[4] * *(double *)(v3 - 8);
      *(double *)(v3 + 24) = v4[9] * *(double *)(v3 + 8) + v4[8] * *(double *)v3 + v4[7] * *(double *)(v3 - 8);
      *(double *)(v3 + 32) = v4[12] * *(double *)(v3 + 8) + v4[11] * *(double *)v3 + v4[10] * *(double *)(v3 - 8);
      v5 = (double *)(*(_DWORD *)(this + 6312) + 32);
      v6 = v4[1] + *(double *)(v3 + 16);
      v7 = v4[2] + *(double *)(v3 + 24);
      v48 = v4[3] + *(double *)(v3 + 32);
      *(double *)(v3 + 64) = *(double *)(*(_DWORD *)(this + 6312) + 48) * *(double *)(v3 + 56)
                           + *(double *)(*(_DWORD *)(this + 6312) + 40) * *(double *)(v3 + 48)
                           + *v5 * *(double *)(v3 + 40);
      *(double *)(v3 + 72) = v5[5] * *(double *)(v3 + 56) + v5[4] * *(double *)(v3 + 48) + v5[3] * *(double *)(v3 + 40);
      *(double *)(v3 + 80) = v5[8] * *(double *)(v3 + 56) + v5[7] * *(double *)(v3 + 48) + v5[6] * *(double *)(v3 + 40);
      v8 = *(double **)(this + 6312);
      v45 = v6 - (*(double *)(v3 + 64) + v8[1]);
      v9 = v7 - (v8[2] + *(double *)(v3 + 72));
      v10 = v48 - (v8[3] + *(double *)(v3 + 80));
      v37 = sqrt(v10 * v10 + v9 * v9 + v45 * v45);
      v46 = v45 * (1.0 / v37);
      *v2 = v46;
      v47 = v9 * (1.0 / v37);
      v2[1] = v47;
      v49 = v10 * (1.0 / v37);
      *((_DWORD *)v2 + 4) = LODWORD(v49);
      v11 = v4[17];
      *((_DWORD *)v2 + 5) = HIDWORD(v49);
      v12 = v11 * *(double *)(v3 + 32) - v4[18] * *(double *)(v3 + 24);
      v13 = v4[18] * *(double *)(v3 + 16) - v4[16] * *(double *)(v3 + 32);
      v52 = v4[16] * *(double *)(v3 + 24) - v4[17] * *(double *)(v3 + 16);
      v50 = v12 + v4[13];
      v14 = v13 + v4[14];
      v15 = v52 + v4[15];
      v16 = v8[18] * *(double *)(v3 + 64) - *(double *)(v3 + 80) * v8[16] + v8[14];
      v43 = *(double *)(v3 + 72) * v8[16] - v8[17] * *(double *)(v3 + 64) + v8[15];
      v50 = v50 - (v8[17] * *(double *)(v3 + 80) - v8[18] * *(double *)(v3 + 72) + v8[13]);
      v51 = v14 - v16;
      v17 = v15 - v43;
      v18 = *(double *)(v3 + 144) - v37;
      *(long double *)(v3 + 128) = v18;
      v19 = v18;
      v20 = -(v17 * v49 + v51 * v47 + v50 * v46);
      *(double *)(v3 + 136) = v20;
      v21 = sub_4396D0((double *)(v3 - 368), v19, v20);
      *(double *)(v3 + 160) = v21;
    }
    v3 += 1280;
    v2 += 3;
    --v40;
  }
  while ( v40 );
  if ( dword_B6FC28 )
  {
    v22 = *(double **)(this + 6312);
    v23 = v22[13] * v22[13] + v22[14] * v22[14] + v22[15] * v22[15];
    v24 = v23 * *(double *)(this + 5880);
    *(double *)(this + 1240) = v24 + *(double *)(this + 1240);
    *(double *)(this + 2520) = v24 + *(double *)(this + 2520);
    v25 = v23 * *(double *)(this + 5888);
    *(double *)(this + 3800) = v25 + *(double *)(this + 3800);
    *(double *)(this + 5080) = v25 + *(double *)(this + 5080);
  }
  if ( !*(_BYTE *)(this + 1232) && !*(_BYTE *)(this + 2512) )
  {
    v26 = *(_BYTE *)(this + 5908);
    v27 = (*(double *)(this + 1208) - *(double *)(this + 1224) - (*(double *)(this + 2488) - *(double *)(this + 2504)))
        * *(double *)(this + 5864);
    v38 = v27 + *(double *)(this + 1240);
    *(double *)(this + 1240) = v38;
    v41 = *(double *)(this + 2520) - v27;
    *(double *)(this + 2520) = v41;
    if ( v26 )
    {
      v28 = sub_4396D0(
              (double *)(this + 5912),
              (*(double *)(this + 2488) + *(double *)(this + 1208)) * 0.5,
              (*(double *)(this + 2496) + *(double *)(this + 1216)) * 0.5)
          * 0.5;
      *(double *)(this + 1240) = v38 + v28;
      *(double *)(this + 2520) = v41 + v28;
    }
  }
  if ( !*(_BYTE *)(this + 3792) && !*(_BYTE *)(this + 5072) )
  {
    v29 = *(_BYTE *)(this + 5908);
    v30 = (*(double *)(this + 3768) - *(double *)(this + 3784) - (*(double *)(this + 5048) - *(double *)(this + 5064)))
        * *(double *)(this + 5872);
    v39 = v30 + *(double *)(this + 3800);
    *(double *)(this + 3800) = v39;
    v42 = *(double *)(this + 5080) - v30;
    *(double *)(this + 5080) = v42;
    if ( v29 )
    {
      v31 = sub_4396D0(
              (double *)(this + 6032),
              (*(double *)(this + 5048) + *(double *)(this + 3768)) * 0.5,
              (*(double *)(this + 5056) + *(double *)(this + 3776)) * 0.5)
          * 0.5;
      *(double *)(this + 3800) = v39 + v31;
      *(double *)(this + 5080) = v42 + v31;
    }
  }
  v32 = (double *)&v54;
  v33 = this + 1068;
  v34 = 4;
  do
  {
    result = *(_BYTE *)(v33 + 164);
    if ( !result )
    {
      v36 = *(double *)(v33 + 172);
      v50 = v36 * *(v32 - 2);
      v44 = v36 * *v32;
      v51 = v36 * *(v32 - 1);
      v52 = v44;
      sub_619450(v33 + 28, &v50);
      result = sub_6194F0(v33 + 76, &v50);
    }
    v33 += 1280;
    v32 += 3;
    --v34;
  }
  while ( v34 );
  return result;
}
