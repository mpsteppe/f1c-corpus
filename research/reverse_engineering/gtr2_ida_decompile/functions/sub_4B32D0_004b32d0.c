int sub_4B32D0()
{
  int v0; // esi
  int v1; // esi
  _DWORD *v2; // eax
  char *v3; // eax
  double v4; // st7
  _DWORD *v5; // eax
  char *v6; // eax
  double v7; // st7
  int v8; // ecx
  _DWORD *v9; // esi
  char *v10; // eax
  int v11; // eax
  float v13; // [esp+Ch] [ebp-214h]
  float v14; // [esp+10h] [ebp-210h] BYREF
  float v15; // [esp+14h] [ebp-20Ch] BYREF
  char v16[61]; // [esp+18h] [ebp-208h] BYREF
  __int16 v17; // [esp+55h] [ebp-1CBh]
  char v18; // [esp+57h] [ebp-1C9h]
  char v19[252]; // [esp+58h] [ebp-1C8h] BYREF
  _BYTE v20[4]; // [esp+154h] [ebp-CCh] BYREF
  _BYTE v21[136]; // [esp+158h] [ebp-C8h] BYREF
  int v22; // [esp+1E0h] [ebp-40h]
  int v23; // [esp+1E4h] [ebp-3Ch]
  int v24; // [esp+218h] [ebp-8h]
  int v25; // [esp+21Ch] [ebp-4h]

  memset(v16, 0, sizeof(v16));
  v17 = 0;
  v18 = 0;
  if ( (unsigned __int8)sub_4735A0() )
  {
    sub_4744E0(v21);
    v25 = 0;
    if ( (unsigned __int8)sub_473900() )
    {
      if ( v23 )
      {
        v0 = v23;
        strcpy((char *)&v15, sub_41D840(&byte_91CC38, "Race Laps:"));
        sprintf(&v16[60], "%s %d", (const char *)&v15, v0);
      }
      else
      {
        v1 = v22;
        strcpy((char *)&v15, sub_41D840(&byte_91CC38, "Race Time:"));
        sprintf(&v16[60], "%s %d:%02d", (const char *)&v15, v1 / 60, v1 % 60);
      }
      sub_4CE020(&v16[60]);
    }
    v24 = -1;
    nullsub_7(v20);
    return 0;
  }
  if ( *(_DWORD *)dword_B72314 == 1 )
  {
    sub_4CE020(WindowName);
    return 0;
  }
  v13 = *(&flt_B728A4 + 9 * *(_DWORD *)dword_B72314);
  if ( byte_B729E8 && !byte_B722E4 && *(_DWORD *)dword_B72314 != 4 )
  {
    v15 = *(&flt_B728A4 + 9 * *(_DWORD *)dword_B72314);
    if ( sub_53A250(0) )
    {
      v2 = (_DWORD *)sub_616630("RaceLaps");
      if ( v2 )
      {
        v3 = sub_48D380(v2);
        v4 = (double)atol(v3) * v15;
        strcpy(v16, sub_41D840(&byte_91CC38, "Race Laps:"));
        sprintf(v19, "%s %d", v16, (unsigned int)(unsigned __int64)v4);
      }
    }
    sub_4CE020(v19);
    return 0;
  }
  if ( (!sub_53A250(0) || (v5 = (_DWORD *)sub_616630("RaceTimeScaled")) == 0)
    && (!sub_616840("DefaultScoring") || (v5 = (_DWORD *)sub_616630("RaceTimeScaled")) == 0) )
  {
    v7 = *(&flt_B728A4 + 9 * *(_DWORD *)dword_B72314) * 120.0;
    goto LABEL_24;
  }
  v6 = sub_48D380(v5);
  if ( sscanf(v6, "%f", &v14) == 1 )
  {
    v7 = v14 * *(&flt_B728A4 + 9 * *(_DWORD *)dword_B72314);
LABEL_24:
    v13 = v7;
  }
  if ( byte_B722E4 )
    v13 = *(float *)&dword_B72A00 * 1440.0;
  strcpy(v16, sub_41D840(&byte_91CC38, "Race Time:"));
  sprintf(
    v19,
    "%s %2.1d:%02d",
    v16,
    abs32((unsigned __int64)(v13 * 0.016666668)),
    (unsigned int)(unsigned __int64)fabs(fmod(v13, 60.0)));
  if ( *(_DWORD *)dword_B72314 == 4 && !byte_B722E4 )
  {
    if ( sub_616840("SceneOrder") )
    {
      v8 = dword_BE1CD8 + 396 * dword_BE1CD4;
      if ( v8 )
      {
        if ( sub_616630((char *)(v8 + 260)) )
        {
          v9 = (_DWORD *)sub_616630("RaceLaps");
          if ( v9 )
          {
            strcpy(v16, sub_41D840(&byte_91CC38, "Race Laps:"));
            v10 = sub_48D380(v9);
            v11 = atol(v10);
            sprintf(v19, "%s %d", v16, v11);
          }
        }
      }
    }
  }
  sub_4CE020(v19);
  return 0;
}
