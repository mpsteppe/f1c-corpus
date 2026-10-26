// f1c  0x0052da10  size=31
int __thiscall sub_52DA10(int this)
{
  int v2; // ecx
  int result; // eax

  v2 = 576;
  if ( !dword_8B0108 )
    v2 = 1152;
  result = 0;
  memset((void *)(this + 4), 0, 4 * v2);
  return result;
}
