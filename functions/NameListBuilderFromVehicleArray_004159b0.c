int __thiscall sub_4159B0(_DWORD *this)
{
  int v1; // ebp
  char ***v2; // edi
  int v3; // ebx
  _BYTE *v4; // ebx
  char ***v5; // esi
  char **v6; // eax
  char *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  int v10; // eax
  bool v11; // zf
  int v12; // esi
  const char **v13; // esi
  const char **v14; // ebx
  int v15; // ecx
  char ***v16; // eax
  char **v17; // eax
  char *v18; // eax
  int v19; // edi
  int v20; // ebp
  int v21; // esi
  int v22; // eax
  char ***v23; // esi
  int v25; // [esp+10h] [ebp-20h]
  int v26; // [esp+10h] [ebp-20h]
  int v27; // [esp+14h] [ebp-1Ch]
  int v28; // [esp+18h] [ebp-18h]
  char ***v30; // [esp+20h] [ebp-10h]
  int v31; // [esp+24h] [ebp-Ch]
  int v32; // [esp+2Ch] [ebp-4h]

  v1 = 0;
  v2 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v28 = dword_8AC390;
  if ( dword_8AC390 > 0 )
  {
    v3 = 0;
    v25 = 0;
    v27 = dword_8AC390;
    do
    {
      v4 = (_BYTE *)(v3 + dword_8AC394 + 124);
      if ( *v4 )
      {
        v5 = v2;
        if ( v2 && (v6 = *v2) != 0 )
        {
          while ( 1 )
          {
            v7 = *v6;
            if ( !v7 )
              v7 = &byte_5EA438;
            if ( !sub_588410(v4, v7) )
              break;
            v5 = (char ***)v5[1];
            if ( v5 )
            {
              v6 = *v5;
              if ( *v5 )
                continue;
            }
            goto LABEL_11;
          }
        }
        else
        {
LABEL_11:
          v8 = (_DWORD *)OperatorNewNhMallocWrapper(8);
          v9 = v8;
          if ( v8 )
          {
            *v8 = 0;
            v8[1] = -1;
            StringCopyWithBufferRealloc(v4);
            v10 = OperatorNewNhMallocWrapper(12);
            if ( v10 )
            {
              *(_DWORD *)v10 = v9;
              *(_DWORD *)(v10 + 4) = 0;
              *(_BYTE *)(v10 + 8) = 1;
            }
            else
            {
              v10 = 0;
            }
            if ( v2 )
            {
              *(_DWORD *)(v31 + 4) = v10;
            }
            else
            {
              v30 = (char ***)v10;
              v2 = (char ***)v10;
            }
            v31 = v10;
            ++v32;
          }
        }
      }
      v3 = v25 + 1060;
      v11 = v27 == 1;
      v25 += 1060;
      --v27;
    }
    while ( !v11 );
  }
  v12 = this[4];
  while ( v12 )
  {
    v12 = *(_DWORD *)(v12 + 4);
    MemoryAllocation_8c10(1);
  }
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  if ( v32 > 0 )
  {
    v26 = 0;
    do
    {
      v13 = (const char **)OperatorNewNhMallocWrapper(172);
      if ( v13 )
      {
        *v13 = 0;
        v13[1] = (const char *)-1;
        sub_401000((int)(v13 + 3), 20, 2, (int (__thiscall *)(int))SmallEntryStructInit);
        sub_401000((int)(v13 + 13), 20, 2, (int (__thiscall *)(int))SmallEntryStructInit);
        sub_401000((int)(v13 + 23), 20, 2, (int (__thiscall *)(int))SmallEntryStructInit);
        sub_401000((int)(v13 + 33), 20, 2, (int (__thiscall *)(int))SmallEntryStructInit);
        TextFormatStructInitializer_4d70((int)v13);
        v14 = v13;
      }
      else
      {
        v14 = 0;
      }
      v15 = v1;
      if ( v1 >= 0 && v1 < v32 )
      {
        v16 = v2;
        if ( v1 <= 0 )
        {
LABEL_32:
          if ( v16 )
          {
            v17 = *v16;
            goto LABEL_35;
          }
        }
        else
        {
          while ( v16 )
          {
            v16 = (char ***)v16[1];
            if ( --v15 <= 0 )
              goto LABEL_32;
          }
        }
      }
      v17 = 0;
LABEL_35:
      v18 = *v17;
      if ( !v18 )
        v18 = &byte_5EA438;
      StringCopyWithBufferRealloc(v18);
      v19 = 0;
      if ( v28 > 0 )
      {
        v20 = 0;
        while ( 1 )
        {
          v21 = dword_8AC394 + v20;
          v22 = NullSafePointerDereference(v14);
          if ( !sub_588410(v21 + 124, v22) )
            break;
          ++v19;
          v20 += 1060;
          if ( v19 >= v28 )
            goto LABEL_43;
        }
        v14[2] = (const char *)v19;
LABEL_43:
        v1 = v26;
      }
      sub_414A90(v14);
      DoublyLinkedListAppend(v14, 1);
      v2 = v30;
      v26 = ++v1;
    }
    while ( v1 < v32 );
  }
  v23 = v2;
  while ( v23 )
  {
    v23 = (char ***)v23[1];
    DestructorWithDoubleFreePattern(1);
  }
  return 0;
}
