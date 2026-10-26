// positive sp value has been detected, the output may be wrong!
char __userpurge sub_41AAFD@<al>(int a1@<eax>, int *a2@<ebp>, int a3@<esi>, char String)
{
  unsigned int v4; // kr00_4
  __int32 v5; // ebx
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  void *v10; // eax
  void *v11; // edi
  _DWORD v12[2]; // [esp-11Ch] [ebp-144h] BYREF
  _DWORD v13[3]; // [esp-114h] [ebp-13Ch] BYREF
  _DWORD v14[3]; // [esp-108h] [ebp-130h] BYREF
  char v15; // [esp-FCh] [ebp-124h] BYREF
  __int32 v16; // [esp-F8h] [ebp-120h] BYREF
  char v17[8]; // [esp-F0h] [ebp-118h] BYREF
  void *v18; // [esp-E8h] [ebp-110h]
  int v19; // [esp-E4h] [ebp-10Ch] BYREF
  int v20; // [esp+24h] [ebp-4h]

  while ( 1 )
  {
    v4 = __readeflags();
    v5 = dword_16C6C98 - *(_DWORD *)sub_41A700;
    __writeeflags(v4);
    v6 = _InterlockedExchange(&v16, v5);
    if ( !(*(int (__thiscall **)(int *, char *))(a1 + 36))(a2, byte_903710) )
      break;
    v7 = sub_612EB0(&unk_9034F8) - v6;
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( !v8 || v8 == 3 )
        return 0;
    }
    else if ( strstr(byte_903710, "[CAREERSEASON]") )
    {
      v10 = operator new(0x17614u);
      v18 = v10;
      v20 = v6;
      if ( v10 == (void *)v6 )
        v11 = 0;
      else
        v11 = (void *)((int (__thiscall *)(void *))sub_5322F0)(v10);
      v20 = -1;
      if ( (unsigned __int8)((int (__thiscall *)(void *, int *))sub_532440)(v11, a2) )
      {
        sub_5FDFB0(v11, 1);
      }
      else if ( v11 != (void *)v6 )
      {
        ((void (__thiscall *)(void *))sub_5323C0)(v11);
        j__free(v11);
      }
    }
    else if ( strstr(byte_903710, "[PLAYERTRACKSTAT]") )
    {
      sub_5343E0(a2);
    }
    else
    {
      sub_6133A0("ABORTEDSEASONS", a3 + 32, v6, v6, v6);
      sub_6133A0("TOTALLAPS", a3 + 36, v6, v6, v6);
      sub_6133A0("TOTALRACES", a3 + 40, v6, v6, v6);
      sub_6133A0("TOTALRACESWITHAI", a3 + 44, v6, v6, v6);
      sub_6133A0("TOTALPOINTSSCORED", a3 + 48, v6, v6, v6);
      sub_6133A0("TOTALCHAMPIONSHIPS", a3 + 52, v6, v6, v6);
      sub_6133A0("TOTALWINS", a3 + 56, v6, v6, v6);
      sub_6133A0("TOTALPOLES", a3 + 60, v6, v6, v6);
      sub_6133A0("TOTALLAPRECORDS", a3 + 64, v6, v6, v6);
      v14[2] = v6;
      v14[1] = &v19;
      v14[0] = "AVGSTARTPOSITION";
      if ( sub_6137E0(&unk_9034F8) )
        *(float *)(a3 + 68) = atof(v17);
      v13[2] = v6;
      v13[1] = v17;
      v13[0] = "AVGFINISHPOSITION";
      if ( sub_6137E0(&unk_9034F8) )
        *(float *)(a3 + 72) = atof(&v15);
      v12[1] = v6;
      v12[0] = &v15;
      if ( sub_6137E0(&unk_9034F8) )
        *(float *)(a3 + 76) = atof((const char *)v14);
      if ( sub_6137E0(&unk_9034F8) )
        *(float *)(a3 + 80) = atof((const char *)v13);
      v12[0] = v6;
      if ( sub_6133A0("MECHFAIL_rate", (int)v12, v6, v6, v6) )
        *(_DWORD *)(a3 + 84) = v12[0];
      sub_6133A0("RACECOND_reconnaissance", a3 + 88, v6, v6, v6);
      sub_6133A0("RACECOND_walkthrough", a3 + 92, v6, v6, v6);
      sub_6134B0("RACECOND_safetycar_thresh", a3 + 100, v6, v6, v6, v6, v6, v6, v6);
      if ( sub_6133A0("RACECOND_flag_rules", (int)v12, v6, v6, v6) )
        *(_DWORD *)(a3 + 104) = v12[0];
      if ( sub_6133A0("RACECOND_weather", (int)v12, v6, v6, v6) )
        *(_DWORD *)(a3 + 108) = v12[0];
      if ( sub_6133A0("RACECOND_timescaled_weather", (int)v12, v6, v6, v6) )
        *(_BYTE *)(a3 + 112) = v12[0] != v6;
      sub_6133A0("GAMEOPT_qualify_laps", a3 + 116, v6, v6, v6);
      sub_6133A0("GAMEOPT_race_laps", a3 + 120, v6, v6, v6);
      sub_6133A0("GAMEOPT_race_time", a3 + 124, v6, v6, v6);
      sub_6134B0("GAMEOPT_race_length", a3 + 128, v6, v6, v6, v6, v6, v6, v6);
      sub_6134B0("GAMEOPT_endurance_race_length", a3 + 132, v6, v6, v6, v6, v6, v6, v6);
      sub_6133A0("GAMEOPT_opponents", a3 + 136, v6, v6, v6);
      sub_6133A0("GAMEOPT_fuel_mult", a3 + 140, v6, v6, v6);
      sub_6133A0("GAMEOPT_tire_mult", a3 + 144, v6, v6, v6);
      sub_6133A0("GAMEOPT_speed_comp", a3 + 148, v6, v6, v6);
    }
    a1 = *a2;
  }
  return 0;
}
