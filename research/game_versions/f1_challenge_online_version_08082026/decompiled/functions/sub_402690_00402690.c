int __thiscall sub_402690(int this, int a2)
{
  int v3; // esi
  _DWORD *v4; // esi
  int v5; // eax
  int v6; // eax
  float *v7; // eax
  double v8; // st7
  double v9; // st6
  int v10; // eax
  double v11; // st7
  double v12; // st6
  float *v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // esi
  _DWORD *v18; // eax
  int v19; // esi
  _DWORD *v20; // ebx
  _DWORD *v21; // edi
  int v22; // esi
  float *v23; // edi
  float *v24; // edi
  int v25; // edx
  int v26; // eax
  int result; // eax
  int v28; // esi
  int v29; // eax
  int v30; // ebx
  _DWORD *v31; // eax
  _DWORD *v32; // edi
  int v33; // eax
  int v34; // edi
  float v35; // [esp+10h] [ebp-364h] BYREF
  float v36; // [esp+14h] [ebp-360h] BYREF
  unsigned int v37; // [esp+18h] [ebp-35Ch] BYREF
  int v38; // [esp+1Ch] [ebp-358h] BYREF
  float v39; // [esp+20h] [ebp-354h] BYREF
  float v40; // [esp+24h] [ebp-350h] BYREF
  float v41; // [esp+28h] [ebp-34Ch] BYREF
  float v42; // [esp+2Ch] [ebp-348h] BYREF
  float v43; // [esp+30h] [ebp-344h] BYREF
  float v44; // [esp+34h] [ebp-340h] BYREF
  float v45; // [esp+38h] [ebp-33Ch] BYREF
  int v46; // [esp+3Ch] [ebp-338h]
  int v47; // [esp+40h] [ebp-334h]
  float v48; // [esp+44h] [ebp-330h] BYREF
  float v49; // [esp+48h] [ebp-32Ch] BYREF
  float v50; // [esp+4Ch] [ebp-328h] BYREF
  float v51; // [esp+50h] [ebp-324h] BYREF
  int v52; // [esp+54h] [ebp-320h]
  int v53; // [esp+58h] [ebp-31Ch]
  _BYTE v54[384]; // [esp+5Ch] [ebp-318h] BYREF
  int v55; // [esp+1DCh] [ebp-198h]
  char v56; // [esp+1E0h] [ebp-194h]
  int v57; // [esp+1E8h] [ebp-18Ch]
  int v58; // [esp+1ECh] [ebp-188h]
  int v59; // [esp+1F0h] [ebp-184h]
  _BYTE v60[384]; // [esp+1F4h] [ebp-180h] BYREF

  v3 = 0;
  memset(v60, 0, sizeof(v60));
  v55 = 0;
  v59 = 0;
  v57 = 0;
  v58 = 0;
  v56 = 1;
  v47 = 0;
  v52 = 0;
  sub_4034D0(this);
  sub_403350(this);
  *(_BYTE *)(this + 300) = 0;
  if ( !a2 )
    goto LABEL_98;
  v4 = (_DWORD *)v46;
  while ( sub_587CA0(v60, 384, a2) )
  {
    if ( sub_587C20(v60, aFeatures) )
    {
      while ( sub_587CA0(v60, 384, a2) )
      {
        v5 = sub_5651B0(v54);
        if ( v5 == 1 )
          break;
        if ( !v5 )
        {
          sub_565760(aPitlanes, this + 348, 0, 0, 0);
          sub_565760(aStartinggrid, this + 352, 0, 0, 0);
          if ( *(int *)(this + 352) < 104 )
            *(_DWORD *)(this + 352) = 104;
          sub_565760(aPitspots, this + 356, 0, 0, 0);
          if ( *(int *)(this + 356) < 52 )
            *(_DWORD *)(this + 356) = 52;
          sub_565760(aGaragespots, this + 360, 0, 0, 0);
          if ( *(int *)(this + 360) < 3 )
            *(_DWORD *)(this + 360) = 3;
        }
      }
      sub_403350(this);
    }
    if ( sub_587C20(v60, aGrid) )
    {
      v37 = -1;
      while ( sub_587CA0(v60, 384, a2) )
      {
        v6 = sub_5651B0(v54);
        if ( v6 == 1 )
          break;
        if ( !v6 && !sub_565760(aGridindex, &v37, 0, 0, 0) )
        {
          if ( !sub_565870(&off_5BE638, &v48, &v49, &v50, 0, 0, 0, 0, 0) )
          {
            if ( !sub_565870(&off_5BE634, &v48, &v49, &v50, 0, 0, 0, 0, 0) || v37 >= 0x68 )
              continue;
            v7 = (float *)(*(_DWORD *)(this + 336) + 28 * v37 + 12);
            goto LABEL_27;
          }
          if ( v37 < 0x68 )
          {
            v7 = (float *)(*(_DWORD *)(this + 336) + 28 * v37);
LABEL_27:
            v8 = v50;
            v9 = v49;
            *v7 = v48;
            v7[1] = v9;
            v7[2] = v8;
          }
        }
      }
    }
    if ( sub_587C20(v60, aPits_1) )
    {
      v37 = -1;
      while ( sub_587CA0(v60, 384, a2) )
      {
        v10 = sub_5651B0(v54);
        if ( v10 == 1 )
          break;
        if ( !v10 && !sub_565760(aTeamindex, &v37, 0, 0, 0) )
        {
          if ( sub_565870(aPitpos, &v40, &v41, &v42, 0, 0, 0, 0, 0) )
          {
            if ( v37 < 0x34 )
            {
              v11 = v42;
              v12 = v41;
              v13 = (float *)(*(_DWORD *)(this + 340) + 28 * v37);
LABEL_44:
              *v13 = v40;
              v13[1] = v12;
              v13[2] = v11;
            }
          }
          else if ( sub_565870(aPitori, &v40, &v41, &v42, 0, 0, 0, 0, 0) )
          {
            if ( v37 < 0x34 )
            {
              v11 = v42;
              v12 = v41;
              v13 = (float *)(28 * v37 + *(_DWORD *)(this + 340) + 12);
              goto LABEL_44;
            }
          }
          else
          {
            if ( sub_565870(aGarpos, &v51, &v40, &v41, &v42, 0, 0, 0, 0) )
            {
              v11 = v42;
              v12 = v41;
              v14 = sub_587BDC(v42);
              v13 = (float *)(*(_DWORD *)(this + 344) + 28 * (v37 + v14 * *(_DWORD *)(this + 356)));
              goto LABEL_44;
            }
            if ( sub_565870(aGarori, &v51, &v40, &v41, &v42, 0, 0, 0, 0) )
            {
              v11 = v42;
              v12 = v41;
              v15 = sub_587BDC(v42);
              v13 = (float *)(28 * (v37 + v15 * *(_DWORD *)(this + 356)) + *(_DWORD *)(this + 344) + 12);
              goto LABEL_44;
            }
          }
        }
      }
    }
    v16 = sub_5651B0(v54);
    if ( v16 )
    {
      if ( v16 == 4 )
        break;
    }
    else
    {
      if ( sub_565760(aNumberWaypoint, &v38, 0, 0, 0) )
      {
        v52 = v38;
        v17 = v38;
        v18 = (_DWORD *)sub_587C03(316 * v38 + 4);
        if ( v18 )
        {
          *v18 = v17;
          v19 = v17 - 1;
          v20 = v18 + 1;
          v21 = v18 + 1;
          if ( v19 >= 0 )
          {
            v22 = v19 + 1;
            do
            {
              sub_4FAD80(v21);
              v21 += 79;
              --v22;
            }
            while ( v22 );
          }
          v4 = v20;
        }
        else
        {
          v4 = 0;
        }
        *(_DWORD *)(this + 308) = v4;
        if ( v4 )
          *(_DWORD *)(this + 304) = v38;
        v47 = 0;
      }
      else if ( sub_565760(aLefthandedpits, &v38, 0, 0, 0) )
      {
        *(_BYTE *)(this + 300) = v38 != 0;
      }
      else
      {
        v23 = (float *)(this + 284);
        if ( sub_565870(aWorstadjust, this + 284, 0, 0, 0, 0, 0, 0, 0) )
        {
          if ( *v23 < 0.5 )
            *v23 = 0.5;
        }
        else if ( !sub_565870(aMidadjust, this + 288, 0, 0, 0, 0, 0, 0, 0) )
        {
          v24 = (float *)(this + 292);
          if ( sub_565870(aBestadjust, this + 292, 0, 0, 0, 0, 0, 0, 0) )
          {
            if ( *v24 > 1.3 )
              *v24 = 1.3;
          }
          else if ( !sub_565870(aRacequalratio, this + 296, 0, 0, 0, 0, 0, 0, 0)
                 && !sub_565870(aLapLength, this + 316, 0, 0, 0, 0, 0, 0, 0)
                 && !sub_565870(aSector1Length, this + 320, 0, 0, 0, 0, 0, 0, 0)
                 && !sub_565870(aSector2Length, this + 324, 0, 0, 0, 0, 0, 0, 0)
                 && !sub_565870(aFueluse, this + 332, 0, 0, 0, 0, 0, 0, 0)
                 && !sub_565870(aGroovewidth, this, 0, 0, 0, 0, 0, 0, 0)
                 && !sub_565870(aGroovewidthwet, this + 4, 0, 0, 0, 0, 0, 0, 0) )
          {
            if ( sub_565870(aIntermediatefo, &v35, 0, 0, 0, 0, 0, 0, 0) )
            {
              sub_4FEFC0(LODWORD(v35));
            }
            else if ( sub_565870(aIntermediatefo_0, &v35, &v36, 0, 0, 0, 0, 0, 0) )
            {
              flt_8AFFA4 = v35;
              flt_8AFFA8 = v36;
            }
            else if ( sub_565870(aRainyfogplanes, &v35, &v36, 0, 0, 0, 0, 0, 0) )
            {
              flt_8AFFB0 = v35;
              flt_8AFFB4 = v36;
            }
            else if ( sub_565870(aIntermediatefo_1, &v35, &v36, &v39, 0, 0, 0, 0, 0) )
            {
              flt_8AFF80 = v35 * 0.0039215689;
              flt_8AFF84 = v36 * 0.0039215689;
              flt_8AFF88 = v39 * 0.0039215689;
            }
            else if ( sub_565870(aRainyfogcolor, &v35, &v36, &v39, 0, 0, 0, 0, 0) )
            {
              flt_8AFF8C = v35 * 0.0039215689;
              flt_8AFF90 = v36 * 0.0039215689;
              flt_8AFF94 = v39 * 0.0039215689;
            }
            else if ( sub_565870(aFogdensity_0, &v35, &v36, 0, 0, 0, 0, 0, 0) )
            {
              flt_8AFFAC = v35;
              flt_8AFFB8 = v36;
            }
            else if ( sub_565870(aRainydarkness, &v35, &v36, 0, 0, 0, 0, 0, 0) )
            {
              sub_4FF040(v35, v36);
            }
          }
        }
      }
      sub_565760(aWpBranchid, v4 + 75, 0, 0, 0);
      sub_565870(aWpPath, v4 + 6, v4 + 7, 0, 0, 0, 0, 0, 0);
      if ( sub_565870(aWpEvent, v4 + 33, &v44, &v45, 0, 0, 0, 0, 0) )
      {
        v53 = (int)v44;
        v4[77] = v53;
        v46 = (int)v45;
        v4[78] = v46;
      }
      sub_565760(aWpWpse, v4 + 77, v4 + 78, 0, 0);
      if ( sub_565870(aWpPos, v4, v4 + 1, v4 + 2, 0, 0, 0, 0, 0) )
      {
        v25 = v4[1];
        v26 = v4[2];
        v4[37] = *v4;
        v4[38] = v25;
        v4[39] = v26;
      }
      sub_565870(aWpGalpha, v4 + 70, 0, 0, 0, 0, 0, 0, 0);
      sub_565870(aWpGrooveLat, v4 + 71, 0, 0, 0, 0, 0, 0, 0);
      if ( sub_565870(aWpScore, &v43, v4 + 18, 0, 0, 0, 0, 0, 0) )
        v4[17] = sub_587BDC(v43);
      sub_565870(aWpPerp, v4 + 8, v4 + 9, v4 + 10, 0, 0, 0, 0, 0);
      sub_565870(aWpWidth, v4 + 11, v4 + 12, v4 + 13, v4 + 14, 0, 0, 0, 0);
      sub_565870(aWpDwidth, v4 + 22, v4 + 23, v4 + 24, v4 + 25, 0, 0, 0, 0);
      sub_565760(aWpBitfields, v4 + 76, 0, 0, 0);
      result = sub_565760(aWpPtrs, v4 + 72, v4 + 73, v4 + 74, 0);
      if ( result )
      {
        v28 = v47;
        if ( v47 >= *(_DWORD *)(this + 304) )
          return result;
        v29 = *(_DWORD *)(this + 308);
        ++v47;
        v4 = (_DWORD *)(v29 + 316 * (v28 + 1));
      }
    }
  }
  v3 = 0;
  if ( !v52 )
  {
LABEL_98:
    v30 = 2;
    *(_DWORD *)(this + 304) = 2;
    v31 = (_DWORD *)sub_587C03(636);
    if ( v31 )
    {
      *v31 = 2;
      v46 = (int)(v31 + 1);
      v32 = v31 + 1;
      do
      {
        sub_4FAD80(v32);
        v32 += 79;
        --v30;
      }
      while ( v30 );
      v33 = v46;
    }
    else
    {
      v33 = 0;
    }
    *(_DWORD *)(this + 308) = v33;
    *(_DWORD *)(v33 + 292) = 1;
    *(_DWORD *)(*(_DWORD *)(this + 308) + 288) = 1;
    *(_DWORD *)(*(_DWORD *)(this + 308) + 296) = -1;
    *(_DWORD *)(*(_DWORD *)(this + 308) + 472) = 1065353216;
    *(_DWORD *)(*(_DWORD *)(this + 308) + 608) = 0;
    *(_DWORD *)(*(_DWORD *)(this + 308) + 604) = 0;
    *(_DWORD *)(*(_DWORD *)(this + 308) + 612) = -1;
  }
  result = sub_403540(this);
  v34 = v47;
  if ( v47 > 0 )
  {
    do
    {
      result = sub_4FAEC0(v3 + *(_DWORD *)(this + 308));
      v3 += 316;
      --v34;
    }
    while ( v34 );
  }
  return result;
}
