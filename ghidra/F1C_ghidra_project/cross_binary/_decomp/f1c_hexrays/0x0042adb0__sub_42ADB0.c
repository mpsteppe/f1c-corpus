// f1c  0x0042adb0  size=28
char __thiscall sub_42ADB0(int this)
{
  char result; // al

  result = *(_BYTE *)(this + 17424);
  if ( !result )
  {
    *(_DWORD *)(this + 17444) = 0;
    *(_BYTE *)(this + 17908) = 1;
  }
  return result;
}
