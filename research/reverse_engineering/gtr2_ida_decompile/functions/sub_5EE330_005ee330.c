int __thiscall sub_5EE330(int this, char *ArgList)
{
  char *v2; // eax
  int v4; // edx
  char v5; // cl
  FILE *v6; // eax
  int v7; // edi
  FILE *v8; // eax
  int v9; // edi
  FILE *v10; // eax
  int v12; // edi
  _DWORD *v13; // eax
  _DWORD *v14; // ebx
  _DWORD *v15; // eax
  int v16; // [esp-8h] [ebp-328h]
  int v17; // [esp-4h] [ebp-324h]
  char Buffer[765]; // [esp+10h] [ebp-310h] BYREF
  __int16 v19; // [esp+30Dh] [ebp-13h]
  char v20; // [esp+30Fh] [ebp-11h]
  int v21; // [esp+31Ch] [ebp-4h]

  v2 = ArgList;
  if ( !ArgList || !*ArgList )
  {
    sub_5D8C80(this, (char *)0xFFFFFFFF, "Invalid MAS file name for %s", (char)ArgList);
    return -1;
  }
  v4 = this + 20 - (_DWORD)ArgList;
  do
  {
    v5 = *v2;
    v2[v4] = *v2;
    ++v2;
  }
  while ( v5 );
  _strupr((char *)(this + 20));
  v6 = fopen((const char *)(this + 20), "rb");
  *(_DWORD *)(this + 16) = v6;
  if ( !v6 )
  {
    memset(Buffer, 0, sizeof(Buffer));
    v19 = 0;
    v20 = 0;
    if ( !byte_910EFC )
      goto LABEL_15;
    dword_FB2874 = (int)dword_FB286C;
    if ( !dword_FB286C )
      goto LABEL_15;
    v7 = *(_DWORD *)dword_FB286C;
    if ( !*(_DWORD *)dword_FB286C )
      goto LABEL_15;
    while ( 1 )
    {
      sprintf(Buffer, "%s\\%s", (const char *)(v7 + 4), (const char *)(this + 20));
      v8 = fopen(Buffer, "rb");
      *(_DWORD *)(this + 16) = v8;
      if ( v8 )
        break;
      if ( dword_FB2874 )
      {
        dword_FB2874 = *(_DWORD *)(dword_FB2874 + 4);
        if ( dword_FB2874 )
        {
          v7 = *(_DWORD *)dword_FB2874;
          if ( *(_DWORD *)dword_FB2874 )
            continue;
        }
      }
      goto LABEL_15;
    }
    if ( !v7 )
    {
LABEL_15:
      dword_FB27CC = (int)dword_FB27C4;
      if ( !dword_FB27C4 )
        goto LABEL_23;
      v9 = *(_DWORD *)dword_FB27C4;
      if ( !*(_DWORD *)dword_FB27C4 )
        goto LABEL_23;
      while ( 1 )
      {
        sprintf(Buffer, "%s\\%s", (const char *)(v9 + 4), (const char *)(this + 20));
        v10 = fopen(Buffer, "rb");
        *(_DWORD *)(this + 16) = v10;
        if ( v10 )
          break;
        if ( dword_FB27CC )
        {
          dword_FB27CC = *(_DWORD *)(dword_FB27CC + 4);
          if ( dword_FB27CC )
          {
            v9 = *(_DWORD *)dword_FB27CC;
            if ( *(_DWORD *)dword_FB27CC )
              continue;
          }
        }
        goto LABEL_23;
      }
      if ( !v9 )
      {
LABEL_23:
        sub_5D8C80(this, (char *)0xFFFFFFFE, "Could not locate MAS file %s", (char)ArgList);
        return -2;
      }
    }
  }
  sub_6318A2(this + 4, 1, 12, *(_DWORD *)(this + 16));
  if ( strcmp((const char *)(this + 4), "GMOTORMAS10") )
  {
    fclose(*(FILE **)(this + 16));
    sub_5D8C80(this, (char *)0xFFFFFFFF, "Wrong MAS file version for %s", (char)ArgList);
    return -1;
  }
  sub_6318A2(this, 1, 4, *(_DWORD *)(this + 16));
  sub_6318A2(this + 276, 1, 4, *(_DWORD *)(this + 16));
  sub_6318A2(this + 284, 1, 4, *(_DWORD *)(this + 16));
  v12 = *(_DWORD *)(this + 276);
  *(_DWORD *)(this + 280) = v12 << 8;
  v13 = operator new((v12 << 8) + 4);
  v21 = 0;
  if ( v13 )
  {
    v14 = v13 + 1;
    *v13 = v12;
    sub_630A11(v13 + 1, 256, v12, sub_5EE300, nullsub_7);
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  v17 = *(_DWORD *)(this + 16);
  v16 = *(_DWORD *)(this + 280);
  *(_DWORD *)(this + 292) = v15;
  sub_6318A2(v15, 1, v16, v17);
  *(_DWORD *)(this + 280) += 24;
  return 0;
}
