int __thiscall sub_4FEDA0(void *this, int a2)
{
  int v3; // ebx
  int v4; // eax
  char *v5; // edi
  int v6; // eax
  _DWORD *v7; // edi
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // edx
  int result; // eax
  CHAR *v12; // esi
  CHAR *v13; // esi
  double v14; // st7
  int v15; // eax
  double *v16; // ecx
  int v17; // ecx
  int v18; // edi
  int v19; // eax
  double *v20; // edx
  int v21; // ebx
  int v22; // ecx
  double v23; // st7
  int v24; // edx
  int v25; // ecx
  double v26; // st7
  int v27; // eax
  int v28; // edi
  double v29; // st7
  int v30; // eax
  int v31; // edi
  int v32; // edi
  int v33; // edi
  int v34; // ebx
  int v35; // edi
  double *v36; // ecx
  long double v37; // st6
  int v38; // edx
  int v39; // eax
  double *v40; // ecx
  double v41; // st7
  int v42; // eax
  double v43; // st6
  int v44; // [esp+10h] [ebp-498h]
  double v45; // [esp+10h] [ebp-498h]
  double v46; // [esp+10h] [ebp-498h]
  double v47; // [esp+10h] [ebp-498h]
  char v48; // [esp+1Fh] [ebp-489h]
  int v49; // [esp+20h] [ebp-488h]
  double v50; // [esp+20h] [ebp-488h]
  double v51; // [esp+20h] [ebp-488h]
  double v52; // [esp+20h] [ebp-488h]
  double *v53; // [esp+2Ch] [ebp-47Ch]
  int v54; // [esp+30h] [ebp-478h]
  double v55; // [esp+30h] [ebp-478h]
  int v56; // [esp+30h] [ebp-478h]
  double v57; // [esp+30h] [ebp-478h]
  double v58; // [esp+38h] [ebp-470h]
  double v59; // [esp+38h] [ebp-470h]
  double v60; // [esp+38h] [ebp-470h]
  double v61; // [esp+40h] [ebp-468h] BYREF
  double v62; // [esp+48h] [ebp-460h]
  int v63[2]; // [esp+50h] [ebp-458h] BYREF
  int v64[2]; // [esp+58h] [ebp-450h] BYREF
  double v65; // [esp+60h] [ebp-448h] BYREF
  double v66; // [esp+68h] [ebp-440h]
  double v67; // [esp+70h] [ebp-438h]
  int v68; // [esp+78h] [ebp-430h]
  int v69; // [esp+7Ch] [ebp-42Ch]
  double v70; // [esp+80h] [ebp-428h]
  double v71; // [esp+88h] [ebp-420h]
  double v72; // [esp+90h] [ebp-418h]
  int v73; // [esp+98h] [ebp-410h]
  int v74; // [esp+9Ch] [ebp-40Ch]
  int v75; // [esp+A0h] [ebp-408h]
  int v76; // [esp+A4h] [ebp-404h]
  double v77; // [esp+A8h] [ebp-400h]
  double v78; // [esp+B0h] [ebp-3F8h]
  double v79; // [esp+B8h] [ebp-3F0h]
  double v80; // [esp+C0h] [ebp-3E8h]
  int v81; // [esp+C8h] [ebp-3E0h]
  int v82; // [esp+CCh] [ebp-3DCh]
  double v83; // [esp+D0h] [ebp-3D8h]
  double v84; // [esp+D8h] [ebp-3D0h]
  double v85; // [esp+E0h] [ebp-3C8h]
  int v86; // [esp+E8h] [ebp-3C0h]
  int v87; // [esp+ECh] [ebp-3BCh]
  int v88; // [esp+F0h] [ebp-3B8h]
  int v89; // [esp+F4h] [ebp-3B4h]
  double v90; // [esp+F8h] [ebp-3B0h]
  _DWORD v91[4]; // [esp+100h] [ebp-3A8h] BYREF
  char String[384]; // [esp+110h] [ebp-398h] BYREF
  int v93; // [esp+290h] [ebp-218h]
  char v94; // [esp+294h] [ebp-214h]
  int v95; // [esp+29Ch] [ebp-20Ch]
  int v96; // [esp+2A0h] [ebp-208h]
  int v97; // [esp+2A4h] [ebp-204h]
  char Str[384]; // [esp+2A8h] [ebp-200h] BYREF
  int v99[32]; // [esp+428h] [ebp-80h] BYREF

  v3 = 0;
  memset(Str, 0, sizeof(Str));
  v48 = 0;
  v64[0] = 1202590843;
  v64[1] = 1065646817;
  v63[0] = 0;
  v63[1] = 1072693248;
  v54 = 0;
  v49 = 0;
  v53 = 0;
  v93 = 0;
  v97 = 0;
  v95 = 0;
  v96 = 0;
  v94 = 1;
  while ( sub_57A490(Str, 384) )
  {
    v4 = sub_577B60(String);
    if ( v4 == 1 || v4 == 4 )
      break;
    if ( !v4 )
    {
      if ( v48 )
      {
        v5 = strtok(Str, asc_612658);
        if ( v5 )
        {
          v44 = v3;
          do
          {
            if ( sscanf(v5, off_612654, &v61) == 1 )
            {
              v6 = v49;
              if ( v3 >= v49 )
              {
                v49 += 128;
                v7 = operator new(8 * (v6 + 128));
                if ( v44 > 0 )
                {
                  v8 = v7;
                  v9 = (char *)v53 - (char *)v7;
                  v10 = v3;
                  do
                  {
                    *v8 = *(_DWORD *)((char *)v8 + v9);
                    v8[1] = *(_DWORD *)((char *)v8 + v9 + 4);
                    v8 += 2;
                    --v10;
                  }
                  while ( v10 );
                  v3 = v54;
                }
                if ( v53 )
                  sub_5BE8AE();
                v53 = (double *)v7;
              }
              ++v3;
              v53[v44] = v61;
              v54 = v3;
              ++v44;
            }
            else
            {
              if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 303) )
                sub_500FE0((int)&unk_7D7920, aSkippingUnexpe, (char)v5);
              v3 = v54;
            }
            v5 = strtok(0, asc_612658);
          }
          while ( v5 );
        }
      }
      else
      {
        if ( sub_577E50(String, aName_1, (int)v99) )
          sub_578600(v99);
        sub_578450(aStep, (int)v64, 0, 0, 0);
        sub_578450(aDropofffunctio, (int)v63, 0, 0, 0);
        if ( strstr(Str, aData) )
          v48 = 1;
      }
    }
  }
  if ( *(double *)v64 <= 0.0 )
  {
    result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 317);
    if ( (_BYTE)result )
    {
      v12 = *(CHAR **)this;
      if ( !v12 )
        v12 = &byte_629120;
      return sub_500FE0((int)&unk_7D7920, aTireSlipCurveS, (char)v12);
    }
    return result;
  }
  if ( v3 < 3 )
  {
    result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 326);
    if ( (_BYTE)result )
      return sub_500FE0((int)&unk_7D7920, aNeedAtLeastDDa, 3);
    return result;
  }
  if ( *v53 != 0.0 )
  {
    result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 334);
    if ( (_BYTE)result )
    {
      v13 = *(CHAR **)this;
      if ( !v13 )
        v13 = &byte_629120;
      return sub_500FE0((int)&unk_7D7920, aFirstDataPoint, (char)v13);
    }
    return result;
  }
  *((_DWORD *)this + 8) = v3;
  *((_DWORD *)this + 9) = operator new(32 * v3);
  if ( *((int *)this + 8) <= 3 )
    v14 = v53[1] - *v53;
  else
    v14 = (v53[2] - *v53 + v53[2] - *v53 - (v53[3] - v53[1])) * 0.5;
  v15 = 0;
  v16 = &v65;
  do
  {
    v91[v15++] = v16;
    v16 += 5;
  }
  while ( v15 < 4 );
  v17 = 0;
  v18 = 0;
  while ( 1 )
  {
    v19 = *((_DWORD *)this + 8);
    if ( v17 < v19 - 2 )
    {
      v20 = v53;
      v58 = (v53[v17 + 2] - v53[v17]) * 0.5;
      goto LABEL_50;
    }
    if ( v17 >= v19 - 1 )
      break;
    v20 = v53;
    v58 = 0.0;
LABEL_50:
    v50 = (double)v17;
    v55 = v20[v17];
    v21 = v17 + 1;
    v67 = v50;
    v68 = 0;
    v69 = 1072693248;
    v65 = v50 * (v50 * v50);
    v73 = 0;
    v74 = 1072693248;
    v66 = v50 * v50;
    v75 = 0;
    v76 = 0;
    v70 = v55;
    v71 = v66 * 3.0;
    v72 = v50 + v50;
    v77 = v14;
    v45 = (double)(v17 + 1);
    v62 = v53[v17 + 1];
    v80 = v45;
    v90 = v58;
    v78 = v45 * (v45 * v45);
    v81 = 0;
    v79 = v45 * v45;
    v82 = 1072693248;
    v86 = 0;
    v83 = v62;
    v87 = 1072693248;
    v88 = 0;
    v89 = 0;
    v84 = v79 * 3.0;
    v85 = v45 + v45;
    if ( sub_579F40(v91, 4) )
    {
      v22 = *((_DWORD *)this + 9);
      v23 = v62 - v55;
      *(_DWORD *)(v18 + v22) = 0;
      *(_DWORD *)(v18 + v22 + 4) = 0;
      v24 = *((_DWORD *)this + 9);
      *(_DWORD *)(v24 + v18 + 8) = 0;
      *(_DWORD *)(v24 + v18 + 12) = 0;
      *(double *)(*((_DWORD *)this + 9) + v18 + 16) = v23 / (v45 - v50);
      v25 = *((_DWORD *)this + 9);
      v26 = v50 * *(double *)(v25 + v18 + 16);
      v27 = v25 + v18;
      v18 += 32;
      v17 = v21;
      *(double *)(v27 + 24) = v55 - v26;
    }
    else
    {
      *(double *)(v18 + *((_DWORD *)this + 9)) = v70;
      v18 += 32;
      *(double *)(*((_DWORD *)this + 9) + v18 - 24) = v77;
      v17 = v21;
      *(double *)(*((_DWORD *)this + 9) + v18 - 16) = v83;
      *(double *)(*((_DWORD *)this + 9) + v18 - 8) = v90;
    }
    v14 = v58;
  }
  v28 = *((_DWORD *)this + 9);
  v29 = 0.0;
  v30 = 32 * v17;
  *(_DWORD *)(v30 + v28) = 0;
  *(_DWORD *)(v30 + v28 + 4) = 0;
  v31 = *((_DWORD *)this + 9);
  *(_DWORD *)(v30 + v31 + 8) = 0;
  *(_DWORD *)(v30 + v31 + 12) = 0;
  v32 = *((_DWORD *)this + 9);
  *(_DWORD *)(v30 + v32 + 16) = 0;
  *(_DWORD *)(v30 + v32 + 20) = 0;
  v33 = *((_DWORD *)this + 9);
  *(_DWORD *)(v30 + v33 + 24) = LODWORD(v53[v17]);
  *(_DWORD *)(v30 + v33 + 28) = HIDWORD(v53[v17]);
  v34 = *((_DWORD *)this + 8);
  v35 = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  v56 = 0;
  if ( v34 > 0 )
  {
    v36 = (double *)*((_DWORD *)this + 9);
    do
    {
      v59 = (double)v56;
      v61 = v59 * ((v59 * *v36 + v36[1]) * v59 + v36[2]) + v36[3];
      if ( v61 > v29 )
      {
        v29 = v61;
        *((double *)this + 3) = v59;
      }
      v51 = *v36 * 3.0;
      if ( v51 != 0.0 )
      {
        v57 = v36[1] + v36[1];
        v37 = v57 * v57 - v36[2] * v51 * 4.0;
        if ( v37 >= 0.0 )
        {
          v62 = sqrt(v37);
          v61 = -0.5 / v51;
          v46 = (v62 + v57) * v61;
          if ( v46 > v59 && (double)(v35 + 1) > v46 )
          {
            v52 = ((v46 * *v36 + v36[1]) * v46 + v36[2]) * v46 + v36[3];
            if ( v52 > v29 )
            {
              v29 = v52;
              *((double *)this + 3) = v46;
            }
          }
          v47 = (v57 - v62) * v61;
          if ( v47 > v59 && (double)(v35 + 1) > v47 )
          {
            v61 = ((v47 * *v36 + v36[1]) * v47 + v36[2]) * v47 + v36[3];
            if ( v61 > v29 )
            {
              v29 = v61;
              *((double *)this + 3) = v47;
            }
          }
        }
      }
      v61 = (double)++v35;
      v62 = v61 * ((v61 * *v36 + v36[1]) * v61 + v36[2]) + v36[3];
      if ( v62 > v29 )
      {
        v29 = v62;
        *((double *)this + 3) = v61;
      }
      v36 += 4;
      v56 = v35;
    }
    while ( v35 < v34 );
  }
  v38 = 0;
  v60 = 1.0 / v29;
  if ( v34 > 0 )
  {
    v39 = 0;
    do
    {
      ++v38;
      *(double *)(v39 + *((_DWORD *)this + 9)) = v60 * *(double *)(*((_DWORD *)this + 9) + v39);
      *(double *)(*((_DWORD *)this + 9) + v39 + 8) = v60 * *(double *)(*((_DWORD *)this + 9) + v39 + 8);
      *(double *)(*((_DWORD *)this + 9) + v39 + 16) = v60 * *(double *)(*((_DWORD *)this + 9) + v39 + 16);
      v40 = (double *)(*((_DWORD *)this + 9) + v39 + 24);
      v39 += 32;
      *v40 = v60 * *v40;
    }
    while ( v38 < *((_DWORD *)this + 8) );
  }
  v41 = 1.0 - *(double *)v63;
  v42 = v63[1];
  v43 = *(double *)v64 * *((double *)this + 3);
  *((_DWORD *)this + 4) = v63[0];
  *((_DWORD *)this + 5) = v42;
  *((double *)this + 1) = v41 / v43;
  return sub_5BE8AE();
}
