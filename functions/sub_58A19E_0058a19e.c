int sub_58A19E()
{
  DWORD Version; // eax
  int wShowWindow; // eax
  HMODULE ModuleHandleA; // eax
  int v4; // [esp-4h] [ebp-78h]
  int v5; // [esp+10h] [ebp-64h]
  UINT v6; // [esp+14h] [ebp-60h]
  struct _STARTUPINFOA StartupInfo; // [esp+18h] [ebp-5Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+5Ch] [ebp-18h]

  Version = GetVersion();
  dword_8D3E80 = BYTE1(Version);
  dword_8D3E7C = (unsigned __int8)Version;
  dword_8D3E78 = BYTE1(Version) + ((unsigned __int8)Version << 8);
  dword_8D3E74 = HIWORD(Version);
  if ( !sub_59325D(1) )
    ErrorHandlerWithOptionalCleanupThenExit(0x1Cu);
  if ( !TLSAllocationThreadIDInit() )
    ErrorHandlerWithOptionalCleanupThenExit(0x10u);
  ms_exc.registration.TryLevel = 0;
  sub_592F2C();
  dword_8D5A44 = (int)GetCommandLineA();
  dword_8D3EB4 = (LPVOID)sub_592DFA();
  sub_592BAD();
  sub_592AF4();
  sub_589C77();
  StartupInfo.dwFlags = 0;
  GetStartupInfoA(&StartupInfo);
  v5 = sub_592A9C();
  if ( (StartupInfo.dwFlags & 1) != 0 )
    wShowWindow = StartupInfo.wShowWindow;
  else
    wShowWindow = 10;
  v4 = wShowWindow;
  ModuleHandleA = GetModuleHandleA(0);
  v6 = GameMainEntry(ModuleHandleA, 0, v5, v4);
  UtilityFunction_9ca4(v6);
  return sub_592924(ms_exc.exc_ptr->ExceptionRecord->ExceptionCode, ms_exc.exc_ptr);
}
