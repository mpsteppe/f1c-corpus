char *__cdecl setlocale(int Category, const char *Locale)
{
  int v2; // ebx
  int v3; // eax
  char *all; // esi
  const char *v5; // edi
  char *i; // esi
  size_t v7; // eax
  const char **v8; // ebx
  const char *v9; // esi
  size_t v10; // eax
  size_t v11; // edi
  const char *v12; // edi
  bool v13; // zf
  const char **v14; // edi
  char Destination[132]; // [esp+8h] [ebp-88h] BYREF
  int v17; // [esp+8Ch] [ebp-4h]
  int Categorya; // [esp+98h] [ebp+8h]
  int Str2; // [esp+9Ch] [ebp+Ch]

  v2 = 0;
  if ( (unsigned int)Category <= 5 )
  {
    _lock(19);
    ++dword_801518;
    while ( dword_80151C )
      Sleep(1u);
    if ( Category )
    {
      if ( Locale )
      {
        v3 = _setlocale_set_cat(Category, (char *)Locale);
LABEL_45:
        all = (char *)v3;
        goto LABEL_46;
      }
      all = (&dword_6251B4)[3 * Category];
LABEL_46:
      _unlock(19);
LABEL_47:
      --dword_801518;
      return all;
    }
    v5 = Locale;
    v17 = 1;
    Categorya = 0;
    if ( Locale )
    {
      if ( *Locale == 76 && Locale[1] == 67 && Locale[2] == 95 )
      {
        for ( i = strpbrk(Locale, "=;"); i; i = strpbrk(v5, "=;") )
        {
          v7 = i - v5;
          v17 = i - v5;
          if ( i == v5 || *i == 59 )
            break;
          Str2 = 1;
          v8 = (const char **)&off_6251BC;
          while ( strncmp(*v8, v5, v7) || v17 != strlen(*v8) )
          {
            ++Str2;
            v8 += 3;
            if ( (int)v8 > (int)&off_6251EC )
              break;
            v7 = v17;
          }
          v9 = i + 1;
          v10 = strcspn(v9, ";");
          v11 = v10;
          if ( !v10 && *v9 != 59 )
            break;
          if ( Str2 <= 5 )
          {
            strncpy(Destination, v9, v10);
            Destination[v11] = 0;
            if ( _setlocale_set_cat(Str2, Destination) )
              ++Categorya;
          }
          v12 = &v9[v11];
          if ( *v12 )
          {
            v5 = v12 + 1;
            if ( *v5 )
              continue;
          }
          v13 = Categorya == 0;
          goto LABEL_31;
        }
        _unlock(19);
        all = 0;
        goto LABEL_47;
      }
      all = (char *)_expandlocale((char *)Locale, Destination, 0, 0);
      if ( !all )
        goto LABEL_46;
      v14 = (const char **)&dword_6251B4;
      do
      {
        if ( v14 != (const char **)&dword_6251B4 )
        {
          if ( !strcmp(Destination, *v14) || _setlocale_set_cat(v2, Destination) )
            ++Categorya;
          else
            v17 = 0;
        }
        v14 += 3;
        ++v2;
      }
      while ( (int)v14 <= (int)&off_6251F0 );
      if ( v17 )
      {
        all = (char *)_setlocale_get_all();
        sub_5C1B88(dword_6251B4);
        dword_6251B4 = 0;
        goto LABEL_46;
      }
      v13 = Categorya == 0;
LABEL_31:
      if ( v13 )
      {
        all = 0;
        goto LABEL_46;
      }
    }
    v3 = _setlocale_get_all();
    goto LABEL_45;
  }
  return 0;
}
