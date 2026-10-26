CHAR *__thiscall sub_509B10(void **this, char a2)
{
  const char *v2; // eax
  void *v4; // eax
  void **v5; // ebx
  _DWORD *v6; // esi
  void *v7; // eax
  void *v8; // eax
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  int v12; // edi
  _DWORD *v13; // esi
  int v14; // ecx
  int v15; // edx
  int *v16; // eax
  int v17; // eax
  int v18; // esi
  int v19; // edi
  bool v20; // zf
  int v21; // esi
  int *v22; // edi
  void *v23; // eax
  void *v24; // eax
  void *v25; // eax
  void *v26; // eax
  void *v27; // eax
  void *v28; // eax
  void *v29; // eax
  void *v30; // eax
  void *v31; // eax
  void *v32; // ecx
  void *v33; // ecx
  void *v34; // ecx
  void *v35; // eax
  void *v36; // eax
  void *v37; // eax
  void *v38; // eax
  void **v39; // edi
  void *v40; // ecx
  void *v41; // ecx
  void *v42; // ecx
  void *v43; // edx
  void *v44; // eax
  float v45; // ecx
  float v46; // edx
  float v47; // eax
  void **v48; // esi
  int v49; // edi
  void *v50; // ecx
  int v51; // eax
  int v52; // esi
  _DWORD *v53; // edi
  int v54; // edi
  int v55; // edi
  const char *v56; // eax
  CHAR *v57; // eax
  int v58; // eax
  int v59; // ebx
  _DWORD *v60; // edi
  char *v61; // esi
  CHAR *v62; // eax
  int v63; // eax
  void *v64; // ecx
  int v65; // eax
  int v66; // esi
  _DWORD *v67; // edi
  const char *v68; // eax
  CHAR *v69; // eax
  int v70; // eax
  int v71; // ebx
  _DWORD *v72; // edi
  char *v73; // esi
  CHAR *v74; // eax
  int v75; // eax
  int v76; // eax
  char *v77; // esi
  int v78; // ecx
  double v79; // st7
  double v80; // st7
  double v81; // st7
  CHAR *result; // eax
  void *v83; // [esp-Ch] [ebp-2CCh]
  void *v84; // [esp-Ch] [ebp-2CCh]
  void *v85; // [esp-Ch] [ebp-2CCh]
  void *v86; // [esp-Ch] [ebp-2CCh]
  void *v87; // [esp-Ch] [ebp-2CCh]
  void *v88; // [esp-Ch] [ebp-2CCh]
  void *v89; // [esp-Ch] [ebp-2CCh]
  void *v90; // [esp-Ch] [ebp-2CCh]
  void *v91; // [esp-Ch] [ebp-2CCh]
  void *v92; // [esp-Ch] [ebp-2CCh]
  void *v93; // [esp-Ch] [ebp-2CCh]
  void *v94; // [esp-Ch] [ebp-2CCh]
  void *v95; // [esp-Ch] [ebp-2CCh]
  void *v96; // [esp-Ch] [ebp-2CCh]
  void *v97; // [esp-Ch] [ebp-2CCh]
  void *v98; // [esp-Ch] [ebp-2CCh]
  int v99; // [esp+8h] [ebp-2B8h]
  int v100; // [esp+8h] [ebp-2B8h]
  _DWORD *v101; // [esp+8h] [ebp-2B8h]
  int v102; // [esp+8h] [ebp-2B8h]
  float v103; // [esp+Ch] [ebp-2B4h] BYREF
  _DWORD *v104; // [esp+10h] [ebp-2B0h]
  CHAR *v105; // [esp+14h] [ebp-2ACh]
  int v106; // [esp+18h] [ebp-2A8h]
  int i; // [esp+1Ch] [ebp-2A4h]
  int j; // [esp+20h] [ebp-2A0h]
  int v109; // [esp+24h] [ebp-29Ch]
  void *v110; // [esp+28h] [ebp-298h] BYREF
  void *v111; // [esp+2Ch] [ebp-294h]
  void *v112; // [esp+30h] [ebp-290h]
  float v113[3]; // [esp+34h] [ebp-28Ch] BYREF
  char ArgList[32]; // [esp+40h] [ebp-280h] BYREF
  char String1[64]; // [esp+60h] [ebp-260h] BYREF
  char String[32]; // [esp+A0h] [ebp-220h] BYREF
  char Buffer[256]; // [esp+C0h] [ebp-200h] BYREF
  char v118[256]; // [esp+1C0h] [ebp-100h] BYREF

  v2 = *(const char **)dword_62A0D0;
  Buffer[0] = 0;
  v118[0] = 0;
  ArgList[0] = 0;
  if ( !*(_DWORD *)dword_62A0D0 )
    v2 = &byte_629120;
  sprintf(Buffer, "%svehgen.scn", v2);
  sub_507BA0(Buffer, *((_DWORD *)*this + 6313), *((_DWORD *)*this + 6312), 0);
  if ( sub_5B3910(dword_7DA9B8, Buffer) )
  {
    sub_591C90(0, v118);
    if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_24, 1592) )
      sub_500FE0((int)&unk_7D7920, "Unable to read %s: %s", Buffer, v118);
  }
  sub_57AF60(Buffer);
  if ( a2 )
  {
    if ( sub_596220(dword_7DA9B8) )
    {
      sub_591C90(0, v118);
      if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_24, 1603) )
        sub_500FE0((int)&unk_7D7920, "Unable to setup after reading %s: %s", Buffer, v118);
    }
    sub_4F6A50(&dword_7D73D0);
    if ( sub_4634F0(dword_764D70) )
    {
      *((_BYTE *)this + 156) = 1;
    }
    else if ( sub_463490(dword_764D70) && !byte_76617C && byte_769A60 && dword_75CBA8 == 5 && dword_75CBB0 != 7 )
    {
      sub_50D130(this);
      *((_BYTE *)this + 156) = 0;
    }
    else
    {
      sub_50D130(this);
      sub_50D370(this);
    }
  }
  sprintf(ArgList, "SLOT%03d", *((_DWORD *)*this + 6312));
  v4 = (void *)sub_5975F0(ArgList, 0);
  v5 = this + 1;
  this[1] = v4;
  if ( !v4 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_24, 1640) )
    sub_500FE0((int)&unk_7D7920, "Could not find instance \"%s\"", ArgList);
  sub_59ECC0(1, 1, 0, 0);
  sub_509880((int *)this + 1, 0, 0, 9);
  sub_59EED0(*((_DWORD *)*this + 6312), 2048);
  sub_507620(*v5, (float *)this + 30, (float *)this + 33);
  sub_5A12F0(0);
  v6 = this + 85;
  v7 = (void *)sub_5975F0(aLftire, *v5);
  v83 = *v5;
  this[85] = v7;
  this[102] = (void *)sub_5975F0(aLfspindle, v83);
  v8 = (void *)sub_5975F0(aRftire, *v5);
  v84 = *v5;
  this[161] = v8;
  v9 = (void *)sub_5975F0(aRfspindle, v84);
  v85 = *v5;
  this[178] = v9;
  this[237] = (void *)sub_5975F0(aLrtire, v85);
  v10 = (void *)sub_5975F0(aLrspindle, *v5);
  v86 = *v5;
  this[254] = v10;
  v11 = (void *)sub_5975F0(aRrtire, v86);
  v87 = *v5;
  this[313] = v11;
  this[330] = (void *)sub_5975F0(aRrspindle, v87);
  v12 = 4;
  do
  {
    sub_50DE40(*v6, v6[17]);
    v6 += 76;
    --v12;
  }
  while ( v12 );
  v104 = this + 103;
  v99 = 4;
  do
  {
    v13 = v104;
    sub_509880(v104 - 18, 1, 0, 3);
    sub_509880(v104 - 1, 1, 0, 5);
    if ( !*(v104 - 1) )
    {
      *v104 = *(v104 - 17);
      v14 = *(v13 - 15);
      v13[1] = *(v13 - 16);
      v13[2] = v14;
      v13[3] = *(v13 - 14);
      v15 = *(v13 - 12);
      v13[4] = *(v13 - 13);
      v13[5] = v15;
      qmemcpy(v13 + 6, v13 - 11, 0x24u);
    }
    v13[23] = 0;
    v13[21] = 0;
    v13[22] = 0;
    for ( i = 0; i < 2; ++i )
    {
      if ( i )
        v16 = v104 - 18;
      else
        v16 = v104 - 1;
      v17 = *v16;
      v109 = v17;
      if ( v17 )
      {
        for ( j = sub_59EFD0(v17) - 1; j >= 0; --j )
        {
          v18 = sub_59EFF0(j);
          v19 = 0;
          v103 = COERCE_FLOAT(sub_59CBB0(v18));
          if ( SLODWORD(v103) > 0 )
          {
            while ( 1 )
            {
              if ( sub_59CC60(v19) )
              {
                String1[0] = 0;
                sub_599750(String1);
                if ( !_strcmpi(String1, aDiscglow) )
                  break;
              }
              if ( ++v19 >= SLODWORD(v103) )
                goto LABEL_41;
            }
            if ( v104[21] )
            {
              v104[22] = v18;
              j = 0;
              i = 1;
            }
            else
            {
              v104[21] = v18;
            }
          }
LABEL_41:
          ;
        }
      }
    }
    v20 = v99 == 1;
    v104 += 76;
    --v99;
  }
  while ( !v20 );
  this[389] = (void *)sub_5975F0(aFwing, *v5);
  sub_509880((int *)this + 389, 1, 1, 4);
  this[406] = (void *)sub_5975F0(aRwing, *v5);
  sub_509880((int *)this + 406, 1, 1, 4);
  v21 = 0;
  v22 = (int *)(this + 423);
  do
  {
    sprintf(String1, "DEBRIS%d", v21);
    *v22 = sub_5975F0(String1, *v5);
    sub_509880(v22, 1, 1, 5);
    ++v21;
    v22 += 17;
  }
  while ( v21 < 12 );
  v88 = *v5;
  this[627] = 0;
  this[628] = 0;
  this[629] = 0;
  this[630] = (void *)sub_5975F0(aCockpit_0, v88);
  v23 = (void *)sub_5975F0(aSuspension_1, *v5);
  v89 = *v5;
  this[631] = v23;
  v24 = (void *)sub_5975F0(aHelmet, v89);
  v90 = *v5;
  this[632] = v24;
  this[633] = (void *)sub_5975F0(aHelmet2, v90);
  v25 = (void *)sub_5975F0(aHelmet3, *v5);
  v91 = *v5;
  this[634] = v25;
  v26 = (void *)sub_5975F0(aLeftArm, v91);
  v92 = *v5;
  this[636] = v26;
  this[637] = (void *)sub_5975F0(aRightArm, v92);
  v27 = (void *)sub_5975F0(aRightArmMorph, *v5);
  v93 = *v5;
  this[638] = v27;
  v28 = (void *)sub_5975F0(aBody, v93);
  v94 = *v5;
  this[635] = v28;
  this[639] = (void *)sub_5975F0(aWheel, v94);
  v29 = (void *)sub_5975F0(aRainlight, *v5);
  v95 = *v5;
  this[640] = v29;
  v30 = (void *)sub_5975F0(aBrakelight, v95);
  v96 = *v5;
  this[641] = v30;
  v31 = (void *)sub_5975F0(aBackfire, v96);
  v32 = this[632];
  this[642] = v31;
  this[643] = 0;
  if ( v32 )
    sub_59E0C0(this + 643, &v103, &v103);
  v33 = this[633];
  this[644] = 0;
  if ( v33 )
    sub_59E0C0(this + 644, &v103, &v103);
  v34 = this[634];
  this[645] = 0;
  if ( v34 )
    sub_59E0C0(this + 645, &v103, &v103);
  v35 = (void *)sub_5975F0(aFlapsmid, *v5);
  v97 = *v5;
  this[646] = v35;
  v36 = (void *)sub_5975F0(aFlapsup, v97);
  v98 = *v5;
  this[647] = v36;
  this[648] = (void *)sub_5975F0(aCpitfmid, v98);
  this[649] = (void *)sub_5975F0(aCpitfup, *v5);
  sub_50E070(this);
  sub_50E6D0(this);
  this[24] = this[30];
  v37 = this[32];
  this[25] = this[31];
  this[26] = v37;
  this[27] = this[33];
  v38 = this[35];
  this[28] = this[34];
  this[29] = v38;
  v39 = this + 102;
  v100 = 4;
  do
  {
    v40 = *(v39 - 17);
    if ( v40 )
      sub_507770(v40, (float *)this + 24, (float *)this + 27);
    if ( *v39 )
      sub_507770(*v39, (float *)this + 24, (float *)this + 27);
    v39 += 76;
    --v100;
  }
  while ( v100 );
  v41 = this[389];
  if ( v41 )
    sub_507770(v41, (float *)this + 24, (float *)this + 27);
  v42 = this[406];
  if ( v42 )
    sub_507770(v42, (float *)this + 24, (float *)this + 27);
  v43 = this[31];
  v44 = this[32];
  v110 = this[30];
  v45 = *((float *)this + 33);
  v111 = v43;
  v46 = *((float *)this + 34);
  v112 = v44;
  v47 = *((float *)this + 35);
  v113[0] = v45;
  v113[1] = v46;
  v113[2] = v47;
  v48 = this + 423;
  v49 = 12;
  do
  {
    if ( *v48 && *((_BYTE *)v48 + 65) )
      sub_507770(*v48, (float *)&v110, v113);
    v48 += 17;
    --v49;
  }
  while ( v49 );
  v50 = this[636];
  this[36] = v111;
  this[650] = 0;
  if ( v50 )
  {
    v51 = sub_59EFD0(v50);
    this[650] = (void *)v51;
    if ( v51 > 2 )
      this[650] = (void *)2;
    v52 = 0;
    if ( (int)this[650] > 0 )
    {
      v53 = this + 651;
      do
        *v53++ = sub_59EFF0(v52++);
      while ( v52 < (int)this[650] );
    }
  }
  v54 = 1232 * *((_DWORD *)*this + 6313);
  v20 = dword_7D6A5C + v54 == 0;
  v55 = dword_7D6A5C + v54;
  v101 = (_DWORD *)v55;
  v105 = 0;
  v106 = -1;
  if ( v20 )
    goto LABEL_80;
  v56 = *(const char **)(v55 + 56);
  if ( !v56 )
    v56 = &byte_629120;
  if ( !strcmp(v56, &byte_629120) )
  {
LABEL_80:
    sub_578600(aLArmSteer_0);
  }
  else
  {
    v57 = *(CHAR **)(v55 + 56);
    if ( !v57 )
      v57 = &byte_629120;
    sub_578600(v57);
    sub_578560(aLArmSteer);
  }
  v58 = (int)this[650];
  v59 = 0;
  this[653] = 0;
  if ( v58 > 0 )
  {
    v60 = this + 654;
    v61 = (char *)(this + 651);
    do
    {
      v62 = v105;
      if ( !v105 )
        v62 = &byte_629120;
      v63 = sub_5ADC10(v62);
      *v60 = v63;
      if ( v63 )
        this[653] = (char *)this[653] + 1;
      ++v59;
      v61 += 4;
      v60 += 5;
    }
    while ( v59 < (int)this[650] );
  }
  v64 = this[637];
  this[664] = 0;
  if ( v64 )
  {
    v65 = sub_59EFD0(v64);
    this[664] = (void *)v65;
    if ( v65 > 2 )
      this[664] = (void *)2;
    v66 = 0;
    if ( (int)this[664] > 0 )
    {
      v67 = this + 665;
      do
        *v67++ = sub_59EFF0(v66++);
      while ( v66 < (int)this[664] );
    }
  }
  if ( !v101 )
    goto LABEL_101;
  v68 = (const char *)v101[14];
  if ( !v68 )
    v68 = &byte_629120;
  if ( !strcmp(v68, &byte_629120) )
  {
LABEL_101:
    sub_578600(aRArmSteer_0);
  }
  else
  {
    v69 = (CHAR *)v101[14];
    if ( !v69 )
      v69 = &byte_629120;
    sub_578600(v69);
    sub_578560(aRArmSteer);
  }
  v70 = (int)this[664];
  this[667] = 0;
  if ( v70 > 0 )
  {
    v71 = 0;
    v72 = this + 668;
    v73 = (char *)(this + 665);
    do
    {
      v74 = v105;
      if ( !v105 )
        v74 = &byte_629120;
      v75 = sub_5ADC10(v74);
      *v72 = v75;
      if ( v75 )
        this[667] = (char *)this[667] + 1;
      ++v71;
      v73 += 4;
      v72 += 5;
    }
    while ( v71 < (int)this[664] );
  }
  if ( this[637] && this[638] )
  {
    v76 = sub_59EFF0(0);
    sub_59D3D0(v76);
  }
  *((_BYTE *)this + 2712) = 0;
  if ( v101 )
  {
    this[680] = (void *)v101[19];
    this[681] = (void *)v101[20];
    this[682] = (void *)v101[21];
    this[683] = (void *)v101[16];
    this[684] = (void *)v101[17];
    this[685] = (void *)v101[18];
    this[686] = 0;
    this[687] = 0;
    this[688] = 0;
    this[689] = 0;
    this[690] = 0;
    this[691] = 0;
    this[705] = 0;
    this[706] = 0;
    this[692] = (void *)v101[22];
    this[693] = (void *)v101[23];
    this[694] = (void *)v101[24];
    this[695] = (void *)v101[25];
    this[696] = (void *)v101[26];
    this[697] = (void *)v101[27];
    this[708] = (void *)v101[28];
    this[709] = (void *)v101[29];
    this[710] = (void *)v101[30];
    this[711] = (void *)v101[31];
    this[712] = (void *)v101[32];
    this[713] = (void *)v101[33];
    this[714] = 0;
    this[715] = 0;
    this[716] = 0;
  }
  v77 = (char *)(this + 123);
  v102 = 4;
  do
  {
    v78 = *((_DWORD *)v77 - 38);
    *((_DWORD *)v77 - 3) = 0;
    if ( v78 )
    {
      sub_59E0C0(v77 - 8, v77 - 4, v77);
      sub_507620(*((void **)v77 - 38), (float *)v77 - 68, (float *)v77 - 65);
      v79 = (*((float *)v77 - 65) - *((float *)v77 - 68)) * 0.36750001;
      *((_DWORD *)v77 + 4) = 0;
      *((float *)v77 - 62) = v79;
      sub_5A2930(0, 0, 0);
    }
    v77 += 304;
    --v102;
  }
  while ( v102 );
  this[698] = 0;
  this[699] = 0;
  this[700] = 0;
  this[701] = 0;
  this[702] = 0;
  *((_WORD *)this + 1406) = 0;
  this[705] = 0;
  this[706] = 0;
  sub_50ADD0(0.0);
  this[848] = 0;
  dword_7D7A48 = 0;
  dword_7D7A4C = 0;
  dword_7D7A50 = 0;
  if ( sub_598170(dword_7DA9B8) )
  {
    dword_7D7A48 = sub_59A660(aTread);
    dword_7D7A4C = 0;
    dword_7D7A50 = 0;
  }
  *((_BYTE *)this + 2876) = 1;
  *((_BYTE *)this + 2877) = 1;
  *((_BYTE *)this + 2888) = 0;
  v80 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
  *((float *)this + 723) = (v80 * 0.0136 + 0.67000002) * 0.67000002;
  *((_BYTE *)this + 2885) = 0;
  *((_BYTE *)this + 2887) = 1;
  this[724] = 0;
  this[720] = (void *)1065353216;
  if ( !sub_4E8E50(String, 32, aVehicleLod, 0) )
  {
    v81 = atof(String);
    v103 = v81;
    if ( v81 > 0.0 )
    {
      sub_50E010(v103);
      this[720] = (void *)1065353216;
    }
  }
  sub_418600(dword_6291D0, *((_DWORD *)*this + 6312), 1);
  if ( byte_7D74CB )
    *((_BYTE *)this + 2886) = 1;
  else
    *((_BYTE *)this + 2886) = 0;
  result = v105;
  if ( v105 )
    return (CHAR *)sub_5BE8AE();
  return result;
}
