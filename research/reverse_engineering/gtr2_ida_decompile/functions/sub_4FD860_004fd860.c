double __thiscall sub_4FD860(char *this, char a2)
{
  int v3; // eax
  float *v4; // ecx
  int v5; // ecx
  double v6; // st7
  int v7; // ebp
  int v8; // edi
  int v9; // edx
  int *v10; // ecx
  int v11; // eax
  int v12; // eax
  char *v13; // ecx
  int v14; // ecx
  double v15; // st6
  double v16; // st6
  double v17; // st6
  double v18; // st6
  int v19; // eax
  double v20; // st7
  double v21; // st7
  double v22; // st7
  int v23; // ecx
  double v24; // st7
  double v25; // st6
  int v26; // eax
  double v27; // st7
  double v28; // st6
  double v29; // st6
  int v30; // eax
  double v31; // st5
  int v32; // ebx
  int v33; // eax
  int v34; // eax
  CHAR **v35; // ebp
  int v36; // edi
  char v37; // al
  CHAR *v38; // ecx
  bool v39; // zf
  double v40; // st7
  double v41; // st7
  char v42; // bl
  _DWORD *v43; // eax
  int v44; // ecx
  int v45; // eax
  int v46; // eax
  double v47; // st7
  double v48; // st7
  double v49; // st6
  double v50; // st7
  double v51; // st7
  double v52; // st7
  double v53; // st6
  double v54; // st7
  double v55; // st7
  double v56; // st7
  double v57; // st6
  double v58; // st7
  double v59; // st7
  double v60; // st7
  double v61; // st6
  double v62; // st7
  double v63; // st7
  double v64; // st7
  double v65; // st6
  double v66; // st7
  double v67; // st7
  int v68; // ecx
  float v70; // [esp+18h] [ebp-A0h]
  float v71; // [esp+18h] [ebp-A0h]
  float v72; // [esp+18h] [ebp-A0h]
  float v73; // [esp+18h] [ebp-A0h]
  float v74; // [esp+18h] [ebp-A0h]
  float v75; // [esp+34h] [ebp-84h]
  float v76; // [esp+3Ch] [ebp-7Ch]
  float v77; // [esp+40h] [ebp-78h]
  float v78; // [esp+40h] [ebp-78h]
  float v79; // [esp+44h] [ebp-74h]
  float v80; // [esp+44h] [ebp-74h]
  float v81; // [esp+44h] [ebp-74h]
  float v82; // [esp+48h] [ebp-70h]
  float v83; // [esp+48h] [ebp-70h]
  float v84[5]; // [esp+4Ch] [ebp-6Ch] BYREF
  float v85; // [esp+60h] [ebp-58h] BYREF
  float v86; // [esp+64h] [ebp-54h]
  float v87; // [esp+6Ch] [ebp-4Ch]
  float v88; // [esp+70h] [ebp-48h]
  float v89; // [esp+74h] [ebp-44h]
  float v90; // [esp+78h] [ebp-40h]
  float v91; // [esp+7Ch] [ebp-3Ch]
  float v92; // [esp+80h] [ebp-38h]
  float v93; // [esp+84h] [ebp-34h]
  float v94; // [esp+88h] [ebp-30h]
  float v95; // [esp+8Ch] [ebp-2Ch]
  float v96; // [esp+90h] [ebp-28h]
  float v97; // [esp+94h] [ebp-24h]
  float v98; // [esp+98h] [ebp-20h]
  float v99; // [esp+9Ch] [ebp-1Ch]
  float v100; // [esp+A0h] [ebp-18h]
  float v101; // [esp+A4h] [ebp-14h]
  int v102; // [esp+A8h] [ebp-10h]
  float v103; // [esp+ACh] [ebp-Ch]
  int v104; // [esp+B0h] [ebp-8h]
  int v105; // [esp+B4h] [ebp-4h]

  *((_DWORD *)this + 207) = 0;
  *((_DWORD *)this + 208) = 0;
  *((_DWORD *)this + 209) = 0;
  *((_DWORD *)this + 210) = 0;
  *((_DWORD *)this + 211) = 0;
  *((_DWORD *)this + 212) = 0;
  *((_DWORD *)this + 213) = 0;
  *((_DWORD *)this + 214) = 0;
  *((_DWORD *)this + 215) = 0;
  *((_DWORD *)this + 216) = 0;
  if ( *((_DWORD *)this + 27) )
  {
    if ( a2 )
    {
      *(float *)&v3 = COERCE_FLOAT(sub_52BDE0(*(_DWORD *)this + 19272));
      v4 = (float *)*((_DWORD *)this + 2);
      v84[0] = *(float *)&v3;
      *((_DWORD *)this + 208) = 1;
      if ( v4 )
      {
        v77 = (float)v3;
        v84[0] = v77;
        sub_4F1020(v4, v84);
        sub_4F0D10();
      }
    }
    goto LABEL_159;
  }
  v5 = *(_DWORD *)this;
  v6 = 0.0;
  if ( !*(_DWORD *)(*(_DWORD *)this + 14820) )
  {
    v6 = (*((float *)this + 190) + 25.0 - dbl_FB1D18) * 0.5;
    if ( v6 >= 0.0 )
    {
      if ( v6 > 4.5 )
        v6 = 4.5;
    }
    else
    {
      v6 = 0.0;
    }
    v7 = *(_DWORD *)(v5 + 19284);
    if ( *(_DWORD *)(v5 + 19288) == 2 )
      ++v7;
    v8 = *((_DWORD *)this + 169);
    v9 = 0;
    if ( v8 > 0 )
    {
      v10 = (int *)(this + 680);
      while ( 1 )
      {
        v11 = *v10;
        if ( *v10 >= 0 )
          break;
        ++v9;
        v10 += 2;
        if ( v9 >= *((_DWORD *)this + 169) )
          goto LABEL_23;
      }
      if ( v7 <= v11 + 1 && v7 < v11 - 1 )
      {
        v12 = v9 + 1;
        if ( v9 + 1 < v8 )
        {
          v13 = &this[8 * v12 + 680];
          do
          {
            *(_DWORD *)v13 = 0x80000000;
            ++v12;
            v13 += 8;
          }
          while ( v12 < *((_DWORD *)this + 169) );
        }
      }
      *(_DWORD *)&this[8 * v9 + 680] = 0x80000000;
    }
  }
LABEL_23:
  v14 = *(_DWORD *)this;
  v88 = v6;
  *((_DWORD *)this + 222) = 0;
  *((_DWORD *)this + 205) = 0;
  v97 = 0.60000002;
  v98 = 1.0;
  v102 = 1065353216;
  v104 = 0x40000000;
  v105 = 0;
  *((_DWORD *)this + 203) = *(_DWORD *)(v14 + 17196);
  v15 = (double)*((int *)this + 43) * *((double *)this + 20) + *((double *)this + 19);
  *((float *)this + 206) = v15;
  v84[0] = v15;
  if ( v15 <= *((float *)this + 203) )
  {
    if ( *(_DWORD *)dword_B640C8 != 6 )
      sub_578550(LODWORD(v84[0]));
    LOBYTE(v98) = 0;
  }
  else
  {
    v16 = *((float *)this + 206);
    *((_DWORD *)this + 209) = 1;
    v82 = (v16 - *((float *)this + 203)) * 0.34482756;
    v17 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
    v18 = v17 + v17;
    if ( !*(_DWORD *)(*(_DWORD *)this + 14820) && dword_B74C9C == 89 )
      v18 = v18 + 2.0;
    v79 = v82 + v18 + v6 + 3.0;
    *((float *)this + 222) = v82 + v6 + 3.0;
    v100 = v6;
    LOBYTE(v99) = 1;
    v103 = v82;
    *((float *)this + 204) = v18 + *((float *)this + 196) + v6 + 1.0;
    v101 = v18;
  }
  v19 = *((_DWORD *)this + 59);
  *((_DWORD *)this + 219) = 0;
  *((_DWORD *)this + 220) = 0;
  *((_DWORD *)this + 221) = 0;
  LOWORD(v89) = 0;
  v96 = 0.0;
  if ( v19 )
  {
    if ( *((_DWORD *)this + 75) )
    {
      v96 = 20.0;
      v84[0] = 1.0;
      goto LABEL_37;
    }
  }
  else if ( !*((_DWORD *)this + 75) )
  {
    goto LABEL_76;
  }
  v96 = 10.0;
  v84[0] = 0.5;
LABEL_37:
  v20 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
  v85 = v20 * v20 * v20 + v20 * v20 * v20;
  v21 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
  v86 = v21 * v21 * v21 + v21 * v21 * v21;
  v22 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
  v23 = dword_BE08A0 + 1;
  v24 = v22 * (v22 * v22) + v22 * (v22 * v22);
  v25 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
  v26 = *((_DWORD *)this + 59);
  v87 = v25 * v25 * v25 + v25 * v25 * v25;
  if ( !v26 )
  {
    v85 = 0.0;
    v86 = 0.0;
  }
  if ( !*((_DWORD *)this + 75) )
  {
    v87 = 0.0;
    v24 = 0.0;
  }
  v94 = v24;
  v27 = v24 + v85;
  v93 = v86;
  v92 = v85;
  v95 = v87;
  v83 = v87 + v86;
  if ( v27 <= v83 )
    v27 = v83;
  v28 = flt_BE08A4[(unsigned __int8)v23];
  dword_BE08A0 = v23 + 1;
  v90 = v28 * 0.1 + v79;
  v29 = flt_BE08A4[(unsigned __int8)(v23 + 1)];
  dword_BE08A0 = v23 + 2;
  v91 = v29 * 0.1 + v79;
  if ( v90 <= (double)v91 )
    v80 = v91;
  else
    v80 = v90;
  v30 = *((_DWORD *)this + 59);
  v31 = v84[0] + v96 + v98 + v97;
  *((float *)this + 219) = v31;
  if ( v30 )
  {
    if ( !*((_DWORD *)this + 75) )
    {
      *((float *)this + 220) = v31;
      goto LABEL_51;
    }
    *((float *)this + 220) = 0.52999997 * v31;
    v31 = v31 * 0.47;
  }
  *((float *)this + 221) = v31;
LABEL_51:
  v32 = 3;
  *((float *)this + 217) = v80 + *((float *)this + 196);
  *((float *)this + 218) = v27 + v96 + v80 + v97 + *((float *)this + 196);
  do
  {
    v33 = *(_DWORD *)&this[64 * v32 + 44];
    if ( v33 )
    {
      if ( v33 <= 0 || (v34 = v33 - 1, v34 >= *(_DWORD *)(*((_DWORD *)this + 166) + 16)) )
        v35 = 0;
      else
        v35 = (CHAR **)sub_560800(v34);
      v36 = 0;
      if ( *(int *)(*((_DWORD *)this + 166) + 16) > 0 )
      {
        while ( v35 != (CHAR **)sub_560800(v36) )
        {
          if ( ++v36 >= *(_DWORD *)(*((_DWORD *)this + 166) + 16) )
            goto LABEL_74;
        }
        v37 = v105;
        *(_DWORD *)&this[4 * v32 + 828] = 1;
        if ( v32 == 3 )
        {
          LOBYTE(v87) = 1;
          if ( v37 )
          {
            sub_57F0F0(0, v36);
            sub_57F0F0(1, v36);
          }
          if ( *((_DWORD *)this + 2) )
          {
            v38 = *v35;
            if ( !*v35 )
              v38 = (CHAR *)WindowName;
LABEL_73:
            sub_4FB6D0(v38);
            sub_4F1F20();
          }
        }
        else
        {
          BYTE1(v87) = 1;
          if ( v37 )
          {
            sub_57F0F0(2, v36);
            sub_57F0F0(3, v36);
          }
          if ( *((_DWORD *)this + 2) )
          {
            v38 = *v35;
            if ( !*v35 )
              v38 = (CHAR *)WindowName;
            goto LABEL_73;
          }
        }
      }
    }
LABEL_74:
    ++v32;
  }
  while ( v32 <= 4 );
  if ( !LOWORD(v87) )
LABEL_76:
    *((_DWORD *)this + 218) = *((_DWORD *)this + 196);
  v39 = *((_DWORD *)this + 11) == *((_DWORD *)this + 12);
  *((_DWORD *)this + 224) = 0;
  if ( v39 )
  {
    v42 = v105;
    goto LABEL_93;
  }
  v40 = sub_576AF0(*(_DWORD *)this + 16);
  if ( v40 >= 0.0 )
  {
    if ( v40 > 1.0 )
      v40 = 1.0;
  }
  else
  {
    v40 = 0.0;
  }
  v81 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
  v41 = v40 * 4.0;
  *((_DWORD *)this + 207) = 1;
  *((float *)this + 224) = v41 + 11.0;
  v78 = v81 * 1.5 + v41 + 11.0;
  if ( v103 < (double)v78 )
    v103 = v81 * 1.5 + v41 + 11.0;
  v42 = v105;
  if ( (_BYTE)v105 )
  {
    if ( (unsigned __int8)sub_4735A0() != 1
      || *(_DWORD *)(*(_DWORD *)this + 21784) != 2
      || !sub_4759A0(&dword_B6CBA8, *(_DWORD *)(*(_DWORD *)this + 22468), *((_DWORD *)this + 11)) )
    {
      v43 = *(_DWORD **)this;
      v44 = *((_DWORD *)this + 11);
      v43[5447] = v44;
      if ( *(_BYTE *)(v43[3706] + 21676) )
      {
        v43[3716] = 2;
        v43[3717] = v44;
        v43[3718] = v44;
      }
      else
      {
        v43[3716] = 1;
        v43[3717] = 0;
        v43[3718] = 0;
      }
      sub_423790();
    }
LABEL_93:
    if ( v42 && (!(unsigned __int8)sub_4735A0() || *(_DWORD *)(*(_DWORD *)this + 21784) == 1) )
    {
      v45 = *(_DWORD *)this;
      if ( !*(_DWORD *)(*(_DWORD *)this + 14820) && *(_DWORD *)(v45 + 21788) == 1 && byte_B6F790 )
      {
        sub_583170(v45 + 16, 1, 1);
        *(_DWORD *)(*(_DWORD *)this + 20768) = 4;
      }
    }
  }
  v46 = *((_DWORD *)this + 91);
  v47 = v75 + *((float *)this + 196);
  *((_DWORD *)this + 225) = 0;
  *((_DWORD *)this + 226) = 0;
  *((float *)this + 200) = v47;
  *((_DWORD *)this + 227) = 0;
  *((_DWORD *)this + 228) = 0;
  *((_DWORD *)this + 230) = 0;
  *((_DWORD *)this + 229) = 0;
  *((_DWORD *)this + 201) = 0;
  if ( v46 )
  {
    *((_DWORD *)this + 212) = 1;
    if ( v42 )
    {
      if ( dword_82F4A0 < 1023 )
      {
        ++dword_82F4A0;
        off_9034A4 += 848;
      }
      v70 = dbl_FB1D18;
      sub_51B2A0(6, 0, 0, *((_DWORD *)this + 1), LODWORD(v70), 0);
    }
    v48 = (1.0 - sub_439A50(&dbl_B66040)) * 30.0 + v85;
    *((float *)this + 226) = v48 + 5.0;
    v49 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 10.0;
    v50 = v48 + v49;
    if ( *((float *)this + 226) > (double)*((float *)this + 201) )
      *((_DWORD *)this + 201) = *((_DWORD *)this + 226);
    v51 = v50 - v85;
    if ( v101 < v51 )
      v101 = v51;
  }
  if ( *((_DWORD *)this + 107) )
  {
    *((_DWORD *)this + 213) = 1;
    if ( v42 )
    {
      if ( dword_82F4A0 < 1023 )
      {
        ++dword_82F4A0;
        off_9034A4 += 848;
      }
      v71 = dbl_FB1D18;
      sub_51B2A0(6, 1, 0, *((_DWORD *)this + 1), LODWORD(v71), 0);
    }
    v52 = 0.0;
    if ( *(_DWORD *)(*(_DWORD *)this + 4352) && !*(_BYTE *)(*(_DWORD *)this + 4416) )
    {
      v52 = v85 + 35.0;
      *((float *)this + 227) = v85 + 40.0;
    }
    v53 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 10.0;
    v54 = v52 + v53;
    if ( *((float *)this + 227) > (double)*((float *)this + 201) )
      *((_DWORD *)this + 201) = *((_DWORD *)this + 227);
    v55 = v54 - v85;
    if ( v101 < v55 )
      v101 = v55;
  }
  if ( *((_DWORD *)this + 123) )
  {
    *((_DWORD *)this + 214) = 1;
    if ( v42 )
    {
      if ( dword_82F4A0 < 1023 )
      {
        ++dword_82F4A0;
        off_9034A4 += 848;
      }
      v72 = dbl_FB1D18;
      sub_51B2A0(6, 2, 0, *((_DWORD *)this + 1), LODWORD(v72), 0);
    }
    v56 = 0.0;
    if ( *(_DWORD *)(*(_DWORD *)this + 4420) && !*(_BYTE *)(*(_DWORD *)this + 4484) )
    {
      v56 = v85 + 35.0;
      *((float *)this + 228) = v85 + 40.0;
    }
    v57 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 10.0;
    v58 = v56 + v57;
    if ( *((float *)this + 228) > (double)*((float *)this + 201) )
      *((_DWORD *)this + 201) = *((_DWORD *)this + 228);
    v59 = v58 - v85;
    if ( v101 < v59 )
      v101 = v59;
  }
  if ( *((_DWORD *)this + 139) )
  {
    *((_DWORD *)this + 215) = 1;
    if ( v42 )
    {
      if ( dword_82F4A0 < 1023 )
      {
        ++dword_82F4A0;
        off_9034A4 += 848;
      }
      v73 = dbl_FB1D18;
      sub_51B2A0(6, 3, 0, *((_DWORD *)this + 1), LODWORD(v73), 0);
    }
    v60 = v85 + 90.0;
    *((float *)this + 229) = v60 + 5.0;
    v61 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 10.0;
    v62 = v60 + v61;
    if ( *((float *)this + 229) > (double)*((float *)this + 201) )
      *((_DWORD *)this + 201) = *((_DWORD *)this + 229);
    v63 = v62 - v85;
    if ( v101 < v63 )
      v101 = v63;
  }
  if ( *((_DWORD *)this + 155) )
  {
    *((_DWORD *)this + 216) = 1;
    if ( v42 )
    {
      if ( dword_82F4A0 < 1023 )
      {
        ++dword_82F4A0;
        off_9034A4 += 848;
      }
      v74 = dbl_FB1D18;
      sub_51B2A0(6, 4, 0, *((_DWORD *)this + 1), LODWORD(v74), 0);
    }
    v64 = v85 + 105.0;
    *((float *)this + 230) = v64 + 5.0;
    v65 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 10.0;
    v66 = v64 + v65;
    if ( *((float *)this + 230) > (double)*((float *)this + 201) )
      *((_DWORD *)this + 201) = *((_DWORD *)this + 230);
    v67 = v66 - v85;
    if ( v101 < v67 )
      v101 = v67;
  }
  v68 = *((_DWORD *)this + 2);
  if ( v68 )
    sub_4F0D30(v68, (int)&v85);
  if ( LOBYTE(v86) )
  {
    if ( BYTE1(v86) )
    {
      v84[0] = v92 * 0.5;
      goto LABEL_158;
    }
LABEL_157:
    v84[0] = v92;
  }
  else
  {
    if ( BYTE1(v86) )
      goto LABEL_157;
    if ( LOBYTE(v95) )
      v84[0] = v99 + v100 + v98;
    else
      v84[0] = 0.0;
  }
LABEL_158:
  sub_415260();
LABEL_159:
  if ( (*(_DWORD *)this != ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) || *(_DWORD *)dword_B640C8)
    && *(_DWORD *)(*(_DWORD *)this + 14820) == 1
    && sub_4227E0() )
  {
    return 0.0;
  }
  else
  {
    return v76;
  }
}
