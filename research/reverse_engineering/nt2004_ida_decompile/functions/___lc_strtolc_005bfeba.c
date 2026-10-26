int __cdecl __lc_strtolc(char *a1, char *Source)
{
  const char *v2; // esi
  int v4; // eax
  char v5; // bl
  const char *v6; // edi
  char *v7; // eax
  const char *v8; // [esp-8h] [ebp-14h]
  size_t v9; // [esp-4h] [ebp-10h]
  char *Sourcea; // [esp+18h] [ebp+Ch]

  memset(a1, 0, 0x88u);
  v2 = Source;
  if ( !*Source )
    return 0;
  if ( *Source == 46 && Source[1] )
  {
    strcpy(a1 + 128, Source + 1);
    return 0;
  }
  for ( Sourcea = 0; ; ++Sourcea )
  {
    v4 = strcspn(v2, "_.,");
    if ( !v4 )
      break;
    v5 = v2[v4];
    v6 = &v2[v4];
    if ( Sourcea )
    {
      if ( Sourcea == (char *)1 )
      {
        if ( v4 >= 64 || v5 == 95 )
          return -1;
        v9 = v4;
        v8 = v2;
        v7 = a1 + 64;
      }
      else
      {
        if ( Sourcea != (char *)2 || v5 && v5 != 44 )
          return -1;
        v9 = v4;
        v8 = v2;
        v7 = a1 + 128;
      }
      strncpy(v7, v8, v9);
    }
    else
    {
      if ( v4 >= 64 || v5 == 46 )
        return -1;
      strncpy(a1, v2, v4);
    }
    if ( v5 == 44 || !v5 )
      return 0;
    v2 = v6 + 1;
  }
  return -1;
}
