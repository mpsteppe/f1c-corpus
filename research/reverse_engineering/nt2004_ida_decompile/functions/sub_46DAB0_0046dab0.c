int *__stdcall sub_46DAB0(int a1)
{
  int v1; // eax
  int v2; // ecx
  int *result; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  int **v7; // esi
  unsigned int *v8; // edi
  unsigned int v9; // edx
  unsigned int v10; // ecx
  int v11; // ebp
  _DWORD *v12; // ebx
  int v13; // edx
  int v14; // ecx
  int *v15; // ecx
  int v16; // ebp
  _DWORD **v17; // esi
  int v18; // ebx
  int v19; // ecx
  _DWORD *v20; // edi
  int v21; // edx
  int v22; // ecx
  int *v23; // ecx
  int *v24; // [esp+8h] [ebp-14h]
  unsigned int v25; // [esp+Ch] [ebp-10h]
  int **v26; // [esp+Ch] [ebp-10h]
  unsigned int v27; // [esp+10h] [ebp-Ch]
  int **v28; // [esp+10h] [ebp-Ch]
  int *v29; // [esp+20h] [ebp+4h]

  v1 = 0;
  v2 = a1;
  if ( !a1 )
    return (int *)a1;
  do
  {
    v2 = *(_DWORD *)(v2 + 4);
    ++v1;
  }
  while ( v2 );
  if ( v1 < 2 )
    return (int *)a1;
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
  v7 = (int **)sub_46DAB0(a1);
  result = (int *)sub_46DAB0(v6);
  v24 = result;
  v29 = (int *)v7;
  if ( v7 )
  {
    if ( result )
    {
      v8 = (unsigned int *)**v7;
      v9 = *v8;
      v10 = *v8 >> 28;
      v11 = 0;
      v25 = *v8;
      v27 = v10;
      v12 = (_DWORD *)(dword_7652DC + 14060);
      while ( 1 )
      {
        if ( v10 == 4 && ((*((_BYTE *)v8 + 2) & 0x3F) == 0 || (*((_BYTE *)v8 + 2) & 0x3F) == 1) )
        {
LABEL_21:
          v28 = v7;
          v26 = v7;
          v29 = v7[1];
          goto LABEL_23;
        }
        v13 = v9 & 0x3F;
        v14 = **(_DWORD **)*result & 0x3F;
        if ( v13 == 63 )
        {
          if ( v14 != 63 )
            goto LABEL_21;
        }
        else if ( v14 == 63 )
        {
          break;
        }
        if ( *v12 == v13 )
          break;
        if ( *v12 == v14 )
          goto LABEL_21;
        ++v11;
        ++v12;
        if ( v11 >= 49 )
          goto LABEL_21;
        v10 = v27;
        LOBYTE(v9) = v25;
        v8 = (unsigned int *)**v7;
      }
      v28 = (int **)result;
      v26 = (int **)result;
      result = (int *)result[1];
      v24 = result;
LABEL_23:
      v15 = v29;
      if ( v29 )
      {
        while ( result )
        {
          v16 = *(_DWORD *)*v15;
          v17 = (_DWORD **)*result;
          v18 = 0;
          v19 = *(_DWORD *)v16 >> 28;
          v20 = (_DWORD *)(dword_7652DC + 14060);
          while ( 1 )
          {
            if ( v19 == 4 && ((*(_BYTE *)(v16 + 2) & 0x3F) == 0 || (*(_BYTE *)(v16 + 2) & 0x3F) == 1) )
            {
LABEL_40:
              v23 = v29;
              v29 = (int *)v29[1];
              goto LABEL_42;
            }
            v21 = *(_DWORD *)v16 & 0x3F;
            v22 = **v17 & 0x3F;
            if ( v21 == 63 )
            {
              if ( v22 != 63 )
                goto LABEL_40;
            }
            else if ( v22 == 63 )
            {
              break;
            }
            if ( *v20 == v21 )
              break;
            if ( *v20 == v22 )
              goto LABEL_40;
            ++v18;
            ++v20;
            if ( v18 >= 49 )
              goto LABEL_40;
            v17 = (_DWORD **)*result;
            v19 = *(_DWORD *)v16 >> 28;
          }
          v23 = v24;
          v24 = (int *)v24[1];
LABEL_42:
          result = v24;
          v26[1] = v23;
          v26 = (int **)v23;
          if ( !v29 )
            goto LABEL_24;
          v15 = v29;
        }
        if ( v15 )
        {
          v26[1] = v15;
          return (int *)v28;
        }
      }
      else
      {
LABEL_24:
        if ( result )
        {
          v26[1] = result;
          return (int *)v28;
        }
      }
      result = (int *)v28;
      v26[1] = 0;
    }
    else
    {
      return (int *)v7;
    }
  }
  return result;
}
