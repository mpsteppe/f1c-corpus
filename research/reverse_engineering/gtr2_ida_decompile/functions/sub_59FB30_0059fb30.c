char __thiscall sub_59FB30(char *this, int a2, int a3)
{
  void *v4; // eax
  char *v5; // ebx
  DWORD v6; // eax
  int *v7; // ecx
  void *v8; // eax
  void *v9; // eax
  void *v10; // edi
  char v12; // [esp+Fh] [ebp-5h]
  int v13; // [esp+10h] [ebp-4h]

  v4 = (void *)*((_DWORD *)this + 694);
  v5 = this + 2760;
  v12 = 0;
  v13 = -1;
  if ( v4 && ((v6 = WaitForSingleObject(v4, *((_DWORD *)this + 695))) == 0 || v6 == 128) )
    v7 = (int *)v5;
  else
    v7 = 0;
  sub_59F730(v7, a2, 1);
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 36) )
    {
      v8 = (void *)*((_DWORD *)this + 701);
      if ( v8 )
        WaitForSingleObject(v8, *((_DWORD *)this + 702));
      *(_DWORD *)(*(_DWORD *)(a2 + 36) + 28) = 0;
      if ( *((_DWORD *)this + 701) )
        ReleaseMutex(*((HANDLE *)this + 701));
      v12 = 1;
      v13 = sub_5A6E90(*(_DWORD *)(a2 + 36));
    }
    sub_59C700();
    v9 = (void *)*((_DWORD *)this + 770);
    if ( v9 )
      WaitForSingleObject(v9, *((_DWORD *)this + 771));
    sub_59EC10();
    v10 = (void *)*((_DWORD *)this + 770);
    if ( v10 )
      ReleaseMutex(v10);
  }
  if ( *((_DWORD *)v5 + 4) )
    ReleaseMutex(*((HANDLE *)v5 + 4));
  if ( v12 )
    (*(void (__thiscall **)(char *, int))(*(_DWORD *)this + 148))(this, v13);
  return 0;
}
