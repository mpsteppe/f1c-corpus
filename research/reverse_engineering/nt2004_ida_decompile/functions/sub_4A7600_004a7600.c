char __thiscall sub_4A7600(_DWORD *this, _DWORD *a2, char a3, char a4, char a5)
{
  _DWORD *v5; // edi
  int v6; // edx
  int v8; // ecx
  int v9; // esi
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  int v12; // esi
  int *v13; // eax
  int v14; // eax
  int v15; // eax
  const char *v16; // eax
  int v17; // ebp
  int v18; // ecx
  int v19; // eax
  const char **v20; // edi
  const char *v21; // esi
  const char *v22; // eax
  int v23; // eax
  const char *v24; // eax
  char *v25; // eax
  _DWORD *v27; // [esp+10h] [ebp-4h]
  int v28; // [esp+1Ch] [ebp+8h]

  v5 = a2;
  v6 = a2[6];
  v8 = 0;
  a2[11] = 0;
  v27 = this;
  if ( *(int *)(v6 + 40) > 0 )
  {
    while ( 1 )
    {
      v9 = v8;
      if ( v8 < 0 || v8 >= *(_DWORD *)(v6 + 40) )
        goto LABEL_8;
      v10 = *(_DWORD **)(v6 + 28);
      if ( v8 > 0 )
        break;
LABEL_7:
      if ( !v10 )
        goto LABEL_8;
      v11 = (_DWORD *)*v10;
LABEL_10:
      if ( a2 != v11 )
      {
        v12 = v8;
        if ( v8 < 0 || v8 >= *(_DWORD *)(v6 + 40) )
          goto LABEL_17;
        v13 = *(int **)(v6 + 28);
        if ( v8 <= 0 )
        {
LABEL_16:
          if ( !v13 )
            goto LABEL_17;
          v14 = *v13;
        }
        else
        {
          while ( v13 )
          {
            v13 = (int *)v13[1];
            if ( --v12 <= 0 )
              goto LABEL_16;
          }
LABEL_17:
          v14 = 0;
        }
        *(_DWORD *)(v14 + 44) = 1;
      }
      v6 = a2[6];
      if ( ++v8 >= *(_DWORD *)(v6 + 40) )
        goto LABEL_21;
    }
    while ( v10 )
    {
      v10 = (_DWORD *)v10[1];
      if ( --v9 <= 0 )
        goto LABEL_7;
    }
LABEL_8:
    v11 = 0;
    goto LABEL_10;
  }
LABEL_21:
  sub_4A7310(this, (_DWORD *)(a2[6] + 28));
  v15 = a2[6];
  if ( v15 != this[67] && a3 )
    sub_4A7600(v15, 1, 0, 1);
  if ( a4 )
  {
    v16 = (const char *)a2[4];
    if ( !v16 )
      v16 = &byte_629120;
    if ( strcmp(v16, &byte_629120) )
    {
      v17 = 0;
      v28 = a2[10];
      if ( v28 > 0 )
      {
        while ( 1 )
        {
          v18 = v17;
          if ( v17 < 0 || v17 >= v5[10] )
            goto LABEL_35;
          v19 = v5[7];
          if ( v17 > 0 )
            break;
LABEL_34:
          if ( !v19 )
            goto LABEL_35;
          v20 = *(const char ***)v19;
LABEL_37:
          v21 = *v20;
          if ( !*v20 )
            v21 = &byte_629120;
          v22 = (const char *)a2[4];
          if ( !v22 )
            v22 = &byte_629120;
          if ( !strcmp(v22, v21) )
          {
            sub_4A7600(v20, 0, 1, 1);
            v5 = a2;
            goto LABEL_46;
          }
          v5 = a2;
          if ( ++v17 >= v28 )
          {
            this = v27;
            goto LABEL_44;
          }
        }
        while ( v19 )
        {
          v19 = *(_DWORD *)(v19 + 4);
          if ( --v18 <= 0 )
            goto LABEL_34;
        }
LABEL_35:
        v20 = 0;
        goto LABEL_37;
      }
    }
  }
LABEL_44:
  if ( (int)v5[10] > 0 )
    sub_4A7310(this, v5 + 7);
LABEL_46:
  LOBYTE(v23) = a5;
  if ( a5 )
  {
    v24 = (const char *)v5[2];
    if ( !v24 )
      v24 = &byte_629120;
    v23 = strcmp(v24, &byte_629120);
    if ( v23 )
    {
      v25 = (char *)v5[2];
      if ( !v25 )
        v25 = &byte_629120;
      LOBYTE(v23) = sub_4AD720(v25, 0);
    }
  }
  return v23;
}
