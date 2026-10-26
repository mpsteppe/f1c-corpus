// f1c  0x004119d0  size=48
int __stdcall sub_4119D0(int a1)
{
  int result; // eax

  result = -1;
  if ( a1 > 0 && a1 < 291 )
    return 0;
  if ( a1 > 292 && a1 < 536 )
    return 1;
  return result;
}
