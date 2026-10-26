char __thiscall sub_45EC80(char *this, int *a2)
{
  float v2; // eax
  int v4; // eax
  _DWORD *v5; // eax
  int v6; // esi
  char result; // al
  int v8; // esi
  int v9; // edi
  signed int i; // ecx
  int v11; // eax
  float *v12; // eax
  float *v13; // ecx
  int v14; // eax
  int v15; // esi
  _DWORD *v16; // eax
  int v17; // esi
  const char *v18; // esi
  char *v19; // esi
  int v20; // eax
  const char *v21; // edx
  const char *v22; // ecx
  int v23; // esi
  CHAR *v24; // esi
  const char *v25; // ecx
  const char *v26; // edx
  CHAR **v27; // esi
  const char *v28; // ecx
  CHAR *v29; // eax
  bool v30; // cc
  char *v31; // edx
  char *v32; // kr00_4
  char v33; // bl
  int v34; // eax
  char v35; // cl
  const char *v36; // eax
  char v37; // cl
  int v38; // eax
  char v39; // cl
  const char *v40; // edx
  const char *v41; // ecx
  char *v42; // eax
  char *v43; // edi
  char v44; // cl
  const char *v45; // esi
  _DWORD *v46; // eax
  _DWORD *v47; // esi
  _DWORD *v48; // eax
  unsigned int v49; // kr28_4
  size_t v50; // esi
  int *v51; // eax
  int v52; // edi
  int v53; // eax
  int *v54; // eax
  int v55; // eax
  _DWORD *v56; // ecx
  int v57; // esi
  int v58; // eax
  int *v59; // ebx
  _DWORD *v60; // eax
  int v61; // edi
  char *v62; // esi
  double v63; // st7
  double v64; // st7
  double v65; // st7
  double v66; // st7
  char *v67; // eax
  bool v68; // zf
  float v69; // [esp+0h] [ebp-3C18h]
  float v70; // [esp+0h] [ebp-3C18h]
  float v71; // [esp+0h] [ebp-3C18h]
  float v72; // [esp+0h] [ebp-3C18h]
  float v73; // [esp+0h] [ebp-3C18h]
  char v74; // [esp+8h] [ebp-3C10h]
  char v75; // [esp+1Bh] [ebp-3BFDh]
  CHAR *v76; // [esp+1Ch] [ebp-3BFCh]
  int j; // [esp+1Ch] [ebp-3BFCh]
  float v78; // [esp+20h] [ebp-3BF8h] BYREF
  const char *v79; // [esp+24h] [ebp-3BF4h]
  int v80; // [esp+28h] [ebp-3BF0h]
  char Destination[4]; // [esp+2Ch] [ebp-3BECh] BYREF
  char v82[75]; // [esp+30h] [ebp-3BE8h] BYREF
  char v83; // [esp+7Bh] [ebp-3B9Dh]
  char v84[8]; // [esp+A0h] [ebp-3B78h] BYREF
  char v85[248]; // [esp+A8h] [ebp-3B70h] BYREF
  char Source[128]; // [esp+1A0h] [ebp-3A78h] BYREF
  LPVOID v87[3]; // [esp+220h] [ebp-39F8h] BYREF
  LPVOID v88; // [esp+22Ch] [ebp-39ECh]
  LPVOID v89; // [esp+234h] [ebp-39E4h]
  LPVOID v90; // [esp+23Ch] [ebp-39DCh]
  LPVOID v91; // [esp+244h] [ebp-39D4h]
  LPVOID v92; // [esp+24Ch] [ebp-39CCh]
  char v93[104]; // [esp+1EF8h] [ebp-1D20h] BYREF
  LPVOID v94; // [esp+1F60h] [ebp-1CB8h]
  int v95[236]; // [esp+3868h] [ebp-3B0h] BYREF

  v2 = *(float *)a2;
  v75 = 1;
  if ( (unsigned int)*a2 >> 28 == 1 )
  {
    if ( (*((_WORD *)a2 + 1) & 0x3F) != 0 )
    {
      if ( (*((_WORD *)a2 + 1) & 0x3F) == 7 && (*a2 & 0x3Fu) < 0x31 )
        *((float *)&unk_632230 + 6326 * (*a2 & 0x3F)) = *((float *)a2 + 1);
    }
    else
    {
      if ( (*a2 & 0xFFC0) == 0xA00 )
        sub_4D18B0(a2);
      if ( (*a2 & 0x3Fu) >= 0x31 )
      {
        if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_6, 2640) )
        {
          sub_500FE0((int)&unk_7D7920, aReceivedCompre, v74);
          v75 = 0;
          goto LABEL_22;
        }
      }
      else
      {
        v67 = (char *)&unk_62BF68 + 25304 * (*a2 & 0x3F);
        v68 = *((_DWORD *)v67 + 4146) == 2;
        *((float *)v67 + 6322) = *((float *)a2 + 1);
        if ( v68 )
        {
          if ( dword_75CBB0 == 5 )
          {
            sub_4EEC20(0);
            sub_4EEC50(0);
          }
          else
          {
            LOBYTE(v78) = *((_BYTE *)a2 + 15) & 1;
            sub_4EEC20(SLOBYTE(v78));
            sub_4EEC50(SLOBYTE(v78));
          }
          v75 = 0;
          goto LABEL_22;
        }
      }
    }
LABEL_238:
    v75 = 0;
LABEL_22:
    if ( (*a2 & 0xC000000) == 0xC000000 || !this[24] && (((unsigned int)*a2 >> 22) & 0xF) == dword_75CBB0 )
    {
      if ( dword_76BC30 < 1023 )
      {
        ++dword_76BC30;
        dword_79FC34 += 208;
      }
      sub_4D1850(a2);
      return 1;
    }
    return v75;
  }
  if ( (unsigned int)*a2 >> 28 != 4 )
  {
    v75 = 0;
    goto LABEL_22;
  }
  switch ( *((_BYTE *)a2 + 2) & 0x3F )
  {
    case 0:
    case 1:
      return v75;
    case 2:
      if ( *((_DWORD *)this + 1680) != 3 )
        return v75;
      qmemcpy(this + 6740, a2 + 2, 0xC2u);
      sub_461DA0(this);
      *((_DWORD *)this + 4) = 1069547520;
      if ( sub_41F230(dword_62A170, aNextSession, ::Destination) )
      {
        strncpy(::Destination, aNextSession, 0x1FFu);
        byte_62A37B = 0;
      }
      if ( (unsigned __int8)sub_4BA730(::Destination, 2.0, 1) )
        Sleep(0x3E8u);
      else
        sub_45D100(&byte_764D68, (int)::Destination, 3, 16909060, 0);
      result = 1;
      *((_DWORD *)this + 162) = 1084227584;
      return result;
    case 3:
      v8 = a2[51];
      v69 = dbl_7DA9D0;
      sub_4D0D00(4, 4, 196, 63, LODWORD(v69), 3);
      if ( (unsigned __int8)sub_45FE10(v8) )
      {
        a2[2] = -1;
        memset32(a2 + 3, -1082130432, 0x30u);
      }
      else
      {
        v9 = sub_45FDD0(this);
        sub_45FDF0(v9, v8);
        a2[2] = v9;
        memset32(a2 + 3, -1082130432, 0x30u);
        for ( i = 0; i < (int)NumOfElements; ++i )
        {
          v11 = dword_75AAD0[i];
          if ( v11 )
            a2[*(_DWORD *)(v11 + 25248) + 3] = *(int *)(v11 + 20960);
        }
      }
      sub_463A40(a2, 2, v8, -1);
      v70 = dbl_7DA9D0;
      sub_4D0D00(4, 35, 2, 63, LODWORD(v70), 3);
      *((_BYTE *)a2 + 8) = this[30092];
      *((_BYTE *)a2 + 9) = this[30093];
      sub_463A40(a2, 2, v8, -1);
      result = 1;
      byte_7DAB1C = 1;
      return result;
    case 4:
      if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 2855) )
        sub_500FE0((int)&unk_7D7920, aReceivedServer, v74);
      v12 = (float *)&unk_631148;
      v13 = (float *)(a2 + 3);
      do
      {
        v12 += 6326;
        *(v12 - 6326) = *v13++;
      }
      while ( (int)v12 < (int)flt_7599C8 );
      sub_461BC0(this, a2[2]);
      return 1;
    case 5:
      if ( !this[24] )
      {
        *((_DWORD *)this + 5) = 1095237632;
        this[24] = 1;
      }
      if ( sub_41F230(dword_62A170, aNextTrack, ::Destination) )
      {
        strncpy(::Destination, aNextTrack, 0x1FFu);
        byte_62A37B = 0;
      }
      if ( (unsigned __int8)sub_4BA730(::Destination, 2.0, 1) )
        Sleep(0x3E8u);
      else
        sub_45D100(&byte_764D68, (int)::Destination, 3, 16909060, 0);
      return 1;
    case 6:
      v4 = LOWORD(v2) >> 6;
      if ( !v4 )
        return v75;
      *((_BYTE *)a2 + v4 + 8) = 0;
      v84[0] = 0;
      sub_462BC0(Destination);
      if ( !(unsigned __int8)sub_463D40(*a2 & 0x3F, Destination, &v78)
        && dword_75CBA8 != 5
        && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 2687) )
      {
        sub_500FE0((int)&unk_7D7920, aCouldnTRetriev, v74);
      }
      if ( *((_DWORD *)this + 1680) == 1 )
      {
        if ( (unsigned __int8)sub_46C5E0(a2 + 2, v82, a2[51]) )
          goto LABEL_21;
      }
      else
      {
        sub_45D040(v82, (const char *)a2 + 8, v84, 256);
        if ( !byte_76617C && byte_769A18 )
          sub_45D100(&byte_764D68, (int)v84, 0, 16909060, 0);
        v5 = operator new(8u);
        if ( v5 )
        {
          *v5 = 0;
          v5[1] = -1;
          v6 = (int)v5;
        }
        else
        {
          v6 = 0;
        }
        sub_578600(v84);
        sub_414410((_DWORD *)this + 7530, v6, 0);
        sub_460390(this);
      }
      v75 = 0;
LABEL_21:
      nullsub_6(Destination);
      if ( !v75 )
        goto LABEL_22;
      return v75;
    case 0x20:
      v14 = *((_DWORD *)this + 1680);
      if ( v14 == 2 || v14 == 1 )
        return v75;
      v15 = a2[2];
      if ( sub_463B50(*(_DWORD *)this) == v15 )
      {
        if ( sub_41F230(dword_62A170, aYouHaveBeenBoo, ::Destination) )
        {
          strncpy(::Destination, aYouHaveBeenBoo, 0x1FFu);
          byte_62A37B = 0;
        }
        v16 = operator new(8u);
        if ( v16 )
        {
          *v16 = 0;
          v16[1] = -1;
          v17 = (int)v16;
        }
        else
        {
          v17 = 0;
        }
        sub_578600(::Destination);
        sub_414410((_DWORD *)this + 7530, v17, 0);
        sub_45D100(&byte_764D68, (int)::Destination, 3, 16909060, 0);
        sub_56A390(*((_DWORD *)this + 1677));
        if ( (unsigned __int8)sub_4BA730(::Destination, 2.0, 1) )
        {
          Sleep(0x3E8u);
          return 1;
        }
        return v75;
      }
      v18 = (const char *)sub_460310(v15);
      if ( !strlen(v18) )
        return v75;
      if ( sub_41F230(dword_62A170, aWasRemovedFrom, ::Destination) )
      {
        strncpy(::Destination, aWasRemovedFrom, 0x1FFu);
        byte_62A37B = 0;
      }
      sprintf(Destination, "%s %s", v18, ::Destination);
      sub_45D100(&byte_764D68, (int)Destination, 3, 16909060, 0);
      return 1;
    case 0x23:
      this[30112] = *((_BYTE *)a2 + 8);
      this[30113] = *((_BYTE *)a2 + 9);
      sub_461E20(1);
      return 1;
    case 0x24:
      v79 = 0;
      v76 = 0;
      v19 = (char *)&unk_62BF68 + 25304 * (LOBYTE(v2) & 0x3F);
      sub_5208C0(v87);
      if ( !v19 )
        goto LABEL_85;
      v20 = sub_4E7790(v19 + 24992);
      if ( !v20 )
        goto LABEL_81;
      v21 = *(const char **)(v20 + 8);
      if ( !v21 )
        v21 = &byte_629120;
      v22 = &v21[strlen(v21)];
      if ( v22 <= v21 )
        goto LABEL_80;
      while ( *v22 != 92 )
      {
        if ( --v22 <= v21 )
          goto LABEL_80;
      }
      ++v22;
LABEL_80:
      v79 = v22;
LABEL_81:
      v23 = *((_DWORD *)v19 + 4695);
      if ( v23 )
      {
        v24 = *(CHAR **)(v23 + 24);
        if ( !v24 )
          v24 = &byte_629120;
        v76 = v24;
      }
LABEL_85:
      if ( (*a2 & 0xFFC0u) > 0x400 )
      {
        strcat((char *)a2 + 24, ".hdv");
        if ( !v79 )
          goto LABEL_93;
        v25 = &v79[strlen(v79)];
        if ( v25 > v79 )
        {
          while ( *v25 != 92 )
          {
            if ( --v25 <= v79 )
              goto LABEL_92;
          }
          ++v25;
        }
LABEL_92:
        if ( _strcmpi(v25, (const char *)a2 + 24) )
        {
LABEL_93:
          v78 = 0.0;
          if ( dword_7D6A58 > 0 )
          {
            v80 = 0;
            do
            {
              v26 = *(const char **)(v80 + dword_7D6A5C + 8);
              v27 = (CHAR **)(v80 + dword_7D6A5C + 8);
              if ( !v26 )
                v26 = &byte_629120;
              v28 = &v26[strlen(v26)];
              if ( v28 > v26 )
              {
                while ( *v28 != 92 )
                {
                  if ( --v28 <= v26 )
                    goto LABEL_102;
                }
                ++v28;
              }
LABEL_102:
              v79 = v28;
              if ( !_strcmpi(v28, (const char *)a2 + 24) )
              {
                sub_430BC0(v93);
                v29 = *v27;
                if ( !*v27 )
                  v29 = &byte_629120;
                sub_521740((char)v29, (int)v93, 3);
                v76 = (CHAR *)v87[0];
                if ( !v87[0] )
                  v76 = &byte_629120;
                sub_430670(v95);
                if ( v94 )
                  sub_5BE8AE(v94);
              }
              v30 = ++LODWORD(v78) < dword_7D6A58;
              v80 += 1232;
            }
            while ( v30 );
          }
        }
      }
      if ( !(unsigned __int8)sub_462160(a2, v79, v76) )
      {
        for ( j = 0; j < 5; ++j )
        {
          v32 = v31;
          v31 = (char *)j;
          switch ( j )
          {
            case 0:
              v33 = this[30114];
              v34 = 0;
              do
              {
                v35 = byte_5FFC7C[v34];
                Destination[v34++] = v35;
              }
              while ( v35 );
              goto LABEL_137;
            case 1:
              v36 = v79;
              v33 = this[30115];
              if ( v79 )
              {
                v31 = (char *)(Destination - v79);
                do
                {
                  v37 = *v36;
                  v31[(_DWORD)v36] = *v36;
                  ++v36;
                }
                while ( v37 );
              }
              else
              {
                Destination[0] = 0;
              }
              goto LABEL_137;
            case 2:
              v33 = this[30116];
              v38 = 0;
              do
              {
                v39 = aTerrainIni[v38];
                Destination[v38++] = v39;
              }
              while ( v39 );
              goto LABEL_137;
            case 3:
              v40 = dword_766578;
              v33 = this[30117];
              if ( !dword_766578 )
                v40 = &byte_629120;
              v41 = &v40[strlen(v40)];
              if ( v41 <= v40 )
                goto LABEL_131;
              break;
            default:
              v31 = v32;
              continue;
          }
          while ( *v41 != 92 )
          {
            if ( --v41 <= v40 )
              goto LABEL_131;
          }
          ++v41;
LABEL_131:
          strncpy(Destination, v41, 0x4Fu);
          v83 = 0;
          v42 = &Destination[strlen(Destination)];
          if ( v42 > Destination )
          {
            while ( *v42 != 46 )
            {
              --v42;
              v31 = Destination;
              if ( v42 <= Destination )
                goto LABEL_136;
            }
            *v42 = 0;
          }
LABEL_136:
          v43 = &Destination[strlen(Destination) + 1];
          v44 = byte_5FFC78;
          *(_DWORD *)--v43 = dword_5FFC74;
          v43[4] = v44;
LABEL_137:
          if ( !v33 )
          {
            v45 = (const char *)sub_460310(a2[51]);
            if ( sub_41F230(dword_62A170, aMismatch, ::Destination) )
            {
              strncpy(::Destination, aMismatch, 0x1FFu);
              byte_62A37B = 0;
            }
            sprintf(Source, "%s \"%s\" %s", v45, Destination, ::Destination);
            v46 = operator new(8u);
            if ( v46 )
            {
              *v46 = 0;
              v46[1] = -1;
              v47 = v46;
            }
            else
            {
              v47 = 0;
            }
            sub_578600(Source);
            if ( v47 )
            {
              v48 = operator new(0xCu);
              if ( v48 )
              {
                *v48 = v47;
                v48[1] = 0;
                *((_BYTE *)v48 + 8) = 0;
              }
              else
              {
                v48 = 0;
              }
              if ( *((_DWORD *)this + 7530) )
              {
                *(_DWORD *)(*((_DWORD *)this + 7531) + 4) = v48;
              }
              else
              {
                *((_DWORD *)this + 7530) = v48;
                *((_DWORD *)this + 7532) = v48;
              }
              *((_DWORD *)this + 7531) = v48;
              ++*((_DWORD *)this + 7533);
            }
            sub_45D100(&byte_764D68, (int)Source, 3, 16909060, 0);
            v49 = strlen(Source) + 1;
            v50 = v49 - 1;
            if ( (int)(v49 - 1) >= 0 )
            {
              if ( (int)(v49 - 1) > 127 )
                v50 = 127;
            }
            else
            {
              v50 = 0;
            }
            v71 = dbl_7DA9D0;
            sub_4D0D00(4, 6, v50, 0, LODWORD(v71), 3);
            strncpy(v85, Source, v50);
            v85[v50] = 0;
            sub_463A40(v84, 0, -1, -1);
          }
        }
      }
      if ( v92 )
        sub_5BE8AE(v92);
      if ( v91 )
        sub_5BE8AE(v91);
      if ( v90 )
        sub_5BE8AE(v90);
      if ( v89 )
        sub_5BE8AE(v89);
      if ( v88 )
        sub_5BE8AE(v88);
      if ( !v87[0] )
        return v75;
      sub_5BE8AE(v87[0]);
      return 1;
    case 0x30:
      *((_BYTE *)a2 + (LOWORD(v2) >> 6) + 8) = 0;
      a2[34] = a2[51];
      if ( !byte_769AD8 )
        goto LABEL_196;
      v51 = (int *)*((_DWORD *)this + 1681);
      *((_DWORD *)this + 1683) = v51;
      if ( !v51 )
        goto LABEL_196;
      v52 = *v51;
      if ( !*v51 )
        goto LABEL_196;
      break;
    case 0x31:
      result = 1;
      *((_DWORD *)this + 160) = 2;
      return result;
    case 0x32:
      result = 1;
      *((_DWORD *)this + 160) = 3;
      return result;
    case 0x33:
      v61 = 0;
      if ( *((int *)this + 1628) <= 0 )
        return v75;
      v62 = this + 852;
      do
      {
        if ( (unsigned __int8)sub_462C60(1) && sub_45DFA0((unsigned __int8 *)this + 27716, *v62, &v78, COERCE_FLOAT(1)) )
        {
          v80 = *((__int16 *)a2 + 4);
          v63 = (double)v80 * 0.00025000001;
          if ( *((float *)this + 166) < fabs(v63 - v78) || v63 < 0.0 || v78 < 0.0 )
          {
            v66 = *((float *)this + 166);
            *((_DWORD *)this + 4) = 1065353216;
            *((float *)this + 166) = v66 + 0.025;
          }
          else
          {
            v64 = *((float *)this + 166) * 0.050000001;
            if ( v64 >= 0.00050000002 )
            {
              if ( v64 > 0.0099999998 )
                v64 = 0.0099999998;
            }
            else
            {
              v64 = 0.00050000002;
            }
            v65 = *((float *)this + 166) - v64;
            *((float *)this + 166) = v65;
            if ( v65 < 0.0099999998 )
              *((_DWORD *)this + 166) = 1008981770;
          }
        }
        ++v61;
        v62 += 116;
      }
      while ( v61 < *((_DWORD *)this + 1628) );
      return 1;
    default:
      goto LABEL_238;
  }
  while ( _strcmpi((const char *)v52, (const char *)a2 + 8) )
  {
    v53 = *((_DWORD *)this + 1683);
    if ( v53 )
      *((_DWORD *)this + 1683) = *(_DWORD *)(v53 + 4);
    v54 = (int *)*((_DWORD *)this + 1683);
    if ( v54 )
    {
      v52 = *v54;
      if ( *v54 )
        continue;
    }
    goto LABEL_196;
  }
  v55 = 0;
  v56 = this + 6320;
  do
  {
    if ( *v56 == *(_DWORD *)(v52 + 128) )
      break;
    ++v55;
    ++v56;
  }
  while ( v55 < 48 );
  if ( v55 != 48 )
  {
    v73 = dbl_7DA9D0;
    sub_4D0D00(4, 50, 0, 63, LODWORD(v73), 3);
    goto LABEL_204;
  }
  v57 = *((_DWORD *)this + 1681);
  v58 = 0;
  if ( v57 )
  {
    while ( *(_DWORD *)v57 != v52 )
    {
      v58 = v57;
      v57 = *(_DWORD *)(v57 + 4);
      if ( !v57 )
        goto LABEL_196;
    }
    if ( v57 == *((_DWORD *)this + 1683) )
      *((_DWORD *)this + 1683) = *(_DWORD *)(v57 + 4);
    if ( v58 )
      *(_DWORD *)(v58 + 4) = *(_DWORD *)(v57 + 4);
    else
      *((_DWORD *)this + 1681) = *(_DWORD *)(v57 + 4);
    if ( *((_DWORD *)this + 1682) == v57 )
      *((_DWORD *)this + 1682) = v58;
    --*((_DWORD *)this + 1684);
    if ( *(_BYTE *)(v57 + 8) )
      sub_5BE8AE(*(LPVOID *)v57);
    sub_5BE8AE((LPVOID)v57);
  }
LABEL_196:
  v59 = (int *)operator new(0x84u);
  qmemcpy(v59, a2 + 2, 0x84u);
  v60 = operator new(0xCu);
  if ( v60 )
  {
    *v60 = v59;
    v60[1] = 0;
    *((_BYTE *)v60 + 8) = 1;
  }
  else
  {
    v60 = 0;
  }
  if ( *((_DWORD *)this + 1681) )
  {
    *(_DWORD *)(*((_DWORD *)this + 1682) + 4) = v60;
  }
  else
  {
    *((_DWORD *)this + 1681) = v60;
    *((_DWORD *)this + 1683) = v60;
  }
  *((_DWORD *)this + 1682) = v60;
  ++*((_DWORD *)this + 1684);
  v72 = dbl_7DA9D0;
  sub_4D0D00(4, 49, 0, 63, LODWORD(v72), 3);
LABEL_204:
  sub_463A40(v84, 2, a2[51], -1);
  return 1;
}
