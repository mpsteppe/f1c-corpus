_DWORD *__thiscall sub_4CF070(int this)
{
  char *v2; // ebx
  int v3; // eax
  _BYTE *v4; // edx
  char v5; // cl
  int v6; // eax
  _DWORD *result; // eax
  int v8; // edi
  int v9; // eax
  _BYTE *v10; // ebp
  _BYTE *v11; // ebp
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
  int v31; // ebx
  int v32; // ebp
  int v33; // eax
  int v34; // eax
  int v35; // edi
  int v36; // ebp
  int v37; // eax
  int v38; // eax
  int v39; // ecx
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // edi
  int v44; // ebp
  int v45; // eax
  int v46; // eax
  int v47; // ecx
  int i; // ebp
  int v49; // ebx
  int v50; // edi
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
  int v68; // [esp+10h] [ebp-9F8h]
  int v69; // [esp+10h] [ebp-9F8h]
  char *v70; // [esp+14h] [ebp-9F4h]
  _BYTE *v71; // [esp+14h] [ebp-9F4h]
  int j; // [esp+14h] [ebp-9F4h]
  int v73; // [esp+18h] [ebp-9F0h]
  char *v74; // [esp+1Ch] [ebp-9ECh]
  int v75; // [esp+20h] [ebp-9E8h] BYREF
  float v76[3]; // [esp+24h] [ebp-9E4h] BYREF
  double v77[3]; // [esp+30h] [ebp-9D8h] BYREF
  int v78; // [esp+48h] [ebp-9C0h]
  int v79; // [esp+4Ch] [ebp-9BCh]
  int v80; // [esp+50h] [ebp-9B8h]
  int v81; // [esp+54h] [ebp-9B4h]
  int v82; // [esp+60h] [ebp-9A8h]
  _BYTE v83[32]; // [esp+64h] [ebp-9A4h] BYREF
  int v84[3]; // [esp+84h] [ebp-984h] BYREF
  _BYTE v85[64]; // [esp+90h] [ebp-978h] BYREF
  _BYTE v86[384]; // [esp+D0h] [ebp-938h] BYREF
  int v87; // [esp+250h] [ebp-7B8h]
  char v88; // [esp+254h] [ebp-7B4h]
  int v89; // [esp+25Ch] [ebp-7ACh]
  int v90; // [esp+260h] [ebp-7A8h]
  int v91; // [esp+264h] [ebp-7A4h]
  char v92[384]; // [esp+268h] [ebp-7A0h] BYREF
  _BYTE v93[32]; // [esp+3E8h] [ebp-620h] BYREF
  CHAR v94[256]; // [esp+408h] [ebp-600h] BYREF
  CHAR v95[256]; // [esp+508h] [ebp-500h] BYREF
  _BYTE v96[256]; // [esp+608h] [ebp-400h] BYREF
  _BYTE v97[256]; // [esp+708h] [ebp-300h] BYREF
  CHAR v98[256]; // [esp+808h] [ebp-200h] BYREF
  _BYTE v99[256]; // [esp+908h] [ebp-100h] BYREF

  v2 = 0;
  memset(v92, 0, sizeof(v92));
  v87 = 0;
  v91 = 0;
  v89 = 0;
  v90 = 0;
  v88 = 1;
  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_25, 2908) )
    sub_4D7AA0(&unk_8AD25C, aEnteredSpecial_1);
  v3 = 396 * dword_8AC48C + dword_8AC490 + 260;
  v4 = &v97[-v3];
  do
  {
    v5 = *(_BYTE *)v3;
    v4[v3] = *(_BYTE *)v3;
    ++v3;
  }
  while ( v5 );
  sub_4CEEF0((int)v96, 256);
  sub_568A60(181, this + 56);
  v6 = sub_587DB0(v96, aRt);
  v68 = v6;
  if ( v6 )
  {
    v74 = 0;
    *(_DWORD *)(this + 8) = 0;
    v73 = 0;
    if ( sub_587CA0(v92, 384, v6) )
    {
      v8 = v68;
      v70 = v99;
      while ( 1 )
      {
        if ( !sub_5651B0(v86) )
        {
          if ( sub_587C20(v92, aTrackvars) && sub_587CA0(v92, 384, v8) )
          {
            do
            {
              v9 = sub_5651B0(v86);
              if ( v9 == 1 || v9 == 4 )
                break;
              if ( !v9 )
              {
                v10 = (_BYTE *)sub_589DB0(v92, 61);
                if ( v10 )
                {
                  if ( strlen(v92) < 0x20 )
                  {
                    *v10 = 0;
                    v11 = v10 + 1;
                    v12 = (_DWORD *)sub_587C03(40);
                    v13 = v12 ? (char *)sub_4C9D10(v12) : 0;
                    strcpy(v13, v92);
                    *((float *)v13 + 8) = sub_58850F(v11);
                    *((_DWORD *)v13 + 9) = v2;
                    v2 = v13;
                    if ( !sub_4C58A0((int)v93, 32, (int)v13, 0) )
                      *((float *)v13 + 8) = sub_58850F(v93);
                  }
                  v8 = v68;
                }
              }
            }
            while ( sub_587CA0(v92, 384, v8) );
            v74 = v2;
          }
          if ( sub_587C20(v92, aFeedback) )
          {
            v14 = 1;
            v15 = 0;
            while ( sub_587CA0(v92, 384, v68) )
            {
              v16 = sub_5651B0(v86);
              if ( v16 == 1 || v16 == 4 )
                break;
              if ( !v16 )
              {
                if ( sub_565520(aIncludetracks, v94, 0) && !sub_566810(v94, v97) )
                  v14 = 0;
                if ( sub_565520(aExcludetracks, v94, 0) && sub_566810(v94, v97) )
                  v14 = 0;
                if ( sub_565520(aReaction, v94, 0) )
                  ++v15;
              }
            }
            *v70++ = v14;
            if ( v14 )
            {
              ++*(_DWORD *)(this + 8);
              v73 += v15;
            }
          }
          else if ( sub_587C20(v92, aLoose) && sub_587CA0(v92, 384, v8) )
          {
            v17 = v73;
            do
            {
              v18 = sub_5651B0(v86);
              if ( v18 == 1 || v18 == 4 )
                break;
              if ( !v18 && sub_565520(aReaction, v94, 0) )
                ++v17;
            }
            while ( sub_587CA0(v92, 384, v8) );
            v73 = v17;
          }
        }
        v8 = v68;
        if ( !sub_587CA0(v92, 384, v68) )
          break;
        v2 = v74;
      }
    }
    v19 = *(_DWORD *)(this + 8);
    v20 = (_DWORD *)sub_587C03(108 * v19 + 4);
    if ( v20 )
    {
      v21 = v20 + 1;
      *v20 = v19;
      v22 = v20 + 1;
      if ( v19 - 1 >= 0 )
      {
        do
        {
          sub_4CDB90(v22);
          v22 += 27;
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
    v24 = (_DWORD *)sub_587C03(108 * v73 + 4);
    if ( v24 )
    {
      v25 = v24 + 1;
      *v24 = v73;
      v26 = v24 + 1;
      if ( v73 - 1 >= 0 )
      {
        v27 = v73;
        do
        {
          sub_4CA3E0(v26);
          v26 = (_DWORD *)(v28 + 108);
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
    v29 = (const char *)dword_5EC428;
    if ( !dword_5EC428 )
      v29 = byte_5EA438;
    v30 = (const char *)dword_5EC3D8;
    if ( !dword_5EC3D8 )
      v30 = byte_5EA438;
    sub_58815F(v95, "%s%s", v30, v29);
    sub_58815F(v98, aCmapsMas);
    v31 = v68;
    sub_587F64(v68, 0, 0);
    if ( sub_587CA0(v92, 384, v68) )
    {
      v32 = 0;
      v69 = 0;
      v71 = v99;
      while ( 1 )
      {
        if ( !sub_5651B0(v86) )
        {
          if ( sub_587C20(v92, aFeedback) )
          {
            v52 = *v71++ == 0;
            if ( v52 )
            {
              if ( sub_587CA0(v92, 384, v31) )
              {
                while ( sub_5651B0(v86) != 1 && sub_587CA0(v92, 384, v31) )
                  ;
              }
            }
            else
            {
              while ( sub_587CA0(v92, 384, v31) )
              {
                v33 = sub_5651B0(v86);
                if ( v33 == 1 || v33 == 4 )
                  break;
                if ( !v33 )
                {
                  if ( sub_565520(aReaction, v94, 0) )
                  {
                    sub_4CA480(*(_DWORD *)(this + 20) + 108 * *(_DWORD *)(this + 16), (int)v86);
                    v34 = *(_DWORD *)(this + 16);
                    v35 = 0;
                    if ( v34 > 0 )
                    {
                      v36 = 0;
                      do
                      {
                        if ( sub_4CAED0(v36 + *(_DWORD *)(this + 20), *(_DWORD *)(this + 20) + 108 * v34) )
                          break;
                        v34 = *(_DWORD *)(this + 16);
                        ++v35;
                        v36 += 108;
                      }
                      while ( v35 < v34 );
                    }
                    v37 = *(_DWORD *)(this + 16);
                    if ( v35 == v37 )
                      *(_DWORD *)(this + 16) = v37 + 1;
                    v38 = *(_DWORD *)(this + 12);
                    v32 = v69;
                    v39 = *(_DWORD *)(v38 + v69 + 60);
                    v40 = v69 + v38;
                    *(_DWORD *)(v40 + 4 * v39 + 64) = *(_DWORD *)(this + 20) + 108 * v35;
                    ++*(_DWORD *)(v40 + 60);
                  }
                  sub_4CDD80(v32 + *(_DWORD *)(this + 12), (int)v86, (int)v74);
                }
              }
              v69 = v32 + 108;
            }
          }
          else if ( sub_587C20(v92, aLoose) && sub_587CA0(v92, 384, v31) )
          {
            do
            {
              v41 = sub_5651B0(v86);
              if ( v41 == 1 || v41 == 4 )
                break;
              if ( !v41 )
              {
                if ( sub_565520(aReaction, v94, 0) )
                {
                  sub_4CA480(*(_DWORD *)(this + 20) + 108 * *(_DWORD *)(this + 16), (int)v86);
                  v42 = *(_DWORD *)(this + 16);
                  v43 = 0;
                  if ( v42 > 0 )
                  {
                    v44 = 0;
                    do
                    {
                      if ( sub_4CAED0(v44 + *(_DWORD *)(this + 20), *(_DWORD *)(this + 20) + 108 * v42) )
                        break;
                      v42 = *(_DWORD *)(this + 16);
                      ++v43;
                      v44 += 108;
                    }
                    while ( v43 < v42 );
                  }
                  v45 = *(_DWORD *)(this + 16);
                  if ( v43 == v45 )
                    *(_DWORD *)(this + 16) = v45 + 1;
                }
                sub_565520(aSearchpath, v95, 0);
                sub_565520(aMasfile, v98, 0);
              }
            }
            while ( sub_587CA0(v92, 384, v31) );
          }
        }
        if ( !sub_587CA0(v92, 384, v31) )
          break;
        v32 = v69;
      }
    }
    sub_587D02(v31);
    if ( v74 )
    {
      sub_4C9D30(v74);
      sub_587BCF(v74);
    }
    v46 = 0;
    if ( *(int *)(this + 16) > 0 )
    {
      v47 = 0;
      do
      {
        *(_DWORD *)(v47 + *(_DWORD *)(this + 20)) = v46++;
        v47 += 108;
      }
      while ( v46 < *(_DWORD *)(this + 16) );
    }
    sub_53C800(v95);
    sub_53CBC0(&v75, v98);
    for ( i = 0; i < 3; ++i )
    {
      v49 = 0;
      if ( *(int *)(this + 16) > 0 )
      {
        v50 = 0;
LABEL_117:
        v51 = v50 + *(_DWORD *)(this + 20);
        switch ( *(_DWORD *)(v51 + 4) )
        {
          case 4:
          case 0xB:
          case 0xC:
          case 0xD:
            v52 = i == 1;
            goto LABEL_123;
          case 6:
          case 7:
          case 8:
            v52 = i == 0;
            goto LABEL_123;
          case 9:
          case 0xA:
            if ( !i )
              sub_4CB120((char *)v51, 0);
            goto LABEL_125;
          default:
            v52 = i == 2;
LABEL_123:
            if ( v52 )
              sub_4CB120((char *)v51, 1);
LABEL_125:
            ++v49;
            v50 += 108;
            if ( v49 >= *(_DWORD *)(this + 16) )
              continue;
            goto LABEL_117;
        }
      }
    }
    sub_53C900(v95);
    sub_53CE40(v75);
    sub_4CEF30((int *)this);
    v53 = *(_DWORD *)(this + 16);
    *(_DWORD *)(this + 24) = 0;
    *(_DWORD *)(this + 28) = 0;
    *(_DWORD *)(this + 32) = 0;
    *(_DWORD *)(this + 36) = 0;
    *(_DWORD *)(this + 40) = 0;
    if ( v53 > 0 )
    {
      v54 = *(_DWORD *)(this + 20);
      v55 = v53;
      do
      {
        v56 = *(_DWORD *)(v54 + 4);
        switch ( v56 )
        {
          case 12:
            *(_DWORD *)(this + 24) = v54;
            break;
          case 13:
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
        }
        v54 += 108;
        --v55;
      }
      while ( v55 );
    }
    sub_44C0E0(dbl_7C9360, 2);
    sub_4024F0((int)dword_5EA2C0);
    sub_403CD0(dword_5EA2C0, 0, v76, v84);
    v77[0] = v76[0];
    v77[1] = v76[1];
    v77[2] = v76[2];
    v78 = 0;
    v79 = 1076101120;
    v80 = 0x40000000;
    v81 = 1201543096;
    v82 = 0;
    v57 = sub_44C4C0(dbl_7C9360, (int)v77);
    if ( v57 )
    {
      v58 = *(_DWORD *)(v57 + 84);
      *(_DWORD *)(this + 44) = v58;
      *(float *)(this + 48) = *(float *)(v58 + 8) - *(float *)(v58 + 12) * 0.0;
      *(float *)(this + 52) = *(float *)(v58 + 8) - *(float *)(v58 + 12);
    }
    if ( !sub_4C58A0((int)v83, 32, (int)aAidrygrip, 0) )
      *(float *)(this + 48) = sub_58850F(v83);
    if ( !sub_4C58A0((int)v83, 32, (int)aAiwetgrip, 0) )
      *(float *)(this + 52) = sub_58850F(v83);
    *(_DWORD *)this = 0;
    v85[0] = 0;
    v59 = sub_5452F0(dword_8AFE88);
    v60 = 0;
    for ( j = v59; v60 < v59; ++v60 )
    {
      if ( (*(_BYTE *)(sub_545340(v60) + 60) & 0x10) == 0x10 )
      {
        sub_54BDA0(v85);
        if ( !sub_588640(v85, aLptree, 6) )
          ++*(_DWORD *)this;
      }
    }
    v61 = *(_DWORD *)this;
    v62 = (int *)sub_587C03(60 * *(_DWORD *)this + 4);
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
          sub_4CA280(v64);
          v64 += 15;
          --v61;
        }
        while ( v61 );
      }
      result = v63;
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
        v67 = sub_545340(v65);
        if ( (*(_BYTE *)(v67 + 60) & 0x10) == 0x10 )
        {
          sub_54BDA0(v85);
          if ( !sub_588640(v85, aLptree, 6) )
          {
            sub_4C9FB0((float *)(v66 + *(_DWORD *)(this + 4)), v67);
            v66 += 60;
          }
        }
        result = (_DWORD *)j;
        ++v65;
      }
      while ( v65 < j );
    }
  }
  else
  {
    result = (_DWORD *)sub_4D7A50(1, aDDevF119992002_25, 2928);
    if ( (_BYTE)result )
      return (_DWORD *)sub_4D7AA0(&unk_8AD25C, aCouldNotOpenS);
  }
  return result;
}
