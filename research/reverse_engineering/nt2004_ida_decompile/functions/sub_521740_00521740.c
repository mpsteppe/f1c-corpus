int __thiscall sub_521740(int this, const char *ArgList, int a3, int a4)
{
  int v5; // edi
  bool v6; // zf
  char *v7; // ebx
  int v8; // eax
  int v9; // eax
  _BYTE *v10; // ecx
  int v12; // eax
  int v13; // edi
  CHAR *v14; // eax
  int v15; // ecx
  int *i; // eax
  char *v17; // eax
  CHAR *v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // ecx
  int *j; // eax
  int v26; // eax
  int v27; // eax
  int v28; // edi
  int v29; // ecx
  int *k; // eax
  int v31; // edi
  char *v32; // eax
  CHAR *v33; // eax
  double v34; // st7
  int v35; // eax
  int v36; // ecx
  int *m; // eax
  char *v38; // eax
  CHAR *v39; // eax
  int v40; // eax
  _BYTE *v41; // ecx
  _BYTE *v42; // edx
  int v43; // ecx
  int v44; // eax
  int v45; // ecx
  _DWORD *v46; // edx
  _DWORD *v47; // edi
  double v48; // st7
  __int64 v49; // rax
  __int64 v50; // rax
  double v51; // st7
  double v52; // st6
  int v53; // eax
  int v54; // [esp+10h] [ebp-5D8h]
  char v55; // [esp+17h] [ebp-5D1h]
  int v56; // [esp+18h] [ebp-5D0h]
  char *FileName[2]; // [esp+1Ch] [ebp-5CCh] BYREF
  int v58; // [esp+24h] [ebp-5C4h] BYREF
  float v59; // [esp+28h] [ebp-5C0h]
  int v60; // [esp+2Ch] [ebp-5BCh]
  int v61; // [esp+30h] [ebp-5B8h]
  float v62; // [esp+34h] [ebp-5B4h] BYREF
  int v63; // [esp+38h] [ebp-5B0h]
  int v64; // [esp+3Ch] [ebp-5ACh] BYREF
  int v65; // [esp+40h] [ebp-5A8h] BYREF
  int v66[2]; // [esp+44h] [ebp-5A4h] BYREF
  int v67; // [esp+4Ch] [ebp-59Ch] BYREF
  char v68[384]; // [esp+50h] [ebp-598h] BYREF
  int v69; // [esp+1D0h] [ebp-418h]
  char v70; // [esp+1D4h] [ebp-414h]
  int v71; // [esp+1DCh] [ebp-40Ch]
  int v72; // [esp+1E0h] [ebp-408h]
  int v73; // [esp+1E4h] [ebp-404h]
  char Str[384]; // [esp+1E8h] [ebp-400h] BYREF
  char String[29]; // [esp+368h] [ebp-280h] BYREF
  __int16 v76; // [esp+385h] [ebp-263h]
  char v77; // [esp+387h] [ebp-261h]
  _DWORD v78[8]; // [esp+388h] [ebp-260h] BYREF
  char v79[256]; // [esp+3A8h] [ebp-240h] BYREF
  char String1[256]; // [esp+4A8h] [ebp-140h] BYREF
  char v81[64]; // [esp+5A8h] [ebp-40h] BYREF

  memset(Str, 0, sizeof(Str));
  v69 = 0;
  v73 = 0;
  v71 = 0;
  v72 = 0;
  v70 = 1;
  FileName[0] = 0;
  FileName[1] = (char *)-1;
  v5 = sub_536110(ArgList, aRb);
  v56 = v5;
  if ( !v5 )
  {
    v6 = FileName[0] == 0;
LABEL_40:
    if ( !v6 )
      sub_5BE8AE();
    return -1;
  }
  if ( a4 == 1 )
  {
    if ( sub_5367E0(384) )
    {
      while ( 1 )
      {
        if ( !sub_577B60(v68) )
        {
          v7 = strchr(Str, 61);
          if ( v7 )
          {
            if ( strstr(Str, aSetting) != v7 - 7
              && strstr(Str, aNotes) != Str
              && strstr(Str, aDownforce) != Str
              && strstr(Str, aBalance) != Str
              && strstr(Str, aRide) != Str
              && strstr(Str, aGearing) != Str
              && strstr(Str, aCustom_0) != Str
              && strstr(Str, aSymmetric) != Str )
            {
              break;
            }
          }
        }
        if ( !sub_5367E0(384) )
          goto LABEL_16;
      }
      if ( dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 817) )
        sub_500FE0((int)&unk_7D7920, "%s is an illegal .SVM file", ArgList);
      sub_536BE0(v5);
      v6 = FileName[0] == 0;
      goto LABEL_40;
    }
LABEL_16:
    sub_5369D0(v5, 0, 0);
  }
  sub_578600(&byte_629120);
  *(_BYTE *)(a3 + 6564) = 1;
  *(_BYTE *)(a3 + 6565) = 0;
  while ( sub_5367E0(384) )
  {
    if ( !sub_577B60(v68) )
    {
      if ( strstr(Str, aGeneral_0) )
      {
        while ( sub_5367E0(384) )
        {
          v8 = sub_577B60(v68);
          if ( v8 == 1 )
            break;
          if ( !v8 )
          {
            if ( sub_578110(aRules, (int)&v65, 0, 0, 0) )
            {
              v9 = v65;
              *(_DWORD *)(this + 52) = v65;
              *(_DWORD *)(a3 + 6544) = v9;
            }
            if ( sub_578110(aGaragedisplayf, this + 56, 0, 0, 0) )
              *(_DWORD *)(a3 + 6540) = *(_DWORD *)(this + 56);
            sub_578450(aMass, this + 60, 0, 0, 0);
            sub_578450(aInertia, this + 68, this + 76, this + 84, 0);
            sub_578450(aCgheight, this + 92, 0, 0, 0);
            if ( sub_578450(aWedgepushrod, this + 100, 0, 0, 0) )
              *(double *)(a3 + 6556) = *(double *)(this + 100);
            sub_578450(aGraphicaloffse, this + 108, this + 116, this + 124, 0);
            sub_578450(aFlundertray, this + 5296, this + 5304, this + 5312, 0);
            sub_578450(aFrundertray, this + 5568, this + 5576, this + 5584, 0);
            sub_578450(aRlundertray, this + 5840, this + 5848, this + 5856, 0);
            sub_578450(aRrundertray, this + 6112, this + 6120, this + 6128, 0);
            if ( sub_577E50(v68, aTirebrand, this + 132) )
            {
              if ( !sub_4E8E50(v81, 64, aTirebrandoverr, 0) )
                strcpy((char *)(this + 132), v81);
              v10 = (_BYTE *)(this + 132 + strlen((const char *)(this + 132)));
              if ( (unsigned int)v10 > this + 132 )
              {
                while ( *v10 != 46 )
                {
                  if ( (unsigned int)--v10 <= this + 132 )
                    goto LABEL_44;
                }
                *v10 = 0;
              }
LABEL_44:
              sub_431A50((char *)a3, (char *)(this + 132));
              v12 = sub_500DC0(&dword_7D7918, (char *)(this + 132));
              v13 = v12;
              if ( v12 )
              {
                *(_DWORD *)(a3 + 3008) = *(_DWORD *)(v12 + 16);
                v14 = *(CHAR **)(v12 + 24);
                if ( !v14 )
                  v14 = &byte_629120;
                sub_578600(v14);
                *(_DWORD *)(this + 8) = *(_DWORD *)(v13 + 32) + 279175584;
              }
              else if ( dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 912) )
              {
                sub_500FE0(
                  (int)&unk_7D7920,
                  "*.hdv file references unknown tire compound \"%s\"",
                  (const char *)(this + 132));
              }
            }
            sub_578450(aFueltankpos, this + 196, this + 204, this + 212, 0);
            sub_578450(aFueltankmotion, this + 220, this + 228, 0, 0);
            sub_578110(aAiminpassesper, this + 236, 0, 0, 0);
            sub_578450(aAirotationthre, this + 240, 0, 0, 0);
            sub_578450(aAievensuspensi, this + 248, 0, 0, 0);
            sub_578450(aAispringrate, this + 256, 0, 0, 0);
            sub_578450(aAidamperslow, this + 264, 0, 0, 0);
            sub_578450(aAidamperfast, this + 272, 0, 0, 0);
            sub_578450(aAidownforcezar, this + 280, 0, 0, 0);
            sub_578450(aAidownforcebia, this + 288, 0, 0, 0);
            sub_578450(aAitorquestab, this + 296, this + 304, this + 312, 0);
            if ( sub_577E50(v68, aNotes_0, (int)String1) )
              sub_578560(String1);
            if ( sub_578110(aSymmetric_0, (int)v66, 0, 0, 0) )
              *(_BYTE *)(a3 + 6565) = v66[0] != 0;
            sub_578110(aFeelerflags, this + 6256, 0, 0, 0);
            sub_578450(aFeeleroffset, this + 6260, this + 6268, this + 6276, 0);
            sub_577FA0(aFeelersatcghei, this + 6284, 0, 0, 0);
            sub_578220(aFeelerfrontlef, this + 6288, this + 6292, this + 6296, 0, 0, 0, 0, 0);
            sub_578220(aFeelerfrontrig, this + 6300, this + 6304, this + 6308, 0, 0, 0, 0, 0);
            sub_578220(aFeelerrearleft, this + 6312, this + 6316, this + 6320, 0, 0, 0, 0, 0);
            sub_578220(aFeelerrearrigh, this + 6324, this + 6328, this + 6332, 0, 0, 0, 0, 0);
            sub_578220(aFeelerfront, this + 6336, this + 6340, this + 6344, 0, 0, 0, 0, 0);
            sub_578220(aFeelerrear, this + 6348, this + 6352, this + 6356, 0, 0, 0, 0, 0);
            sub_578220(aFeelerright, this + 6360, this + 6364, this + 6368, 0, 0, 0, 0, 0);
            sub_578220(aFeelerleft, this + 6372, this + 6376, this + 6380, 0, 0, 0, 0, 0);
            sub_578220(aFeelertopfront, this + 6384, this + 6388, this + 6392, 0, 0, 0, 0, 0);
            sub_578220(aFeelertopfront_0, this + 6396, this + 6400, this + 6404, 0, 0, 0, 0, 0);
            sub_578220(aFeelertoprearl, this + 6408, this + 6412, this + 6416, 0, 0, 0, 0, 0);
            sub_578220(aFeelertoprearr, this + 6420, this + 6424, this + 6428, 0, 0, 0, 0, 0);
            sub_578220(aFeelerbottom, this + 6432, this + 6436, this + 6440, 0, 0, 0, 0, 0);
            if ( sub_577E50(v68, aDamagefile, (int)String1) && a4 != 3 )
            {
              strcpy(v79, ArgList);
              v15 = strlen(v79);
              if ( v15 > 0 )
              {
                for ( i = (_DWORD *)((char *)&v78[7] + v15 + 3); i >= (int *)v79; i = (int *)((char *)i - 1) )
                {
                  if ( *(_BYTE *)i == 92 )
                    break;
                  *(_BYTE *)i = 0;
                }
              }
              if ( !sub_4E77B0(String1, aIni, v79, (int)FileName) )
              {
                if ( a4 != 2 )
                {
                  v17 = FileName[0];
                  if ( !FileName[0] )
                    v17 = &byte_629120;
                  sub_51F750((char *)(this + 6444), v17);
                }
                v18 = FileName[0];
                if ( !FileName[0] )
                  v18 = &byte_629120;
                sub_578600(v18);
              }
            }
            sub_430A90((char *)(a3 + 3056), (int)v68, aCgrightrange, aCgrightsetting_0, 1.0);
            sub_430A90((char *)(a3 + 3120), (int)v68, aCgrearrange, aCgrearsetting, 1.0);
            sub_430A90((char *)(a3 + 3184), (int)v68, aWedgerange, aWedgesetting, 1.0);
            sub_430A90((char *)(a3 + 2992), (int)v68, 0, aTirecompoundse_0, 1.0);
            sub_430A90((char *)(a3 + 3248), (int)v68, aFuelrange, aFuelsetting, 1.0);
            sub_430A90((char *)(a3 + 6256), (int)v68, aNumpitstopsran, aNumpitstopsset_0, 1.0);
            sub_430A90((char *)(a3 + 6320), (int)v68, aPitstop1range, aPitstop1settin_0, 1.0);
            sub_430A90((char *)(a3 + 6384), (int)v68, aPitstop2range, aPitstop2settin_0, 1.0);
            sub_430A90((char *)(a3 + 6448), (int)v68, aPitstop3range, aPitstop3settin_0, 1.0);
            v5 = v56;
          }
        }
      }
      else if ( strstr(Str, aFrontwing_0) )
      {
        while ( sub_5367E0(384) )
        {
          v19 = sub_577B60(v68);
          if ( v19 == 1 )
            break;
          if ( !v19 )
          {
            if ( sub_578450(aFwdragparams, this + 532, this + 540, this + 548, 0) )
              *(_BYTE *)(this + 520) = 1;
            sub_578450(aFwliftparams, this + 556, this + 564, this + 572, 0);
            sub_578450(aFwmaxheight, this + 524, 0, 0, 0);
            sub_578450(aFwliftheight, this + 580, 0, 0, 0);
            sub_578450(aFwliftsideways, this + 588, 0, 0, 0);
            if ( sub_578450(aFwliftpeakyaw, this + 596, this + 604, 0, 0) )
              *(double *)(this + 596) = *(double *)(this + 596) * 0.0174532925199433;
            sub_520620((char *)(this + 612), (int)v68, 0, aFwleft);
            sub_520620((char *)(this + 612), (int)v68, 1, aFwright);
            sub_520620((char *)(this + 612), (int)v68, 2, aFwup);
            sub_520620((char *)(this + 612), (int)v68, 3, aFwdown);
            sub_520620((char *)(this + 612), (int)v68, 4, aFwaft);
            sub_520620((char *)(this + 612), (int)v68, 5, aFwfore);
            sub_520870((long double *)(this + 612), (int)v68, aFwrot);
            sub_578450(aFwcenter, this + 780, this + 788, this + 796, 0);
            sub_430A90((char *)(a3 + 4720), (int)v68, aFwrange, aFwsetting, 1.0);
            v5 = v56;
          }
        }
      }
      else if ( strstr(Str, aLeftfender_0) )
      {
        sub_520450((char *)(this + 320), 9, v5, (int)v68, a3);
      }
      else if ( strstr(Str, aRightfender_0) )
      {
        sub_520450((char *)(this + 420), 10, v5, (int)v68, a3);
      }
      else if ( strstr(Str, aRearwing_0) )
      {
        while ( sub_5367E0(384) )
        {
          v20 = sub_577B60(v68);
          if ( v20 == 1 )
            break;
          if ( !v20 )
          {
            if ( sub_578450(aRwdragparams, this + 808, this + 816, this + 824, 0) )
              *(_BYTE *)(this + 804) = 1;
            sub_578450(aRwliftparams, this + 832, this + 840, this + 848, 0);
            sub_578450(aRwliftsideways, this + 856, 0, 0, 0);
            if ( sub_578450(aRwliftpeakyaw, this + 864, this + 872, 0, 0) )
              *(double *)(this + 864) = *(double *)(this + 864) * 0.0174532925199433;
            sub_520620((char *)(this + 880), (int)v68, 0, aRwleft);
            sub_520620((char *)(this + 880), (int)v68, 1, aRwright);
            sub_520620((char *)(this + 880), (int)v68, 2, aRwup);
            sub_520620((char *)(this + 880), (int)v68, 3, aRwdown);
            sub_520620((char *)(this + 880), (int)v68, 4, aRwaft);
            sub_520620((char *)(this + 880), (int)v68, 5, aRwfore);
            sub_520870((long double *)(this + 880), (int)v68, aRwrot);
            sub_578450(aRwcenter, this + 1048, this + 1056, this + 1064, 0);
            sub_430A90((char *)(a3 + 4784), (int)v68, aRwrange, aRwsetting, 1.0);
            v5 = v56;
          }
        }
      }
      else if ( strstr(Str, aBodyaero_0) )
      {
        while ( sub_5367E0(384) )
        {
          v21 = sub_577B60(v68);
          if ( v21 == 1 )
            break;
          if ( !v21 )
          {
            sub_578450(aBodydragbase, this + 1072, 0, 0, 0);
            sub_578450(aBodydragheight, this + 1080, 0, 0, 0);
            sub_578450(aBodydragheight_0, this + 1088, 0, 0, 0);
            sub_578450(aBodymaxheight, this + 1096, 0, 0, 0);
            sub_520620((char *)(this + 1128), (int)v68, 0, aBodyleft);
            sub_520620((char *)(this + 1128), (int)v68, 1, aBodyright);
            sub_520620((char *)(this + 1128), (int)v68, 2, aBodyup);
            sub_520620((char *)(this + 1128), (int)v68, 3, aBodydown);
            sub_520620((char *)(this + 1128), (int)v68, 4, aBodyaft);
            sub_520620((char *)(this + 1128), (int)v68, 5, aBodyfore);
            sub_520870((long double *)(this + 1128), (int)v68, aBodyrot);
            sub_578450(aBodycenter, this + 1104, this + 1112, this + 1120, 0);
            sub_578450(aRadiatordrag, this + 1380, 0, 0, 0);
            sub_578450(aRadiatorlift, this + 1388, 0, 0, 0);
            sub_430A90((char *)(a3 + 4848), (int)v68, aRadiatorrange, aRadiatorsettin_0, 1.0);
            sub_578450(aBrakeductdrag, this + 1396, 0, 0, 0);
            sub_578450(aBrakeductlift, this + 1404, 0, 0, 0);
            sub_430A90((char *)(a3 + 4912), (int)v68, aBrakeductrange, aBrakeductsetti_0, 1.0);
            v5 = v56;
          }
        }
      }
      else if ( strstr(Str, aDiffuser) )
      {
        while ( sub_5367E0(384) )
        {
          v22 = sub_577B60(v68);
          if ( v22 == 1 )
            break;
          if ( !v22 )
          {
            if ( sub_578450(aDiffuserbase, this + 1300, this + 1308, this + 1316, 0) )
              *(_BYTE *)(this + 1296) = 1;
            sub_578450(aDiffuserfronth, this + 1324, 0, 0, 0);
            sub_578450(aDiffusersidewa, this + 1332, 0, 0, 0);
            if ( sub_578450(aDiffuserpeakya, this + 1340, this + 1348, 0, 0) )
              *(double *)(this + 1340) = *(double *)(this + 1340) * 0.0174532925199433;
            sub_578450(aDiffusercenter, this + 1356, this + 1364, this + 1372, 0);
            v5 = v56;
          }
        }
      }
      else if ( strstr(Str, aSuspension_2) )
      {
        while ( sub_5367E0(384) )
        {
          v23 = sub_577B60(v68);
          if ( v23 == 1 )
            break;
          if ( !v23 )
          {
            if ( sub_577E50(v68, aPhysicalmodelf, (int)String1) && a4 != 3 )
            {
              strcpy(v79, ArgList);
              v24 = strlen(v79);
              if ( v24 > 0 )
              {
                for ( j = (_DWORD *)((char *)&v78[7] + v24 + 3); j >= (int *)v79; j = (int *)((char *)j - 1) )
                {
                  if ( *(_BYTE *)j == 92 )
                    break;
                  *(_BYTE *)j = 0;
                }
              }
              sub_4E77B0(String1, aPm, v79, this + 44);
            }
            sub_578450(aFixinnersusphe, this + 1428, 0, 0, 0);
            if ( sub_577FA0(aApplyslowtofas, this + 1436, 0, 0, 0) )
              *(_BYTE *)(a3 + 6536) = *(_BYTE *)(this + 1436);
            sub_577FA0(aAdjustsusprate, this + 1437, 0, 0, 0);
            sub_577FA0(aAlignwheels, this + 1438, 0, 0, 0);
            sub_578450(aFrontwheeltrac, this + 1440, 0, 0, 0);
            sub_578450(aRearwheeltrack, this + 1448, 0, 0, 0);
            sub_578450(aLeftwheelbase, this + 1456, 0, 0, 0);
            sub_578450(aRightwheelbase, this + 1464, 0, 0, 0);
            if ( sub_577FA0(aSpringbasedant, this + 1472, 0, 0, 0) )
              *(_BYTE *)(a3 + 6537) = *(_BYTE *)(this + 1472);
            if ( sub_577FA0(aAllownoantiswa, this + 1473, 0, 0, 0) )
              *(_BYTE *)(a3 + 6538) = *(_BYTE *)(this + 1473);
            sub_578450(aFrontantiswayb, this + 1476, 0, 0, 0);
            sub_578450(aFrontantiswayr, this + 1484, this + 1492, 0, 0);
            sub_578450(aRearantiswayba, this + 1500, 0, 0, 0);
            sub_578450(aRearantiswayra, this + 1508, this + 1516, 0, 0);
            sub_578450(aFront3rdbumptr, this + 1524, 0, 0, 0);
            sub_578450(aFront3rdreboun, this + 1532, 0, 0, 0);
            sub_578450(aFront3rdbumpst, this + 1540, 0, 0, 0);
            sub_578450(aFront3rdbumpst_0, this + 1548, 0, 0, 0);
            sub_578450(aFront3rdbumpst_1, this + 1556, 0, 0, 0);
            sub_578450(aFront3rdbumpst_2, this + 1564, 0, 0, 0);
            sub_578450(aFront3rdbumpst_3, this + 1572, 0, 0, 0);
            sub_578450(aFront3rdreboun_0, this + 1580, 0, 0, 0);
            sub_578450(aRear3rdbumptra, this + 1588, 0, 0, 0);
            sub_578450(aRear3rdrebound, this + 1596, 0, 0, 0);
            sub_578450(aRear3rdbumpsto, this + 1604, 0, 0, 0);
            sub_578450(aRear3rdbumpsto_0, this + 1612, 0, 0, 0);
            sub_578450(aRear3rdbumpsto_1, this + 1620, 0, 0, 0);
            sub_578450(aRear3rdbumpsto_2, this + 1628, 0, 0, 0);
            sub_578450(aRear3rdbumpsta, this + 1636, 0, 0, 0);
            sub_578450(aRear3rdrebound_0, this + 1644, 0, 0, 0);
            sub_430A90((char *)(a3 + 3312), (int)v68, aFrontantiswayr_0, aFrontantisways_0, 1.0);
            sub_430A90((char *)(a3 + 3376), (int)v68, aRearantiswayra_0, aRearantiswayse_0, 1.0);
            sub_430A90((char *)(a3 + 3440), (int)v68, aFronttoeinrang, aFronttoeinsett_0, 0.0174532925199433);
            sub_430A90((char *)(a3 + 3504), (int)v68, aReartoeinrange, aReartoeinsetti_0, 0.0174532925199433);
            sub_430A90((char *)(a3 + 3568), (int)v68, aLeftfenderflar_0, aLeftfenderflar, 1.0);
            sub_430A90((char *)(a3 + 3632), (int)v68, aRightfenderfla_0, aRightfenderfla, 1.0);
            sub_430A90((char *)(a3 + 3696), (int)v68, aLeftcasterrang, aLeftcastersett_0, 0.0174532925199433);
            sub_430A90((char *)(a3 + 3760), (int)v68, aRightcasterran, aRightcasterset_0, 0.0174532925199433);
            sub_430A90((char *)(a3 + 3824), (int)v68, aLefttrackbarra, aLefttrackbarse_0, 1.0);
            sub_430A90((char *)(a3 + 3888), (int)v68, aRighttrackbarr, aRighttrackbars_0, 1.0);
            sub_430A90((char *)(a3 + 3952), (int)v68, aFront3rdpacker_1, aFront3rdpacker_0, 1.0);
            sub_430A90((char *)(a3 + 4016), (int)v68, aFront3rdspring_1, aFront3rdspring_0, 1.0);
            sub_430A90((char *)(a3 + 4080), (int)v68, aFront3rdslowbu_1, aFront3rdslowbu_0, 1.0);
            sub_430A90((char *)(a3 + 4144), (int)v68, aFront3rdfastbu_1, aFront3rdfastbu_0, 1.0);
            sub_430A90((char *)(a3 + 4208), (int)v68, aFront3rdslowre_1, aFront3rdslowre_0, 1.0);
            sub_430A90((char *)(a3 + 4272), (int)v68, aFront3rdfastre_1, aFront3rdfastre_0, 1.0);
            sub_430A90((char *)(a3 + 4336), (int)v68, aRear3rdpackerr, aRear3rdpackers_0, 1.0);
            sub_430A90((char *)(a3 + 4400), (int)v68, aRear3rdspringr, aRear3rdsprings_0, 1.0);
            sub_430A90((char *)(a3 + 4464), (int)v68, aRear3rdslowbum_1, aRear3rdslowbum_0, 1.0);
            sub_430A90((char *)(a3 + 4528), (int)v68, aRear3rdfastbum_1, aRear3rdfastbum_0, 1.0);
            sub_430A90((char *)(a3 + 4592), (int)v68, aRear3rdslowreb_1, aRear3rdslowreb_0, 1.0);
            sub_430A90((char *)(a3 + 4656), (int)v68, aRear3rdfastreb_1, aRear3rdfastreb_0, 1.0);
            v5 = v56;
          }
        }
      }
      else if ( strstr(Str, aControls_1) )
      {
        while ( sub_5367E0(384) )
        {
          v26 = sub_577B60(v68);
          if ( v26 == 1 )
            break;
          if ( !v26 )
          {
            sub_578450(aAutoupshiftgri, this + 1652, 0, 0, 0);
            sub_578450(aAutodownshiftg, this + 1660, 0, 0, 0);
            sub_578450(aTractioncontro, this + 1668, this + 1676, 0, 0);
            sub_578450(aTractioncontro_0, this + 1684, this + 1692, 0, 0);
            sub_577FA0(aAbs4wheel, this + 1700, 0, 0, 0);
            sub_578450(aAbsgrip, this + 1704, this + 1712, 0, 0);
            sub_578450(aAbslevel, this + 1720, this + 1728, 0, 0);
            sub_577FA0(aOnboardbrakebi, this + 1736, 0, 0, 0);
            sub_430A90((char *)(a3 + 5168), (int)v68, aSteerlockrange, aSteerlocksetti_0, 0.0174532925199433);
            sub_430A90((char *)(a3 + 4976), (int)v68, aRearbrakerange, aRearbrakesetti_0, 1.0);
            sub_430A90((char *)(a3 + 5040), (int)v68, aBrakepressurer, aBrakepressures_0, 1.0);
            sub_430A90((char *)(a3 + 5104), (int)v68, aHandbrakepress_1, aHandbrakepress_0, 1.0);
          }
        }
      }
      else if ( strstr(Str, aEngine_1) )
      {
        String[0] = byte_629120;
        memset(&String[1], 0, 0x1Cu);
        v76 = 0;
        v77 = 0;
        v55 = 0;
        if ( !sub_4E8E50(String, 32, aRestrictorplat, 0)
          && (!_strcmpi(String, aTrue_0) || !_strcmpi(String, off_613DE4) || atol(String) == 1) )
        {
          v55 = 1;
        }
        v62 = 1.0;
        v64 = 1065353216;
        while ( sub_5367E0(384) )
        {
          v27 = sub_577B60(v68);
          if ( v27 == 1 )
            break;
          if ( !v27 )
          {
            sub_577FA0(aSpeedlimiter, this + 5040, 0, 0, 0);
            sub_578220(aRevmultiplier, (int)&v62, 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aTorquemultipli, (int)&v64, 0, 0, 0, 0, 0, 0, 0);
            if ( a4 != 1 && a4 != 3 )
            {
              v28 = sub_577E50(v68, aRestrictorplat, (int)String1);
              v61 = v28;
              v60 = sub_577E50(v68, aNormal_0, (int)String1);
              if ( v28 != v60 )
              {
                strcpy(v79, ArgList);
                v29 = strlen(v79);
                if ( v29 > 0 )
                {
                  for ( k = (_DWORD *)((char *)&v78[7] + v29 + 3); k >= (int *)v79; k = (int *)((char *)k - 1) )
                  {
                    if ( *(_BYTE *)k == 92 )
                      break;
                    *(_BYTE *)k = 0;
                  }
                }
                if ( !sub_4E77B0(String1, aIni, v79, (int)FileName) )
                {
                  v31 = v61;
                  if ( (v61 && v55 || v60 && !v55) && a4 != 2 )
                  {
                    v32 = FileName[0];
                    if ( !FileName[0] )
                      v32 = &byte_629120;
                    sub_521110(this, v32, (char *)a3, v62, *(float *)&v64);
                  }
                  v33 = FileName[0];
                  if ( v31 )
                  {
                    if ( !FileName[0] )
                      v33 = &byte_629120;
                  }
                  else if ( !FileName[0] )
                  {
                    v33 = &byte_629120;
                  }
                  sub_578600(v33);
                }
              }
            }
            sub_5210A0((int)v68, (char *)a3, v62);
          }
        }
        v5 = v56;
        v34 = *(double *)(this + 1748)
            * *(double *)(this + 1740)
            * flt_7D7418
            * flt_6290E0
            * (double)*(int *)dword_76926C;
        if ( v34 <= 0.0 )
        {
          *(_DWORD *)(a3 + 6548) = 0;
          *(_DWORD *)(a3 + 6552) = 0;
        }
        else
        {
          *(double *)(a3 + 6548) = 1.0 / v34;
        }
      }
      else if ( strstr(Str, aDriveline_0) )
      {
        v54 = 0;
        while ( sub_5367E0(384) )
        {
          v35 = sub_577B60(v68);
          if ( v35 == 1 )
            break;
          if ( !v35 )
          {
            sub_578450(aClutchinertia, this + 5068, 0, 0, 0);
            sub_578450(aClutchtorque, this + 5076, 0, 0, 0);
            sub_578450(aClutchwear, this + 5084, 0, 0, 0);
            sub_578450(aClutchfriction, this + 5092, 0, 0, 0);
            sub_578450(aBaulktorque, this + 5100, 0, 0, 0);
            sub_577FA0(aAllowmanualove, this + 5108, 0, 0, 0);
            sub_577FA0(aSemiautomatic, this + 5109, 0, 0, 0);
            sub_578450(aUpshiftdelay, this + 5112, 0, 0, 0);
            sub_578450(aUpshiftclutcht, this + 5120, 0, 0, 0);
            sub_578450(aDownshiftdelay, this + 5128, 0, 0, 0);
            sub_578450(aDownshiftclutc, this + 5136, 0, 0, 0);
            sub_578450(aDownshiftblipt, this + 5144, 0, 0, 0);
            sub_578450(aDiffpumptorque, this + 5160, 0, 0, 0);
            if ( sub_577E50(v68, aWheeldrive, (int)String1) )
            {
              if ( _strcmpi(String1, aRear_0) )
              {
                if ( _strcmpi(String1, aFour) )
                {
                  if ( !_strcmpi(String1, aFront_0) )
                    *(_DWORD *)(this + 5152) = 2;
                }
                else
                {
                  *(_DWORD *)(this + 5152) = 1;
                }
              }
              else
              {
                *(_DWORD *)(this + 5152) = 0;
              }
            }
            if ( sub_577E50(v68, aGearfile, (int)String1) && a4 != 3 )
            {
              strcpy(v79, ArgList);
              v36 = strlen(v79);
              if ( v36 > 0 )
              {
                for ( m = (_DWORD *)((char *)&v78[7] + v36 + 3); m >= (int *)v79; m = (int *)((char *)m - 1) )
                {
                  if ( *(_BYTE *)m == 92 )
                    break;
                  *(_BYTE *)m = 0;
                }
              }
              if ( !sub_4E77B0(String1, aIni, v79, (int)FileName) )
              {
                if ( a4 != 2 )
                {
                  v38 = FileName[0];
                  if ( !FileName[0] )
                    v38 = &byte_629120;
                  sub_4319C0((_DWORD *)a3, v38);
                }
                v39 = FileName[0];
                if ( !FileName[0] )
                  v39 = &byte_629120;
                sub_578600(v39);
              }
            }
            sub_578110(aForwardgears, this + 5156, 0, 0, 0);
            if ( sub_578110(aGear1setting, (int)&v58, 0, 0, 0) )
              ++v54;
            if ( sub_578110(aGear2setting, (int)&v58, 0, 0, 0) )
              ++v54;
            if ( sub_578110(aGear3setting, (int)&v58, 0, 0, 0) )
              ++v54;
            if ( sub_578110(aGear4setting, (int)&v58, 0, 0, 0) )
              ++v54;
            if ( sub_578110(aGear5setting, (int)&v58, 0, 0, 0) )
              ++v54;
            if ( sub_578110(aGear6setting, (int)&v58, 0, 0, 0) )
              ++v54;
            if ( sub_578110(aGear7setting, (int)&v58, 0, 0, 0) )
              ++v54;
            sub_430A90((char *)(a3 + 5680), (int)v68, 0, aFinaldrivesett_0, 1.0);
            sub_430A90((char *)(a3 + 5744), (int)v68, 0, aReversesetting_0, 1.0);
            sub_430A90((char *)(a3 + 5808), (int)v68, 0, aGear1setting, 1.0);
            sub_430A90((char *)(a3 + 5872), (int)v68, 0, aGear2setting, 1.0);
            sub_430A90((char *)(a3 + 5936), (int)v68, 0, aGear3setting, 1.0);
            sub_430A90((char *)(a3 + 6000), (int)v68, 0, aGear4setting, 1.0);
            sub_430A90((char *)(a3 + 6064), (int)v68, 0, aGear5setting, 1.0);
            sub_430A90((char *)(a3 + 6128), (int)v68, 0, aGear6setting, 1.0);
            sub_430A90((char *)(a3 + 6192), (int)v68, 0, aGear7setting, 1.0);
            sub_430A90((char *)(a3 + 5232), (int)v68, aDiffpumprange, aDiffpumpsettin_0, 1.0);
            sub_430A90((char *)(a3 + 5296), (int)v68, aDiffpowerrange, aDiffpowersetti_0, 1.0);
            sub_430A90((char *)(a3 + 5360), (int)v68, aDiffcoastrange, aDiffcoastsetti_0, 1.0);
            sub_430A90((char *)(a3 + 5424), (int)v68, aDiffpreloadran, aDiffpreloadset_0, 1.0);
            v5 = v56;
          }
        }
        v40 = 44;
        if ( *(_DWORD *)(this + 5156) + 44 <= 44 )
          goto LABEL_225;
        v41 = (_BYTE *)(a3 + 5836);
        do
        {
          *v41 = 1;
          ++v40;
          v41 += 64;
        }
        while ( v40 < *(_DWORD *)(this + 5156) + 44 );
        if ( v40 <= 50 )
        {
LABEL_225:
          v42 = (_BYTE *)((v40 << 6) + a3 + 3020);
          v43 = 51 - v40;
          do
          {
            *v42 = 0;
            v42 += 64;
            --v43;
          }
          while ( v43 );
        }
        v44 = *(_DWORD *)(this + 5156);
        if ( v44 > 1 && v54 > 1 && v44 != v54 )
        {
          v45 = 0;
          v46 = (_DWORD *)(a3 + 5828);
          do
          {
            v78[v45++] = *v46;
            v46 += 16;
          }
          while ( v45 < v54 );
          v60 = 0;
          v61 = v54 - 1;
          v63 = 0;
          v47 = (_DWORD *)(a3 + 5828);
          do
          {
            v48 = (double)v63 / (double)(v44 - 1);
            v59 = v48;
            if ( v48 > 0.0 )
            {
              if ( (double)v61 > v59 )
              {
                v50 = (__int64)v59;
                v51 = (double)(int)v78[(_DWORD)v50];
                v52 = (double)(int)v78[(_DWORD)v50 + 1];
                v66[1] = v50;
                v49 = (__int64)((v52 - v51) * (v59 - (double)(int)v50) + v51 + 0.5);
              }
              else
              {
                LODWORD(v49) = *(_DWORD *)&String[4 * v54 + 28];
              }
            }
            else
            {
              LODWORD(v49) = v78[0];
            }
            if ( (int)v49 >= 0 && (int)v49 < *(v47 - 1) )
              *v47 = v49;
            v63 += v61;
            v44 = *(_DWORD *)(this + 5156);
            v47 += 16;
            ++v60;
          }
          while ( v60 < v44 );
          v5 = v56;
        }
      }
      else if ( strstr(Str, aFrontleft_1) )
      {
        sub_520000((double *)(this + 5168), 0, v5, (int)v68, a3);
      }
      else if ( strstr(Str, aFrontright_1) )
      {
        sub_520000((double *)(this + 5440), 1, v5, (int)v68, a3);
      }
      else if ( strstr(Str, aRearleft_1) )
      {
        sub_520000((double *)(this + 5712), 2, v5, (int)v68, a3);
      }
      else if ( strstr(Str, aRearright_1) )
      {
        sub_520000((double *)(this + 5984), 3, v5, (int)v68, a3);
      }
      else if ( strstr(Str, aBasic_0) && sub_5367E0(384) )
      {
        do
        {
          v53 = sub_577B60(v68);
          if ( v53 == 1 )
            break;
          if ( !v53 )
          {
            sub_4345D0((void *)a3, (int)v68, 0, aDownforce_0);
            sub_4345D0((void *)a3, (int)v68, 1, aBalance_0);
            sub_4345D0((void *)a3, (int)v68, 2, aRide_0);
            sub_4345D0((void *)a3, (int)v68, 3, aGearing_0);
            if ( sub_578110(aCustom, (int)&v67, 0, 0, 0) )
              *(_BYTE *)(a3 + 6564) = v67 != 0;
          }
        }
        while ( sub_5367E0(384) );
      }
    }
  }
  sub_430ED0(a3, -1, -1);
  sub_536BE0(v5);
  if ( FileName[0] )
    sub_5BE8AE();
  return 0;
}
