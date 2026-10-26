int sub_49B1C0()
{
  int *v0; // esi
  int result; // eax
  void *v2; // edi

  v0 = dword_7CE23C;
  do
  {
    if ( *v0 )
    {
      result = ResourceCleanup_cd10(*v0);
      v2 = (void *)*v0;
      if ( *v0 )
      {
        ResourceCleanup_cd10(*v0);
        result = FreeWrapper_7bcf(v2);
      }
      *v0 = 0;
    }
    ++v0;
  }
  while ( (int)v0 < (int)&unk_7CE24C );
  return result;
}

