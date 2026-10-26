int __fastcall sub_5BB5D0(int a1, int a2)
{
  int result; // eax

  *(_DWORD *)(a2 + 2048) = 1;
  *(_BYTE *)a2 = 92;
  sub_5BB620(0);
  sub_5BB620(1);
  sub_5BB620(2);
  sub_5BABA0(a2, aFinalQueryid11);
  result = *(_DWORD *)(a2 + 2048) - 1;
  *(_DWORD *)(a2 + 2048) = result;
  return result;
}
