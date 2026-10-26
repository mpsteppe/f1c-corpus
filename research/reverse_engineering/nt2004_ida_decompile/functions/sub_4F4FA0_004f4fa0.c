int __thiscall sub_4F4FA0(int this, float *a2, float *a3, float a4, int a5, float *a6)
{
  int result; // eax
  float *v8; // edi
  double v9; // st7
  double v10; // st7
  long double v11; // st7
  long double v12; // st7
  long double v13; // st7
  double v14; // st6
  long double v15; // st7
  long double v16; // st7
  long double v17; // st7
  double v18; // st6
  double v19; // st7
  double v20; // st6
  double v21; // st7
  double v22; // st6
  double v23; // st7
  double v24; // st6
  _DWORD *v25; // eax
  int v26; // [esp-Ch] [ebp-40h]
  int v27; // [esp-Ch] [ebp-40h]
  float v28; // [esp+4h] [ebp-30h]
  float v29; // [esp+4h] [ebp-30h]
  float v30; // [esp+4h] [ebp-30h]
  float v31; // [esp+8h] [ebp-2Ch]
  float v32; // [esp+8h] [ebp-2Ch]
  float v33; // [esp+Ch] [ebp-28h]
  float v34; // [esp+Ch] [ebp-28h]
  float v35; // [esp+10h] [ebp-24h]
  float v36; // [esp+10h] [ebp-24h]
  float v37; // [esp+14h] [ebp-20h]
  float v38; // [esp+14h] [ebp-20h]
  float v39; // [esp+18h] [ebp-1Ch]
  float v40; // [esp+1Ch] [ebp-18h]
  float v41; // [esp+1Ch] [ebp-18h]
  float v42; // [esp+1Ch] [ebp-18h]
  float v43; // [esp+1Ch] [ebp-18h]
  float v44; // [esp+1Ch] [ebp-18h]
  float v45; // [esp+20h] [ebp-14h]
  float v46; // [esp+20h] [ebp-14h]
  float v47; // [esp+20h] [ebp-14h]
  float v48; // [esp+20h] [ebp-14h]
  float v49; // [esp+20h] [ebp-14h]
  float v50; // [esp+24h] [ebp-10h]
  float v51; // [esp+24h] [ebp-10h]
  float v52; // [esp+24h] [ebp-10h]
  float v53; // [esp+24h] [ebp-10h]
  float v54; // [esp+24h] [ebp-10h]
  _BYTE v55[8]; // [esp+28h] [ebp-Ch] BYREF
  float v56; // [esp+30h] [ebp-4h]
  float v57; // [esp+48h] [ebp+14h]

  result = *(_DWORD *)(this + 96);
  if ( result > 0 )
  {
    v8 = (float *)sub_4F2AE0((_DWORD *)this);
    if ( dword_7D5DA4 == 2 )
      v9 = sub_4D9E20(&dword_7D5DAC);
    else
      v9 = dbl_7DA9D0;
    v8[2] = v9;
    v8[3] = 3.4028235e38;
    if ( a6 )
    {
      v28 = *a6;
      v10 = a6[1];
      v33 = a6[2];
    }
    else
    {
      v10 = 0.0;
      v28 = 0.0;
      v33 = 0.0;
      if ( fabs(a3[1]) <= 0.99000001 )
        v10 = 1.0;
      else
        v28 = 1.0;
    }
    v40 = v10 * a3[2] - v33 * a3[1];
    v35 = v40;
    v45 = v33 * *a3 - v28 * a3[2];
    v37 = v45;
    v50 = v28 * a3[1] - v10 * *a3;
    v11 = v50 * v50 + v45 * v45 + v40 * v40;
    if ( v11 <= 0.0 )
    {
      v13 = v50;
    }
    else
    {
      v12 = 1.0 / sqrt(v11);
      v35 = v40 * v12;
      v37 = v45 * v12;
      v13 = v12 * v50;
    }
    v14 = *(float *)(this + 12) * 0.5;
    v36 = v35 * v14;
    v38 = v37 * v14;
    v39 = v13 * v14;
    v41 = v39 * a3[1] - v38 * a3[2];
    v29 = v41;
    v46 = v36 * a3[2] - v39 * *a3;
    v31 = v46;
    v51 = v38 * *a3 - v36 * a3[1];
    v15 = v51 * v51 + v46 * v46 + v41 * v41;
    if ( v15 <= 0.0 )
    {
      v17 = v51;
    }
    else
    {
      v16 = 1.0 / sqrt(v15);
      v29 = v41 * v16;
      v31 = v46 * v16;
      v17 = v16 * v51;
    }
    v18 = *(float *)(this + 16) * 0.5;
    v30 = v29 * v18;
    v32 = v31 * v18;
    v34 = v17 * v18;
    v57 = a4 * 254.0;
    *((_DWORD *)v8 + 24) = ((int)v57 << 24) | a5 & 0xFFFFFF;
    v19 = v36 + *a2;
    v20 = v38 + a2[1];
    v56 = v39 + a2[2];
    v42 = v19 + v30;
    v47 = v20 + v32;
    v52 = v56 + v34;
    sub_5B0D50(*(_DWORD *)v8, 0, LODWORD(v42), LODWORD(v47), LODWORD(v52), ((int)v57 << 24) | a5 & 0xFFFFFF);
    v21 = v36 + *a2;
    v26 = *((_DWORD *)v8 + 24);
    v22 = v38 + a2[1];
    v56 = v39 + a2[2];
    v43 = v21 - v30;
    v48 = v22 - v32;
    v53 = v56 - v34;
    sub_5B0D50(*(_DWORD *)v8, 1, LODWORD(v43), LODWORD(v48), LODWORD(v53), v26);
    v23 = *a2 - v36;
    v24 = a2[1] - v38;
    v27 = *((_DWORD *)v8 + 24);
    v56 = a2[2] - v39;
    v44 = v23 - v30;
    v49 = v24 - v32;
    v54 = v56 - v34;
    sub_5B0D50(*(_DWORD *)v8, 2, LODWORD(v44), LODWORD(v49), LODWORD(v54), v27);
    v25 = (_DWORD *)sub_4F5370(v55);
    return sub_5B0D50(*(_DWORD *)v8, 3, *v25, v25[1], v25[2], *((_DWORD *)v8 + 24));
  }
  return result;
}
