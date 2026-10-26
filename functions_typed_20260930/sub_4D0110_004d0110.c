int __thiscall sub_4D0110(int *this)
{
  int v2; // esi
  int *v3; // eax
  _DWORD *v4; // ebp
  int v5; // eax
  _DWORD *v6; // esi
  int v7; // edi
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // edi
  __int16 v11; // si
  const char *v12; // ecx
  int v13; // ebp
  char *v14; // eax
  char *v15; // edi
  char v16; // cl
  const char *v17; // ecx
  char *v18; // eax
  void *v19; // eax
  char *v20; // edi
  const char *v21; // ecx
  const char *v22; // eax
  int result; // eax
  const char *v24; // ecx
  const char *v25; // eax
  bool v26; // cc
  int v27; // ebx
  int v28; // esi
  int v29; // ecx
  int v30; // edx
  const char *v31; // eax
  double v32; // st7
  double v33; // st6
  double v34; // st7
  double v35; // st6
  double v36; // st7
  int v37; // ecx
  char v38; // al
  const char *v39; // ecx
  char *v40; // eax
  int v41; // ebp
  double v42; // st7
  int v43; // eax
  double v44; // st7
  int v45; // edi
  CHAR *v46; // edi
  char v47; // cl
  int *v48; // ebx
  int v49; // esi
  int v50; // edi
  int v51; // [esp+0h] [ebp-37Ch]
  int v52; // [esp+10h] [ebp-36Ch]
  float v53; // [esp+10h] [ebp-36Ch]
  int v54; // [esp+24h] [ebp-358h] BYREF
  float v55; // [esp+28h] [ebp-354h]
  int v56; // [esp+2Ch] [ebp-350h]
  int *v57; // [esp+30h] [ebp-34Ch]
  int v58; // [esp+34h] [ebp-348h]
  int v59; // [esp+38h] [ebp-344h]
  int v60; // [esp+3Ch] [ebp-340h] BYREF
  char *v61; // [esp+40h] [ebp-33Ch]
  int v62; // [esp+44h] [ebp-338h]
  float v63; // [esp+48h] [ebp-334h] BYREF
  float v64; // [esp+4Ch] [ebp-330h]
  float v65; // [esp+50h] [ebp-32Ch]
  int v66; // [esp+54h] [ebp-328h] BYREF
  int v67; // [esp+58h] [ebp-324h] BYREF
  int v68; // [esp+5Ch] [ebp-320h] BYREF
  float v69; // [esp+60h] [ebp-31Ch] BYREF
  float v70; // [esp+64h] [ebp-318h]
  float v71; // [esp+68h] [ebp-314h]
  float v72; // [esp+6Ch] [ebp-310h]
  float v73; // [esp+70h] [ebp-30Ch]
  float v74; // [esp+74h] [ebp-308h]
  float v75; // [esp+78h] [ebp-304h]
  float v76; // [esp+7Ch] [ebp-300h]
  float v77; // [esp+80h] [ebp-2FCh]
  _DWORD v78[3]; // [esp+84h] [ebp-2F8h] BYREF
  float v79; // [esp+90h] [ebp-2ECh]
  float v80; // [esp+94h] [ebp-2E8h]
  double v81[3]; // [esp+9Ch] [ebp-2E0h] BYREF
  int v82; // [esp+B4h] [ebp-2C8h]
  int v83; // [esp+B8h] [ebp-2C4h]
  int v84; // [esp+BCh] [ebp-2C0h]
  int v85; // [esp+C0h] [ebp-2BCh]
  double v86; // [esp+C4h] [ebp-2B8h]
  int v87; // [esp+CCh] [ebp-2B0h]
  CHAR SrcStr[32]; // [esp+D0h] [ebp-2ACh] BYREF
  char v89[16]; // [esp+F0h] [ebp-28Ch] BYREF
  float v90; // [esp+104h] [ebp-278h]
  char v91[36]; // [esp+10Ch] [ebp-270h] BYREF
  char v92[12]; // [esp+130h] [ebp-24Ch] BYREF
  char v93[256]; // [esp+13Ch] [ebp-240h] BYREF
  _BYTE v94[32]; // [esp+23Ch] [ebp-140h] BYREF
  _BYTE v95[32]; // [esp+25Ch] [ebp-120h] BYREF
  char v96[256]; // [esp+27Ch] [ebp-100h] BYREF

  v2 = dword_5C329C;
  v52 = 132 * dword_5C329C + 4;
  v57 = this;
  *this = dword_5C329C;
  v3 = (int *)OperatorNewNhMallocWrapper(v52);
  if ( v3 )
  {
    *v3 = v2;
    v4 = v3 + 1;
    v5 = v2 - 1;
    if ( v2 - 1 >= 0 )
    {
      v6 = v4 + 1;
      v7 = v5 + 1;
      do
      {
        F_3FieldInitCall_0b00(v6);
        v6 += 33;
        --v7;
      }
      while ( v7 );
    }
    v8 = v4;
  }
  else
  {
    v8 = 0;
  }
  this[1] = (int)v8;
  v9 = 0;
  if ( *this > 0 )
  {
    v10 = 0;
    do
    {
      v11 = 1;
      if ( !((*(_DWORD *)(dword_7C54F0[v9] + 16472) - 1) % 3) || v9 == dword_7C54E4 )
        v11 = 0;
      *(_WORD *)(v10 + this[1] + 4) = v11;
      ++v9;
      v10 += 132;
    }
    while ( v9 < *this );
  }
  v12 = (const char *)dword_7CE5D0;
  v13 = 0;
  v68 = 0;
  if ( !dword_7CE5D0 )
    v12 = byte_5EA438;
  strcpy(v93, v12);
  v14 = &v93[strlen(v93)];
  if ( v14 > v93 )
  {
    while ( *v14 != 46 )
    {
      if ( --v14 <= v93 )
        goto LABEL_20;
    }
    *v14 = 0;
  }
LABEL_20:
  v15 = &v93[strlen(v93) + 1];
  v16 = byte_5C4490;
  *(_DWORD *)--v15 = dword_5C448C;
  v15[4] = v16;
  if ( sub_53CBC0(&v68, v93) && dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_3, 205) )
    DebugLogWrite(&dword_8AD25C, aCouldNotLoadS);
  v17 = (const char *)dword_7CE5D0;
  v66 = 0;
  if ( !dword_7CE5D0 )
    v17 = byte_5EA438;
  strcpy(v93, v17);
  v18 = &v93[strlen(v93)];
  if ( v18 > v93 )
  {
    while ( *v18 != 46 )
    {
      if ( --v18 <= v93 )
        goto LABEL_31;
    }
    *v18 = 0;
  }
LABEL_31:
  v19 = off_5D3B54;
  v20 = &v93[strlen(v93)];
  *(_DWORD *)v20 = dword_5D3B50;
  *((_DWORD *)v20 + 1) = v19;
  if ( sub_53CBC0(&v66, v93) && dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_3, 212) )
    DebugLogWrite(&dword_8AD25C, aCouldNotLoadS);
  v21 = (const char *)dword_5EC428;
  v60 = 0;
  if ( !dword_5EC428 )
    v21 = byte_5EA438;
  v22 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v22 = byte_5EA438;
  StringFormatWithBufferOverflowCheck(v93, "%s%s%s", v22, v21, aCdbMas);
  result = sub_53CBC0(&v60, v93);
  if ( result )
  {
    if ( dword_7C569C != 5 )
    {
      result = StringSplitLoop(1, aDDevF119992002_3, 219);
      if ( (_BYTE)result )
        return DebugLogWrite(&dword_8AD25C, aCouldNotLoadCd);
    }
  }
  else
  {
    v24 = (const char *)dword_5EC428;
    v67 = 0;
    if ( !dword_5EC428 )
      v24 = byte_5EA438;
    v25 = (const char *)dword_5EC3D8;
    if ( !dword_5EC3D8 )
      v25 = byte_5EA438;
    StringFormatWithBufferOverflowCheck(v93, "%s%s%s", v25, v24, aCmapsMas);
    if ( sub_53CBC0(&v67, v93) )
    {
      result = PhysicsObjectLinkedListRemoval(v60);
      if ( dword_7C569C != 5 )
      {
        result = StringSplitLoop(1, aDDevF119992002_3, 228);
        if ( (_BYTE)result )
          return DebugLogWrite(&dword_8AD25C, aCouldNotLoadCm);
      }
    }
    else
    {
      v26 = *this <= 0;
      v58 = 0;
      if ( !v26 )
      {
        v59 = 0;
        do
        {
          v27 = dword_7C54F0[v13];
          v28 = v59 + v57[1];
          v91[0] = 0;
          StringFormatWithBufferOverflowCheck(v91, "GridModel%02d", v13);
          v30 = RandLCGRandomNumberGenerator(v29) % 3;
          if ( v30 )
          {
            v31 = aGridgirlbMts;
            if ( v30 != 1 )
              v31 = aGridgirlcMts;
          }
          else
          {
            v31 = aGridgirlaMts;
          }
          StringCopyWithReverse((__int16 *)(v28 + 4), v91, v31, 0, 0);
          SingleFunctionDispatch_10e0(v27, &v54, &v63);
          EulerToRotationMatrix(&v63, &v69);
          v32 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
          v33 = v32;
          v34 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.25;
          v35 = v33 * 0.25 - 1.25;
          v79 = v34 * v69 + v71 * v35 + v70 * 0.0;
          v80 = v74 * v35 + v72 * v34 + v73 * 0.0;
          *(float *)&v54 = v79 + *(float *)&v54;
          v55 = v80 + v55;
          *(float *)&v56 = v77 * v35 + v75 * v34 + v76 * 0.0 + *(float *)&v56;
          if ( *(_DWORD *)(v28 + 104) )
          {
            BoundingBoxComputation(v92);
            v81[0] = *(float *)&v54;
            v81[1] = v55;
            v81[2] = *(float *)&v56;
            v82 = 0;
            v83 = 1075838976;
            v84 = 0x40000000;
            v85 = 1201543096;
            v87 = 0;
            if ( SpatialGridQuery(dbl_7C9360, (int)v81) )
              v55 = v86 - v90;
          }
          v36 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.1;
          *(float *)&v78[1] = v36;
          v78[0] = 0;
          v78[2] = 0;
          sub_567120(v78, &v63);
          v63 = 0.0;
          v65 = 0.0;
          v64 = -atan2(v76 * 0.0 + v77 * 0.0 + v75, v70 * 0.0 + v71 * 0.0 + v69);
          v55 = v55 - 1.02;
          Vec3CopyToStruct((_DWORD *)(v28 + 4), &v54, &v63);
          v61 = 0;
          v62 = -1;
          v55 = v55 - -1.02;
          v38 = RandLCGRandomNumberGenerator(v37);
          v39 = aGirla;
          if ( (v38 & 1) == 0 )
            v39 = aGirlb;
          strcpy(v89, v39);
          StringCopyWithBufferRealloc(byte_5EA438);
          StringCopyWithBufferRealloc(v89);
          sub_5665B0(aAnm);
          v40 = v61;
          if ( !v61 )
            v40 = byte_5EA438;
          sub_4A22D0((_DWORD *)(v28 + 4), (int)v89, (int)v40, 0, 0);
          if ( *(int *)(v28 + 116) > 0 )
          {
            v41 = *(_DWORD *)(v28 + 120);
            v42 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.2;
            v53 = (v42 + 1.0) * *(float *)(v41 + 16);
            RangeProportionInitializer((float *)v41, 0.0, v53);
            v43 = *(_DWORD *)(v41 + 4);
            v13 = v58;
            *(_DWORD *)(v28 + 124) = v43;
            v44 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
            *(float *)(v28 + 128) = v44 * *(float *)(v28 + 124);
          }
          StringFormatWithBufferOverflowCheck(v95, "GridSign%02d", v13);
          *(_DWORD *)v28 = 0;
          if ( *(_DWORD *)(v28 + 104) )
          {
            MeshResourceAllocator(v28, v95, aGgirlsignMts, 16);
            if ( *(_DWORD *)v28 )
            {
              v45 = LinkedListIndexedAccessor_c230(0);
              *(float *)&v51 = v55 + 0.2;
              sub_54B4D0(v54, v51, v56, v63, v64, v65);
              ActorNodeLinkedListAppend(*(_DWORD *)v28);
              if ( v45 )
                LinkedListNodeInsert_5930(v45, 0);
              StringFormatWithBufferOverflowCheck(v94, "%s.BMP", (const char *)(v27 + 18184));
              TextureAdjuster(v94, aWcnumberBmp, 0, 1, 0);
              sub_587DD0(SrcStr, v27 + 18016, 31);
              SrcStr[31] = 0;
              sub_589901(SrcStr);
              if ( strlen(SrcStr) < 0x1B )
              {
                v46 = &SrcStr[strlen(SrcStr) + 1];
                v47 = byte_5CC7A0;
                *(_DWORD *)--v46 = dword_5CC79C;
                v46[4] = v47;
              }
              TextureAdjuster(SrcStr, aWcflagBmp, 0, 1, 0);
            }
          }
          if ( VertexBufferResourceAllocation(dword_8AFE88) )
          {
            StringRelocationCopy(0, v96);
            if ( dword_7C569C != 5 )
            {
              if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_3, 368) )
                DebugLogWrite(&dword_8AD25C, aUnableToSetupS);
            }
          }
          if ( v61 )
            FreeWrapper_7bcf(v61);
          v26 = ++v13 < *v57;
          v58 = v13;
          v59 += 132;
        }
        while ( v26 );
      }
      PhysicsObjectLinkedListRemoval(v68);
      PhysicsObjectLinkedListRemoval(v66);
      PhysicsObjectLinkedListRemoval(v60);
      PhysicsObjectLinkedListRemoval(v67);
      v48 = v57;
      result = *v57;
      v49 = 0;
      if ( *v57 > 0 )
      {
        v50 = 0;
        do
        {
          ConditionalDispatch_27d0(v50 + v48[1] + 4);
          result = *v48;
          ++v49;
          v50 += 132;
        }
        while ( v49 < *v48 );
      }
    }
  }
  return result;
}

