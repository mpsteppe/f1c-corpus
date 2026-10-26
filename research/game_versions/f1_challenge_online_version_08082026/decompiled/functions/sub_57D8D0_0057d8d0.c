char __thiscall sub_57D8D0(_DWORD *this, unsigned int a2, _DWORD *a3)
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
  char *v15; // eax
  void *v16; // eax
  _DWORD *v17; // edi
  DWORD v18; // eax
  int **v19; // ebx
  int *v20; // eax
  int v21; // esi
  int v22; // edi
  int *v23; // ebp
  _DWORD *v24; // eax
  int v25; // eax
  int v26; // edi
  __int64 v27; // rax
  char *v28; // eax
  int *v29; // eax
  int *v30; // eax
  char v31; // [esp+13h] [ebp-631h]
  _DWORD *v32; // [esp+14h] [ebp-630h]
  _DWORD *v33; // [esp+14h] [ebp-630h]
  int **v34; // [esp+18h] [ebp-62Ch]
  int len; // [esp+1Ch] [ebp-628h]
  unsigned __int16 buf[770]; // [esp+40h] [ebp-604h] BYREF

  sub_57D5D0(a2, buf);
  len = buf[1] + buf[0] + 4;
  if ( a3 )
  {
    v4 = (void *)this[687];
    v5 = this + 683;
    v32 = v5;
    if ( v4 && ((v6 = WaitForSingleObject(v4, v5[5])) == 0 || v6 == 128) )
      v7 = (int **)v5;
    else
      v7 = 0;
    v8 = *v7;
    v9 = *v7 == 0;
    v7[2] = *v7;
    if ( v9 )
      goto LABEL_15;
    v10 = *v8;
    if ( !*v8 )
      goto LABEL_15;
    while ( (*(_DWORD *)(v10 + 4) != a3[1] || *(_WORD *)(v10 + 2) != HIWORD(*a3))
         && !(unsigned __int8)sub_57DB80(*a3, a3[1], a3[2], a3[3]) )
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
      goto LABEL_15;
    }
    v15 = sub_57B6B0((char *)v10);
    if ( send(*(_DWORD *)v15, (const char *)buf, len, 0) == len )
LABEL_15:
      v13 = 1;
    else
      v13 = 0;
    if ( v32[4] )
      ReleaseMutex((HANDLE)v32[4]);
    return v13;
  }
  else
  {
    v16 = (void *)this[687];
    v17 = this + 683;
    v33 = this + 683;
    if ( v16 && ((v18 = WaitForSingleObject(v16, this[688])) == 0 || v18 == 128) )
      v19 = (int **)(this + 683);
    else
      v19 = 0;
    v20 = *v19;
    v34 = v19;
    v19[2] = *v19;
    if ( v20 )
    {
      v21 = *v20;
      if ( *v20 )
      {
        do
        {
          v22 = 0;
          v31 = 0;
          v23 = *(int **)(a2 + 72);
          v24 = (_DWORD *)sub_57B0D0(v23, 0);
          if ( v24 )
          {
            do
            {
              if ( *(_DWORD *)(v21 + 4) == v24[1] && *(_WORD *)(v21 + 2) == HIWORD(*v24)
                || *(_DWORD *)(v21 + 20) == v24[1] && *(_WORD *)(v21 + 18) == HIWORD(*v24) )
              {
                v31 = 1;
              }
              v24 = (_DWORD *)sub_57B0D0(v23, ++v22);
            }
            while ( v24 );
            v19 = v34;
            if ( v31 )
              goto LABEL_38;
          }
          v25 = sub_57B2E0((_DWORD *)v21);
          if ( v25 )
          {
            v26 = *v23;
            v27 = sub_5871F0(v25);
            if ( (*(unsigned __int8 (__fastcall **)(int *, _DWORD, _DWORD))(v26 + 16))(v23, HIDWORD(v27), v27) )
            {
LABEL_38:
              v28 = sub_57B6B0((char *)v21);
              send(*(_DWORD *)v28, (const char *)buf, len, 0);
            }
          }
          v29 = v19[2];
          if ( !v29 )
            break;
          v30 = (int *)v29[1];
          v19[2] = v30;
          if ( !v30 )
            break;
          v21 = *v30;
        }
        while ( *v30 );
        v17 = v33;
      }
    }
    if ( v17[4] )
      ReleaseMutex((HANDLE)v17[4]);
    return 1;
  }
}
