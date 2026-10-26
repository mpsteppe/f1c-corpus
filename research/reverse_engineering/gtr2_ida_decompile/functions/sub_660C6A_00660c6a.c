int __thiscall sub_660C6A(int this)
{
  int *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax

  v2 = (int *)(this + 16);
  while ( 1 )
  {
    if ( sub_65D1E3(*(_DWORD **)(this + 4), v2) < 0 )
    {
      *(_DWORD *)(this + 76) = 1;
      *(_DWORD *)(this + 80) = 1;
      return -1;
    }
    v3 = *v2;
    if ( *v2 <= 9 )
      break;
    v4 = v3 - 10;
    if ( !v4 )
      return 272;
    v5 = v4 - 2;
    if ( v5 )
    {
      if ( v5 != 1 )
        return 272;
      return -1;
    }
  }
  if ( *v2 == 9 )
  {
    if ( !strcmp(*(const char **)(this + 24), "entrypoint") )
    {
      return 257;
    }
    else if ( !strcmp(*(const char **)(this + 24), "true") )
    {
      return 273;
    }
    else if ( !strcmp(*(const char **)(this + 24), "false") )
    {
      return 274;
    }
    else if ( *(_DWORD *)(this + 56) == -1 )
    {
      return 269;
    }
    else
    {
      return sub_65EDD0((_DWORD *)this, this + 16);
    }
  }
  else
  {
    if ( !v3 )
      return 272;
    if ( v3 == 1 )
    {
      if ( *(_BYTE *)(this + 25) )
        return 272;
      return *(char *)(this + 24);
    }
    else
    {
      if ( v3 <= 1 )
        return 272;
      if ( v3 > 4 )
      {
        if ( v3 <= 8 )
          return 271;
        return 272;
      }
      return 270;
    }
  }
}
