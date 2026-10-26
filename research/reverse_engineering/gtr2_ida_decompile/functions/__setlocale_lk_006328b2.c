char *__fastcall _setlocale_lk(char *Str2, int a2)
{
  const char *v2; // edi
  char *all; // esi
  char *v5; // eax
  char *v6; // ebx
  size_t v7; // eax
  const char **v8; // esi
  const char *v9; // ebx
  size_t v10; // eax
  size_t v11; // edi
  const char *v12; // edi
  int v14; // esi
  const char **v15; // ebx
  int v16; // [esp+Ch] [ebp-1Ch]
  int v17; // [esp+10h] [ebp-18h]
  size_t v18; // [esp+10h] [ebp-18h]
  int v19; // [esp+14h] [ebp-14h]
  char Str1[132]; // [esp+18h] [ebp-10h] BYREF
  int v21; // [esp+9Ch] [ebp+74h]

  v21 = dword_912B08;
  v2 = Str2;
  if ( !a2 )
  {
    v17 = 1;
    v19 = 0;
    if ( Str2 )
    {
      if ( *Str2 == 76 && Str2[1] == 67 && Str2[2] == 95 )
      {
        do
        {
          v5 = strpbrk(v2, "=;");
          v6 = v5;
          if ( !v5 )
            return 0;
          v7 = v5 - v2;
          v18 = v7;
          if ( !v7 || *v6 == 59 )
            return 0;
          v16 = 1;
          v8 = (const char **)off_912A54;
          while ( strncmp(*v8, v2, v7) || v18 != sub_6354D0(*v8) )
          {
            ++v16;
            v8 += 3;
            if ( (int)v8 > (int)off_912A84 )
              break;
            v7 = v18;
          }
          v9 = v6 + 1;
          v10 = strcspn(v9, ";");
          v11 = v10;
          if ( !v10 && *v9 != 59 )
            return 0;
          if ( v16 <= 5 )
          {
            sub_630FE0((int)Str1, (int)v9, v10);
            Str1[v11] = 0;
            if ( sub_632623() )
              ++v19;
          }
          v12 = &v9[v11];
          if ( !*v12 )
            break;
          v2 = v12 + 1;
        }
        while ( *v2 );
        all = 0;
        if ( !v19 )
          return all;
      }
      else
      {
        all = _expandlocale(Str2, Str1, 0, 0);
        if ( !all )
          return all;
        v14 = 0;
        v15 = (const char **)&dword_912A4C;
        do
        {
          if ( v15 != (const char **)&dword_912A4C )
          {
            if ( !strcmp(Str1, *v15) || sub_632623() )
              ++v19;
            else
              v17 = 0;
          }
          v15 += 3;
          ++v14;
        }
        while ( (int)v15 <= (int)&off_912A88 );
        if ( v17 )
        {
          all = _setlocale_get_all();
          free(dword_912A4C);
          dword_912A4C = 0;
          return all;
        }
        if ( !v19 )
          return 0;
      }
    }
    return _setlocale_get_all();
  }
  if ( Str2 )
    return (char *)sub_632623();
  return (&dword_912A4C)[3 * a2];
}
