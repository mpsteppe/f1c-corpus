int sub_54CBF1()
{
  BYTE Data[4]; // [esp+4h] [ebp-10h] BYREF
  DWORD Type; // [esp+8h] [ebp-Ch] BYREF
  DWORD cbData; // [esp+Ch] [ebp-8h] BYREF
  HKEY phkResult; // [esp+10h] [ebp-4h] BYREF

  if ( !RegOpenKeyA(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Direct3D", &phkResult) )
  {
    cbData = 4;
    if ( !RegQueryValueExA(phkResult, "DisableMMX", 0, &Type, Data, &cbData) && Type == 4 && *(_DWORD *)Data )
    {
      RegCloseKey(phkResult);
      dword_617614 = 0;
      return 0;
    }
    RegCloseKey(phkResult);
  }
  if ( dword_617614 < 0 )
  {
    dword_617614 = 0;
    if ( sub_54CBCC() )
    {
      _m_empty();
      dword_617614 = 1;
    }
  }
  return dword_617614;
}
