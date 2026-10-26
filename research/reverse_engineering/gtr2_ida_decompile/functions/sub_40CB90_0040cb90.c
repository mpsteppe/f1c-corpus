int *__thiscall sub_40CB90(_DWORD *this, char *String1, int a3, int a4)
{
  const char *v4; // edx
  int *result; // eax
  int *v7; // eax
  int v8; // ebx
  int v9; // eax
  int *v10; // eax
  int *v11; // eax
  int *v12; // ebx
  int v13; // esi
  const char *v14; // ebx
  int v15; // eax
  int *v16; // eax
  const char *v17; // ecx
  int v18; // eax
  int v19; // edx
  bool v20; // zf
  char *v21; // eax
  char v22; // cl
  char v23; // cl
  char *v24; // edi
  int v26; // eax
  const char ***v27; // eax
  const char **v28; // eax
  const char *v29; // eax
  int v30; // eax
  int v31; // eax
  const char ***v32; // eax
  int v33; // [esp+0h] [ebp-610h]
  int v34; // [esp+4h] [ebp-60Ch]
  int v35; // [esp+8h] [ebp-608h] BYREF
  int v36; // [esp+Ch] [ebp-604h] BYREF
  char Buffer[1032]; // [esp+208h] [ebp-408h] BYREF
  char *retaddr; // [esp+610h] [ebp+0h]

  v4 = String1;
  if ( !String1 && a3 == -1 && a4 == -1 )
    return 0;
  v7 = (int *)this[2];
  this[4] = v7;
  if ( v7 )
    v8 = *v7;
  else
    v8 = 0;
  v35 = 0;
  v36 = 0;
  if ( !String1 || !strcmp(String1, WindowName) )
  {
    v35 = sub_40B310();
    if ( !v35 )
      return 0;
    v34 = 1;
    if ( v8 )
    {
      while ( 1 )
      {
        result = *(int **)(v8 + 92);
        if ( *(char **)(v8 + 12) == String1 && *(_DWORD *)(v8 + 16) == a3 && result )
          break;
        v9 = this[4];
        if ( v9 )
          this[4] = *(_DWORD *)(v9 + 4);
        v10 = (int *)this[4];
        if ( v10 )
        {
          v8 = *v10;
          if ( *v10 )
            continue;
        }
        goto LABEL_19;
      }
      ++result[1];
      return result;
    }
LABEL_19:
    v11 = (int *)operator new(8u);
    if ( v11 )
    {
      *v11 = 0;
      v11[1] = 1;
      v12 = v11;
    }
    else
    {
      v12 = 0;
    }
    if ( !v34 )
    {
      v18 = sub_616480(retaddr, ".wav");
      v19 = (char *)&v36 - retaddr;
      v20 = v18 == 0;
      v21 = retaddr;
      if ( v20 )
      {
        do
        {
          v23 = *v21;
          v21[v19] = *v21;
          ++v21;
        }
        while ( v23 );
        v24 = (char *)&v35 + 3;
        while ( *++v24 )
          ;
        strcpy(v24, ".wav");
      }
      else
      {
        do
        {
          v22 = *v21;
          v21[v19] = *v21;
          ++v21;
        }
        while ( v22 );
      }
LABEL_48:
      v26 = AIL_file_read(&v35, 0);
      *v12 = v26;
      if ( v26 )
      {
LABEL_49:
        if ( v33 )
          sub_40A1E0();
        return v12;
      }
      v27 = (const char ***)this[10];
      this[12] = v27;
      if ( v27 )
      {
        v28 = *v27;
        if ( v28 )
        {
          while ( 1 )
          {
            v29 = *v28;
            if ( !v29 )
              v29 = WindowName;
            sprintf(Buffer, "%s%s", v29, (const char *)&v35);
            v30 = AIL_file_read(Buffer, 0);
            *v12 = v30;
            if ( v30 )
              goto LABEL_49;
            v31 = this[12];
            if ( v31 )
              this[12] = *(_DWORD *)(v31 + 4);
            v32 = (const char ***)this[12];
            if ( v32 )
            {
              v28 = *v32;
              if ( v28 )
                continue;
            }
            goto LABEL_61;
          }
        }
      }
      goto LABEL_61;
    }
    if ( !sub_40C720() )
    {
      v17 = *(const char **)(v35 + 4);
      if ( !v17 )
        v17 = WindowName;
      strcpy((char *)&v35, v17);
      goto LABEL_48;
    }
    if ( v12 )
LABEL_61:
      j__free(v12);
    return 0;
  }
  if ( !v8 )
    goto LABEL_19;
  while ( 1 )
  {
    v13 = *(_DWORD *)(v8 + 92);
    v14 = *(const char **)(v8 + 4);
    if ( !v14 )
      v14 = WindowName;
    if ( !_stricmp(v4, v14) && v13 )
      break;
    v15 = this[4];
    if ( v15 )
      this[4] = *(_DWORD *)(v15 + 4);
    v16 = (int *)this[4];
    if ( !v16 )
      goto LABEL_19;
    v8 = *v16;
    if ( !*v16 )
      goto LABEL_19;
    v4 = String1;
  }
  ++*(_DWORD *)(v13 + 4);
  return (int *)v13;
}
