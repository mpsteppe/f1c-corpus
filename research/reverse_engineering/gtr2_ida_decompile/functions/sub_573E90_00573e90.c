void __thiscall sub_573E90(float *this, float *a2)
{
  double v3; // st7
  double v4; // st7
  float *v5; // eax
  float v6; // ecx
  float v7; // edx
  float v8; // eax
  long double v9; // st7
  float *v10; // eax
  float v11; // ecx
  float v12; // edx
  float v13; // eax
  float *v14; // eax
  float v15; // ecx
  float v16; // edx
  float v17; // eax
  long double v18; // st7
  float *v19; // eax
  float v20; // ecx
  float v21; // edx
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st6
  double v28; // st7
  int v29; // edx
  long double v30; // st7
  long double v31; // st7
  long double v32; // st6
  long double v33; // st6
  unsigned __int8 v35; // c0
  unsigned __int8 v36; // c3
  double v37; // st6
  double v38; // st6
  double v39; // st5
  double v40; // st5
  double v41; // st4
  bool v42; // zf
  float v43; // [esp+8h] [ebp-44h]
  float v44; // [esp+Ch] [ebp-40h]
  float v45; // [esp+Ch] [ebp-40h]
  float v46; // [esp+10h] [ebp-3Ch]
  float v47; // [esp+14h] [ebp-38h]
  float v48; // [esp+18h] [ebp-34h]
  float v49; // [esp+1Ch] [ebp-30h] BYREF
  float v50; // [esp+20h] [ebp-2Ch]
  float v51; // [esp+24h] [ebp-28h]
  float v52; // [esp+28h] [ebp-24h] BYREF
  float v53; // [esp+2Ch] [ebp-20h]
  float v54; // [esp+30h] [ebp-1Ch]
  float v55; // [esp+34h] [ebp-18h] BYREF
  float v56; // [esp+38h] [ebp-14h]
  float v57; // [esp+3Ch] [ebp-10h]
  float v58[2]; // [esp+40h] [ebp-Ch] BYREF
  float v59; // [esp+48h] [ebp-4h]
  float v60; // [esp+50h] [ebp+4h]

  if ( this[15] <= 0.98500001 )
  {
    if ( fabs(this[14]) >= 0.7071067811865476 )
    {
      v13 = this[49];
      v51 = this[48];
      v49 = v13;
      v50 = 0.0;
      v14 = sub_401320(this + 14, &v49, v58);
      v15 = *v14;
      v16 = v14[1];
      v17 = v14[2];
      v18 = 1.0 / sqrt(v17 * v17 + v16 * v16 + v15 * v15);
      v52 = v15 * v18;
      v53 = v16 * v18;
      v54 = v18 * v17;
      v19 = sub_401320(&v52, this + 14, v58);
      v20 = v19[1];
      v49 = *v19;
      v21 = v19[2];
      v50 = v20;
      v51 = v21;
    }
    else
    {
      v4 = -this[49];
      v52 = this[48];
      v54 = v4;
      v53 = 0.0;
      v5 = sub_401320(&v52, this + 14, v58);
      v6 = *v5;
      v7 = v5[1];
      v8 = v5[2];
      v9 = 1.0 / sqrt(v8 * v8 + v7 * v7 + v6 * v6);
      v49 = v6 * v9;
      v50 = v7 * v9;
      v51 = v9 * v8;
      v10 = sub_401320(this + 14, &v49, v58);
      v11 = v10[1];
      v52 = *v10;
      v12 = v10[2];
      v53 = v11;
      v54 = v12;
    }
    v44 = v54 * this[8] + v53 * this[7] + v52 * this[6];
    v3 = v51 * this[8] + v50 * this[7] + v49 * this[6];
  }
  else
  {
    if ( *((_DWORD *)this + 48) == 1065353216 )
    {
      v44 = this[6];
      v43 = this[8];
      goto LABEL_10;
    }
    v44 = this[48] * this[6] - this[8] * this[49];
    v3 = this[8] * this[48] + this[49] * this[6];
  }
  v43 = v3;
LABEL_10:
  v47 = v43 - this[12] * this[36];
  v48 = this[46] * this[17] + this[22];
  v22 = this[17];
  this[22] = v48;
  if ( v22 > this[43] )
    v22 = this[43];
  v23 = v22 * this[42];
  this[18] = 5.0;
  this[19] = (v23 + 1.0) * this[39] * this[17];
  if ( this[19] <= 0.0 )
  {
    this[19] = 0.0;
    this[20] = 0.0;
    this[55] = 0.0;
    this[56] = 0.0;
    this[57] = 0.0;
    return;
  }
  this[20] = 1.0;
  if ( this[12] != 0.0 )
    goto LABEL_23;
  v24 = this[50];
  v58[1] = 0.0;
  v58[0] = v24 - *this;
  v25 = this[51] - this[2];
  v59 = v25;
  if ( v25 * v59 + v58[0] * v58[0] >= 0.0056250002 )
    goto LABEL_23;
  sub_41FAB0(a2, v58, &v55);
  if ( this[15] <= 0.98500001 )
  {
    v26 = v56 * v53 + v54 * v57 + v52 * v55;
    v27 = v56 * v50 + v51 * v57 + v49 * v55;
  }
  else
  {
    v26 = v55;
    if ( *((_DWORD *)this + 48) == 1065353216 )
    {
      v46 = v57;
      goto LABEL_22;
    }
    v26 = v26 * this[48] - v57 * this[49];
    v27 = v57 * this[48] + v55 * this[49];
  }
  v46 = v27;
LABEL_22:
  v60 = v26 * 16000.0 - v44 * 1050.0;
  v28 = v46 * 16000.0 - v43 * 1050.0;
  if ( this[19] * this[19] <= v28 * v28 + v60 * v60 )
  {
LABEL_23:
    v29 = *((_DWORD *)this + 2);
    this[50] = *this;
    *((_DWORD *)this + 51) = v29;
    v30 = sqrt(v43 * v43 + v44 * v44);
    if ( v30 < 1.0 )
      v30 = 1.0;
    v31 = -(this[37] / v30 * this[19]);
    v60 = v44 * v31;
    v28 = v31 * v47;
    v32 = v28 * v28 + v60 * v60;
    if ( v32 > this[19] * this[19] )
    {
      v33 = this[19] / sqrt(v32);
      this[20] = v33;
      v60 = v60 * v33;
      v28 = v28 * v33;
      this[22] = (v33 * 0.25 + 0.75) * v48;
    }
    v37 = this[21] - v28 * this[36];
    if ( v35 | v36 )
      v38 = v37 + this[22];
    else
      v38 = v37 - this[22];
    v39 = this[28] * this[27] * this[36] * v38;
    v40 = v39 + v39;
    v41 = v47 - v40;
    if ( v47 * v41 < 0.0 )
    {
      v45 = fabs(v38 * (v41 / (v40 * this[36])));
      if ( v28 <= 0.0 )
      {
        if ( -v28 >= v45 )
          v28 = v28 + v45;
        else
          v28 = 0.0;
      }
      else if ( v28 >= v45 )
      {
        v28 = v28 - v45;
      }
      else
      {
        v28 = 0.0;
      }
    }
  }
  this[21] = this[21] - v28 * this[36];
  if ( this[15] <= 0.98500001 )
  {
    this[55] = v49 * v28 + v52 * v60;
    this[56] = v50 * v28 + v53 * v60;
    this[57] = v51 * v28 + v54 * v60;
  }
  else
  {
    v42 = *((_DWORD *)this + 48) == 1065353216;
    this[56] = 0.0;
    if ( v42 )
    {
      this[57] = v28;
      this[55] = v60;
    }
    else
    {
      this[55] = v28 * this[49] + v60 * this[48];
      this[57] = v28 * this[48] + v60 * this[49];
    }
  }
}
