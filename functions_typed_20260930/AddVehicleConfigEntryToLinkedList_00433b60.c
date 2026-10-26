int __thiscall sub_433B60(_DWORD *this, int a2, int a3, char a4)
{
  int v4; // eax
  _DWORD *v5; // edi
  int v6; // ebx
  char *v7; // ecx
  char *v8; // eax
  int v9; // ebp
  char ***v10; // eax
  char **v11; // esi
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  int v15; // eax
  char ***v16; // eax
  _DWORD *v17; // esi
  char *v18; // ebp
  char *v20; // eax
  int v21; // eax
  int v23; // [esp+14h] [ebp-4h]
  int v24; // [esp+20h] [ebp+8h]

  v4 = a3;
  v5 = this;
  v6 = 1;
  if ( !a3 )
  {
    v7 = (char *)dword_7CE5EC;
    if ( !dword_7CE5EC )
      v7 = &byte_5EA438;
    v4 = SettingsFolderResolver(v7);
  }
  v24 = v4;
  v23 = IterationCountMap(dword_7C56A4);
  v8 = (char *)dword_7CE64C;
  if ( !dword_7CE64C )
    v8 = &byte_5EA438;
  v9 = ConditionalDispatch_40b0(v8);
  v10 = (char ***)v5[7];
  v5[9] = v10;
  if ( v10 && (v11 = *v10) != 0 )
  {
    while ( 1 )
    {
      v12 = *v11;
      if ( !*v11 )
        v12 = &byte_5EA438;
      if ( !sub_588410(v24, v12) )
      {
        v13 = v11[2];
        if ( !v13 )
          v13 = &byte_5EA438;
        if ( !*v13 || !v9 )
          break;
        v14 = v11[2];
        if ( !v14 )
          v14 = &byte_5EA438;
        if ( !sub_588410(v9 + 444, v14) )
          break;
      }
      v15 = v5[9];
      if ( v15 )
        v5[9] = *(_DWORD *)(v15 + 4);
      v16 = (char ***)v5[9];
      if ( v16 )
      {
        v11 = *v16;
        if ( *v16 )
          continue;
      }
      goto LABEL_23;
    }
    if ( !a4 )
      return 1;
    StringCopyWithBufferRealloc(a2);
    v20 = &byte_5EA438;
    if ( v9 )
      v20 = (char *)(v9 + 444);
    StringCopyWithBufferRealloc(v20);
    v6 = 0;
  }
  else
  {
LABEL_23:
    v17 = (_DWORD *)OperatorNewNhMallocWrapper(28);
    if ( v17 )
    {
      *v17 = 0;
      v17[1] = -1;
      v17[2] = 0;
      v17[3] = -1;
      v17[5] = 0;
      v17[6] = -1;
      SessionConfigDefaultInit(v17);
      if ( v9 )
        v18 = (char *)(v9 + 444);
      else
        v18 = &byte_5EA438;
      StringCopyWithBufferRealloc(v24);
      StringCopyWithBufferRealloc(v18);
      v17[4] = v23;
      StringCopyWithBufferRealloc(a2);
      v21 = OperatorNewNhMallocWrapper(12);
      v6 = 0;
      if ( v21 )
      {
        *(_DWORD *)v21 = v17;
        *(_DWORD *)(v21 + 4) = 0;
        *(_BYTE *)(v21 + 8) = 1;
      }
      else
      {
        v21 = 0;
      }
      if ( this[7] )
      {
        *(_DWORD *)(this[8] + 4) = v21;
      }
      else
      {
        this[7] = v21;
        this[9] = v21;
      }
      v5 = this;
      this[8] = v21;
      ++this[10];
    }
  }
  StringCopyWithBufferRealloc(a2);
  ConfigFileParser(v5, (int)&byte_7CE498);
  return v6;
}

