int __fastcall sub_4EDA10(int a1, int a2, char a3)
{
  int result; // eax

  *(_BYTE *)(a1 + 16) = a3;
  result = a3 != 0 ? a1 : 0;
  dword_B6F1C4 = result;
  return result;
}
