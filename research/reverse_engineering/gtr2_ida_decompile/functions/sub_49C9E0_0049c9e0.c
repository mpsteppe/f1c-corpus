int sub_49C9E0()
{
  int v0; // eax
  char v1; // cl
  HKEY phkResult; // [esp+4h] [ebp-114h] BYREF
  HKEY hKey; // [esp+8h] [ebp-110h] BYREF
  DWORD Type; // [esp+Ch] [ebp-10Ch] BYREF
  DWORD cbData; // [esp+10h] [ebp-108h] BYREF
  int v7; // [esp+14h] [ebp-104h]
  BYTE Data; // [esp+18h] [ebp-100h] BYREF
  _BYTE v9[3]; // [esp+19h] [ebp-FFh] BYREF

  Type = strlen(byte_B6DC70);
  if ( !Type )
    return -1;
  if ( !(unsigned __int8)sub_48C640() )
  {
    sub_46AD90();
    sub_615860(byte_B6DC70);
    return 0;
  }
  if ( !(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 753) )
    return 0;
  if ( byte_B6CBC2 )
  {
    CINet::Logout((CINet *)dword_B6CBB0);
    byte_B6CBC2 = 0;
  }
  byte_B6CBC1 = 1;
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
    if ( RegQueryValueExA(hKey, "SerialNumber", 0, &Type, &Data, &cbData)
      || (v7 = &v9[strlen((const char *)&Data)] - v9) == 0 )
    {
      sub_4E1810("GTR_ONLINE_CDKEY", 0);
    }
    else
    {
      v0 = 0;
      do
      {
        v1 = v9[v0 - 1];
        byte_B6DFD0[v0++] = v1;
      }
      while ( v1 );
      sub_4E1810("GTR_ONLINE_LOGIN", 0);
    }
    RegCloseKey(hKey);
    return 0;
  }
}
