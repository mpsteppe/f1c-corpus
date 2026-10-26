int __thiscall sub_5E5670(_DWORD *this, char *String2, int a3)
{
  int v4; // ecx
  char *v5; // edi
  int *v6; // eax
  bool v7; // zf
  int v8; // esi
  _DWORD *v9; // eax
  int result; // eax
  int v11; // eax
  int *v12; // eax
  int **v13; // edi
  int *v14; // eax
  _DWORD *v15; // eax
  int *v16; // eax
  int *v17; // eax

  v4 = a3;
  v5 = (char *)(a3 + 800);
  if ( !a3 )
    v5 = (char *)(this + 97);
  v6 = *(int **)v5;
  v7 = *(_DWORD *)v5 == 0;
  *((_DWORD *)v5 + 2) = *(_DWORD *)v5;
  if ( v7 || (v8 = *v6) == 0 )
  {
LABEL_13:
    v13 = (int **)(v4 + 800);
    if ( !v4 )
      v13 = (int **)(this + 101);
    v14 = *v13;
    v7 = *v13 == 0;
    v13[2] = *v13;
    if ( v7 )
      return 0;
    v8 = *v14;
    if ( !*v14 )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        v15 = *(_DWORD **)(v8 + 800);
        *(_DWORD *)(v8 + 808) = v15;
        if ( v15 )
        {
          if ( *v15 )
          {
            result = sub_5E5670(String2, v8);
            if ( result )
              break;
          }
        }
        if ( !_stricmp((const char *)(v8 + 4), String2) )
          return v8;
        v16 = v13[2];
        if ( v16 )
        {
          v17 = (int *)v16[1];
          v13[2] = v17;
          if ( v17 )
          {
            v8 = *v17;
            if ( *v17 )
              continue;
          }
        }
        return 0;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      v9 = *(_DWORD **)(v8 + 800);
      *(_DWORD *)(v8 + 808) = v9;
      if ( v9 )
      {
        if ( *v9 )
        {
          result = sub_5E5670(String2, v8);
          if ( result )
            break;
        }
      }
      if ( !_stricmp((const char *)(v8 + 4), String2) )
        return v8;
      v11 = *((_DWORD *)v5 + 2);
      if ( v11 )
      {
        v12 = *(int **)(v11 + 4);
        *((_DWORD *)v5 + 2) = v12;
        if ( v12 )
        {
          v8 = *v12;
          if ( *v12 )
            continue;
        }
      }
      v4 = a3;
      goto LABEL_13;
    }
  }
  return result;
}
