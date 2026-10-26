void __thiscall sub_4296A0(int this)
{
  int v2; // edx
  int v3; // ebp
  int v4; // edi
  double v5; // st7
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c2
  int v9; // eax
  double v10; // st6
  double v11; // st4
  int v12; // ecx
  long double v13; // st7
  double v15; // st7
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c3
  double v18; // st7
  double v19; // st7
  float v20; // eax
  double v21; // st7
  double v22; // st7
  double v24; // st7
  unsigned __int8 v25; // c0
  unsigned __int8 v26; // c3
  double v27; // st7
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // edx
  int v32; // eax
  int v33; // ecx
  float *v34; // ebp
  double v35; // st7
  int v36; // ecx
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // ecx
  int v41; // eax
  double v42; // st7
  int v43; // eax
  double v44; // st7
  double v45; // st5
  int v46; // eax
  int v47; // ecx
  double v48; // st7
  int v49; // ecx
  double v50; // st7
  double v51; // st7
  double v52; // st6
  double v53; // st7
  int v54; // [esp-8h] [ebp-44h]
  float v55; // [esp-8h] [ebp-44h]
  char v56; // [esp+13h] [ebp-29h]
  float v57; // [esp+14h] [ebp-28h]
  float v58; // [esp+18h] [ebp-24h] BYREF
  int v59; // [esp+1Ch] [ebp-20h]
  float v60; // [esp+20h] [ebp-1Ch]
  float v61[2]; // [esp+24h] [ebp-18h] BYREF
  float v62; // [esp+2Ch] [ebp-10h]
  _BYTE v63[12]; // [esp+30h] [ebp-Ch] BYREF

  v2 = *(_DWORD *)(this + 20184);
  v54 = *(_DWORD *)(this + 20852);
  v60 = *(float *)(this + 20468);
  v56 = 0;
  v59 = 0;
  v3 = sub_403390((float *)(this + 15988), v2, v54, 0);
  sub_4209D0();
  v4 = sub_4209D0();
  if ( !*(_DWORD *)(this + 20472) || !*(_DWORD *)(this + 20360) )
    goto LABEL_21;
  v58 = 1.0;
  sub_577780(v61, v63);
  v5 = sub_591960(*(_DWORD *)(this + 20360));
  *(float *)(this + 20788) = v5;
  if ( v7 | v8 && v5 > -10.0 )
  {
    v9 = *(_DWORD *)(this + 20360);
    if ( *(_DWORD *)(v9 + 280) )
    {
      v10 = v62 - *(float *)(v9 + 12);
      v11 = v61[0] - *(float *)(v9 + 4);
      *(float *)(this + 20788) = sqrt(v10 * v10 + v11 * v11);
    }
    else
    {
      *(_DWORD *)(this + 20788) = 1120403456;
    }
    v58 = *(float *)(*(_DWORD *)(v9 + 280) + 24) * (*(float *)(v9 + 12) - v62)
        + *(float *)(*(_DWORD *)(v9 + 280) + 16) * (*(float *)(v9 + 4) - v61[0]);
  }
  if ( *(float *)(this + 20788) < 0.5 || v58 < 0.0 )
  {
    v27 = *(float *)(this + 20476);
    *(_DWORD *)(this + 20468) = 1065353216;
    *(_DWORD *)(this + 20460) = 0;
    if ( v27 < 2.0 )
    {
      *(_BYTE *)(this + 21516) = 0;
      *(_DWORD *)(this + 20472) = 0;
      sub_573810(this + 16);
      sub_41FC20();
      *(_DWORD *)(this + 20768) = (*(_DWORD *)dword_B640C8 != 6) + 4;
      sub_54FDB0(&unk_FADD40, *(_DWORD *)this, v61, v63);
      sub_57DCC0(&v58, v61);
      *(_DWORD *)(this + 20788) = 0;
      *(_DWORD *)(this + 20848) = 0;
      *(_DWORD *)(this + 20852) = 1;
      *(_DWORD *)(this + 20444) = 0;
      sub_427DB0((char *)this);
      if ( (_UNKNOWN *)this == off_757C18 )
        sub_52B230(&byte_9034D0, 1);
    }
    return;
  }
  v12 = *(_DWORD *)(this + 20360);
  v13 = sqrt(*(float *)(v12 + 28) * *(float *)(v12 + 28)) + 19.0;
  if ( v13 > 28.0 )
    v13 = 28.0;
  if ( 0.5 * v13 > *(float *)(this + 20788) )
  {
    *(_DWORD *)(this + 20544) = 0;
    *(_DWORD *)(this + 20444) = *(_DWORD *)(v12 + 28);
    goto LABEL_21;
  }
  if ( v13 > *(float *)(this + 20788) )
  {
    v15 = *(float *)(v12 + 28);
    if ( !(v16 | v17) )
    {
      v18 = v15 - 3.0;
      goto LABEL_18;
    }
    v18 = v15 + 3.0;
    goto LABEL_31;
  }
  if ( *(float *)(this + 20788) < 1.34 * v13 )
  {
    v24 = *(float *)(v12 + 28);
    if ( !(v25 | v26) )
    {
      v18 = v24 - 5.0;
LABEL_18:
      if ( v18 >= 0.0 )
      {
LABEL_20:
        *(float *)(this + 20444) = v18;
        goto LABEL_21;
      }
LABEL_19:
      v18 = 0.0;
      goto LABEL_20;
    }
    v18 = v24 + 5.0;
LABEL_31:
    if ( v18 <= 0.0 )
      goto LABEL_20;
    goto LABEL_19;
  }
LABEL_21:
  v19 = *(float *)(this + 20476) * 1.05;
  v20 = *(float *)(v3 + 120);
  v55 = *(float *)(v3 + 116);
  v58 = v19;
  sub_575AD0(v20, v3 + 124, v55, 16.0);
  v21 = (v19 * *(float *)(this + 20720) + *(float *)(this + 20716))
      * *(float *)(v3 + 136)
      * *(float *)(this + 20824)
      * *(float *)(this + 20536);
  if ( v21 < v58 || (v21 = sub_41FB80((float *)this, v21, (float *)*(_DWORD *)(v3 + 276)), v21 < v58) )
    v56 = 1;
  if ( *(_DWORD *)(v4 + 312) == 1 )
    v22 = (double)*(int *)(v4 + 316) * 0.7692307692307692;
  else
    v22 = sub_41FB80((float *)this, v21, (float *)v4);
  v28 = *(_DWORD *)(this + 20472);
  v58 = v22;
  if ( v28 )
  {
    v29 = *(_DWORD *)(this + 20360);
    if ( v29 )
    {
      v30 = *(_DWORD *)(v29 + 280);
      if ( v30 == v4 )
      {
        v58 = 4.0;
      }
      else if ( v30 == *(_DWORD *)(v4 + 272) )
      {
        v58 = 3.0;
      }
    }
  }
  v31 = *(int *)(this + 20476);
  v32 = this + 20184;
  v33 = v59;
  v57 = *(float *)&v31;
  if ( v4 != *(_DWORD *)(this + 20184) )
  {
    do
    {
      *(float *)&v31 = v57;
      *(float *)(v32 + 80) = v57;
      ++v33;
      v32 += 4;
      *(float *)v4 = v57;
    }
    while ( v33 < 20 && v4 != *(_DWORD *)v32 );
    v59 = v33;
  }
  *(_DWORD *)(this + 20352) = 1176255488;
  *(_DWORD *)(this + 20356) = 1176255488;
  *(_DWORD *)(this + 20348) = 0;
  if ( v57 <= 0.0 )
    goto LABEL_93;
  v31 = v59;
  v34 = (float *)(this + 4 * v33 + 20264);
  while ( v57 < (double)v58 )
  {
    v35 = v58 - v57;
    if ( v35 > *(float *)(this + 20356) )
      v35 = *(float *)(this + 20356);
    v36 = *(_DWORD *)(this + 20848);
    *(float *)(this + 20356) = v35;
    if ( v36
      && (v37 = *(_DWORD *)(v4 + 280)) != 0
      && v36 == *(_DWORD *)(v37 + 304)
      && ((v38 = sub_4FC350(this + 14824)) == 0 || v38 == 4 || *(_DWORD *)(this + 19380) == 1) )
    {
      v4 = *(_DWORD *)(v4 + 280);
    }
    else
    {
      v4 = *(_DWORD *)(v4 + 276);
    }
    if ( !v4 )
      goto LABEL_93;
    if ( *(_DWORD *)(v4 + 312) == 1 )
    {
      v58 = *(float *)&dword_FADE50;
      goto LABEL_71;
    }
    v39 = *(_DWORD *)(v4 + 280);
    if ( v39 && (v40 = *(_DWORD *)(v39 + 304), v41 = *(_DWORD *)(this + 20848), v40 == v41) && v41 != 1 )
    {
      if ( v40 )
      {
        v58 = 12.0;
        goto LABEL_71;
      }
      v42 = sub_41FB80((float *)this, v35, (float *)v4);
    }
    else
    {
      sub_575AD0(*(float *)(v4 + 120), v4 + 124, *(float *)(v4 + 116), 16.0);
      v42 = (v35 * *(float *)(this + 20720) + *(float *)(this + 20716))
          * *(float *)(v4 + 136)
          * *(float *)(this + 20824)
          * *(float *)(this + 20536);
    }
    v58 = v42;
LABEL_71:
    if ( *(_DWORD *)(this + 20472) )
    {
      v43 = *(_DWORD *)(this + 20360);
      if ( v43 )
      {
        if ( *(_DWORD *)(v43 + 280) == v4 )
          v58 = 4.0;
      }
    }
    v44 = v58;
    if ( v58 < (double)*(float *)(this + 20476) && !*(_DWORD *)(this + 20348) )
      *(_DWORD *)(this + 20348) = v4;
    sub_575EC0(v57, *(float *)(v4 + 120), v4 + 124, *(float *)(v4 + 116));
    if ( v57 <= 1.0 )
      goto LABEL_82;
    v45 = v58 * 0.014285714;
    if ( v45 > 1.0 )
      v45 = 1.0;
    v57 = v57 - v45 * *(float *)(this + 20664) * (*(float *)(v4 + 64) / v57) * v44 * 0.91500002;
    if ( v57 < 0.5 )
LABEL_82:
      v57 = 0.0;
    v31 = v59;
    if ( v59 < 20 )
    {
      v31 = v59 + 1;
      *v34 = v57;
      v59 = v31;
      ++v34;
    }
    *(float *)v4 = v57;
    if ( v57 <= 0.0 )
      goto LABEL_93;
  }
  if ( v31 >= 1 )
  {
    if ( v31 < 20 )
      goto LABEL_90;
  }
  else
  {
    v31 = 1;
LABEL_90:
    v46 = this + 4 * v31 + 20264;
    v47 = 20 - v31;
    do
    {
      v48 = *(float *)(v46 - 4);
      v46 += 4;
      --v47;
      *(float *)(v46 - 4) = v48 - 1.8;
    }
    while ( v47 );
  }
  *(float *)&v31 = v58;
  byte_757C08 = 0;
  *(float *)(this + 20352) = v58;
LABEL_93:
  v49 = *(_DWORD *)(this + 20184);
  *(_BYTE *)(this + 20504) = *(float *)(v49 + 88) + 1.5 > *(float *)(this + 20448)
                          && *(float *)(v49 + 84) + 1.5 > -*(float *)(this + 20448);
  if ( v57 <= 0.0 )
  {
    *(_DWORD *)(this + 20468) = 0;
    if ( v56 )
    {
      v53 = sub_573020(this + 16, v31);
      *(float *)(this + 20460) = v53;
      *(float *)(this + 20464) = v53;
    }
    else
    {
      if ( *(_BYTE *)(this + 20504) )
      {
        if ( *(_DWORD *)(this + 20548) )
          v51 = sub_573020(this + 16, v31);
        else
          v51 = 1.0;
      }
      else if ( *(float *)(this + 20476) <= 25.0 )
      {
        v51 = 0.40000001;
      }
      else
      {
        v51 = 0.5;
      }
      if ( byte_757C08 )
        v52 = *(float *)(this + 20644);
      else
        v52 = *(float *)(this + 20656);
      v58 = v52 * 0.2;
      *(float *)(this + 20464) = v51;
      if ( v51 - *(float *)(this + 20460) > v58 )
        v51 = v58 + *(float *)(this + 20460);
      *(float *)(this + 20460) = v51;
    }
  }
  else
  {
    v50 = sub_573160(this + 16, v31);
    if ( v50 - v60 > 0.2 )
      v50 = v60 + 0.2;
    *(float *)(this + 20468) = v50;
    *(_DWORD *)(this + 20460) = 0;
    *(_DWORD *)(this + 20464) = 0;
  }
  if ( *(_DWORD *)(*(_DWORD *)this + 15576) == 3 )
  {
    sub_573810(this + 16);
    sub_573480(0);
    *(_DWORD *)(this + 20468) = 1065353216;
    *(_DWORD *)(this + 20460) = 0;
    *(_DWORD *)(this + 20452) = 0;
  }
}
