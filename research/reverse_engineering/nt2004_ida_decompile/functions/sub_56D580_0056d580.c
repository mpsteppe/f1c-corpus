char __thiscall sub_56D580(_DWORD *this, unsigned int a2, _DWORD *a3)
{
  void *v4; // eax
  _DWORD *v5; // esi
  DWORD v6; // eax
  int **v7; // edi
  int *v8; // eax
  bool v9; // zf
  int v10; // esi
  int *v11; // eax
  int *v12; // eax
  char v13; // bl
  void *v15; // eax
  _DWORD *v16; // ebp
  DWORD v17; // eax
  int **v18; // ebx
  int *v19; // eax
  int v20; // esi
  int v21; // edi
  int *v22; // ebp
  _DWORD *v23; // eax
  int v24; // eax
  int v25; // edi
  __int64 v26; // rax
  int *v27; // eax
  int *v28; // eax
  char v29; // [esp+13h] [ebp-635h]
  _DWORD *v30; // [esp+14h] [ebp-634h]
  int **v31; // [esp+1Ch] [ebp-62Ch]
  int len; // [esp+20h] [ebp-628h]
  unsigned __int16 v33[770]; // [esp+44h] [ebp-604h] BYREF

  sub_56D280(a2, v33);
  len = v33[1] + v33[0] + 4;
  if ( a3 )
  {
    v4 = (void *)this[687];
    v5 = this + 683;
    if ( v4 && ((v6 = WaitForSingleObject(v4, this[688])) == 0 || v6 == 128) )
      v7 = (int **)(this + 683);
    else
      v7 = 0;
    v8 = *v7;
    v9 = *v7 == 0;
    v7[2] = *v7;
    if ( !v9 )
    {
      v10 = *v8;
      if ( *v8 )
      {
        while ( (*(_DWORD *)(v10 + 4) != a3[1] || *(_WORD *)(v10 + 2) != HIWORD(*a3))
             && !(unsigned __int8)sub_56D830(*a3, a3[1], a3[2], a3[3]) )
        {
          v11 = v7[2];
          if ( v11 )
          {
            v12 = (int *)v11[1];
            v7[2] = v12;
            if ( v12 )
            {
              v10 = *v12;
              if ( *v12 )
                continue;
            }
          }
          v13 = 1;
          goto LABEL_21;
        }
        if ( sub_56D990(v10, (char *)v33, len) == len )
          goto LABEL_18;
        v13 = 0;
LABEL_21:
        v5 = this + 683;
        goto LABEL_22;
      }
LABEL_18:
      v5 = this + 683;
    }
    v13 = 1;
LABEL_22:
    if ( v5[4] )
      ReleaseMutex((HANDLE)v5[4]);
    return v13;
  }
  v15 = (void *)this[687];
  v16 = this + 683;
  v30 = v16;
  if ( v15 && ((v17 = WaitForSingleObject(v15, v16[5])) == 0 || v17 == 128) )
    v18 = (int **)v16;
  else
    v18 = 0;
  v19 = *v18;
  v31 = v18;
  v18[2] = *v18;
  if ( v19 )
  {
    v20 = *v19;
    if ( *v19 )
    {
      do
      {
        v21 = 0;
        v29 = 0;
        v22 = *(int **)(a2 + 72);
        v23 = (_DWORD *)sub_56AE00(v22, 0);
        if ( v23 )
        {
          do
          {
            if ( *(_DWORD *)(v20 + 4) == v23[1] && *(_WORD *)(v20 + 2) == HIWORD(*v23)
              || *(_DWORD *)(v20 + 20) == v23[1] && *(_WORD *)(v20 + 18) == HIWORD(*v23) )
            {
              v29 = 1;
            }
            v23 = (_DWORD *)sub_56AE00(v22, ++v21);
          }
          while ( v23 );
          v18 = v31;
          if ( v29 )
            goto LABEL_42;
        }
        v24 = sub_56B010((_DWORD *)v20);
        if ( v24 )
        {
          v25 = *v22;
          v26 = sub_577280(v24);
          if ( (*(unsigned __int8 (__fastcall **)(int *, _DWORD, _DWORD))(v25 + 16))(v22, HIDWORD(v26), v26) )
LABEL_42:
            sub_56D990(v20, (char *)v33, len);
        }
        v27 = v18[2];
        if ( !v27 )
          break;
        v28 = (int *)v27[1];
        v18[2] = v28;
        if ( !v28 )
          break;
        v20 = *v28;
      }
      while ( *v28 );
      v16 = v30;
    }
  }
  if ( v16[4] )
    ReleaseMutex((HANDLE)v16[4]);
  return 1;
}
