// f1c  0x004dc290  size=39
int sub_4DC290()
{
  int result; // eax

  result = sub_587C03(16);
  if ( !result )
    return 0;
  *(_DWORD *)(result + 4) = 4;
  *(_BYTE *)(result + 8) = 0;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)result = &off_5AD11C;
  return result;
}
