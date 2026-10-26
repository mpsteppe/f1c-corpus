int __cdecl sub_648560(int a1, char *lpBuffer, unsigned int a3)
{
  int v3; // eax
  DWORD NumberOfBytesWritten; // [esp+0h] [ebp-4h] BYREF

  v3 = sub_67A0AC(a1);
  NumberOfBytesWritten = 0;
  return sub_6462BB(v3, lpBuffer, a3, &NumberOfBytesWritten);
}
