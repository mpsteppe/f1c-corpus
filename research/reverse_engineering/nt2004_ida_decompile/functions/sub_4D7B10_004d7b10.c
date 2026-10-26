bool sub_4D7B10()
{
  bool v0; // bl
  const char *v1; // esi
  FILE *v2; // eax
  bool v3; // bl
  char *FileName[2]; // [esp+8h] [ebp-8h] BYREF

  v0 = 0;
  FileName[0] = 0;
  FileName[1] = (char *)-1;
  sub_4D9840(FileName);
  v1 = FileName[0];
  if ( !FileName[0] )
    v1 = &byte_629120;
  v2 = fopen(v1, aRb);
  if ( v2 )
  {
    fclose(v2);
    _chmod(v1, 384);
    v0 = remove(v1) == 0;
  }
  v3 = !v0;
  if ( FileName[0] )
    sub_5BE8AE(FileName[0]);
  return v3;
}
