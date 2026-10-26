double __fastcall sub_43A6A0(int a1, int a2, double *a3, double *a4, char a5, _DWORD *a6)
{
  double *v6; // ebx
  long double v7; // st7
  long double v8; // st7
  double v9; // st7
  double result; // st7
  double *v11; // esi
  double *v12; // edi
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c3
  bool v16; // zf
  double v17; // st7
  bool v18; // c0
  bool v19; // c3
  double v20; // st7
  double v21; // st6
  double v22; // st5
  double v23; // st7
  double v24; // st6
  double v26; // st5
  unsigned __int8 v27; // c0
  unsigned __int8 v28; // c3
  int v29; // ebx
  int v30; // edx
  double v32; // st7
  unsigned __int8 v33; // c0
  unsigned __int8 v34; // c3
  double v35; // st7
  double v36; // st6
  double v37; // st5
  int v38; // edx
  int v39; // eax
  double v40; // st7
  double v41; // st4
  double v42; // st3
  double v43; // st4
  double v44; // st3
  long double v45; // st7
  bool v46; // cc
  int v47; // eax
  int v48; // edx
  int v49; // eax
  int v50; // edx
  int v51; // eax
  int v52; // eax
  int v53; // edx
  int v54; // eax
  double v55; // [esp+10h] [ebp-118h]
  double v56; // [esp+10h] [ebp-118h]
  double v57; // [esp+10h] [ebp-118h]
  double v58; // [esp+10h] [ebp-118h]
  double v59; // [esp+10h] [ebp-118h]
  double v60; // [esp+10h] [ebp-118h]
  double v61; // [esp+10h] [ebp-118h]
  int v62; // [esp+1Ch] [ebp-10Ch]
  double v63; // [esp+20h] [ebp-108h]
  double v64; // [esp+28h] [ebp-100h]
  double v65; // [esp+30h] [ebp-F8h]
  double v66; // [esp+38h] [ebp-F0h]
  double v67; // [esp+40h] [ebp-E8h]
  double v68; // [esp+48h] [ebp-E0h]
  double v69; // [esp+50h] [ebp-D8h]
  double v70; // [esp+58h] [ebp-D0h]
  double v71; // [esp+60h] [ebp-C8h]
  double v72; // [esp+68h] [ebp-C0h]
  double v73; // [esp+68h] [ebp-C0h]
  double v74; // [esp+70h] [ebp-B8h]
  double v75; // [esp+70h] [ebp-B8h]
  double v76; // [esp+78h] [ebp-B0h]
  double v77; // [esp+78h] [ebp-B0h]
  int v78; // [esp+84h] [ebp-A4h]
  double v79; // [esp+A8h] [ebp-80h]
  double v80; // [esp+B0h] [ebp-78h]
  double v81; // [esp+B8h] [ebp-70h]
  double v82; // [esp+C0h] [ebp-68h]
  double v83; // [esp+D8h] [ebp-50h]
  double v84; // [esp+E0h] [ebp-48h]
  double v85; // [esp+E8h] [ebp-40h]
  _DWORD v86[12]; // [esp+F0h] [ebp-38h] BYREF
  double v87; // [esp+120h] [ebp-8h]

  v6 = a3;
  v62 = a2;
  if ( a5 )
  {
    v72 = *a4 - *(double *)a1;
    v74 = a4[1] - *(double *)(a1 + 8);
    v76 = a4[2] - *(double *)(a1 + 16);
    v7 = v76 * v76 + v74 * v74 + v72 * v72;
    if ( v7 > a4[4] )
    {
      v8 = sqrt(v7);
      v9 = v8 * (v8 - a4[3]);
      if ( v76 * (*(double *)(a2 + 16) - *(double *)(a1 + 16))
         + (*(double *)(a2 + 8) - *(double *)(a1 + 8)) * v74
         + (*(double *)a2 - *(double *)a1) * v72 < v9
        && v76 * (a3[2] - *(double *)(a1 + 16)) + (a3[1] - *(double *)(a1 + 8)) * v74 + (*a3 - *(double *)a1) * v72 < v9 )
      {
        return 0.0;
      }
    }
  }
  v63 = *(double *)a2 - *(double *)a1;
  v64 = *(double *)(a2 + 8) - *(double *)(a1 + 8);
  v65 = *(double *)(a2 + 16) - *(double *)(a1 + 16);
  v66 = *a3 - *(double *)a2;
  v67 = a3[1] - *(double *)(a2 + 8);
  v68 = a3[2] - *(double *)(a2 + 16);
  v69 = *(double *)a1 - *a3;
  v70 = *(double *)(a1 + 8) - a3[1];
  v71 = *(double *)(a1 + 16) - a3[2];
  v73 = v67 * v65 - v68 * v64;
  v75 = v68 * v63 - v66 * v65;
  v77 = v66 * v64 - v67 * v63;
  v83 = v73 * v64 - v75 * v63;
  v79 = v75 * v68 - v77 * v67;
  v80 = v77 * v66 - v73 * v68;
  v81 = v73 * v67 - v75 * v66;
  v87 = (v77 * v63 - v73 * v65) * *(double *)(a1 + 8)
      + v83 * *(double *)(a1 + 16)
      + (v75 * v65 - v77 * v64) * *(double *)a1;
  v82 = v79 * *(double *)a2 + v81 * *(double *)(a2 + 16) + v80 * *(double *)(a2 + 8);
  v78 = 0;
  v11 = (double *)v86;
  v12 = a4 + 2;
  do
  {
    v16 = (v14 | v15) == 0;
    v17 = v79 * *(v12 - 2) + v80 * *(v12 - 1) + v81 * *v12;
    v18 = v17 < v82;
    v19 = v17 == v82;
    if ( v16 )
    {
      if ( !v18 && !v19 )
      {
        v20 = *(v12 - 2) - *(double *)a2;
        v21 = *(v12 - 1) - *(double *)(a2 + 8);
        v22 = *v12 - *(double *)(a2 + 16);
        if ( v71 * v22 + v21 * v70 + v20 * v69 > 0.0 )
        {
          v55 = (v22 * v65 + v21 * v64 + v20 * v63) / (v63 * v63 + v64 * v64 + v65 * v65);
          if ( v55 < -1.0 )
          {
LABEL_45:
            *(_DWORD *)v11 = *(_DWORD *)a1;
            *((_DWORD *)v11 + 1) = *(_DWORD *)(a1 + 4);
            *((_DWORD *)v11 + 2) = *(_DWORD *)(a1 + 8);
            *((_DWORD *)v11 + 3) = *(_DWORD *)(a1 + 12);
            v39 = *(_DWORD *)(a1 + 20);
            *((_DWORD *)v11 + 4) = *(_DWORD *)(a1 + 16);
            v6 = a3;
            *((_DWORD *)v11 + 5) = v39;
            a2 = v62;
            goto LABEL_47;
          }
          if ( v55 <= 0.0 )
          {
            *v11 = v63 * v55 + *(double *)a2;
            v11[1] = v64 * v55 + *(double *)(a2 + 8);
            v11[2] = v65 * v55 + *(double *)(a2 + 16);
            goto LABEL_47;
          }
LABEL_25:
          *(_DWORD *)v11 = *(_DWORD *)a2;
          *((_DWORD *)v11 + 1) = *(_DWORD *)(a2 + 4);
          *((_DWORD *)v11 + 2) = *(_DWORD *)(a2 + 8);
          *((_DWORD *)v11 + 3) = *(_DWORD *)(a2 + 12);
          v29 = *(_DWORD *)(a2 + 16);
          v30 = *(_DWORD *)(a2 + 20);
          *((_DWORD *)v11 + 4) = v29;
          v6 = a3;
          *((_DWORD *)v11 + 5) = v30;
          a2 = v62;
          goto LABEL_47;
        }
        v56 = (v22 * v68 + v21 * v67 + v20 * v66) / (v66 * v66 + v67 * v67 + v68 * v68);
        if ( v56 < 0.0 )
          goto LABEL_25;
        if ( v56 <= 1.0 )
        {
          *v11 = v66 * v56 + *(double *)a2;
          v11[1] = v67 * v56 + *(double *)(a2 + 8);
          v11[2] = v68 * v56 + *(double *)(a2 + 16);
          goto LABEL_47;
        }
LABEL_43:
        *(_DWORD *)v11 = *(_DWORD *)v6;
        *((_DWORD *)v11 + 1) = *((_DWORD *)v6 + 1);
        *((_DWORD *)v11 + 2) = *((_DWORD *)v6 + 2);
        *((_DWORD *)v11 + 3) = *((_DWORD *)v6 + 3);
        *((_DWORD *)v11 + 4) = *((_DWORD *)v6 + 4);
        v38 = *((_DWORD *)v6 + 5);
        v6 = a3;
        *((_DWORD *)v11 + 5) = v38;
        a2 = v62;
        goto LABEL_47;
      }
      v23 = *(v12 - 2) - *(double *)a1;
      v24 = *(v12 - 1) - *(double *)(a1 + 8);
      v26 = *v12 - *(double *)(a1 + 16);
      if ( v27 | v28 )
      {
        v58 = (v26 * v65 + v24 * v64 + v23 * v63) / (v63 * v63 + v64 * v64 + v65 * v65);
        if ( v58 < 0.0 )
          goto LABEL_45;
      }
      else
      {
        if ( v68 * v26 + v24 * v67 + v23 * v66 > 0.0 )
        {
          v57 = (v26 * v71 + v24 * v70 + v23 * v69) / (v69 * v69 + v70 * v70 + v71 * v71);
          if ( v57 < -1.0 )
            goto LABEL_43;
          if ( v57 <= 0.0 )
          {
            *v11 = v69 * v57 + *(double *)a1;
            v11[1] = v70 * v57 + *(double *)(a1 + 8);
            v11[2] = v71 * v57 + *(double *)(a1 + 16);
            goto LABEL_47;
          }
          goto LABEL_45;
        }
        v58 = (v26 * v65 + v24 * v64 + v23 * v63) / (v63 * v63 + v64 * v64 + v65 * v65);
        if ( v58 < 0.0 )
        {
          a2 = a1;
          goto LABEL_25;
        }
      }
      if ( v58 > 1.0 )
        goto LABEL_25;
      *v11 = v58 * v63 + *(double *)a1;
      v11[1] = v58 * v64 + *(double *)(a1 + 8);
      v11[2] = v58 * v65 + *(double *)(a1 + 16);
    }
    else
    {
      v16 = !v18 && !v19;
      v32 = *(v12 - 2);
      if ( v16 )
      {
        if ( v33 | v34 )
        {
          v61 = ((*v12 - *(double *)(a2 + 16)) * v68
               + (*(v12 - 1) - *(double *)(a2 + 8)) * v67
               + (v32 - *(double *)a2) * v66)
              / (v66 * v66 + v67 * v67 + v68 * v68);
          if ( v61 < 0.0 )
            goto LABEL_25;
          if ( v61 <= 1.0 )
          {
            *v11 = v61 * v66 + *(double *)a2;
            v11[1] = v61 * v67 + *(double *)(a2 + 8);
            v11[2] = v61 * v68 + *(double *)(a2 + 16);
            goto LABEL_47;
          }
        }
        else
        {
          v35 = v32 - *v6;
          v36 = *(v12 - 1) - v6[1];
          v37 = *v12 - v6[2];
          if ( v65 * v37 + v36 * v64 + v35 * v63 <= 0.0 )
          {
            v60 = (v37 * v71 + v36 * v70 + v35 * v69) / (v69 * v69 + v70 * v70 + v71 * v71);
            if ( v60 < 0.0 )
              goto LABEL_43;
            if ( v60 <= 1.0 )
              goto LABEL_37;
            goto LABEL_45;
          }
          v59 = (v37 * v68 + v36 * v67 + v35 * v66) / (v66 * v66 + v67 * v67 + v68 * v68);
          if ( v59 < -1.0 )
            goto LABEL_25;
          if ( v59 <= 0.0 )
          {
            *v11 = v59 * v66 + *v6;
            v11[1] = v59 * v67 + v6[1];
            v11[2] = v59 * v68 + v6[2];
            goto LABEL_47;
          }
        }
        goto LABEL_43;
      }
      if ( !(v33 | v34) )
      {
        v60 = ((*v12 - v6[2]) * v71 + (*(v12 - 1) - v6[1]) * v70 + (v32 - *v6) * v69)
            / (v69 * v69 + v70 * v70 + v71 * v71);
        if ( v60 < 0.0 )
          goto LABEL_43;
        if ( v60 <= 1.0 )
        {
LABEL_37:
          *v11 = v60 * v69 + *v6;
          v11[1] = v60 * v70 + v6[1];
          v11[2] = v60 * v71 + v6[2];
          goto LABEL_47;
        }
        goto LABEL_45;
      }
      v40 = ((*v12 - *(double *)(a1 + 16)) * v77 + (*(v12 - 1) - *(double *)(a1 + 8)) * v75 + (v32 - *(double *)a1)
                                                                                            * v73)
          / (v73 * v73 + v75 * v75 + v77 * v77);
      *v11 = *(v12 - 2) - v73 * v40;
      v11[1] = *(v12 - 1) - v75 * v40;
      v11[2] = *v12 - v77 * v40;
    }
LABEL_47:
    v41 = *v12 - v11[2];
    v42 = *(v12 - 1) - v11[1];
    v43 = v41 * v41 + v42 * v42;
    v44 = *(v12 - 2) - *v11;
    v45 = v43 + v44 * v44;
    if ( v45 >= v12[1] * v12[1] )
      return 0.0;
    v11 += 3;
    v12 += 5;
    v46 = ++v78 < 2;
    *(&v83 + v78) = *(v12 - 4) - sqrt(v45);
  }
  while ( v46 );
  if ( v84 >= v85 )
  {
    result = v85;
    v52 = v86[7];
    *a6 = v86[6];
    v53 = v86[8];
    a6[1] = v52;
    v54 = v86[9];
    a6[2] = v53;
    v50 = v86[10];
    a6[3] = v54;
    v51 = v86[11];
  }
  else
  {
    result = v84;
    v47 = v86[1];
    *a6 = v86[0];
    v48 = v86[2];
    a6[1] = v47;
    v49 = v86[3];
    a6[2] = v48;
    v50 = v86[4];
    a6[3] = v49;
    v51 = v86[5];
  }
  a6[4] = v50;
  a6[5] = v51;
  return result;
}
