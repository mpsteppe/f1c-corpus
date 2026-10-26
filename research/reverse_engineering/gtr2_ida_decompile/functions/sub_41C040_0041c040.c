char __thiscall sub_41C040(const CHAR **this, const CHAR *ArgList)
{
  unsigned int v2; // kr00_4
  __int32 v3; // ebx
  int v5; // ebx
  const CHAR *v6; // esi
  int v8; // eax
  CHAR *p_pszPath; // eax
  char v10; // cl
  CHAR *v11; // eax
  char v12; // cl
  _WORD *v13; // edi
  char v14; // al
  CHAR *v15; // eax
  char v16; // cl
  CHAR *v17; // eax
  char v18; // cl
  _WORD *v19; // edi
  char v20; // al
  CHAR *v21; // eax
  char v22; // cl
  CHAR *v23; // eax
  char v24; // cl
  _WORD *v25; // edi
  char v26; // al
  CHAR *v27; // eax
  char v28; // cl
  CHAR *v29; // eax
  char v30; // cl
  _WORD *v31; // edi
  char v32; // al
  const char *v33; // ecx
  const char *v34; // eax
  const CHAR *v35; // eax
  const char *v36; // ecx
  const char *v37; // eax
  const CHAR *v38; // eax
  const char *v39; // ecx
  const char *v40; // eax
  const CHAR *v41; // eax
  const char *v42; // ecx
  const char *v43; // eax
  const CHAR *v44; // eax
  const char *v45; // ecx
  const char *v46; // eax
  const CHAR *v47; // eax
  int v48; // eax
  bool v49; // cc
  int v50; // eax
  CHAR *v51; // eax
  char v52; // cl
  CHAR *v53; // eax
  char v54; // cl
  _WORD *v55; // edi
  char v56; // al
  int v57; // eax
  int v58; // eax
  __int32 v59; // ecx
  int v60; // eax
  unsigned int v61; // kr04_4
  __int32 v62; // ebx
  __int32 v63[2]; // [esp+4h] [ebp-6A0h] BYREF
  int v64[3]; // [esp+Ch] [ebp-698h] BYREF
  char String[4]; // [esp+18h] [ebp-68Ch] BYREF
  char v66; // [esp+1Fh] [ebp-685h]
  int v67; // [esp+20h] [ebp-684h] BYREF
  CHAR pszPath; // [esp+24h] [ebp-680h] BYREF
  _BYTE v69[243]; // [esp+25h] [ebp-67Fh] BYREF
  CHAR v70[92]; // [esp+124h] [ebp-580h] BYREF
  CHAR NewFileName[244]; // [esp+180h] [ebp-524h] BYREF
  _BYTE v72[512]; // [esp+280h] [ebp-424h] BYREF
  int v73; // [esp+480h] [ebp-224h]
  char v74; // [esp+484h] [ebp-220h]
  char Buffer[4]; // [esp+48Ch] [ebp-218h] BYREF
  int v76; // [esp+490h] [ebp-214h]
  int v77; // [esp+494h] [ebp-210h]
  char Str[512]; // [esp+498h] [ebp-20Ch] BYREF
  int v79; // [esp+6A0h] [ebp-4h]

  v5 = 0;
  memset(Str, 0, sizeof(Str));
  v73 = 0;
  v77 = 0;
  *(_DWORD *)Buffer = 0;
  v76 = 0;
  v74 = 1;
  sub_613B30(v70);
  v79 = 0;
  v66 = 0;
  sub_41AE50(&pszPath);
  if ( (!strcmp(&pszPath, (const char *)&dword_6F2600)
     || !strcmp(&pszPath, (const char *)&dword_6F260C)
     || !strcmp(&pszPath, (const char *)&dword_6F25F0))
    && !(unsigned __int8)sub_41B080() )
  {
    v66 = 1;
    if ( SHGetSpecialFolderPathA(0, &pszPath, 5, 1) >= 0 )
    {
      sprintf(NewFileName, "%s\\%s", &pszPath, "GTR2\\");
      if ( _access(NewFileName, 0) == -1 )
      {
        sub_41B2B0();
        sub_615860(NewFileName);
        sprintf(NewFileName, "%s\\%s%s", &pszPath, "GTR2\\", "Config.ini");
        sub_615860(NewFileName);
        CopyFileA("Config.ini", NewFileName, 1);
      }
      else
      {
        sub_615860(NewFileName);
        sprintf(NewFileName, "%s\\%s%s", &pszPath, "GTR2\\", "Config.ini");
        sub_615860(NewFileName);
      }
    }
  }
  v6 = ArgList;
  if ( !ArgList )
  {
    v6 = *this;
    if ( !*this )
      v6 = WindowName;
  }
  if ( !(unsigned __int8)sub_614460(v6, 1) )
  {
    if ( !(unsigned __int8)sub_41B6F0((__int32)this, (int)v6) )
    {
      v63[0] = 0;
      v61 = __readeflags();
      v62 = dword_16C6D84 - 1823347749;
      __writeeflags(v61);
      _InterlockedExchange(v63, v62);
      if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\config.cpp", v63[0]) )
        sub_561210((int)byte_FAE910, "Could not create config file \"%s\"", (char)v6);
LABEL_19:
      v79 = -1;
      sub_614140(v70);
      return 0;
    }
    if ( !(unsigned __int8)sub_614460(v6, 1) )
    {
      if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\config.cpp", 473) )
        sub_561210((int)byte_FAE910, "Successfully created, but could not subsequently load \"%s\"", (char)v6);
      goto LABEL_19;
    }
  }
  while ( sub_613DE0(Str, 256) )
  {
    if ( !sub_612EB0(v72) )
    {
      if ( strstr(Str, "[COMPONENTS]") )
      {
        if ( sub_613DE0(Str, 256) )
        {
          do
          {
            v8 = sub_612EB0(v72);
            *(_DWORD *)String = v8;
            if ( v8 != v5 )
            {
              if ( v8 == 1 )
                break;
              goto LABEL_231;
            }
            if ( sub_6131C0("SEASONDIR", (int)&pszPath) )
            {
              p_pszPath = &pszPath;
              do
                v10 = *p_pszPath++;
              while ( v10 != (_BYTE)v5 );
              v67 = p_pszPath - v69;
              if ( p_pszPath != v69 )
              {
                v11 = &pszPath;
                do
                  v12 = *v11++;
                while ( v12 != (_BYTE)v5 );
                if ( *((_BYTE *)&v67 + v11 - v69 + 3) != 92 )
                {
                  v13 = (_WORD *)((char *)&v67 + 3);
                  do
                  {
                    v14 = *((_BYTE *)v13 + 1);
                    v13 = (_WORD *)((char *)v13 + 1);
                  }
                  while ( v14 != (_BYTE)v5 );
                  *v13 = 92;
                }
              }
              sub_615860(&pszPath);
            }
            if ( sub_6131C0("CHAMPIONSHIPOFFICIALDIR", (int)&pszPath) )
            {
              v15 = &pszPath;
              do
                v16 = *v15++;
              while ( v16 != (_BYTE)v5 );
              v67 = v15 - v69;
              if ( v15 != v69 )
              {
                v17 = &pszPath;
                do
                  v18 = *v17++;
                while ( v18 != (_BYTE)v5 );
                if ( *((_BYTE *)&v67 + v17 - v69 + 3) != 92 )
                {
                  v19 = (_WORD *)((char *)&v67 + 3);
                  do
                  {
                    v20 = *((_BYTE *)v19 + 1);
                    v19 = (_WORD *)((char *)v19 + 1);
                  }
                  while ( v20 != (_BYTE)v5 );
                  *v19 = 92;
                }
              }
              sub_615860(&pszPath);
            }
            if ( sub_6131C0("CHAMPIONSHIPCUSTOMDIR", (int)&pszPath) )
            {
              v21 = &pszPath;
              do
                v22 = *v21++;
              while ( v22 != (_BYTE)v5 );
              v67 = v21 - v69;
              if ( v21 != v69 )
              {
                v23 = &pszPath;
                do
                  v24 = *v23++;
                while ( v24 != (_BYTE)v5 );
                if ( *((_BYTE *)&v67 + v23 - v69 + 3) != 92 )
                {
                  v25 = (_WORD *)((char *)&v67 + 3);
                  do
                  {
                    v26 = *((_BYTE *)v25 + 1);
                    v25 = (_WORD *)((char *)v25 + 1);
                  }
                  while ( v26 != (_BYTE)v5 );
                  *v25 = 92;
                }
              }
            }
            else
            {
              if ( !sub_6131C0("SOUNDDIR", (int)&pszPath) )
              {
                if ( sub_6131C0("VEHICLESOUND", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41A520();
                }
                else if ( sub_6131C0("OPTIONSANIM", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41A580();
                }
                else if ( sub_6131C0("OPTIONSFLAGS", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41A5E0();
                }
                else if ( sub_6131C0("OPTIONSSOUNDS", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41A640();
                }
                else if ( sub_6131C0("OPTIONSDIR", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41A6A0();
                }
                else if ( sub_6131C0("MOVIEDIR", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41A820();
                }
                else if ( sub_6131C0("TRACKSDIR", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41A880();
                }
                else if ( sub_6131C0("PITSDIR", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41A8E0();
                }
                else if ( sub_6131C0("VEHICLESDIR", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41A940();
                }
                else if ( sub_6131C0("DRIVERSDIR", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41A9A0();
                }
                else if ( sub_6131C0("MUSICDIR", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41AAC0();
                }
                else if ( sub_6131C0("REPLAYDIR", (int)&pszPath) )
                {
                  if ( v66 != (_BYTE)v5 )
                  {
                    v33 = this[20];
                    if ( v33 == (const char *)v5 )
                      v33 = WindowName;
                    v34 = this[50];
                    if ( v34 == (const char *)v5 )
                      v34 = WindowName;
                    sprintf(NewFileName, "%s%s", v34, v33);
                    if ( _access(NewFileName, v5) == -1 )
                    {
                      sub_41B2B0();
                      v35 = this[20];
                      if ( v35 == (const CHAR *)v5 )
                        v35 = WindowName;
                      ((void (__fastcall *)(const CHAR *, CHAR *))&stru_41ABD8.HandlerFunc)(v35, NewFileName);
                      sprintf(&pszPath, "%s", NewFileName);
                    }
                  }
                  v63[0] = (__int32)&pszPath;
                  sub_41A700();
                }
                else if ( sub_6131C0("TIMETRIALDIR", (int)&pszPath) )
                {
                  if ( v66 != (_BYTE)v5 )
                  {
                    v36 = this[22];
                    if ( v36 == (const char *)v5 )
                      v36 = WindowName;
                    v37 = this[50];
                    if ( v37 == (const char *)v5 )
                      v37 = WindowName;
                    sprintf(NewFileName, "%s%s", v37, v36);
                    if ( _access(NewFileName, v5) == -1 )
                    {
                      sub_41B2B0();
                      v38 = this[22];
                      if ( v38 == (const CHAR *)v5 )
                        v38 = WindowName;
                      ((void (__fastcall *)(const CHAR *, CHAR *))&stru_41ABD8.HandlerFunc)(v38, NewFileName);
                      sprintf(&pszPath, "%s", NewFileName);
                    }
                  }
                  v63[0] = (__int32)&pszPath;
                  sub_41A760();
                }
                else if ( sub_6131C0("DRIVINGSCHOOLDIR", (int)&pszPath) )
                {
                  if ( v66 != (_BYTE)v5 )
                  {
                    v39 = this[24];
                    if ( v39 == (const char *)v5 )
                      v39 = WindowName;
                    v40 = this[50];
                    if ( v40 == (const char *)v5 )
                      v40 = WindowName;
                    sprintf(NewFileName, "%s%s", v40, v39);
                    if ( _access(NewFileName, v5) == -1 )
                    {
                      sub_41B2B0();
                      v41 = this[24];
                      if ( v41 == (const CHAR *)v5 )
                        v41 = WindowName;
                      ((void (__fastcall *)(const CHAR *, CHAR *))&stru_41ABD8.HandlerFunc)(v41, NewFileName);
                      sprintf(&pszPath, "%s", NewFileName);
                    }
                  }
                  v63[0] = (__int32)&pszPath;
                  sub_41A7C0();
                }
                else if ( sub_6131C0("LOGDIR", (int)&pszPath) )
                {
                  if ( v66 != (_BYTE)v5 )
                  {
                    v42 = this[36];
                    if ( v42 == (const char *)v5 )
                      v42 = WindowName;
                    v43 = this[50];
                    if ( v43 == (const char *)v5 )
                      v43 = WindowName;
                    sprintf(NewFileName, "%s%s", v43, v42);
                    if ( _access(NewFileName, v5) == -1 )
                    {
                      sub_41B2B0();
                      v44 = this[36];
                      if ( v44 == (const CHAR *)v5 )
                        v44 = WindowName;
                      ((void (__fastcall *)(const CHAR *, CHAR *))&stru_41ABD8.HandlerFunc)(v44, NewFileName);
                      sprintf(&pszPath, "%s", NewFileName);
                    }
                  }
                  v63[0] = (__int32)&pszPath;
                  sub_41AA00();
                }
                else if ( sub_6131C0("SAVEDIR", (int)&pszPath) )
                {
                  if ( v66 != (_BYTE)v5 )
                  {
                    v45 = this[38];
                    if ( v45 == (const char *)v5 )
                      v45 = WindowName;
                    v46 = this[50];
                    if ( v46 == (const char *)v5 )
                      v46 = WindowName;
                    sprintf(NewFileName, "%s%s", v46, v45);
                    if ( _access(NewFileName, v5) == -1 )
                    {
                      sub_41B2B0();
                      v47 = this[38];
                      if ( v47 == (const CHAR *)v5 )
                        v47 = WindowName;
                      ((void (__fastcall *)(const CHAR *, CHAR *))&stru_41ABD8.HandlerFunc)(v47, NewFileName);
                      sprintf(&pszPath, "%s", NewFileName);
                    }
                  }
                  v63[0] = (__int32)&pszPath;
                  sub_41AA60();
                }
                else if ( sub_6131C0("CAMERAEDITORRESOURCEDIR", (int)&pszPath) )
                {
                  v63[0] = (__int32)&pszPath;
                  sub_41AB80();
                }
                else if ( sub_6133A0("GRIDSIZE", (int)String, v5, v5, v5) )
                {
                  v48 = *(_DWORD *)String;
                  v49 = *(_DWORD *)String < v5;
                  this[57] = *(const CHAR **)String;
                  if ( v49 )
                  {
                    this[57] = (const CHAR *)v5;
                  }
                  else if ( v48 > 104 )
                  {
                    this[57] = (const CHAR *)104;
                  }
                }
                else if ( sub_6133A0("CPURATING", (int)String, v5, v5, v5) )
                {
                  this[58] = *(const CHAR **)String;
                }
                else if ( sub_6133A0("SYSTEMRAM", (int)String, v5, v5, v5) )
                {
                  this[59] = *(const CHAR **)String;
                }
                else if ( sub_6133A0("VIDEORAM", (int)String, v5, v5, v5) )
                {
                  this[60] = *(const CHAR **)String;
                }
                else if ( sub_6133A0("OBJDETAIL", (int)String, v5, v5, v5) )
                {
                  this[62] = *(const CHAR **)String;
                }
                else if ( sub_6133A0("TEXDETAIL", (int)String, v5, v5, v5) )
                {
                  this[63] = *(const CHAR **)String;
                }
                else
                {
                  v63[0] = v5;
                  if ( sub_6137E0(v72) )
                  {
                    sub_615860(String);
                  }
                  else if ( sub_6133A0("VIDEODRIVER", (int)v64, v5, v5, v5) )
                  {
                    this[54] = (const CHAR *)v64[0];
                  }
                  else if ( sub_6133A0("VIDEOMODE", (int)v64, v5, v5, v5) )
                  {
                    this[55] = (const CHAR *)v64[0];
                  }
                  else if ( sub_6133A0("VIDEOREFRESH", (int)v64, v5, v5, v5) )
                  {
                    this[56] = (const CHAR *)v64[0];
                  }
                  else if ( sub_6133A0("WINDOWEDMODE", (int)v64, v5, v5, v5) )
                  {
                    *((_BYTE *)this + 244) = v64[0] != v5;
                  }
                  else if ( sub_6133A0("RUNBENCHMARKS", (int)v64, v5, v5, v5) )
                  {
                    *((_BYTE *)this + 245) = v64[0] != v5;
                  }
                  else if ( sub_6133A0("FSAA", (int)v64, v5, v5, v5) )
                  {
                    this[64] = (const CHAR *)v64[0];
                  }
                  else if ( sub_6133A0("VSYNC", (int)v64, v5, v5, v5) )
                  {
                    *((_BYTE *)this + 246) = v64[0] != v5;
                  }
                  else if ( sub_6133A0("SHADERLEVEL", (int)v64, v5, v5, v5) )
                  {
                    this[67] = (const CHAR *)v64[0];
                  }
                }
                goto LABEL_231;
              }
              v27 = &pszPath;
              do
                v28 = *v27++;
              while ( v28 != (_BYTE)v5 );
              v67 = v27 - v69;
              if ( v27 != v69 )
              {
                v29 = &pszPath;
                do
                  v30 = *v29++;
                while ( v30 != (_BYTE)v5 );
                if ( *((_BYTE *)&v67 + v29 - v69 + 3) != 92 )
                {
                  v31 = (_WORD *)((char *)&v67 + 3);
                  do
                  {
                    v32 = *((_BYTE *)v31 + 1);
                    v31 = (_WORD *)((char *)v31 + 1);
                  }
                  while ( v32 != (_BYTE)v5 );
                  *v31 = 92;
                }
              }
            }
            sub_615860(&pszPath);
LABEL_231:
            v63[0] = v5;
            v2 = __readeflags();
            v3 = dword_16C6C8C + 1461443073;
            __writeeflags(v2);
            v5 = _InterlockedExchange(v63, v3);
          }
          while ( sub_613DE0(Str, v63[0]) );
        }
      }
      else if ( strstr(Str, "[INSTALL]") )
      {
        while ( sub_613DE0(Str, 256) )
        {
          v50 = sub_612EB0(v72);
          *(_DWORD *)String = v50;
          if ( v50 == v5 )
          {
            if ( sub_6131C0("INSTALLFROM", (int)&pszPath) )
            {
              v51 = &pszPath;
              do
                v52 = *v51++;
              while ( v52 != (_BYTE)v5 );
              v67 = v51 - v69;
              if ( v51 != v69 )
              {
                v53 = &pszPath;
                do
                  v54 = *v53++;
                while ( v54 != (_BYTE)v5 );
                if ( *((_BYTE *)&v67 + v53 - v69 + 3) != 92 )
                {
                  v55 = (_WORD *)((char *)&v67 + 3);
                  do
                  {
                    v56 = *((_BYTE *)v55 + 1);
                    v55 = (_WORD *)((char *)v55 + 1);
                  }
                  while ( v56 != (_BYTE)v5 );
                  *v55 = 92;
                }
              }
              sub_615860(&pszPath);
            }
            else if ( sub_6131C0("INSTALLTO", (int)&pszPath) )
            {
              v63[0] = (__int32)&pszPath;
              sub_41AB20();
            }
          }
          else if ( v50 == 1 )
          {
            break;
          }
        }
      }
      else if ( strstr(Str, "[AUTOLAUNCH]") )
      {
        while ( sub_613DE0(Str, 256) )
        {
          v57 = sub_612EB0(v72);
          *(_DWORD *)String = v57;
          if ( v57 == v5 )
          {
            if ( sub_6131C0("MODE", (int)&pszPath) )
            {
              v58 = sub_409A90(&pszPath);
              sub_409B10(&dword_91BE54, v58);
            }
            else if ( sub_6133A0("LAUNCHTIME", (int)String, v5, v5, v5) )
            {
              *(float *)v63 = (float)*(int *)String;
              sub_409B00(&dword_91BE54, v63[0]);
            }
            else if ( sub_6133A0("VCRCYCLE", (int)String, v5, v5, v5) )
            {
              LOBYTE(v59) = *(_DWORD *)String != v5;
              v63[0] = v59;
              sub_40A020();
            }
            else if ( sub_6131C0("VCRFILE", (int)&pszPath) )
            {
              v63[0] = (__int32)&pszPath;
              sub_409EE0();
            }
            else if ( sub_6131C0("IPADDRESS", (int)&pszPath) )
            {
              sub_409B70((int)&pszPath);
            }
          }
          else if ( v57 == 1 )
          {
            break;
          }
        }
      }
      else if ( strstr(Str, "[VERSION]") && sub_613DE0(Str, 256) )
      {
        do
        {
          v60 = sub_612EB0(v72);
          *(_DWORD *)String = v60;
          if ( v60 == v5 )
          {
            v63[0] = v5;
            if ( sub_6137E0(v72) )
              *((float *)this + 66) = atof(String);
          }
          else if ( v60 == 1 )
          {
            break;
          }
        }
        while ( sub_613DE0(Buffer, 256) );
      }
    }
  }
  sub_613C30(v70);
  if ( v66 != (_BYTE)v5 )
    sub_41B6F0((__int32)this, v5);
  v79 = -1;
  sub_614140(v70);
  return 1;
}
