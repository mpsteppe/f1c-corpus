int __thiscall sub_57FC80(char *lpParameter)
{
  void *v3; // eax
  _DWORD *v4; // ebx
  DWORD v5; // eax
  _DWORD *v6; // edi
  _DWORD *v7; // ebp
  void *v8; // eax
  DWORD v9; // eax
  _DWORD *v10; // eax
  void *v11; // edi
  SOCKET v12; // eax
  SOCKET v13; // ecx
  int v14; // [esp+4h] [ebp-4h]

  (*(void (__thiscall **)(char *))(*(_DWORD *)lpParameter + 76))(lpParameter);
  v14 = 6;
  *((_DWORD *)lpParameter + 590) = -1;
  *((_DWORD *)lpParameter + 591) = -1;
  lpParameter[2677] = 0;
  if ( !WinsockInit((int)lpParameter) )
    return 6;
  v3 = (void *)*((_DWORD *)lpParameter + 694);
  v4 = lpParameter + 2760;
  if ( !v3 || (v5 = WaitForSingleObject(v3, *((_DWORD *)lpParameter + 695))) != 0 && v5 != 128 )
    v4 = 0;
  v6 = (_DWORD *)*v4;
  if ( *v4 )
  {
    do
    {
      v7 = v6;
      v6 = (_DWORD *)v6[1];
      if ( *((_BYTE *)v7 + 8) && *v7 )
        (**(void (__thiscall ***)(_DWORD, int))*v7)(*v7, 1);
      FreeWrapper_7bcf(v7);
    }
    while ( v6 );
  }
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  if ( *((_DWORD *)lpParameter + 694) )
    ReleaseMutex(*((HANDLE *)lpParameter + 694));
  v8 = (void *)*((_DWORD *)lpParameter + 719);
  if ( v8 && ((v9 = WaitForSingleObject(v8, *((_DWORD *)lpParameter + 720))) == 0 || v9 == 128) )
    v10 = lpParameter + 2872;
  else
    v10 = 0;
  *v10 = 1;
  v11 = (void *)*((_DWORD *)lpParameter + 719);
  if ( v11 )
    ReleaseMutex(v11);
  *((_DWORD *)lpParameter + 591) = socket(2, 2, 0);
  v12 = socket(2, 1, 0);
  v13 = *((_DWORD *)lpParameter + 591);
  *((_DWORD *)lpParameter + 590) = v12;
  if ( v13 != -1 && v12 != -1 && TCPSocketInit(v13, 0) )
  {
    if ( TCPSocketInit(*((_DWORD *)lpParameter + 590), 1) )
    {
      lpParameter[2677] = 1;
      v14 = 0;
    }
  }
  sub_585470(lpParameter);
  return v14;
}

