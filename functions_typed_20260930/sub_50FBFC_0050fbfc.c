BOOL __cdecl sub_50FBFC(int a1, LPCSTR lpValueName, LPBYTE lpData, DWORD cbData)
{
  LSTATUS v4; // esi
  BOOL result; // eax
  DWORD Type; // [esp+0h] [ebp-8h] BYREF
  HKEY phkResult; // [esp+4h] [ebp-4h] BYREF

  phkResult = 0;
  result = 0;
  if ( !RegOpenKeyA(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Direct3D", &phkResult) )
  {
    v4 = RegQueryValueExA(phkResult, lpValueName, 0, &Type, lpData, &cbData);
    RegCloseKey(phkResult);
    if ( !v4 && Type == a1 )
      return 1;
  }
  return result;
}

