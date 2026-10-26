int __thiscall sub_481D60(const CHAR ****this)
{
  const CHAR *v2; // eax
  const CHAR *v3; // esi
  const CHAR *v4; // eax
  const CHAR *v5; // eax
  const CHAR *v6; // eax
  const CHAR ***v7; // eax
  bool v8; // zf
  const CHAR **i; // eax
  const CHAR *v10; // eax
  const CHAR ***v11; // eax
  const CHAR ***v12; // eax
  char v14; // [esp+10h] [ebp-78h]
  char v15; // [esp+14h] [ebp-74h]
  double v16; // [esp+14h] [ebp-74h]
  char v17; // [esp+1Ch] [ebp-6Ch]
  char ArgList[4]; // [esp+20h] [ebp-68h] BYREF
  int v19; // [esp+84h] [ebp-4h]

  sub_613B30(ArgList);
  v2 = dword_91CB00;
  v19 = 0;
  if ( !dword_91CB00 )
    v2 = WindowName;
  sub_615860(v2);
  sub_615A50("DedicatedServer.ini");
  v3 = (const CHAR *)this[215];
  if ( !v3 )
    v3 = WindowName;
  if ( (unsigned __int8)sub_6146B0(v3, 0, 1, 1, 1) )
  {
    sub_613D30((int)ArgList, "//\n// Dedicated Server configuration file\n//\n\n", v17);
    sub_613D30((int)ArgList, "[SETTINGS]\n", v15);
    sub_613D30((int)ArgList, "DSFM=%d\n", dword_B6CE80[0]);
    LOBYTE(v4) = dword_759EB8[0];
    if ( !*(_DWORD *)dword_759EB8 )
      v4 = WindowName;
    sub_613D30((int)ArgList, "GameDatabase=\"%s\"\n", (char)v4);
    sub_613D30((int)ArgList, "ConnectionType=%d\n", dword_B6CE7C[0]);
    sub_613D30((int)ArgList, "UploadSpeed=%d\n", lParam);
    sub_613D30((int)ArgList, "MaxPlayers=%d\n", dword_759E4C[0]);
    LOBYTE(v5) = dword_759EC0;
    if ( !dword_759EC0 )
      v5 = WindowName;
    sub_613D30((int)ArgList, "RaceName=\"%s\"\n", (char)v5);
    LOBYTE(v6) = dword_759EC8;
    if ( !dword_759EC8 )
      v6 = WindowName;
    sub_613D30((int)ArgList, "Password=\"%s\"\n", (char)v6);
    sub_613D30((int)ArgList, "FlagRules=%d\n", wParam);
    sub_613D30((int)ArgList, "FuelUsage=%d\n", dword_759E58);
    sub_613D30((int)ArgList, "TireUsage=%d\n", dword_759E5C[0]);
    sub_613D30((int)ArgList, "MechFailures=%d\n", dword_759E60[0]);
    sub_613D30((int)ArgList, "Weather=%d\n", dword_B6CE8C[0]);
    v16 = flt_B6CE90;
    sub_613D30((int)ArgList, "RainAmount=%f\n", SLOBYTE(v16));
    sub_613D30((int)ArgList, "AllowSteerHelp=%d\n", byte_759E64);
    sub_613D30((int)ArgList, "AllowBrakeHelp=%d\n", byte_759E65);
    sub_613D30((int)ArgList, "AllowABS=%d\n", byte_759E66);
    sub_613D30((int)ArgList, "AllowTraction=%d\n", byte_759E67);
    sub_613D30((int)ArgList, "AllowStability=%d\n", byte_759E68);
    sub_613D30((int)ArgList, "AllowInvulnerable=%d\n", byte_B6CE94);
    sub_613D30((int)ArgList, "AllowSpinRecover=%d\n", byte_759E69);
    sub_613D30((int)ArgList, "AllowAutoShift=%d\n", byte_759E6A);
    sub_613D30((int)ArgList, "AllowAutoClutch=%d\n", byte_759E6B);
    sub_613D30((int)ArgList, "AllowAutoPit=%d\n", byte_759E6C);
    sub_613D30((int)ArgList, "AllowDupVehicles=%d\n", byte_B6CE95);
    sub_613D30((int)ArgList, "ForceCockpit=%d\n", byte_B6CE96);
    sub_613D30((int)ArgList, "AllowAIControl=%d\n", byte_759E6D);
    sub_613D30((int)ArgList, "DamageMultiplier=%d\n", dword_759E70[0]);
    sub_613D30((int)ArgList, "StartHour=%d\n", dword_759E74[0]);
    sub_613D30((int)ArgList, "LobbyBroadcast=%d\n", byte_B6CEA0);
    sub_613D30((int)ArgList, "UniqueLobbyUsername=\"%s\"\n", dword_759ED8[0]);
    sub_613D30((int)ArgList, "UniqueLobbyPassword=\"%s\"\n", dword_759EE0[0]);
    sub_613D30((int)ArgList, "LiveReporting=%d\n", byte_B6CEA1);
    sub_613D30((int)ArgList, "LivePeriod=\"%s\"\n", (char)dword_759EF0);
    sub_613D30((int)ArgList, "LiveUpdates=%d\n", byte_B6CEA2);
    sub_613D30((int)ArgList, "LiveUpdatePeriod=\"%s\"\n", (char)dword_759EF8);
    sub_613D30((int)ArgList, "SessionPractice1=%d\n", byte_759E78);
    sub_613D30((int)ArgList, "SessionPractice2=%d\n", byte_B6CE97);
    sub_613D30((int)ArgList, "SessionQualify1=%d\n", byte_B6CE98);
    sub_613D30((int)ArgList, "SessionQualify2=%d\n", byte_B6CE99);
    sub_613D30((int)ArgList, "SessionWarmup=%d\n", byte_B6CE9A);
    sub_613D30((int)ArgList, "SessionRace=%d\n", byte_B6CE9B);
    sub_613D30((int)ArgList, "SessionPractice1Mins=%d\n", dword_759E7C[0]);
    sub_613D30((int)ArgList, "SessionPractice2Mins=%d\n", dword_759E80[0]);
    sub_613D30((int)ArgList, "SessionQualify1Mins=%d\n", dword_759E84[0]);
    sub_613D30((int)ArgList, "SessionQualify2Mins=%d\n", dword_759E88[0]);
    sub_613D30((int)ArgList, "SessionWarmupMins=%d\n", dword_759E8C[0]);
    sub_613D30((int)ArgList, "SessionRaceMins=%d\n", dword_759E90[0]);
    sub_613D30((int)ArgList, "SessionRaceLaps=%d\n", dword_B6CE9C[0]);
    sub_613D30((int)ArgList, "RaceStart=%d\n", dword_759E94[0]);
    sub_613D30((int)ArgList, "SkipFormation=%d\n", dword_759E98[0]);
    sub_613D30((int)ArgList, "DifficultyMode=%d\n", dword_B6CE88[0]);
    sub_613D30((int)ArgList, "EnableCollisions=%d\n", byte_759E9C);
    sub_613D30((int)ArgList, "\n[TRACKS]\n", v14);
    v7 = *this;
    v8 = *this == 0;
    this[2] = *this;
    if ( !v8 )
    {
      for ( i = *v7; i; i = *v12 )
      {
        v10 = *i;
        if ( !v10 )
          v10 = WindowName;
        sub_613D30((int)ArgList, "%s\n", (char)v10);
        v11 = this[2];
        if ( !v11 )
          break;
        v12 = (const CHAR ***)v11[1];
        this[2] = v12;
        if ( !v12 )
          break;
      }
    }
    sub_613C30(ArgList);
  }
  v19 = -1;
  return sub_614140(ArgList);
}
