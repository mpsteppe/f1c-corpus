void *sub_44C600()
{
  char *v0; // esi
  int v1; // edi
  void *result; // eax

  v0 = (char *)&unk_7CC9A0;
  v1 = 44;
  do
  {
    result = (void *)*((_DWORD *)v0 - 2);
    v0 -= 8;
    if ( result )
      result = (void *)FreeWrapper_7bcf(result);
    --v1;
  }
  while ( v1 );
  return result;
}
