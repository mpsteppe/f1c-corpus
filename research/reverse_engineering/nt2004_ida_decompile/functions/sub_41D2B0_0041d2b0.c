char __thiscall sub_41D2B0(int this, char *FileName)
{
  size_t v3; // esi
  unsigned int v4; // kr04_4
  char *v5; // esi
  FILE *v6; // edi
  int v8; // eax
  const char *v9; // ecx
  const char *v10; // eax
  size_t v11; // esi
  unsigned int v12; // kr08_4
  char *v13; // eax
  const char *v14; // ecx
  const char *v15; // eax
  size_t v16; // esi
  unsigned int v17; // kr0C_4
  char *v18; // eax
  const char *v19; // ecx
  const char *v20; // eax
  size_t v21; // esi
  unsigned int v22; // kr10_4
  char *v23; // ecx
  const char *v24; // eax
  const char *v25; // ecx
  const char *v26; // eax
  size_t v27; // esi
  unsigned int v28; // kr14_4
  int v29; // eax
  bool v30; // sf
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // [esp+0h] [ebp-1B38h]
  int v36; // [esp+14h] [ebp-1B24h] BYREF
  char v37; // [esp+1Bh] [ebp-1B1Dh]
  FILE *v38; // [esp+1Ch] [ebp-1B1Ch]
  CHAR pszPath[256]; // [esp+20h] [ebp-1B18h] BYREF
  CHAR NewFileName[256]; // [esp+120h] [ebp-1A18h] BYREF
  char String[384]; // [esp+220h] [ebp-1918h] BYREF
  int v42; // [esp+3A0h] [ebp-1798h]
  char v43; // [esp+3A4h] [ebp-1794h]
  int v44; // [esp+3ACh] [ebp-178Ch]
  int v45; // [esp+3B0h] [ebp-1788h]
  int v46; // [esp+3B4h] [ebp-1784h]
  char Str[384]; // [esp+3B8h] [ebp-1780h] BYREF
  char Source[509]; // [esp+538h] [ebp-1600h] BYREF
  __int16 v49; // [esp+735h] [ebp-1403h]
  char v50; // [esp+737h] [ebp-1401h]
  char Destination[509]; // [esp+738h] [ebp-1400h] BYREF
  __int16 v52; // [esp+935h] [ebp-1203h]
  char v53; // [esp+937h] [ebp-1201h]
  char v54[1024]; // [esp+B38h] [ebp-1000h] BYREF
  char v55[1024]; // [esp+F38h] [ebp-C00h] BYREF
  char Path[1024]; // [esp+1338h] [ebp-800h] BYREF
  char v57[1024]; // [esp+1738h] [ebp-400h] BYREF

  memset(Str, 0, sizeof(Str));
  v42 = 0;
  v46 = 0;
  v44 = 0;
  v45 = 0;
  v43 = 1;
  v37 = 0;
  sub_41E8F0(pszPath);
  if ( (!strcmp(pszPath, aWindowsXp) || !strcmp(pszPath, aWindowsNt) || !strcmp(pszPath, aWindows2000))
    && !(unsigned __int8)sub_41EA80(this) )
  {
    v37 = 1;
    if ( SHGetSpecialFolderPathA(0, pszPath, 5, 1) >= 0 )
    {
      sprintf(NewFileName, "%s\\%s", pszPath, aNascarThunder2);
      if ( _access(NewFileName, 0) == -1 )
      {
        v3 = 0;
        v4 = strlen(NewFileName) + 1;
        if ( (int)(v4 - 1) > 0 )
        {
          do
          {
            if ( v3 >= 0x400 )
              break;
            if ( NewFileName[v3] == 92 )
            {
              strncpy(Destination, NewFileName, v3);
              Destination[v3] = 0;
              _mkdir(Destination);
            }
            ++v3;
          }
          while ( (int)v3 < (int)(v4 - 1) );
        }
        _mkdir(NewFileName);
        sub_578600(NewFileName);
        sprintf(NewFileName, "%s\\%s%s", pszPath, aNascarThunder2, ExistingFileName);
        sub_578600(NewFileName);
        CopyFileA(ExistingFileName, NewFileName, 1);
      }
      else
      {
        sub_578600(NewFileName);
        sprintf(NewFileName, "%s\\%s%s", pszPath, aNascarThunder2, ExistingFileName);
        sub_578600(NewFileName);
      }
    }
  }
  v5 = FileName;
  if ( !FileName )
  {
    v5 = *(char **)this;
    if ( !*(_DWORD *)this )
      v5 = &byte_629120;
  }
  v6 = fopen(v5, Mode);
  v38 = v6;
  if ( !v6 )
  {
    if ( !(unsigned __int8)sub_41E340((Concurrency::details::SchedulerBase *)this, v5) )
    {
      if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_1, 476) )
      {
        sub_500FE0((int)&unk_7D7920, aCouldNotCreate, (char)v5);
        return 0;
      }
      return 0;
    }
    v6 = fopen(v5, Mode);
    v38 = v6;
    if ( !v6 )
    {
      if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_1, 486) )
        sub_500FE0((int)&unk_7D7920, aSuccessfullyCr, (char)v5);
      return 0;
    }
  }
  while ( fgets(Str, 256, v6) )
  {
    if ( !sub_577B60(String) )
    {
      if ( strstr(Str, aComponents) )
      {
        while ( fgets(Str, 256, v6) )
        {
          v8 = sub_577B60(String);
          v36 = v8;
          if ( v8 )
          {
            if ( v8 == 1 )
              break;
          }
          else if ( sub_577E50(String, aSeasondir, (int)pszPath) )
          {
            sub_41CEB0(pszPath);
          }
          else if ( sub_577E50(String, aSounddir, (int)pszPath) )
          {
            sub_41CED0(pszPath);
          }
          else if ( sub_577E50(String, aVehiclesound, (int)pszPath) )
          {
            sub_41CEF0(pszPath);
          }
          else if ( sub_577E50(String, aOptionsanim, (int)pszPath) )
          {
            sub_41CF10(pszPath);
          }
          else if ( sub_577E50(String, aOptionsflags, (int)pszPath) )
          {
            sub_41CF30(pszPath);
          }
          else if ( sub_577E50(String, aOptionssounds, (int)pszPath) )
          {
            sub_41CF50(pszPath);
          }
          else if ( sub_577E50(String, aOptionsdir, (int)pszPath) )
          {
            sub_41CF70(pszPath);
          }
          else if ( sub_577E50(String, aMoviedir, (int)pszPath) )
          {
            sub_41CFB0(pszPath);
          }
          else if ( sub_577E50(String, aTracksdir, (int)pszPath) )
          {
            sub_41CFD0(pszPath);
          }
          else if ( sub_577E50(String, aVehiclesdir, (int)pszPath) )
          {
            sub_41CFF0(pszPath);
          }
          else if ( sub_577E50(String, aDriversdir, (int)pszPath) )
          {
            sub_41D010(pszPath);
          }
          else if ( sub_577E50(String, aMusicdir, (int)pszPath) )
          {
            sub_41D070(pszPath);
          }
          else if ( sub_577E50(String, aReplaydir, (int)pszPath) )
          {
            if ( v37 )
            {
              v9 = *(const char **)(this + 64);
              if ( !v9 )
                v9 = &byte_629120;
              v10 = *(const char **)(this + 176);
              if ( !v10 )
                v10 = &byte_629120;
              sprintf(NewFileName, "%s%s", v10, v9);
              if ( _access(NewFileName, 0) == -1 )
              {
                v11 = 0;
                v12 = strlen(NewFileName) + 1;
                if ( (int)(v12 - 1) > 0 )
                {
                  do
                  {
                    if ( v11 >= 0x400 )
                      break;
                    if ( NewFileName[v11] == 92 )
                    {
                      strncpy(Path, NewFileName, v11);
                      Path[v11] = 0;
                      _mkdir(Path);
                    }
                    ++v11;
                  }
                  while ( (int)v11 < (int)(v12 - 1) );
                }
                _mkdir(NewFileName);
                v13 = *(char **)(this + 64);
                if ( !v13 )
                  v13 = &byte_629120;
                sub_41D0F0(v13, NewFileName);
                sprintf(pszPath, "%s", NewFileName);
                v6 = v38;
              }
            }
            sub_41CF90(pszPath);
          }
          else if ( sub_577E50(String, aLogdir, (int)pszPath) )
          {
            if ( v37 )
            {
              v14 = *(const char **)(this + 104);
              if ( !v14 )
                v14 = &byte_629120;
              v15 = *(const char **)(this + 176);
              if ( !v15 )
                v15 = &byte_629120;
              sprintf(NewFileName, "%s%s", v15, v14);
              if ( _access(NewFileName, 0) == -1 )
              {
                v16 = 0;
                v17 = strlen(NewFileName) + 1;
                if ( (int)(v17 - 1) > 0 )
                {
                  do
                  {
                    if ( v16 >= 0x400 )
                      break;
                    if ( NewFileName[v16] == 92 )
                    {
                      strncpy(v54, NewFileName, v16);
                      v54[v16] = 0;
                      _mkdir(v54);
                    }
                    ++v16;
                  }
                  while ( (int)v16 < (int)(v17 - 1) );
                }
                _mkdir(NewFileName);
                v18 = *(char **)(this + 104);
                if ( !v18 )
                  v18 = &byte_629120;
                sub_41D0F0(v18, NewFileName);
                sprintf(pszPath, "%s", NewFileName);
                v6 = v38;
              }
            }
            sub_41D030(pszPath);
          }
          else if ( sub_577E50(String, aSavedir, (int)pszPath) )
          {
            if ( v37 )
            {
              v19 = *(const char **)(this + 112);
              if ( !v19 )
                v19 = &byte_629120;
              v20 = *(const char **)(this + 176);
              if ( !v20 )
                v20 = &byte_629120;
              sprintf(NewFileName, "%s%s", v20, v19);
              if ( _access(NewFileName, 0) == -1 )
              {
                v21 = 0;
                v22 = strlen(NewFileName) + 1;
                if ( (int)(v22 - 1) > 0 )
                {
                  do
                  {
                    if ( v21 >= 0x400 )
                      break;
                    if ( NewFileName[v21] == 92 )
                    {
                      strncpy(v55, NewFileName, v21);
                      v55[v21] = 0;
                      _mkdir(v55);
                    }
                    ++v21;
                  }
                  while ( (int)v21 < (int)(v22 - 1) );
                }
                _mkdir(NewFileName);
                v23 = *(char **)(this + 112);
                if ( !v23 )
                  v23 = &byte_629120;
                sub_41D0F0(v23, NewFileName);
                Destination[0] = byte_629120;
                memset(&Destination[1], 0, 0x1FCu);
                v52 = 0;
                v53 = 0;
                Source[0] = byte_629120;
                memset(&Source[1], 0, 0x1FCu);
                v49 = 0;
                v50 = 0;
                v24 = *(const char **)(this + 192);
                if ( !v24 )
                  v24 = &byte_629120;
                v25 = *(const char **)(this + 112);
                if ( !v25 )
                  v25 = &byte_629120;
                sub_405480(Destination, 0x1FFu, "%s%s", v25, v24);
                v26 = *(const char **)(this + 192);
                if ( !v26 )
                  v26 = &byte_629120;
                sub_405480(Source, 0x1FFu, "%s%s", NewFileName, v26);
                v27 = 0;
                v28 = strlen(Source) + 1;
                if ( (int)(v28 - 1) > 0 )
                {
                  do
                  {
                    if ( v27 >= 0x400 )
                      break;
                    if ( Source[v27] == 92 )
                    {
                      strncpy(v57, Source, v27);
                      v57[v27] = 0;
                      _mkdir(v57);
                    }
                    ++v27;
                  }
                  while ( (int)v27 < (int)(v28 - 1) );
                }
                _mkdir(Source);
                sub_41D0F0(Destination, Source);
                sprintf(pszPath, "%s", NewFileName);
                v6 = v38;
              }
            }
            sub_41D050(pszPath);
          }
          else if ( sub_577E50(String, aCameraeditorre, (int)pszPath) )
          {
            sub_41D0D0(pszPath);
          }
          else if ( sub_578110(aGridsize, (int)&v36, 0, 0, 0) )
          {
            v29 = v36;
            v30 = v36 < 0;
            *(_DWORD *)(this + 228) = v36;
            if ( v30 )
            {
              *(_DWORD *)(this + 228) = 0;
            }
            else if ( v29 > 48 )
            {
              *(_DWORD *)(this + 228) = 48;
            }
          }
          else if ( sub_578110(aCpurating, (int)&v36, 0, 0, 0) )
          {
            *(_DWORD *)(this + 232) = v36;
          }
          else if ( sub_578110(aSystemram, (int)&v36, 0, 0, 0) )
          {
            *(_DWORD *)(this + 236) = v36;
          }
          else if ( sub_578110(aVideoram, (int)&v36, 0, 0, 0) )
          {
            *(_DWORD *)(this + 240) = v36;
          }
          else if ( sub_578110(aObjdetail, (int)&v36, 0, 0, 0) )
          {
            *(_DWORD *)(this + 248) = v36;
          }
          else if ( sub_578110(aTexdetail, (int)&v36, 0, 0, 0) )
          {
            *(_DWORD *)(this + 252) = v36;
          }
          else if ( sub_577ED0(String, aVideoguid, pszPath, 0) || sub_577ED0(String, aGameDatabase, pszPath, 0) )
          {
            sub_578600(pszPath);
          }
          else if ( sub_578110(aVideodriver, (int)&v36, 0, 0, 0) )
          {
            *(_DWORD *)(this + 216) = v36;
          }
          else if ( sub_578110(aVideomode, (int)&v36, 0, 0, 0) )
          {
            *(_DWORD *)(this + 220) = v36;
          }
          else if ( sub_578110(aVideorefresh, (int)&v36, 0, 0, 0) )
          {
            *(_DWORD *)(this + 224) = v36;
          }
          else if ( sub_578110(aWindowedmode, (int)&v36, 0, 0, 0) )
          {
            *(_BYTE *)(this + 244) = v36 != 0;
          }
          else if ( sub_578110(aRunbenchmarks, (int)&v36, 0, 0, 0) )
          {
            *(_BYTE *)(this + 245) = v36 != 0;
          }
          else if ( sub_578110(aFsaa, (int)&v36, 0, 0, 0) )
          {
            *(_DWORD *)(this + 256) = v36;
          }
          else if ( sub_578110(aVsync, (int)&v36, 0, 0, 0) )
          {
            *(_BYTE *)(this + 246) = v36 != 0;
          }
          else if ( sub_578110(aVbstrategy, (int)&v36, 0, 0, 0) )
          {
            *(_DWORD *)(this + 260) = v36;
          }
          else if ( sub_578110(aSoundcard, (int)&v36, 0, 0, 0) )
          {
            *(_BYTE *)(this + 268) = v36 != 0;
          }
        }
      }
      else if ( strstr(Str, aInstall) )
      {
        while ( fgets(Str, 256, v6) )
        {
          v31 = sub_577B60(String);
          v36 = v31;
          if ( v31 )
          {
            if ( v31 == 1 )
              break;
          }
          else if ( sub_577E50(String, aInstallfrom, (int)pszPath) )
          {
            sub_41D090(pszPath);
          }
          else if ( sub_577E50(String, aInstallto, (int)pszPath) )
          {
            sub_41D0B0(pszPath);
          }
        }
      }
      else if ( strstr(Str, aAutolaunch) )
      {
        while ( fgets(Str, 256, v6) )
        {
          v32 = sub_577B60(String);
          v36 = v32;
          if ( v32 )
          {
            if ( v32 == 1 )
              break;
          }
          else if ( sub_577E50(String, aMode, (int)pszPath) )
          {
            v33 = sub_4059A0(pszPath);
            sub_405A20(&dword_629124, v33);
          }
          else if ( sub_578110(aLaunchtime, (int)&v36, 0, 0, 0) )
          {
            *(float *)&v35 = (float)v36;
            sub_405A10(&dword_629124, v35);
          }
          else if ( sub_578110(aVcrcycle, (int)&v36, 0, 0, 0) )
          {
            sub_405A30(&dword_629124, v36 != 0);
          }
          else if ( sub_577E50(String, aVcrfile, (int)pszPath) )
          {
            sub_405B40(&dword_629124, (int)pszPath);
          }
          else if ( sub_577E50(String, aIpaddress, (int)pszPath) )
          {
            sub_405BD0((int)pszPath);
          }
        }
      }
      else if ( strstr(Str, aVersion) && fgets(Str, 256, v6) )
      {
        do
        {
          v34 = sub_577B60(String);
          v36 = v34;
          if ( v34 )
          {
            if ( v34 == 1 )
              break;
          }
          else if ( sub_577ED0(String, aVersion_0, pszPath, 0) )
          {
            *(float *)(this + 264) = atof(pszPath);
          }
        }
        while ( fgets(Str, 256, v6) );
      }
    }
  }
  fclose(v6);
  if ( v37 )
    sub_41E340((Concurrency::details::SchedulerBase *)&unk_62A060, 0);
  return 1;
}
