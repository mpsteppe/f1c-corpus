char __thiscall SceneLoadAndNameMatch(_DWORD *this)
{
  int *v2; // esi
  int v3; // eax
  char *v4; // eax
  int v5; // ebx
  int v6; // edi
  int v7; // edx
  int v8; // ecx
  char **v9; // ecx
  char *v10; // esi
  char *v11; // ecx
  bool v12; // cf
  int v13; // ecx
  char *v15; // [esp+10h] [ebp-4h]

  v2 = (int *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 3);
  v3 = GuardedAccessor(v2);
  v4 = FilenameFromLinkedList((int)v2, v3);
  v5 = this[62];
  v6 = 0;
  v15 = v4;
  if ( v5 > 0 )
  {
    while ( 1 )
    {
      v7 = v6;
      if ( v6 < 0 || v6 >= this[61] )
        goto LABEL_8;
      v8 = this[58];
      if ( v6 > 0 )
        break;
LABEL_7:
      if ( !v8 )
        goto LABEL_8;
      v9 = *(char ***)v8;
LABEL_10:
      v10 = *v9;
      if ( !*v9 )
        v10 = byte_5EA438;
      v11 = v15;
      while ( 1 )
      {
        LOBYTE(v4) = *v11;
        v12 = (unsigned __int8)*v11 < (unsigned __int8)*v10;
        if ( *v11 != *v10 )
          break;
        if ( !*v11 )
          goto LABEL_17;
        LOBYTE(v4) = v11[1];
        v12 = (unsigned __int8)v4 < (unsigned __int8)v10[1];
        if ( (_BYTE)v4 != v10[1] )
          break;
        v11 += 2;
        v10 += 2;
        if ( !(_BYTE)v4 )
        {
LABEL_17:
          v13 = 0;
          goto LABEL_19;
        }
      }
      v13 = -v12 - (v12 - 1);
LABEL_19:
      if ( !v13 )
        this[63] = v6;
      if ( ++v6 >= v5 )
        return (char)v4;
    }
    while ( v8 )
    {
      v8 = *(_DWORD *)(v8 + 4);
      if ( --v7 <= 0 )
        goto LABEL_7;
    }
LABEL_8:
    v9 = 0;
    goto LABEL_10;
  }
  return (char)v4;
}
