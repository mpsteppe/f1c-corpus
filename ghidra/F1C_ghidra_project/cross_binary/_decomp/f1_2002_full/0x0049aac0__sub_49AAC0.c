// f1_2002_full  0x0049aac0  size=21
int __fastcall sub_49AAC0(int a1, int a2, char a3)
{
  int result; // eax

  *(_BYTE *)(a1 + 16) = a3;
  result = a3 != 0 ? a1 : 0;
  dword_637898 = result;
  return result;
}
