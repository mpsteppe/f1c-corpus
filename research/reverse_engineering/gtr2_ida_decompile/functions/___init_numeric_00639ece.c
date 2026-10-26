int __init_numeric()
{
  char **v0; // ebx
  _DWORD *v1; // eax
  _DWORD *v3; // eax
  int v4; // esi
  int v5; // esi
  char *v6; // eax
  char v7; // cl
  char *v8; // esi
  void *Block; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]
  int v11; // [esp+10h] [ebp-4h]

  if ( dword_FB83EC || dword_FB83E8 )
  {
    v0 = (char **)calloc(1u, 0x30u);
    if ( !v0 )
      return 1;
    qmemcpy(v0, off_91318C, 0x30u);
    v1 = malloc(4u);
    Block = v1;
    if ( !v1 )
    {
      free(v0);
      return 1;
    }
    *v1 = 0;
    if ( !dword_FB83EC )
    {
      dword_FBB5F8 = 0;
      *v0 = (char *)off_91315C;
      v0[1] = (char *)off_913160;
      v0[2] = (char *)off_913164;
LABEL_30:
      if ( dword_FBB5F4 && !*(_DWORD *)dword_FBB5F4 && dword_FBB5F4 != *((void **)off_91290C + 11) )
      {
        free(dword_FBB5F4);
        free(dword_FB83B4);
      }
      dword_FBB5F4 = Block;
      dword_FB83B4 = v0;
      goto LABEL_35;
    }
    v3 = malloc(4u);
    dword_FBB5F8 = (int)v3;
    if ( !v3 )
    {
      v4 = 1;
LABEL_17:
      free(v0);
      free(Block);
      return v4;
    }
    *v3 = 0;
    v5 = (unsigned __int16)word_FB841A;
    v10 = sub_6422F4(1, (unsigned __int16)word_FB841A, 14, v0);
    v11 = sub_6422F4(1, v5, 15, v0 + 1) | v10;
    if ( v11 | sub_6422F4(1, v5, 16, v0 + 2) )
    {
      __free_lconv_num((int)v0);
      v4 = -1;
      goto LABEL_17;
    }
    v6 = v0[2];
    while ( 1 )
    {
      if ( !*v6 )
        goto LABEL_30;
      v7 = *v6;
      if ( *v6 >= 48 && v7 <= 57 )
        break;
      if ( v7 == 59 )
      {
        v8 = v6;
        do
        {
          *v8 = v8[1];
          ++v8;
        }
        while ( *v8 );
      }
      else
      {
LABEL_22:
        ++v6;
      }
    }
    *v6 = v7 - 48;
    goto LABEL_22;
  }
  if ( dword_FBB5F4 && !*(_DWORD *)dword_FBB5F4 && dword_FBB5F4 != *((void **)off_91290C + 11) )
  {
    free(dword_FBB5F4);
    free(dword_FB83B4);
  }
  dword_FBB5F8 = 0;
  dword_FBB5F4 = 0;
  v0 = (char **)&off_91315C;
  dword_FB83B4 = 0;
LABEL_35:
  off_91318C = (_UNKNOWN **)v0;
  byte_9131A4 = **v0;
  dword_9131A8 = 1;
  return 0;
}
