int __userpurge sub_5886AD@<eax>(int a1@<ecx>, _DWORD *a2@<ebp>, int a3, int a4, int a5)
{
  unsigned int v5; // kr00_4
  __int32 v6; // edx
  char *v9; // edi
  int v10; // ebx
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // edi
  _BYTE *v15; // eax
  int v16; // eax
  int v17; // edi
  const CHAR *v18; // eax
  char *v19; // eax
  char *v20; // edx
  char v21; // cl
  int v22; // kr08_4
  char *j; // eax
  char *v24; // eax
  char *v25; // edi
  const CHAR *v27; // eax
  const CHAR *v28; // eax
  int v29; // eax
  long double *v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  char *v35; // eax
  char *v36; // edx
  char v37; // cl
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // edi
  char *v43; // eax
  char *v44; // edx
  char v45; // cl
  const CHAR *v46; // eax
  const CHAR *v47; // eax
  double v48; // st7
  int v49; // eax
  char *v50; // eax
  char *v51; // edx
  char v52; // cl
  const CHAR *v53; // eax
  const CHAR *v54; // eax
  int v55; // eax
  _BYTE *v56; // ecx
  _BYTE *v57; // edx
  int v58; // ecx
  int v59; // eax
  _DWORD *v60; // ecx
  _DWORD *v61; // edi
  double v62; // st7
  unsigned __int64 v63; // rax
  unsigned __int64 v64; // rax
  double v65; // st7
  double v66; // st6
  int v67; // ecx
  int v68; // eax
  double v69; // st7
  double v70; // st6
  int v71; // eax
  int v72; // esi
  int v73; // edi
  char v74; // cl
  int v75; // ebx
  int v76; // edx
  double v77; // [esp+0h] [ebp-7B8h] BYREF
  char *v78; // [esp+8h] [ebp-7B0h]
  const char *v79; // [esp+Ch] [ebp-7ACh]
  _BYTE *v80; // [esp+10h] [ebp-7A8h]
  int *v81; // [esp+14h] [ebp-7A4h]
  int *v82; // [esp+18h] [ebp-7A0h]
  const char *v83; // [esp+1Ch] [ebp-79Ch]
  char *v84; // [esp+20h] [ebp-798h]
  void *v85; // [esp+24h] [ebp-794h]
  char *v86; // [esp+28h] [ebp-790h]
  void **v87; // [esp+2Ch] [ebp-78Ch]
  int v88; // [esp+30h] [ebp-788h]
  int v89; // [esp+34h] [ebp-784h] BYREF
  void *v90; // [esp+38h] [ebp-780h]
  const CHAR *v91; // [esp+3Ch] [ebp-77Ch]
  int v92; // [esp+40h] [ebp-778h]
  int i; // [esp+44h] [ebp-774h]
  int v94; // [esp+48h] [ebp-770h]
  void *Block[2]; // [esp+4Ch] [ebp-76Ch] BYREF
  long double *v96; // [esp+54h] [ebp-764h]
  _DWORD v97[4]; // [esp+58h] [ebp-760h] BYREF
  int v98; // [esp+68h] [ebp-750h] BYREF
  int v99; // [esp+6Ch] [ebp-74Ch] BYREF
  int v100[2]; // [esp+70h] [ebp-748h] BYREF
  char String; // [esp+78h] [ebp-740h] BYREF
  int v102; // [esp+79h] [ebp-73Fh]
  int v103; // [esp+7Dh] [ebp-73Bh]
  int v104; // [esp+81h] [ebp-737h]
  int v105; // [esp+85h] [ebp-733h]
  int v106; // [esp+89h] [ebp-72Fh]
  int v107; // [esp+8Dh] [ebp-72Bh]
  int v108; // [esp+91h] [ebp-727h]
  __int16 v109; // [esp+95h] [ebp-723h]
  char v110; // [esp+97h] [ebp-721h]
  _DWORD v111[14]; // [esp+98h] [ebp-720h] BYREF
  int v112[5]; // [esp+D0h] [ebp-6E8h] BYREF
  int v113; // [esp+E4h] [ebp-6D4h] BYREF
  int v114[2]; // [esp+E8h] [ebp-6D0h] BYREF
  int v115[124]; // [esp+F8h] [ebp-6C0h] BYREF
  char v116[16]; // [esp+2E8h] [ebp-4D0h] BYREF
  int v117; // [esp+2F8h] [ebp-4C0h]
  char v118[4]; // [esp+2FCh] [ebp-4BCh] BYREF
  char v119[4]; // [esp+300h] [ebp-4B8h] BYREF
  int v120; // [esp+304h] [ebp-4B4h]
  int v121; // [esp+308h] [ebp-4B0h]
  int v122; // [esp+30Ch] [ebp-4ACh]
  _DWORD Str[129]; // [esp+310h] [ebp-4A8h] BYREF
  char v124; // [esp+517h] [ebp-2A1h] BYREF
  char v125[16]; // [esp+518h] [ebp-2A0h] BYREF
  int v126[2]; // [esp+528h] [ebp-290h] BYREF
  char String1[232]; // [esp+530h] [ebp-288h] BYREF
  _BYTE v128[16]; // [esp+618h] [ebp-1A0h] BYREF
  char v129[8]; // [esp+628h] [ebp-190h] BYREF
  char v130[256]; // [esp+630h] [ebp-188h] BYREF
  char v131[64]; // [esp+730h] [ebp-88h] BYREF
  char Buffer[28]; // [esp+770h] [ebp-48h] BYREF
  int v133; // [esp+794h] [ebp-24h]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+7B4h] [ebp-4h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  sub_613B30(v111);
  memset(Str, 0, 0x200u);
  v117 = 0;
  v122 = 0;
  v120 = 0;
  v121 = 0;
  v118[0] = 1;
  Block[0] = 0;
  Block[1] = (void *)-1;
  if ( !(unsigned __int8)sub_614460(a2[2], 1) )
  {
LABEL_2:
    sub_614140(v111);
    return -1;
  }
  if ( a2[4] == 1 )
  {
    if ( sub_613DE0((char *)Str, 512) )
    {
      while ( 1 )
      {
        if ( !sub_612EB0(v115) )
        {
          v9 = strchr((const char *)Str, 61);
          if ( v9 )
          {
            if ( strstr((const char *)Str, "SETTING=") != v9 - 7
              && strstr((const char *)Str, "NOTES=") != (char *)Str
              && strstr((const char *)Str, "DOWNFORCE=") != (char *)Str
              && strstr((const char *)Str, "BALANCE=") != (char *)Str
              && strstr((const char *)Str, "RIDE=") != (char *)Str
              && strstr((const char *)Str, "GEARING=") != (char *)Str
              && strstr((const char *)Str, "CUSTOM=") != (char *)Str
              && strstr((const char *)Str, "SYMMETRIC=") != (char *)Str )
            {
              break;
            }
          }
        }
        if ( !sub_613DE0((char *)Str, 512) )
          goto LABEL_16;
      }
      if ( dword_B640C0 != 5 && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 818) )
        sub_561210((int)byte_FAE910, "%s is an illegal .SVM file", (const char *)a2[2]);
      sub_613C30(v111);
      goto LABEL_2;
    }
LABEL_16:
    sub_613F20(v111);
  }
  v10 = a2[3];
  sub_615860(WindowName);
  v87 = (void **)512;
  v86 = (char *)Str;
  *(_BYTE *)(v10 + 6952) = 1;
  *(_BYTE *)(v10 + 6953) = 1;
  if ( sub_613DE0(v86, (int)v87) )
  {
    do
    {
      if ( !sub_612EB0(v115) )
      {
        if ( strstr((const char *)Str, "[GENERAL]") )
        {
          if ( sub_613DE0((char *)Str, 512) )
          {
            do
            {
              v12 = sub_612EB0(v115);
              if ( v12 == 1 )
                break;
              if ( !v12 )
              {
                if ( sub_6133A0("Rules", (int)v100, 0, 0, 0) )
                {
                  v13 = v100[0];
                  *(_DWORD *)(a1 + 52) = v100[0];
                  *(_DWORD *)(v10 + 6928) = v13;
                }
                if ( sub_6133A0("GarageDisplayFlags", a1 + 56, 0, 0, 0) )
                  *(_DWORD *)(v10 + 6924) = *(_DWORD *)(a1 + 56);
                sub_6136D0("Mass", a1 + 64, 0, 0, 0);
                sub_6136D0("Inertia", a1 + 72, a1 + 80, a1 + 88, 0);
                sub_6136D0("CGHeight", a1 + 96, 0, 0, 0);
                if ( sub_6136D0("WedgePushrod", a1 + 104, 0, 0, 0) )
                  *(double *)(v10 + 6944) = *(double *)(a1 + 104);
                sub_6136D0("GraphicalOffset", a1 + 112, a1 + 120, a1 + 128, 0);
                if ( sub_616480(Str, "Undertray") )
                {
                  v14 = a1 + 5392;
                  sub_6136D0("FLUndertray", a1 + 5384, a1 + 5392, a1 + 5400, 0);
                  sub_6136D0("FRUndertray", a1 + 5408, a1 + 5416, a1 + 5424, 0);
                  sub_6136D0("RLUndertray", a1 + 5432, a1 + 5440, a1 + 5448, 0);
                  sub_6136D0("RRUndertray", a1 + 5456, a1 + 5464, a1 + 5472, 0);
                  sub_6136D0("UndertrayParams", a1 + 5672, a1 + 5680, a1 + 5688, 0);
                  for ( i = 0; i < 12; ++i )
                  {
                    sprintf(Buffer, "Undertray%02d", i);
                    if ( sub_6136D0(Buffer, v14 - 8, v14, v14 + 8, 0) )
                      *(_BYTE *)(a1 + 5376) = 0;
                    v14 += 24;
                  }
                }
                if ( sub_6131C0("TireBrand", a1 + 136) )
                {
                  if ( !sub_53A2B0((int)v131, 64, "TireBrandOverride", 0) )
                    strcpy((char *)(a1 + 136), v131);
                  v15 = (_BYTE *)(a1 + strlen((const char *)(a1 + 136)) + 136);
                  if ( (unsigned int)v15 > a1 + 136 )
                  {
                    while ( *v15 != 46 )
                    {
                      if ( (unsigned int)--v15 <= a1 + 136 )
                        goto LABEL_46;
                    }
                    *v15 = 0;
                  }
LABEL_46:
                  v87 = (void **)(a1 + 136);
                  sub_432C70();
                  v16 = sub_560950(&dword_FAE908, a1 + 136);
                  v17 = v16;
                  if ( v16 )
                  {
                    *(_DWORD *)(v10 + 3008) = *(_DWORD *)(v16 + 16);
                    *(_DWORD *)(v10 + 3072) = *(_DWORD *)(v16 + 16);
                    v18 = *(const CHAR **)(v16 + 24);
                    if ( !v18 )
                      v18 = WindowName;
                    sub_615860(v18);
                    *(_DWORD *)(a1 + 8) = *(_DWORD *)(v17 + 32) + 537133609;
                  }
                  else if ( dword_B640C0 != 5
                         && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 921) )
                  {
                    sub_561210(
                      (int)byte_FAE910,
                      "*.hdc file references unknown tire compound \"%s\"",
                      (const char *)(a1 + 136));
                  }
                }
                sub_6136D0("FuelTankPos", a1 + 200, a1 + 208, a1 + 216, 0);
                sub_6136D0("FuelTankMotion", a1 + 224, a1 + 232, 0, 0);
                sub_6133A0("AIMinPassesPerTick", a1 + 240, 0, 0, 0);
                sub_6136D0("AIRotationThreshold", a1 + 248, 0, 0, 0);
                sub_6136D0("AIEvenSuspension", a1 + 256, 0, 0, 0);
                sub_6136D0("AISpringRate", a1 + 264, 0, 0, 0);
                sub_6136D0("AIDamperSlow", a1 + 272, 0, 0, 0);
                sub_6136D0("AIDamperFast", a1 + 280, 0, 0, 0);
                sub_6136D0("AIDownforceZArm", a1 + 288, 0, 0, 0);
                sub_6136D0("AIDownforceBias", a1 + 296, 0, 0, 0);
                sub_6136D0("AITorqueStab", a1 + 304, a1 + 312, a1 + 320, 0);
                if ( sub_6131C0("Notes", (int)v126) )
                  sub_615A50(v126);
                if ( sub_6133A0("Symmetric", (int)&v99, 0, 0, 0) )
                  *(_BYTE *)(v10 + 6953) = v99 != 0;
                sub_6133A0("FeelerFlags", a1 + 6720, 0, 0, 0);
                sub_613240("FeelersAtCGHeight", a1 + 6724, 0, 0, 0);
                sub_6134B0("FeelerFrontLeft", a1 + 6728, a1 + 6732, a1 + 6736, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerFrontRight", a1 + 6740, a1 + 6744, a1 + 6748, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerRearLeft", a1 + 6752, a1 + 6756, a1 + 6760, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerRearRight", a1 + 6764, a1 + 6768, a1 + 6772, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerFront", a1 + 6776, a1 + 6780, a1 + 6784, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerRear", a1 + 6788, a1 + 6792, a1 + 6796, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerRight", a1 + 6800, a1 + 6804, a1 + 6808, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerLeft", a1 + 6812, a1 + 6816, a1 + 6820, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerTopFrontLeft", a1 + 6824, a1 + 6828, a1 + 6832, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerTopFrontRight", a1 + 6836, a1 + 6840, a1 + 6844, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerTopRearLeft", a1 + 6848, a1 + 6852, a1 + 6856, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerTopRearRight", a1 + 6860, a1 + 6864, a1 + 6868, 0, 0, 0, 0, 0);
                sub_6134B0("FeelerBottom", a1 + 6872, a1 + 6876, a1 + 6880, 0, 0, 0, 0, 0);
                if ( sub_6131C0("DamageFile", (int)v126) && a2[4] != 3 )
                {
                  v19 = (char *)a2[2];
                  v20 = (char *)(v129 - v19);
                  do
                  {
                    v21 = *v19;
                    v20[(_DWORD)v19] = *v19;
                    ++v19;
                  }
                  while ( v21 );
                  v22 = strlen(v129);
                  if ( v22 > 0 )
                  {
                    for ( j = &v128[v22 + 15]; j >= v129; *j-- = 0 )
                    {
                      if ( *j == 92 )
                        break;
                    }
                  }
                  v97[0] = 0;
                  v97[1] = -1;
                  v85 = v97;
                  v84 = v129;
                  v83 = ".DMG";
                  v82 = v126;
                  LOBYTE(ExceptionList) = 2;
                  sub_5396B0();
                  if ( byte_B71E28 )
                  {
                    v24 = &v125[strlen(v125)];
                    if ( v24 > v125 )
                    {
                      while ( *v24 != 46 )
                      {
                        if ( --v24 <= v125 )
                          goto LABEL_71;
                      }
                      *v24 = 0;
                    }
LABEL_71:
                    v25 = &v124;
                    while ( *++v25 )
                      ;
                    strcpy(v25, "_LOW.DMG");
                  }
                  v81 = &v89;
                  v80 = v128;
                  v79 = ".DMG";
                  v78 = v125;
                  if ( !sub_5396B0() )
                  {
                    if ( a2[4] != 2 )
                    {
                      v27 = (const CHAR *)v85;
                      if ( !v85 )
                        v27 = WindowName;
                      sub_586450((void *)(a1 + 6884), (int)v27);
                    }
                    v28 = (const CHAR *)v90;
                    if ( !v90 )
                      v28 = WindowName;
                    sub_615860(v28);
                  }
                  LOBYTE(v133) = 1;
                  if ( v90 )
                    j_j__free(v90);
                }
                sub_431730((char *)(v10 + 3120), (int)v112, "CGRightRange", "CGRightSetting", 1.0);
                sub_431730((char *)(v10 + 3184), (int)v112, "CGRearRange", "CGRearSetting", 1.0);
                sub_431730((char *)(v10 + 3248), (int)v112, "WedgeRange", "WedgeSetting", 1.0);
                sub_431730((char *)(v10 + 2992), (int)v112, 0, "FrontTireCompoundSetting", 1.0);
                sub_431730((char *)(v10 + 3056), (int)v112, 0, "RearTireCompoundSetting", 1.0);
                sub_431730((char *)(v10 + 3312), (int)v112, "FuelRange", "FuelSetting", 1.0);
                sub_431730((char *)(v10 + 6320), (int)v112, "NumPitstopsRange", "NumPitstopsSetting", 1.0);
                sub_431730((char *)(v10 + 6384), (int)v112, "Pitstop1Range", "Pitstop1Setting", 1.0);
                sub_431730((char *)(v10 + 6448), (int)v112, "Pitstop2Range", "Pitstop2Setting", 1.0);
                sub_431730((char *)(v10 + 6512), (int)v112, "Pitstop3Range", "Pitstop3Setting", 1.0);
                sub_431730((char *)(v10 + 6576), (int)v112, "Pitstop4Range", "Pitstop4Setting", 1.0);
                sub_431730((char *)(v10 + 6640), (int)v112, "Pitstop5Range", "Pitstop5Setting", 1.0);
                sub_431730((char *)(v10 + 6704), (int)v112, "Pitstop6Range", "Pitstop6Setting", 1.0);
                sub_431730((char *)(v10 + 6768), (int)v112, "Pitstop7Range", "Pitstop7Setting", 1.0);
                sub_431730((char *)(v10 + 6832), (int)v112, "Pitstop8Range", "Pitstop8Setting", 1.0);
              }
            }
            while ( sub_613DE0(v116, 512) );
          }
        }
        else if ( strstr((const char *)Str, "[FRONTWING]") )
        {
          while ( sub_613DE0((char *)Str, 512) )
          {
            v29 = sub_612EB0(v115);
            if ( v29 == 1 )
              break;
            if ( !v29 )
            {
              if ( sub_6136D0("FWDragParams", a1 + 552, a1 + 560, a1 + 568, 0) )
                *(_BYTE *)(a1 + 536) = 1;
              sub_6136D0("FWLiftParams", a1 + 576, a1 + 584, a1 + 592, 0);
              sub_6136D0("FWMaxHeight", a1 + 544, 0, 0, 0);
              sub_6136D0("FWLiftHeight", a1 + 600, 0, 0, 0);
              sub_6136D0("FWLiftSideways", a1 + 608, 0, 0, 0);
              if ( sub_6136D0("FWLiftPeakYaw", a1 + 616, a1 + 624, 0, 0) )
                *(double *)(a1 + 616) = *(double *)(a1 + 616) * 0.0174532925199433;
              sub_5873A0((char *)(a1 + 632), (int)v115, 0, "FWLeft");
              if ( sub_6136D0("FWRight", a1 + 656, a1 + 664, a1 + 672, 0)
                && *(double *)(a1 + 656) < 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 391) )
              {
                sub_561210((int)byte_FAE910, "-x force applied when moving in -x direction");
              }
              if ( sub_6136D0("FWUp", a1 + 680, a1 + 688, a1 + 696, 0)
                && *(double *)(a1 + 688) > 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 396) )
              {
                sub_561210((int)byte_FAE910, "+y force applied when moving in +y direction");
              }
              if ( sub_6136D0("FWDown", a1 + 704, a1 + 712, a1 + 720, 0)
                && *(double *)(a1 + 712) < 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 401) )
              {
                sub_561210((int)byte_FAE910, "-y force applied when moving in -y direction");
              }
              if ( sub_6136D0("FWAft", a1 + 728, a1 + 736, a1 + 744, 0)
                && *(double *)(a1 + 744) > 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 406) )
              {
                sub_561210((int)byte_FAE910, "+z force applied when moving in +z direction");
              }
              if ( sub_6136D0("FWFore", a1 + 752, a1 + 760, a1 + 768, 0)
                && *(double *)(a1 + 768) < 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 411) )
              {
                sub_561210((int)byte_FAE910, "-z force applied when moving in -z direction");
              }
              v97[0] = a1 + 784;
              v96 = (long double *)(a1 + 792);
              if ( sub_6136D0("FWRot", a1 + 776, a1 + 784, a1 + 792, 0) )
              {
                v30 = (long double *)v97[0];
                *(long double *)(a1 + 776) = fabs(*(double *)(a1 + 776));
                *v30 = fabs(*v30);
                *v96 = fabs(*v96);
              }
              sub_6136D0("FWCenter", a1 + 800, a1 + 808, a1 + 816, 0);
              sub_431730((char *)(v10 + 4784), (int)v115, "FWRange", "FWSetting", 1.0);
            }
          }
        }
        else if ( strstr((const char *)Str, "[LEFTFENDER]") )
        {
          sub_5871A0((double *)(a1 + 328), 10, (int)v111, (int)v115, v10);
        }
        else if ( strstr((const char *)Str, "[RIGHTFENDER]") )
        {
          sub_5871A0((double *)(a1 + 432), 11, (int)v111, (int)v115, v10);
        }
        else if ( strstr((const char *)Str, "[REARWING]") )
        {
          while ( sub_613DE0((char *)Str, 512) )
          {
            v31 = sub_612EB0(v115);
            if ( v31 == 1 )
              break;
            if ( !v31 )
            {
              if ( sub_6136D0("RWDragParams", a1 + 832, a1 + 840, a1 + 848, 0) )
                *(_BYTE *)(a1 + 824) = 1;
              sub_6136D0("RWLiftParams", a1 + 856, a1 + 864, a1 + 872, 0);
              sub_6136D0("RWLiftSideways", a1 + 880, 0, 0, 0);
              if ( sub_6136D0("RWLiftPeakYaw", a1 + 888, a1 + 896, 0, 0) )
                *(double *)(a1 + 888) = *(double *)(a1 + 888) * 0.0174532925199433;
              sub_5873A0((char *)(a1 + 904), (int)v115, 0, "RWLeft");
              sub_5873A0((char *)(a1 + 904), (int)v115, 1u, "RWRight");
              if ( sub_6136D0("RWUp", a1 + 952, a1 + 960, a1 + 968, 0)
                && *(double *)(a1 + 960) > 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 396) )
              {
                sub_561210((int)byte_FAE910, "+y force applied when moving in +y direction");
              }
              if ( sub_6136D0("RWDown", a1 + 976, a1 + 984, a1 + 992, 0)
                && *(double *)(a1 + 984) < 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 401) )
              {
                sub_561210((int)byte_FAE910, "-y force applied when moving in -y direction");
              }
              if ( sub_6136D0("RWAft", a1 + 1000, a1 + 1008, a1 + 1016, 0)
                && *(double *)(a1 + 1016) > 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 406) )
              {
                sub_561210((int)byte_FAE910, "+z force applied when moving in +z direction");
              }
              if ( sub_6136D0("RWFore", a1 + 1024, a1 + 1032, a1 + 1040, 0)
                && *(double *)(a1 + 1040) < 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 411) )
              {
                sub_561210((int)byte_FAE910, "-z force applied when moving in -z direction");
              }
              sub_585E20((long double *)(a1 + 904), (int)v115, "RWRot");
              sub_6136D0("RWCenter", a1 + 1072, a1 + 1080, a1 + 1088, 0);
              sub_431730((char *)(v10 + 4848), (int)v115, "RWRange", "RWSetting", 1.0);
            }
          }
        }
        else if ( strstr((const char *)Str, "[BODYAERO]") )
        {
          while ( sub_613DE0((char *)Str, 512) )
          {
            v32 = sub_612EB0(v115);
            if ( v32 == 1 )
              break;
            if ( !v32 )
            {
              sub_6136D0("BodyDragBase", a1 + 1096, 0, 0, 0);
              sub_6136D0("BodyDragHeightAvg", a1 + 1104, 0, 0, 0);
              sub_6136D0("BodyDragHeightDiff", a1 + 1112, 0, 0, 0);
              sub_6136D0("BodyMaxHeight", a1 + 1120, 0, 0, 0);
              sub_5873A0((char *)(a1 + 1152), (int)v115, 0, "BodyLeft");
              sub_5873A0((char *)(a1 + 1152), (int)v115, 1u, "BodyRight");
              sub_5873A0((char *)(a1 + 1152), (int)v115, 2u, "BodyUp");
              if ( sub_6136D0("BodyDown", a1 + 1224, a1 + 1232, a1 + 1240, 0)
                && *(double *)(a1 + 1232) < 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 401) )
              {
                sub_561210((int)byte_FAE910, "-y force applied when moving in -y direction");
              }
              if ( sub_6136D0("BodyAft", a1 + 1248, a1 + 1256, a1 + 1264, 0)
                && *(double *)(a1 + 1264) > 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 406) )
              {
                sub_561210((int)byte_FAE910, "+z force applied when moving in +z direction");
              }
              if ( sub_6136D0("BodyFore", a1 + 1272, a1 + 1280, a1 + 1288, 0)
                && *(double *)(a1 + 1288) < 0.0
                && dword_B640C0 != 5
                && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 411) )
              {
                sub_561210((int)byte_FAE910, "-z force applied when moving in -z direction");
              }
              sub_585E20((long double *)(a1 + 1152), (int)v115, "BodyRot");
              sub_6136D0("BodyCenter", a1 + 1128, a1 + 1136, a1 + 1144, 0);
              sub_6136D0("RadiatorDrag", a1 + 1472, 0, 0, 0);
              sub_6136D0("RadiatorLift", a1 + 1480, 0, 0, 0);
              sub_431730((char *)(v10 + 4912), (int)v115, "RadiatorRange", "RadiatorSetting", 1.0);
              sub_6136D0("BrakeDuctDrag", a1 + 1488, 0, 0, 0);
              sub_6136D0("BrakeDuctLift", a1 + 1496, 0, 0, 0);
              sub_431730((char *)(v10 + 4976), (int)v115, "BrakeDuctRange", "BrakeDuctSetting", 1.0);
            }
          }
        }
        else if ( strstr((const char *)Str, "[DIFFUSER]") )
        {
          while ( sub_613DE0((char *)Str, 512) )
          {
            v33 = sub_612EB0(v115);
            if ( v33 == 1 )
              break;
            if ( !v33 )
            {
              if ( sub_6136D0("DiffuserBase", a1 + 1328, a1 + 1336, a1 + 1344, 0) )
                *(_BYTE *)(a1 + 1320) = 1;
              sub_6136D0("DiffuserFrontHeight", a1 + 1360, 0, 0, 0);
              sub_6136D0("DiffuserRake", a1 + 1368, a1 + 1376, a1 + 1384, 0);
              sub_6136D0("DiffuserLimits", a1 + 1400, a1 + 1352, a1 + 1392, 0);
              sub_6136D0("DiffuserStall", a1 + 1408, a1 + 1416, 0, 0);
              sub_6136D0("DiffuserSideways", a1 + 1424, 0, 0, 0);
              if ( sub_6136D0("DiffuserPeakYaw", a1 + 1432, a1 + 1440, 0, 0) )
                *(double *)(a1 + 1432) = *(double *)(a1 + 1432) * 0.0174532925199433;
              sub_6136D0("DiffuserCenter", a1 + 1448, a1 + 1456, a1 + 1464, 0);
            }
          }
        }
        else if ( strstr((const char *)Str, "[SUSPENSION]") )
        {
          if ( sub_613DE0((char *)Str, 512) )
          {
            do
            {
              v34 = sub_612EB0(v115);
              if ( v34 == 1 )
                break;
              if ( !v34 )
              {
                if ( sub_6131C0("PhysicalModelFile", (int)String1) && a2[4] != 3 )
                {
                  v35 = (char *)a2[2];
                  v36 = (char *)(v130 - v35);
                  do
                  {
                    v37 = *v35;
                    v35[(_DWORD)v36] = *v35;
                    ++v35;
                  }
                  while ( v37 );
                  sub_408500(v130);
                  v87 = (void **)(a1 + 44);
                  v86 = v130;
                  v85 = &off_7234A8;
                  v84 = String1;
                  sub_5396B0();
                }
                sub_6136D0("FixInnerSuspHeight", a1 + 1520, 0, 0, 0);
                sub_6136D0("CorrectedInnerSuspHeight", a1 + 1528, 0, 0, 0);
                if ( sub_613240("ApplySlowToFastDampers", a1 + 1536, 0, 0, 0) )
                  *(_BYTE *)(v10 + 6921) = *(_BYTE *)(a1 + 1536);
                sub_613240("AdjustSuspRates", a1 + 1537, 0, 0, 0);
                sub_613240("AlignWheels", a1 + 1538, 0, 0, 0);
                sub_6136D0("FrontWheelTrack", a1 + 1544, 0, 0, 0);
                sub_6136D0("RearWheelTrack", a1 + 1552, 0, 0, 0);
                sub_6136D0("LeftWheelBase", a1 + 1560, 0, 0, 0);
                sub_6136D0("RightWheelBase", a1 + 1568, 0, 0, 0);
                if ( sub_613240("SpringBasedAntiSway", a1 + 1576, 0, 0, 0) )
                  *(_BYTE *)(v10 + 6922) = *(_BYTE *)(a1 + 1576);
                if ( sub_613240("AllowNoAntiSway", a1 + 1577, 0, 0, 0) )
                  *(_BYTE *)(v10 + 6923) = *(_BYTE *)(a1 + 1577);
                sub_6136D0("FrontAntiSwayBase", a1 + 1584, 0, 0, 0);
                sub_6136D0("FrontAntiSwayRate", a1 + 1592, a1 + 1600, 0, 0);
                sub_6136D0("RearAntiSwayBase", a1 + 1608, 0, 0, 0);
                sub_6136D0("RearAntiSwayRate", a1 + 1616, a1 + 1624, 0, 0);
                sub_6136D0("Front3rdBumpTravel", a1 + 1632, 0, 0, 0);
                sub_6136D0("Front3rdReboundTravel", a1 + 1640, 0, 0, 0);
                sub_6136D0("Front3rdBumpStopSpring", a1 + 1648, 0, 0, 0);
                sub_6136D0("Front3rdBumpStopRisingSpring", a1 + 1656, 0, 0, 0);
                sub_6136D0("Front3rdBumpStopDamper", a1 + 1664, 0, 0, 0);
                sub_6136D0("Front3rdBumpStopRisingDamper", a1 + 1672, 0, 0, 0);
                sub_6136D0("Front3rdBumpStage2", a1 + 1680, 0, 0, 0);
                sub_6136D0("Front3rdReboundStage2", a1 + 1688, 0, 0, 0);
                sub_6136D0("Rear3rdBumpTravel", a1 + 1696, 0, 0, 0);
                sub_6136D0("Rear3rdReboundTravel", a1 + 1704, 0, 0, 0);
                sub_6136D0("Rear3rdBumpStopSpring", a1 + 1712, 0, 0, 0);
                sub_6136D0("Rear3rdBumpStopRisingSpring", a1 + 1720, 0, 0, 0);
                sub_6136D0("Rear3rdBumpStopDamper", a1 + 1728, 0, 0, 0);
                sub_6136D0("Rear3rdBumpStopRisingDamper", a1 + 1736, 0, 0, 0);
                sub_6136D0("Rear3rdBumpStage2", a1 + 1744, 0, 0, 0);
                sub_6136D0("Rear3rdReboundStage2", a1 + 1752, 0, 0, 0);
                sub_586250((char *)v10, (int)v114, 6, "FrontAntiSwayRange", "FrontAntiSwaySetting", 1.0);
                sub_586250((char *)v10, (int)v114, 7, "RearAntiSwayRange", "RearAntiSwaySetting", 1.0);
                sub_586250((char *)v10, (int)v114, 8, "FrontToeInRange", "FrontToeInSetting", 0.0174532925199433);
                sub_586250((char *)v10, (int)v114, 9, "RearToeInRange", "RearToeInSetting", 0.0174532925199433);
                sub_586250((char *)v10, (int)v114, 10, "LeftFenderFlareRange", "LeftFenderFlareSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 11, "RightFenderFlareRange", "RightFenderFlareSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 12, "LeftCasterRange", "LeftCasterSetting", 0.0174532925199433);
                sub_586250((char *)v10, (int)v114, 13, "RightCasterRange", "RightCasterSetting", 0.0174532925199433);
                sub_586250((char *)v10, (int)v114, 14, "LeftTrackBarRange", "LeftTrackBarSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 15, "RightTrackBarRange", "RightTrackBarSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 16, "Front3rdPackerRange", "Front3rdPackerSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 17, "Front3rdSpringRange", "Front3rdSpringSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 18, "Front3rdSlowBumpRange", "Front3rdSlowBumpSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 19, "Front3rdFastBumpRange", "Front3rdFastBumpSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 20, "Front3rdSlowReboundRange", "Front3rdSlowReboundSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 21, "Front3rdFastReboundRange", "Front3rdFastReboundSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 22, "Rear3rdPackerRange", "Rear3rdPackerSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 23, "Rear3rdSpringRange", "Rear3rdSpringSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 24, "Rear3rdSlowBumpRange", "Rear3rdSlowBumpSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 25, "Rear3rdFastBumpRange", "Rear3rdFastBumpSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 26, "Rear3rdSlowReboundRange", "Rear3rdSlowReboundSetting", 1.0);
                sub_586250((char *)v10, (int)v114, 27, "Rear3rdFastReboundRange", "Rear3rdFastReboundSetting", 1.0);
              }
            }
            while ( sub_613DE0(v119, 512) );
          }
        }
        else if ( strstr((const char *)Str, "[CONTROLS]") )
        {
          while ( sub_613DE0((char *)Str, 512) )
          {
            v38 = sub_612EB0(v115);
            if ( v38 == 1 )
              break;
            if ( !v38 )
            {
              sub_6136D0("SteeringFFBMult", a1 + 1760, 0, 0, 0);
              if ( sub_6136D0("UpshiftAlgorithm", a1 + 5336, a1 + 5344, 0, 0) )
                *(double *)(a1 + 5344) = *(double *)(a1 + 5344) * 0.1047197551196598;
              sub_6136D0("DownshiftAlgorithm", a1 + 5352, a1 + 5360, a1 + 5368, 0);
              sub_6136D0("AutoUpshiftGripThresh", a1 + 1768, 0, 0, 0);
              sub_6136D0("AutoDownshiftGripThresh", a1 + 1776, 0, 0, 0);
              sub_6136D0("TractionControlGrip", a1 + 1784, a1 + 1792, 0, 0);
              sub_6136D0("TractionControlLevel", a1 + 1800, a1 + 1808, 0, 0);
              sub_613240("ABS4Wheel", a1 + 1817, 0, 0, 0);
              sub_6136D0("ABSGrip", a1 + 1824, a1 + 1832, 0, 0);
              sub_6136D0("ABSLevel", a1 + 1840, a1 + 1848, 0, 0);
              sub_613240("OnboardBrakeBias", a1 + 1816, 0, 0, 0);
              sub_586250((char *)v10, (int)v115, 35, "SteerLockRange", "SteerLockSetting", 0.0174532925199433);
              sub_586250((char *)v10, (int)v115, 32, "RearBrakeRange", "RearBrakeSetting", 1.0);
              sub_586250((char *)v10, (int)v115, 33, "BrakePressureRange", "BrakePressureSetting", 1.0);
              sub_586250((char *)v10, (int)v115, 34, "HandbrakePressRange", "HandbrakePressSetting", 1.0);
            }
          }
        }
        else if ( strstr((const char *)Str, "[ENGINE]") )
        {
          v102 = 0;
          v103 = 0;
          v104 = 0;
          v105 = 0;
          v106 = 0;
          v107 = 0;
          v108 = 0;
          v109 = 0;
          String = 0;
          v110 = 0;
          v39 = sub_53A2B0((int)&String, 32, "RestrictorPlate", 0);
          HIBYTE(v92) = 0;
          if ( !v39 && (!_stricmp(&String, "true") || !_stricmp(&String, off_722C90) || atol(&String) == 1) )
            HIBYTE(v92) = 1;
          if ( sub_613DE0((char *)Str, 512) )
          {
            do
            {
              v40 = sub_612EB0(v115);
              if ( v40 == 1 )
                break;
              if ( !v40 )
              {
                sub_613240("SpeedLimiter", a1 + 5184, 0, 0, 0);
                v41 = a2[4];
                if ( v41 != 1 && v41 != 3 )
                {
                  i = sub_6131C0("RestrictorPlate", (int)String1);
                  v42 = sub_6131C0("Normal", (int)String1);
                  if ( i != v42 )
                  {
                    v43 = (char *)a2[2];
                    v44 = (char *)(v130 - v43);
                    do
                    {
                      v45 = *v43;
                      v43[(_DWORD)v44] = *v43;
                      ++v43;
                    }
                    while ( v45 );
                    sub_408500(v130);
                    v87 = Block;
                    v86 = v130;
                    v85 = ".ENG";
                    v84 = String1;
                    if ( !sub_5396B0() )
                    {
                      if ( (v89 && HIBYTE(v88) || v42 && !HIBYTE(v88)) && a2[4] != 2 )
                      {
                        v46 = v91;
                        if ( !v91 )
                          v46 = WindowName;
                        sub_587F80(a1, (int)v46, (char *)v10);
                      }
                      v47 = v91;
                      if ( v89 )
                      {
                        if ( !v91 )
                          v47 = WindowName;
                      }
                      else if ( !v91 )
                      {
                        v47 = WindowName;
                      }
                      sub_615860(v47);
                    }
                  }
                }
                sub_587F00((int)v114, (char *)v10);
              }
            }
            while ( sub_613DE0(v119, 512) );
          }
          v48 = flt_BE27A8 * (*(double *)(a1 + 1864) * *(double *)(a1 + 1856) * flt_91BDF4 * (double)dword_B72E08);
          if ( v48 <= 0.0 )
            *(double *)(v10 + 6936) = 0.0;
          else
            *(double *)(v10 + 6936) = 1.0 / v48;
        }
        else if ( strstr((const char *)Str, "[DRIVELINE]") )
        {
          v91 = 0;
          if ( sub_613DE0((char *)Str, 512) )
          {
            do
            {
              v49 = sub_612EB0(v115);
              if ( v49 == 1 )
                break;
              if ( !v49 )
              {
                sub_6136D0("ClutchEngageRate", a1 + 5216, 0, 0, 0);
                sub_6136D0("ClutchInertia", a1 + 5224, 0, 0, 0);
                sub_6136D0("ClutchTorque", a1 + 5232, 0, 0, 0);
                sub_6136D0("ClutchWear", a1 + 5240, 0, 0, 0);
                sub_6136D0("ClutchFriction", a1 + 5248, 0, 0, 0);
                sub_6136D0("BaulkTorque", a1 + 5256, 0, 0, 0);
                sub_613240("AllowManualOverride", a1 + 5264, 0, 0, 0);
                sub_613240("SemiAutomatic", a1 + 5265, 0, 0, 0);
                sub_6136D0("UpshiftDelay", a1 + 5272, 0, 0, 0);
                sub_6136D0("UpshiftClutchTime", a1 + 5280, 0, 0, 0);
                sub_6136D0("UpshiftLiftThrottle", a1 + 5288, 0, 0, 0);
                sub_6136D0("DownshiftDelay", a1 + 5296, 0, 0, 0);
                sub_6136D0("DownshiftClutchTime", a1 + 5304, 0, 0, 0);
                sub_6136D0("DownshiftBlipThrottle", a1 + 5312, 0, 0, 0);
                sub_6136D0("DiffPumpTorque", a1 + 5328, 0, 0, 0);
                if ( sub_6131C0("WheelDrive", (int)String1) )
                {
                  if ( !_stricmp(String1, "REAR") )
                  {
                    *(_DWORD *)(a1 + 5320) = 0;
                  }
                  else if ( !_stricmp(String1, "FOUR") )
                  {
                    *(_DWORD *)(a1 + 5320) = 1;
                  }
                  else if ( !_stricmp(String1, "FRONT") )
                  {
                    *(_DWORD *)(a1 + 5320) = 2;
                  }
                }
                if ( sub_6131C0("GearFile", (int)String1) )
                {
                  if ( a2[4] != 3 )
                  {
                    v50 = (char *)a2[2];
                    v51 = (char *)(v130 - v50);
                    do
                    {
                      v52 = *v50;
                      v50[(_DWORD)v51] = *v50;
                      ++v50;
                    }
                    while ( v52 );
                    sub_408500(v130);
                    v87 = Block;
                    v86 = v130;
                    v85 = ".GRB";
                    v84 = String1;
                    if ( !sub_5396B0() )
                    {
                      if ( a2[4] != 2 )
                      {
                        v53 = v91;
                        if ( !v91 )
                          v53 = WindowName;
                        v83 = v53;
                        sub_432C00();
                      }
                      v54 = (const CHAR *)v90;
                      if ( !v90 )
                        v54 = WindowName;
                      sub_615860(v54);
                    }
                  }
                }
                sub_6133A0("ForwardGears", a1 + 5324, 0, 0, 0);
                if ( sub_6133A0("Gear1Setting", (int)&v89, 0, 0, 0) )
                  ++v86;
                if ( sub_6133A0("Gear2Setting", (int)&v89, 0, 0, 0) )
                  ++v86;
                if ( sub_6133A0("Gear3Setting", (int)&v89, 0, 0, 0) )
                  ++v86;
                if ( sub_6133A0("Gear4Setting", (int)&v89, 0, 0, 0) )
                  ++v86;
                if ( sub_6133A0("Gear5Setting", (int)&v89, 0, 0, 0) )
                  ++v86;
                if ( sub_6133A0("Gear6Setting", (int)&v89, 0, 0, 0) )
                  ++v86;
                if ( sub_6133A0("Gear7Setting", (int)&v89, 0, 0, 0) )
                  ++v86;
                sub_586250((char *)v10, (int)&v113, 43, 0, "FinalDriveSetting", 1.0);
                sub_586250((char *)v10, (int)&v113, 44, 0, "ReverseSetting", 1.0);
                sub_586250((char *)v10, (int)&v113, 45, 0, "Gear1Setting", 1.0);
                sub_586250((char *)v10, (int)&v113, 46, 0, "Gear2Setting", 1.0);
                sub_586250((char *)v10, (int)&v113, 47, 0, "Gear3Setting", 1.0);
                sub_586250((char *)v10, (int)&v113, 48, 0, "Gear4Setting", 1.0);
                sub_586250((char *)v10, (int)&v113, 49, 0, "Gear5Setting", 1.0);
                sub_586250((char *)v10, (int)&v113, 50, 0, "Gear6Setting", 1.0);
                sub_586250((char *)v10, (int)&v113, 51, 0, "Gear7Setting", 1.0);
                sub_586250((char *)v10, (int)&v113, 36, "DiffPumpRange", "DiffPumpSetting", 1.0);
                sub_586250((char *)v10, (int)&v113, 37, "DiffPowerRange", "DiffPowerSetting", 1.0);
                sub_586250((char *)v10, (int)&v113, 38, "DiffCoastRange", "DiffCoastSetting", 1.0);
                sub_586250((char *)v10, (int)&v113, 39, "DiffPreloadRange", "DiffPreloadSetting", 1.0);
              }
            }
            while ( sub_613DE0(v118, 512) );
          }
          v55 = 45;
          if ( *(_DWORD *)(a1 + 5324) + 45 <= 45 )
            goto LABEL_298;
          v56 = (_BYTE *)(v10 + 5900);
          do
          {
            *v56 = 1;
            ++v55;
            v56 += 64;
          }
          while ( v55 < *(_DWORD *)(a1 + 5324) + 45 );
          if ( v55 <= 51 )
          {
LABEL_298:
            v57 = (_BYTE *)((v55 << 6) + v10 + 3020);
            v58 = 52 - v55;
            do
            {
              *v57 = 0;
              v57 += 64;
              --v58;
            }
            while ( v58 );
          }
          v11 = *(_DWORD *)(a1 + 5324);
          if ( v11 > 1 && (int)v86 > 1 && (char *)v11 != v86 )
          {
            v59 = 0;
            v60 = (_DWORD *)(v10 + 5892);
            do
            {
              Str[v59++ + 123] = *v60;
              v60 += 16;
            }
            while ( v59 < (int)v86 );
            v92 = 0;
            i = (int)(v86 - 1);
            v94 = 0;
            v61 = (_DWORD *)(v10 + 5892);
            do
            {
              v88 = *(_DWORD *)(a1 + 5324) - 1;
              v62 = (double)v94 / (double)v88;
              *(float *)&v88 = v62;
              if ( v62 > 0.0 )
              {
                if ( (double)i > *(float *)&v88 )
                {
                  v64 = (unsigned __int64)*(float *)&v88;
                  v65 = (double)(int)Str[(_DWORD)v64 + 123];
                  v66 = (double)(int)Str[(_DWORD)v64 + 124];
                  v97[0] = v64;
                  v63 = (unsigned __int64)((*(float *)&v88 - (double)(int)v64) * (v66 - v65) + v65 + 0.5);
                }
                else
                {
                  LODWORD(v63) = Str[(_DWORD)v86 + 122];
                }
              }
              else
              {
                LODWORD(v63) = Str[123];
              }
              if ( (v63 & 0x80000000) == 0LL && (int)v63 < *(v61 - 1) )
                *v61 = v63;
              v11 = i;
              v94 += i;
              v67 = *(_DWORD *)(a1 + 5324);
              v61 += 16;
              ++v92;
            }
            while ( v92 < v67 );
          }
        }
        else if ( strstr((const char *)Str, "[FRONTLEFT]") )
        {
          v87 = (void **)v10;
          v86 = (char *)v115;
          sub_586CE0(0, v111);
        }
        else if ( strstr((const char *)Str, "[FRONTRIGHT]") )
        {
          v87 = (void **)v10;
          v86 = (char *)v115;
          sub_586CE0(1, v111);
        }
        else if ( strstr((const char *)Str, "[REARLEFT]") )
        {
          v87 = (void **)v10;
          v86 = (char *)v115;
          sub_586CE0(2, v111);
        }
        else if ( strstr((const char *)Str, "[REARRIGHT]") )
        {
          v87 = (void **)v10;
          v86 = (char *)v115;
          sub_586CE0(3, v111);
        }
        else if ( strstr((const char *)Str, "[BASIC]") && sub_613DE0((char *)Str, 512) )
        {
          do
          {
            v68 = sub_612EB0(v115);
            if ( v68 == 1 )
              break;
            if ( !v68 )
            {
              sub_431920((void *)v10, (int)v115, 0, "Downforce");
              sub_431920((void *)v10, (int)v115, 1, "Balance");
              sub_431920((void *)v10, (int)v115, 2, "Ride");
              sub_431920((void *)v10, (int)v115, 3, "Gearing");
              if ( sub_6133A0("Custom", (int)&v98, 0, 0, 0) )
                *(_BYTE *)(v10 + 6952) = v98 != 0;
            }
          }
          while ( sub_613DE0((char *)Str, 512) );
        }
      }
      HIDWORD(v77) = v11;
      v5 = __readeflags();
      v6 = dword_16C6DD0 - 1823626277;
      __writeeflags(v5);
      _InterlockedExchange((volatile __int32 *)&v77 + 1, v6);
    }
    while ( sub_613DE0(v116, SHIDWORD(v77)) );
  }
  sub_432080((_DWORD *)v10, -1, -1);
  *(_DWORD *)(v10 + 6336) = 9;
  v69 = *(double *)(v10 + 3312);
  v70 = *(double *)(v10 + 3320);
  v71 = *(_DWORD *)(v10 + 3328);
  v72 = *(_DWORD *)(v10 + 6536);
  v73 = *(_DWORD *)(v10 + 6532);
  v74 = *(_BYTE *)(v10 + 6540);
  v75 = v10 + 6592;
  v76 = 5;
  do
  {
    if ( !*(_DWORD *)v75 )
    {
      *(_DWORD *)v75 = v71;
      *(double *)(v75 - 16) = v69;
      *(_DWORD *)(v75 + 8) = v72;
      *(_DWORD *)(v75 + 4) = v73;
      *(double *)(v75 - 8) = v70;
      *(_BYTE *)(v75 + 12) = v74;
    }
    v75 += 64;
    --v76;
  }
  while ( v76 );
  sub_613C30(v100);
  if ( v85 )
    j_j__free(v85);
  v133 = -1;
  sub_614140(v100);
  return 0;
}
