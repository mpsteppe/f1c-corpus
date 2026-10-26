int __thiscall sub_65A765(int this)
{
  _DWORD *v2; // edi
  int v3; // esi
  int v4; // eax
  unsigned int v5; // eax
  int v6; // eax
  unsigned int v7; // esi
  int v8; // eax
  void *v9; // edi
  int v10; // eax
  void *v11; // edi
  int v12; // eax
  int result; // eax
  int v14; // edi
  _DWORD *v15; // edi
  int i; // eax
  int v17; // [esp+Ch] [ebp-18h]
  unsigned int v18; // [esp+10h] [ebp-14h]
  int v19; // [esp+14h] [ebp-10h]
  _DWORD *v20; // [esp+18h] [ebp-Ch]
  _BYTE *Block; // [esp+1Ch] [ebp-8h]
  unsigned int v22; // [esp+20h] [ebp-4h]

  Block = 0;
  v20 = 0;
  v2 = (_DWORD *)(this + 632);
  v3 = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
  if ( v3 < 0 )
    goto LABEL_52;
  if ( *v2 != 1 || strcmp((const char *)(this + 640), "(") )
    goto LABEL_48;
  v3 = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
  if ( v3 < 0 )
    goto LABEL_52;
  v22 = 0;
LABEL_6:
  v4 = *(_DWORD *)(this + 632);
  if ( v4 == 1 && !strcmp((const char *)(this + 640), (const char *)&word_6FBE80) )
  {
    v3 = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
    if ( v3 < 0 )
      goto LABEL_52;
    v14 = *(_DWORD *)(this + 632);
    if ( v14 != 12 && v14 != 13 )
      goto LABEL_48;
    v18 = 0;
    if ( !v22 )
    {
LABEL_51:
      v3 = 0;
      goto LABEL_52;
    }
    v15 = v20;
    for ( i = Block - (_BYTE *)v20; ; i = Block - (_BYTE *)v20 )
    {
      v3 = sub_65DCB5(*v15, *(_DWORD *)((char *)v15 + i));
      if ( v3 < 0 )
        break;
      ++v18;
      ++v15;
      if ( v18 >= v22 )
        goto LABEL_51;
    }
    goto LABEL_52;
  }
  if ( v4 == 9 )
  {
    if ( !strcmp(*(const char **)(this + 640), "once") )
    {
      v19 = 16;
    }
    else if ( !strcmp(*(const char **)(this + 640), "error") )
    {
      v19 = 15;
    }
    else if ( !strcmp(*(const char **)(this + 640), "disable") )
    {
      v19 = 0;
    }
    else
    {
      if ( strcmp(*(const char **)(this + 640), "default") )
        goto LABEL_48;
      v19 = 255;
    }
  }
  else
  {
    if ( v4 != 2 && v4 != 3 && v4 != 4 )
      goto LABEL_48;
    v5 = *(_DWORD *)(this + 640);
    if ( !v5 || v5 > 4 )
      goto LABEL_48;
    v19 = *(_DWORD *)(this + 640);
  }
  v3 = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
  if ( v3 < 0 )
    goto LABEL_52;
  if ( *(_DWORD *)(this + 632) != 1 || strcmp((const char *)(this + 640), ":") )
  {
LABEL_48:
    v12 = *(_DWORD *)(this + 632);
    if ( v12 != 12 && v12 != 13 )
      sub_65D86A(*(_DWORD *)(this + 620));
    goto LABEL_51;
  }
  v3 = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
  if ( v3 >= 0 )
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)(this + 632);
      if ( v6 != 2 && v6 != 3 && v6 != 4 )
        goto LABEL_48;
      v7 = v22;
      v17 = *(_DWORD *)(this + 640);
      if ( v22 == (v22 & -v22) )
      {
        if ( v22 )
          v8 = 2 * v22;
        else
          v8 = 1;
        v9 = operator new(4 * v8);
        if ( !v9
          || ((qmemcpy(v9, Block, 4 * v22), j__free(Block), Block = v9, !v22) ? (v10 = 1) : (v10 = 2 * v22),
              (v11 = operator new(4 * v10)) == 0) )
        {
          v3 = -2147024882;
          break;
        }
        qmemcpy(v11, v20, 4 * v22);
        j__free(v20);
        v7 = v22;
        v20 = v11;
      }
      v20[v7] = v17;
      *(_DWORD *)&Block[4 * v7] = v19;
      v22 = v7 + 1;
      v3 = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
      if ( v3 < 0 )
        break;
      if ( *(_DWORD *)(this + 632) == 1
        && (!strcmp((const char *)(this + 640), ";") || !strcmp((const char *)(this + 640), (const char *)&word_6FBE80)) )
      {
        if ( strcmp((const char *)(this + 640), ";") )
          goto LABEL_6;
        v3 = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
        if ( v3 < 0 )
          break;
        if ( *(_DWORD *)(this + 632) != 1 || strcmp((const char *)(this + 640), (const char *)&word_6FBE80) )
          goto LABEL_6;
        goto LABEL_48;
      }
    }
  }
LABEL_52:
  j__free(Block);
  j__free(v20);
  j__free(0);
  result = v3;
  *(_DWORD *)(this + 64) = 1;
  return result;
}
