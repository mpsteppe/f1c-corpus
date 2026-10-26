// positive sp value has been detected, the output may be wrong!
_DWORD *__thiscall sub_56D417(_DWORD *this, _DWORD *a2, int *a3)
{
  int v4; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // ebx
  _DWORD *v7; // eax
  bool v8; // cc
  int v9; // ecx
  int v10; // ebx
  int *v11; // eax
  int v12; // ebp
  _DWORD *v13; // esi
  int v14; // eax
  float *v15; // eax
  int v16; // ecx
  double v17; // st7
  float v18; // edx
  double v19; // st7
  double v20; // st6
  int v21; // ebx
  int v22; // edx
  int v23; // eax
  double v24; // st7
  unsigned __int16 *v25; // esi
  int v26; // eax
  float *v27; // ecx
  float *v28; // edx
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  int v33; // esi
  int v34; // ecx
  int v35; // esi
  int v36; // ebx
  float *v37; // edi
  int v38; // ecx
  unsigned __int8 v40; // c0
  unsigned __int8 v41; // c2
  int v42; // ebp
  unsigned __int16 **v43; // ebx
  unsigned __int16 *v44; // eax
  bool v45; // zf
  int v46; // esi
  _DWORD *result; // eax
  _DWORD *v48; // edi
  _DWORD *v49; // ebp
  float *v50; // esi
  float *v51; // ecx
  int v52; // eax
  int v53; // edx
  int v54; // eax
  int v55; // edx
  int v56; // ebx
  int v57; // edi
  int v58; // ecx
  double v59; // st7
  float *v60; // ecx
  long double v61; // st7
  int v63; // [esp-4h] [ebp-74h]
  float v64; // [esp-4h] [ebp-74h]
  int v65; // [esp-4h] [ebp-74h]
  int v66; // [esp-4h] [ebp-74h]
  _DWORD *v67; // [esp+0h] [ebp-70h]
  int v68; // [esp+0h] [ebp-70h]
  int v69; // [esp+4h] [ebp-6Ch]
  int v70; // [esp+4h] [ebp-6Ch]
  int v71; // [esp+4h] [ebp-6Ch]
  int v72; // [esp+8h] [ebp-68h]
  int v73; // [esp+8h] [ebp-68h]
  float v74; // [esp+Ch] [ebp-64h]
  int v75; // [esp+Ch] [ebp-64h]
  int v76; // [esp+10h] [ebp-60h]
  float *v77; // [esp+10h] [ebp-60h]
  int v78; // [esp+14h] [ebp-5Ch]
  int v79; // [esp+14h] [ebp-5Ch]
  int v80; // [esp+18h] [ebp-58h]
  float v81; // [esp+18h] [ebp-58h]
  float v82; // [esp+1Ch] [ebp-54h]
  float v83; // [esp+20h] [ebp-50h]
  float v84; // [esp+24h] [ebp-4Ch]
  float *v85; // [esp+34h] [ebp-3Ch]
  float *v86; // [esp+38h] [ebp-38h]
  float *v87; // [esp+3Ch] [ebp-34h]
  float v88; // [esp+40h] [ebp-30h] BYREF
  float v89; // [esp+44h] [ebp-2Ch]
  float v90; // [esp+48h] [ebp-28h]
  float v91; // [esp+4Ch] [ebp-24h]
  float v92; // [esp+50h] [ebp-20h]
  float v93; // [esp+54h] [ebp-1Ch]
  float v94[4]; // [esp+58h] [ebp-18h] BYREF
  int v95; // [esp+6Ch] [ebp-4h]
  int v96; // [esp+78h] [ebp+8h]
  _DWORD *v97; // [esp+78h] [ebp+8h]

  v94[3] = *(float *)&NtCurrentTeb()->NtTib.ExceptionList;
  this[1] = a3;
  v4 = *(_DWORD *)(*a3 + 544);
  v80 = *a3;
  this[2] = v4;
  v5 = operator new(12 * v4 + 4);
  v95 = 0;
  if ( v5 )
  {
    v6 = v5 + 1;
    *v5 = v4;
    sub_630A11(v5 + 1, 12, v4, unknown_libname_25, Concurrency::details::TaskStack::~TaskStack);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  this[3] = v7;
  v8 = this[2] <= 0;
  v95 = -1;
  v96 = 0;
  if ( !v8 )
  {
    v72 = 0;
    do
    {
      v9 = v96;
      v10 = 0;
      if ( v72 >= 0 && v96 < *(_DWORD *)(v80 + 544) )
      {
        v11 = *(int **)(v80 + 532);
        if ( v72 <= 0 )
        {
LABEL_11:
          if ( v11 )
          {
            v12 = *v11;
            goto LABEL_14;
          }
        }
        else
        {
          while ( v11 )
          {
            v11 = (int *)v11[1];
            if ( --v9 <= 0 )
              goto LABEL_11;
          }
        }
      }
      v12 = 0;
LABEL_14:
      v13 = (_DWORD *)(v72 + this[3]);
      v67 = v13;
      *v13 = v12;
      v14 = sub_5EA5B0(v12);
      v13[1] = v14;
      v13[2] = operator new(v14 << 6);
      v76 = 0;
      if ( (int)v13[1] > 0 )
      {
        v63 = 0;
        do
        {
          v15 = (float *)sub_5EB140(v10, 1);
          v16 = v63 + v13[2];
          *(_DWORD *)v16 = v15;
          v17 = v15[2];
          v18 = *v15;
          *(float *)(v16 + 8) = v15[1];
          *(float *)(v16 + 4) = v18;
          v69 = 0;
          *(float *)(v16 + 12) = v17;
          v19 = v15[5];
          v20 = v15[4];
          *(float *)(v16 + 20) = v15[3];
          *(float *)(v16 + 24) = v20;
          *(float *)(v16 + 28) = v19;
          *(float *)(v16 + 32) = v15[6];
          *(_DWORD *)(v16 + 16) = *a2;
          if ( (int)a2[1] > 0 )
          {
            v21 = 0;
            do
            {
              v22 = v21 + a2[2];
              v82 = *(float *)v22;
              v84 = *(float *)(v22 + 8);
              v23 = this[1];
              v83 = *(float *)(v22 + 4);
              if ( *(_BYTE *)(v23 + 66) )
              {
                v82 = v82 - *(float *)(v23 + 4);
                v83 = *(float *)(v22 + 4) - *(float *)(v23 + 8);
                v24 = v84 - *(float *)(v23 + 12);
              }
              else
              {
                v24 = v84;
              }
              v91 = *(float *)(v16 + 4) - v82;
              v92 = *(float *)(v16 + 8) - v83;
              v93 = *(float *)(v16 + 12) - v24;
              if ( v91 * v91 + v93 * v93 + v92 * v92 < *(float *)(v22 + 12)
                && *(float *)(v16 + 16) > (double)*(float *)(v22 + 16) )
              {
                *(_DWORD *)(v16 + 16) = *(_DWORD *)(v22 + 16);
              }
              v21 += 20;
              ++v69;
            }
            while ( v69 < a2[1] );
            v10 = v76;
          }
          *(_DWORD *)(v16 + 36) = 0;
          *(_DWORD *)(v16 + 40) = 0;
          *(_DWORD *)(v16 + 44) = 0;
          *(_DWORD *)(v16 + 48) = 0;
          *(_DWORD *)(v16 + 52) = 0;
          *(_DWORD *)(v16 + 56) = 0;
          *(_DWORD *)(v16 + 60) = 0;
          v76 = ++v10;
          v63 += 64;
        }
        while ( v10 < v13[1] );
      }
      sub_632C60(v13[2], v13[1]);
      if ( *(int *)(*v13 + 368) > 0 )
      {
        v70 = 0;
        v78 = *(_DWORD *)(*v13 + 368);
        do
        {
          v25 = (unsigned __int16 *)(v70 + *(_DWORD *)(*v67 + 372));
          v26 = *(_DWORD *)(*((_DWORD *)v25 + 2) + 32);
          v27 = (float *)(v26 + (*v25 << 6));
          v77 = (float *)v25;
          v28 = (float *)(v26 + (v25[1] << 6));
          v85 = v27;
          v86 = v28;
          v87 = (float *)(v26 + (v25[2] << 6));
          if ( v27[2] >= (double)v28[2] )
            v29 = v28[2];
          else
            v29 = v27[2];
          if ( v29 >= v87[2] )
          {
            v30 = v87[2];
          }
          else if ( v27[2] >= (double)v28[2] )
          {
            v30 = v28[2];
          }
          else
          {
            v30 = v27[2];
          }
          v74 = v30 - 0.0049999999;
          if ( v27[2] <= (double)v28[2] )
            v31 = v28[2];
          else
            v31 = v27[2];
          if ( v31 <= v87[2] )
          {
            v32 = v87[2];
          }
          else if ( v27[2] <= (double)v28[2] )
          {
            v32 = v28[2];
          }
          else
          {
            v32 = v27[2];
          }
          v33 = v67[1];
          v34 = 0;
          while ( v34 < v33 )
          {
            if ( *(float *)(((v33 + v34) >> 1 << 6) + v67[2] + 12) >= (double)v74 )
              v33 = (v33 + v34) >> 1;
            else
              v34 = ((v33 + v34) >> 1) + 1;
          }
          v35 = v67[1];
          v36 = v34;
          if ( v34 < v35 )
          {
            do
            {
              v64 = v32 + 0.0049999999;
              if ( *(float *)(((v35 + v34) >> 1 << 6) + v67[2] + 12) > (double)v64 )
                v35 = (v35 + v34) >> 1;
              else
                v34 = ((v35 + v34) >> 1) + 1;
            }
            while ( v34 < v35 );
            if ( v36 < v34 )
            {
              v65 = v36 << 6;
              v75 = v34 - v36;
              do
              {
                v37 = (float *)(v65 + v67[2]);
                if ( v77[8] + 0.0049999999 >= fabs(v77[5] - v37[1]) )
                {
                  v38 = 0;
                  while ( !(v40 | v41) )
                  {
                    if ( ++v38 >= 3 )
                      goto LABEL_71;
                  }
                  sub_568D90(v85, v86, v87, &v88);
                  if ( v90 * v37[3] + v89 * v37[2] + v88 * v37[1] > 0.0 )
                  {
                    v42 = 0;
                    v43 = (unsigned __int16 **)(v37 + 9);
                    while ( *v43 )
                    {
                      v44 = *v43;
                      sub_568D90(
                        (float *)(*(_DWORD *)(*((_DWORD *)v44 + 2) + 32) + (*v44 << 6)),
                        (float *)(*(_DWORD *)(*((_DWORD *)v44 + 2) + 32) + (v44[1] << 6)),
                        (float *)(*(_DWORD *)(*((_DWORD *)v44 + 2) + 32) + (v44[2] << 6)),
                        v94);
                      if ( v94[0] != v88 || v94[1] != v89 || v94[2] != v90 )
                      {
                        ++v42;
                        ++v43;
                        if ( v42 < 7 )
                          continue;
                      }
                      goto LABEL_71;
                    }
                    LODWORD(v37[v42 + 9]) = v77;
                  }
                }
LABEL_71:
                v45 = v75 == 1;
                v65 += 64;
                --v75;
              }
              while ( !v45 );
            }
          }
          v45 = v78 == 1;
          v70 += 36;
          --v78;
        }
        while ( !v45 );
      }
      v8 = ++v96 < this[2];
      v72 += 12;
    }
    while ( v8 );
  }
  v46 = a2[3];
  this[4] = v46;
  result = operator new(24 * v46 + 4);
  v95 = 1;
  if ( result )
  {
    v48 = result + 1;
    *result = v46;
    result = (_DWORD *)sub_630A11(result + 1, 24, v46, sub_569660, sub_568D80);
  }
  else
  {
    v48 = 0;
  }
  v8 = this[4] <= 0;
  v95 = -1;
  this[5] = v48;
  v97 = 0;
  if ( v8 )
  {
    this[6] = 0;
  }
  else
  {
    v68 = 0;
    v49 = this;
    do
    {
      v50 = (float *)(v68 + v49[5]);
      v51 = (float *)(v68 + a2[4]);
      *v50 = *v51;
      v50[1] = v51[1];
      v50[2] = v51[2];
      v50[3] = v51[3];
      v50[4] = v51[4];
      v50[5] = v51[5];
      v50[4] = 0.0;
      v52 = v49[1];
      if ( *(_BYTE *)(v52 + 66) )
      {
        *v50 = *v50 - *(float *)(v52 + 4);
        v50[1] = v50[1] - *(float *)(v52 + 8);
        v50[2] = v50[2] - *(float *)(v52 + 12);
      }
      v73 = 0;
      v66 = 0;
      v81 = sqrt(v50[3]);
      do
      {
        if ( v66 == 1 )
          *((_DWORD *)v50 + 5) = operator new(4 * v73);
        v79 = 0;
        if ( (int)v49[2] > 0 )
        {
          v71 = 0;
          do
          {
            v53 = v49[3];
            v54 = *(_DWORD *)(v53 + v71 + 4);
            v55 = v71 + v53;
            v56 = 0;
            if ( v54 > 0 )
            {
              v57 = 0;
              do
              {
                v58 = *(_DWORD *)(v55 + 8);
                v59 = *v50 - *(float *)(v58 + v57 + 4);
                v60 = (float *)(v57 + v58);
                v91 = v59;
                v92 = v50[1] - v60[2];
                v93 = v50[2] - v60[3];
                v61 = sqrt(v60[4]) + v81;
                if ( v91 * v91 + v93 * v93 + v92 * v92 < v61 * v61 )
                {
                  if ( v66 )
                  {
                    *(_DWORD *)(*((_DWORD *)v50 + 5) + 4 * *((_DWORD *)v50 + 4)) = v60;
                    v49 = this;
                    ++*((_DWORD *)v50 + 4);
                  }
                  else
                  {
                    ++v73;
                  }
                }
                ++v56;
                v57 += 64;
              }
              while ( v56 < *(_DWORD *)(v55 + 4) );
            }
            v8 = ++v79 < v49[2];
            v71 += 12;
          }
          while ( v8 );
        }
        ++v66;
      }
      while ( v66 < 2 );
      result = (_DWORD *)((char *)v97 + 1);
      v97 = result;
      v68 += 24;
    }
    while ( (int)result < v49[4] );
    v49[6] = 0;
  }
  return result;
}
