// f1c  0x004b21c0  size=10
int *sub_4B21C0()
{
  int *result; // eax

  result = &dword_83EE60;
  dword_8AAE6C = (int)&unk_83EE64;
  dword_8AAE68 = (int)&unk_83EE64;
  dword_8AAE64 = (int)&unk_83EE64;
  dword_83EE60 = 0;
  return result;
}
