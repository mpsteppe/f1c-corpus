int __thiscall sub_441C50(int this, double a2)
{
  int result; // eax
  int v4; // ebp
  int v5; // ebx
  int v6; // esi
  const char *v7; // eax
  _DWORD *v8; // esi
  int v9; // ecx
  int v10; // eax
  double *v11; // eax
  double v12; // st7
  double *v13; // ecx
  double v14; // st7

  result = *(_DWORD *)(this + 6268);
  v4 = 0;
  if ( result > 0 )
  {
    v5 = 0;
    do
    {
      v6 = *(_DWORD *)(this + 6272);
      v7 = *(const char **)(v6 + v5);
      v8 = (_DWORD *)(v5 + v6);
      if ( !v7 || _stricmp(v7, "track_bar") )
        goto LABEL_12;
      v9 = v8[1];
      v10 = *(_DWORD *)(this + 6312);
      if ( v9 == v10 && v8[3] == *(_DWORD *)(this + 5832) )
      {
        v11 = (double *)v8[2];
      }
      else
      {
        if ( v8[3] != v10 || v9 != *(_DWORD *)(this + 5832) )
          goto LABEL_12;
        v11 = (double *)v8[4];
      }
      if ( v11 )
      {
        v12 = a2 + *(double *)(this + 5840);
        v11[1] = v12;
        v13 = *(double **)(this + 6312);
        v14 = v12 * v13[7];
        v13 += 4;
        v11[3] = v14 + v13[6] * v11[2] + *v11 * *v13;
        v11[4] = v13[7] * v11[2] + v13[1] * *v11 + v13[4] * v11[1];
        v11[5] = v13[8] * v11[2] + v13[2] * *v11 + v13[5] * v11[1];
        sub_61D230(v8);
        return sub_61D2B0(v8);
      }
LABEL_12:
      result = *(_DWORD *)(this + 6268);
      ++v4;
      v5 += 80;
    }
    while ( v4 < result );
  }
  return result;
}
