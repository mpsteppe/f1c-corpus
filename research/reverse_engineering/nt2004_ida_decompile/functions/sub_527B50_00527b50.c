int sub_527B50()
{
  int v1; // eax
  int v2; // eax
  char v3; // cl
  const char *v4; // esi
  int v5; // eax
  char v6; // cl
  int v7; // edi
  int i; // esi
  int v9; // esi
  int v10; // edi
  int v11; // [esp+Ch] [ebp-568h] BYREF
  int v12; // [esp+10h] [ebp-564h] BYREF
  int v13; // [esp+14h] [ebp-560h] BYREF
  int nWidth; // [esp+18h] [ebp-55Ch] BYREF
  int nHeight; // [esp+1Ch] [ebp-558h] BYREF
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+20h] [ebp-554h] BYREF
  struct _STARTUPINFOA StartupInfo; // [esp+30h] [ebp-544h] BYREF
  CHAR Filename[256]; // [esp+74h] [ebp-500h] BYREF
  CHAR CommandLine[1024]; // [esp+174h] [ebp-400h] BYREF

  if ( sub_500F90(&unk_7D7920, 2, aDDevNascar2004_26, 1012) )
    sub_500FE0((int)&unk_7D7920, aEnteredVidmanE);
  sub_57B610(1);
  if ( sub_592F60(0, 0, 0) )
    return 1;
  v1 = sub_5A4750(dword_62A138);
  if ( v1 )
  {
    sub_5A47A0(v1 + 8, Filename);
  }
  else
  {
    v2 = 0;
    do
    {
      v3 = byte_615438[v2];
      Filename[v2++] = v3;
    }
    while ( v3 );
  }
  v4 = (const char *)dword_62A128;
  if ( !dword_62A128 )
    v4 = &byte_629120;
  if ( strcmp(Filename, v4) )
  {
    GetModuleFileNameA(0, Filename, 0x100u);
    v5 = 0;
    memset(&StartupInfo, 0, sizeof(StartupInfo));
    StartupInfo.cb = 68;
    do
    {
      v6 = byte_615428[v5];
      CommandLine[v5++] = v6;
    }
    while ( v6 );
    strcat(CommandLine, Filename);
    CreateProcessA(0, CommandLine, 0, 0, 0, 0x20u, 0, 0, &StartupInfo, &ProcessInformation);
    return 1;
  }
  if ( sub_4634F0(dword_764D70) )
  {
    sub_526AA0(dword_62A138);
    byte_62A154 = 1;
    sub_5B40B0((int)&unk_7E6B48, 0, 0, (int)&v12);
    v7 = sub_526AD0();
    for ( i = 0; i < v7; ++i )
    {
      sub_526AF0(i, &nWidth, &nHeight, &v11, &v13);
      if ( v11 == v12 )
        break;
    }
    if ( i == v7 )
    {
      if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_26, 1092) )
        sub_500FE0((int)&unk_7D7920, aCouldnTSetAnAp);
      return 1;
    }
  }
  else
  {
    sub_526AA0(dword_62A138);
    sub_526AF0(dword_62A13C, &nWidth, &nHeight, &v11, &v13);
    if ( byte_62A154 )
    {
      sub_5B40B0((int)&unk_7E6B48, 0, 0, (int)&v12);
      if ( v12 != v11 )
        byte_62A154 = 0;
    }
  }
  v9 = nHeight;
  v10 = nWidth;
  if ( !sub_4BB1A0(nWidth, nHeight, (unsigned __int8)byte_62A154) )
  {
    sub_591D70(hWndParent, hWndParent, hinst);
    sub_5A7A40(dword_62A164);
    sub_526D20(v10, v9, v11, v13);
    if ( sub_526C10(dword_7DA998) )
      return 1;
    sub_5278E0();
    sub_5A0010(0.0, 0.0, 1.0, 1.0, 0);
    sub_5A98C0(0);
    sub_5A0010(0.0, 0.0, 1.0, 1.0, 0);
    sub_527910();
    sub_4AAE70();
  }
  return 0;
}
