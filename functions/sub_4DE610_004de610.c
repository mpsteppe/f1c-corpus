_DWORD *__thiscall sub_4DE610(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  int v4; // esi
  int *v5; // eax
  _DWORD *v6; // edx
  _DWORD *v7; // eax
  int v8; // ecx
  _DWORD *v9; // eax
  int v10; // eax
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // ebp
  int v14; // eax
  int v15; // ecx
  double v16; // st7
  double v17; // st6
  int v18; // ecx
  double v19; // st7
  double v20; // st6
  int v21; // edi
  int v22; // edx
  unsigned __int8 v24; // c0
  unsigned __int8 v25; // c2
  int v26; // edi
  int i; // esi
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  int v32; // esi
  int v33; // ecx
  int v34; // esi
  int v35; // ebx
  float *v36; // esi
  int v37; // ecx
  unsigned __int8 v39; // c0
  unsigned __int8 v40; // c2
  int v41; // ebp
  int *v42; // ebx
  int v43; // edi
  float *v44; // eax
  bool v45; // zf
  bool v46; // cc
  int v47; // esi
  _DWORD *v48; // eax
  _DWORD *v49; // edx
  _DWORD *v50; // eax
  int v51; // ecx
  _DWORD *result; // eax
  _DWORD *v53; // ebx
  float *v54; // ebp
  int v55; // eax
  int v56; // edx
  int v57; // eax
  int v58; // edx
  int v59; // edi
  int v60; // esi
  unsigned __int8 v62; // c0
  unsigned __int8 v63; // c2
  float *v64; // [esp-8h] [ebp-70h]
  int v66; // [esp+14h] [ebp-54h]
  float v67; // [esp+14h] [ebp-54h]
  int v68; // [esp+14h] [ebp-54h]
  int j; // [esp+14h] [ebp-54h]
  _DWORD *v70; // [esp+18h] [ebp-50h]
  int v71; // [esp+18h] [ebp-50h]
  int v72; // [esp+1Ch] [ebp-4Ch]
  int v73; // [esp+1Ch] [ebp-4Ch]
  int v74; // [esp+1Ch] [ebp-4Ch]
  int v75; // [esp+20h] [ebp-48h]
  int v76; // [esp+20h] [ebp-48h]
  int v77; // [esp+24h] [ebp-44h]
  int v78; // [esp+24h] [ebp-44h]
  float v79; // [esp+28h] [ebp-40h]
  int v80; // [esp+28h] [ebp-40h]
  int v81; // [esp+2Ch] [ebp-3Ch]
  int v82; // [esp+2Ch] [ebp-3Ch]
  float *v83; // [esp+34h] [ebp-34h]
  float *v84; // [esp+44h] [ebp-24h]
  float *v85; // [esp+48h] [ebp-20h]
  float *v86; // [esp+4Ch] [ebp-1Ch]
  float v87; // [esp+50h] [ebp-18h] BYREF
  float v88; // [esp+54h] [ebp-14h]
  float v89; // [esp+58h] [ebp-10h]
  float v90[3]; // [esp+5Ch] [ebp-Ch] BYREF
  int v91; // [esp+70h] [ebp+8h]
  int v92; // [esp+70h] [ebp+8h]

  this[1] = a3;
  v4 = SceneGraphChildCount(*a3);
  this[2] = v4;
  v5 = (int *)OperatorNewNhMallocWrapper(12 * v4 + 4);
  if ( v5 )
  {
    v6 = v5 + 1;
    *v5 = v4;
    v7 = v5 + 1;
    if ( v4 - 1 >= 0 )
    {
      v8 = v4;
      do
      {
        *v7 = 0;
        v7[1] = 0;
        v7[2] = 0;
        v7 += 3;
        --v8;
      }
      while ( v8 );
    }
    v9 = v6;
  }
  else
  {
    v9 = 0;
  }
  this[3] = v9;
  v91 = 0;
  if ( (int)this[2] > 0 )
  {
    v75 = 0;
    do
    {
      v10 = LinkedListIndexedAccessor_c230(v91);
      v11 = (_DWORD *)(v75 + this[3]);
      v70 = v11;
      *v11 = v10;
      v12 = PackedArrayTotalSize(v10);
      v11[1] = v12;
      v11[2] = OperatorNewNhMallocWrapper(v12 << 6);
      v13 = 0;
      v77 = 0;
      if ( (int)v11[1] > 0 )
      {
        v66 = 0;
        do
        {
          v14 = PackedArrayIndexLookup(v13);
          v15 = v11[2];
          *(_DWORD *)(v15 + v66) = v14;
          v16 = *(float *)(v14 + 8);
          v17 = *(float *)(v14 + 4);
          v18 = v66 + v15;
          v72 = 0;
          *(float *)(v18 + 4) = *(float *)v14;
          *(float *)(v18 + 8) = v17;
          *(float *)(v18 + 12) = v16;
          v19 = *(float *)(v14 + 20);
          v20 = *(float *)(v14 + 16);
          *(float *)(v18 + 20) = *(float *)(v14 + 12);
          *(float *)(v18 + 24) = v20;
          *(float *)(v18 + 28) = v19;
          *(_DWORD *)(v18 + 32) = *(_DWORD *)(v14 + 24);
          *(_DWORD *)(v18 + 16) = *a2;
          if ( (int)a2[1] > 0 )
          {
            v21 = 0;
            do
            {
              v22 = v21 + a2[2];
              if ( v24 | v25 && *(float *)(v18 + 16) > (double)*(float *)(v22 + 16) )
                *(_DWORD *)(v18 + 16) = *(_DWORD *)(v22 + 16);
              v21 += 20;
              ++v72;
            }
            while ( v72 < a2[1] );
            v13 = v77;
          }
          memset((void *)(v18 + 36), 0, 0x1Cu);
          v77 = ++v13;
          v66 += 64;
        }
        while ( v13 < v11[1] );
      }
      sub_5890AA(v11[2], v11[1], 64, sub_4DE590);
      if ( *(int *)(*v11 + 288) > 0 )
      {
        v73 = 0;
        v81 = *(_DWORD *)(*v11 + 288);
        do
        {
          v26 = v73 + *(_DWORD *)(*v70 + 292);
          v78 = v26;
          for ( i = 0; i < 3; ++i )
            (&v84)[i] = (float *)sub_4DE5D0(v26, i);
          if ( v85[2] <= (double)v84[2] )
            v28 = v85[2];
          else
            v28 = v84[2];
          if ( v28 >= v86[2] )
          {
            v29 = v86[2];
          }
          else if ( v85[2] <= (double)v84[2] )
          {
            v29 = v85[2];
          }
          else
          {
            v29 = v84[2];
          }
          v79 = v29 - 0.0049999999;
          if ( v85[2] >= (double)v84[2] )
            v30 = v85[2];
          else
            v30 = v84[2];
          if ( v30 <= v86[2] )
          {
            v31 = v86[2];
          }
          else if ( v85[2] >= (double)v84[2] )
          {
            v31 = v85[2];
          }
          else
          {
            v31 = v84[2];
          }
          v32 = v70[1];
          v33 = 0;
          while ( v33 < v32 )
          {
            if ( *(float *)(((v32 + v33) >> 1 << 6) + v70[2] + 12) >= (double)v79 )
              v32 = (v32 + v33) >> 1;
            else
              v33 = ((v32 + v33) >> 1) + 1;
          }
          v34 = v70[1];
          v35 = v33;
          if ( v33 < v34 )
          {
            do
            {
              v67 = v31 + 0.0049999999;
              if ( *(float *)(((v34 + v33) >> 1 << 6) + v70[2] + 12) > (double)v67 )
                v34 = (v34 + v33) >> 1;
              else
                v33 = ((v34 + v33) >> 1) + 1;
            }
            while ( v33 < v34 );
            if ( v35 < v33 )
            {
              v68 = v35 << 6;
              v80 = v33 - v35;
              do
              {
                v36 = (float *)(v68 + v70[2]);
                if ( *(float *)(v78 + 28) + 0.0049999999 >= fabs(*(float *)(v78 + 16) - v36[1]) )
                {
                  v37 = 0;
                  while ( !(v39 | v40) )
                  {
                    if ( ++v37 >= 3 )
                      goto LABEL_65;
                  }
                  TriangleNormalComputation(v84, v85, v86, &v87);
                  if ( v89 * v36[3] + v88 * v36[2] + v87 * v36[1] > 0.0 )
                  {
                    v41 = 0;
                    v42 = (int *)(v36 + 9);
                    while ( 1 )
                    {
                      v43 = *v42;
                      if ( !*v42 )
                        break;
                      v64 = (float *)sub_4DE5D0(v43, 2);
                      v83 = (float *)sub_4DE5D0(v43, 1);
                      v44 = (float *)sub_4DE5D0(v43, 0);
                      TriangleNormalComputation(v44, v83, v64, v90);
                      if ( v90[0] != v87 || v90[1] != v88 || v90[2] != v89 )
                      {
                        ++v41;
                        ++v42;
                        if ( v41 < 7 )
                          continue;
                      }
                      goto LABEL_65;
                    }
                    LODWORD(v36[v41 + 9]) = v78;
                  }
                }
LABEL_65:
                v45 = v80 == 1;
                v68 += 64;
                --v80;
              }
              while ( !v45 );
            }
          }
          v45 = v81 == 1;
          v73 += 36;
          --v81;
        }
        while ( !v45 );
      }
      v46 = ++v91 < this[2];
      v75 += 12;
    }
    while ( v46 );
  }
  v47 = a2[3];
  this[4] = v47;
  v48 = (_DWORD *)OperatorNewNhMallocWrapper(24 * v47 + 4);
  if ( v48 )
  {
    *v48 = v47;
    v49 = v48 + 1;
    if ( v47 - 1 >= 0 )
    {
      v50 = v48 + 6;
      v51 = v47;
      do
      {
        *(v50 - 1) = 0;
        *v50 = 0;
        v50 += 6;
        --v51;
      }
      while ( v51 );
    }
    result = v49;
  }
  else
  {
    result = 0;
  }
  this[5] = result;
  v92 = 0;
  if ( (int)this[4] <= 0 )
  {
    this[6] = 0;
  }
  else
  {
    v71 = 0;
    v53 = this;
    do
    {
      v54 = (float *)(v71 + v53[5]);
      qmemcpy(v54, (const void *)(v71 + a2[4]), 0x18u);
      v54[4] = 0.0;
      v55 = v53[1];
      if ( *(_BYTE *)(v55 + 66) )
      {
        *v54 = *v54 - *(float *)(v55 + 4);
        v54[1] = v54[1] - *(float *)(v55 + 8);
        v54[2] = v54[2] - *(float *)(v55 + 12);
      }
      v76 = 0;
      for ( j = 0; j < 2; ++j )
      {
        if ( j == 1 )
          *((_DWORD *)v54 + 5) = OperatorNewNhMallocWrapper(4 * v76);
        v82 = 0;
        if ( (int)v53[2] > 0 )
        {
          v74 = 0;
          do
          {
            v56 = v53[3];
            v57 = *(_DWORD *)(v56 + v74 + 4);
            v58 = v74 + v56;
            v59 = 0;
            if ( v57 > 0 )
            {
              v60 = 0;
              do
              {
                if ( v62 | v63 )
                {
                  if ( j )
                  {
                    *(_DWORD *)(*((_DWORD *)v54 + 5) + 4 * *((_DWORD *)v54 + 4)) = v60 + *(_DWORD *)(v58 + 8);
                    v53 = this;
                    ++*((_DWORD *)v54 + 4);
                  }
                  else
                  {
                    ++v76;
                  }
                }
                ++v59;
                v60 += 64;
              }
              while ( v59 < *(_DWORD *)(v58 + 4) );
            }
            v46 = ++v82 < v53[2];
            v74 += 12;
          }
          while ( v46 );
        }
      }
      result = (_DWORD *)(v92 + 1);
      v46 = ++v92 < v53[4];
      v71 += 24;
    }
    while ( v46 );
    v53[6] = 0;
  }
  return result;
}
