double __thiscall sub_4E8CE0(float *this, float a2, float *a3, float a4, float a5)
{
  long double v6; // st7
  int v7; // eax
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v12; // st7
  unsigned __int8 v13; // c0
  unsigned __int8 v14; // c2
  double v15; // st7
  int v16; // eax
  double v17; // st7
  double v18; // st7
  double v19; // st7
  int v20; // eax
  double v21; // st7
  double v22; // st7
  double v23; // st7
  double v25; // st7
  unsigned __int8 v26; // c0
  unsigned __int8 v27; // c2
  double v28; // st7
  int v29; // eax
  double v30; // st7
  double v31; // st7
  double v32; // st7
  int v33; // eax
  double v34; // st7
  double v35; // st7
  double v36; // st6
  unsigned __int8 v38; // c0
  unsigned __int8 v39; // c2
  double v40; // st7
  double v41; // st7
  double v43; // st7
  float v44; // [esp+10h] [ebp-28h]
  float v45; // [esp+14h] [ebp-24h]
  float v46; // [esp+18h] [ebp-20h]
  float v47; // [esp+18h] [ebp-20h]
  float v48; // [esp+18h] [ebp-20h]
  float v49; // [esp+18h] [ebp-20h]
  int v50; // [esp+1Ch] [ebp-1Ch]
  float v51; // [esp+1Ch] [ebp-1Ch]
  int v52; // [esp+1Ch] [ebp-1Ch]
  int v53; // [esp+1Ch] [ebp-1Ch]
  float v54; // [esp+1Ch] [ebp-1Ch]
  float v55; // [esp+20h] [ebp-18h]
  float v56; // [esp+20h] [ebp-18h]
  int v57; // [esp+20h] [ebp-18h]
  float v58; // [esp+20h] [ebp-18h]
  float v59; // [esp+24h] [ebp-14h]
  float v60; // [esp+24h] [ebp-14h]
  float v61; // [esp+24h] [ebp-14h]
  float v62; // [esp+24h] [ebp-14h]
  float v63; // [esp+24h] [ebp-14h]
  float v64; // [esp+24h] [ebp-14h]
  int v65; // [esp+24h] [ebp-14h]

  v6 = fabs(a4) * this[3903];
  v46 = v6;
  sub_5895A2(v6);
  v59 = v6;
  v7 = (int)v59;
  v50 = v7;
  if ( v7 >= 0 )
  {
    if ( v7 >= 14 )
    {
      v7 = 13;
      v50 = 13;
    }
    v9 = this[v7 + 3904];
    v8 = v9 + (this[v7 + 3905] - v9) * (v46 - (double)v50);
  }
  else
  {
    v8 = this[3904];
  }
  if ( v8 > 128.0 )
    v8 = 128.0;
  v45 = v8 - 4.0;
  if ( v8 - 4.0 >= 0.0 )
  {
    v44 = v8 + 4.0;
  }
  else
  {
    v45 = 0.0;
    v44 = 8.0;
  }
  while ( 1 )
  {
    v10 = v45 * v45;
    v51 = v10 * this[3740] - (v10 * a2 + a3[1]) * this[3397];
    v55 = (v10 * a4 - *a3) * this[3397];
    v12 = v51;
    if ( v13 | v14 )
    {
      v15 = v12 * this[3855];
      v47 = v15;
      sub_5895A2(v15);
      v60 = v15;
      v16 = (int)v60;
      v52 = v16;
      if ( v16 >= 0 )
      {
        if ( v16 >= 14 )
        {
          v16 = 13;
          v52 = 13;
        }
        v18 = this[v16 + 3856];
        v17 = v18 + (this[v16 + 3857] - v18) * (v47 - (double)v52) + v55;
      }
      else
      {
        v17 = this[3856] + v55;
      }
    }
    else
    {
      v19 = v12 * this[3871];
      v48 = v19;
      sub_5895A2(v19);
      v61 = v19;
      v20 = (int)v61;
      v53 = v20;
      if ( v20 >= 0 )
      {
        if ( v20 >= 14 )
        {
          v20 = 13;
          v53 = 13;
        }
        v22 = this[v20 + 3872];
        v21 = v22 + (this[v20 + 3873] - v22) * (v48 - (double)v53);
      }
      else
      {
        v21 = this[3872];
      }
      v17 = v21 - v55;
    }
    v54 = v17;
    v23 = v44 * v44;
    v62 = v23 * this[3740] - (v23 * a2 + a3[1]) * this[3397];
    v49 = (v23 * a4 - *a3) * this[3397];
    v25 = v62;
    if ( v26 | v27 )
    {
      v28 = v25 * this[3855];
      v63 = v28;
      sub_5895A2(v28);
      v56 = v28;
      v29 = (int)v56;
      v57 = v29;
      if ( v29 >= 0 )
      {
        if ( v29 >= 14 )
        {
          v29 = 13;
          v57 = 13;
        }
        v31 = this[v29 + 3856];
        v30 = v31 + (this[v29 + 3857] - v31) * (v63 - (double)v57) + v49;
      }
      else
      {
        v30 = this[3856] + v49;
      }
    }
    else
    {
      v32 = v25 * this[3871];
      v58 = v32;
      sub_5895A2(v32);
      v64 = v32;
      v33 = (int)v64;
      v65 = v33;
      if ( v33 >= 0 )
      {
        if ( v33 >= 14 )
        {
          v33 = 13;
          v65 = 13;
        }
        v35 = this[v33 + 3872];
        v34 = v35 + (this[v33 + 3873] - v35) * (v58 - (double)v65);
      }
      else
      {
        v34 = this[3872];
      }
      v30 = v34 - v49;
    }
    v36 = v54;
    if ( v30 * v54 <= 0.0 )
      break;
    if ( v36 >= 0.0 )
    {
      if ( v38 | v39 )
        return 128.0;
LABEL_38:
      if ( v44 >= 128.0 )
        return 128.0;
      v40 = v44 + a5;
      v44 = v40;
      if ( v40 > 128.0 )
        v44 = 128.0;
    }
    else
    {
      if ( v38 | v39 )
        goto LABEL_38;
      if ( v45 <= 0.0 )
        return 0.0;
      v41 = v45 - a5;
      v44 = v45;
      v45 = v41;
      if ( v41 < 0.0 )
        v45 = 0.0;
    }
  }
  v43 = v36 - v30;
  if ( v43 == 0.0 )
    return 0.5 * (v44 - v45) + v45;
  else
    return v54 / v43 * (v44 - v45) + v45;
}
