void __thiscall sub_4252A0(int this)
{
  int v2; // ecx
  float *v3; // edi
  _DWORD *v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // ebp
  int v8; // edx
  int v9; // ebp
  int v10; // ebx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  float *v14; // ecx
  float *v15; // edx
  float *v16; // eax
  float *v17; // eax
  int v18; // ecx
  int v19; // ecx
  double v21; // st7
  unsigned __int8 v22; // c0
  unsigned __int8 v23; // c3
  double v24; // st7
  int v25; // ecx
  int v26; // eax
  int v27; // ebx
  int v28; // ecx
  float *v29; // edi
  int v30; // edx
  int v31; // eax
  double v33; // st7
  unsigned __int8 v34; // c0
  unsigned __int8 v35; // c2
  double v36; // st7
  bool v37; // c3
  double v38; // st7
  int v39; // eax
  int v40; // ecx
  bool v41; // dl
  int v42; // eax
  float *v43; // ecx
  bool v44; // al
  BOOL v45; // eax
  int v46; // ebp
  int v47; // edi
  bool v48; // dl
  int v49; // eax
  float *v50; // ecx
  bool v51; // al
  BOOL v52; // eax
  double v53; // st7
  int v54; // eax
  int v55; // ebp
  int v56; // edi
  int v57; // ebx
  int v58; // ecx
  int v59; // ecx
  long double v60; // st7
  long double v61; // st7
  double v63; // st6
  unsigned __int8 v64; // c0
  unsigned __int8 v65; // c2
  long double v66; // st6
  double v67; // st7
  double v68; // st7
  double v69; // st7
  char v70; // [esp+13h] [ebp-1Dh]
  float v71; // [esp+14h] [ebp-1Ch]
  float v72; // [esp+14h] [ebp-1Ch]
  int v73; // [esp+14h] [ebp-1Ch]
  int v74; // [esp+18h] [ebp-18h]
  int v75; // [esp+1Ch] [ebp-14h]
  _DWORD *v76; // [esp+1Ch] [ebp-14h]
  int v77; // [esp+20h] [ebp-10h]
  int v78; // [esp+20h] [ebp-10h]
  float v79; // [esp+24h] [ebp-Ch]
  long double v80; // [esp+28h] [ebp-8h]

  v70 = 0;
  *(_DWORD *)(this + 24680) = 0;
  *(_BYTE *)(this + 56) = 0;
  sub_42A130();
  v2 = *(_DWORD *)(this + 24080);
  *(_DWORD *)(this + 24040) = -1046478848;
  *(_DWORD *)(this + 24044) = 1101004800;
  v74 = v2 != -1;
  if ( *(_DWORD *)(this + 24076) != -1 )
    v74 += 2;
  memset((void *)(this + 24064), 0xFFu, 0x20u);
  v75 = 0;
  v3 = (float *)(this + 21360);
  do
  {
    v4 = (_DWORD *)*((_DWORD *)v3 - 26);
    if ( v4 && (v4[6006] == 3 || v4[6172]) )
      *(v3 - 4) = 12000.0;
    if ( *(v3 - 4) < 12000.0 )
    {
      v5 = v4[6312] << 7;
      if ( byte_62A3C0[v5] || *(_DWORD *)(*(int *)((char *)dword_62A420 + v5) + 328) != *(_DWORD *)(this + 24244) )
      {
        *(int *)((char *)&dword_62A3C4 + v5) = (int)v4;
        v6 = *((_DWORD *)v3 - 26);
        v7 = *(_DWORD *)(v6 + 25248);
        dword_62A420[32 * v7] = sub_4040B0(
                                  &flt_628F60,
                                  (float *)(v6 + 17604),
                                  *(_DWORD **)(v6 + 23432),
                                  *(_DWORD *)(this + 24244),
                                  0.0,
                                  *(_DWORD **)(this + 23432));
        v8 = *((_DWORD *)v3 - 26);
        v10 = dword_62A420[32 * *(_DWORD *)(v8 + 25248)];
        v11 = *(_DWORD *)(this + 24244);
        if ( *(_DWORD *)(v10 + 328) != v11 )
        {
          if ( !*(_DWORD *)(v10 + 300) || *(_DWORD *)(*(_DWORD *)(v10 + 300) + 328) != v11 )
          {
LABEL_19:
            *(v3 - 4) = 12000.0;
            goto LABEL_36;
          }
          v9 = *(_DWORD *)(v8 + 25248);
          dword_62A420[32 * v9] = sub_4040B0(
                                    &flt_628F60,
                                    (float *)(v8 + 17604),
                                    *(_DWORD **)(dword_62A420[32 * v9] + 300),
                                    v11,
                                    0.0,
                                    0);
        }
        v77 = 1065353216;
        if ( *(_DWORD *)(this + 24024) != 7 )
          v77 = 1056964608;
        sub_41F560(
          (int)&byte_62A3C0[128 * *(_DWORD *)(*((_DWORD *)v3 - 26) + 25248)],
          (float *)dword_62A420[32 * *(_DWORD *)(*((_DWORD *)v3 - 26) + 25248)],
          0,
          *(float *)&v77,
          1);
        byte_62A3C0[128 * *(_DWORD *)(*((_DWORD *)v3 - 26) + 25248)] = 0;
      }
      v12 = *((_DWORD *)v3 - 26);
      v13 = dword_62A420[32 * *(_DWORD *)(v12 + 25248)];
      v14 = v3 - 27;
      *((_DWORD *)v3 - 3) = v13;
      if ( !v13 )
        goto LABEL_19;
      v15 = (float *)((char *)&unk_62A404 + 128 * *(_DWORD *)(v12 + 25248));
      v16 = v3 - 10;
      *v16 = *v15;
      v16[1] = v15[1];
      v16[2] = v15[2];
      v17 = (float *)((char *)&unk_62A410 + 128 * *(_DWORD *)(*((_DWORD *)v3 - 26) + 25248));
      v14[20] = *v17;
      v14[21] = v17[1];
      v14[22] = v17[2];
      sub_41F6B0(
        (int)v14,
        *(float *)(this + 17628),
        *(_DWORD *)(this + 17632),
        *(float *)(this + 17636),
        *(float *)(this + 23764));
      sub_41F800(
        v18,
        *(float *)(*(_DWORD *)(this + 23432) + 12),
        *(_DWORD *)(*(_DWORD *)(this + 23432) + 16),
        *(float *)(*(_DWORD *)(this + 23432) + 20),
        *(float *)(this + 17604),
        *(_DWORD *)(this + 17608),
        *(float *)(this + 17612));
      sub_41F560(v19, (float *)dword_62A420[32 * *(_DWORD *)(*((_DWORD *)v3 - 26) + 25248)], 0, 0.2, 0);
      *(v3 - 10) = *(v3 - 10) - *(float *)(this + 23728);
      v21 = *(v3 - 14);
      if ( v22 | v23 )
      {
        v24 = v21 + 5.0;
        if ( v24 <= 0.0 )
          goto LABEL_25;
      }
      else
      {
        v24 = v21 - 5.0;
        if ( v24 >= 0.0 )
          goto LABEL_25;
      }
      v24 = 0.0;
LABEL_25:
      *v3 = -(v24 / *(v3 - 11));
      if ( *v3 >= 0.0 )
      {
        if ( *v3 <= 50.0 )
          goto LABEL_29;
      }
      else
      {
        *v3 = 500.0;
      }
      *v3 = 49.0;
LABEL_29:
      if ( *(v3 - 14) < -7.0 && *(v3 - 11) < 0.0 )
        *(v3 - 4) = 12000.0;
      if ( *(_DWORD *)(this + 24244) == 1 && !*(_DWORD *)(*((_DWORD *)v3 - 26) + 24244) )
        *(v3 - 10) = *(v3 - 16);
      sub_426340(v75);
    }
LABEL_36:
    v3 += 32;
    ++v75;
  }
  while ( v75 < 5 );
  *(_DWORD *)(this + 24288) = -1;
  if ( dword_7D7928 == 1 && !*(_BYTE *)(this + 24292) )
  {
    v25 = *(_DWORD *)(this + 24064);
    if ( v25 != -1 )
    {
      v26 = *(_DWORD *)(this + 24064);
      goto LABEL_47;
    }
    v26 = *(_DWORD *)(this + 24068);
    if ( v26 > -1 && *(_DWORD *)(this + 23800) && *(_DWORD *)(this + 23804)
      || (v26 = *(_DWORD *)(this + 24072), v26 > -1) && *(_DWORD *)(this + 23804) && *(_DWORD *)(this + 23800) )
    {
LABEL_47:
      *(_DWORD *)(this + 24288) = *(_DWORD *)(*(_DWORD *)((v26 << 7) + this + 21256) + 25248);
    }
    if ( v25 != -1 && (v25 == *(_DWORD *)(this + 24076) || v25 == *(_DWORD *)(this + 24080)) )
      *(_DWORD *)(this + 24288) = -1;
  }
  v27 = 18;
  v28 = 0;
  v29 = (float *)(this + 21256);
  while ( 1 )
  {
    if ( *(_DWORD *)v29 )
    {
      v30 = *(_DWORD *)(*(_DWORD *)v29 + 24020);
      if ( v30 == 7 || v30 == 8 && v29[12] < 0.0 )
        break;
    }
    ++v28;
    v29 += 32;
    if ( v28 >= 5 )
      goto LABEL_60;
  }
  v27 = *(_DWORD *)(*(_DWORD *)v29 + 24020);
  v71 = sqrt(*(float *)((v28 << 7) + this + 21344));
LABEL_60:
  *(float *)(this + 24044) = *(float *)(this + 24044) - 2.2;
  *(float *)(this + 24040) = *(float *)(this + 24040) + 2.2;
  if ( v27 == 18 || v71 >= 30.0 )
  {
    v37 = 0.0 == *(float *)(this + 24);
    *(_DWORD *)(this + 20) = 0;
    if ( v37 )
    {
      *(_DWORD *)(this + 28) = 0;
    }
    else
    {
      v38 = *(float *)(this + 24) - 0.0099999998;
      if ( v38 < 0.0 )
        v38 = 0.0;
      *(float *)(this + 24) = v38;
    }
  }
  else
  {
    if ( v71 < 0.0 )
      v71 = 0.0;
    v31 = *(_DWORD *)(this + 28);
    v72 = 1.0 - v71 * 0.033333335;
    *(float *)(this + 20) = v72;
    if ( v31 )
    {
      v33 = *(float *)(this + 24);
      if ( v34 | v35 )
      {
        v36 = v33 + 0.0099999998;
        if ( v72 < v36 )
          v36 = v72;
      }
      else
      {
        v36 = v33 - 0.0099999998;
        if ( v72 > v36 )
        {
          *(float *)(this + 24) = v72;
          goto LABEL_79;
        }
      }
      *(float *)(this + 24) = v36;
    }
    else
    {
      *(_DWORD *)(this + 24) = 0;
      v80 = fabs(*(float *)(this + 23716) - sub_529A00(0));
      if ( fabs(*(float *)(this + 23716) - sub_529A00(1)) <= v80 )
        *(_DWORD *)(this + 28) = 2;
      else
        *(_DWORD *)(this + 28) = 1;
    }
  }
LABEL_79:
  v39 = *(_DWORD *)(this + 24068);
  v41 = 1;
  if ( v39 != -1 )
  {
    v40 = (v39 << 7) + this;
    if ( *(float *)(v40 + 21360) <= 3.0 || *(float *)(v40 + 21304) <= 10.0 )
      v41 = 0;
  }
  v42 = *(_DWORD *)(this + 24084);
  v44 = v42 == -1 || (v43 = (float *)((v42 << 7) + this), v43[5340] > 3.0) && v43[5329] > 2.0 || v43[5326] < -10.0;
  v45 = *(_DWORD *)(this + 24076) == -1 && v41 && v44;
  *(_DWORD *)(this + 23808) = v45;
  if ( !v45 )
    *(float *)(this + 23792) = 2.0 - *(float *)(this + 23964) + *(float *)(this + 23852);
  v46 = *(_DWORD *)(this + 24080);
  v47 = *(_DWORD *)(this + 24072);
  v48 = v47 == -1 || *(float *)((v47 << 7) + this + 21360) > 3.0 && *(float *)(this + (v47 << 7) + 21304) > 10.0;
  v49 = *(_DWORD *)(this + 24088);
  v51 = v49 == -1 || (v50 = (float *)((v49 << 7) + this), v50[5340] > 3.0) && v50[5329] > 2.0 || v50[5326] < -10.0;
  v52 = v46 == -1 && v48 && v51;
  *(_DWORD *)(this + 23812) = v52;
  if ( !v52 )
    *(float *)(this + 23796) = 2.0 - *(float *)(this + 23964) + *(float *)(this + 23852);
  v53 = *(float *)(this + 23700);
  *(float *)(this + 23624) = *(float *)(this + 23700);
  if ( *(float *)(this + 23644) < (double)*(float *)(this + 23648) )
  {
    *(float *)(this + 23644) = v53 + 2.0;
    *(float *)(this + 23648) = v53 - 2.0;
  }
  v54 = *(_DWORD *)(this + 24068);
  *(_DWORD *)(this + 24272) = 0;
  *(_DWORD *)(this + 24276) = 0;
  *(_BYTE *)(this + 24693) = 0;
  if ( v54 != -1
    || v47 != -1
    || *(_DWORD *)(this + 24076) != -1
    || v46 != -1
    || dword_7D7928 == 3
    || *(_DWORD *)(*(_DWORD *)(this + 23432) + 328)
    || *(_DWORD *)(this + 24024) != 5 )
  {
    *(float *)(this + 24768) = *(float *)(this + 23964) * 10.0 + *(float *)(this + 23852) + 2.0;
  }
  if ( *(float *)(this + 24768) >= (double)*(float *)(this + 23852) )
  {
    *(_DWORD *)(this + 24296) = -1082130432;
    *(_BYTE *)(this + 24764) = 0;
  }
  else
  {
    *(_BYTE *)(this + 24764) = 1;
  }
  v55 = 0;
  v56 = this + 21296;
  do
  {
    v57 = 0;
    v76 = (_DWORD *)(this + 24096);
    do
    {
      if ( v55 == *(v76 - 8) && v55 != -1 && *(float *)(v56 + 48) < 12000.0 )
      {
        v58 = -21296 - this + 12 * *v76;
        *(_DWORD *)v56 = *(_DWORD *)(v56 + 12 * *v76 - 21296 + 21260);
        *(_DWORD *)(v56 + 4) = *(_DWORD *)(v56 + v58 + this + 21264);
        *(_DWORD *)(v56 + 8) = *(_DWORD *)(v56 + v58 + this + 21268);
        sub_428180(this, v55, v74, v57);
        v59 = *(_DWORD *)(v56 + 52);
        v60 = *(float *)(*(_DWORD *)(this + 23432) + 260) - *(float *)(v59 + 260);
        if ( fabs(v60) >= 3.141592653589793 )
        {
          if ( v60 >= 0.0 )
            v60 = v60 - 6.283185307179586;
          else
            v60 = v60 + 6.283185307179586;
        }
        if ( fabs(v60) <= 0.800000011920929 )
        {
          v61 = *(float *)(v59 + 116) - *(float *)(this + 24200);
          if ( flt_6290D0 * 0.5 <= fabs(v61) )
          {
            v63 = flt_6290D0;
            if ( v64 | v65 )
              v66 = v63 + v61;
            else
              v66 = v61 - v63;
            *(float *)&v73 = v66;
          }
          else
          {
            *(float *)&v73 = v61;
          }
          if ( *(float *)&v73 >= 0.0
            && (v67 = *(float *)&v73 - *(float *)(this + 23912), *(float *)&v73 = v67, v67 < 0.0)
            || *(float *)&v73 <= 5.0 && *(float *)&v73 >= -5.0 )
          {
            v73 = *(int *)(v56 + 8);
          }
          v68 = *(float *)(this + 23764) * 0.75;
          v79 = *(float *)(this + 23764) - (*(float *)(v56 + 44) + *(float *)(v56 + 44));
          if ( v68 <= v79 )
            *(float *)&v78 = *(float *)(this + 23764) - (*(float *)(v56 + 44) + *(float *)(v56 + 44));
          else
            *(float *)&v78 = v68;
          if ( *(float *)&v73 < 0.0
            && *(float *)&v73 > -20.0
            && *(float *)(*(_DWORD *)(v56 - 40) + 23984) > (double)*(float *)(this + 23984) )
          {
            v70 = 1;
          }
          if ( *(float *)&v78 * 1.75 >= *(float *)&v73 )
            sub_4298D0(*(float *)&v55, v78, v73);
        }
      }
      ++v57;
      ++v76;
    }
    while ( v57 < 8 );
    ++v55;
    v56 += 128;
  }
  while ( v55 < 5 );
  if ( v70 )
  {
    v69 = *(float *)(this + 24160) - *(float *)(this + 23856) * 0.0099999998;
    if ( v69 < 0.5 )
    {
      *(float *)(this + 24160) = 0.5;
      return;
    }
  }
  else
  {
    v69 = *(float *)(this + 23984) * *(float *)(this + 23856) * 0.0099999998 + *(float *)(this + 24160);
    if ( v69 > 1.0 )
      v69 = 1.0;
  }
  *(float *)(this + 24160) = v69;
}
