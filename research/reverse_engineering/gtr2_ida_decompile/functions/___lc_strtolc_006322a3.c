int __cdecl __lc_strtolc(char *a1, char *Str)
{
  const char *v2; // esi
  const char *v4; // edi
  char v5; // bl
  char *v6; // eax
  size_t v7; // eax
  int v8; // [esp-8h] [ebp-10h]
  char *Stra; // [esp+14h] [ebp+Ch]

  memset(a1, 0, 0x90u);
  v2 = Str;
  if ( !*Str )
    return 0;
  if ( *Str == 46 && Str[1] )
  {
    sub_630FE0((int)(a1 + 128), (int)(Str + 1), 15);
    a1[143] = 0;
    return 0;
  }
  for ( Stra = 0; ; ++Stra )
  {
    v7 = strcspn(v2, "_.,");
    if ( !v7 )
      return -1;
    v4 = &v2[v7];
    v5 = v2[v7];
    if ( Stra )
    {
      if ( Stra == (char *)1 )
      {
        if ( v7 >= 0x40 || v5 == 95 )
          return -1;
        v8 = v7;
        v6 = a1 + 64;
      }
      else
      {
        if ( Stra != (char *)2 || v7 >= 0x10 || v5 && v5 != 44 )
          return -1;
        v8 = v7;
        v6 = a1 + 128;
      }
      sub_630FE0((int)v6, (int)v2, v8);
    }
    else
    {
      if ( v7 >= 0x40 || v5 == 46 )
        return -1;
      sub_630FE0((int)a1, (int)v2, v7);
    }
    if ( v5 == 44 || !v5 )
      break;
    v2 = v4 + 1;
  }
  return 0;
}
