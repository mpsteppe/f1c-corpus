char __thiscall sub_41E340(const char **this, char *FileName)
{
  const char *v2; // esi
  FILE *v4; // eax
  FILE *v5; // esi
  const char *v7; // eax
  const char *v8; // eax
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
  unsigned int NumberOfBoundContexts; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  int v28; // eax
  char *v29; // eax
  double v30; // st7

  v2 = FileName;
  if ( !FileName )
  {
    v2 = *this;
    if ( !*this )
      v2 = &byte_629120;
  }
  _chmod(v2, 128);
  v4 = fopen(v2, aWt);
  v5 = v4;
  if ( !v4 )
    return 0;
  fprintf(v4, "[COMPONENTS]\n");
  v7 = this[2];
  if ( !v7 )
    v7 = &byte_629120;
  fprintf(v5, "SEASONDIR=%s\n", v7);
  v8 = this[4];
  if ( !v8 )
    v8 = &byte_629120;
  fprintf(v5, "SOUNDDIR=%s\n", v8);
  v9 = this[6];
  if ( !v9 )
    v9 = &byte_629120;
  fprintf(v5, "VEHICLESOUND=%s\n", v9);
  v10 = this[8];
  if ( !v10 )
    v10 = &byte_629120;
  fprintf(v5, "OPTIONSANIM=%s\n", v10);
  v11 = this[10];
  if ( !v11 )
    v11 = &byte_629120;
  fprintf(v5, "OPTIONSFLAGS=%s\n", v11);
  v12 = this[12];
  if ( !v12 )
    v12 = &byte_629120;
  fprintf(v5, "OPTIONSSOUNDS=%s\n", v12);
  v13 = this[14];
  if ( !v13 )
    v13 = &byte_629120;
  fprintf(v5, "OPTIONSDIR=%s\n", v13);
  v14 = this[16];
  if ( !v14 )
    v14 = &byte_629120;
  fprintf(v5, "REPLAYDIR=%s\n", v14);
  v15 = this[18];
  if ( !v15 )
    v15 = &byte_629120;
  fprintf(v5, "MOVIEDIR=%s\n", v15);
  v16 = this[20];
  if ( !v16 )
    v16 = &byte_629120;
  fprintf(v5, "TRACKSDIR=%s\n", v16);
  v17 = this[22];
  if ( !v17 )
    v17 = &byte_629120;
  fprintf(v5, "VEHICLESDIR=%s\n", v17);
  v18 = this[24];
  if ( !v18 )
    v18 = &byte_629120;
  fprintf(v5, "DRIVERSDIR=%s\n", v18);
  v19 = this[26];
  if ( !v19 )
    v19 = &byte_629120;
  fprintf(v5, "LOGDIR=%s\n", v19);
  v20 = this[28];
  if ( !v20 )
    v20 = &byte_629120;
  fprintf(v5, "SAVEDIR=%s\n", v20);
  v21 = this[30];
  if ( !v21 )
    v21 = &byte_629120;
  fprintf(v5, "MUSICDIR=%s\n", v21);
  v22 = this[38];
  if ( !v22 )
    v22 = &byte_629120;
  fprintf(v5, "CAMERAEDITORRESOURCEDIR=%s\n", v22);
  NumberOfBoundContexts = Concurrency::details::SchedulerBase::GetNumberOfBoundContexts((Concurrency::details::SchedulerBase *)this);
  fprintf(v5, "GRIDSIZE=%d\n", NumberOfBoundContexts);
  fprintf(v5, "CPURATING=%d\n", this[58]);
  fprintf(v5, "SYSTEMRAM=%d\n", this[59]);
  fprintf(v5, "VIDEORAM=%d\n", this[60]);
  fprintf(v5, "OBJDETAIL=%d\n", this[62]);
  fprintf(v5, "TEXDETAIL=%d\n", this[63]);
  v24 = this[52];
  if ( !v24 )
    v24 = &byte_629120;
  fprintf(v5, "GAME_DATABASE=%s\n", v24);
  v25 = this[50];
  if ( !v25 )
    v25 = &byte_629120;
  fprintf(v5, "VIDEOGUID=%s\n", v25);
  fprintf(v5, "VIDEODRIVER=%d\n", this[54]);
  fprintf(v5, "VIDEOMODE=%d\n", this[55]);
  fprintf(v5, "VIDEOREFRESH=%d\n", this[56]);
  fprintf(v5, "WINDOWEDMODE=%d\n", *((unsigned __int8 *)this + 244));
  fprintf(v5, "RUNBENCHMARKS=%d\n", *((unsigned __int8 *)this + 245));
  fprintf(v5, "FSAA=%d\n", this[64]);
  fprintf(v5, "VSYNC=%d\n", *((unsigned __int8 *)this + 246));
  fprintf(v5, "VBSTRATEGY=%d\n", this[65]);
  fprintf(v5, "SOUNDCARD=%d\n", *((unsigned __int8 *)this + 268));
  fprintf(v5, "\n[INSTALL]\n");
  v26 = this[34];
  if ( !v26 )
    v26 = &byte_629120;
  fprintf(v5, "INSTALLFROM=%s\n", v26);
  v27 = this[36];
  if ( !v27 )
    v27 = &byte_629120;
  fprintf(v5, "INSTALLTO=%s\n", v27);
  fprintf(v5, "\n[AUTOLAUNCH]\n");
  v28 = sub_4059F0(&dword_629124);
  v29 = sub_4059E0(v28);
  fprintf(v5, "MODE=%s\n", v29);
  v30 = sub_405A00(&dword_629124);
  fprintf(v5, "LAUNCHTIME=%d\n", (unsigned int)(__int64)v30);
  fprintf(v5, "\n[VERSION]\n");
  fprintf(v5, "VERSION=%f", *((float *)this + 66));
  fclose(v5);
  return 1;
}
