int __init_monetary()
{
  char *v0; // ebx
  _DWORD *v1; // eax
  void *v2; // edi
  _DWORD *v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  char *v20; // eax
  char v21; // cl
  char *v22; // esi
  void *Block; // [esp+Ch] [ebp-4h]

  if ( dword_FB83E8 || dword_FB83EC )
  {
    v0 = (char *)calloc(1u, 0x30u);
    if ( !v0 )
      return 1;
    v1 = malloc(4u);
    v2 = v1;
    Block = v1;
    if ( !v1 )
    {
      free(v0);
      return 1;
    }
    *v1 = 0;
    if ( !dword_FB83E8 )
    {
      qmemcpy(v0, &off_91315C, 0x30u);
      dword_FBB5F0 = 0;
LABEL_25:
      *(_DWORD *)v0 = *off_91318C;
      *((_DWORD *)v0 + 1) = off_91318C[1];
      *((_DWORD *)v0 + 2) = off_91318C[2];
      off_91318C = (_UNKNOWN **)v0;
      dword_FBB5F4 = Block;
      dword_FB83B4 = v0;
      return 0;
    }
    v3 = malloc(4u);
    dword_FBB5F0 = (int)v3;
    if ( !v3 )
    {
      free(v0);
      free(v2);
      return 1;
    }
    *v3 = 0;
    v4 = (unsigned __int16)word_FB8414;
    v5 = sub_6422F4(1, (unsigned __int16)word_FB8414, 21, v0 + 12);
    v6 = sub_6422F4(1, v4, 20, v0 + 16) | v5;
    v7 = sub_6422F4(1, v4, 22, v0 + 20) | v6;
    v8 = sub_6422F4(1, v4, 23, v0 + 24) | v7;
    v9 = sub_6422F4(1, v4, 24, v0 + 28) | v8;
    v10 = sub_6422F4(1, v4, 80, v0 + 32) | v9;
    v11 = sub_6422F4(1, v4, 81, v0 + 36) | v10;
    v12 = sub_6422F4(0, v4, 26, v0 + 40) | v11;
    v13 = sub_6422F4(0, v4, 25, v0 + 41) | v12;
    v14 = sub_6422F4(0, v4, 84, v0 + 42) | v13;
    v15 = sub_6422F4(0, v4, 85, v0 + 43) | v14;
    v16 = sub_6422F4(0, v4, 86, v0 + 44) | v15;
    v17 = sub_6422F4(0, v4, 87, v0 + 45) | v16;
    v18 = sub_6422F4(0, v4, 82, v0 + 46) | v17;
    if ( v18 | sub_6422F4(0, v4, 83, v0 + 47) )
    {
      __free_lconv_mon((int)v0);
      free(v0);
      free(Block);
      return 1;
    }
    v20 = (char *)*((_DWORD *)v0 + 7);
    while ( 1 )
    {
      if ( !*v20 )
        goto LABEL_25;
      v21 = *v20;
      if ( *v20 >= 48 && v21 <= 57 )
        break;
      if ( v21 == 59 )
      {
        v22 = v20;
        do
        {
          *v22 = v22[1];
          ++v22;
        }
        while ( *v22 );
      }
      else
      {
LABEL_17:
        ++v20;
      }
    }
    *v20 = v21 - 48;
    goto LABEL_17;
  }
  dword_FBB5F0 = 0;
  dword_FBB5F4 = 0;
  off_91318C = &off_91315C;
  dword_FB83B4 = 0;
  return 0;
}
