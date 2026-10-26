char __fastcall sub_617D00(char *FileName, char *a2)
{
  FILE *v3; // esi
  FILE *v4; // edi
  int i; // eax
  _BYTE v7[2048]; // [esp+8h] [ebp-800h] BYREF

  v3 = fopen(FileName, "rb");
  if ( !v3 )
    return 0;
  v4 = fopen(a2, "wb");
  if ( !v4 )
  {
    fclose(v3);
    return 0;
  }
  for ( i = sub_6318A2(v7, 1, 2048, v3); i > 0; i = sub_6318A2(v7, 1, 2048, v3) )
    sub_631E50(v7, 1, i, v4);
  fclose(v3);
  fclose(v4);
  return 1;
}
