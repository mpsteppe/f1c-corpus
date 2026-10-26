int sub_5AE78A()
{
  _SYSTEM_INFO SystemInfo; // [esp+4h] [ebp-34h] BYREF
  BYTE Data[4]; // [esp+28h] [ebp-10h] BYREF
  DWORD Type; // [esp+2Ch] [ebp-Ch] BYREF
  DWORD cbData; // [esp+30h] [ebp-8h] BYREF
  HKEY phkResult; // [esp+34h] [ebp-4h] BYREF

  if ( !RegOpenKeyA(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Direct3D", &phkResult) )
  {
    cbData = 4;
    if ( !RegQueryValueExA(phkResult, "DisableMMX", 0, &Type, Data, &cbData) && Type == 4 && *(_DWORD *)Data )
    {
      RegCloseKey(phkResult);
      dword_904D48 = 0;
      return 0;
    }
    RegCloseKey(phkResult);
  }
  if ( dword_904D48 < 0 )
  {
    dword_904D48 = 0;
    GetSystemInfo(&SystemInfo);
    if ( !SystemInfo.wProcessorArchitecture && SystemInfo.wProcessorLevel >= 5u )
    {
      if ( sub_5AE762() )
      {
        _m_empty();
        dword_904D48 = 1;
      }
    }
  }
  return dword_904D48;
}
