char __thiscall sub_59E2C0(int **this, int a2)
{
  int *v3; // eax
  int **v4; // esi
  DWORD v5; // eax
  int **v6; // edi
  int *v7; // eax
  bool v8; // zf
  int v9; // esi
  int *v10; // eax
  int *v11; // eax
  int **v13; // [esp+10h] [ebp-14h]

  v3 = this[708];
  v4 = this + 704;
  v13 = this + 704;
  if ( v3 && ((v5 = WaitForSingleObject(v3, (DWORD)this[709])) == 0 || v5 == 128) )
    v6 = v4;
  else
    v6 = 0;
  htonl(0);
  htons(0);
  *(_DWORD *)(a2 + 304) = this[681];
  v7 = *v6;
  v8 = *v6 == 0;
  v6[2] = *v6;
  if ( v8 )
    goto LABEL_14;
  v9 = *v7;
  if ( !*v7 )
  {
LABEL_13:
    v4 = v13;
LABEL_14:
    sub_5FDFB0(a2, 0);
    goto LABEL_15;
  }
  while ( *(_DWORD *)(a2 + 304) != *(_DWORD *)(v9 + 304) || *(_WORD *)(a2 + 300) != *(_WORD *)(v9 + 300) )
  {
    v10 = v6[2];
    if ( v10 )
    {
      v11 = (int *)v10[1];
      v6[2] = v11;
      if ( v11 )
      {
        v9 = *v11;
        if ( *v11 )
          continue;
      }
    }
    goto LABEL_13;
  }
  sub_59C130(v9, a2);
  *(_WORD *)(v9 + 300) = *(_WORD *)(a2 + 300);
  *(_DWORD *)(v9 + 304) = *(_DWORD *)(a2 + 304);
  ((void (__thiscall *)(int **, int))(*this)[31])(this, a2);
  v4 = v13;
LABEL_15:
  if ( v4[4] )
    ReleaseMutex(v4[4]);
  return 1;
}
