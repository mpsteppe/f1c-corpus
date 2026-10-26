int __thiscall sub_4F6B90(int this)
{
  char *v2; // ebx
  int v3; // eax
  char *v4; // edx
  char v5; // cl
  FILE *v6; // eax
  int result; // eax
  FILE *v8; // edi
  int v9; // eax
  char *v10; // ebp
  const char *v11; // ebp
  _DWORD *v12; // eax
  char *v13; // edi
  char v14; // bl
  int v15; // ebp
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int v19; // edi
  _DWORD *v20; // eax
  _DWORD *v21; // ebx
  _DWORD *v22; // ebp
  _DWORD *v23; // eax
  _DWORD *v24; // eax
  _DWORD *v25; // edi
  _DWORD *v26; // edx
  int v27; // ebp
  int v28; // edx
  const char *v29; // ecx
  const char *v30; // eax
  FILE *v31; // ebx
  FILE *v32; // ebp
  int v33; // eax
  int v34; // eax
  int v35; // edi
  int v36; // ebp
  int v37; // eax
  int v38; // eax
  int v39; // ecx
  char *v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // edi
  int v44; // ebp
  int v45; // eax
  int v46; // eax
  int v47; // ecx
  int i; // edi
  int v49; // ebx
  int v50; // ebp
  int v51; // ecx
  bool v52; // zf
  int v53; // eax
  int v54; // ecx
  int v55; // edx
  int v56; // eax
  int v57; // eax
  int v58; // eax
  int v59; // ebx
  int v60; // edi
  int v61; // ebp
  int *v62; // eax
  _DWORD *v63; // ebx
  _DWORD *v64; // edi
  int v65; // ebp
  int v66; // ebx
  int v67; // edi
  char v68; // [esp+0h] [ebp-A08h]
  FILE *Stream; // [esp+10h] [ebp-9F8h]
  FILE *Streama; // [esp+10h] [ebp-9F8h]
  char *v71; // [esp+14h] [ebp-9F4h]
  _BYTE *v72; // [esp+14h] [ebp-9F4h]
  int j; // [esp+14h] [ebp-9F4h]
  int v74; // [esp+18h] [ebp-9F0h]
  char *v75; // [esp+1Ch] [ebp-9ECh]
  int v76; // [esp+20h] [ebp-9E8h] BYREF
  char v77[32]; // [esp+24h] [ebp-9E4h] BYREF
  float v78[3]; // [esp+44h] [ebp-9C4h] BYREF
  double v79[3]; // [esp+50h] [ebp-9B8h] BYREF
  int v80; // [esp+68h] [ebp-9A0h]
  int v81; // [esp+6Ch] [ebp-99Ch]
  int v82; // [esp+70h] [ebp-998h]
  int v83; // [esp+74h] [ebp-994h]
  int v84; // [esp+80h] [ebp-988h]
  int v85[3]; // [esp+84h] [ebp-984h] BYREF
  char Str1[64]; // [esp+90h] [ebp-978h] BYREF
  char v87[384]; // [esp+D0h] [ebp-938h] BYREF
  int v88; // [esp+250h] [ebp-7B8h]
  char v89; // [esp+254h] [ebp-7B4h]
  int v90; // [esp+25Ch] [ebp-7ACh]
  int v91; // [esp+260h] [ebp-7A8h]
  int v92; // [esp+264h] [ebp-7A4h]
  char Str[384]; // [esp+268h] [ebp-7A0h] BYREF
  char String[32]; // [esp+3E8h] [ebp-620h] BYREF
  char v95[256]; // [esp+408h] [ebp-600h] BYREF
  char Buffer[256]; // [esp+508h] [ebp-500h] BYREF
  char FileName[256]; // [esp+608h] [ebp-400h] BYREF
  char v98[256]; // [esp+708h] [ebp-300h] BYREF
  char v99[256]; // [esp+808h] [ebp-200h] BYREF
  _BYTE v100[256]; // [esp+908h] [ebp-100h] BYREF

  v2 = 0;
  memset(Str, 0, sizeof(Str));
  v88 = 0;
  v92 = 0;
  v90 = 0;
  v91 = 0;
  v89 = 1;
  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_20, 3166) )
    sub_500FE0((int)&unk_7D7920, aEnteredSpecial_1, v68);
  v3 = 400 * dword_7D6B54 + dword_7D6B58 + 260;
  v4 = &v98[-v3];
  do
  {
    v5 = *(_BYTE *)v3;
    v4[v3] = *(_BYTE *)v3;
    ++v3;
  }
  while ( v5 );
  sub_4F6A10(FileName, 256);
  sub_57B490(FileName, 181, this + 76);
  v6 = fopen(FileName, Mode);
  Stream = v6;
  if ( v6 )
  {
    v75 = 0;
    *(_DWORD *)(this + 8) = 0;
    v74 = 0;
    if ( fgets(Str, 384, v6) )
    {
      v8 = Stream;
      v71 = v100;
      while ( 1 )
      {
        if ( !sub_577B60(v87) )
        {
          if ( strstr(Str, aTrackvars) && fgets(Str, 384, v8) )
          {
            do
            {
              v9 = sub_577B60(v87);
              if ( v9 == 1 || v9 == 4 )
                break;
              if ( !v9 )
              {
                v10 = strchr(Str, 61);
                if ( v10 )
                {
                  if ( strlen(Str) < 0x20 )
                  {
                    *v10 = 0;
                    v11 = v10 + 1;
                    v12 = operator new(0x28u);
                    v13 = v12 ? (char *)sub_4F1120(v12) : 0;
                    strcpy(v13, Str);
                    *((float *)v13 + 8) = atof(v11);
                    *((_DWORD *)v13 + 9) = v2;
                    v2 = v13;
                    if ( !sub_4E8E50(String, 32, v13, 0) )
                      *((float *)v13 + 8) = atof(String);
                  }
                  v8 = Stream;
                }
              }
            }
            while ( fgets(Str, 384, v8) );
            v75 = v2;
          }
          if ( strstr(Str, aFeedback) )
          {
            v14 = 1;
            v15 = 0;
            while ( fgets(Str, 384, Stream) )
            {
              v16 = sub_577B60(v87);
              if ( v16 == 1 || v16 == 4 )
                break;
              if ( !v16 )
              {
                if ( sub_577ED0(v87, aIncludetracks, v95, 0) && !sub_579060(v95, v98) )
                  v14 = 0;
                if ( sub_577ED0(v87, aExcludetracks, v95, 0) && sub_579060(v95, v98) )
                  v14 = 0;
                if ( sub_577ED0(v87, aReaction, v95, 0) )
                  ++v15;
              }
            }
            *v71++ = v14;
            if ( v14 )
            {
              ++*(_DWORD *)(this + 8);
              v74 += v15;
            }
          }
          else if ( strstr(Str, aLoose) && fgets(Str, 384, v8) )
          {
            v17 = v74;
            do
            {
              v18 = sub_577B60(v87);
              if ( v18 == 1 || v18 == 4 )
                break;
              if ( !v18 && sub_577ED0(v87, aReaction, v95, 0) )
                ++v17;
            }
            while ( fgets(Str, 384, v8) );
            v74 = v17;
          }
        }
        v8 = Stream;
        if ( !fgets(Str, 384, Stream) )
          break;
        v2 = v75;
      }
    }
    v19 = *(_DWORD *)(this + 8);
    v20 = operator new(104 * v19 + 4);
    if ( v20 )
    {
      v21 = v20 + 1;
      *v20 = v19;
      v22 = v20 + 1;
      if ( v19 - 1 >= 0 )
      {
        do
        {
          sub_4F5680(v22);
          v22 += 26;
          --v19;
        }
        while ( v19 );
      }
      v23 = v21;
    }
    else
    {
      v23 = 0;
    }
    *(_DWORD *)(this + 12) = v23;
    v24 = operator new(116 * v74 + 4);
    if ( v24 )
    {
      v25 = v24 + 1;
      *v24 = v74;
      v26 = v24 + 1;
      if ( v74 - 1 >= 0 )
      {
        v27 = v74;
        do
        {
          sub_4F1830(v26);
          v26 = (_DWORD *)(v28 + 116);
          --v27;
        }
        while ( v27 );
      }
    }
    else
    {
      v25 = 0;
    }
    *(_DWORD *)(this + 20) = v25;
    *(_DWORD *)(this + 16) = 0;
    v29 = (const char *)dword_62A0B8;
    if ( !dword_62A0B8 )
      v29 = &byte_629120;
    v30 = *(const char **)dword_62A068;
    if ( !*(_DWORD *)dword_62A068 )
      v30 = &byte_629120;
    sprintf(Buffer, "%s%s", v30, v29);
    sprintf(v99, aCmapsMas);
    v31 = Stream;
    fseek(Stream, 0, 0);
    if ( fgets(Str, 384, Stream) )
    {
      v32 = 0;
      Streama = 0;
      v72 = v100;
      while ( 1 )
      {
        if ( !sub_577B60(v87) )
        {
          if ( strstr(Str, aFeedback) )
          {
            v52 = *v72++ == 0;
            if ( v52 )
            {
              if ( fgets(Str, 384, v31) )
              {
                while ( sub_577B60(v87) != 1 && fgets(Str, 384, v31) )
                  ;
              }
            }
            else
            {
              while ( fgets(Str, 384, v31) )
              {
                v33 = sub_577B60(v87);
                if ( v33 == 1 || v33 == 4 )
                  break;
                if ( !v33 )
                {
                  if ( sub_577ED0(v87, aReaction, v95, 0) )
                  {
                    sub_4F18E0(*(_DWORD *)(this + 20) + 116 * *(_DWORD *)(this + 16), v87);
                    v34 = *(_DWORD *)(this + 16);
                    v35 = 0;
                    if ( v34 > 0 )
                    {
                      v36 = 0;
                      do
                      {
                        if ( sub_4F2400(v36 + *(_DWORD *)(this + 20), *(_DWORD *)(this + 20) + 116 * v34) )
                          break;
                        v34 = *(_DWORD *)(this + 16);
                        ++v35;
                        v36 += 116;
                      }
                      while ( v35 < v34 );
                    }
                    v37 = *(_DWORD *)(this + 16);
                    if ( v35 == v37 )
                      *(_DWORD *)(this + 16) = v37 + 1;
                    v38 = *(_DWORD *)(this + 12);
                    v32 = Streama;
                    v39 = *(int *)((char *)&Streama[1]._bufsiz + v38);
                    v40 = (char *)Streama + v38;
                    *(_DWORD *)&v40[4 * v39 + 60] = *(_DWORD *)(this + 20) + 116 * v35;
                    ++*((_DWORD *)v40 + 14);
                  }
                  sub_4F5870((int)v32 + *(_DWORD *)(this + 12), v87, (int)v75);
                }
              }
              Streama = (FILE *)((char *)v32 + 104);
            }
          }
          else if ( strstr(Str, aLoose) && fgets(Str, 384, v31) )
          {
            do
            {
              v41 = sub_577B60(v87);
              if ( v41 == 1 || v41 == 4 )
                break;
              if ( !v41 )
              {
                if ( sub_577ED0(v87, aReaction, v95, 0) )
                {
                  sub_4F18E0(*(_DWORD *)(this + 20) + 116 * *(_DWORD *)(this + 16), v87);
                  v42 = *(_DWORD *)(this + 16);
                  v43 = 0;
                  if ( v42 > 0 )
                  {
                    v44 = 0;
                    do
                    {
                      if ( sub_4F2400(v44 + *(_DWORD *)(this + 20), *(_DWORD *)(this + 20) + 116 * v42) )
                        break;
                      v42 = *(_DWORD *)(this + 16);
                      ++v43;
                      v44 += 116;
                    }
                    while ( v43 < v42 );
                  }
                  v45 = *(_DWORD *)(this + 16);
                  if ( v43 == v45 )
                    *(_DWORD *)(this + 16) = v45 + 1;
                }
                sub_577ED0(v87, aSearchpath, Buffer, 0);
                sub_577ED0(v87, aMasfile, v99, 0);
              }
            }
            while ( fgets(Str, 384, v31) );
          }
        }
        if ( !fgets(Str, 384, v31) )
          break;
        v32 = Streama;
      }
    }
    fclose(v31);
    if ( v75 )
    {
      sub_4F1140(v75);
      sub_5BE8AE();
    }
    v46 = 0;
    if ( *(int *)(this + 16) > 0 )
    {
      v47 = 0;
      do
      {
        *(_DWORD *)(v47 + *(_DWORD *)(this + 20)) = v46++;
        v47 += 116;
      }
      while ( v46 < *(_DWORD *)(this + 16) );
    }
    sub_591F10(Buffer);
    sub_5924D0(dword_7DA988, (int)&v76, (int)v99);
    for ( i = 0; i < 4; ++i )
    {
      v49 = 0;
      if ( *(int *)(this + 16) > 0 )
      {
        v50 = 0;
LABEL_117:
        v51 = *(_DWORD *)(this + 20) + v50;
        switch ( *(_DWORD *)(v51 + 4) )
        {
          case 4:
            v52 = i == 3;
            goto LABEL_124;
          case 6:
          case 7:
          case 8:
            v52 = i == 0;
            goto LABEL_124;
          case 9:
          case 0xA:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0x11:
            if ( !i )
              sub_4F2650((char *)v51, 0);
            goto LABEL_126;
          case 0xB:
          case 0xF:
          case 0x10:
            v52 = i == 1;
            goto LABEL_124;
          default:
            v52 = i == 2;
LABEL_124:
            if ( v52 )
              sub_4F2650((char *)v51, 1);
LABEL_126:
            ++v49;
            v50 += 116;
            if ( v49 >= *(_DWORD *)(this + 16) )
              continue;
            goto LABEL_117;
        }
      }
    }
    sub_592030(Buffer);
    sub_592750(v76);
    sub_4F6A50((int *)this);
    v53 = *(_DWORD *)(this + 16);
    *(_DWORD *)(this + 24) = 0;
    *(_DWORD *)(this + 28) = 0;
    *(_DWORD *)(this + 32) = 0;
    *(_DWORD *)(this + 36) = 0;
    *(_DWORD *)(this + 40) = 0;
    *(_DWORD *)(this + 44) = 0;
    if ( v53 > 0 )
    {
      v54 = *(_DWORD *)(this + 20);
      v55 = v53;
      do
      {
        v56 = *(_DWORD *)(v54 + 4);
        switch ( v56 )
        {
          case 15:
            *(_DWORD *)(this + 24) = v54;
            break;
          case 16:
            *(_DWORD *)(this + 28) = v54;
            break;
          case 1:
            *(_DWORD *)(this + 32) = v54;
            break;
          case 3:
            *(_DWORD *)(this + 36) = v54;
            break;
          case 4:
            *(_DWORD *)(this + 40) = v54;
            break;
          case 17:
            *(_DWORD *)(this + 44) = v54;
            break;
        }
        v54 += 116;
        --v55;
      }
      while ( v55 );
    }
    sub_44E520(dbl_760B48, 2);
    sub_402940((int)&flt_628F60, 1, 0);
    sub_4042F0(&flt_628F60, 0, v78, v85);
    v79[0] = v78[0];
    v79[1] = v78[1];
    v79[2] = v78[2];
    v80 = 0;
    v81 = 1076101120;
    v82 = 0x40000000;
    v83 = 1201543096;
    v84 = 0;
    v57 = sub_44E900(dbl_760B48, (int)v79);
    if ( v57 )
    {
      v58 = *(_DWORD *)(v57 + 84);
      *(_DWORD *)(this + 48) = v58;
      *(float *)(this + 52) = *(float *)(v58 + 8) - *(float *)(v58 + 12) * 0.0;
      *(float *)(this + 56) = *(float *)(v58 + 8) - *(float *)(v58 + 12);
    }
    *(_DWORD *)(this + 60) = 1065353216;
    *(_DWORD *)(this + 64) = 1065353216;
    *(_DWORD *)(this + 68) = 1065353216;
    *(_DWORD *)(this + 72) = 1065353216;
    if ( !sub_4E8E50(v77, 32, aAidrygrip, 0) )
      *(float *)(this + 52) = atof(v77);
    if ( !sub_4E8E50(v77, 32, aAiwetgrip, 0) )
      *(float *)(this + 56) = atof(v77);
    if ( !sub_4E8E50(v77, 32, aAitirewear, 0) )
      *(float *)(this + 60) = atof(v77);
    if ( !sub_4E8E50(v77, 32, aAifuelmult, 0) )
      *(float *)(this + 64) = atof(v77);
    if ( !sub_4E8E50(v77, 32, aPlayertirewear, 0) )
      *(float *)(this + 68) = atof(v77);
    if ( !sub_4E8E50(v77, 32, aPlayerfuelmult, 0) )
      *(float *)(this + 72) = atof(v77);
    *(_DWORD *)this = 0;
    Str1[0] = 0;
    v59 = sub_597540(dword_7DA9B8);
    v60 = 0;
    for ( j = v59; v60 < v59; ++v60 )
    {
      if ( (*(_BYTE *)(sub_597590(v60) + 60) & 0x10) == 0x10 )
      {
        sub_59EA30(Str1);
        if ( !strncmp(Str1, aLptree, 6u) )
          ++*(_DWORD *)this;
      }
    }
    v61 = *(_DWORD *)this;
    v62 = (int *)operator new(60 * *(_DWORD *)this + 4);
    if ( v62 )
    {
      v63 = v62 + 1;
      *v62 = v61;
      v64 = v62 + 1;
      if ( v61 - 1 >= 0 )
      {
        do
        {
          v64[14] = 0;
          sub_4F16D0(v64);
          v64 += 15;
          --v61;
        }
        while ( v61 );
      }
      result = (int)v63;
      v59 = j;
    }
    else
    {
      result = 0;
    }
    v65 = 0;
    *(_DWORD *)(this + 4) = result;
    if ( v59 > 0 )
    {
      v66 = 0;
      do
      {
        v67 = sub_597590(v65);
        if ( (*(_BYTE *)(v67 + 60) & 0x10) == 0x10 )
        {
          sub_59EA30(Str1);
          if ( !strncmp(Str1, aLptree, 6u) )
          {
            sub_4F1400((float *)(v66 + *(_DWORD *)(this + 4)), v67);
            v66 += 60;
          }
        }
        result = j;
        ++v65;
      }
      while ( v65 < j );
    }
  }
  else
  {
    result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_20, 3186);
    if ( (_BYTE)result )
      return sub_500FE0((int)&unk_7D7920, aCouldNotOpenS, (char)FileName);
  }
  return result;
}
