char __thiscall sub_57DE30(char *this, int a2, int a3)
{
  void *v4; // eax
  char *v5; // esi
  DWORD v6; // eax
  char *v7; // eax
  _DWORD *v8; // edi
  _DWORD *v9; // ecx
  int v10; // edx
  void *v11; // eax
  int v12; // eax
  char *v13; // eax
  void *v14; // eax
  void *v15; // edi
  char v17; // [esp+Fh] [ebp-5h]
  int v18; // [esp+10h] [ebp-4h]

  v18 = -1;
  v4 = (void *)*((_DWORD *)this + 687);
  v5 = this + 2732;
  v17 = 0;
  if ( v4 && ((v6 = WaitForSingleObject(v4, *((_DWORD *)this + 688))) == 0 || v6 == 128) )
    v7 = v5;
  else
    v7 = 0;
  if ( a2 )
  {
    v8 = *(_DWORD **)v7;
    v9 = 0;
    if ( *(_DWORD *)v7 )
    {
      while ( *v8 != a2 )
      {
        v9 = v8;
        v8 = (_DWORD *)v8[1];
        if ( !v8 )
          goto LABEL_19;
      }
      if ( v8 == *((_DWORD **)v7 + 2) )
        *((_DWORD *)v7 + 2) = v8[1];
      v10 = v8[1];
      if ( v9 )
        v9[1] = v10;
      else
        *(_DWORD *)v7 = v10;
      if ( *((_DWORD **)v7 + 1) == v8 )
        *((_DWORD *)v7 + 1) = v9;
      --*((_DWORD *)v7 + 3);
      sub_491E40((int)v8);
      sub_587BCF(v8);
    }
LABEL_19:
    if ( sub_57B2E0((_DWORD *)a2) )
    {
      v11 = (void *)*((_DWORD *)this + 694);
      if ( v11 )
        WaitForSingleObject(v11, *((_DWORD *)this + 695));
      *(_DWORD *)(sub_57B2E0((_DWORD *)a2) + 28) = 0;
      if ( *((_DWORD *)this + 694) )
        ReleaseMutex(*((HANDLE *)this + 694));
      v17 = 1;
      v12 = sub_57B2E0((_DWORD *)a2);
      v18 = sub_5871F0(v12);
    }
    v13 = sub_57B6B0((char *)a2);
    sub_57C8E0((SOCKET *)v13, 1);
    v14 = (void *)*((_DWORD *)this + 763);
    if ( v14 )
      WaitForSingleObject(v14, *((_DWORD *)this + 764));
    sub_57B530((_WORD *)(a2 + 54));
    *(_DWORD *)a2 = 0;
    *(_DWORD *)(a2 + 4) = 0;
    *(_DWORD *)(a2 + 8) = 0;
    *(_DWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 16) = 0;
    *(_DWORD *)(a2 + 20) = 0;
    *(_DWORD *)(a2 + 24) = 0;
    *(_DWORD *)(a2 + 28) = 0;
    *(_DWORD *)(a2 + 32) = -1;
    *(_DWORD *)(a2 + 36) = 0;
    *(_BYTE *)(a2 + 40) = 0;
    *(_DWORD *)(a2 + 44) = 0;
    *(_DWORD *)(a2 + 48) = 0;
    *(_WORD *)(a2 + 52) = 0;
    sub_583210(a2, 0);
    v15 = (void *)*((_DWORD *)this + 763);
    if ( v15 )
      ReleaseMutex(v15);
  }
  if ( *((_DWORD *)this + 687) )
    ReleaseMutex(*((HANDLE *)this + 687));
  if ( v17 )
    (*(void (__thiscall **)(char *, int))(*(_DWORD *)this + 148))(this, v18);
  return 0;
}
