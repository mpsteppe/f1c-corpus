int __usercall sub_62A3D0@<eax>(int *a1@<eax>)
{
  unsigned int i; // edi
  int v3; // eax
  int v4; // eax
  int v5; // edx
  unsigned __int8 v6; // cl
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int result; // eax
  int v11; // eax
  int v12; // ecx
  unsigned __int8 v13; // cl
  char v14; // bl
  int v15; // edx
  char v16; // cl
  int v17; // edi
  int v18; // eax
  int v19; // edi
  int v20; // edi
  int v22; // eax
  char *v23; // eax
  unsigned __int8 v24; // cl
  char *v25; // eax
  unsigned __int8 v26; // cl
  int v27; // ecx
  char *v28; // eax
  unsigned __int8 v29; // cl
  int v30; // edx
  int j; // edi
  int v32; // edx

  for ( i = 0; i < 2; ++i )
  {
    if ( a1[15] )
    {
      v3 = -1;
      goto LABEL_11;
    }
    if ( a1[1] )
      goto LABEL_10;
    *_errno() = 0;
    v4 = sub_6318A2(a1[17], 1, 0x4000, a1[16]);
    a1[1] = v4;
    if ( v4 )
    {
      *a1 = a1[17];
LABEL_10:
      --a1[1];
      v6 = *(_BYTE *)(*a1)++;
      v3 = v6;
      goto LABEL_11;
    }
    v5 = a1[16];
    a1[15] = 1;
    if ( (*(_BYTE *)(v5 + 12) & 0x20) != 0 )
      a1[14] = -1;
    v3 = -1;
LABEL_11:
    if ( v3 != dword_911678[i] )
    {
      if ( i )
      {
        v8 = *a1 - 1;
        ++a1[1];
        *a1 = v8;
      }
      if ( v3 != -1 )
      {
        v9 = *a1 - 1;
        ++a1[1];
        *a1 = v9;
        a1[22] = 1;
      }
      result = a1[1];
      a1[14] = result == 0;
      return result;
    }
  }
  if ( a1[15] )
  {
    v7 = -1;
    goto LABEL_27;
  }
  if ( a1[1] )
    goto LABEL_26;
  *_errno() = 0;
  v11 = sub_6318A2(a1[17], 1, 0x4000, a1[16]);
  a1[1] = v11;
  if ( v11 )
  {
    *a1 = a1[17];
LABEL_26:
    --a1[1];
    v13 = *(_BYTE *)(*a1)++;
    v7 = v13;
    goto LABEL_27;
  }
  v12 = a1[16];
  a1[15] = 1;
  if ( (*(_BYTE *)(v12 + 12) & 0x20) != 0 )
    a1[14] = -1;
  v7 = -1;
LABEL_27:
  result = a1[15];
  if ( result )
  {
    v14 = -1;
    goto LABEL_36;
  }
  if ( a1[1] )
  {
LABEL_35:
    --a1[1];
    v16 = *(_BYTE *)*a1;
    result = *a1 + 1;
    *a1 = result;
    v14 = v16;
    goto LABEL_36;
  }
  *_errno() = 0;
  result = sub_6318A2(a1[17], 1, 0x4000, a1[16]);
  a1[1] = result;
  if ( result )
  {
    *a1 = a1[17];
    goto LABEL_35;
  }
  v15 = a1[16];
  a1[15] = 1;
  if ( (*(_BYTE *)(v15 + 12) & 0x20) != 0 )
    a1[14] = -1;
  v14 = -1;
LABEL_36:
  if ( v7 != 8 || (v14 & 0xE0) != 0 )
  {
    a1[14] = -3;
    return result;
  }
  v17 = 6;
  while ( 2 )
  {
    result = a1[15];
    if ( !result )
    {
      if ( !a1[1] )
      {
        *_errno() = 0;
        v18 = sub_6318A2(a1[17], 1, 0x4000, a1[16]);
        a1[1] = v18;
        if ( !v18 )
        {
          result = a1[16];
          a1[15] = 1;
          if ( (*(_BYTE *)(result + 12) & 0x20) != 0 )
            a1[14] = -1;
          goto LABEL_46;
        }
        *a1 = a1[17];
      }
      result = *a1 + 1;
      --a1[1];
      *a1 = result;
    }
LABEL_46:
    if ( --v17 )
      continue;
    break;
  }
  if ( (v14 & 4) != 0 )
  {
    v19 = sub_62A360(a1);
    result = sub_62A360(a1) << 8;
    v20 = result + v19;
    do
    {
      if ( !v20-- )
        break;
      result = a1[15];
      if ( result )
        break;
      if ( !a1[1] )
      {
        *_errno() = 0;
        v22 = sub_6318A2(a1[17], 1, 0x4000, a1[16]);
        a1[1] = v22;
        if ( !v22 )
        {
          result = a1[16];
          a1[15] = 1;
          if ( (*(_BYTE *)(result + 12) & 0x20) != 0 )
            a1[14] = -1;
          break;
        }
        *a1 = a1[17];
      }
      v23 = (char *)*a1;
      --a1[1];
      v24 = *v23;
      *a1 = (int)(v23 + 1);
      result = v24;
    }
    while ( v24 != -1 );
  }
  if ( (v14 & 8) != 0 )
  {
    do
    {
      result = a1[15];
      if ( result )
        break;
      if ( !a1[1] )
      {
        *_errno() = 0;
        result = sub_6318A2(a1[17], 1, 0x4000, a1[16]);
        a1[1] = result;
        if ( !result )
        {
          v27 = a1[16];
          a1[15] = 1;
          if ( (*(_BYTE *)(v27 + 12) & 0x20) != 0 )
            a1[14] = -1;
          break;
        }
        *a1 = a1[17];
      }
      v25 = (char *)*a1;
      --a1[1];
      v26 = *v25;
      *a1 = (int)(v25 + 1);
      result = v26;
    }
    while ( v26 && v26 != -1 );
  }
  if ( (v14 & 0x10) != 0 )
  {
    do
    {
      result = a1[15];
      if ( result )
        break;
      if ( !a1[1] )
      {
        *_errno() = 0;
        result = sub_6318A2(a1[17], 1, 0x4000, a1[16]);
        a1[1] = result;
        if ( !result )
        {
          v30 = a1[16];
          a1[15] = 1;
          if ( (*(_BYTE *)(v30 + 12) & 0x20) != 0 )
            a1[14] = -1;
          break;
        }
        *a1 = a1[17];
      }
      v28 = (char *)*a1;
      --a1[1];
      v29 = *v28;
      *a1 = (int)(v28 + 1);
      result = v29;
    }
    while ( v29 && v29 != -1 );
  }
  if ( (v14 & 2) != 0 )
  {
    for ( j = 2; j; --j )
    {
      result = a1[15];
      if ( !result )
      {
        if ( !a1[1] )
        {
          *_errno() = 0;
          result = sub_6318A2(a1[17], 1, 0x4000, a1[16]);
          a1[1] = result;
          if ( !result )
          {
            v32 = a1[16];
            a1[15] = 1;
            if ( (*(_BYTE *)(v32 + 12) & 0x20) != 0 )
              a1[14] = -1;
            continue;
          }
          *a1 = a1[17];
        }
        result = *a1 + 1;
        --a1[1];
        *a1 = result;
      }
    }
  }
  a1[14] = a1[15] != 0 ? 0xFFFFFFFD : 0;
  return result;
}
