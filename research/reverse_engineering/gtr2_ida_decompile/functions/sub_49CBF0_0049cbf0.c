int __thiscall sub_49CBF0(_DWORD *this)
{
  char *v1; // eax
  int v3; // eax
  char v4; // cl
  char *v6; // [esp+0h] [ebp-11Ch]
  HKEY phkResult; // [esp+8h] [ebp-114h] BYREF
  HKEY hKey; // [esp+Ch] [ebp-110h] BYREF
  DWORD cbData; // [esp+10h] [ebp-10Ch] BYREF
  DWORD Type; // [esp+14h] [ebp-108h] BYREF
  unsigned int v11; // [esp+18h] [ebp-104h]
  BYTE Data[256]; // [esp+1Ch] [ebp-100h] BYREF

  v1 = (char *)dword_B7384C;
  if ( !dword_B7384C )
    v1 = (char *)WindowName;
  CINet::SetServerName((CINet *)dword_B6CBB0, v1);
  CINet::SetDifficulty((CINet *)dword_B6CBB0, dword_B71F90);
  if ( byte_B6CBC3 || byte_B6CBC0 || byte_B6CBC2 )
  {
    v6 = sub_41D840(&byte_91CC38, "Please Wait...");
    sub_4EB900(off_16C9AFC, v6);
    sub_4DF020(this[12]);
    sub_4E1810("GARAGEONLINEPAGE", 0);
    return 0;
  }
  else
  {
    dword_B6CBBC = 1;
    if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB", &phkResult) )
      RegCloseKey(phkResult);
    if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2", &phkResult) )
      RegCloseKey(phkResult);
    if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", &phkResult) )
      RegCloseKey(phkResult);
    if ( RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", &hKey) )
    {
      sub_4E1810("GTR_ONLINE_CDKEY", 0);
      return 0;
    }
    else
    {
      cbData = 255;
      Type = 0;
      if ( RegQueryValueExA(hKey, "SerialNumber", 0, &Type, Data, &cbData) || (v11 = strlen((const char *)Data)) == 0 )
      {
        sub_4E1810("GTR_ONLINE_CDKEY", 0);
      }
      else
      {
        v3 = 0;
        do
        {
          v4 = Data[v3];
          byte_B6DFD0[v3++] = v4;
        }
        while ( v4 );
        sub_4E1810("GTR_ONLINE_LOGIN", 0);
      }
      RegCloseKey(hKey);
      return 0;
    }
  }
}
