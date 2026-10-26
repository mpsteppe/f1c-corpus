char __thiscall sub_5A00C0(char *this)
{
  void *v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  DWORD v6; // eax
  int *v7; // ecx
  void *v8; // esi
  void *v9; // eax
  DWORD v10; // eax
  int *v11; // ecx
  void *v12; // esi
  void *v13; // eax
  DWORD v14; // eax
  int *v15; // ecx
  void *v16; // esi

  v2 = (void *)*((_DWORD *)this + 701);
  v3 = this + 2788;
  if ( v2 )
    WaitForSingleObject(v2, *((_DWORD *)this + 702));
  if ( *((_DWORD *)v3 + 4) )
    ReleaseMutex(*((HANDLE *)v3 + 4));
  v4 = (void *)*((_DWORD *)this + 708);
  if ( v4 )
    WaitForSingleObject(v4, *((_DWORD *)this + 709));
  if ( *((_DWORD *)this + 708) )
    ReleaseMutex(*((HANDLE *)this + 708));
  sub_59FF20();
  v5 = (void *)*((_DWORD *)v3 + 4);
  if ( v5 && ((v6 = WaitForSingleObject(v5, *((_DWORD *)v3 + 5))) == 0 || v6 == 128) )
    v7 = (int *)v3;
  else
    v7 = 0;
  sub_59EAD0(v7);
  v8 = (void *)*((_DWORD *)v3 + 4);
  if ( v8 )
    ReleaseMutex(v8);
  (*(void (__thiscall **)(char *))(*(_DWORD *)this + 48))(this);
  v9 = (void *)*((_DWORD *)this + 715);
  if ( v9 && ((v10 = WaitForSingleObject(v9, *((_DWORD *)this + 716))) == 0 || v10 == 128) )
    v11 = (int *)(this + 2844);
  else
    v11 = 0;
  v11[2] = *v11;
  sub_525140(v11);
  v12 = (void *)*((_DWORD *)this + 715);
  if ( v12 )
    ReleaseMutex(v12);
  v13 = (void *)*((_DWORD *)this + 722);
  if ( v13 && ((v14 = WaitForSingleObject(v13, *((_DWORD *)this + 723))) == 0 || v14 == 128) )
    v15 = (int *)(this + 2872);
  else
    v15 = 0;
  sub_525140(v15);
  v16 = (void *)*((_DWORD *)this + 722);
  if ( v16 )
    ReleaseMutex(v16);
  return 1;
}
