int __thiscall sub_561600(_DWORD *this, int a2)
{
  int result; // eax
  HKEY phkResult; // [esp+4h] [ebp-110h] BYREF
  DWORD cbData; // [esp+8h] [ebp-10Ch] BYREF
  _BYTE v6[4]; // [esp+Ch] [ebp-108h] BYREF
  BYTE Data[260]; // [esp+10h] [ebp-104h] BYREF

  phkResult = 0;
  result = RegOpenKeyExA(
             HKEY_CURRENT_USER,
             "Software\\NaturalPoint\\NATURALPOINT\\NPClient Location",
             0,
             0x20019u,
             &phkResult);
  if ( !result )
  {
    if ( RegQueryValueExA(phkResult, "Path", 0, 0, 0, &cbData) )
    {
      return RegCloseKey(phkResult);
    }
    else
    {
      if ( !RegQueryValueExA(phkResult, "Path", 0, 0, Data, &cbData) )
        RegCloseKey(phkResult);
      *this = 0;
      this[1] = 0;
      result = sub_48B7B0((char *)Data);
      if ( !result )
      {
        result = sub_48B690(a2);
        if ( !result )
        {
          result = sub_48B6D0(3903);
          if ( !result )
          {
            result = sub_48B6F0((int)v6);
            if ( !result )
            {
              result = sub_48B710(119);
              if ( !result )
                return sub_48B770();
            }
          }
        }
      }
    }
  }
  return result;
}
