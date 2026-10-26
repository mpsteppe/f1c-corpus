void _mtdeletelocks()
{
  int *v0; // esi
  LPCRITICAL_SECTION v1; // edi
  int *v2; // esi

  v0 = dword_912CB0;
  do
  {
    v1 = (LPCRITICAL_SECTION)*v0;
    if ( *v0 && v0[1] != 1 )
    {
      DeleteCriticalSection((LPCRITICAL_SECTION)*v0);
      free(v1);
      *v0 = 0;
    }
    v0 += 2;
  }
  while ( (int)v0 < (int)&off_912DD0 );
  v2 = dword_912CB0;
  do
  {
    if ( *v2 )
    {
      if ( v2[1] == 1 )
        DeleteCriticalSection((LPCRITICAL_SECTION)*v2);
    }
    v2 += 2;
  }
  while ( (int)v2 < (int)&off_912DD0 );
}
