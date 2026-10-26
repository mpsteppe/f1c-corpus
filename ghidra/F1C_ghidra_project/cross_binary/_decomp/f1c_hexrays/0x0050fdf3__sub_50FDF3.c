// f1c  0x0050fdf3  size=180
int __cdecl sub_50FDF3(DWORD ProcessorFeature)
{
  char v1; // bl
  struct _OSVERSIONINFOA VersionInformation; // [esp+8h] [ebp-24h] BYREF
  char v4; // [esp+9Fh] [ebp+73h]

  memset(&VersionInformation, 0, sizeof(VersionInformation));
  v1 = 0;
  v4 = 0;
  VersionInformation.dwOSVersionInfoSize = 148;
  if ( !GetVersionExA(&VersionInformation) )
  {
    v1 = 1;
    v4 = 1;
  }
  if ( VersionInformation.dwPlatformId == 1 )
  {
    if ( VersionInformation.dwMajorVersion <= 4
      && (VersionInformation.dwMajorVersion != 4
       || VersionInformation.dwMinorVersion < 0xA
       || LOWORD(VersionInformation.dwBuildNumber) < 0x55Du) )
    {
      v4 = 1;
    }
    goto LABEL_11;
  }
  if ( VersionInformation.dwPlatformId != 2 )
    return 0;
  if ( v1 )
  {
LABEL_11:
    if ( ProcessorFeature != 6 )
    {
      if ( ProcessorFeature == 7 )
        return sub_50FD16();
      if ( ProcessorFeature != 10 || v4 )
        return 0;
      return sub_50FD4E((int)&VersionInformation.szCSDVersion[16]) & 8;
    }
    if ( !v4 )
      return sub_50FD4E((int)&VersionInformation.szCSDVersion[16]) & 4;
    return 0;
  }
  if ( ProcessorFeature != 10 )
    return IsProcessorFeaturePresent(ProcessorFeature);
  return sub_50FD4E((int)&VersionInformation.szCSDVersion[16]) & 8;
}
