int __thiscall sub_594000(int this, char *FileName)
{
  FILE *v3; // eax
  FILE *v4; // esi
  int v6; // edi
  char *v7; // eax
  char *v8; // eax
  _DWORD *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  int v14; // edi
  double v15; // st7
  int v16; // ecx
  float *v17; // eax
  double v18; // st7
  float *v19; // eax
  double v20; // st7
  int v21; // [esp+14h] [ebp-94h]
  float v22; // [esp+14h] [ebp-94h]
  float v23; // [esp+18h] [ebp-90h]
  int v24; // [esp+1Ch] [ebp-8Ch]
  float v25; // [esp+20h] [ebp-88h]
  char String1[61]; // [esp+28h] [ebp-80h] BYREF
  __int16 v27; // [esp+65h] [ebp-43h]
  char v28; // [esp+67h] [ebp-41h]
  char v29[61]; // [esp+68h] [ebp-40h] BYREF
  __int16 v30; // [esp+A5h] [ebp-3h]
  char v31; // [esp+A7h] [ebp-1h]

  v3 = fopen(FileName, "wb");
  v4 = v3;
  if ( v3 )
  {
    fprintf(v3, "Weather\n");
    fprintf(v4, "{\n");
    v6 = 0;
    v21 = 0;
    do
    {
      v7 = sub_42FEC0(v6, 0, 1);
      fprintf(v4, " %s\n", v7);
      fprintf(v4, " {\n");
      v25 = 180.0;
      v24 = sub_616840("DefaultScoring");
      if ( sub_53A250(0) )
      {
        memset(String1, 0, sizeof(String1));
        v27 = 0;
        v28 = 0;
        v8 = sub_42FEC0(v21, 0, 1);
        sub_632041(String1, 64, "%sTime", v8);
        v9 = (_DWORD *)sub_616630(String1);
        if ( v9 )
          goto LABEL_12;
        v10 = sub_42FEC0(v21, 0, 1);
        sub_632041(String1, 64, "%sDuration", v10);
        v9 = (_DWORD *)sub_616630(String1);
        if ( v9 )
          goto LABEL_12;
      }
      if ( v24 )
      {
        memset(v29, 0, sizeof(v29));
        v30 = 0;
        v31 = 0;
        v11 = sub_42FEC0(v21, 0, 1);
        sub_632041(v29, 64, "%sTime", v11);
        v9 = (_DWORD *)sub_616630(v29);
        if ( v9
          || (v12 = sub_42FEC0(v21, 0, 1), sub_632041(v29, 64, "%sDuration", v12), (v9 = (_DWORD *)sub_616630(v29)) != 0) )
        {
LABEL_12:
          v13 = sub_48D380(v9);
          v25 = atof(v13);
        }
      }
      v14 = v21;
      v22 = sub_5926A0(v21);
      *(_DWORD *)(this + 60) = *(_DWORD *)(this + 64);
      v23 = 0.0;
      if ( v22 > 0.0 )
      {
        do
        {
          sub_5936E0((_DWORD *)this, 10.0, v23, 0);
          v15 = v23 + 10.0;
          v23 = v15;
        }
        while ( v15 < v22 );
      }
      v16 = *(_DWORD *)(this + 60);
      v17 = *(float **)(v16 + 12);
      if ( v17 && *v17 > (double)*(float *)v16 )
        v18 = (v22 - *(float *)v16)
            / (**(float **)(v16 + 12) - *(float *)v16)
            * (*(float *)(*(_DWORD *)(v16 + 12) + 8) - *(float *)(v16 + 8))
            + *(float *)(v16 + 8);
      else
        v18 = *(float *)(v16 + 8);
      fprintf(v4, "  Conditions=%.2f\n", v18 * 100.0);
      fprintf(v4, "  OnPathWetness=%.2f\n", *(float *)(this + 44) * 100.0);
      fprintf(v4, "  OffPathWetness=%.2f\n", *(float *)(this + 48) * 100.0);
      fprintf(v4, "  AmbientTemp=%.2f\n", *(float *)(this + 52));
      fprintf(v4, "  TrackTemp=%.2f\n", *(float *)(this + 56));
      v19 = *(float **)(*(_DWORD *)(this + 60) + 12);
      for ( *(_DWORD *)(this + 60) = v19; v19; *(_DWORD *)(this + 60) = v19 )
      {
        v20 = (*v19 - v22) * 0.016666668;
        if ( v20 > v25 )
          break;
        fprintf(v4, "  Minute=%.2f\n", v20);
        fprintf(v4, "  {\n");
        fprintf(v4, "   Conditions=%.2f\n", *(float *)(*(_DWORD *)(this + 60) + 8) * 100.0);
        fprintf(v4, "   AmbientTemp=%.2f\n", *(float *)(*(_DWORD *)(this + 60) + 4));
        fprintf(v4, "  }\n");
        v19 = *(float **)(*(_DWORD *)(this + 60) + 12);
      }
      fprintf(v4, " }\n");
      v6 = v14 + 1;
      v21 = v6;
    }
    while ( v6 < 7 );
    fprintf(v4, "}\n");
    fclose(v4);
    return 0;
  }
  else
  {
    if ( sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\weather.cpp", 2921) )
      sub_561210((int)byte_FAE910, "Could not write to file %s", FileName);
    return -1;
  }
}
