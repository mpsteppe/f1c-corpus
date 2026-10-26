BOOL __stdcall sub_5AE703(BYTE *a1, LPCSTR lpValueName, BYTE *Type, DWORD cbData)
{
  LSTATUS v4; // esi
  BOOL result; // eax
  HKEY phkResult; // [esp+0h] [ebp-4h] BYREF

  phkResult = 0;
  result = 0;
  if ( !RegOpenKeyA(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Direct3D", &phkResult) )
  {
    v4 = RegQueryValueExA(phkResult, lpValueName, 0, (LPDWORD)&Type, Type, &cbData);
    RegCloseKey(phkResult);
    if ( !v4 && Type == a1 )
      return 1;
  }
  return result;
}
