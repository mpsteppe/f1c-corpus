int __thiscall sub_40F2E0(_DWORD *this, char *String2)
{
  int v2; // ebx
  int v4; // eax
  const char *v5; // eax
  int v7; // eax
  const char *v8; // eax
  int v9; // eax
  const char *v10; // eax
  int v11; // eax
  const char *v12; // eax
  int v13; // eax
  const char *v14; // eax
  int v15; // eax
  const char *v16; // eax
  int v17; // eax
  const char *v18; // eax
  int v19; // eax
  const char *v20; // eax
  int v21; // edi
  const char *v22; // eax
  int v23; // [esp+Ch] [ebp-4h]

  v2 = 0;
  v23 = 0;
  if ( String2 )
  {
    v4 = this[4];
    if ( v4 )
    {
      v5 = *(const char **)(v4 + 4);
      if ( !v5 )
        v5 = WindowName;
      if ( !_stricmp(v5, String2) )
        return this[4];
    }
    v7 = this[5];
    if ( v7 )
    {
      v8 = *(const char **)(v7 + 4);
      if ( !v8 )
        v8 = WindowName;
      if ( !_stricmp(v8, String2) )
        return this[5];
    }
    v9 = this[6];
    if ( v9 )
    {
      v10 = *(const char **)(v9 + 4);
      if ( !v10 )
        v10 = WindowName;
      if ( !_stricmp(v10, String2) )
        return this[6];
    }
    v11 = this[7];
    if ( v11 )
    {
      v12 = *(const char **)(v11 + 4);
      if ( !v12 )
        v12 = WindowName;
      if ( !_stricmp(v12, String2) )
        return this[7];
    }
    v13 = this[9];
    if ( v13 )
    {
      v14 = *(const char **)(v13 + 4);
      if ( !v14 )
        v14 = WindowName;
      if ( !_stricmp(v14, String2) )
        return this[9];
    }
    v15 = this[10];
    if ( v15 )
    {
      v16 = *(const char **)(v15 + 4);
      if ( !v16 )
        v16 = WindowName;
      if ( !_stricmp(v16, String2) )
        return this[10];
    }
    v17 = this[11];
    if ( v17 )
    {
      v18 = *(const char **)(v17 + 4);
      if ( !v18 )
        v18 = WindowName;
      if ( !_stricmp(v18, String2) )
        return this[11];
    }
    v19 = this[12];
    if ( v19 )
    {
      v20 = *(const char **)(v19 + 4);
      if ( !v20 )
        v20 = WindowName;
      if ( !_stricmp(v20, String2) )
        return this[12];
    }
    v21 = 0;
    if ( (int)this[14] > 0 )
    {
      while ( 1 )
      {
        v22 = *(const char **)(this[8] + v2 + 4);
        if ( !v22 )
          v22 = WindowName;
        if ( !_stricmp(v22, String2) )
          break;
        ++v21;
        v2 += 204;
        if ( v21 >= this[14] )
          return 0;
      }
      return this[8] + 204 * v21;
    }
  }
  return v23;
}
