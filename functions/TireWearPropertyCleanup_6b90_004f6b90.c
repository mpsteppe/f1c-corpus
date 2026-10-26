void *TireWearPropertyCleanup_6b90()
{
  char *v0; // esi
  int v1; // edi
  void *result; // eax

  v0 = (char *)&unk_8AF8EC;
  v1 = 45;
  do
  {
    result = (void *)*((_DWORD *)v0 - 5);
    v0 -= 20;
    if ( result )
      result = (void *)FreeWrapper_7bcf(result);
    --v1;
  }
  while ( v1 );
  return result;
}
