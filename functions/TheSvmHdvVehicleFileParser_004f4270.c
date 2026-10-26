int __thiscall sub_4F4270(int this, const char *a2, int a3, char a4)
{
  int v5; // edi
  void *v6; // eax
  bool v7; // zf
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  _BYTE *v11; // ecx
  int v13; // eax
  int v14; // edi
  char *v15; // eax
  int v16; // ecx
  char *i; // eax
  char *v18; // eax
  char *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // ecx
  char *j; // eax
  int v27; // eax
  int v28; // eax
  int v29; // edi
  int v30; // ecx
  char *k; // eax
  int v32; // edi
  char *v33; // eax
  char *v34; // eax
  double v35; // st7
  int v36; // eax
  int v37; // ecx
  char *m; // eax
  char *v39; // eax
  char *v40; // eax
  int v41; // eax
  _BYTE *v42; // ecx
  _BYTE *v43; // edx
  int v44; // ecx
  int v45; // eax
  int v46; // ecx
  _DWORD *v47; // edx
  int *v48; // edi
  double v49; // st7
  int v50; // eax
  int v51; // eax
  double v52; // st7
  int v53; // eax
  int v54; // [esp+Ch] [ebp-594h]
  char v55; // [esp+13h] [ebp-58Dh]
  int v56; // [esp+14h] [ebp-58Ch]
  LPVOID v57[2]; // [esp+18h] [ebp-588h] BYREF
  float v58; // [esp+20h] [ebp-580h]
  _BYTE v59[4]; // [esp+24h] [ebp-57Ch] BYREF
  int v60; // [esp+28h] [ebp-578h]
  int v61; // [esp+2Ch] [ebp-574h]
  int v62; // [esp+30h] [ebp-570h]
  int v63; // [esp+34h] [ebp-56Ch] BYREF
  _DWORD v64[2]; // [esp+38h] [ebp-568h] BYREF
  int v65; // [esp+40h] [ebp-560h]
  int v66; // [esp+44h] [ebp-55Ch] BYREF
  int v67[97]; // [esp+48h] [ebp-558h] BYREF
  char v68; // [esp+1CCh] [ebp-3D4h]
  int v69; // [esp+1D4h] [ebp-3CCh]
  int v70; // [esp+1D8h] [ebp-3C8h]
  int v71; // [esp+1DCh] [ebp-3C4h]
  _BYTE v72[384]; // [esp+1E0h] [ebp-3C0h] BYREF
  _BYTE v73[29]; // [esp+360h] [ebp-240h] BYREF
  __int16 v74; // [esp+37Dh] [ebp-223h]
  char v75; // [esp+37Fh] [ebp-221h]
  _DWORD v76[8]; // [esp+380h] [ebp-220h] BYREF
  char v77[256]; // [esp+3A0h] [ebp-200h] BYREF
  char v78[256]; // [esp+4A0h] [ebp-100h] BYREF

  memset(v72, 0, sizeof(v72));
  v67[96] = 0;
  v71 = 0;
  v69 = 0;
  v70 = 0;
  v68 = 1;
  v57[0] = 0;
  v57[1] = (LPVOID)-1;
  v5 = sub_534B00(a2, aRb);
  v56 = v5;
  if ( !v5 )
  {
    v6 = v57[0];
    v7 = v57[0] == 0;
LABEL_38:
    if ( !v7 )
      FreeWrapper_7bcf(v6);
    return -1;
  }
  v65 = a4 & 1;
  if ( (a4 & 1) != 0 )
  {
    if ( LineInputReader(384) )
    {
      while ( 1 )
      {
        if ( !sub_5651B0(v67) )
        {
          v8 = sub_589DB0(v72, 61);
          if ( v8 )
          {
            if ( sub_587C20(v72, aSetting) != v8 - 7
              && (_BYTE *)sub_587C20(v72, aNotes) != v72
              && (_BYTE *)sub_587C20(v72, aDownforce) != v72
              && (_BYTE *)sub_587C20(v72, aBalance) != v72
              && (_BYTE *)sub_587C20(v72, aRide) != v72
              && (_BYTE *)sub_587C20(v72, aGearing) != v72
              && (_BYTE *)sub_587C20(v72, aCustom) != v72
              && (_BYTE *)sub_587C20(v72, aSymmetric) != v72 )
            {
              break;
            }
          }
        }
        if ( !LineInputReader(384) )
          goto LABEL_16;
      }
      if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_7, 730) )
        DebugLogWrite((int)dword_8AD25C, (int)"%s is an illegal .SVM file", a2);
      StreamFileTypeCheckWithDispatch(v5);
      v6 = v57[0];
      v7 = v57[0] == 0;
      goto LABEL_38;
    }
LABEL_16:
    AudioStreamBufferRead(0);
  }
  StringCopyWithBufferRealloc(byte_5EA438);
  *(_BYTE *)(a3 + 6564) = 1;
  *(_BYTE *)(a3 + 6565) = 1;
  while ( LineInputReader(384) )
  {
    if ( !sub_5651B0(v67) )
    {
      if ( sub_587C20(v72, aGeneral) )
      {
        while ( LineInputReader(384) )
        {
          v9 = sub_5651B0(v67);
          if ( v9 == 1 )
            break;
          if ( !v9 )
          {
            if ( sub_565760(aRules, &v66, 0, 0, 0) )
            {
              v10 = v66;
              *(_DWORD *)(this + 52) = v66;
              *(_DWORD *)(a3 + 6544) = v10;
            }
            if ( sub_565760(aGaragedisplayf, this + 56, 0, 0, 0) )
              *(_DWORD *)(a3 + 6540) = *(_DWORD *)(this + 56);
            sub_565760(aFeelerflags, this + 60, 0, 0, 0);
            sub_565AA0(aMass, this + 64, 0, 0, 0);
            sub_565AA0(aInertia, this + 72, this + 80, this + 88, 0);
            sub_565AA0(aCgheight, this + 96, 0, 0, 0);
            if ( sub_565AA0(aWedgepushrod, this + 104, 0, 0, 0) )
              *(double *)(a3 + 6556) = *(double *)(this + 104);
            sub_565AA0(aGraphicaloffse, this + 112, this + 120, this + 128, 0);
            sub_565AA0(aFlundertray, this + 5192, this + 5200, this + 5208, 0);
            sub_565AA0(aFrundertray, this + 5456, this + 5464, this + 5472, 0);
            sub_565AA0(aRlundertray, this + 5720, this + 5728, this + 5736, 0);
            sub_565AA0(aRrundertray, this + 5984, this + 5992, this + 6000, 0);
            if ( sub_5654A0(aTirebrand, this + 136) )
            {
              v11 = (_BYTE *)(this + 136 + strlen((const char *)(this + 136)));
              if ( (unsigned int)v11 > this + 136 )
              {
                while ( *v11 != 46 )
                {
                  if ( (unsigned int)--v11 <= this + 136 )
                    goto LABEL_42;
                }
                *v11 = 0;
              }
LABEL_42:
              NameStringCopy((char *)a3, this + 136);
              v13 = TireBrandLookup(&dword_8AD254, this + 136);
              v14 = v13;
              if ( v13 )
              {
                *(_DWORD *)(a3 + 3008) = *(_DWORD *)(v13 + 16);
                v15 = *(char **)(v13 + 24);
                if ( !v15 )
                  v15 = byte_5EA438;
                StringCopyWithBufferRealloc(v15);
                *(_DWORD *)(this + 8) = *(_DWORD *)(v14 + 32) + 537133609;
              }
              else if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_7, 820) )
              {
                DebugLogWrite(
                  (int)dword_8AD25C,
                  (int)"*.hdv file references unknown tire compound \"%s\"",
                  (const char *)(this + 136));
              }
            }
            sub_565AA0(aFueltankpos, this + 200, this + 208, this + 216, 0);
            sub_565AA0(aFueltankmotion, this + 224, this + 232, 0, 0);
            sub_565760(aAiminpassesper, this + 240, 0, 0, 0);
            sub_565AA0(aAirotationthre, this + 244, 0, 0, 0);
            sub_565AA0(aAievensuspensi, this + 252, 0, 0, 0);
            sub_565AA0(aAispringrate, this + 260, 0, 0, 0);
            sub_565AA0(aAidamperslow, this + 268, 0, 0, 0);
            sub_565AA0(aAidamperfast, this + 276, 0, 0, 0);
            sub_565AA0(aAidownforcezar, this + 284, 0, 0, 0);
            sub_565AA0(aAidownforcebia, this + 292, 0, 0, 0);
            sub_565AA0(aAitorquestab, this + 300, this + 308, this + 316, 0);
            if ( sub_5654A0(aNotes_0, v78) )
              sub_5665B0(v78);
            if ( sub_565760(aSymmetric_0, &v63, 0, 0, 0) )
              *(_BYTE *)(a3 + 6565) = v63 != 0;
            if ( sub_5654A0(aDamagefile, v78) )
            {
              strcpy(v77, a2);
              v16 = strlen(v77);
              if ( v16 > 0 )
              {
                for ( i = (char *)&v76[7] + v16 + 3; i >= v77; *i-- = 0 )
                {
                  if ( *i == 92 )
                    break;
                }
              }
              if ( !FileFinder(v78, aIni, v77, (int)v57) )
              {
                if ( (a4 & 2) == 0 )
                {
                  v18 = (char *)v57[0];
                  if ( !v57[0] )
                    v18 = byte_5EA438;
                  VehicleDamageModel((char *)(this + 6128), (int)v18);
                }
                v19 = (char *)v57[0];
                if ( !v57[0] )
                  v19 = byte_5EA438;
                StringCopyWithBufferRealloc(v19);
              }
            }
            CRTMathHelper_e1f0((char *)(a3 + 3056), (int)v67, (int)aCgrightrange, (int)aCgrightsetting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 3120), (int)v67, (int)aCgrearrange, (int)aCgrearsetting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 3184), (int)v67, (int)aWedgerange, (int)aWedgesetting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 2992), (int)v67, 0, (int)aTirecompoundse, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 3248), (int)v67, (int)aFuelrange, (int)aFuelsetting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 6256), (int)v67, (int)aNumpitstopsran, (int)aNumpitstopsset, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 6320), (int)v67, (int)aPitstop1range, (int)aPitstop1settin, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 6384), (int)v67, (int)aPitstop2range, (int)aPitstop2settin, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 6448), (int)v67, (int)aPitstop3range, (int)aPitstop3settin, 1.0);
            v5 = v56;
          }
        }
      }
      else if ( sub_587C20(v72, aFrontwing) )
      {
        while ( LineInputReader(384) )
        {
          v20 = sub_5651B0(v67);
          if ( v20 == 1 )
            break;
          if ( !v20 )
          {
            if ( sub_565AA0(aFwdragparams, this + 504, this + 512, this + 520, 0) )
              *(_BYTE *)(this + 492) = 1;
            sub_565AA0(aFwliftparams, this + 528, this + 536, this + 544, 0);
            sub_565AA0(aFwmaxheight, this + 496, 0, 0, 0);
            sub_565AA0(aFwliftheight, this + 552, 0, 0, 0);
            sub_565AA0(aFwliftsideways, this + 560, 0, 0, 0);
            VehicleDampingDirectionValidation((char *)(this + 568), (int)v67, 0, (int)aFwleft);
            VehicleDampingDirectionValidation((char *)(this + 568), (int)v67, 1, (int)aFwright);
            VehicleDampingDirectionValidation((char *)(this + 568), (int)v67, 2, (int)aFwup);
            VehicleDampingDirectionValidation((char *)(this + 568), (int)v67, 3, (int)aFwdown);
            VehicleDampingDirectionValidation((char *)(this + 568), (int)v67, 4, (int)aFwaft);
            VehicleDampingDirectionValidation((char *)(this + 568), (int)v67, 5, (int)aFwfore);
            ArithmeticComparison_3490((long double *)(this + 568), (int)v67, (int)aFwrot);
            sub_565AA0(aFwcenter, this + 736, this + 744, this + 752, 0);
            CRTMathHelper_e1f0((char *)(a3 + 4720), (int)v67, (int)aFwrange, (int)aFwsetting, 1.0);
            v5 = v56;
          }
        }
      }
      else if ( sub_587C20(v72, aLeftfender) )
      {
        FenderAeroSetupSectionReader((_BYTE *)(this + 324), 9, v5, (int)v67, a3);
      }
      else if ( sub_587C20(v72, aRightfender) )
      {
        FenderAeroSetupSectionReader((_BYTE *)(this + 408), 10, v5, (int)v67, a3);
      }
      else if ( sub_587C20(v72, aRearwing) )
      {
        while ( LineInputReader(384) )
        {
          v21 = sub_5651B0(v67);
          if ( v21 == 1 )
            break;
          if ( !v21 )
          {
            if ( sub_565AA0(aRwdragparams, this + 764, this + 772, this + 780, 0) )
              *(_BYTE *)(this + 760) = 1;
            sub_565AA0(aRwliftparams, this + 788, this + 796, this + 804, 0);
            sub_565AA0(aRwliftsideways, this + 812, 0, 0, 0);
            VehicleDampingDirectionValidation((char *)(this + 820), (int)v67, 0, (int)aRwleft);
            VehicleDampingDirectionValidation((char *)(this + 820), (int)v67, 1, (int)aRwright);
            VehicleDampingDirectionValidation((char *)(this + 820), (int)v67, 2, (int)aRwup);
            VehicleDampingDirectionValidation((char *)(this + 820), (int)v67, 3, (int)aRwdown);
            VehicleDampingDirectionValidation((char *)(this + 820), (int)v67, 4, (int)aRwaft);
            VehicleDampingDirectionValidation((char *)(this + 820), (int)v67, 5, (int)aRwfore);
            ArithmeticComparison_3490((long double *)(this + 820), (int)v67, (int)aRwrot);
            sub_565AA0(aRwcenter, this + 988, this + 996, this + 1004, 0);
            CRTMathHelper_e1f0((char *)(a3 + 4784), (int)v67, (int)aRwrange, (int)aRwsetting, 1.0);
            v5 = v56;
          }
        }
      }
      else if ( sub_587C20(v72, aBodyaero) )
      {
        while ( LineInputReader(384) )
        {
          v22 = sub_5651B0(v67);
          if ( v22 == 1 )
            break;
          if ( !v22 )
          {
            sub_565AA0(aBodydragbase, this + 1012, 0, 0, 0);
            sub_565AA0(aBodydragheight, this + 1020, 0, 0, 0);
            sub_565AA0(aBodydragheight_0, this + 1028, 0, 0, 0);
            sub_565AA0(aBodymaxheight, this + 1036, 0, 0, 0);
            VehicleDampingDirectionValidation((char *)(this + 1068), (int)v67, 0, (int)aBodyleft);
            VehicleDampingDirectionValidation((char *)(this + 1068), (int)v67, 1, (int)aBodyright);
            VehicleDampingDirectionValidation((char *)(this + 1068), (int)v67, 2, (int)aBodyup);
            VehicleDampingDirectionValidation((char *)(this + 1068), (int)v67, 3, (int)aBodydown);
            VehicleDampingDirectionValidation((char *)(this + 1068), (int)v67, 4, (int)aBodyaft);
            VehicleDampingDirectionValidation((char *)(this + 1068), (int)v67, 5, (int)aBodyfore);
            ArithmeticComparison_3490((long double *)(this + 1068), (int)v67, (int)aBodyrot);
            sub_565AA0(aBodycenter, this + 1044, this + 1052, this + 1060, 0);
            sub_565AA0(aRadiatordrag, this + 1304, 0, 0, 0);
            sub_565AA0(aRadiatorlift, this + 1312, 0, 0, 0);
            CRTMathHelper_e1f0((char *)(a3 + 4848), (int)v67, (int)aRadiatorrange, (int)aRadiatorsettin, 1.0);
            sub_565AA0(aBrakeductdrag, this + 1320, 0, 0, 0);
            sub_565AA0(aBrakeductlift, this + 1328, 0, 0, 0);
            CRTMathHelper_e1f0((char *)(a3 + 4912), (int)v67, (int)aBrakeductrange, (int)aBrakeductsetti, 1.0);
            v5 = v56;
          }
        }
      }
      else if ( sub_587C20(v72, aDiffuser) )
      {
        while ( LineInputReader(384) )
        {
          v23 = sub_5651B0(v67);
          if ( v23 == 1 )
            break;
          if ( !v23 )
          {
            if ( sub_565AA0(aDiffuserbase, this + 1240, this + 1248, this + 1256, 0) )
              *(_BYTE *)(this + 1236) = 1;
            sub_565AA0(aDiffuserfronth, this + 1264, 0, 0, 0);
            sub_565AA0(aDiffusersidewa, this + 1272, 0, 0, 0);
            sub_565AA0(aDiffusercenter, this + 1280, this + 1288, this + 1296, 0);
          }
        }
      }
      else if ( sub_587C20(v72, aSuspension_1) )
      {
        while ( LineInputReader(384) )
        {
          v24 = sub_5651B0(v67);
          if ( v24 == 1 )
            break;
          if ( !v24 )
          {
            if ( sub_5654A0(aPhysicalmodelf, v78) )
            {
              strcpy(v77, a2);
              v25 = strlen(v77);
              if ( v25 > 0 )
              {
                for ( j = (char *)&v76[7] + v25 + 3; j >= v77; *j-- = 0 )
                {
                  if ( *j == 92 )
                    break;
                }
              }
              FileFinder(v78, (const char *)&off_5D6164, v77, this + 44);
            }
            if ( sub_5655F0(aApplyslowtofas, this + 1352, 0, 0, 0) )
              *(_BYTE *)(a3 + 6536) = *(_BYTE *)(this + 1352);
            sub_5655F0(aAdjustsusprate, this + 1353, 0, 0, 0);
            sub_5655F0(aAlignwheels, this + 1354, 0, 0, 0);
            sub_565AA0(aFrontwheeltrac, this + 1356, 0, 0, 0);
            sub_565AA0(aRearwheeltrack, this + 1364, 0, 0, 0);
            sub_565AA0(aLeftwheelbase, this + 1372, 0, 0, 0);
            sub_565AA0(aRightwheelbase, this + 1380, 0, 0, 0);
            if ( sub_5655F0(aSpringbasedant, this + 1388, 0, 0, 0) )
              *(_BYTE *)(a3 + 6537) = *(_BYTE *)(this + 1388);
            sub_565AA0(aFrontantiswayb, this + 1392, 0, 0, 0);
            sub_565AA0(aFrontantiswayr, this + 1400, this + 1408, 0, 0);
            sub_565AA0(aRearantiswayba, this + 1416, 0, 0, 0);
            sub_565AA0(aRearantiswayra, this + 1424, this + 1432, 0, 0);
            sub_565AA0(aFront3rdbumptr, this + 1440, 0, 0, 0);
            sub_565AA0(aFront3rdreboun, this + 1448, 0, 0, 0);
            sub_565AA0(aFront3rdbumpst, this + 1456, 0, 0, 0);
            sub_565AA0(aFront3rdbumpst_0, this + 1464, 0, 0, 0);
            sub_565AA0(aFront3rdbumpst_1, this + 1472, 0, 0, 0);
            sub_565AA0(aFront3rdbumpst_2, this + 1480, 0, 0, 0);
            sub_565AA0(aFront3rdbumpst_3, this + 1488, 0, 0, 0);
            sub_565AA0(aFront3rdreboun_0, this + 1496, 0, 0, 0);
            sub_565AA0(aRear3rdbumptra, this + 1504, 0, 0, 0);
            sub_565AA0(aRear3rdrebound, this + 1512, 0, 0, 0);
            sub_565AA0(aRear3rdbumpsto, this + 1520, 0, 0, 0);
            sub_565AA0(aRear3rdbumpsto_0, this + 1528, 0, 0, 0);
            sub_565AA0(aRear3rdbumpsto_1, this + 1536, 0, 0, 0);
            sub_565AA0(aRear3rdbumpsto_2, this + 1544, 0, 0, 0);
            sub_565AA0(aRear3rdbumpsta, this + 1552, 0, 0, 0);
            sub_565AA0(aRear3rdrebound_0, this + 1560, 0, 0, 0);
            CRTMathHelper_e1f0((char *)(a3 + 3312), (int)v67, (int)aFrontantiswayr_0, (int)aFrontantisways, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 3376), (int)v67, (int)aRearantiswayra_0, (int)aRearantiswayse, 1.0);
            CRTMathHelper_e1f0(
              (char *)(a3 + 3440),
              (int)v67,
              (int)aFronttoeinrang,
              (int)aFronttoeinsett,
              0.0174532925199433);
            CRTMathHelper_e1f0(
              (char *)(a3 + 3504),
              (int)v67,
              (int)aReartoeinrange,
              (int)aReartoeinsetti,
              0.0174532925199433);
            CRTMathHelper_e1f0((char *)(a3 + 3568), (int)v67, (int)aLeftfenderflar_0, (int)aLeftfenderflar, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 3632), (int)v67, (int)aRightfenderfla_0, (int)aRightfenderfla, 1.0);
            CRTMathHelper_e1f0(
              (char *)(a3 + 3696),
              (int)v67,
              (int)aLeftcasterrang,
              (int)aLeftcastersett,
              0.0174532925199433);
            CRTMathHelper_e1f0(
              (char *)(a3 + 3760),
              (int)v67,
              (int)aRightcasterran,
              (int)aRightcasterset,
              0.0174532925199433);
            CRTMathHelper_e1f0((char *)(a3 + 3824), (int)v67, (int)aLefttrackbarra, (int)aLefttrackbarse, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 3888), (int)v67, (int)aRighttrackbarr, (int)aRighttrackbars, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 3952), (int)v67, (int)aFront3rdpacker_0, (int)aFront3rdpacker, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 4016), (int)v67, (int)aFront3rdspring_0, (int)aFront3rdspring, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 4080), (int)v67, (int)aFront3rdslowbu_0, (int)aFront3rdslowbu, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 4144), (int)v67, (int)aFront3rdfastbu_0, (int)aFront3rdfastbu, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 4208), (int)v67, (int)aFront3rdslowre_0, (int)aFront3rdslowre, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 4272), (int)v67, (int)aFront3rdfastre_0, (int)aFront3rdfastre, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 4336), (int)v67, (int)aRear3rdpackerr, (int)aRear3rdpackers, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 4400), (int)v67, (int)aRear3rdspringr, (int)aRear3rdsprings, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 4464), (int)v67, (int)aRear3rdslowbum_0, (int)aRear3rdslowbum, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 4528), (int)v67, (int)aRear3rdfastbum_0, (int)aRear3rdfastbum, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 4592), (int)v67, (int)aRear3rdslowreb_0, (int)aRear3rdslowreb, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 4656), (int)v67, (int)aRear3rdfastreb_0, (int)aRear3rdfastreb, 1.0);
            v5 = v56;
          }
        }
      }
      else if ( sub_587C20(v72, aControls_0) )
      {
        while ( LineInputReader(384) )
        {
          v27 = sub_5651B0(v67);
          if ( v27 == 1 )
            break;
          if ( !v27 )
          {
            sub_565AA0(aAutoupshiftgri, this + 1568, 0, 0, 0);
            sub_565AA0(aAutodownshiftg, this + 1576, 0, 0, 0);
            sub_565AA0(aTractioncontro, this + 1584, this + 1592, 0, 0);
            sub_565AA0(aTractioncontro_0, this + 1600, this + 1608, 0, 0);
            sub_5655F0(aAbs4wheel, this + 1616, 0, 0, 0);
            sub_565AA0(aAbsgrip, this + 1620, this + 1628, 0, 0);
            sub_565AA0(aAbslevel, this + 1636, this + 1644, 0, 0);
            CRTMathHelper_e1f0(
              (char *)(a3 + 5168),
              (int)v67,
              (int)aSteerlockrange,
              (int)aSteerlocksetti,
              0.0174532925199433);
            CRTMathHelper_e1f0((char *)(a3 + 4976), (int)v67, (int)aRearbrakerange, (int)aRearbrakesetti, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 5040), (int)v67, (int)aBrakepressurer, (int)aBrakepressures, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 5104), (int)v67, (int)aHandbrakepress_0, (int)aHandbrakepress, 1.0);
          }
        }
      }
      else if ( sub_587C20(v72, aEngine_0) )
      {
        v73[0] = byte_5EA438[0];
        memset(&v73[1], 0, 0x1Cu);
        v74 = 0;
        v75 = 0;
        v55 = 0;
        if ( !StringCopyWithValidation((int)v73, 32, (int)aRestrictorplat, 0)
          && (!sub_588410(v73, aTrue_0) || !sub_588410(v73, &off_5D59D0) || sub_587ECE(v73) == 1) )
        {
          v55 = 1;
        }
        while ( LineInputReader(384) )
        {
          v28 = sub_5651B0(v67);
          if ( v28 == 1 )
            break;
          if ( !v28 )
          {
            if ( !v65 )
            {
              v29 = sub_5654A0(aRestrictorplat, v78);
              v61 = v29;
              v60 = sub_5654A0(aNormal_0, v78);
              if ( v29 != v60 )
              {
                strcpy(v77, a2);
                v30 = strlen(v77);
                if ( v30 > 0 )
                {
                  for ( k = (char *)&v76[7] + v30 + 3; k >= v77; *k-- = 0 )
                  {
                    if ( *k == 92 )
                      break;
                  }
                }
                if ( !FileFinder(v78, aIni, v77, (int)v57) )
                {
                  v32 = v61;
                  if ( (v61 && v55 || v60 && !v55) && (a4 & 2) == 0 )
                  {
                    v33 = (char *)v57[0];
                    if ( !v57[0] )
                      v33 = byte_5EA438;
                    EngineSectionParser(this, (int)v33, (char *)a3);
                  }
                  v34 = (char *)v57[0];
                  if ( v32 )
                  {
                    if ( !v57[0] )
                      v34 = byte_5EA438;
                  }
                  else if ( !v57[0] )
                  {
                    v34 = byte_5EA438;
                  }
                  StringCopyWithBufferRealloc(v34);
                }
              }
            }
            EngineMapSetupFieldDefinitions((int)v67, (char *)a3);
          }
        }
        v5 = v56;
        v35 = *(double *)(this + 1660) * *(double *)(this + 1652) * flt_5EA40C * (double)dword_7D0B64;
        if ( v35 <= 0.0 )
        {
          *(_DWORD *)(a3 + 6548) = 0;
          *(_DWORD *)(a3 + 6552) = 0;
        }
        else
        {
          *(double *)(a3 + 6548) = 1.0 / v35;
        }
      }
      else if ( sub_587C20(v72, aDriveline) )
      {
        v54 = 0;
        while ( LineInputReader(384) )
        {
          v36 = sub_5651B0(v67);
          if ( v36 == 1 )
            break;
          if ( !v36 )
          {
            sub_565AA0(aClutchinertia, this + 4980, 0, 0, 0);
            sub_565AA0(aClutchtorque, this + 4988, 0, 0, 0);
            sub_565AA0(aClutchwear, this + 4996, 0, 0, 0);
            sub_565AA0(aClutchfriction, this + 5004, 0, 0, 0);
            sub_565AA0(aBaulktorque, this + 5012, 0, 0, 0);
            sub_5655F0(aAllowmanualove, this + 5020, 0, 0, 0);
            sub_5655F0(aSemiautomatic, this + 5021, 0, 0, 0);
            sub_565AA0(aUpshiftdelay, this + 5024, 0, 0, 0);
            sub_565AA0(aUpshiftclutcht, this + 5032, 0, 0, 0);
            sub_565AA0(aDownshiftdelay, this + 5040, 0, 0, 0);
            sub_565AA0(aDownshiftclutc, this + 5048, 0, 0, 0);
            sub_565AA0(aDiffpumptorque, this + 5064, 0, 0, 0);
            if ( sub_5654A0(aWheeldrive, v78) )
            {
              if ( sub_588410(v78, aRear) )
              {
                if ( sub_588410(v78, aFour) )
                {
                  if ( !sub_588410(v78, aFront) )
                    *(_DWORD *)(this + 5056) = 2;
                }
                else
                {
                  *(_DWORD *)(this + 5056) = 1;
                }
              }
              else
              {
                *(_DWORD *)(this + 5056) = 0;
              }
            }
            if ( sub_5654A0(aGearfile, v78) )
            {
              strcpy(v77, a2);
              v37 = strlen(v77);
              if ( v37 > 0 )
              {
                for ( m = (char *)&v76[7] + v37 + 3; m >= v77; *m-- = 0 )
                {
                  if ( *m == 92 )
                    break;
                }
              }
              if ( !FileFinder(v78, aIni, v77, (int)v57) )
              {
                if ( (a4 & 2) == 0 )
                {
                  v39 = (char *)v57[0];
                  if ( !v57[0] )
                    v39 = byte_5EA438;
                  ReplayStateCopy((_DWORD *)a3, (int)v39);
                }
                v40 = (char *)v57[0];
                if ( !v57[0] )
                  v40 = byte_5EA438;
                StringCopyWithBufferRealloc(v40);
              }
            }
            sub_565760(aForwardgears, this + 5060, 0, 0, 0);
            if ( sub_565760(aGear1setting, v59, 0, 0, 0) )
              ++v54;
            if ( sub_565760(aGear2setting, v59, 0, 0, 0) )
              ++v54;
            if ( sub_565760(aGear3setting, v59, 0, 0, 0) )
              ++v54;
            if ( sub_565760(aGear4setting, v59, 0, 0, 0) )
              ++v54;
            if ( sub_565760(aGear5setting, v59, 0, 0, 0) )
              ++v54;
            if ( sub_565760(aGear6setting, v59, 0, 0, 0) )
              ++v54;
            if ( sub_565760(aGear7setting, v59, 0, 0, 0) )
              ++v54;
            if ( sub_565760(aGear8setting, v59, 0, 0, 0) )
              ++v54;
            if ( sub_565760(aGear9setting, v59, 0, 0, 0) )
              ++v54;
            if ( sub_565760(aGear10s, v59, 0, 0, 0) )
              ++v54;
            CRTMathHelper_e1f0((char *)(a3 + 5680), (int)v67, 0, (int)aFinaldrivesett_0, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 5744), (int)v67, 0, (int)aReversesetting_0, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 5808), (int)v67, 0, (int)aGear1setting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 5872), (int)v67, 0, (int)aGear2setting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 5936), (int)v67, 0, (int)aGear3setting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 6000), (int)v67, 0, (int)aGear4setting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 6064), (int)v67, 0, (int)aGear5setting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 6128), (int)v67, 0, (int)aGear6setting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 6192), (int)v67, 0, (int)aGear7setting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 6256), (int)v67, 0, (int)aGear8setting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 6320), (int)v67, 0, (int)aGear9setting, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 6384), (int)v67, 0, (int)aGear10s, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 5232), (int)v67, (int)aDiffpumprange, (int)aDiffpumpsettin_0, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 5296), (int)v67, (int)aDiffpowerrange, (int)aDiffpowersetti_0, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 5360), (int)v67, (int)aDiffcoastrange, (int)aDiffcoastsetti_0, 1.0);
            CRTMathHelper_e1f0((char *)(a3 + 5424), (int)v67, (int)aDiffpreloadran, (int)aDiffpreloadset_0, 1.0);
            v5 = v56;
          }
        }
        v41 = 44;
        if ( *(_DWORD *)(this + 5060) + 44 <= 44 )
          goto LABEL_209;
        v42 = (_BYTE *)(a3 + 5836);
        do
        {
          *v42 = 1;
          ++v41;
          v42 += 64;
        }
        while ( v41 < *(_DWORD *)(this + 5060) + 44 );
        if ( v41 <= 50 )
        {
LABEL_209:
          v43 = (_BYTE *)((v41 << 6) + a3 + 3020);
          v44 = 51 - v41;
          do
          {
            *v43 = 0;
            v43 += 64;
            --v44;
          }
          while ( v44 );
        }
        v45 = *(_DWORD *)(this + 5060);
        if ( v45 > 1 && v54 > 1 && v45 != v54 )
        {
          v46 = 0;
          v47 = (_DWORD *)(a3 + 5828);
          do
          {
            v76[v46++] = *v47;
            v47 += 16;
          }
          while ( v46 < v54 );
          v60 = 0;
          v61 = v54 - 1;
          v62 = 0;
          v48 = (int *)(a3 + 5828);
          do
          {
            v49 = (double)v62 / (double)(v45 - 1);
            v58 = v49;
            if ( v49 > 0.0 )
            {
              if ( (double)v61 > v58 )
              {
                v51 = CRTFtol(v58);
                v52 = (double)(int)v76[v51];
                v64[1] = v51;
                v50 = CRTFtol(v52);
              }
              else
              {
                v50 = *(_DWORD *)&v73[4 * v54 + 28];
              }
            }
            else
            {
              v50 = v76[0];
            }
            if ( v50 >= 0 && v50 < *(v48 - 1) )
              *v48 = v50;
            v62 += v61;
            v45 = *(_DWORD *)(this + 5060);
            v48 += 16;
            ++v60;
          }
          while ( v60 < v45 );
          v5 = v56;
        }
      }
      else if ( sub_587C20(v72, aFrontleft) )
      {
        PerWheelBrakeSuspensionDataLoader((double *)(this + 5072), 0, v5, (int)v67, a3);
      }
      else if ( sub_587C20(v72, aFrontright) )
      {
        PerWheelBrakeSuspensionDataLoader((double *)(this + 5336), 1, v5, (int)v67, a3);
      }
      else if ( sub_587C20(v72, aRearleft) )
      {
        PerWheelBrakeSuspensionDataLoader((double *)(this + 5600), 2, v5, (int)v67, a3);
      }
      else if ( sub_587C20(v72, aRearright) )
      {
        PerWheelBrakeSuspensionDataLoader((double *)(this + 5864), 3, v5, (int)v67, a3);
      }
      else if ( sub_587C20(v72, aBasic) && LineInputReader(384) )
      {
        do
        {
          v53 = sub_5651B0(v67);
          if ( v53 == 1 )
            break;
          if ( !v53 )
          {
            DynamicsJointSetTargetPosition((char *)a3, (int)v67, 0, (int)aDownforce_0);
            DynamicsJointSetTargetPosition((char *)a3, (int)v67, 1, (int)aBalance_0);
            DynamicsJointSetTargetPosition((char *)a3, (int)v67, 2, (int)aRide_0);
            DynamicsJointSetTargetPosition((char *)a3, (int)v67, 3, (int)aGearing_0);
            if ( sub_565760(aCustom_0, v64, 0, 0, 0) )
              *(_BYTE *)(a3 + 6564) = v64[0] != 0;
          }
        }
        while ( LineInputReader(384) );
      }
    }
  }
  TrackConfig(a3, -1, -1);
  StreamFileTypeCheckWithDispatch(v5);
  if ( v57[0] )
    FreeWrapper_7bcf(v57[0]);
  return 0;
}
