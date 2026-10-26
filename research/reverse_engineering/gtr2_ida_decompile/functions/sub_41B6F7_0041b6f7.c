char __userpurge sub_41B6F7@<al>(int a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4, int a5, char *FileName)
{
  const char *v7; // edi
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  int v31; // eax
  char *v32; // eax
  unsigned __int64 v33; // rax
  _DWORD v34[2]; // [esp+1Ch] [ebp-168h] BYREF
  _BYTE v35[84]; // [esp+24h] [ebp-160h] BYREF
  char Buffer[256]; // [esp+78h] [ebp-10Ch] BYREF
  int ExceptionList; // [esp+180h] [ebp-4h]

  ExceptionList = (int)NtCurrentTeb()->NtTib.ExceptionList;
  v34[1] = a3;
  v34[0] = a2;
  sub_613B30(v35);
  v7 = FileName;
  if ( !FileName )
  {
    v7 = *(const char **)a1;
    if ( !*(_DWORD *)a1 )
      v7 = WindowName;
  }
  _chmod(v7, 128);
  if ( (unsigned __int8)sub_6146B0(v7, 0, 1) )
  {
    sub_632041(Buffer, 256, "[COMPONENTS]\n", 1);
    sub_613EC0(Buffer);
    v9 = *(const char **)(a1 + 8);
    if ( !v9 )
      v9 = WindowName;
    sub_632041(Buffer, 256, "SEASONDIR=%s\n", v9);
    sub_613EC0(Buffer);
    v10 = *(const char **)(a1 + 32);
    if ( !v10 )
      v10 = WindowName;
    sub_632041(Buffer, 256, "SOUNDDIR=%s\n", v10);
    sub_613EC0(Buffer);
    v11 = *(const char **)(a1 + 40);
    if ( !v11 )
      v11 = WindowName;
    sub_632041(Buffer, 256, "VEHICLESOUND=%s\n", v11);
    sub_613EC0(Buffer);
    v12 = *(const char **)(a1 + 48);
    if ( !v12 )
      v12 = WindowName;
    sub_632041(Buffer, 256, "OPTIONSANIM=%s\n", v12);
    sub_613EC0(Buffer);
    v13 = *(const char **)(a1 + 56);
    if ( !v13 )
      v13 = WindowName;
    sub_632041(Buffer, 256, "OPTIONSFLAGS=%s\n", v13);
    sub_613EC0(Buffer);
    v14 = *(const char **)(a1 + 64);
    if ( !v14 )
      v14 = WindowName;
    sub_632041(Buffer, 256, "OPTIONSSOUNDS=%s\n", v14);
    sub_613EC0(Buffer);
    v15 = *(const char **)(a1 + 72);
    if ( !v15 )
      v15 = WindowName;
    sub_632041(Buffer, 256, "OPTIONSDIR=%s\n", v15);
    sub_613EC0(Buffer);
    v16 = *(const char **)(a1 + 80);
    if ( !v16 )
      v16 = WindowName;
    sub_632041(Buffer, 256, "REPLAYDIR=%s\n", v16);
    sub_613EC0(Buffer);
    v17 = *(const char **)(a1 + 88);
    if ( !v17 )
      v17 = WindowName;
    sub_632041(Buffer, 256, "TIMETRIALDIR=%s\n", v17);
    sub_613EC0(Buffer);
    v18 = *(const char **)(a1 + 96);
    if ( !v18 )
      v18 = WindowName;
    sub_632041(Buffer, 256, "DRIVINGSCHOOLDIR=%s\n", v18);
    sub_613EC0(Buffer);
    v19 = *(const char **)(a1 + 104);
    if ( !v19 )
      v19 = WindowName;
    sub_632041(Buffer, 256, "MOVIEDIR=%s\n", v19);
    sub_613EC0(Buffer);
    v20 = *(const char **)(a1 + 112);
    if ( !v20 )
      v20 = WindowName;
    sub_632041(Buffer, 256, "TRACKSDIR=%s\n", v20);
    sub_613EC0(Buffer);
    v21 = *(const char **)(a1 + 120);
    if ( !v21 )
      v21 = WindowName;
    sub_632041(Buffer, 256, "PITSDIR=%s\n", v21);
    sub_613EC0(Buffer);
    v22 = *(const char **)(a1 + 128);
    if ( !v22 )
      v22 = WindowName;
    sub_632041(Buffer, 256, "VEHICLESDIR=%s\n", v22);
    sub_613EC0(Buffer);
    v23 = *(const char **)(a1 + 136);
    if ( !v23 )
      v23 = WindowName;
    sub_632041(Buffer, 256, "DRIVERSDIR=%s\n", v23);
    sub_613EC0(Buffer);
    v24 = *(const char **)(a1 + 144);
    if ( !v24 )
      v24 = WindowName;
    sub_632041(Buffer, 256, "LOGDIR=%s\n", v24);
    sub_613EC0(Buffer);
    v25 = *(const char **)(a1 + 152);
    if ( !v25 )
      v25 = WindowName;
    sub_632041(Buffer, 256, "SAVEDIR=%s\n", v25);
    sub_613EC0(Buffer);
    v26 = *(const char **)(a1 + 160);
    if ( !v26 )
      v26 = WindowName;
    sub_632041(Buffer, 256, "MUSICDIR=%s\n", v26);
    sub_613EC0(Buffer);
    v27 = *(const char **)(a1 + 184);
    if ( !v27 )
      v27 = WindowName;
    sub_632041(Buffer, 256, "CAMERAEDITORRESOURCEDIR=%s\n", v27);
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "GRIDSIZE=%d\n", *(_DWORD *)(a1 + 228));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "CPURATING=%d\n", *(_DWORD *)(a1 + 232));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "SYSTEMRAM=%d\n", *(_DWORD *)(a1 + 236));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "VIDEORAM=%d\n", *(_DWORD *)(a1 + 240));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "OBJDETAIL=%d\n", *(_DWORD *)(a1 + 248));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "TEXDETAIL=%d\n", *(_DWORD *)(a1 + 252));
    sub_613EC0(Buffer);
    v28 = *(const char **)(a1 + 208);
    if ( !v28 )
      v28 = WindowName;
    sub_632041(Buffer, 256, "VIDEOGUID=%s\n", v28);
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "VIDEODRIVER=%d\n", *(_DWORD *)(a1 + 216));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "VIDEOMODE=%d\n", *(_DWORD *)(a1 + 220));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "VIDEOREFRESH=%d\n", *(_DWORD *)(a1 + 224));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "WINDOWEDMODE=%d\n", *(unsigned __int8 *)(a1 + 244));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "RUNBENCHMARKS=%d\n", *(unsigned __int8 *)(a1 + 245));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "FSAA=%d\n", *(_DWORD *)(a1 + 256));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "VSYNC=%d\n", *(unsigned __int8 *)(a1 + 246));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "SHADERLEVEL=%d\n", *(_DWORD *)(a1 + 268));
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "\n[INSTALL]\n");
    sub_613EC0(Buffer);
    v29 = *(const char **)(a1 + 168);
    if ( !v29 )
      v29 = WindowName;
    sub_632041(Buffer, 256, "INSTALLFROM=%s\n", v29);
    sub_613EC0(Buffer);
    v30 = *(const char **)(a1 + 176);
    if ( !v30 )
      v30 = WindowName;
    sub_632041(Buffer, 256, "INSTALLTO=%s\n", v30);
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "\n[AUTOLAUNCH]\n");
    sub_613EC0(Buffer);
    v31 = sub_409AE0(&dword_91BE54);
    v32 = sub_409AD0(v31);
    sub_632041(Buffer, 256, "MODE=%s\n", v32);
    sub_613EC0(Buffer);
    v33 = (unsigned __int64)sub_409AF0(&dword_91BE54);
    sub_632041(Buffer, 256, "LAUNCHTIME=%d\n", (_DWORD)v33);
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "\n[VERSION]\n");
    sub_613EC0(Buffer);
    sub_632041(Buffer, 256, "VERSION=%f", *(float *)(a1 + 264));
    sub_613EC0(Buffer);
    sub_613C30(v34);
    ExceptionList = -1;
    sub_614140(v34);
    return 1;
  }
  else
  {
    ExceptionList = -1;
    sub_614140(v34);
    return 0;
  }
}
