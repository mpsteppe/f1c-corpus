char __fastcall sub_57B530(char *FileName, char *a2)
{
  FILE *v3; // esi
  FILE *v4; // edi
  signed int i; // eax
  _BYTE Buffer[2048]; // [esp+8h] [ebp-800h] BYREF

  v3 = fopen(FileName, aRb);
  if ( !v3 )
    return 0;
  v4 = fopen(a2, aWb);
  if ( !v4 )
  {
    fclose(v3);
    return 0;
  }
  for ( i = sub_5BED6F(Buffer, 1u, 0x800u, v3); i > 0; i = sub_5BED6F(Buffer, 1u, 0x800u, v3) )
    sub_5BF5A6(Buffer, 1u, i, v4);
  fclose(v3);
  fclose(v4);
  return 1;
}
