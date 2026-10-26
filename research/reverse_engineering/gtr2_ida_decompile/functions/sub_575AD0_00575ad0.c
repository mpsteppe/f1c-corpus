double __thiscall sub_575AD0(float *this, float a2, float *a3, float a4, float a5)
{
  double v6; // st7
  double v7; // st7
  double v9; // st7
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c2
  double v12; // st7
  int v13; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st7
  int v17; // eax
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v22; // st7
  unsigned __int8 v23; // c0
  unsigned __int8 v24; // c2
  double v25; // st7
  int v26; // eax
  double v27; // st7
  double v28; // st7
  double v29; // st7
  int v30; // eax
  double v31; // st7
  double v32; // st7
  double v33; // st6
  unsigned __int8 v35; // c0
  unsigned __int8 v36; // c2
  double v37; // st7
  double v38; // st7
  double v39; // st7
  double v40; // st7
  float v42; // [esp+4h] [ebp-24h]
  float v43; // [esp+4h] [ebp-24h]
  float v44; // [esp+4h] [ebp-24h]
  float v45; // [esp+4h] [ebp-24h]
  float v46; // [esp+4h] [ebp-24h]
  float v47; // [esp+10h] [ebp-18h]
  float v48; // [esp+14h] [ebp-14h]
  float v49; // [esp+18h] [ebp-10h]
  float v50; // [esp+18h] [ebp-10h]
  float v51; // [esp+18h] [ebp-10h]
  float v52; // [esp+1Ch] [ebp-Ch]
  int v53; // [esp+1Ch] [ebp-Ch]
  int v54; // [esp+1Ch] [ebp-Ch]
  float v55; // [esp+1Ch] [ebp-Ch]
  float v56; // [esp+20h] [ebp-8h]
  int v57; // [esp+20h] [ebp-8h]
  float v58; // [esp+20h] [ebp-8h]
  float v59; // [esp+24h] [ebp-4h]
  float v60; // [esp+24h] [ebp-4h]
  int v61; // [esp+24h] [ebp-4h]

  v42 = fabs(a4);
  v6 = sub_5738D0(this + 4577, v42);
  if ( v6 > 128.0 )
    v6 = 128.0;
  v48 = v6 - 4.0;
  if ( v6 - 4.0 >= 0.0 )
  {
    v47 = v6 + 4.0;
  }
  else
  {
    v48 = 0.0;
    v47 = 8.0;
  }
  while ( 1 )
  {
    v7 = v48 * v48;
    v52 = v7 * this[4358] - (v7 * a2 + a3[1]) * this[4009];
    v56 = (v7 * a4 - *a3) * this[4009];
    v9 = v52;
    if ( v10 | v11 )
    {
      v12 = v9 * this[4529];
      v49 = v12;
      v43 = floor(v12);
      v13 = sub_4015C0(v43);
      v53 = v13;
      if ( v13 >= 0 )
      {
        if ( v13 >= 14 )
        {
          v13 = 13;
          v53 = 13;
        }
        v15 = this[v13 + 4530];
        v14 = v15 + (this[v13 + 4531] - v15) * (v49 - (double)v53) + v56;
      }
      else
      {
        v14 = this[4530] + v56;
      }
    }
    else
    {
      v16 = v9 * this[4545];
      v50 = v16;
      v44 = floor(v16);
      v17 = sub_4015C0(v44);
      v54 = v17;
      if ( v17 >= 0 )
      {
        if ( v17 >= 14 )
        {
          v17 = 13;
          v54 = 13;
        }
        v19 = this[v17 + 4546];
        v18 = v19 + (this[v17 + 4547] - v19) * (v50 - (double)v54);
      }
      else
      {
        v18 = this[4546];
      }
      v14 = v18 - v56;
    }
    v55 = v14;
    v20 = v47 * v47;
    v59 = v20 * this[4358] - (v20 * a2 + a3[1]) * this[4009];
    v51 = (v20 * a4 - *a3) * this[4009];
    v22 = v59;
    if ( v23 | v24 )
    {
      v25 = v22 * this[4529];
      v60 = v25;
      v45 = floor(v25);
      v26 = sub_4015C0(v45);
      v57 = v26;
      if ( v26 >= 0 )
      {
        if ( v26 >= 14 )
        {
          v26 = 13;
          v57 = 13;
        }
        v28 = this[v26 + 4530];
        v27 = v28 + (this[v26 + 4531] - v28) * (v60 - (double)v57) + v51;
      }
      else
      {
        v27 = this[4530] + v51;
      }
    }
    else
    {
      v29 = v22 * this[4545];
      v58 = v29;
      v46 = floor(v29);
      v30 = sub_4015C0(v46);
      v61 = v30;
      if ( v30 >= 0 )
      {
        if ( v30 >= 14 )
        {
          v30 = 13;
          v61 = 13;
        }
        v32 = this[v30 + 4546];
        v31 = v32 + (this[v30 + 4547] - v32) * (v58 - (double)v61);
      }
      else
      {
        v31 = this[4546];
      }
      v27 = v31 - v51;
    }
    v33 = v55;
    if ( v27 * v55 <= 0.0 )
      break;
    if ( v33 >= 0.0 )
    {
      if ( v35 | v36 || v47 >= 128.0 )
        return 128.0;
      v39 = v47 + a5;
      v47 = v39;
      if ( v39 > 128.0 )
        v47 = 128.0;
    }
    else if ( v35 | v36 )
    {
      if ( v47 >= 128.0 )
        return 128.0;
      v37 = v47 + a5;
      v47 = v37;
      if ( v37 > 128.0 )
        v47 = 128.0;
    }
    else
    {
      if ( v48 <= 0.0 )
        return 0.0;
      v38 = v48 - a5;
      v47 = v48;
      v48 = v38;
      if ( v38 < 0.0 )
        v48 = 0.0;
    }
  }
  v40 = v33 - v27;
  if ( v40 == 0.0 )
    return 0.5 * (v47 - v48) + v48;
  else
    return v55 / v40 * (v47 - v48) + v48;
}
