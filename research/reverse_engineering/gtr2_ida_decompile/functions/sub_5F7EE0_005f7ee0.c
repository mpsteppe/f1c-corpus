int __thiscall sub_5F7EE0(_DWORD *this, const char *a2, int a3)
{
  int *v4; // eax
  int v5; // esi
  int v6; // eax
  int *v7; // eax
  int v9; // eax
  int *v10; // eax
  char String[64]; // [esp+Ch] [ebp-40h] BYREF

  strcpy(String, a2);
  _strupr(String);
  sub_5F6680(String);
  v4 = (int *)this[2344];
  this[2346] = v4;
  if ( v4 )
    v5 = *v4;
  else
    v5 = 0;
  if ( a3 )
  {
    if ( v5 )
    {
      while ( *(_DWORD *)(v5 + 336) != a3 || _stricmp(String, (const char *)(v5 + 204)) )
      {
        v9 = this[2346];
        if ( v9 )
          this[2346] = *(_DWORD *)(v9 + 4);
        v10 = (int *)this[2346];
        if ( !v10 )
          return 0;
        v5 = *v10;
        if ( !*v10 )
          return 0;
      }
      return v5;
    }
    return 0;
  }
  if ( !v5 )
    return 0;
  while ( _stricmp(String, (const char *)(v5 + 204)) )
  {
    v6 = this[2346];
    if ( v6 )
      this[2346] = *(_DWORD *)(v6 + 4);
    v7 = (int *)this[2346];
    if ( v7 )
    {
      v5 = *v7;
      if ( *v7 )
        continue;
    }
    return 0;
  }
  return v5;
}
