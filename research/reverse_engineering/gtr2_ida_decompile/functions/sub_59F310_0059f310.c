int __thiscall sub_59F310(char *lpParameter)
{
  char v2; // al
  void *v4; // eax
  DWORD v5; // eax
  int *v6; // ecx
  void *v7; // edi
  void *v8; // eax
  DWORD v9; // eax
  _DWORD *v10; // ebx
  int v11; // eax
  char v12; // cl
  char *v13; // edi
  FILE *v15; // eax
  SOCKET v16; // eax
  SOCKET v17; // edi
  char optval[4]; // [esp+14h] [ebp-204h] BYREF
  char FileName[252]; // [esp+18h] [ebp-200h] BYREF
  __int16 v20; // [esp+114h] [ebp-104h]
  char v21; // [esp+116h] [ebp-102h]
  CHAR Filename[256]; // [esp+118h] [ebp-100h] BYREF

  (*(void (__thiscall **)(char *))(*(_DWORD *)lpParameter + 76))(lpParameter);
  *((_DWORD *)lpParameter + 597) = -1;
  *((_DWORD *)lpParameter + 598) = -1;
  v2 = lpParameter[2704];
  lpParameter[2705] = 0;
  if ( !v2 )
    return 6;
  v4 = (void *)*((_DWORD *)lpParameter + 701);
  if ( v4 && ((v5 = WaitForSingleObject(v4, *((_DWORD *)lpParameter + 702))) == 0 || v5 == 128) )
    v6 = (int *)(lpParameter + 2788);
  else
    v6 = 0;
  sub_59EAD0(v6);
  v7 = (void *)*((_DWORD *)lpParameter + 701);
  if ( v7 )
    ReleaseMutex(v7);
  v8 = (void *)*((_DWORD *)lpParameter + 726);
  if ( v8 && ((v9 = WaitForSingleObject(v8, *((_DWORD *)lpParameter + 727))) == 0 || v9 == 128) )
    v10 = lpParameter + 2900;
  else
    v10 = 0;
  *v10 = 1;
  if ( GetModuleFileNameA(0, Filename, 0x100u) )
  {
    memset(FileName, 0, sizeof(FileName));
    v20 = 0;
    v21 = 0;
    v11 = 0;
    do
    {
      v12 = Filename[v11];
      FileName[v11++] = v12;
    }
    while ( v12 );
    v13 = &optval[3];
    while ( *++v13 )
      ;
    *(_DWORD *)v13 = 1146048046;
    *((_DWORD *)v13 + 1) = sub_444945;
    v15 = fopen(FileName, "rb");
    if ( v15 )
    {
      fclose(v15);
      *v10 = 20000;
    }
  }
  if ( *((_DWORD *)lpParameter + 726) )
    ReleaseMutex(*((HANDLE *)lpParameter + 726));
  *((_DWORD *)lpParameter + 598) = socket(2, 2, 0);
  v16 = socket(2, 1, 0);
  v17 = *((_DWORD *)lpParameter + 598);
  *((_DWORD *)lpParameter + 597) = v16;
  if ( v17 == -1
    || v16 == -1
    || (*(_DWORD *)optval = 1,
        setsockopt(v17, 0xFFFF, 32, optval, 4),
        WSAAsyncSelect(v17, dword_FB22D0, 0x1A0Au, 63),
        !sub_59BEA0(*((_DWORD *)lpParameter + 597), 1)) )
  {
    sub_5A6260(lpParameter);
    return 6;
  }
  else
  {
    lpParameter[2705] = 1;
    sub_5A6260(lpParameter);
    return 0;
  }
}
