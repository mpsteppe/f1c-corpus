int __stdcall sub_4FE920(char *FileName)
{
  FILE *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int Buffer; // [esp+8h] [ebp-4h] BYREF

  v1 = fopen(FileName, aRb);
  Buffer = 0;
  if ( !v1 )
    return sub_4FEA10(&Buffer, 4u);
  while ( fgetc(v1) != -1 )
    ++Buffer;
  sub_4FEA10(&Buffer, 4u);
  fseek(v1, 0, 0);
  while ( 1 )
  {
    v2 = fgetc(v1);
    if ( v2 == -1 )
      break;
    LOBYTE(FileName) = v2 ^ 0x5C;
    sub_4FEA10(&FileName, 1u);
    v3 = fgetc(v1);
    if ( v3 == -1 )
      break;
    LOBYTE(FileName) = v3 ^ 0xB4;
    sub_4FEA10(&FileName, 1u);
    v4 = fgetc(v1);
    if ( v4 == -1 )
      break;
    LOBYTE(FileName) = v4 ^ 0x12;
    sub_4FEA10(&FileName, 1u);
  }
  return fclose(v1);
}
