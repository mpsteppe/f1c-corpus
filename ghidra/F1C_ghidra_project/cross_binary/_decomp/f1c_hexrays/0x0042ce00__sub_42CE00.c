// f1c  0x0042ce00  size=10
int *sub_42CE00()
{
  int *result; // eax

  result = &dword_7C569C;
  dword_7C569C = 1;
  dword_7C56A0 = 3;
  dword_7C56A4 = 1;
  dword_7C56A8 = 0;
  byte_7C56AC = 0;
  byte_7C56AD = 0;
  dword_7C56B0 = 0;
  dword_7C56B4 = 0;
  dword_7C56B8 = -1;
  return result;
}
