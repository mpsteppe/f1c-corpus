int *__thiscall sub_465460(int **this, int a2, int a3)
{
  _DWORD *v4; // esi
  _DWORD *v5; // edi
  void *v6; // ecx
  int v7; // eax
  int v8; // edi
  int *v9; // esi
  int v10; // eax
  _DWORD **v11; // ecx
  _DWORD *v12; // ebp
  _DWORD *v13; // esi
  int v14; // eax
  int v15; // ecx
  int v16; // ecx
  int v17; // eax
  _DWORD **v18; // eax
  int v19; // edx
  _DWORD *v20; // edi
  _DWORD *v21; // esi
  void *v22; // ebp
  int v23; // ecx
  int v24; // eax
  int v25; // ebp
  int *v26; // esi
  int v27; // edi
  int v28; // eax
  int v29; // edx
  float **v30; // ecx
  float *v31; // ecx
  float *v32; // esi
  int v33; // ecx
  int v34; // eax
  float **v35; // eax
  _DWORD *v36; // esi
  int v37; // eax
  int v38; // ecx
  int i; // edx
  int *v40; // ecx
  int v41; // eax
  int v42; // edx
  int v43; // ecx
  int v44; // eax
  int *v45; // eax
  int v46; // eax
  int *v47; // ecx
  bool v48; // zf
  int v49; // edi
  _DWORD *v50; // esi
  int v51; // eax
  int v52; // ecx
  int v53; // eax
  int *v54; // eax
  _DWORD *v55; // eax
  int j; // ecx
  int v57; // eax
  _BYTE ***v58; // ecx
  _BYTE **v59; // ebp
  int v60; // ecx
  int v61; // eax
  _BYTE ***v62; // eax
  int v63; // edi
  _DWORD *v64; // esi
  int v65; // eax
  _DWORD *v66; // eax
  _DWORD *v67; // esi
  _DWORD *v68; // edi
  _DWORD *v69; // esi
  int v70; // eax
  int v71; // ecx
  int v72; // eax
  _BYTE ***v73; // eax
  _DWORD **v74; // eax
  _DWORD *v75; // edi
  _DWORD *v76; // esi
  int v77; // eax
  LPVOID *v78; // esi
  LPVOID *v79; // edi
  char v80; // al
  int *result; // eax
  float v82; // [esp+0h] [ebp-44h]
  int v83; // [esp+18h] [ebp-2Ch]
  float v84; // [esp+1Ch] [ebp-28h]
  int v85; // [esp+20h] [ebp-24h]
  _DWORD *v86; // [esp+20h] [ebp-24h]
  int v87; // [esp+24h] [ebp-20h]
  int v88; // [esp+24h] [ebp-20h]
  int v89; // [esp+24h] [ebp-20h]
  int v90; // [esp+28h] [ebp-1Ch]
  void *v91; // [esp+2Ch] [ebp-18h]
  float v92; // [esp+2Ch] [ebp-18h]
  int v93; // [esp+30h] [ebp-14h]
  int v94; // [esp+34h] [ebp-10h]
  _DWORD *v95; // [esp+34h] [ebp-10h]
  int v96; // [esp+38h] [ebp-Ch]
  _DWORD *v97; // [esp+3Ch] [ebp-8h]
  int v98; // [esp+40h] [ebp-4h]

  v4 = *this + 14704;
  v5 = (_DWORD *)*v4;
  if ( *v4 )
  {
    do
    {
      v6 = v5;
      v5 = (_DWORD *)v5[1];
      v91 = v6;
      ConditionalFreeByFlagCheck(v6);
      FreeWrapper_7bcf(v91);
    }
    while ( v5 );
  }
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  v7 = DivisionWithCapComputation(*this, a2);
  v8 = 140 * a2;
  v9 = *this;
  v87 = v7;
  v90 = v8 * 4;
  v92 = (float)v7;
  v10 = LOWORD(v9[140 * a2 + 173]) + CRTFtol(*((float *)v9 + 25) * *((float *)v9 + 24) * v92);
  LOWORD(v9[v8 + 173]) = 0;
  v83 = v10;
  v11 = (_DWORD **)(*this)[27];
  (*this)[29] = (int)v11;
  if ( v11 )
  {
    v12 = *v11;
    if ( *v11 )
    {
      do
      {
        if ( v12[107] != a3 )
        {
          v13 = *this + 14704;
          v14 = OperatorNewNhMallocWrapper(12);
          if ( v14 )
          {
            *(_DWORD *)v14 = v12;
            *(_DWORD *)(v14 + 4) = 0;
            *(_BYTE *)(v14 + 8) = 0;
          }
          else
          {
            v14 = 0;
          }
          if ( *v13 )
          {
            *(_DWORD *)(v13[1] + 4) = v14;
          }
          else
          {
            *v13 = v14;
            v13[2] = v14;
          }
          v15 = v13[3] + 1;
          v13[1] = v14;
          v13[3] = v15;
          v83 += -8 - ((*v12 >> 8) & 0x3FF);
        }
        v16 = (*this)[29];
        v17 = (int)(*this + 27);
        if ( v16 )
          (*this)[29] = *(_DWORD *)(v16 + 4);
        v18 = *(_DWORD ***)(v17 + 8);
        if ( !v18 )
          break;
        v12 = *v18;
      }
      while ( *v18 );
    }
  }
  switch ( ThresholdToRankClassifier(v87) )
  {
    case 1:
      v84 = 0.125;
      break;
    case 2:
      v84 = 0.083333336;
      break;
    case 3:
      v84 = 0.0625;
      break;
    case 4:
      v84 = 0.015625;
      break;
    default:
      v84 = 0.16666667;
      break;
  }
  v82 = dbl_8AFE90;
  if ( UtilityFunction_4bb0((float *)(v8 * 4 + v19 + 140), v82, v84) && v83 > 0 )
  {
    FloatFieldDecrementWithClamp((float *)&(*this)[v8 + 35], v84);
    v93 = v83 / 60;
    if ( v83 / 60 > 0 )
    {
      v20 = (_DWORD *)(*this)[14700];
      v21 = *this + 14700;
      while ( v20 )
      {
        v22 = v20;
        v20 = (_DWORD *)v20[1];
        ConditionalFreeByFlagCheck(v22);
        FreeWrapper_7bcf(v22);
      }
      v23 = a2;
      v24 = 0;
      *v21 = 0;
      v21[1] = 0;
      v21[2] = 0;
      v21[3] = 0;
      v85 = 0;
      v88 = 0;
      v25 = 14596;
      do
      {
        (*this)[v25] = -1;
        v26 = *this;
        if ( *((_BYTE *)*this + v24 + 248) )
        {
          if ( v85 != v23 )
          {
            v27 = *(int *)((char *)v26 + v24 + 696);
            if ( v27 )
            {
              v28 = OperatorNewNhMallocWrapper(12);
              if ( v28 )
              {
                *(_DWORD *)v28 = v27;
                *(_DWORD *)(v28 + 4) = 0;
                *(_BYTE *)(v28 + 8) = 0;
              }
              else
              {
                v28 = 0;
              }
              if ( v26[14700] )
              {
                *(_DWORD *)(v26[14701] + 4) = v28;
              }
              else
              {
                v26[14700] = v28;
                v26[14702] = v28;
              }
              v23 = a2;
              v26[14701] = v28;
              ++v26[14703];
              v24 = v88;
            }
          }
        }
        ++v25;
        v24 += 560;
        ++v85;
        v88 = v24;
      }
      while ( v25 < 14700 );
      v29 = MEMORY[0x5F0F88][9312 * v23];
      if ( MEMORY[0x5EF9A0][4656 * v29] == -1 )
        v29 = v23;
      v30 = (float **)(*this)[14700];
      (*this)[14702] = (int)v30;
      if ( v30 )
      {
        v31 = *v30;
        if ( v31 )
        {
          v32 = (float *)((char *)&stru_5EC6D8 + 18624 * v29);
          do
          {
            ShortComputation_4990(v31, v32);
            v33 = (*this)[14702];
            v34 = (int)(*this + 14700);
            if ( v33 )
              (*this)[14702] = *(_DWORD *)(v33 + 4);
            v35 = *(float ***)(v34 + 8);
            if ( !v35 )
              break;
            v31 = *v35;
          }
          while ( *v35 );
        }
      }
      v36 = *this + 14700;
      v37 = MergeSortOnLinkedList(*v36);
      v38 = v37;
      *v36 = v37;
      if ( v37 )
      {
        for ( i = *(_DWORD *)(v37 + 4); i; i = *(_DWORD *)(i + 4) )
          v38 = i;
      }
      v36[2] = v37;
      v36[1] = v38;
      v40 = (int *)(*this)[14700];
      (*this)[14702] = (int)v40;
      if ( v40 )
        v41 = *v40;
      else
        v41 = 0;
      if ( v41 )
      {
        v42 = 14596;
        do
        {
          (*this)[v42] = (unsigned __int8)*(_DWORD *)(*(_DWORD *)v41 + 109);
          v43 = (*this)[14702];
          v44 = (int)(*this + 14700);
          ++v42;
          if ( v43 )
            (*this)[14702] = *(_DWORD *)(v43 + 4);
          v45 = *(int **)(v44 + 8);
          if ( !v45 )
            break;
          v41 = *v45;
        }
        while ( v41 );
      }
      dword_7CD2AC = (int)*this;
      v46 = (int)(*this + 31);
      v94 = 0;
      v96 = 0;
      v98 = 0;
      v47 = *(int **)v46;
      v48 = *(_DWORD *)v46 == 0;
      *(_DWORD *)(v46 + 8) = *(_DWORD *)v46;
      if ( !v48 )
      {
        v49 = *v47;
        if ( *v47 )
        {
          do
          {
            if ( *(_DWORD *)(v49 + 428) != a3 )
            {
              v50 = (_DWORD *)OperatorNewNhMallocWrapper(4);
              *v50 = v49;
              v51 = OperatorNewNhMallocWrapper(12);
              if ( v51 )
              {
                *(_DWORD *)v51 = v50;
                *(_DWORD *)(v51 + 4) = 0;
                *(_BYTE *)(v51 + 8) = 1;
              }
              else
              {
                v51 = 0;
              }
              if ( v94 )
                *(_DWORD *)(v96 + 4) = v51;
              else
                v94 = v51;
              v96 = v51;
              ++v98;
            }
            v52 = (*this)[33];
            v53 = (int)(*this + 31);
            if ( v52 )
              (*this)[33] = *(_DWORD *)(v52 + 4);
            v54 = *(int **)(v53 + 8);
            if ( !v54 )
              break;
            v49 = *v54;
          }
          while ( *v54 );
        }
      }
      v55 = (_DWORD *)sub_465D70(v94);
      v95 = v55;
      if ( v55 )
      {
        for ( j = v55[1]; j; j = *(_DWORD *)(j + 4) )
          ;
      }
      v57 = v83 / 60;
      if ( v93 > 1 )
        v57 = v93 / 2;
      v89 = v57;
      v58 = (_BYTE ***)(*this)[14700];
      (*this)[14702] = (int)v58;
      if ( v58 )
        v59 = *v58;
      else
        v59 = 0;
      v97 = v95;
      if ( v95 )
        v86 = (_DWORD *)*v95;
      else
        v86 = 0;
      do
      {
        if ( v59 )
        {
          while ( !(*v59)[108] || !CharacterRangeCheckWithSignFlag(*v59, a2, *((unsigned __int8 *)*this + v90 + 694)) )
          {
            v60 = (*this)[14702];
            v61 = (int)(*this + 14700);
            if ( v60 )
              (*this)[14702] = *(_DWORD *)(v60 + 4);
            v62 = *(_BYTE ****)(v61 + 8);
            if ( !v62 )
              goto LABEL_118;
            v59 = *v62;
            if ( !*v62 )
              goto LABEL_119;
          }
          DispatchWrapper(*v59, a2);
          if ( *(_DWORD *)(*v59 + 537) != a3 )
          {
            if ( --v89 < 0 )
            {
              v66 = (_DWORD *)OperatorNewNhMallocWrapper(432);
              v67 = *v59 + 109;
              v68 = v66;
              ProgressBarEventEncode(1, 7, 19, (unsigned __int8)*v67, *(float *)(*v59 + 113), 0);
              VectorToShort3Conversion(v67 + 2);
              v69 = *this + 14704;
              if ( v68 )
              {
                v70 = OperatorNewNhMallocWrapper(12);
                if ( v70 )
                {
                  *(_DWORD *)v70 = v68;
                  *(_DWORD *)(v70 + 4) = 0;
                  *(_BYTE *)(v70 + 8) = 1;
                }
                else
                {
                  v70 = 0;
                }
                if ( *v69 )
                {
                  *(_DWORD *)(v69[1] + 4) = v70;
                }
                else
                {
                  *v69 = v70;
                  v69[2] = v70;
                }
                v69[1] = v70;
                ++v69[3];
              }
              v83 += -8 - ((*v68 >> 8) & 0x3FF);
            }
            else
            {
              v63 = (int)(*v59 + 109);
              v64 = *this + 14704;
              if ( *v59 != (_BYTE *)-109 )
              {
                v65 = OperatorNewNhMallocWrapper(12);
                if ( v65 )
                {
                  *(_DWORD *)v65 = v63;
                  *(_DWORD *)(v65 + 4) = 0;
                  *(_BYTE *)(v65 + 8) = 0;
                }
                else
                {
                  v65 = 0;
                }
                if ( *v64 )
                {
                  *(_DWORD *)(v64[1] + 4) = v65;
                }
                else
                {
                  *v64 = v65;
                  v64[2] = v65;
                }
                v64[1] = v65;
                ++v64[3];
              }
              v83 -= 60;
            }
          }
          v71 = (*this)[14702];
          v72 = (int)(*this + 14700);
          if ( v71 )
            (*this)[14702] = *(_DWORD *)(v71 + 4);
          v73 = *(_BYTE ****)(v72 + 8);
          if ( v73 )
          {
            v59 = *v73;
            goto LABEL_119;
          }
LABEL_118:
          v59 = 0;
        }
LABEL_119:
        if ( v83 <= 0 )
          break;
        v74 = (_DWORD **)v86;
        if ( v86 )
        {
          v75 = (_DWORD *)*v86;
          v76 = *this + 14704;
          if ( *v86 )
          {
            v77 = OperatorNewNhMallocWrapper(12);
            if ( v77 )
            {
              *(_DWORD *)v77 = v75;
              *(_DWORD *)(v77 + 4) = 0;
              *(_BYTE *)(v77 + 8) = 0;
            }
            else
            {
              v77 = 0;
            }
            if ( *v76 )
            {
              *(_DWORD *)(v76[1] + 4) = v77;
            }
            else
            {
              *v76 = v77;
              v76[2] = v77;
            }
            v76[1] = v77;
            ++v76[3];
            v74 = (_DWORD **)v86;
          }
          v83 += -8 - ((**v74 >> 8) & 0x3FF);
          if ( v97 && (v97 = (_DWORD *)v97[1]) != 0 )
            v86 = (_DWORD *)*v97;
          else
            v86 = 0;
        }
        else if ( !v59 )
        {
          break;
        }
      }
      while ( v83 > 0 );
      v78 = (LPVOID *)v95;
      if ( v95 )
      {
        do
        {
          v79 = v78;
          v80 = *((_BYTE *)v78 + 8);
          v78 = (LPVOID *)v78[1];
          if ( v80 )
            FreeWrapper_7bcf(*v79);
          FreeWrapper_7bcf(v79);
        }
        while ( v78 );
      }
    }
  }
  result = *this + 14704;
  (*this)[14706] = *result;
  if ( v83 > 0 )
  {
    result = (int *)CRTFtol(v92 * v84);
    if ( (int)result >= v83 )
      result = (int *)v83;
    *(_WORD *)((char *)*this + v90 + 692) = (_WORD)result;
  }
  return result;
}

