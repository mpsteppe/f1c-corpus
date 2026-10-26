char __thiscall NetCommSessionMessageDispatcher(char *this, unsigned int *a2)
{
  unsigned int *v2; // esi
  unsigned int v3; // eax
  char v5; // bl
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // esi
  int v9; // edx
  int v10; // eax
  char v11; // cl
  char result; // al
  int v13; // esi
  unsigned int v14; // edi
  int i; // ecx
  float v16; // eax
  float *v17; // eax
  float *v18; // ecx
  int v19; // edx
  int v20; // eax
  char v21; // cl
  int v22; // eax
  int v23; // esi
  int v24; // eax
  char v25; // cl
  _DWORD *v26; // eax
  int v27; // esi
  int v28; // edx
  char *v29; // esi
  int v30; // eax
  char v31; // cl
  int v32; // eax
  const char *v33; // edi
  bool v34; // zf
  char *v35; // eax
  int v36; // eax
  const char *v37; // edx
  const char *v38; // ecx
  char *v39; // edx
  char *v40; // kr00_4
  char v41; // bl
  int v42; // eax
  char v43; // cl
  float v44; // eax
  char v45; // cl
  int v46; // eax
  char v47; // cl
  const char *v48; // edx
  char *v49; // ecx
  char *v50; // eax
  char *v51; // edi
  char v52; // cl
  const char *v53; // ecx
  const char *v54; // eax
  char *v55; // esi
  int v56; // eax
  char v57; // cl
  _DWORD *v58; // eax
  int v59; // esi
  int v60; // eax
  unsigned int v61; // kr1C_4
  unsigned int v62; // esi
  _BYTE **v63; // eax
  _BYTE *v64; // eax
  int v65; // eax
  _BYTE **v66; // eax
  _BYTE *v67; // esi
  int v68; // eax
  int v69; // edi
  char *v70; // esi
  double v71; // st7
  double v72; // st7
  double v73; // st7
  double v74; // st7
  _DWORD *v75; // ecx
  int v76; // [esp+0h] [ebp-2B0h]
  int v77; // [esp+0h] [ebp-2B0h]
  int v78; // [esp+0h] [ebp-2B0h]
  int v79; // [esp+0h] [ebp-2B0h]
  int v80; // [esp+0h] [ebp-2B0h]
  char v81; // [esp+1Bh] [ebp-295h]
  float v82; // [esp+1Ch] [ebp-294h] BYREF
  int j; // [esp+20h] [ebp-290h]
  char v84[79]; // [esp+24h] [ebp-28Ch] BYREF
  char v85; // [esp+73h] [ebp-23Dh]
  char v86[4]; // [esp+74h] [ebp-23Ch] BYREF
  char v87[136]; // [esp+78h] [ebp-238h] BYREF
  char v88[253]; // [esp+100h] [ebp-1B0h] BYREF
  __int16 v89; // [esp+1FDh] [ebp-B3h]
  char v90; // [esp+1FFh] [ebp-B1h]

  v2 = a2;
  v3 = *a2;
  v5 = 0;
  v81 = 1;
  if ( (*a2 & 0xE0000000) == 0x80000000 )
  {
    switch ( (v3 >> 18) & 0x3F )
    {
      case 0u:
      case 1u:
        return v81;
      case 2u:
        if ( *((_DWORD *)this + 4081) != 3 )
          return v81;
        qmemcpy(this + 16344, a2 + 2, 0x1A2u);
        ConditionalRenderStateUpdate(this);
        *((_DWORD *)this + 4) = 1069547520;
        this[20] = 1;
        if ( BinarySearchInStringTable(byte_5EC4C0, aNextSession, byte_5EC4CC) )
        {
          v10 = 0;
          do
          {
            v11 = aNextSession[v10];
            byte_5EC4CC[v10++] = v11;
          }
          while ( v11 );
        }
        if ( SessionTypeGuard((int)&unk_7CE24D, v9, byte_5EC4CC) )
          Sleep(0x3E8u);
        else
          TextLineWrappingAndRendering(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
        result = 1;
        *((_DWORD *)this + 224) = 1084227584;
        return result;
      case 3u:
        v13 = a2[107];
        *(float *)&v76 = dbl_8AFEA0;
        ProgressBarEventEncode(a2, 4, 4, 420, 255, v76, 1);
        if ( ArrayScanForMatch(this, v13) )
        {
          a2[2] = -1;
          memset32(a2 + 3, -1082130432, 0x68u);
        }
        else
        {
          v14 = ArraySearchFor1Sentinel(this);
          ShortComputation_e5d0(this, v14, v13);
          a2[2] = v14;
          memset32(a2 + 3, -1082130432, 0x68u);
          for ( i = 0; i < dword_5C329C; ++i )
          {
            v16 = dword_7C54F0[i];
            if ( v16 != 0.0 )
              a2[*(_DWORD *)(LODWORD(v16) + 18580) + 3] = *(unsigned int *)(LODWORD(v16) + 16540);
          }
        }
        TextureCreationWrapper(*(void **)this, a2, 2, v13, -1);
        *(float *)&v77 = dbl_8AFEA0;
        ProgressBarEventEncode(a2, 4, 35, 2, 255, v77, 1);
        *((_BYTE *)a2 + 8) = this[112468];
        *((_BYTE *)a2 + 9) = this[112469];
        TextureCreationWrapper(*(void **)this, a2, 2, v13, -1);
        result = 1;
        byte_8AFF00 = 1;
        return result;
      case 4u:
        if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_1, 2461) )
          DebugLogWrite((int)dword_8AD25C, (int)aReceivedServer);
        v17 = MEMORY[0x5F0774];
        v18 = (float *)(a2 + 3);
        do
        {
          v17 += 4656;
          *(v17 - 4656) = *v18++;
        }
        while ( (int)v17 < (int)flt_7C9574 );
        NetComm_SetSelfAsReady(this, a2[2]);
        return 1;
      case 5u:
        if ( !this[32] )
        {
          *((_DWORD *)this + 7) = 1089470464;
          this[32] = 1;
        }
        if ( BinarySearchInStringTable(byte_5EC4C0, aNextTrack, byte_5EC4CC) )
        {
          v20 = 0;
          do
          {
            v21 = aNextTrack[v20];
            byte_5EC4CC[v20++] = v21;
          }
          while ( v21 );
        }
        if ( SessionTypeGuard((int)&unk_7CE24D, v19, byte_5EC4CC) )
          Sleep(0x3E8u);
        else
          TextLineWrappingAndRendering(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
        return 1;
      case 6u:
        v6 = (v3 >> 8) & 0x3FF;
        if ( !v6 )
          return v81;
        *((_BYTE *)a2 + v6 + 8) = 0;
        v88[0] = byte_5EA438[0];
        memset(&v88[1], 0, 0xFCu);
        v89 = 0;
        v90 = 0;
        ThunkToFUN00461480(v86);
        DriverDataCopyByID(*(int **)this, (unsigned __int8)*a2, v86, &v82);
        if ( *((_DWORD *)this + 4081) != 1 )
        {
          StringCopyWithFormatQuery(v87, (const char *)a2 + 8, v88, 256);
          if ( !byte_7CE254 && byte_7D1044 )
            TextLineWrappingAndRendering(&dword_7CD204, (int)v88, 3, 16909060);
          v7 = (_DWORD *)OperatorNewNhMallocWrapper(8);
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
          StringCopyWithBufferRealloc(v8, v88);
          DoublyLinkedListAppend((_DWORD *)this + 28124, v8, 0);
          LinkedListPurgeByThreshold(this);
          v2 = a2;
        }
        v81 = 0;
        v5 = 1;
        EmptyStub_0170();
        goto LABEL_161;
      case 0x20u:
        v22 = *((_DWORD *)this + 4081);
        if ( v22 == 2 || v22 == 1 )
          return v81;
        v23 = a2[2];
        if ( SingleFunctionDispatch(*(void **)this) == v23 )
        {
          if ( BinarySearchInStringTable(byte_5EC4C0, aYouHaveBeenBoo, byte_5EC4CC) )
          {
            v24 = 0;
            do
            {
              v25 = aYouHaveBeenBoo[v24];
              byte_5EC4CC[v24++] = v25;
            }
            while ( v25 );
          }
          v26 = (_DWORD *)OperatorNewNhMallocWrapper(8);
          if ( v26 )
          {
            *v26 = 0;
            v26[1] = -1;
            v27 = (int)v26;
          }
          else
          {
            v27 = 0;
          }
          StringCopyWithBufferRealloc(v27, byte_5EC4CC);
          DoublyLinkedListAppend((_DWORD *)this + 28124, v27, 0);
          TextLineWrappingAndRendering(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
          DualVirtualDispatchWrapper(*((_DWORD **)this + 4078));
          if ( SessionTypeGuard((int)&unk_7CE24D, v28, byte_5EC4CC) )
          {
            Sleep(0x3E8u);
            return 1;
          }
          return v81;
        }
        v29 = NodeIDToPlayerNameLookup(this, v23);
        if ( !strlen(v29) )
          return v81;
        if ( BinarySearchInStringTable(byte_5EC4C0, aWasRemovedFrom, byte_5EC4CC) )
        {
          v30 = 0;
          do
          {
            v31 = aWasRemovedFrom[v30];
            byte_5EC4CC[v30++] = v31;
          }
          while ( v31 );
        }
        StringFormatWithBufferOverflowCheck(v84, (int)"%s %s", v29, byte_5EC4CC);
        TextLineWrappingAndRendering(&dword_7CD204, (int)v84, 3, 16909060);
        return 1;
      case 0x23u:
        this[112488] = *((_BYTE *)a2 + 8);
        this[112489] = *((_BYTE *)a2 + 9);
        ParticleSoundEffectSpawner((unsigned __int8 *)this);
        return 1;
      case 0x24u:
        v32 = 18624 * (unsigned __int8)*a2;
        v33 = 0;
        v34 = (_UNKNOWN *)((char *)&stru_5EC6D8 + v32) == 0;
        v35 = (char *)&stru_5EC6D8 + v32;
        v82 = 0.0;
        if ( v34 )
          goto LABEL_71;
        v36 = ConditionalDispatch_40b0((int)(v35 + 18196));
        if ( !v36 )
          goto LABEL_71;
        v37 = *(const char **)(v36 + 8);
        if ( !v37 )
          v37 = byte_5EA438;
        v38 = &v37[strlen(v37)];
        if ( v38 <= v37 )
          goto LABEL_70;
        while ( *v38 != 92 )
        {
          if ( --v38 <= v37 )
            goto LABEL_70;
        }
        ++v38;
LABEL_70:
        v33 = v38;
        v82 = *(float *)&v38;
LABEL_71:
        if ( TerrainIniParser((unsigned __int8 *)this, (int)a2, v33) )
          return v81;
        for ( j = 0; j < 5; ++j )
        {
          v40 = v39;
          v39 = (char *)j;
          switch ( j )
          {
            case 0:
              v41 = this[112490];
              v42 = 0;
              do
              {
                v43 = byte_5C5D2C[v42];
                v84[v42++] = v43;
              }
              while ( v43 );
              goto LABEL_103;
            case 1:
              v44 = v82;
              v41 = this[112491];
              if ( v82 == 0.0 )
              {
                v84[0] = 0;
              }
              else
              {
                v39 = &v84[-LODWORD(v82)];
                do
                {
                  v45 = *(_BYTE *)LODWORD(v44);
                  v39[LODWORD(v44)++] = *(_BYTE *)LODWORD(v44);
                }
                while ( v45 );
              }
              goto LABEL_103;
            case 2:
              v41 = this[112492];
              v46 = 0;
              do
              {
                v47 = aTerrainIni[v46];
                v84[v46++] = v47;
              }
              while ( v47 );
              goto LABEL_103;
            case 3:
              v48 = (const char *)dword_7CE5D0;
              v41 = this[112493];
              if ( !dword_7CE5D0 )
                v48 = byte_5EA438;
              v49 = (char *)&v48[strlen(v48)];
              if ( v49 <= v48 )
                goto LABEL_92;
              break;
            case 4:
              v53 = (const char *)dword_7D0434;
              v41 = this[112494];
              if ( !dword_7D0434 )
                v53 = byte_5EA438;
              v54 = (const char *)dword_5EC3D8;
              if ( !dword_5EC3D8 )
                v54 = byte_5EA438;
              StringFormatProcessingWithNullTerm(v84, 80, "%s%s", v54, v53);
              v85 = 0;
              goto LABEL_103;
            default:
              v39 = v40;
              continue;
          }
          while ( *v49 != 92 )
          {
            if ( --v49 <= v48 )
              goto LABEL_92;
          }
          ++v49;
LABEL_92:
          sub_587DD0(v84, v49, 0x4Fu);
          v85 = 0;
          v50 = &v84[strlen(v84)];
          if ( v50 > v84 )
          {
            while ( *v50 != 46 )
            {
              --v50;
              v39 = v84;
              if ( v50 <= v84 )
                goto LABEL_97;
            }
            *v50 = 0;
          }
LABEL_97:
          v51 = &v84[strlen(v84) + 1];
          v52 = byte_5C5D28;
          *(_DWORD *)--v51 = dword_5C5D24;
          v51[4] = v52;
LABEL_103:
          if ( !v41 )
          {
            v55 = NodeIDToPlayerNameLookup(this, a2[107]);
            if ( BinarySearchInStringTable(byte_5EC4C0, aMismatch, byte_5EC4CC) )
            {
              v56 = 0;
              do
              {
                v57 = aMismatch[v56];
                byte_5EC4CC[v56++] = v57;
              }
              while ( v57 );
            }
            StringFormatWithBufferOverflowCheck(v86, (int)"%s \"%s\" %s", v55, v84, byte_5EC4CC);
            v58 = (_DWORD *)OperatorNewNhMallocWrapper(8);
            if ( v58 )
            {
              *v58 = 0;
              v58[1] = -1;
              v59 = (int)v58;
            }
            else
            {
              v59 = 0;
            }
            StringCopyWithBufferRealloc(v59, v86);
            if ( v59 )
            {
              v60 = OperatorNewNhMallocWrapper(12);
              if ( v60 )
              {
                *(_DWORD *)v60 = v59;
                *(_DWORD *)(v60 + 4) = 0;
                *(_BYTE *)(v60 + 8) = 0;
              }
              else
              {
                v60 = 0;
              }
              if ( *((_DWORD *)this + 28124) )
              {
                *(_DWORD *)(*((_DWORD *)this + 28125) + 4) = v60;
              }
              else
              {
                *((_DWORD *)this + 28124) = v60;
                *((_DWORD *)this + 28126) = v60;
              }
              *((_DWORD *)this + 28125) = v60;
              ++*((_DWORD *)this + 28127);
            }
            TextLineWrappingAndRendering(&dword_7CD204, (int)v86, 3, 16909060);
            v61 = strlen(v86) + 1;
            v62 = v61 - 1;
            if ( (int)(v61 - 1) >= 0 )
            {
              if ( (int)(v61 - 1) > 159 )
                v62 = 159;
            }
            else
            {
              v62 = 0;
            }
            *(float *)&v78 = dbl_8AFEA0;
            ProgressBarEventEncode(v88, 4, 6, v62, 0, v78, 1);
            sub_587DD0(&v88[8], v86, v62);
            v88[v62 + 8] = 0;
            TextureCreationWrapper(dword_7CD25C, v88, 0, -1, -1);
          }
        }
        return 1;
      case 0x27u:
        if ( !byte_7D10D4 )
          goto LABEL_133;
        v63 = (_BYTE **)*((_DWORD *)this + 4082);
        *((_DWORD *)this + 4084) = v63;
        if ( !v63 )
          goto LABEL_133;
        v64 = *v63;
        if ( !v64 )
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
        v69 = 0;
        if ( *((int *)this + 3973) <= 0 )
          return v81;
        v70 = this + 1040;
        do
        {
          if ( FlagBitTest(v70 - 124, 1)
            && TerrainSurfaceRoughnessHeightSampling((unsigned __int8 *)this + 107456, *v70, &v82, COERCE_FLOAT(1)) )
          {
            j = *((__int16 *)a2 + 4);
            v71 = (double)j * 0.00025000001;
            if ( *((float *)this + 228) < fabs(v71 - v82) || v71 < 0.0 || v82 < 0.0 )
            {
              v74 = *((float *)this + 228);
              this[20] = 1;
              *((_DWORD *)this + 4) = 1065353216;
              *((float *)this + 228) = v74 + 0.025;
            }
            else
            {
              v72 = *((float *)this + 228) * 0.050000001;
              if ( v72 >= 0.00050000002 )
              {
                if ( v72 > 0.0099999998 )
                  v72 = 0.0099999998;
              }
              else
              {
                v72 = 0.00050000002;
              }
              v73 = *((float *)this + 228) - v72;
              *((float *)this + 228) = v73;
              if ( v73 < 0.0099999998 )
                *((_DWORD *)this + 228) = 1008981770;
            }
          }
          ++v69;
          v70 += 140;
        }
        while ( v69 < *((_DWORD *)this + 3973) );
        return 1;
      default:
        goto LABEL_160;
    }
    do
    {
      if ( !sub_588410(v64, (_BYTE *)a2 + 8) )
      {
        *(float *)&v80 = dbl_8AFEA0;
        ProgressBarEventEncode(v88, 4, 41, 0, 255, v80, 1);
        goto LABEL_141;
      }
      v65 = *((_DWORD *)this + 4084);
      if ( v65 )
        *((_DWORD *)this + 4084) = *(_DWORD *)(v65 + 4);
      v66 = (_BYTE **)*((_DWORD *)this + 4084);
      if ( !v66 )
        break;
      v64 = *v66;
    }
    while ( v64 );
LABEL_133:
    v67 = (_BYTE *)OperatorNewNhMallocWrapper(128);
    sub_587DD0(v67, (char *)a2 + 8, 0x7Fu);
    v67[127] = 0;
    v68 = OperatorNewNhMallocWrapper(12);
    if ( v68 )
    {
      *(_DWORD *)v68 = v67;
      *(_DWORD *)(v68 + 4) = 0;
      *(_BYTE *)(v68 + 8) = 1;
    }
    else
    {
      v68 = 0;
    }
    if ( *((_DWORD *)this + 4082) )
    {
      *(_DWORD *)(*((_DWORD *)this + 4083) + 4) = v68;
    }
    else
    {
      *((_DWORD *)this + 4082) = v68;
      *((_DWORD *)this + 4084) = v68;
    }
    *((_DWORD *)this + 4083) = v68;
    ++*((_DWORD *)this + 4085);
    *(float *)&v79 = dbl_8AFEA0;
    ProgressBarEventEncode(v88, 4, 40, 0, 255, v79, 1);
LABEL_141:
    TextureCreationWrapper(*(void **)this, v88, 2, a2[107], -1);
    return 1;
  }
  else
  {
LABEL_160:
    v81 = 0;
LABEL_161:
    if ( !this[32] )
    {
      if ( (*v2 & 0x8000000) != 0 )
        v5 = 1;
      if ( (*((_BYTE *)v2 + 3) & 7) == dword_7C56A4 || v5 )
      {
        v75 = (_DWORD *)dword_83EE54;
        if ( dword_7D2E50 < 1023 )
        {
          ++dword_7D2E50;
          dword_83EE54 += 432;
        }
        ArithmeticComparison_3a90(v75, v2);
        return 1;
      }
    }
    return v81;
  }
}

