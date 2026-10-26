int __thiscall sub_4E9CE0(_DWORD *this, _DWORD *a2)
{
  int v3; // eax
  int v4; // ecx
  int v5; // edx
  int *v6; // eax
  int v7; // esi
  int v8; // edx
  int *v9; // eax
  int v10; // eax
  int i; // edi
  int v12; // ecx
  int *v13; // eax
  int v14; // ebx
  int v15; // ecx
  int *v16; // eax
  int v17; // esi
  CHAR *v18; // eax
  CHAR *v19; // eax
  _DWORD *v20; // edx
  int result; // eax
  int j; // ebp
  int v23; // ecx
  int *v24; // eax
  int v25; // ebx
  int v26; // ecx
  int *v27; // eax
  int v28; // edi
  int *v29; // eax
  int v30; // esi
  const char *v31; // ecx
  const char *v32; // eax
  const char *v33; // ecx
  const char *v34; // eax
  CHAR *v35; // eax
  CHAR *v36; // eax
  CHAR *v37; // esi
  _DWORD *v38; // [esp+10h] [ebp-4h]

  v3 = this[16];
  v4 = 0;
  v38 = this;
  if ( v3 > 0 )
  {
    do
    {
      v5 = v4;
      if ( v4 >= 0 && v4 < this[16] )
      {
        v6 = (int *)this[13];
        if ( v4 <= 0 )
        {
LABEL_7:
          if ( v6 )
          {
            v7 = *v6;
            goto LABEL_10;
          }
        }
        else
        {
          while ( v6 )
          {
            v6 = (int *)v6[1];
            if ( --v5 <= 0 )
              goto LABEL_7;
          }
        }
      }
      v7 = 0;
LABEL_10:
      v8 = v4;
      if ( v4 < 0 || v4 >= a2[16] )
        goto LABEL_16;
      v9 = (int *)a2[13];
      if ( v4 > 0 )
      {
        while ( v9 )
        {
          v9 = (int *)v9[1];
          if ( --v8 <= 0 )
            goto LABEL_15;
        }
LABEL_16:
        v10 = 0;
        goto LABEL_18;
      }
LABEL_15:
      if ( !v9 )
        goto LABEL_16;
      v10 = *v9;
LABEL_18:
      if ( v7 && v10 )
        *(_DWORD *)(v7 + 20) = *(_DWORD *)(v10 + 20);
      ++v4;
    }
    while ( v4 < this[16] );
  }
  for ( i = 0; i < this[24]; ++i )
  {
    v12 = i;
    if ( i >= 0 && i < this[24] )
    {
      v13 = (int *)this[21];
      if ( i <= 0 )
      {
LABEL_28:
        if ( v13 )
        {
          v14 = *v13;
          goto LABEL_31;
        }
      }
      else
      {
        while ( v13 )
        {
          v13 = (int *)v13[1];
          if ( --v12 <= 0 )
            goto LABEL_28;
        }
      }
    }
    v14 = 0;
LABEL_31:
    v15 = i;
    if ( i < 0 || i >= a2[24] )
      goto LABEL_37;
    v16 = (int *)a2[21];
    if ( i > 0 )
    {
      while ( v16 )
      {
        v16 = (int *)v16[1];
        if ( --v15 <= 0 )
          goto LABEL_36;
      }
LABEL_37:
      v17 = 0;
      goto LABEL_39;
    }
LABEL_36:
    if ( !v16 )
      goto LABEL_37;
    v17 = *v16;
LABEL_39:
    if ( v14 && v17 )
    {
      v18 = *(CHAR **)v17;
      if ( !*(_DWORD *)v17 )
        v18 = &byte_629120;
      sub_578600(v18);
      v19 = *(CHAR **)(v17 + 20);
      if ( !v19 )
        v19 = &byte_629120;
      sub_578600(v19);
      *(_DWORD *)(v14 + 28) = *(_DWORD *)(v17 + 28);
    }
  }
  v20 = this;
  result = this[20];
  for ( j = 0; j < result; ++j )
  {
    v23 = j;
    if ( j >= 0 && j < a2[20] )
    {
      v24 = (int *)a2[17];
      if ( j <= 0 )
      {
LABEL_53:
        if ( v24 )
        {
          v25 = *v24;
          if ( *v24 )
          {
            if ( *(_DWORD *)(v25 + 8) == 1 )
            {
              v26 = j;
              if ( j < v20[20] )
              {
                v27 = (int *)v20[17];
                if ( j <= 0 )
                {
LABEL_60:
                  if ( v27 )
                  {
                    v28 = *v27;
                    if ( *v27 )
                    {
                      if ( *(_DWORD *)(v28 + 40) )
                      {
                        sub_592310(*(_DWORD *)(v28 + 40));
                        *(_DWORD *)(v28 + 40) = 0;
                      }
                      if ( dword_7D6B74 )
                      {
                        v29 = *(int **)(dword_7D6B74 + 32);
                        *(_DWORD *)(dword_7D6B74 + 40) = v29;
                        if ( v29 )
                        {
                          v30 = *v29;
                          if ( *v29 )
                          {
                            while ( 1 )
                            {
                              v31 = *(const char **)v25;
                              if ( !*(_DWORD *)v25 )
                                v31 = &byte_629120;
                              v32 = *(const char **)v30;
                              if ( !*(_DWORD *)v30 )
                                v32 = &byte_629120;
                              if ( !_strcmpi(v32, v31) )
                              {
                                v33 = (const char *)v38[5];
                                if ( !v33 )
                                  v33 = &byte_629120;
                                v34 = *(const char **)(v30 + 28);
                                if ( !v34 )
                                  v34 = &byte_629120;
                                if ( !_strcmpi(v34, v33) )
                                  break;
                              }
                              v30 = sub_50EE10(dword_7D6B74 + 32);
                              if ( !v30 )
                                goto LABEL_86;
                            }
                            v35 = *(CHAR **)v30;
                            if ( !*(_DWORD *)v30 )
                              v35 = &byte_629120;
                            sub_578600(v35);
                            v36 = *(CHAR **)(v30 + 12);
                            if ( !v36 )
                              v36 = &byte_629120;
                            sub_578600(v36);
                            v37 = *(CHAR **)(v30 + 28);
                            if ( !v37 )
                              v37 = &byte_629120;
                            sub_578600(v37);
                            sub_4E9FB0(v28);
                          }
                        }
                      }
                    }
                  }
                }
                else
                {
                  while ( v27 )
                  {
                    v27 = (int *)v27[1];
                    if ( --v26 <= 0 )
                      goto LABEL_60;
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        while ( v24 )
        {
          v24 = (int *)v24[1];
          if ( --v23 <= 0 )
            goto LABEL_53;
        }
      }
    }
LABEL_86:
    v20 = v38;
    result = v38[20];
  }
  return result;
}
