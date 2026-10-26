int __thiscall sub_52CAF0(int this, char *FileName)
{
  FILE *v3; // eax
  FILE *v4; // esi
  int i; // ebx
  char *v7; // eax
  double v8; // st7
  int v9; // ecx
  float *v10; // edx
  double v11; // st7
  float *v12; // eax
  double v13; // st7
  float v14; // [esp+18h] [ebp-8h]
  float v15; // [esp+1Ch] [ebp-4h]

  v3 = fopen(FileName, aWb);
  v4 = v3;
  if ( v3 )
  {
    fprintf(v3, "Weather\n");
    fprintf(v4, "{\n");
    for ( i = 0; i < 9; ++i )
    {
      v7 = sub_42F570(i, 0);
      fprintf(v4, " %s\n", v7);
      fprintf(v4, " {\n");
      v15 = sub_529CA0((void *)i);
      *(_DWORD *)(this + 52) = *(_DWORD *)(this + 56);
      v14 = 0.0;
      if ( v15 > 0.0 )
      {
        do
        {
          sub_52C170((_DWORD *)this, 10.0, v14, 0);
          v8 = v14 + 10.0;
          v14 = v8;
        }
        while ( v8 < v15 );
      }
      v9 = *(_DWORD *)(this + 52);
      v10 = *(float **)(v9 + 12);
      if ( v10 && *v10 > (double)*(float *)v9 )
        v11 = (v15 - *(float *)v9) / (*v10 - *(float *)v9) * (v10[2] - *(float *)(v9 + 8)) + *(float *)(v9 + 8);
      else
        v11 = *(float *)(v9 + 8);
      fprintf(v4, "  Conditions=%.2f\n", v11 * 100.0);
      fprintf(v4, "  OnPathWetness=%.2f\n", *(float *)(this + 36) * 100.0);
      fprintf(v4, "  OffPathWetness=%.2f\n", *(float *)(this + 40) * 100.0);
      fprintf(v4, "  AmbientTemp=%.2f\n", *(float *)(this + 44));
      fprintf(v4, "  TrackTemp=%.2f\n", *(float *)(this + 48));
      v12 = *(float **)(*(_DWORD *)(this + 52) + 12);
      for ( *(_DWORD *)(this + 52) = v12; v12; *(_DWORD *)(this + 52) = v12 )
      {
        v13 = (*v12 - v15) * 0.016666668;
        if ( v13 > 150.0 )
          break;
        fprintf(v4, "  Minute=%.2f\n", v13);
        fprintf(v4, "  {\n");
        fprintf(v4, "   Conditions=%.2f\n", *(float *)(*(_DWORD *)(this + 52) + 8) * 100.0);
        fprintf(v4, "   AmbientTemp=%.2f\n", *(float *)(*(_DWORD *)(this + 52) + 4));
        fprintf(v4, "  }\n");
        v12 = *(float **)(*(_DWORD *)(this + 52) + 12);
      }
      fprintf(v4, " }\n");
    }
    fprintf(v4, "}\n");
    fclose(v4);
    return 0;
  }
  else
  {
    if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_27, 2156) )
      sub_500FE0((int)&unk_7D7920, "Could not write to file %s", FileName);
    return -1;
  }
}
