// f1c  0x0058b9ff  size=55
BOOL __cdecl sub_58B9FF(int RootPathName)
{
  BOOL result; // eax

  result = 1;
  if ( RootPathName )
  {
    LOBYTE(RootPathName) = RootPathName + 64;
    strcpy((char *)&RootPathName + 1, ":\\");
    if ( GetDriveTypeA((LPCSTR)&RootPathName) < 2 )
      return 0;
  }
  return result;
}
