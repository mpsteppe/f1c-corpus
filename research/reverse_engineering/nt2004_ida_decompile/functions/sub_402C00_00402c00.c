int __thiscall sub_402C00(char *this, FILE *Stream)
{
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // eax
  float *v6; // eax
  double v7; // st7
  double v8; // st6
  int v9; // eax
  float *v10; // eax
  double v11; // st7
  double v12; // st6
  int v13; // eax
  float *v14; // eax
  double v15; // st7
  double v16; // st6
  int v17; // eax
  int v18; // esi
  int *v19; // eax
  _DWORD *v20; // ebx
  _DWORD *v21; // edi
  float *v22; // edi
  float *v23; // edi
  float *v24; // edi
  _DWORD *v25; // edi
  int v26; // edx
  int v27; // eax
  int result; // eax
  int v29; // esi
  int v30; // eax
  int v31; // edi
  _DWORD *v32; // eax
  _DWORD *v33; // ebx
  _DWORD *v34; // esi
  _DWORD *v35; // eax
  int v36; // edi
  int v37; // esi
  signed int i; // esi
  int v39; // [esp+10h] [ebp-350h] BYREF
  int v40; // [esp+14h] [ebp-34Ch] BYREF
  int v41; // [esp+18h] [ebp-348h]
  int v42; // [esp+1Ch] [ebp-344h] BYREF
  int v43; // [esp+20h] [ebp-340h] BYREF
  int v44; // [esp+24h] [ebp-33Ch] BYREF
  int v45; // [esp+28h] [ebp-338h] BYREF
  int v46; // [esp+2Ch] [ebp-334h] BYREF
  int v47; // [esp+30h] [ebp-330h] BYREF
  int v48; // [esp+34h] [ebp-32Ch] BYREF
  int v49; // [esp+38h] [ebp-328h] BYREF
  int v50; // [esp+3Ch] [ebp-324h] BYREF
  int v51; // [esp+40h] [ebp-320h]
  int v52; // [esp+44h] [ebp-31Ch] BYREF
  _BYTE v53[384]; // [esp+48h] [ebp-318h] BYREF
  int v54; // [esp+1C8h] [ebp-198h]
  char v55; // [esp+1CCh] [ebp-194h]
  int v56; // [esp+1D4h] [ebp-18Ch]
  int v57; // [esp+1D8h] [ebp-188h]
  int v58; // [esp+1DCh] [ebp-184h]
  char Str[384]; // [esp+1E0h] [ebp-180h] BYREF

  v3 = 0;
  memset(Str, 0, sizeof(Str));
  v54 = 0;
  v58 = 0;
  v56 = 0;
  v57 = 0;
  v55 = 1;
  v41 = 0;
  v51 = 0;
  sub_403B70(this);
  sub_403990(this);
  this[432] = 1;
  if ( !Stream )
    goto LABEL_116;
  while ( fgets(Str, 384, Stream) )
  {
    if ( strstr(Str, SubStr) )
    {
      while ( fgets(Str, 384, Stream) )
      {
        v4 = sub_577B60(v53);
        if ( v4 == 1 )
          break;
        if ( !v4 )
        {
          sub_578110(aPitlanes, (int)(this + 404), 0, 0, 0);
          sub_578110(aStartinggrid, (int)(this + 408), 0, 0, 0);
          if ( *((int *)this + 102) < 48 )
            *((_DWORD *)this + 102) = 48;
          sub_578110(aPitspots, (int)(this + 412), 0, 0, 0);
          if ( *((int *)this + 103) < 44 )
            *((_DWORD *)this + 103) = 44;
          sub_578110(aGaragespots, (int)(this + 416), 0, 0, 0);
          if ( *((int *)this + 104) < 1 )
            *((_DWORD *)this + 104) = 1;
        }
      }
      sub_403990(this);
    }
    if ( strstr(Str, aGrid) )
    {
      v39 = -1;
      while ( fgets(Str, 384, Stream) )
      {
        v5 = sub_577B60(v53);
        if ( v5 == 1 )
          break;
        if ( !v5 && !sub_578110(aGridindex, (int)&v39, 0, 0, 0) )
        {
          if ( !sub_578220(off_5FB72C, (int)&v48, (int)&v49, (int)&v50, 0, 0, 0, 0, 0) )
          {
            if ( !sub_578220(off_5FB728, (int)&v48, (int)&v49, (int)&v50, 0, 0, 0, 0, 0) || (unsigned int)v39 >= 0x30 )
              continue;
            v6 = (float *)(*((_DWORD *)this + 97) + 28 * v39 + 12);
            goto LABEL_26;
          }
          if ( (unsigned int)v39 < 0x30 )
          {
            v6 = (float *)(*((_DWORD *)this + 97) + 28 * v39);
LABEL_26:
            v7 = *(float *)&v50;
            v8 = *(float *)&v49;
            *v6 = *(float *)&v48;
            v6[1] = v8;
            v6[2] = v7;
          }
        }
      }
    }
    if ( strstr(Str, aTeleport) )
    {
      v39 = -1;
      while ( fgets(Str, 384, Stream) )
      {
        v9 = sub_577B60(v53);
        if ( v9 == 1 )
          break;
        if ( !v9 && !sub_578110(aGridindex, (int)&v39, 0, 0, 0) )
        {
          if ( !sub_578220(off_5FB72C, (int)&v45, (int)&v46, (int)&v47, 0, 0, 0, 0, 0) )
          {
            if ( !sub_578220(off_5FB728, (int)&v45, (int)&v46, (int)&v47, 0, 0, 0, 0, 0) || (unsigned int)v39 >= 0x30 )
              continue;
            v10 = (float *)(*((_DWORD *)this + 100) + 28 * v39 + 12);
            goto LABEL_39;
          }
          if ( (unsigned int)v39 < 0x30 )
          {
            v10 = (float *)(*((_DWORD *)this + 100) + 28 * v39);
LABEL_39:
            v11 = *(float *)&v47;
            v12 = *(float *)&v46;
            *v10 = *(float *)&v45;
            v10[1] = v12;
            v10[2] = v11;
          }
        }
      }
    }
    if ( strstr(Str, aPits) )
    {
      v39 = -1;
      while ( fgets(Str, 384, Stream) )
      {
        v13 = sub_577B60(v53);
        if ( v13 == 1 )
          break;
        if ( !v13 && !sub_578110(aTeamindex, (int)&v39, 0, 0, 0) )
        {
          if ( !sub_578220(aPitpos, (int)&v42, (int)&v43, (int)&v44, 0, 0, 0, 0, 0) )
          {
            if ( !sub_578220(aPitori, (int)&v42, (int)&v43, (int)&v44, 0, 0, 0, 0, 0) || (unsigned int)v39 >= 0x2C )
              continue;
            v14 = (float *)(28 * v39 + *((_DWORD *)this + 98) + 12);
            goto LABEL_52;
          }
          if ( (unsigned int)v39 < 0x2C )
          {
            v14 = (float *)(*((_DWORD *)this + 98) + 28 * v39);
LABEL_52:
            v15 = *(float *)&v44;
            v16 = *(float *)&v43;
            *v14 = *(float *)&v42;
            v14[1] = v16;
            v14[2] = v15;
          }
        }
      }
    }
    v17 = sub_577B60(v53);
    if ( v17 )
    {
      if ( v17 == 4 )
        break;
    }
    else
    {
      if ( sub_578110(aNumberWaypoint, (int)&v40, 0, 0, 0) )
      {
        v51 = v40;
        v18 = v40;
        v19 = (int *)operator new(348 * v40 + 4);
        if ( v19 )
        {
          v20 = v19 + 1;
          *v19 = v18;
          v21 = v19 + 1;
          if ( v18 - 1 >= 0 )
          {
            do
            {
              sub_528A00(v21);
              v21 += 87;
              --v18;
            }
            while ( v18 );
          }
          v3 = v20;
        }
        else
        {
          v3 = 0;
        }
        *((_DWORD *)this + 90) = v3;
        if ( v3 )
          *((_DWORD *)this + 89) = v40;
        v41 = 0;
      }
      else if ( !sub_578110(aPitlanepaths, (int)(this + 424), (int)(this + 428), 0, 0) )
      {
        if ( sub_578110(aLefthandedpits, (int)&v40, 0, 0, 0) )
        {
          this[432] = v40 != 0;
        }
        else
        {
          v22 = (float *)(this + 344);
          if ( sub_578220(aWorstadjust, (int)(this + 344), 0, 0, 0, 0, 0, 0, 0) )
          {
            if ( *v22 < 0.80000001 )
              *v22 = 0.80000001;
          }
          else if ( !sub_578220(aMidadjust, (int)(this + 348), 0, 0, 0, 0, 0, 0, 0) )
          {
            v23 = (float *)(this + 352);
            if ( sub_578220(aBestadjust, (int)(this + 352), 0, 0, 0, 0, 0, 0, 0) )
            {
              if ( *v23 > 1.2 )
                *v23 = 1.2;
            }
            else if ( !sub_578220(aAirange, (int)(this + 336), 0, 0, 0, 0, 0, 0, 0)
                   && !sub_578220(aLapLength, (int)(this + 368), 0, 0, 0, 0, 0, 0, 0)
                   && !sub_578220(aSector1Length, (int)(this + 372), 0, 0, 0, 0, 0, 0, 0)
                   && !sub_578220(aSector2Length, (int)(this + 376), 0, 0, 0, 0, 0, 0, 0)
                   && !sub_578220(aFueluse, (int)(this + 384), 0, 0, 0, 0, 0, 0, 0)
                   && !sub_578220(aTirewearmulti, (int)(this + 52), 0, 0, 0, 0, 0, 0, 0)
                   && !sub_578220(aSpeedoffset, (int)(this + 48), 0, 0, 0, 0, 0, 0, 0) )
            {
              if ( sub_578110(aTracktype, (int)&v40, 0, 0, 0) )
              {
                *((_DWORD *)this + 10) = v40;
              }
              else if ( sub_578110(aDelaypitcrewlo, (int)&v40, 0, 0, 0) )
              {
                *((_DWORD *)this + 9) = v40;
              }
              else if ( !sub_578220(aOutsideadjustm, (int)(this + 8), 0, 0, 0, 0, 0, 0, 0)
                     && !sub_578220(aInsideadjustme, (int)(this + 12), 0, 0, 0, 0, 0, 0, 0)
                     && !sub_578220(aGroovewidth, (int)(this + 56), 0, 0, 0, 0, 0, 0, 0)
                     && !sub_578220(aGrooveheight, (int)(this + 16), 0, 0, 0, 0, 0, 0, 0)
                     && !sub_578220(aGroovewidthwet, (int)(this + 60), 0, 0, 0, 0, 0, 0, 0) )
              {
                v24 = (float *)(this + 4);
                if ( sub_578220(aPacecarrelease, (int)this, (int)(this + 4), 0, 0, 0, 0, 0, 0) )
                {
                  if ( *(float *)this > 1.0 || *(float *)this < 0.0 || *v24 > 1.0 || *v24 < 0.0 )
                  {
                    *(_DWORD *)this = 1061997773;
                    *v24 = 0.87;
                  }
                }
              }
            }
          }
        }
      }
      if ( v3 )
      {
        sub_578110(aWpBranchid, (int)(v3 + 82), 0, 0, 0);
        sub_578220(aWpPath, (int)(v3 + 6), (int)(v3 + 10), 0, 0, 0, 0, 0, 0);
        sub_578220(aWpCheat, (int)(v3 + 84), 0, 0, 0, 0, 0, 0, 0);
        v25 = v3 + 85;
        if ( sub_578110(aWpWpse, (int)(v3 + 85), (int)&v40, 0, 0) )
        {
          if ( *v25 == 1 || *v25 == 7 )
          {
            *v25 = 1;
            v3[86] = &flt_7D74DC;
          }
          else
          {
            v3[86] = 0;
          }
          if ( *v25 == 1 )
            v3[24] = 2139095039;
        }
        if ( sub_578220(aWpPos, (int)v3, (int)(v3 + 1), (int)(v3 + 2), 0, 0, 0, 0, 0) )
        {
          v26 = v3[1];
          v27 = v3[2];
          v3[49] = *v3;
          v3[50] = v26;
          v3[51] = v27;
        }
        if ( *(_DWORD *)dword_7689CC == 6 )
          sub_578220(aWpAlpha, (int)(v3 + 76), 0, 0, 0, 0, 0, 0, 0);
        else
          sub_578220(aWpGalpha, (int)(v3 + 76), 0, 0, 0, 0, 0, 0, 0);
        sub_578110(aWpMarks, (int)(v3 + 77), 0, 0, 0);
        sub_578220(aWpGrooveLat, (int)(v3 + 78), 0, 0, 0, 0, 0, 0, 0);
        if ( sub_578220(aWpScore, (int)&v52, (int)(v3 + 29), 0, 0, 0, 0, 0, 0) )
          v3[28] = (__int64)*(float *)&v52;
        sub_578220(aWpPerp, (int)(v3 + 11), (int)(v3 + 12), (int)(v3 + 13), 0, 0, 0, 0, 0);
        sub_578220(aWpNormal, (int)(v3 + 14), (int)(v3 + 15), (int)(v3 + 16), 0, 0, 0, 0, 0);
        sub_578220(aWpWidth, (int)(v3 + 17), (int)(v3 + 18), (int)(v3 + 19), (int)(v3 + 20), 0, 0, 0, 0);
        sub_578220(aWpDwidth, (int)(v3 + 33), (int)(v3 + 34), (int)(v3 + 35), (int)(v3 + 36), 0, 0, 0, 0);
        sub_578110(aWpBitfields, (int)(v3 + 83), 0, 0, 0);
        sub_578110(aWpLockedlats, (int)(v3 + 9), 0, 0, 0);
        sub_578220(aWpStockcarlat, (int)(v3 + 7), (int)(v3 + 8), 0, 0, 0, 0, 0, 0);
        sub_578220(aWpTransitionla, (int)(v3 + 57), 0, 0, 0, 0, 0, 0, 0);
        sub_578220(aWpTranslat, (int)(v3 + 57), (int)(v3 + 58), 0, 0, 0, 0, 0, 0);
        sub_578110(aWpPitlane, (int)(v3 + 25), 0, 0, 0);
        result = sub_578110(aWpPtrs, (int)(v3 + 79), (int)(v3 + 80), (int)(v3 + 81), 0);
        if ( result )
        {
          v29 = v41;
          if ( v41 >= *((_DWORD *)this + 89) )
            return result;
          v30 = *((_DWORD *)this + 90);
          ++v41;
          v3 = (_DWORD *)(v30 + 348 * (v29 + 1));
        }
      }
    }
  }
  if ( !v51 )
  {
LABEL_116:
    v31 = 2;
    *((_DWORD *)this + 89) = 2;
    v32 = operator new(0x2BCu);
    if ( v32 )
    {
      v33 = v32 + 1;
      *v32 = 2;
      v34 = v32 + 1;
      do
      {
        sub_528A00(v34);
        v34 += 87;
        --v31;
      }
      while ( v31 );
      v35 = v33;
    }
    else
    {
      v35 = 0;
    }
    *((_DWORD *)this + 90) = v35;
    v35[80] = 1;
    *(_DWORD *)(*((_DWORD *)this + 90) + 316) = 1;
    *(_DWORD *)(*((_DWORD *)this + 90) + 324) = -1;
    *(_DWORD *)(*((_DWORD *)this + 90) + 552) = 1065353216;
    *(_DWORD *)(*((_DWORD *)this + 90) + 668) = 0;
    *(_DWORD *)(*((_DWORD *)this + 90) + 664) = 0;
    *(_DWORD *)(*((_DWORD *)this + 90) + 672) = -1;
  }
  sub_403BE0(this);
  v36 = v41;
  if ( v41 > 0 )
  {
    v37 = 0;
    do
    {
      sub_528B80(v37 + *((_DWORD *)this + 90));
      v37 += 348;
      --v36;
    }
    while ( v36 );
  }
  result = NumOfElements;
  for ( i = 0; i < (int)NumOfElements; ++i )
  {
    if ( dword_75AAD0[i] )
      sub_42D500();
    result = NumOfElements;
  }
  return result;
}
