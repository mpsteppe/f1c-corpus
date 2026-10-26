char __thiscall sub_40A280(int this, char *String2, int a3)
{
  int v4; // ecx
  const char *v5; // eax
  int *v6; // eax
  bool v7; // zf
  int v8; // ecx
  int j; // eax
  int v10; // eax
  int *v11; // eax
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  const char *v15; // eax
  int v16; // eax
  int *v17; // eax
  int *v18; // eax
  int v19; // edi
  const char *v20; // eax
  int v21; // eax
  int *v22; // eax
  int *v23; // eax
  int v24; // ecx
  int i; // eax
  int v26; // eax
  int *v27; // eax
  int v28; // eax
  int *v29; // eax
  int v30; // edi
  const char *v31; // eax
  int v32; // eax
  int *v33; // eax
  int *v34; // eax
  int v35; // edi
  const char *v36; // eax
  int v37; // eax
  int *v38; // eax
  const char *v39; // eax
  char *v40; // eax
  int v41; // eax
  int *v42; // eax
  int v43; // edi
  const char *v44; // eax
  int v45; // eax
  int *v46; // eax
  int v47; // ecx
  const char *v48; // eax
  int v49; // eax
  char result; // al
  char v51; // [esp+13h] [ebp-1h]

  v4 = *(_DWORD *)(this + 16);
  v51 = 0;
  if ( !v4 || (v5 = (const char *)sub_459BA0(v4), _strcmpi(v5, String2)) )
  {
    if ( _strcmpi(String2, aDrivable) )
      goto LABEL_63;
    v39 = *(const char **)(this + 28);
    if ( !v39 )
      v39 = &byte_629120;
    if ( !strlen(v39) )
      goto LABEL_63;
    v40 = *(char **)(this + 28);
    if ( !v40 )
      v40 = &byte_629120;
    v41 = sub_40A660(v40);
    if ( v41 )
    {
      if ( !(unsigned __int8)sub_40A7D0(v41) )
        sub_40A1B0((int **)this, aSwingman);
    }
    else
    {
LABEL_63:
      v42 = *(int **)this;
      v7 = *(_DWORD *)this == 0;
      *(_DWORD *)(this + 8) = *(_DWORD *)this;
      if ( v7 )
        goto LABEL_75;
      v43 = *v42;
      if ( !*v42 )
        goto LABEL_75;
      while ( 1 )
      {
        v44 = (const char *)sub_459BA0(v43);
        if ( !_strcmpi(String2, v44) )
        {
          if ( (unsigned __int8)sub_40A7D0(v43) )
            break;
        }
        v45 = *(_DWORD *)(this + 8);
        if ( v45 )
        {
          v46 = *(int **)(v45 + 4);
          *(_DWORD *)(this + 8) = v46;
          if ( v46 )
          {
            v43 = *v46;
            if ( *v46 )
              continue;
          }
        }
        goto LABEL_75;
      }
    }
    v51 = 1;
  }
  else
  {
    v51 = 1;
    if ( a3 )
    {
      if ( a3 == 1 )
      {
        v23 = *(int **)this;
        v7 = *(_DWORD *)this == 0;
        v24 = *(_DWORD *)(this + 16);
        *(_DWORD *)(this + 8) = *(_DWORD *)this;
        if ( !v7 )
        {
          for ( i = *v23; i; i = *v27 )
          {
            if ( i == v24 )
              break;
            v26 = *(_DWORD *)(this + 8);
            if ( !v26 )
              break;
            v27 = *(int **)(v26 + 4);
            *(_DWORD *)(this + 8) = v27;
            if ( !v27 )
              break;
          }
        }
        v28 = *(_DWORD *)(this + 8);
        if ( v28 )
          *(_DWORD *)(this + 8) = *(_DWORD *)(v28 + 8);
        v29 = *(int **)(this + 8);
        if ( v29 && (v30 = *v29) != 0 )
        {
          while ( 1 )
          {
            v31 = (const char *)sub_459BA0(v30);
            if ( !_strcmpi(v31, String2) )
            {
              if ( (unsigned __int8)sub_40A7D0(v30) )
                break;
            }
            v32 = *(_DWORD *)(this + 8);
            if ( v32 )
            {
              v33 = *(int **)(v32 + 8);
              *(_DWORD *)(this + 8) = v33;
              if ( v33 )
              {
                v30 = *v33;
                if ( *v33 )
                  continue;
              }
            }
            goto LABEL_43;
          }
        }
        else
        {
LABEL_43:
          v34 = *(int **)(this + 4);
          *(_DWORD *)(this + 8) = v34;
          if ( v34 )
          {
            v35 = *v34;
            if ( *v34 )
            {
              do
              {
                v36 = (const char *)sub_459BA0(v35);
                if ( !_strcmpi(v36, String2) && (unsigned __int8)sub_40A7D0(v35) )
                  break;
                v37 = *(_DWORD *)(this + 8);
                if ( !v37 )
                  break;
                v38 = *(int **)(v37 + 8);
                *(_DWORD *)(this + 8) = v38;
                if ( !v38 )
                  break;
                v35 = *v38;
              }
              while ( *v38 );
            }
          }
        }
      }
    }
    else
    {
      v6 = *(int **)this;
      v7 = *(_DWORD *)this == 0;
      v8 = *(_DWORD *)(this + 16);
      *(_DWORD *)(this + 8) = *(_DWORD *)this;
      if ( !v7 )
      {
        for ( j = *v6; j; j = *v11 )
        {
          if ( j == v8 )
            break;
          v10 = *(_DWORD *)(this + 8);
          if ( !v10 )
            break;
          v11 = *(int **)(v10 + 4);
          *(_DWORD *)(this + 8) = v11;
          if ( !v11 )
            break;
        }
      }
      v12 = *(_DWORD *)(this + 8);
      if ( v12 )
        *(_DWORD *)(this + 8) = *(_DWORD *)(v12 + 4);
      v13 = *(int **)(this + 8);
      if ( v13 && (v14 = *v13) != 0 )
      {
        while ( 1 )
        {
          v15 = (const char *)sub_459BA0(v14);
          if ( !_strcmpi(v15, String2) )
          {
            if ( (unsigned __int8)sub_40A7D0(v14) )
              break;
          }
          v16 = *(_DWORD *)(this + 8);
          if ( v16 )
          {
            v17 = *(int **)(v16 + 4);
            *(_DWORD *)(this + 8) = v17;
            if ( v17 )
            {
              v14 = *v17;
              if ( *v17 )
                continue;
            }
          }
          goto LABEL_19;
        }
      }
      else
      {
LABEL_19:
        v18 = *(int **)this;
        v7 = *(_DWORD *)this == 0;
        *(_DWORD *)(this + 8) = *(_DWORD *)this;
        if ( !v7 )
        {
          v19 = *v18;
          if ( *v18 )
          {
            do
            {
              v20 = (const char *)sub_459BA0(v19);
              if ( !_strcmpi(v20, String2) && (unsigned __int8)sub_40A7D0(v19) )
                break;
              v21 = *(_DWORD *)(this + 8);
              if ( !v21 )
                break;
              v22 = *(int **)(v21 + 4);
              *(_DWORD *)(this + 8) = v22;
              if ( !v22 )
                break;
              v19 = *v22;
            }
            while ( *v22 );
          }
        }
      }
    }
  }
  if ( _strcmpi(String2, aTrackside) )
    *(_DWORD *)(this + 24) = 0;
  else
    *(_DWORD *)(this + 24) = 1;
  v47 = *(_DWORD *)(this + 20);
  if ( v47 )
  {
    v48 = (const char *)sub_459BA0(v47);
    if ( !_strcmpi(v48, aDrivable) )
    {
      v49 = sub_459B80(*(_DWORD *)(this + 20));
      sub_578600(v49);
    }
  }
LABEL_75:
  result = v51;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 0;
  *(_DWORD *)(this + 84) = 0;
  *(_DWORD *)(this + 88) = 0;
  return result;
}
