int __fastcall sub_4A1DA0(int a1, int a2, char a3)
{
  int result; // eax

  *(_BYTE *)(a1 + 16) = a3;
  result = a3 != 0 ? a1 : 0;
  dword_7CE2E8 = result;
  return result;
}

