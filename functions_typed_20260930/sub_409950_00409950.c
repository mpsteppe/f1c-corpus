int sub_409950()
{
  int result; // eax

  result = GlobalFlagSetClear(32, 1);
  *(_DWORD *)(dword_8AFE88 + 236) &= ~0x8000u;
  return result;
}

