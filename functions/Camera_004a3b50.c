int __thiscall sub_4A3B50(_DWORD *this)
{
  float *v2; // eax
  float *v3; // ecx
  float *v4; // eax
  long double v5; // st7
  long double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st5
  double v10; // st7
  double v11; // st3
  double v12; // st4
  double v13; // st6
  int v14; // ecx
  double v15; // st6
  double v16; // st7
  long double v17; // st6
  double v18; // st7
  double v19; // st7
  long double v20; // st5
  int v21; // ecx
  float v23; // [esp+4h] [ebp-A4h]
  float v24; // [esp+4h] [ebp-A4h]
  float v25; // [esp+4h] [ebp-A4h]
  float v26; // [esp+4h] [ebp-A4h]
  float v27; // [esp+8h] [ebp-A0h]
  float v28; // [esp+8h] [ebp-A0h]
  float v29; // [esp+Ch] [ebp-9Ch]
  float v30; // [esp+Ch] [ebp-9Ch]
  float v31; // [esp+Ch] [ebp-9Ch]
  float v32; // [esp+Ch] [ebp-9Ch]
  float v33; // [esp+Ch] [ebp-9Ch]
  float v34; // [esp+10h] [ebp-98h]
  float v35; // [esp+14h] [ebp-94h]
  float v36; // [esp+18h] [ebp-90h]
  float v37; // [esp+1Ch] [ebp-8Ch] BYREF
  float v38; // [esp+20h] [ebp-88h]
  float v39; // [esp+24h] [ebp-84h]
  float v40; // [esp+28h] [ebp-80h]
  _DWORD v41[5]; // [esp+2Ch] [ebp-7Ch] BYREF
  float v42; // [esp+40h] [ebp-68h]
  float v43[2]; // [esp+44h] [ebp-64h] BYREF
  float v44; // [esp+4Ch] [ebp-5Ch]
  float v45[2]; // [esp+50h] [ebp-58h] BYREF
  float v46; // [esp+58h] [ebp-50h]
  float v47; // [esp+5Ch] [ebp-4Ch]
  float v48; // [esp+60h] [ebp-48h]
  float v49; // [esp+64h] [ebp-44h]
  float v50; // [esp+68h] [ebp-40h]
  float v51; // [esp+6Ch] [ebp-3Ch]
  float v52; // [esp+70h] [ebp-38h]
  double v53[3]; // [esp+74h] [ebp-34h] BYREF
  int v54; // [esp+8Ch] [ebp-1Ch]
  int v55; // [esp+90h] [ebp-18h]
  int v56; // [esp+94h] [ebp-14h]
  int v57; // [esp+98h] [ebp-10h]
  double v58; // [esp+9Ch] [ebp-Ch]
  int v59; // [esp+A4h] [ebp-4h]

  RenderCallWithGuard(dword_7C54E8, &v37, v41);
  v2 = sub_403640(dword_5EA2C0, &v37, 0);
  v3 = v2;
  if ( *((_DWORD *)v2 + 75) == 1 )
  {
    v4 = (float *)*((_DWORD *)v2 + 68);
    v23 = *v4 - *v3;
    v34 = v23;
    v27 = v4[1] - v3[1];
    v35 = v27;
    v29 = v4[2] - v3[2];
    v36 = v29;
    v5 = v29 * v29 + v27 * v27 + v23 * v23;
    if ( v5 > 0.0 )
    {
      v6 = 1.0 / sqrt(v5);
      v34 = v23 * v6;
      v35 = v27 * v6;
      v36 = v6 * v29;
    }
    v7 = v37 - *v3;
    v8 = v38 - v3[1];
    v9 = v39 - v3[2];
    v40 = v35 * v8 + v9 * v36 + v7 * v34;
    v10 = (v9 * v3[10] + v8 * v3[9] + v7 * v3[8]) * 0.30000001;
    if ( v10 < 0.0 || v10 >= 2.75 )
    {
      if ( v10 <= 0.0 && v10 > -2.75 )
        v10 = -2.75;
    }
    else
    {
      v10 = 2.75;
    }
    v42 = v36 * v40;
    v11 = v10 * v3[9];
    v30 = v10 * v3[10];
    v43[0] = v10 * v3[8] + *v3;
    v12 = v11 + v3[1];
    v44 = v30 + v3[2];
    v24 = v43[0] + v34 * v40;
    v37 = v24;
    v28 = v12 + v35 * v40;
    v38 = v28;
    v31 = v44 + v42;
    v13 = flt_8AB274[(unsigned __int8)dword_8AAE70];
    v39 = v31;
    v14 = ++dword_8AAE70 + 1;
    v37 = v13 * 0.050000001 + v24;
    v15 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
    v39 = v15 * 0.050000001 + v31;
    if ( v10 < 0.0 )
    {
      v25 = -v34;
      v34 = v25;
      v32 = -v36;
      v36 = v32;
    }
    v16 = flt_8AB274[(unsigned __int8)v14] * 0.050000001;
    dword_8AAE70 = v14 + 1;
    v17 = atan2(v36, v34);
  }
  else
  {
    v18 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
    v26 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.1;
    v33 = v18 * 0.1 - 6.0;
    EulerToRotationMatrix(v41, v45);
    v19 = v45[1] * 0.0;
    v40 = v51 * 0.0;
    v42 = v52 * v33 + v50 * v26 + v40;
    v37 = v46 * v33 + v26 * v45[0] + v19 + v37;
    v38 = v49 * v33 + v47 * v26 + v48 * 0.0 + v38;
    v39 = v42 + v39;
    v20 = v19 + v46 * 0.0 + v45[0] * -1.0;
    v16 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.050000001;
    v17 = atan2(v50 * -1.0 + v52 * 0.0 + v40, v20);
  }
  v21 = this[25];
  v41[0] = 0;
  *(float *)&v41[1] = v16 - v17;
  v41[2] = 0;
  if ( v21 )
  {
    BoundingBoxComputation(v43);
    v53[0] = v37;
    v53[1] = v38;
    v53[2] = v39;
    v54 = 0;
    v55 = 1075838976;
    v56 = 0x40000000;
    v57 = 1201543096;
    v59 = 0;
    if ( SpatialGridQuery(dbl_7C9360, (int)v53) )
      v38 = v58 - *(float *)&v41[4] - 0.079999998;
  }
  return Vec3CopyToStruct(this, &v37, v41);
}
