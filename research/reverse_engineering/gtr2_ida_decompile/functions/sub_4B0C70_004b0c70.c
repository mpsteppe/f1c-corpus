bool __stdcall sub_4B0C70(const char *a1, int a2, int a3)
{
  bool result; // al
  _DWORD FileName[4]; // [esp+0h] [ebp-110h] BYREF
  char v5; // [esp+10h] [ebp-100h] BYREF

  result = 0;
  if ( !strcmp(off_759F1C[0], a1) )
  {
    FileName[3] = 0;
    FileName[2] = 256;
    FileName[1] = &v5;
    FileName[0] = a2;
    sub_4ABBB0();
    if ( (unsigned __int8)sub_617680((char *)FileName) )
      return 1;
  }
  return result;
}
