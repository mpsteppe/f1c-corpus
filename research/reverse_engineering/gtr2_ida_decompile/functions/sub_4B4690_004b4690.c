int sub_4B4690()
{
  int v0; // eax
  char *v1; // eax
  int v2; // eax
  char v3; // cl
  const CHAR *v4; // eax
  const CHAR *v5; // eax
  HKEY phkResult; // [esp+14h] [ebp-50Ch] BYREF
  HKEY hKey; // [esp+1Ch] [ebp-504h] BYREF
  DWORD cbData; // [esp+20h] [ebp-500h] BYREF
  DWORD Type; // [esp+24h] [ebp-4FCh] BYREF
  int v11; // [esp+28h] [ebp-4F8h]
  BYTE Data; // [esp+2Ch] [ebp-4F4h] BYREF
  _BYTE v13[3]; // [esp+2Dh] [ebp-4F3h] BYREF
  _BYTE v14[4]; // [esp+124h] [ebp-3FCh] BYREF
  _BYTE v15[1016]; // [esp+128h] [ebp-3F8h] BYREF

  if ( dword_B6CBBC )
  {
    byte_B6CBC0 = 0;
    CINet::Logout((CINet *)dword_B6CBB0);
    dword_B6CBBC = 0;
  }
  if ( byte_B6CBC1 )
  {
    byte_B6CBC1 = 0;
    CINet::Logout((CINet *)dword_B6CBB0);
    byte_B6CBC2 = 0;
  }
  v0 = dword_B7231C;
  *(_DWORD *)dword_B72314 = 5;
  if ( dword_B7231C > 5 || (v0 = dword_B72320, dword_B72320 < 5) )
    *(_DWORD *)dword_B72314 = v0;
  v1 = (char *)dword_B7384C;
  byte_B6DC50[0] = 0;
  if ( !dword_B7384C )
    v1 = (char *)WindowName;
  CINet::SetServerName((CINet *)dword_B6CBB0, v1);
  CINet::SetDifficulty((CINet *)dword_B6CBB0, dword_B72338);
  if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB", &phkResult) )
    RegCloseKey(phkResult);
  if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2", &phkResult) )
    RegCloseKey(phkResult);
  if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", &phkResult) )
    RegCloseKey(phkResult);
  if ( RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", &hKey) )
  {
    sub_4E1810("GTR_ONLINE_CDKEY", 0);
  }
  else
  {
    cbData = 255;
    Type = 0;
    if ( RegQueryValueExA(hKey, "SerialNumber", 0, &Type, &Data, &cbData)
      || (v11 = &v13[strlen((const char *)&Data)] - v13) == 0 )
    {
      sub_4E1810("GTR_ONLINE_CDKEY", 0);
      RegCloseKey(hKey);
    }
    else
    {
      v2 = 0;
      do
      {
        v3 = v13[v2 - 1];
        byte_B6DFD0[v2++] = v3;
      }
      while ( v3 );
      sub_4E1810("GTR_ONLINE_LOGIN", 0);
      RegCloseKey(hKey);
    }
  }
  v4 = dword_B7235C;
  if ( !dword_B7235C )
    v4 = WindowName;
  sub_5100A0(&byte_B6F530, v4);
  sub_53B0D0(&unk_BE1CFC, v15, 1023);
  sub_53BDE0(&unk_BE1CE0, v14);
  v5 = (const CHAR *)dword_B6F724;
  if ( !dword_B6F724 )
    v5 = WindowName;
  sub_615860(v5);
  return -1;
}
