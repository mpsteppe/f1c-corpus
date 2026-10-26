__int16 __fastcall sub_5EA6C0(int a1, int a2, char a3)
{
  int v3; // esi
  double v5; // st7
  int v6; // eax
  double v7; // st6
  double v8; // st5
  double v9; // st4
  double v10; // st3
  double v11; // st2
  _DWORD *v12; // ecx
  int v13; // edx
  int v14; // edi
  int v15; // edx
  float *v16; // eax
  int v17; // eax
  bool v18; // zf
  int v19; // edx
  int v20; // eax
  int v21; // esi
  int v22; // edi
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  int v26; // eax
  float v27; // ecx
  unsigned __int8 v29; // c0
  unsigned __int8 v30; // c2
  unsigned __int8 v32; // c0
  unsigned __int8 v33; // c2
  unsigned __int8 v35; // c0
  unsigned __int8 v36; // c2
  int v37; // ecx
  int v38; // ecx
  int v39; // edx
  int v40; // eax
  int v41; // eax
  int v42; // eax
  _DWORD *v43; // ecx
  int v44; // edi
  int v45; // edx
  int v46; // esi
  float *v47; // eax
  int v48; // eax
  double v49; // st5
  double v50; // st3
  double v51; // st4
  double v52; // st3
  long double v53; // st4
  int v55; // [esp+10h] [ebp-1D8h]
  float v56; // [esp+10h] [ebp-1D8h]
  float v57; // [esp+10h] [ebp-1D8h]
  int v58; // [esp+10h] [ebp-1D8h]
  float v59; // [esp+14h] [ebp-1D4h] BYREF
  float v60; // [esp+18h] [ebp-1D0h]
  float v61; // [esp+1Ch] [ebp-1CCh]
  float v62; // [esp+24h] [ebp-1C4h]
  double v63; // [esp+28h] [ebp-1C0h]
  double v64; // [esp+30h] [ebp-1B8h]
  double v65; // [esp+38h] [ebp-1B0h]
  double v66; // [esp+40h] [ebp-1A8h]
  double v67; // [esp+48h] [ebp-1A0h]
  double v68; // [esp+50h] [ebp-198h]
  double v69; // [esp+58h] [ebp-190h]
  double v70; // [esp+60h] [ebp-188h]
  double v71; // [esp+68h] [ebp-180h]
  long double v72; // [esp+70h] [ebp-178h]
  float v73[16]; // [esp+78h] [ebp-170h] BYREF
  double v74[9]; // [esp+B8h] [ebp-130h] BYREF
  double v75; // [esp+100h] [ebp-E8h] BYREF
  double v76; // [esp+108h] [ebp-E0h]
  double v77; // [esp+110h] [ebp-D8h]
  double v78; // [esp+118h] [ebp-D0h]
  double v79; // [esp+120h] [ebp-C8h]
  double v80; // [esp+128h] [ebp-C0h]
  double v81; // [esp+130h] [ebp-B8h]
  double v82; // [esp+138h] [ebp-B0h]
  double v83; // [esp+140h] [ebp-A8h]
  int v84; // [esp+148h] [ebp-A0h] BYREF
  _BYTE v85[64]; // [esp+14Ch] [ebp-9Ch] BYREF
  double v86[3]; // [esp+190h] [ebp-58h] BYREF
  float v87[16]; // [esp+1A8h] [ebp-40h] BYREF

  v3 = 0;
  v55 = 0;
  sub_5D7710((int)dword_FB27A8, a2, 2, 0);
  v5 = 0.0;
  v6 = *(_DWORD *)(a1 + 360);
  v68 = 0.0;
  v7 = 0.0;
  v67 = 0.0;
  v69 = 0.0;
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  v11 = 0.0;
  if ( v6 > 0 )
  {
    v12 = *(_DWORD **)(a1 + 364);
    v62 = 0.0;
    LODWORD(v63) = v6;
    do
    {
      if ( (int)v12[2] > 0 )
      {
        v13 = *(_DWORD *)(a1 + 364);
        LODWORD(v65) = *v12 & 1;
        LODWORD(v66) = *(_DWORD *)(v13 + LODWORD(v62) + 8);
        LODWORD(v64) = 0;
        v14 = 0;
        v15 = 0;
        do
        {
          if ( LODWORD(v65) )
          {
            v16 = (float *)(v3 + v12[3]);
          }
          else
          {
            v17 = v12[8];
            if ( (*(_BYTE *)v12 & 8) != 0 )
              v16 = (float *)(v14 + v17);
            else
              v16 = (float *)(v15 + v17);
          }
          v3 += 32;
          v14 += 88;
          v15 += 64;
          v8 = v8 + *v16 * *v16;
          v7 = v7 + v16[1] * v16[1];
          v5 = v5 + v16[2] * v16[2];
          v69 = *v16 * v16[1] + v69;
          v67 = *v16 * v16[2] + v67;
          v68 = v16[1] * v16[2] + v68;
          v11 = v11 + *v16;
          v10 = v10 + v16[1];
          v18 = LODWORD(v66) == 1;
          v9 = v9 + v16[2];
          --LODWORD(v66);
        }
        while ( !v18 );
        v3 = 0;
      }
      v19 = v12[2] + v55;
      v12 += 27;
      v18 = LODWORD(v63) == 1;
      v55 = v19;
      LODWORD(v62) += 108;
      --LODWORD(v63);
    }
    while ( !v18 );
  }
  v64 = 1.0 / (double)v55;
  v65 = v64 * v11;
  v66 = v64 * v10;
  v63 = v64 * v9;
  v67 = v64 * v67 - v63 * v65;
  v68 = v64 * v68 - v63 * v66;
  v75 = v64 * v8 - v65 * v65;
  v76 = v64 * v69 - v66 * v65;
  v77 = v67;
  v78 = v76;
  v79 = v64 * v7 - v66 * v66;
  v80 = v68;
  v81 = v67;
  v82 = v68;
  v83 = v64 * v5 - v63 * v63;
  sub_5D7A10(&v75, v86, (int)v74);
  v73[0] = v74[0];
  v73[1] = v74[3];
  v73[2] = v74[6];
  v73[4] = v74[1];
  v73[3] = 0.0;
  v73[7] = 0.0;
  v73[5] = v74[4];
  memset(&v73[11], 0, 16);
  v73[6] = v74[7];
  v73[8] = v74[2];
  v73[15] = 1.0;
  v84 = 1;
  v73[9] = v74[5];
  v73[10] = v74[8];
  qmemcpy(v85, v73, sizeof(v85));
  sub_5D71F0((float *)&v84, (int)v87);
  v20 = *(_DWORD *)(a1 + 360);
  v21 = 0;
  v69 = 9.99999995904e11;
  LODWORD(v65) = 0;
  v71 = 9.99999995904e11;
  v68 = 9.99999995904e11;
  v70 = -9.99999995904e11;
  v64 = -9.99999995904e11;
  v67 = -9.99999995904e11;
  v72 = 0.0;
  if ( v20 > 0 )
  {
    do
    {
      v22 = 0;
      if ( *(int *)(*(_DWORD *)(a1 + 364) + v21 + 8) > 0 )
      {
        LODWORD(v63) = 0;
        v62 = 0.0;
        v56 = 0.0;
        do
        {
          v23 = *(_DWORD *)(a1 + 364);
          v24 = *(_DWORD *)(v23 + v21);
          v25 = v21 + v23;
          if ( (v24 & 1) != 0 )
          {
            v26 = *(_DWORD *)(v25 + 12);
            v27 = v56;
          }
          else
          {
            v26 = *(_DWORD *)(v25 + 32);
            v18 = (v24 & 8) == 0;
            v27 = v62;
            if ( v18 )
              v27 = *(float *)&v63;
          }
          sub_5D7810((float *)(LODWORD(v27) + v26), &v59, v87);
          if ( v29 | v30 )
          {
            v68 = v59;
          }
          else if ( v59 > v67 )
          {
            v67 = v59;
          }
          if ( v32 | v33 )
          {
            v71 = v60;
          }
          else if ( v60 > v64 )
          {
            v64 = v60;
          }
          if ( v35 | v36 )
          {
            v69 = v61;
          }
          else if ( v61 > v70 )
          {
            v70 = v61;
          }
          LODWORD(v62) += 88;
          LODWORD(v56) += 32;
          v37 = *(_DWORD *)(*(_DWORD *)(a1 + 364) + v21 + 8);
          ++v22;
          LODWORD(v63) += 64;
        }
        while ( v22 < v37 );
      }
      v38 = *(_DWORD *)(a1 + 360);
      v21 += 108;
      ++LODWORD(v65);
    }
    while ( SLODWORD(v65) < v38 );
  }
  v57 = v67;
  v59 = v57;
  *(float *)&v63 = v71;
  v60 = *(float *)&v63;
  *(float *)&v65 = v69;
  v61 = *(float *)&v65;
  sub_5D7810(&v59, (float *)(a1 + 24), v73);
  v62 = v70;
  v59 = v57;
  v61 = v62;
  v60 = *(float *)&v63;
  sub_5D7810(&v59, (float *)(a1 + 36), v73);
  *(float *)&v66 = v68;
  v59 = *(float *)&v66;
  v60 = *(float *)&v63;
  v61 = v62;
  sub_5D7810(&v59, (float *)(a1 + 48), v73);
  v59 = *(float *)&v66;
  v60 = *(float *)&v63;
  v61 = *(float *)&v65;
  sub_5D7810(&v59, (float *)(a1 + 60), v73);
  *(float *)&v63 = v64;
  v60 = *(float *)&v63;
  v59 = v57;
  v61 = *(float *)&v65;
  sub_5D7810(&v59, (float *)(a1 + 72), v73);
  v59 = v57;
  v60 = *(float *)&v63;
  v61 = v62;
  sub_5D7810(&v59, (float *)(a1 + 84), v73);
  v59 = *(float *)&v66;
  v60 = *(float *)&v63;
  v61 = v62;
  sub_5D7810(&v59, (float *)(a1 + 96), v73);
  v59 = *(float *)&v66;
  v60 = *(float *)&v63;
  v61 = *(float *)&v65;
  sub_5D7810(&v59, (float *)(a1 + 108), v73);
  if ( a3 )
  {
    v59 = (v67 + v68) * 0.5;
    v60 = (v64 + v71) * 0.5;
    v61 = (v70 + v69) * 0.5;
    sub_5D7810(&v59, (float *)(a1 + 216), v73);
    v40 = *(_DWORD *)(a1 + 392);
    if ( v40 )
    {
      sub_5D7810((float *)(a1 + 216), (float *)(a1 + 228), (float *)(v40 + 184));
    }
    else
    {
      v41 = *(_DWORD *)(a1 + 220);
      *(_DWORD *)(a1 + 228) = *(_DWORD *)(a1 + 216);
      v39 = *(_DWORD *)(a1 + 224);
      *(_DWORD *)(a1 + 232) = v41;
      *(_DWORD *)(a1 + 236) = v39;
    }
  }
  v42 = *(_DWORD *)(a1 + 360);
  if ( v42 > 0 )
  {
    v43 = *(_DWORD **)(a1 + 364);
    LODWORD(v66) = 0;
    v58 = v42;
    do
    {
      v44 = 0;
      if ( (int)v43[2] > 0 )
      {
        v45 = *(_DWORD *)(a1 + 364);
        LODWORD(v65) = *v43 & 1;
        LODWORD(v63) = *(_DWORD *)(LODWORD(v66) + v45 + 8);
        LODWORD(v64) = 0;
        v46 = 0;
        v39 = 0;
        do
        {
          if ( LODWORD(v65) )
          {
            v47 = (float *)(v46 + v43[3]);
          }
          else
          {
            v48 = v43[8];
            if ( (*(_BYTE *)v43 & 8) != 0 )
              v47 = (float *)(v44 + v48);
            else
              v47 = (float *)(v39 + v48);
          }
          v49 = *(float *)(a1 + 224) - v47[2];
          v50 = *(float *)(a1 + 220) - v47[1];
          v51 = v49 * v49 + v50 * v50;
          v52 = *(float *)(a1 + 216) - *v47;
          v53 = v51 + v52 * v52;
          if ( v72 <= v53 )
            v72 = v53;
          v46 += 32;
          v44 += 88;
          v39 += 64;
          --LODWORD(v63);
        }
        while ( LODWORD(v63) );
      }
      v43 += 27;
      v18 = v58 == 1;
      LODWORD(v66) += 108;
      --v58;
    }
    while ( !v18 );
  }
  *(float *)(a1 + 20) = sqrt(v72);
  return sub_5D7710((int)dword_FB27A8, v39, 1, 0);
}
