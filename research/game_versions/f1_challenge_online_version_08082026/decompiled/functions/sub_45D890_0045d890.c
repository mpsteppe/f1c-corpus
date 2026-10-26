char __thiscall sub_45D890(char *this, unsigned int *a2)
{
  unsigned int *v2; // esi
  unsigned int v3; // eax
  char v5; // bl
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // esi
  int v9; // eax
  char v10; // cl
  char result; // al
  unsigned int v12; // esi
  int v13; // edi
  int i; // ecx
  int v15; // eax
  float *v16; // eax
  float *v17; // ecx
  int v18; // eax
  char v19; // cl
  int v20; // eax
  unsigned int v21; // esi
  int v22; // eax
  char v23; // cl
  _DWORD *v24; // eax
  int v25; // esi
  const char *v26; // esi
  int v27; // eax
  char v28; // cl
  int v29; // eax
  const char *v30; // edi
  bool v31; // zf
  char *v32; // eax
  int v33; // eax
  const char *v34; // edx
  const char *v35; // ecx
  char *v36; // edx
  char *v37; // kr00_4
  char v38; // bl
  int v39; // eax
  char v40; // cl
  float v41; // eax
  char v42; // cl
  int v43; // eax
  char v44; // cl
  const char *v45; // edx
  const char *v46; // ecx
  char *v47; // eax
  char *v48; // edi
  char v49; // cl
  const char *v50; // ecx
  const char *v51; // eax
  const char *v52; // esi
  int v53; // eax
  char v54; // cl
  _DWORD *v55; // eax
  _DWORD *v56; // esi
  int v57; // eax
  unsigned int v58; // kr1C_4
  int v59; // esi
  int *v60; // eax
  int v61; // eax
  int v62; // eax
  int *v63; // eax
  int v64; // esi
  int v65; // eax
  int v66; // edi
  char *v67; // esi
  double v68; // st7
  double v69; // st7
  double v70; // st7
  double v71; // st7
  float v72; // [esp+0h] [ebp-2B0h]
  float v73; // [esp+0h] [ebp-2B0h]
  float v74; // [esp+0h] [ebp-2B0h]
  float v75; // [esp+0h] [ebp-2B0h]
  float v76; // [esp+0h] [ebp-2B0h]
  char v77; // [esp+1Bh] [ebp-295h]
  float v78; // [esp+1Ch] [ebp-294h] BYREF
  int j; // [esp+20h] [ebp-290h]
  char v80[79]; // [esp+24h] [ebp-28Ch] BYREF
  char v81; // [esp+73h] [ebp-23Dh]
  char v82[4]; // [esp+74h] [ebp-23Ch] BYREF
  char v83[136]; // [esp+78h] [ebp-238h] BYREF
  _BYTE v84[253]; // [esp+100h] [ebp-1B0h] BYREF
  __int16 v85; // [esp+1FDh] [ebp-B3h]
  char v86; // [esp+1FFh] [ebp-B1h]

  v2 = a2;
  v3 = *a2;
  v5 = 0;
  v77 = 1;
  if ( (*a2 & 0xE0000000) == 0x80000000 )
  {
    switch ( (v3 >> 18) & 0x3F )
    {
      case 0u:
      case 1u:
        return v77;
      case 2u:
        if ( *((_DWORD *)this + 4081) != 3 )
          return v77;
        qmemcpy(this + 16344, a2 + 2, 0x1A2u);
        sub_460710(this);
        *((_DWORD *)this + 4) = 1069547520;
        this[20] = 1;
        if ( sub_423A00(byte_5EC4C0, aNextSession, byte_5EC4CC) )
        {
          v9 = 0;
          do
          {
            v10 = aNextSession[v9];
            byte_5EC4CC[v9++] = v10;
          }
          while ( v10 );
        }
        if ( (unsigned __int8)sub_4A0E70(byte_5EC4CC) )
          Sleep(0x3E8u);
        else
          sub_45BD10(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
        result = 1;
        *((_DWORD *)this + 224) = 1084227584;
        return result;
      case 3u:
        v12 = a2[107];
        v72 = dbl_8AFEA0;
        sub_4B33B0(4, 4, 420, 255, LODWORD(v72), 1);
        if ( (unsigned __int8)sub_45E5F0(v12) )
        {
          a2[2] = -1;
          memset32(a2 + 3, -1082130432, 0x68u);
        }
        else
        {
          v13 = sub_45E5B0(this);
          sub_45E5D0(v13, v12);
          a2[2] = v13;
          memset32(a2 + 3, -1082130432, 0x68u);
          for ( i = 0; i < dword_5C329C; ++i )
          {
            v15 = dword_7C54F0[i];
            if ( v15 )
              a2[*(_DWORD *)(v15 + 18580) + 3] = *(unsigned int *)(v15 + 16540);
          }
        }
        sub_462250(a2, 2, v12, -1);
        v73 = dbl_8AFEA0;
        sub_4B33B0(4, 35, 2, 255, LODWORD(v73), 1);
        *((_BYTE *)a2 + 8) = this[112468];
        *((_BYTE *)a2 + 9) = this[112469];
        sub_462250(a2, 2, v12, -1);
        result = 1;
        byte_8AFF00 = 1;
        return result;
      case 4u:
        if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 2461) )
          sub_4D7AA0(&unk_8AD25C, aReceivedServer);
        v16 = &flt_5F0774;
        v17 = (float *)(a2 + 3);
        do
        {
          v16 += 4656;
          *(v16 - 4656) = *v17++;
        }
        while ( (int)v16 < (int)flt_7C9574 );
        sub_460520(a2[2]);
        return 1;
      case 5u:
        if ( !this[32] )
        {
          *((_DWORD *)this + 7) = 1089470464;
          this[32] = 1;
        }
        if ( sub_423A00(byte_5EC4C0, aNextTrack, byte_5EC4CC) )
        {
          v18 = 0;
          do
          {
            v19 = aNextTrack[v18];
            byte_5EC4CC[v18++] = v19;
          }
          while ( v19 );
        }
        if ( (unsigned __int8)sub_4A0E70(byte_5EC4CC) )
          Sleep(0x3E8u);
        else
          sub_45BD10(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
        return 1;
      case 6u:
        v6 = (v3 >> 8) & 0x3FF;
        if ( !v6 )
          return v77;
        *((_BYTE *)a2 + v6 + 8) = 0;
        v84[0] = byte_5EA438[0];
        memset(&v84[1], 0, 0xFCu);
        v85 = 0;
        v86 = 0;
        sub_461470(v82);
        sub_462460((unsigned __int8)*a2, v82, &v78);
        if ( *((_DWORD *)this + 4081) != 1 )
        {
          sub_45BC50(v83, (const char *)a2 + 8, v84, 256);
          if ( !byte_7CE254 && byte_7D1044 )
            sub_45BD10(&dword_7CD204, (int)v84, 3, 16909060);
          v7 = (_DWORD *)sub_587C03(8);
          if ( v7 )
          {
            *v7 = 0;
            v7[1] = -1;
            v8 = (int)v7;
          }
          else
          {
            v8 = 0;
          }
          sub_566650(v84);
          sub_434030((_DWORD *)this + 28124, v8, 0);
          sub_45EBD0(this);
          v2 = a2;
        }
        v77 = 0;
        v5 = 1;
        nullsub_3(v82);
        goto LABEL_161;
      case 0x20u:
        v20 = *((_DWORD *)this + 4081);
        if ( v20 == 2 || v20 == 1 )
          return v77;
        v21 = a2[2];
        if ( sub_462300(*(_DWORD *)this) == v21 )
        {
          if ( sub_423A00(byte_5EC4C0, aYouHaveBeenBoo, byte_5EC4CC) )
          {
            v22 = 0;
            do
            {
              v23 = aYouHaveBeenBoo[v22];
              byte_5EC4CC[v22++] = v23;
            }
            while ( v23 );
          }
          v24 = (_DWORD *)sub_587C03(8);
          if ( v24 )
          {
            *v24 = 0;
            v24[1] = -1;
            v25 = (int)v24;
          }
          else
          {
            v25 = 0;
          }
          sub_566650(byte_5EC4CC);
          sub_434030((_DWORD *)this + 28124, v25, 0);
          sub_45BD10(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
          sub_57A660(*((_DWORD *)this + 4078));
          if ( (unsigned __int8)sub_4A0E70(byte_5EC4CC) )
          {
            Sleep(0x3E8u);
            return 1;
          }
          return v77;
        }
        v26 = (const char *)sub_45EB50(v21);
        if ( !strlen(v26) )
          return v77;
        if ( sub_423A00(byte_5EC4C0, aWasRemovedFrom, byte_5EC4CC) )
        {
          v27 = 0;
          do
          {
            v28 = aWasRemovedFrom[v27];
            byte_5EC4CC[v27++] = v28;
          }
          while ( v28 );
        }
        sub_58815F(v80, "%s %s", v26, byte_5EC4CC);
        sub_45BD10(&dword_7CD204, (int)v80, 3, 16909060);
        return 1;
      case 0x23u:
        this[112488] = *((_BYTE *)a2 + 8);
        this[112489] = *((_BYTE *)a2 + 9);
        sub_4607A0(this);
        return 1;
      case 0x24u:
        v29 = 18624 * (unsigned __int8)*a2;
        v30 = 0;
        v31 = (_UNKNOWN *)((char *)&unk_5EC6D8 + v29) == 0;
        v32 = (char *)&unk_5EC6D8 + v29;
        v78 = 0.0;
        if ( v31 )
          goto LABEL_71;
        v33 = sub_4C40B0(v32 + 18196);
        if ( !v33 )
          goto LABEL_71;
        v34 = *(const char **)(v33 + 8);
        if ( !v34 )
          v34 = byte_5EA438;
        v35 = &v34[strlen(v34)];
        if ( v35 <= v34 )
          goto LABEL_70;
        while ( *v35 != 92 )
        {
          if ( --v35 <= v34 )
            goto LABEL_70;
        }
        ++v35;
LABEL_70:
        v30 = v35;
        v78 = *(float *)&v35;
LABEL_71:
        if ( (unsigned __int8)sub_460A10(a2, v30) )
          return v77;
        for ( j = 0; j < 5; ++j )
        {
          v37 = v36;
          v36 = (char *)j;
          switch ( j )
          {
            case 0:
              v38 = this[112490];
              v39 = 0;
              do
              {
                v40 = byte_5C5D2C[v39];
                v80[v39++] = v40;
              }
              while ( v40 );
              goto LABEL_103;
            case 1:
              v41 = v78;
              v38 = this[112491];
              if ( v78 == 0.0 )
              {
                v80[0] = 0;
              }
              else
              {
                v36 = &v80[-LODWORD(v78)];
                do
                {
                  v42 = *(_BYTE *)LODWORD(v41);
                  v36[LODWORD(v41)++] = *(_BYTE *)LODWORD(v41);
                }
                while ( v42 );
              }
              goto LABEL_103;
            case 2:
              v38 = this[112492];
              v43 = 0;
              do
              {
                v44 = aTerrainIni[v43];
                v80[v43++] = v44;
              }
              while ( v44 );
              goto LABEL_103;
            case 3:
              v45 = (const char *)dword_7CE5D0;
              v38 = this[112493];
              if ( !dword_7CE5D0 )
                v45 = byte_5EA438;
              v46 = &v45[strlen(v45)];
              if ( v46 <= v45 )
                goto LABEL_92;
              break;
            case 4:
              v50 = (const char *)dword_7D0434;
              v38 = this[112494];
              if ( !dword_7D0434 )
                v50 = byte_5EA438;
              v51 = (const char *)dword_5EC3D8;
              if ( !dword_5EC3D8 )
                v51 = byte_5EA438;
              sub_58969D(v80, 80, "%s%s", v51, v50);
              v81 = 0;
              goto LABEL_103;
            default:
              v36 = v37;
              continue;
          }
          while ( *v46 != 92 )
          {
            if ( --v46 <= v45 )
              goto LABEL_92;
          }
          ++v46;
LABEL_92:
          sub_587DD0(v80, v46, 79);
          v81 = 0;
          v47 = &v80[strlen(v80)];
          if ( v47 > v80 )
          {
            while ( *v47 != 46 )
            {
              --v47;
              v36 = v80;
              if ( v47 <= v80 )
                goto LABEL_97;
            }
            *v47 = 0;
          }
LABEL_97:
          v48 = &v80[strlen(v80) + 1];
          v49 = byte_5C5D28;
          *(_DWORD *)--v48 = dword_5C5D24;
          v48[4] = v49;
LABEL_103:
          if ( !v38 )
          {
            v52 = (const char *)sub_45EB50(a2[107]);
            if ( sub_423A00(byte_5EC4C0, aMismatch, byte_5EC4CC) )
            {
              v53 = 0;
              do
              {
                v54 = aMismatch[v53];
                byte_5EC4CC[v53++] = v54;
              }
              while ( v54 );
            }
            sub_58815F(v82, "%s \"%s\" %s", v52, v80, byte_5EC4CC);
            v55 = (_DWORD *)sub_587C03(8);
            if ( v55 )
            {
              *v55 = 0;
              v55[1] = -1;
              v56 = v55;
            }
            else
            {
              v56 = 0;
            }
            sub_566650(v82);
            if ( v56 )
            {
              v57 = sub_587C03(12);
              if ( v57 )
              {
                *(_DWORD *)v57 = v56;
                *(_DWORD *)(v57 + 4) = 0;
                *(_BYTE *)(v57 + 8) = 0;
              }
              else
              {
                v57 = 0;
              }
              if ( *((_DWORD *)this + 28124) )
              {
                *(_DWORD *)(*((_DWORD *)this + 28125) + 4) = v57;
              }
              else
              {
                *((_DWORD *)this + 28124) = v57;
                *((_DWORD *)this + 28126) = v57;
              }
              *((_DWORD *)this + 28125) = v57;
              ++*((_DWORD *)this + 28127);
            }
            sub_45BD10(&dword_7CD204, (int)v82, 3, 16909060);
            v58 = strlen(v82) + 1;
            v59 = v58 - 1;
            if ( (int)(v58 - 1) >= 0 )
            {
              if ( (int)(v58 - 1) > 159 )
                v59 = 159;
            }
            else
            {
              v59 = 0;
            }
            v74 = dbl_8AFEA0;
            sub_4B33B0(4, 6, v59, 0, LODWORD(v74), 1);
            sub_587DD0(&v84[8], v82, v59);
            v84[v59 + 8] = 0;
            sub_462250(v84, 0, -1, -1);
          }
        }
        return 1;
      case 0x27u:
        if ( !byte_7D10D4 )
          goto LABEL_133;
        v60 = (int *)*((_DWORD *)this + 4082);
        *((_DWORD *)this + 4084) = v60;
        if ( !v60 )
          goto LABEL_133;
        v61 = *v60;
        if ( !v61 )
          goto LABEL_133;
        break;
      case 0x28u:
        result = 1;
        *((_DWORD *)this + 222) = 2;
        return result;
      case 0x29u:
        result = 1;
        *((_DWORD *)this + 222) = 3;
        return result;
      case 0x2Au:
        v66 = 0;
        if ( *((int *)this + 3973) <= 0 )
          return v77;
        v67 = this + 1040;
        do
        {
          if ( (unsigned __int8)sub_461530(1)
            && sub_45CA20((unsigned __int8 *)this + 107456, *v67, &v78, COERCE_FLOAT(1)) )
          {
            j = *((__int16 *)a2 + 4);
            v68 = (double)j * 0.00025000001;
            if ( *((float *)this + 228) < fabs(v68 - v78) || v68 < 0.0 || v78 < 0.0 )
            {
              v71 = *((float *)this + 228);
              this[20] = 1;
              *((_DWORD *)this + 4) = 1065353216;
              *((float *)this + 228) = v71 + 0.025;
            }
            else
            {
              v69 = *((float *)this + 228) * 0.050000001;
              if ( v69 >= 0.00050000002 )
              {
                if ( v69 > 0.0099999998 )
                  v69 = 0.0099999998;
              }
              else
              {
                v69 = 0.00050000002;
              }
              v70 = *((float *)this + 228) - v69;
              *((float *)this + 228) = v70;
              if ( v70 < 0.0099999998 )
                *((_DWORD *)this + 228) = 1008981770;
            }
          }
          ++v66;
          v67 += 140;
        }
        while ( v66 < *((_DWORD *)this + 3973) );
        return 1;
      default:
        goto LABEL_160;
    }
    do
    {
      if ( !sub_588410(v61, a2 + 2) )
      {
        v76 = dbl_8AFEA0;
        sub_4B33B0(4, 41, 0, 255, LODWORD(v76), 1);
        goto LABEL_141;
      }
      v62 = *((_DWORD *)this + 4084);
      if ( v62 )
        *((_DWORD *)this + 4084) = *(_DWORD *)(v62 + 4);
      v63 = (int *)*((_DWORD *)this + 4084);
      if ( !v63 )
        break;
      v61 = *v63;
    }
    while ( v61 );
LABEL_133:
    v64 = sub_587C03(128);
    sub_587DD0(v64, a2 + 2, 127);
    *(_BYTE *)(v64 + 127) = 0;
    v65 = sub_587C03(12);
    if ( v65 )
    {
      *(_DWORD *)v65 = v64;
      *(_DWORD *)(v65 + 4) = 0;
      *(_BYTE *)(v65 + 8) = 1;
    }
    else
    {
      v65 = 0;
    }
    if ( *((_DWORD *)this + 4082) )
    {
      *(_DWORD *)(*((_DWORD *)this + 4083) + 4) = v65;
    }
    else
    {
      *((_DWORD *)this + 4082) = v65;
      *((_DWORD *)this + 4084) = v65;
    }
    *((_DWORD *)this + 4083) = v65;
    ++*((_DWORD *)this + 4085);
    v75 = dbl_8AFEA0;
    sub_4B33B0(4, 40, 0, 255, LODWORD(v75), 1);
LABEL_141:
    sub_462250(v84, 2, a2[107], -1);
    return 1;
  }
  else
  {
LABEL_160:
    v77 = 0;
LABEL_161:
    if ( !this[32] )
    {
      if ( (*v2 & 0x8000000) != 0 )
        v5 = 1;
      if ( (*((_BYTE *)v2 + 3) & 7) == dword_7C56A4 || v5 )
      {
        if ( dword_7D2E50 < 1023 )
        {
          ++dword_7D2E50;
          dword_83EE54 += 432;
        }
        sub_4B3A90(v2);
        return 1;
      }
    }
    return v77;
  }
}
