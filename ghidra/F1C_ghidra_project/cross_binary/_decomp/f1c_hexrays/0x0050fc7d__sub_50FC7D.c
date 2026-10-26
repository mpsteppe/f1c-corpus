// f1c  0x0050fc7d  size=153
int sub_50FC7D()
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
      dword_5D7994 = 0;
      return 0;
    }
    RegCloseKey(phkResult);
  }
  if ( dword_5D7994 < 0 )
  {
    dword_5D7994 = 0;
    if ( sub_50FC58() )
    {
      _m_empty();
      dword_5D7994 = 1;
    }
  }
  return dword_5D7994;
}
