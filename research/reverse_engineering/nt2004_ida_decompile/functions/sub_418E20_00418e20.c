CHAR **__thiscall sub_418E20(int this)
{
  CHAR **result; // eax
  CHAR *v2; // eax
  int v3; // eax
  int v4; // eax
  unsigned int i; // [esp+50h] [ebp-4h]

  do
    result = (CHAR **)sub_58DC50(0);
  while ( result );
  for ( i = 0; i < 2; ++i )
  {
    if ( !*(_DWORD *)(this + 36) )
    {
      result = (CHAR **)sub_414470((int *)(this + 20));
      if ( !result )
        return result;
      v2 = sub_410E00(result);
      *(_DWORD *)(this + 36) = fopen(v2, aRb);
      if ( *(_DWORD *)(this + 36) )
      {
        rewind(*(FILE **)(this + 36));
      }
      else
      {
        *(_DWORD *)(this + 36) = 0;
        v3 = sub_414470((int *)(this + 20));
        sub_4192A0(v3, 1);
      }
    }
    if ( *(_DWORD *)(this + 36) )
    {
      if ( (unsigned int)sub_5BED6F(*(void **)(this + 40), 0x400u, 0x400u, *(FILE **)(this + 36)) < 0x400 )
      {
        fclose(*(FILE **)(this + 36));
        *(_DWORD *)(this + 36) = 0;
        v4 = sub_414470((int *)(this + 20));
        sub_4192A0(v4, 1);
      }
    }
    result = (CHAR **)(i + 1);
  }
  return result;
}
