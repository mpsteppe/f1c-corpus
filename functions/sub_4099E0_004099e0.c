int sub_4099E0()
{
  int result; // eax

  result = GlobalFlagSetClear(32, 0);
  *(_DWORD *)(dword_8AFE88 + 236) |= 0x8000u;
  return result;
}
