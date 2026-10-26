// f1c  0x005904c1  size=54
BOOL sub_5904C1()
{
  struct _OSVERSIONINFOA VersionInformation; // [esp+0h] [ebp-94h] BYREF

  VersionInformation.dwOSVersionInfoSize = 148;
  return GetVersionExA(&VersionInformation) && VersionInformation.dwPlatformId == 2;
}
