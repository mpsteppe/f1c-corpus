int sub_4FA000()
{
  int v1; // eax
  int v2; // eax
  char v3; // cl
  const char *v4; // esi
  int v5; // eax
  char v6; // cl
  int v7; // ebx
  int v8; // esi
  int v9; // edi
  int v10; // [esp+Ch] [ebp-564h] BYREF
  int v11; // [esp+10h] [ebp-560h] BYREF
  int nWidth; // [esp+14h] [ebp-55Ch] BYREF
  int nHeight; // [esp+18h] [ebp-558h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+1Ch] [ebp-554h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+2Ch] [ebp-544h] BYREF
  CHAR Filename[256]; // [esp+70h] [ebp-500h] BYREF
  CHAR CommandLine[1024]; // [esp+170h] [ebp-400h] BYREF

  if ( StringSplitLoop(dword_8AD25C, 2, (int)aDDevF119992002_26, 928) )
    DebugLogWrite((int)dword_8AD25C, (int)aEnteredVidmanE);
  QPCTimerInitialization(1);
  if ( SystemInitAllocatorWrapper(0, 0, 0) )
    return 1;
  v1 = IndexedArrayAccess_d890(dword_5EC488);
  if ( v1 )
  {
    sub_53D8E0(v1 + 8, Filename);
  }
  else
  {
    v2 = 0;
    do
    {
      v3 = byte_5D6E60[v2];
      Filename[v2++] = v3;
    }
    while ( v3 );
  }
  v4 = (const char *)dword_5EC480;
  if ( !dword_5EC480 )
    v4 = byte_5EA438;
  if ( !strcmp(Filename, v4) )
  {
    UtilityFunction_9160(dword_5EC488);
    GlobalGuardedFieldReader(dword_5EC48C, &nWidth, &nHeight, &v10, &v11);
    v7 = v10;
    if ( byte_5EC4A4 )
    {
      sub_55C330(0, 0, &v10);
      if ( v10 != v7 )
        byte_5EC4A4 = 0;
    }
    v8 = nHeight;
    v9 = nWidth;
    if ( !sub_4A1200(nWidth, nHeight, (unsigned __int8)byte_5EC4A4) )
    {
      ThreeGlobalSetter(hWnd, hWnd, hinst);
      GraphicsConfigStateSetter(dword_5EC4B4);
      sub_4F9420(v9, v8, v7, v11);
      if ( sub_4F9310(dword_8AFE74) )
        return 1;
      ConditionalInit();
      sub_5434A0(0.0, 0.0, 1.0, 1.0, 0);
      CallWrapper_c060(0);
      sub_5434A0(0.0, 0.0, 1.0, 1.0, 0);
      ConditionalStateReset();
      sub_494690();
    }
    return 0;
  }
  else
  {
    sub_422BE0((const CHAR **)dword_5EC3D0, 0);
    GetModuleFileNameA(0, Filename, 0x100u);
    v5 = 0;
    memset(&StartupInfo, 0, sizeof(StartupInfo));
    StartupInfo.cb = 68;
    do
    {
      v6 = byte_5D6E50[v5];
      CommandLine[v5++] = v6;
    }
    while ( v6 );
    strcat(CommandLine, Filename);
    CreateProcessA(0, CommandLine, 0, 0, 0, 0x20u, 0, 0, &StartupInfo, &ProcessInformation);
    return 1;
  }
}
