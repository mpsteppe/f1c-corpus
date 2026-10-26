int __thiscall sub_4D5F70(double *this, int a2)
{
  int v3; // ebx
  int v4; // eax
  int v5; // edi
  _DWORD *v6; // edi
  _DWORD *v7; // eax
  char *v8; // ecx
  int v9; // edx
  int result; // eax
  double v11; // st7
  int v12; // eax
  double *v13; // ecx
  int v14; // ecx
  int v15; // edi
  int v16; // eax
  double *v17; // edx
  int v18; // ebx
  int v19; // ecx
  double v20; // st7
  int v21; // edx
  int v22; // ecx
  double v23; // st7
  int v24; // eax
  int v25; // edi
  double v26; // st7
  int v27; // eax
  int v28; // edi
  int v29; // edi
  int v30; // edi
  int v31; // ebx
  int v32; // edi
  double *v33; // ecx
  long double v34; // st6
  int v35; // edx
  int v36; // eax
  double *v37; // ecx
  int v38; // [esp-4h] [ebp-4A4h]
  int v39; // [esp+10h] [ebp-490h]
  double v40; // [esp+10h] [ebp-490h]
  double v41; // [esp+10h] [ebp-490h]
  double v42; // [esp+10h] [ebp-490h]
  char v43; // [esp+1Fh] [ebp-481h]
  int v44; // [esp+20h] [ebp-480h]
  double v45; // [esp+20h] [ebp-480h]
  double v46; // [esp+20h] [ebp-480h]
  double v47; // [esp+20h] [ebp-480h]
  double *v48; // [esp+2Ch] [ebp-474h]
  int v49; // [esp+30h] [ebp-470h]
  double v50; // [esp+30h] [ebp-470h]
  int v51; // [esp+30h] [ebp-470h]
  double v52; // [esp+30h] [ebp-470h]
  double v53; // [esp+38h] [ebp-468h]
  double v54; // [esp+38h] [ebp-468h]
  double v55; // [esp+38h] [ebp-468h]
  double v56; // [esp+40h] [ebp-460h] BYREF
  double v57; // [esp+48h] [ebp-458h]
  double v58; // [esp+50h] [ebp-450h] BYREF
  double v59; // [esp+58h] [ebp-448h] BYREF
  double v60; // [esp+60h] [ebp-440h]
  double v61; // [esp+68h] [ebp-438h]
  int v62; // [esp+70h] [ebp-430h]
  int v63; // [esp+74h] [ebp-42Ch]
  double v64; // [esp+78h] [ebp-428h]
  double v65; // [esp+80h] [ebp-420h]
  double v66; // [esp+88h] [ebp-418h]
  int v67; // [esp+90h] [ebp-410h]
  int v68; // [esp+94h] [ebp-40Ch]
  int v69; // [esp+98h] [ebp-408h]
  int v70; // [esp+9Ch] [ebp-404h]
  double v71; // [esp+A0h] [ebp-400h]
  double v72; // [esp+A8h] [ebp-3F8h]
  double v73; // [esp+B0h] [ebp-3F0h]
  double v74; // [esp+B8h] [ebp-3E8h]
  int v75; // [esp+C0h] [ebp-3E0h]
  int v76; // [esp+C4h] [ebp-3DCh]
  double v77; // [esp+C8h] [ebp-3D8h]
  double v78; // [esp+D0h] [ebp-3D0h]
  double v79; // [esp+D8h] [ebp-3C8h]
  int v80; // [esp+E0h] [ebp-3C0h]
  int v81; // [esp+E4h] [ebp-3BCh]
  int v82; // [esp+E8h] [ebp-3B8h]
  int v83; // [esp+ECh] [ebp-3B4h]
  double v84; // [esp+F0h] [ebp-3B0h]
  _DWORD v85[4]; // [esp+F8h] [ebp-3A8h] BYREF
  _BYTE v86[384]; // [esp+108h] [ebp-398h] BYREF
  int v87; // [esp+288h] [ebp-218h]
  char v88; // [esp+28Ch] [ebp-214h]
  int v89; // [esp+294h] [ebp-20Ch]
  int v90; // [esp+298h] [ebp-208h]
  int v91; // [esp+29Ch] [ebp-204h]
  _BYTE v92[384]; // [esp+2A0h] [ebp-200h] BYREF
  _BYTE v93[128]; // [esp+420h] [ebp-80h] BYREF

  v3 = 0;
  memset(v92, 0, sizeof(v92));
  v43 = 0;
  v58 = 0.01;
  v49 = 0;
  v44 = 0;
  v48 = 0;
  v87 = 0;
  v91 = 0;
  v89 = 0;
  v90 = 0;
  v88 = 1;
  while ( ConditionalDispatchBasedOnFlag(v92, 384) )
  {
    v4 = sub_5651B0(v86);
    if ( v4 == 1 || v4 == 4 )
      break;
    if ( !v4 )
    {
      if ( v43 )
      {
        v5 = sub_5897CA(v92, &unk_5D46FC);
        if ( v5 )
        {
          v39 = v3;
          do
          {
            if ( StrlenFormatCallWrapper(v5, (const char *)&off_5D46F8, &v56) == 1 )
            {
              if ( v3 >= v44 )
              {
                v38 = 8 * (v44 + 128);
                v44 += 128;
                v6 = (_DWORD *)OperatorNewNhMallocWrapper(v38);
                if ( v39 > 0 )
                {
                  v7 = v6;
                  v8 = (char *)((char *)v48 - (char *)v6);
                  v9 = v3;
                  do
                  {
                    *v7 = *(_DWORD *)((char *)v7 + (_DWORD)v8);
                    v7[1] = *(_DWORD *)((char *)v7 + (_DWORD)v8 + 4);
                    v7 += 2;
                    --v9;
                  }
                  while ( v9 );
                  v3 = v49;
                }
                if ( v48 )
                  FreeWrapper_7bcf(v48);
                v48 = (double *)v6;
              }
              ++v3;
              v48[v39] = v56;
              v49 = v3;
              ++v39;
            }
            else
            {
              if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_4, 287) )
                DebugLogWrite(&dword_8AD25C, aSkippingUnexpe);
              v3 = v49;
            }
            v5 = sub_5897CA(0, &unk_5D46FC);
          }
          while ( v5 );
        }
      }
      else
      {
        if ( sub_5654A0(aName, v93) )
          StringCopyWithBufferRealloc(v93);
        sub_565AA0(aStep, &v58, 0, 0, 0);
        if ( sub_587C20(v92, aData) )
          v43 = 1;
      }
    }
  }
  if ( v58 <= 0.0 )
  {
    result = StringSplitLoop(1, aDDevF119992002_4, 301);
    if ( (_BYTE)result )
      return DebugLogWrite(&dword_8AD25C, aTireSlipCurveS);
    return result;
  }
  if ( v3 < 3 )
  {
    result = StringSplitLoop(1, aDDevF119992002_4, 310);
    if ( (_BYTE)result )
      return DebugLogWrite(&dword_8AD25C, aNeedAtLeastDDa);
    return result;
  }
  if ( *v48 != 0.0 )
  {
    result = StringSplitLoop(1, aDDevF119992002_4, 318);
    if ( (_BYTE)result )
      return DebugLogWrite(&dword_8AD25C, aFirstDataPoint);
    return result;
  }
  *((_DWORD *)this + 4) = v3;
  *((_DWORD *)this + 5) = OperatorNewNhMallocWrapper(32 * v3);
  if ( *((int *)this + 4) <= 3 )
    v11 = v48[1] - *v48;
  else
    v11 = (v48[2] - *v48 + v48[2] - *v48 - (v48[3] - v48[1])) * 0.5;
  v12 = 0;
  v13 = &v59;
  do
  {
    v85[v12++] = v13;
    v13 += 5;
  }
  while ( v12 < 4 );
  v14 = 0;
  v15 = 0;
  while ( 1 )
  {
    v16 = *((_DWORD *)this + 4);
    if ( v14 < v16 - 2 )
    {
      v17 = v48;
      v53 = (v48[v14 + 2] - v48[v14]) * 0.5;
      goto LABEL_46;
    }
    if ( v14 >= v16 - 1 )
      break;
    v17 = v48;
    v53 = 0.0;
LABEL_46:
    v45 = (double)v14;
    v50 = v17[v14];
    v18 = v14 + 1;
    v61 = v45;
    v62 = 0;
    v63 = 1072693248;
    v59 = v45 * (v45 * v45);
    v67 = 0;
    v68 = 1072693248;
    v60 = v45 * v45;
    v69 = 0;
    v70 = 0;
    v64 = v50;
    v65 = v60 * 3.0;
    v66 = v45 + v45;
    v71 = v11;
    v40 = (double)(v14 + 1);
    v57 = v48[v14 + 1];
    v74 = v40;
    v84 = v53;
    v72 = v40 * (v40 * v40);
    v75 = 0;
    v73 = v40 * v40;
    v76 = 1072693248;
    v80 = 0;
    v77 = v57;
    v81 = 1072693248;
    v82 = 0;
    v83 = 0;
    v78 = v73 * 3.0;
    v79 = v40 + v40;
    if ( sub_5677B0(v85, 4) )
    {
      v19 = *((_DWORD *)this + 5);
      v20 = v57 - v50;
      *(_DWORD *)(v15 + v19) = 0;
      *(_DWORD *)(v15 + v19 + 4) = 0;
      v21 = *((_DWORD *)this + 5);
      *(_DWORD *)(v21 + v15 + 8) = 0;
      *(_DWORD *)(v21 + v15 + 12) = 0;
      *(double *)(*((_DWORD *)this + 5) + v15 + 16) = v20 / (v40 - v45);
      v22 = *((_DWORD *)this + 5);
      v23 = v45 * *(double *)(v22 + v15 + 16);
      v24 = v22 + v15;
      v15 += 32;
      v14 = v18;
      *(double *)(v24 + 24) = v50 - v23;
    }
    else
    {
      *(double *)(v15 + *((_DWORD *)this + 5)) = v64;
      v15 += 32;
      *(double *)(*((_DWORD *)this + 5) + v15 - 24) = v71;
      v14 = v18;
      *(double *)(*((_DWORD *)this + 5) + v15 - 16) = v77;
      *(double *)(*((_DWORD *)this + 5) + v15 - 8) = v84;
    }
    v11 = v53;
  }
  v25 = *((_DWORD *)this + 5);
  v26 = 0.0;
  v27 = 32 * v14;
  *(_DWORD *)(v27 + v25) = 0;
  *(_DWORD *)(v27 + v25 + 4) = 0;
  v28 = *((_DWORD *)this + 5);
  *(_DWORD *)(v27 + v28 + 8) = 0;
  *(_DWORD *)(v27 + v28 + 12) = 0;
  v29 = *((_DWORD *)this + 5);
  *(_DWORD *)(v27 + v29 + 16) = 0;
  *(_DWORD *)(v27 + v29 + 20) = 0;
  v30 = *((_DWORD *)this + 5);
  *(_DWORD *)(v27 + v30 + 24) = LODWORD(v48[v14]);
  *(_DWORD *)(v27 + v30 + 28) = HIDWORD(v48[v14]);
  v31 = *((_DWORD *)this + 4);
  v32 = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  v51 = 0;
  if ( v31 > 0 )
  {
    v33 = (double *)*((_DWORD *)this + 5);
    do
    {
      v54 = (double)v51;
      v56 = v54 * ((v54 * *v33 + v33[1]) * v54 + v33[2]) + v33[3];
      if ( v56 > v26 )
      {
        v26 = v56;
        this[1] = v54;
      }
      v46 = *v33 * 3.0;
      if ( v46 != 0.0 )
      {
        v52 = v33[1] + v33[1];
        v34 = v52 * v52 - v33[2] * v46 * 4.0;
        if ( v34 >= 0.0 )
        {
          v57 = sqrt(v34);
          v56 = -0.5 / v46;
          v41 = (v57 + v52) * v56;
          if ( v41 > v54 && (double)(v32 + 1) > v41 )
          {
            v47 = ((v41 * *v33 + v33[1]) * v41 + v33[2]) * v41 + v33[3];
            if ( v47 > v26 )
            {
              v26 = v47;
              this[1] = v41;
            }
          }
          v42 = (v52 - v57) * v56;
          if ( v42 > v54 && (double)(v32 + 1) > v42 )
          {
            v56 = ((v42 * *v33 + v33[1]) * v42 + v33[2]) * v42 + v33[3];
            if ( v56 > v26 )
            {
              v26 = v56;
              this[1] = v42;
            }
          }
        }
      }
      v56 = (double)++v32;
      v57 = v56 * ((v56 * *v33 + v33[1]) * v56 + v33[2]) + v33[3];
      if ( v57 > v26 )
      {
        v26 = v57;
        this[1] = v56;
      }
      v33 += 4;
      v51 = v32;
    }
    while ( v32 < v31 );
  }
  v35 = 0;
  v55 = 1.0 / v26;
  if ( v31 > 0 )
  {
    v36 = 0;
    do
    {
      ++v35;
      *(double *)(v36 + *((_DWORD *)this + 5)) = v55 * *(double *)(*((_DWORD *)this + 5) + v36);
      *(double *)(*((_DWORD *)this + 5) + v36 + 8) = v55 * *(double *)(*((_DWORD *)this + 5) + v36 + 8);
      *(double *)(*((_DWORD *)this + 5) + v36 + 16) = v55 * *(double *)(*((_DWORD *)this + 5) + v36 + 16);
      v37 = (double *)(*((_DWORD *)this + 5) + v36 + 24);
      v36 += 32;
      *v37 = v55 * *v37;
    }
    while ( v35 < *((_DWORD *)this + 4) );
  }
  return FreeWrapper_7bcf(v48);
}
