char __thiscall sub_5A0B40(int this, int optval)
{
  double v2; // st7
  int v3; // ebp
  SOCKET v4; // esi
  void *v5; // eax
  int v6; // ebx
  DWORD v7; // eax
  int v8; // edi
  int *v9; // eax
  bool v10; // zf
  int v11; // esi
  int v12; // eax
  int *v13; // eax
  char v16[4]; // [esp+14h] [ebp-4h] BYREF

  v2 = sub_5A3EA0(this);
  v3 = optval;
  *(float *)(optval + 48) = v2;
  *(float *)(v3 + 44) = v2;
  v4 = *(_DWORD *)(v3 + 32);
  optval = 1;
  setsockopt(v4, 6, 1, (const char *)&optval, 4);
  *(_DWORD *)v16 = 1;
  setsockopt(v4, 0xFFFF, 8, v16, 4);
  WSAAsyncSelect(v4, dword_FB22D0, 0x1A0Au, 63);
  v5 = *(void **)(this + 2776);
  v6 = this + 2760;
  optval = this + 2760;
  if ( v5 && ((v7 = WaitForSingleObject(v5, *(_DWORD *)(this + 2780))) == 0 || v7 == 128) )
    v8 = this + 2760;
  else
    v8 = 0;
  while ( 1 )
  {
    v9 = *(int **)v8;
    v10 = *(_DWORD *)v8 == 0;
    *(_DWORD *)(v8 + 8) = *(_DWORD *)v8;
    if ( v10 )
      break;
    v11 = *v9;
    if ( !*v9 )
      break;
    while ( !sub_59C230(v11, (_DWORD *)(v3 + 16)) )
    {
      v12 = *(_DWORD *)(v8 + 8);
      if ( v12 )
      {
        v13 = *(int **)(v12 + 4);
        *(_DWORD *)(v8 + 8) = v13;
        if ( v13 )
        {
          v11 = *v13;
          if ( *v13 )
            continue;
        }
      }
      v6 = optval;
      goto LABEL_13;
    }
    sub_59FB30((char *)this, v11, (int)"Duplicate connection");
    v6 = optval;
  }
LABEL_13:
  sub_5FDFB0(v3, 0);
  if ( *(_DWORD *)(v6 + 16) )
    ReleaseMutex(*(HANDLE *)(v6 + 16));
  return 0;
}
