_DWORD *__thiscall sub_430110(_DWORD *this)
{
  DWORD v2; // edi
  HKEY phkResult; // [esp+10h] [ebp-110h] BYREF
  HKEY hKey; // [esp+14h] [ebp-10Ch] BYREF
  DWORD cbData; // [esp+18h] [ebp-108h] BYREF
  DWORD Type; // [esp+1Ch] [ebp-104h] BYREF
  BYTE Data[256]; // [esp+20h] [ebp-100h] BYREF

  *this = 1;
  this[1] = 3;
  this[2] = 1;
  this[29] = 0;
  *((_BYTE *)this + 124) = 0;
  *((_BYTE *)this + 125) = 0;
  this[32] = 0;
  this[33] = 0;
  this[34] = -1;
  memset(this + 3, 0, 0x68u);
  if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB", &phkResult) )
    RegCloseKey(phkResult);
  if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2", &phkResult) )
    RegCloseKey(phkResult);
  if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", &phkResult) )
    RegCloseKey(phkResult);
  if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", &hKey) )
  {
    cbData = 255;
    Type = 0;
    if ( !RegQueryValueExA(hKey, "SerialNumber", 0, &Type, Data, &cbData) )
    {
      v2 = cbData;
      if ( cbData >= 0x1F )
        v2 = 31;
      sub_630FE0(byte_B6DFD0, Data, v2);
      byte_B6DFD0[v2] = 0;
    }
    RegCloseKey(hKey);
  }
  this[30] = 1;
  return this;
}
