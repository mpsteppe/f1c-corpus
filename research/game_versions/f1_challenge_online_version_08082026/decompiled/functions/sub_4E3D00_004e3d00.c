void __thiscall sub_4E3D00(float *this, float *a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // st6
  long double v5; // st7
  long double v6; // st7
  double v7; // st7
  long double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st6
  double v15; // st7
  long double v16; // st7
  long double v17; // st7
  long double v18; // st6
  long double v19; // st6
  unsigned __int8 v21; // c0
  unsigned __int8 v22; // c3
  double v23; // st6
  double v24; // st6
  double v25; // st5
  double v26; // st5
  double v27; // st4
  bool v28; // zf
  float v29; // [esp+0h] [ebp-44h]
  float v30; // [esp+4h] [ebp-40h]
  float v31; // [esp+4h] [ebp-40h]
  float v32; // [esp+8h] [ebp-3Ch]
  float v33; // [esp+Ch] [ebp-38h]
  float v34; // [esp+10h] [ebp-34h]
  float v35; // [esp+14h] [ebp-30h]
  float v36; // [esp+14h] [ebp-30h]
  float v37; // [esp+18h] [ebp-2Ch]
  float v38; // [esp+18h] [ebp-2Ch]
  float v39; // [esp+1Ch] [ebp-28h]
  float v40; // [esp+1Ch] [ebp-28h]
  float v41; // [esp+20h] [ebp-24h]
  float v42; // [esp+20h] [ebp-24h]
  float v43; // [esp+24h] [ebp-20h]
  float v44; // [esp+24h] [ebp-20h]
  float v45; // [esp+28h] [ebp-1Ch]
  float v46; // [esp+28h] [ebp-1Ch]
  float v47; // [esp+2Ch] [ebp-18h]
  float v48; // [esp+34h] [ebp-10h]
  float v49; // [esp+38h] [ebp-Ch]
  float v50; // [esp+38h] [ebp-Ch]
  float v51; // [esp+38h] [ebp-Ch]
  float v52; // [esp+3Ch] [ebp-8h]
  float v53; // [esp+3Ch] [ebp-8h]
  float v54; // [esp+3Ch] [ebp-8h]
  float v55; // [esp+40h] [ebp-4h]
  float v56; // [esp+40h] [ebp-4h]
  float v57; // [esp+40h] [ebp-4h]
  float v58; // [esp+48h] [ebp+4h]

  if ( this[15] <= 0.98500001 )
  {
    if ( fabs(this[14]) >= 0.7071067811865476 )
    {
      v7 = this[48];
      v36 = this[47] * this[15] - this[16] * 0.0;
      v38 = v7 * this[16] - this[47] * this[14];
      v40 = this[14] * 0.0 - v7 * this[15];
      v8 = 1.0 / sqrt(v40 * v40 + v38 * v38 + v36 * v36);
      v41 = v36 * v8;
      v43 = v38 * v8;
      v45 = v8 * v40;
      v50 = v43 * this[16] - v45 * this[15];
      v53 = v45 * this[14] - v41 * this[16];
      v56 = v41 * this[15] - v43 * this[14];
      v35 = v50;
      v37 = v53;
      v39 = v56;
    }
    else
    {
      v3 = this[47];
      v4 = -this[48];
      v42 = this[16] * 0.0 - v4 * this[15];
      v44 = v4 * this[14] - v3 * this[16];
      v46 = v3 * this[15] - this[14] * 0.0;
      v5 = 1.0 / sqrt(v46 * v46 + v44 * v44 + v42 * v42);
      v35 = v42 * v5;
      v37 = v44 * v5;
      v6 = v5 * v46;
      v39 = v6;
      v49 = v6 * this[15] - v37 * this[16];
      v41 = v49;
      v52 = v35 * this[16] - v39 * this[14];
      v55 = v37 * this[14] - v35 * this[15];
      v43 = v52;
      v45 = v55;
    }
    v30 = v45 * this[8] + v43 * this[7] + v41 * this[6];
    v2 = v39 * this[8] + v37 * this[7] + v35 * this[6];
  }
  else
  {
    if ( *((_DWORD *)this + 47) == 1065353216 )
    {
      v30 = this[6];
      v29 = this[8];
      goto LABEL_10;
    }
    v30 = this[47] * this[6] - this[8] * this[48];
    v2 = this[8] * this[47] + this[48] * this[6];
  }
  v29 = v2;
LABEL_10:
  v33 = v29 - this[36] * this[12];
  v34 = this[46] * this[17] + this[22];
  v9 = this[17];
  this[22] = v34;
  if ( v9 > this[43] )
    v9 = this[43];
  v10 = v9 * this[42];
  this[18] = 5.0;
  this[19] = (v10 + 1.0) * this[39] * this[17];
  if ( this[19] <= 0.0 )
  {
    this[19] = 0.0;
    this[20] = 0.0;
    this[54] = 0.0;
    this[55] = 0.0;
    this[56] = 0.0;
    return;
  }
  v11 = this[12];
  this[20] = 1.0;
  if ( v11 != 0.0 )
    goto LABEL_23;
  v47 = this[49] - *this;
  v12 = this[50] - this[2];
  v48 = v12;
  if ( v12 * v48 + v47 * v47 >= 0.0056250002 )
    goto LABEL_23;
  v13 = v48 * a2[6] + v47 * *a2 + a2[3] * 0.0;
  v51 = v13;
  v54 = v48 * a2[7] + v47 * a2[1] + a2[4] * 0.0;
  v57 = v48 * a2[8] + v47 * a2[2] + a2[5] * 0.0;
  if ( this[15] <= 0.98500001 )
  {
    v13 = v54 * v43 + v45 * v57 + v41 * v13;
    v14 = v54 * v37 + v39 * v57 + v35 * v51;
  }
  else
  {
    if ( *((_DWORD *)this + 47) == 1065353216 )
    {
      v32 = v48 * a2[8] + v47 * a2[2] + a2[5] * 0.0;
      goto LABEL_22;
    }
    v13 = v13 * this[47] - v57 * this[48];
    v14 = v57 * this[47] + v51 * this[48];
  }
  v32 = v14;
LABEL_22:
  v58 = v13 * 16000.0 - v30 * 1050.0;
  v15 = v32 * 16000.0 - v29 * 1050.0;
  if ( this[19] * this[19] <= v15 * v15 + v58 * v58 )
  {
LABEL_23:
    this[49] = *this;
    this[50] = this[2];
    v16 = sqrt(v29 * v29 + v30 * v30);
    if ( v16 < 1.0 )
      v16 = 1.0;
    v17 = -(this[19] / v16 * this[37]);
    v58 = v30 * v17;
    v15 = v17 * v33;
    v18 = v15 * v15 + v58 * v58;
    if ( v18 > this[19] * this[19] )
    {
      v19 = this[19] / sqrt(v18);
      this[20] = v19;
      v58 = v58 * v19;
      v15 = v15 * v19;
      this[22] = (v19 * 0.25 + 0.75) * v34;
    }
    v23 = this[21] - v15 * this[36];
    if ( v21 | v22 )
      v24 = v23 + this[22];
    else
      v24 = v23 - this[22];
    v25 = this[28] * this[27] * this[36] * v24;
    v26 = v25 + v25;
    v27 = v33 - v26;
    if ( v33 * v27 < 0.0 )
    {
      v31 = fabs(v27 / (v26 * this[36]) * v24);
      if ( v15 <= 0.0 )
      {
        if ( -v15 >= v31 )
          v15 = v15 + v31;
        else
          v15 = 0.0;
      }
      else if ( v15 >= v31 )
      {
        v15 = v15 - v31;
      }
      else
      {
        v15 = 0.0;
      }
    }
  }
  this[21] = this[21] - v15 * this[36];
  if ( this[15] <= 0.98500001 )
  {
    this[54] = v35 * v15 + v41 * v58;
    this[55] = v37 * v15 + v43 * v58;
    this[56] = v39 * v15 + v45 * v58;
  }
  else
  {
    v28 = *((_DWORD *)this + 47) == 1065353216;
    this[55] = 0.0;
    if ( v28 )
    {
      this[56] = v15;
      this[54] = v58;
    }
    else
    {
      this[54] = v15 * this[48] + v58 * this[47];
      this[56] = v15 * this[47] + v58 * this[48];
    }
  }
}
