int __cdecl sub_6600AD(const void ***a1, const char ***a2)
{
  const char *v2; // edx
  const char **v3; // eax
  const char *v4; // edi
  int result; // eax
  bool v6; // cf
  const char *v7; // eax
  const char *v8; // esi
  unsigned __int8 v9; // dl

  v2 = (const char *)**a1;
  v3 = *a2;
  if ( *(_WORD *)"v_" == *(_WORD *)v2
    || *(_WORD *)"r_" == *(_WORD *)v2
    || *(_WORD *)"o_" == *(_WORD *)v2
    || (v4 = *v3, *(_WORD *)"v_" == *(_WORD *)*v3)
    || *(_WORD *)"r_" == *(_WORD *)v4
    || *(_WORD *)"o_" == *(_WORD *)v4 )
  {
    v7 = *v3;
    v8 = (const char *)**a1;
    while ( 1 )
    {
      v6 = *v8 < (unsigned int)*v7;
      if ( *v8 != *v7 )
        break;
      if ( *v8 )
      {
        v9 = v8[1];
        v6 = v9 < (unsigned int)v7[1];
        if ( v9 != v7[1] )
          return -v6 - (v6 - 1);
        v8 += 2;
        v7 += 2;
        if ( v9 )
          continue;
      }
      return 0;
    }
    return -v6 - (v6 - 1);
  }
  result = strcmp(v2 + 2, v4 + 2);
  if ( !result )
  {
    result = 0;
    v6 = 0;
    if ( memcmp(**a1, v4, 2u) )
      return -v6 - (v6 - 1);
  }
  return result;
}
