char __fastcall sub_57B490(char *FileName, unsigned __int8 a2, unsigned __int8 a3, _DWORD *a4)
{
  FILE *v4; // edi
  int v6; // esi
  int i; // eax

  *a4 = 0;
  v4 = fopen(FileName, aRb);
  if ( !v4 )
    return 0;
  if ( !a2 )
    a2 = 1;
  *a4 = 0;
  fseek(v4, 0, 0);
  v6 = a3;
  for ( i = fgetc(v4); i != -1; i = fgetc(v4) )
  {
    *a4 += v6 * i;
    v6 = (v6 + 1) % a2;
  }
  fclose(v4);
  return 1;
}
