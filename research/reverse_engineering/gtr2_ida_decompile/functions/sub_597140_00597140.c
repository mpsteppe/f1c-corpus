int __thiscall sub_597140(int this)
{
  const char *v2; // eax
  _DWORD *v3; // eax
  char *v4; // eax
  _DWORD *v5; // eax
  char *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  char *v9; // eax
  _DWORD *v10; // eax
  char *v11; // eax
  _DWORD *v12; // eax
  char *v13; // eax
  _DWORD *v14; // eax
  char *v15; // eax
  _DWORD *v16; // eax
  char *v17; // eax
  _DWORD *v18; // eax
  char *v19; // eax
  _DWORD *v20; // eax
  char *v21; // eax
  _DWORD *v22; // eax
  char *v23; // eax
  _DWORD *v24; // eax
  char *v25; // eax
  _DWORD *v26; // eax
  char *v27; // eax
  _DWORD *v28; // eax
  char *v29; // eax
  _DWORD *v30; // eax
  char *v31; // eax
  _DWORD *v32; // eax
  char *v33; // eax
  _DWORD *v34; // eax
  char *v35; // eax
  _DWORD *v36; // eax
  char *v37; // eax
  _DWORD *v38; // eax
  char *v39; // eax
  _DWORD *v40; // eax
  char *v41; // eax
  _DWORD *v42; // eax
  char *v43; // eax
  _DWORD *v44; // eax
  char *v45; // eax
  _DWORD *v46; // eax
  char *v47; // eax
  _DWORD *v48; // eax
  char *v49; // eax
  _DWORD *v50; // eax
  char *v51; // eax
  _DWORD *v52; // eax
  char *v53; // eax
  _DWORD *v54; // eax
  char *v55; // eax
  _DWORD *v56; // eax
  char *v57; // eax
  _DWORD *v58; // eax
  char *v59; // eax
  _DWORD *v60; // eax
  char *v61; // eax
  _DWORD *v62; // eax
  char *v63; // eax
  _DWORD *v64; // eax
  char *v65; // eax
  _DWORD *v66; // eax
  char *v67; // eax
  _DWORD *v68; // eax
  char *v69; // eax
  _DWORD *v70; // eax
  char *v71; // eax
  _DWORD *v72; // eax
  char *v73; // eax
  _DWORD *v74; // eax
  char *v75; // eax
  _DWORD *v76; // eax
  char *v77; // eax
  _DWORD *v78; // eax
  char *v79; // eax
  _DWORD *v80; // eax
  char *v81; // eax
  _DWORD *v82; // eax
  char *v83; // eax
  _DWORD *v84; // eax
  char *v85; // eax
  _DWORD *v86; // eax
  char *v87; // eax
  _DWORD *v88; // eax
  char *v89; // eax
  _DWORD *v90; // eax
  char *v91; // eax
  _DWORD *v92; // eax
  char *v93; // eax
  _DWORD *v94; // eax
  char *v95; // eax
  _DWORD *v96; // eax
  char *v97; // eax
  _DWORD *v98; // eax
  char *v99; // eax
  _DWORD *v100; // eax
  char *v101; // eax
  _DWORD *v102; // eax
  char *v103; // eax
  _DWORD *v104; // eax
  char *v105; // eax
  _DWORD *v106; // eax
  char *v107; // eax
  _DWORD *v108; // eax
  char *v109; // eax
  _DWORD *v110; // eax
  char *v111; // eax
  _DWORD *v112; // eax
  char *v113; // eax
  _DWORD *v114; // eax
  char *v115; // eax
  double v116; // st7
  int result; // eax
  int v118; // [esp-4h] [ebp-150h]
  float v119; // [esp+4h] [ebp-148h]
  int v120; // [esp+8h] [ebp-144h] BYREF
  float v121; // [esp+Ch] [ebp-140h] BYREF
  float v122; // [esp+10h] [ebp-13Ch] BYREF
  float v123; // [esp+14h] [ebp-138h] BYREF
  float v124; // [esp+18h] [ebp-134h] BYREF
  float v125; // [esp+1Ch] [ebp-130h] BYREF
  float v126; // [esp+20h] [ebp-12Ch]
  char *v127; // [esp+24h] [ebp-128h]
  float v128; // [esp+28h] [ebp-124h]
  char String1[32]; // [esp+2Ch] [ebp-120h] BYREF
  char Buffer[256]; // [esp+4Ch] [ebp-100h] BYREF

  sub_596A40();
  if ( !dword_B70618[0] )
  {
    sub_596A80((_DWORD *)this, 0.0, 362879.97);
    v2 = (const char *)dword_91CAF8;
    if ( !dword_91CAF8 )
      v2 = WindowName;
    sprintf(Buffer, "%sweather.txt", v2);
    sub_594000(this, Buffer);
  }
  *(_DWORD *)(this + 176) = -1082130432;
  *(_DWORD *)(this + 20) = -1082130432;
  v118 = *(_DWORD *)(this + 500);
  *(_DWORD *)(this + 12) = 1065353216;
  *(_DWORD *)(this + 28) = -1;
  *(_DWORD *)(this + 32) = -1031798784;
  *(_DWORD *)(this + 756) = sub_5DA9A0(&off_7251E8, v118);
  *(_DWORD *)(this + 760) = sub_5DA9A0("MOON", *(_DWORD *)(this + 500));
  *(_DWORD *)(this + 724) = sub_5DA9A0("SUNRISE", *(_DWORD *)(this + 500));
  *(_DWORD *)(this + 728) = sub_5DA9A0(&off_724984, *(_DWORD *)(this + 500));
  *(_DWORD *)(this + 732) = sub_5DA9A0("SUNSET", *(_DWORD *)(this + 500));
  *(_DWORD *)(this + 736) = sub_5DA9A0("NIGHT", *(_DWORD *)(this + 500));
  *(_DWORD *)(this + 740) = sub_5DA9A0("SUNRISER", *(_DWORD *)(this + 500));
  *(_DWORD *)(this + 744) = sub_5DA9A0("DAYR", *(_DWORD *)(this + 500));
  *(_DWORD *)(this + 748) = sub_5DA9A0("SUNSETR", *(_DWORD *)(this + 500));
  *(_DWORD *)(this + 752) = sub_5DA9A0("NIGHTR", *(_DWORD *)(this + 500));
  if ( sub_5DA9A0("CLOUDY", *(_DWORD *)(this + 500)) )
    sub_5DB320(0, 0, 0);
  *(_DWORD *)(this + 764) = sub_5E9690("SUNRISE", 0, 0);
  *(_DWORD *)(this + 768) = sub_5E9690(&off_724984, 0, 0);
  *(_DWORD *)(this + 772) = sub_5E9690("SUNSET", 0, 0);
  *(_DWORD *)(this + 776) = sub_5E9690("NIGHT", 0, 0);
  *(_DWORD *)(this + 780) = sub_5E9690("SUNRISER", 0, 0);
  *(_DWORD *)(this + 784) = sub_5E9690("DAYR", 0, 0);
  *(_DWORD *)(this + 788) = sub_5E9690("SUNSETR", 0, 0);
  *(_DWORD *)(this + 792) = sub_5E9690("NIGHTR", 0, 0);
  *(_DWORD *)(this + 796) = 1126498304;
  *(_DWORD *)(this + 800) = 1127809024;
  *(_DWORD *)(this + 804) = 1128464384;
  *(_DWORD *)(this + 808) = 1123024896;
  *(_DWORD *)(this + 812) = 1121714176;
  *(_DWORD *)(this + 816) = 1121058816;
  *(_DWORD *)(this + 820) = 1106247680;
  *(_DWORD *)(this + 824) = 1108082688;
  *(_DWORD *)(this + 828) = 1114636288;
  *(_DWORD *)(this + 232) = 1162551296;
  *(_DWORD *)(this + 228) = 0;
  *(_DWORD *)(this + 236) = 0;
  *(_DWORD *)(this + 276) = 1118437376;
  *(_DWORD *)(this + 280) = 1118437376;
  *(_DWORD *)(this + 284) = 1118437376;
  *(_DWORD *)(this + 288) = 1110704128;
  *(_DWORD *)(this + 292) = 1110704128;
  *(_DWORD *)(this + 296) = 1110704128;
  *(_DWORD *)(this + 300) = 1112014848;
  *(_DWORD *)(this + 304) = 1112276992;
  *(_DWORD *)(this + 308) = 1113325568;
  *(_DWORD *)(this + 312) = 0;
  *(_DWORD *)(this + 316) = 1159684096;
  *(_DWORD *)(this + 320) = 0;
  *(_DWORD *)(this + 832) = 1128792064;
  *(_DWORD *)(this + 836) = 1129119744;
  *(_DWORD *)(this + 840) = 1130102784;
  *(_DWORD *)(this + 844) = 1131741184;
  *(_DWORD *)(this + 848) = 1132068864;
  *(_DWORD *)(this + 852) = 1132396544;
  *(_DWORD *)(this + 856) = 1124204544;
  *(_DWORD *)(this + 860) = 1124859904;
  *(_DWORD *)(this + 864) = 1125842944;
  *(_DWORD *)(this + 248) = 0;
  *(_DWORD *)(this + 240) = 1119092736;
  *(_DWORD *)(this + 244) = 1161527296;
  *(_DWORD *)(this + 324) = 1121058816;
  *(_DWORD *)(this + 328) = 1121058816;
  *(_DWORD *)(this + 332) = 1121058816;
  *(_DWORD *)(this + 336) = 1110704128;
  *(_DWORD *)(this + 340) = 1110704128;
  *(_DWORD *)(this + 344) = 1110704128;
  *(_DWORD *)(this + 348) = 1120403456;
  *(_DWORD *)(this + 352) = 1120927744;
  *(_DWORD *)(this + 356) = 1120796672;
  *(_DWORD *)(this + 360) = 0;
  *(_DWORD *)(this + 368) = 0;
  *(_DWORD *)(this + 364) = 1159069696;
  *(_DWORD *)(this + 868) = 1126563840;
  *(_DWORD *)(this + 872) = 1126170624;
  *(_DWORD *)(this + 876) = 1128792064;
  *(_DWORD *)(this + 880) = 1123024896;
  *(_DWORD *)(this + 884) = 1119092736;
  *(_DWORD *)(this + 888) = 1113325568;
  *(_DWORD *)(this + 892) = 1114636288;
  *(_DWORD *)(this + 896) = 1115422720;
  *(_DWORD *)(this + 900) = 1117126656;
  *(_DWORD *)(this + 252) = 1128792064;
  *(_DWORD *)(this + 260) = 0;
  *(_DWORD *)(this + 256) = 1160708096;
  *(_DWORD *)(this + 372) = 1116733440;
  *(_DWORD *)(this + 376) = 1116471296;
  *(_DWORD *)(this + 380) = 1116471296;
  *(_DWORD *)(this + 384) = 1108082688;
  *(_DWORD *)(this + 388) = 1107296256;
  *(_DWORD *)(this + 392) = 1107296256;
  *(_DWORD *)(this + 396) = 1109917696;
  *(_DWORD *)(this + 400) = 1109393408;
  *(_DWORD *)(this + 404) = 1109393408;
  *(_DWORD *)(this + 408) = 0;
  *(_DWORD *)(this + 416) = 0;
  *(_DWORD *)(this + 412) = 1159069696;
  *(_DWORD *)(this + 908) = 1104674816;
  *(_DWORD *)(this + 912) = 1106247680;
  *(_DWORD *)(this + 904) = 1103626240;
  *(_DWORD *)(this + 916) = 1100480512;
  *(_DWORD *)(this + 920) = 1101004800;
  *(_DWORD *)(this + 924) = 1103101952;
  *(_DWORD *)(this + 928) = 1082130432;
  *(_DWORD *)(this + 932) = 1088421888;
  *(_DWORD *)(this + 936) = 1092616192;
  *(_DWORD *)(this + 264) = 1130102784;
  *(_DWORD *)(this + 268) = 1155186688;
  *(_DWORD *)(this + 272) = 0;
  *(_DWORD *)(this + 420) = 1103626240;
  *(_DWORD *)(this + 424) = 1103626240;
  *(_DWORD *)(this + 428) = 1103626240;
  *(_DWORD *)(this + 432) = 1097859072;
  *(_DWORD *)(this + 436) = 1097859072;
  *(_DWORD *)(this + 440) = 1097859072;
  *(_DWORD *)(this + 448) = 1103626240;
  *(_DWORD *)(this + 444) = 1102577664;
  *(_DWORD *)(this + 452) = 1103101952;
  *(_DWORD *)(this + 456) = 0;
  *(_DWORD *)(this + 460) = 1146388480;
  *(_DWORD *)(this + 464) = 0;
  *(_DWORD *)(this + 468) = 1070945621;
  *(_DWORD *)(this + 472) = 1065794722;
  *(_DWORD *)(this + 476) = 1092616192;
  *(_DWORD *)(this + 480) = 1065353216;
  *(_DWORD *)(this + 940) = -1095545259;
  *(_DWORD *)(this + 944) = -1131481002;
  *(_DWORD *)(this + 948) = 1045178144;
  *(_DWORD *)(this + 952) = 1054632944;
  *(_DWORD *)(this + 956) = 1043452104;
  v128 = 0.0;
  v126 = 245.0;
  v119 = 0.22;
  v127 = "July 1";
  v121 = COERCE_FLOAT(sub_53A250(0));
  if ( v121 != 0.0 )
  {
    v3 = (_DWORD *)sub_616630("Latitude");
    if ( v3 )
    {
      v4 = sub_48D380(v3);
      v128 = atof(v4);
    }
    v5 = (_DWORD *)sub_616630("NorthDir");
    if ( v5 )
    {
      v6 = sub_48D380(v5);
      v126 = atof(v6);
    }
    v7 = (_DWORD *)sub_616630("RaceDate");
    if ( v7 )
      v127 = sub_48D380(v7);
    v8 = (_DWORD *)sub_616630("SunriseAmbientColour");
    if ( v8 )
    {
      v9 = sub_48D380(v8);
      sscanf(v9, "( %f , %f , %f", this + 796, this + 800, this + 804);
    }
    v10 = (_DWORD *)sub_616630("SunriseDirectionalColour");
    if ( v10 )
    {
      v11 = sub_48D380(v10);
      sscanf(v11, "( %f , %f , %f", this + 808, this + 812, this + 816);
    }
    v12 = (_DWORD *)sub_616630("SunriseFogColour");
    if ( v12 )
    {
      v13 = sub_48D380(v12);
      sscanf(v13, "( %f , %f , %f", this + 820, this + 824, this + 828);
    }
    v14 = (_DWORD *)sub_616630("DayAmbientColour");
    if ( v14 )
    {
      v15 = sub_48D380(v14);
      sscanf(v15, "( %f , %f , %f", this + 832, this + 836, this + 840);
    }
    v16 = (_DWORD *)sub_616630("DayDirectionalColour");
    if ( v16 )
    {
      v17 = sub_48D380(v16);
      sscanf(v17, "( %f , %f , %f", this + 844, this + 848, this + 852);
    }
    v18 = (_DWORD *)sub_616630("DayFogColour");
    if ( v18 )
    {
      v19 = sub_48D380(v18);
      sscanf(v19, "( %f , %f , %f", this + 856, this + 860, this + 864);
    }
    v20 = (_DWORD *)sub_616630("SunsetAmbientColour");
    if ( v20 )
    {
      v21 = sub_48D380(v20);
      sscanf(v21, "( %f , %f , %f", this + 868, this + 872, this + 876);
    }
    v22 = (_DWORD *)sub_616630("SunsetDirectionalColour");
    if ( v22 )
    {
      v23 = sub_48D380(v22);
      sscanf(v23, "( %f , %f , %f", this + 880, this + 884, this + 888);
    }
    v24 = (_DWORD *)sub_616630("SunsetFogColour");
    if ( v24 )
    {
      v25 = sub_48D380(v24);
      sscanf(v25, "( %f , %f , %f", this + 892, this + 896, this + 900);
    }
    v26 = (_DWORD *)sub_616630("NightAmbientColour");
    if ( v26 )
    {
      v27 = sub_48D380(v26);
      sscanf(v27, "( %f , %f , %f", this + 904, this + 908, this + 912);
    }
    v28 = (_DWORD *)sub_616630("NightDirectionalColour");
    if ( v28 )
    {
      v29 = sub_48D380(v28);
      sscanf(v29, "( %f , %f , %f", this + 916, this + 920, this + 924);
    }
    v30 = (_DWORD *)sub_616630("NightFogColour");
    if ( v30 )
    {
      v31 = sub_48D380(v30);
      sscanf(v31, "( %f , %f , %f", this + 928, this + 932, this + 936);
    }
    v32 = (_DWORD *)sub_616630("SunriseFogIn");
    if ( v32 )
    {
      v33 = sub_48D380(v32);
      sscanf(v33, "%f", this + 228);
    }
    v34 = (_DWORD *)sub_616630("SunriseFogOut");
    if ( v34 )
    {
      v35 = sub_48D380(v34);
      sscanf(v35, "%f", this + 232);
    }
    v36 = (_DWORD *)sub_616630("SunriseFogDensity");
    if ( v36 )
    {
      v37 = sub_48D380(v36);
      sscanf(v37, "%f", this + 236);
    }
    v38 = (_DWORD *)sub_616630("DayFogIn");
    if ( v38 )
    {
      v39 = sub_48D380(v38);
      sscanf(v39, "%f", this + 240);
    }
    v40 = (_DWORD *)sub_616630("DayFogOut");
    if ( v40 )
    {
      v41 = sub_48D380(v40);
      sscanf(v41, "%f", this + 244);
    }
    v42 = (_DWORD *)sub_616630("DayFogDensity");
    if ( v42 )
    {
      v43 = sub_48D380(v42);
      sscanf(v43, "%f", this + 248);
    }
    v44 = (_DWORD *)sub_616630("SunsetFogIn");
    if ( v44 )
    {
      v45 = sub_48D380(v44);
      sscanf(v45, "%f", this + 252);
    }
    v46 = (_DWORD *)sub_616630("SunsetFogOut");
    if ( v46 )
    {
      v47 = sub_48D380(v46);
      sscanf(v47, "%f", this + 256);
    }
    v48 = (_DWORD *)sub_616630("SunsetFogDensity");
    if ( v48 )
    {
      v49 = sub_48D380(v48);
      sscanf(v49, "%f", this + 260);
    }
    v50 = (_DWORD *)sub_616630("NightFogIn");
    if ( v50 )
    {
      v51 = sub_48D380(v50);
      sscanf(v51, "%f", this + 264);
    }
    v52 = (_DWORD *)sub_616630("NightFogOut");
    if ( v52 )
    {
      v53 = sub_48D380(v52);
      sscanf(v53, "%f", this + 268);
    }
    v54 = (_DWORD *)sub_616630("NightFogDensity");
    if ( v54 )
    {
      v55 = sub_48D380(v54);
      sscanf(v55, "%f", this + 272);
    }
    v56 = (_DWORD *)sub_616630("RainSunriseAmbientColour");
    if ( v56 )
    {
      v57 = sub_48D380(v56);
      sscanf(v57, "( %f , %f , %f", this + 276, this + 280, this + 284);
    }
    v58 = (_DWORD *)sub_616630("RainSunriseDirectionalColour");
    if ( v58 )
    {
      v59 = sub_48D380(v58);
      sscanf(v59, "( %f , %f , %f", this + 288, this + 292, this + 296);
    }
    v60 = (_DWORD *)sub_616630("RainSunriseFogColour");
    if ( v60 )
    {
      v61 = sub_48D380(v60);
      sscanf(v61, "( %f , %f , %f", this + 300, this + 304, this + 308);
    }
    v62 = (_DWORD *)sub_616630("RainDayAmbientColour");
    if ( v62 )
    {
      v63 = sub_48D380(v62);
      sscanf(v63, "( %f , %f , %f", this + 324, this + 328, this + 332);
    }
    v64 = (_DWORD *)sub_616630("RainDayDirectionalColour");
    if ( v64 )
    {
      v65 = sub_48D380(v64);
      sscanf(v65, "( %f , %f , %f", this + 336, this + 340, this + 344);
    }
    v66 = (_DWORD *)sub_616630("RainDayFogColour");
    if ( v66 )
    {
      v67 = sub_48D380(v66);
      sscanf(v67, "( %f , %f , %f", this + 348, this + 352, this + 356);
    }
    v68 = (_DWORD *)sub_616630("RainSunsetAmbientColour");
    if ( v68 )
    {
      v69 = sub_48D380(v68);
      sscanf(v69, "( %f , %f , %f", this + 372, this + 376, this + 380);
    }
    v70 = (_DWORD *)sub_616630("RainSunsetDirectionalColour");
    if ( v70 )
    {
      v71 = sub_48D380(v70);
      sscanf(v71, "( %f , %f , %f", this + 384, this + 388, this + 392);
    }
    v72 = (_DWORD *)sub_616630("RainSunsetFogColour");
    if ( v72 )
    {
      v73 = sub_48D380(v72);
      sscanf(v73, "( %f , %f , %f", this + 396, this + 400, this + 404);
    }
    v74 = (_DWORD *)sub_616630("RainNightAmbientColour");
    if ( v74 )
    {
      v75 = sub_48D380(v74);
      sscanf(v75, "( %f , %f , %f", this + 420, this + 424, this + 428);
    }
    v76 = (_DWORD *)sub_616630("RainNightDirectionalColour");
    if ( v76 )
    {
      v77 = sub_48D380(v76);
      sscanf(v77, "( %f , %f , %f", this + 432, this + 436, this + 440);
    }
    v78 = (_DWORD *)sub_616630("RainNightFogColour");
    if ( v78 )
    {
      v79 = sub_48D380(v78);
      sscanf(v79, "( %f , %f , %f", this + 444, this + 448, this + 452);
    }
    v80 = (_DWORD *)sub_616630("RainSunriseFogIn");
    if ( v80 )
    {
      v81 = sub_48D380(v80);
      sscanf(v81, "%f", this + 312);
    }
    v82 = (_DWORD *)sub_616630("RainSunriseFogOut");
    if ( v82 )
    {
      v83 = sub_48D380(v82);
      sscanf(v83, "%f", this + 316);
    }
    v84 = (_DWORD *)sub_616630("RainSunriseFogDensity");
    if ( v84 )
    {
      v85 = sub_48D380(v84);
      sscanf(v85, "%f", this + 320);
    }
    v86 = (_DWORD *)sub_616630("RainDayFogIn");
    if ( v86 )
    {
      v87 = sub_48D380(v86);
      sscanf(v87, "%f", this + 360);
    }
    v88 = (_DWORD *)sub_616630("RainDayFogOut");
    if ( v88 )
    {
      v89 = sub_48D380(v88);
      sscanf(v89, "%f", this + 364);
    }
    v90 = (_DWORD *)sub_616630("RainDayFogDensity");
    if ( v90 )
    {
      v91 = sub_48D380(v90);
      sscanf(v91, "%f", this + 368);
    }
    v92 = (_DWORD *)sub_616630("RainSunsetFogIn");
    if ( v92 )
    {
      v93 = sub_48D380(v92);
      sscanf(v93, "%f", this + 408);
    }
    v94 = (_DWORD *)sub_616630("RainSunsetFogOut");
    if ( v94 )
    {
      v95 = sub_48D380(v94);
      sscanf(v95, "%f", this + 412);
    }
    v96 = (_DWORD *)sub_616630("RainSunsetFogDensity");
    if ( v96 )
    {
      v97 = sub_48D380(v96);
      sscanf(v97, "%f", this + 416);
    }
    v98 = (_DWORD *)sub_616630("RainNightFogIn");
    if ( v98 )
    {
      v99 = sub_48D380(v98);
      sscanf(v99, "%f", this + 456);
    }
    v100 = (_DWORD *)sub_616630("RainNightFogOut");
    if ( v100 )
    {
      v101 = sub_48D380(v100);
      sscanf(v101, "%f", this + 460);
    }
    v102 = (_DWORD *)sub_616630("RainNightFogDensity");
    if ( v102 )
    {
      v103 = sub_48D380(v102);
      sscanf(v103, "%f", this + 464);
    }
    v104 = (_DWORD *)sub_616630("RainLightScale");
    if ( v104 )
    {
      v105 = sub_48D380(v104);
      sscanf(v105, "%f", this + 468);
      *(float *)(this + 468) = 1.0 / *(float *)(this + 468);
    }
    v106 = (_DWORD *)sub_616630("RainFogScale");
    if ( v106 )
    {
      v107 = sub_48D380(v106);
      sscanf(v107, "%f", this + 472);
      *(float *)(this + 472) = 1.0 / *(float *)(this + 472);
    }
    v108 = (_DWORD *)sub_616630("RainFogColourScale");
    if ( v108 )
    {
      v109 = sub_48D380(v108);
      sscanf(v109, "%f", this + 476);
      *(float *)(this + 476) = 1.0 / *(float *)(this + 476);
    }
    v110 = (_DWORD *)sub_616630("RainCloudScale");
    if ( v110 )
    {
      v111 = sub_48D380(v110);
      sscanf(v111, "%f", this + 480);
      *(float *)(this + 480) = 1.0 / *(float *)(this + 480);
    }
    v112 = (_DWORD *)sub_616630("SkyBlendSunAngles");
    if ( v112 )
    {
      v113 = sub_48D380(v112);
      if ( sscanf(v113, "( %f , %f , %f , %f", &v122, &v123, &v124, &v125) == 4
        && v122 < (double)v123
        && v123 <= (double)v124
        && v124 < (double)v125 )
      {
        *(float *)(this + 940) = sin(v122 * 0.017453292);
        *(float *)(this + 944) = sin(v123 * 0.017453292);
        *(float *)(this + 948) = sin(v124 * 0.017453292);
        *(float *)(this + 952) = sin(v125 * 0.017453292);
      }
      else if ( sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\weather.cpp", 1070) )
      {
        sub_561210(
          (int)byte_FAE910,
          "Could not read all four SkyBlendRange parameters in GDB or values were out of order");
      }
    }
    v114 = (_DWORD *)sub_616630("ShadowMinSunAngle");
    if ( v114 )
    {
      v115 = sub_48D380(v114);
      if ( sscanf(v115, "%f", &v121) )
        *(float *)(this + 956) = sin(v121 * 0.017453292);
    }
  }
  if ( sscanf(v127, "%s %d", String1, &v120) != 2 )
    goto LABEL_158;
  String1[3] = 0;
  if ( !_stricmp(String1, "Jan") )
  {
    v116 = (double)v120 + 0.5;
  }
  else if ( !_stricmp(String1, off_724CD0) )
  {
    v116 = (double)v120 + 31.5;
  }
  else if ( !_stricmp(String1, off_724CC8) )
  {
    v116 = (double)v120 + 59.75;
  }
  else if ( !_stricmp(String1, off_724CC0) )
  {
    v116 = (double)v120 + 89.75;
  }
  else if ( !_stricmp(String1, off_724CB8) )
  {
    v116 = (double)v120 + 119.75;
  }
  else if ( !_stricmp(String1, off_724CB0) )
  {
    v116 = (double)v120 + 150.75;
  }
  else if ( !_stricmp(String1, "Jul") )
  {
    v116 = (double)v120 + 180.75;
  }
  else if ( !_stricmp(String1, "Aug") )
  {
    v116 = (double)v120 + 211.75;
  }
  else if ( !_stricmp(String1, off_724C98) )
  {
    v116 = (double)v120 + 242.75;
  }
  else if ( !_stricmp(String1, off_724C90) )
  {
    v116 = (double)v120 + 272.75;
  }
  else if ( !_stricmp(String1, off_724C88) )
  {
    v116 = (double)v120 + 303.75;
  }
  else
  {
    if ( _stricmp(String1, "Dec") )
      goto LABEL_158;
    v116 = (double)v120 + 333.75;
  }
  v119 = v116 * 0.0027378509;
  if ( v119 < 0.0 )
  {
    sub_592C90((float *)(this + 636), v128, v126, 0.0);
    goto LABEL_159;
  }
  if ( v119 > 1.0 )
    v119 = 1.0;
LABEL_158:
  sub_592C90((float *)(this + 636), v128, v126, v119);
LABEL_159:
  sub_596970();
  result = sub_5DA9A0("SKYBOXI", 0);
  *(_DWORD *)(this + 500) = result;
  if ( result )
    result = sub_5DA7A0(this + 504, this + 508, this + 512);
  *(_DWORD *)(this + 516) = -1;
  *(_DWORD *)(this + 632) = -1082130432;
  *(_BYTE *)(this + 692) = 0;
  return result;
}
