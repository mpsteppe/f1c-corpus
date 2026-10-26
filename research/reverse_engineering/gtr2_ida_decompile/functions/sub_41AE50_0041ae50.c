char __stdcall sub_41AE50(char *a1)
{
  int Version; // eax
  _DWORD v3[64]; // [esp+8h] [ebp-1A0h] BYREF
  struct _OSVERSIONINFOA VersionInformation; // [esp+108h] [ebp-A0h] BYREF

  v3[1] = (char *)&loc_6E776B + 4;
  v3[0] = 1852534357;
  memset(&VersionInformation, 0, 0x9Cu);
  VersionInformation.dwOSVersionInfoSize = 156;
  if ( !GetVersionExA(&VersionInformation) )
  {
    VersionInformation.dwOSVersionInfoSize = 148;
    Version = GetVersionExA(&VersionInformation);
    if ( !Version )
      return Version;
  }
  if ( VersionInformation.dwPlatformId )
  {
    if ( VersionInformation.dwPlatformId != 1 )
    {
      LOBYTE(Version) = LOBYTE(VersionInformation.dwPlatformId) - 2;
      if ( VersionInformation.dwPlatformId == 2 )
      {
        LOBYTE(Version) = VersionInformation.dwMajorVersion;
        if ( VersionInformation.dwMajorVersion <= 4 )
          strcpy((char *)v3, "Windows NT");
        if ( VersionInformation.dwMajorVersion >= 5 )
        {
          if ( VersionInformation.dwMinorVersion )
          {
            LOBYTE(Version) = 0;
            strcpy((char *)v3, "Windows XP");
          }
          else
          {
            LOBYTE(Version) = 50;
            strcpy((char *)v3, "Windows 2000");
          }
        }
      }
      goto LABEL_20;
    }
    if ( VersionInformation.dwMajorVersion < 4 )
      goto LABEL_17;
    if ( VersionInformation.dwMinorVersion >= 0x5A )
    {
      LOBYTE(Version) = 111;
      strcpy((char *)v3, "Windows ME");
      goto LABEL_20;
    }
    if ( VersionInformation.dwMajorVersion > 4 || VersionInformation.dwMinorVersion )
    {
      LOBYTE(Version) = 57;
      strcpy((char *)v3, "Windows 98");
    }
    else
    {
LABEL_17:
      LOBYTE(Version) = 0;
      strcpy((char *)v3, "Windows 95");
    }
  }
  else
  {
    LOBYTE(Version) = 0;
    strcpy((char *)v3, "Microsoft Win32s");
  }
LABEL_20:
  if ( a1 )
    strcpy(a1, (const char *)v3);
  return Version;
}
