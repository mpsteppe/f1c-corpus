int __userpurge sub_533F30@<eax>(int a1@<ecx>, char *a2@<edi>, int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // edi
  const char *v6; // eax
  int v7; // esi
  unsigned __int8 v8; // bl
  int v9; // edi
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
  int v22; // ecx
  int v23; // eax
  char v24; // al
  int v25; // eax
  int v26; // eax
  int v27; // eax
  char *v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // esi
  _DWORD *v32; // eax
  _DWORD *v33; // esi
  char *v34; // eax
  char *v35; // eax
  char *v36; // eax
  char *v37; // eax
  char *v38; // eax
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
  int result; // eax
  char *v53[5]; // [esp+0h] [ebp-20h] BYREF
  int v54; // [esp+14h] [ebp-Ch]
  int v55; // [esp+18h] [ebp-8h]
  int v56; // [esp+1Ch] [ebp-4h]
  int retaddr; // [esp+20h] [ebp+0h]

  v53[0] = a2;
  v3 = __readeflags();
  v4 = dword_16C6EFC - (dword_16DF655 + 1);
  __writeeflags(v3);
  _InterlockedExchange((volatile __int32 *)v53, v4);
  v56 = sub_616840(v53[0]);
  v6 = Str;
  if ( !Str )
    v6 = WindowName;
  if ( strstr(v6, "Custom") )
  {
    v7 = dword_B70568;
    v8 = byte_B707BD;
    v9 = dword_B72E9C;
    v55 = dword_B72FE0;
    v54 = dword_B70424;
    v10 = (_DWORD *)sub_616840("Full Course Yellows");
    if ( v10 )
    {
      v11 = sub_48D380(v10);
      atol(v11);
    }
    v12 = (_DWORD *)sub_616840("Flag Rules");
    if ( v12 )
    {
      v13 = sub_48D380(v12);
      v7 = atol(v13);
    }
    v14 = (_DWORD *)sub_616840("Time Scaled Weather");
    if ( v14 )
    {
      v15 = sub_48D380(v14);
      v8 = atol(v15) != 0;
    }
    v16 = (_DWORD *)sub_616840("Safetycar Threshold");
    if ( v16 )
    {
      v17 = sub_48D380(v16);
      *(float *)&v54 = atof(v17);
    }
    v18 = (_DWORD *)sub_616840("Fuel Multiplier");
    if ( v18 )
    {
      v19 = sub_48D380(v18);
      v9 = atol(v19);
    }
    v20 = (_DWORD *)sub_616840("Tire Multiplier");
    if ( v20 )
    {
      v21 = sub_48D380(v20);
      v22 = atol(v21);
    }
    else
    {
      v22 = v55;
    }
    v23 = dword_B7056C;
    dword_B70564 = v7;
    if ( v7 < dword_B7056C || (v23 = dword_B70570, v7 > dword_B70570) )
      dword_B70564 = v23;
    v24 = byte_B707BE;
    byte_B707BC = v8;
    if ( v8 < (unsigned __int8)byte_B707BE || (v24 = byte_B707BF, v8 > (unsigned __int8)byte_B707BF) )
      byte_B707BC = v24;
    dword_B70420 = v54;
    if ( *(float *)&v54 >= (double)flt_B70428 )
    {
      if ( *(float *)&v54 > (double)flt_B7042C )
        dword_B70420 = LODWORD(flt_B7042C);
    }
    else
    {
      dword_B70420 = LODWORD(flt_B70428);
    }
    v25 = dword_B72EA0;
    dword_B72E98 = v9;
    if ( v9 < dword_B72EA0 || (v25 = dword_B72EA4, v9 > dword_B72EA4) )
      dword_B72E98 = v25;
    v26 = dword_B72FE4;
    dword_B72FDC = v22;
    if ( v22 < dword_B72FE4 || (v26 = dword_B72FE8, v22 > dword_B72FE8) )
      dword_B72FDC = v26;
  }
  if ( !v56 )
    return 0;
  v27 = sub_616610(a3);
  if ( !v27 )
    return 0;
  v28 = (char *)sub_6165E0(v27);
  v29 = sub_53A250(v28);
  if ( !v29 )
    return 0;
  v30 = sub_6165E0(v29);
  sub_538860(&unk_BE1CFD, v30, v53[1], v53[2]);
  v31 = dword_BE1CD8 + 396 * dword_BE1CD4;
  v55 = a1 + 95680;
  sub_615860(v31 + 260);
  sub_615860(v31 + 4);
  v32 = (_DWORD *)sub_616630("SpecialEvent");
  v33 = v32;
  if ( v32 )
  {
    v34 = sub_48D380(v32);
    if ( sub_616480(v34, "CONTINUE") )
      *(_BYTE *)(a1 + 95712) = 1;
    v35 = sub_48D380(v33);
    if ( sub_616480(v35, "DISCARDDAMAGED") )
      *(_BYTE *)(a1 + 95714) = 1;
    v36 = sub_48D380(v33);
    if ( sub_616480(v36, "NOPOINTS") )
      *(_BYTE *)(a1 + 95713) = 1;
    v37 = sub_48D380(v33);
    if ( sub_616480(v37, "LAPSADDED") )
      *(_BYTE *)(a1 + 95715) = 1;
    v38 = sub_48D380(v33);
    if ( sub_616480(v38, "DOUBLEPOINTS") )
      *(_BYTE *)(a1 + 95716) = 1;
    v39 = sub_48D380(v33);
    if ( sub_616480(v39, "ENDURANCE") )
      *(_BYTE *)(a1 + 95717) = 1;
  }
  v40 = (_DWORD *)sub_616630("QualifyLaps");
  if ( v40 )
  {
    v41 = sub_48D380(v40);
    *(_DWORD *)(a1 + 95696) = atol(v41);
  }
  else
  {
    *(_DWORD *)(a1 + 95696) = -1;
  }
  v42 = (_DWORD *)sub_616630("QualifyTime");
  if ( v42 )
  {
    v43 = sub_48D380(v42);
    *(_DWORD *)(a1 + 95700) = atol(v43);
  }
  else
  {
    *(_DWORD *)(a1 + 95700) = -1;
  }
  v44 = (_DWORD *)sub_616630("RaceLaps");
  if ( v44 )
  {
    v45 = sub_48D380(v44);
    *(_DWORD *)(a1 + 95704) = atol(v45);
  }
  else
  {
    *(_DWORD *)(a1 + 95704) = -1;
  }
  v46 = (_DWORD *)sub_616630("RaceTime");
  if ( v46 )
  {
    v47 = sub_48D380(v46);
    *(_DWORD *)(a1 + 95708) = atol(v47);
  }
  else
  {
    *(_DWORD *)(a1 + 95708) = -1;
  }
  v48 = (_DWORD *)sub_616630("Weather");
  if ( v48 )
  {
    v49 = sub_48D380(v48);
    *(_DWORD *)(a1 + 95720) = atol(v49);
  }
  else
  {
    *(_DWORD *)(a1 + 95720) = 0;
  }
  v50 = (_DWORD *)sub_616630("StartMode");
  if ( v50 )
  {
    v51 = sub_48D380(v50);
    *(_DWORD *)(a1 + 95724) = sub_616480(v51, "StandingStart") == 0;
  }
  if ( retaddr >= *(_DWORD *)(a1 + 95736) )
  {
    result = v55;
    *(_DWORD *)(a1 + 95728) = -1;
  }
  else
  {
    *(_DWORD *)(a1 + 95728) = *(_DWORD *)(a1 + 4 * retaddr + 94784);
    return v55;
  }
  return result;
}
