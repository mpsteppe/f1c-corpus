const char ***__stdcall sub_436F70(int a1)
{
  int v1; // eax
  int v2; // ecx
  const char ***result; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // esi
  int v7; // edi
  const char ***v8; // ebp
  const char *v9; // ecx
  const char *v10; // edx
  const char ***v11; // ebx
  const char **v12; // edx
  const char *v13; // esi
  const char *v14; // ecx
  const char ***v15; // ecx
  const char ***v16; // [esp+Ch] [ebp+4h]

  v1 = 0;
  v2 = a1;
  if ( !a1 )
    return (const char ***)a1;
  do
  {
    v2 = *(_DWORD *)(v2 + 4);
    ++v1;
  }
  while ( v2 );
  if ( v1 < 2 )
    return (const char ***)a1;
  v4 = v1 / 2 - 1;
  v5 = a1;
  if ( v4 > 0 )
  {
    do
    {
      --v4;
      v5 = *(_DWORD *)(v5 + 4);
    }
    while ( v4 );
  }
  v6 = *(_DWORD *)(v5 + 4);
  *(_DWORD *)(v5 + 4) = 0;
  v7 = sub_436F70(a1);
  result = (const char ***)sub_436F70(v6);
  v8 = result;
  if ( v7 )
  {
    if ( result )
    {
      v9 = **result;
      if ( !v9 )
        v9 = &byte_629120;
      v10 = **(const char ***)v7;
      if ( !v10 )
        v10 = &byte_629120;
      if ( strcmp(v10, v9) >= 0 )
      {
        v16 = v8;
        v11 = v8;
        v8 = (const char ***)v8[1];
      }
      else
      {
        v16 = (const char ***)v7;
        v11 = (const char ***)v7;
        v7 = *(_DWORD *)(v7 + 4);
      }
      if ( v7 )
      {
        while ( v8 )
        {
          v12 = *(const char ***)v7;
          v13 = **v8;
          if ( !v13 )
            v13 = &byte_629120;
          v14 = *v12;
          if ( !*v12 )
            v14 = &byte_629120;
          if ( strcmp(v14, v13) >= 0 )
          {
            v15 = v8;
            v8 = (const char ***)v8[1];
          }
          else
          {
            v15 = (const char ***)v7;
            v7 = *(_DWORD *)(v7 + 4);
          }
          v11[1] = (const char **)v15;
          v11 = v15;
          if ( !v7 )
            goto LABEL_26;
        }
        result = v16;
        v11[1] = (const char **)v7;
      }
      else
      {
LABEL_26:
        result = v16;
        if ( v8 )
          v11[1] = (const char **)v8;
        else
          v11[1] = 0;
      }
    }
    else
    {
      return (const char ***)v7;
    }
  }
  return result;
}
