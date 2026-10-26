char __stdcall sub_4B0940(const char *a1, int a2, int a3)
{
  _DWORD FileName[4]; // [esp+0h] [ebp-110h] BYREF
  char v5; // [esp+10h] [ebp-100h] BYREF

  if ( strcmp(off_759F1C[0], a1) )
    return 0;
  FileName[3] = 0;
  FileName[2] = 256;
  FileName[1] = &v5;
  FileName[0] = a2;
  sub_4ABA50();
  if ( !(unsigned __int8)sub_617680((char *)FileName) )
    return 0;
  sub_437830();
  sub_437C50();
  return 1;
}
