char __fastcall sub_4608F0(int a1, int a2)
{
  char result; // al

  result = *(_BYTE *)(a1 + 676);
  if ( !result )
  {
    *(_BYTE *)(a1 + 676) = 1;
    *(_DWORD *)(a1 + 748) = dword_761FF8;
    dword_761FF8 = 4;
    result = sub_4514A0((int)word_761D7C, a2, 1);
    *(_BYTE *)(a1 + 677) = 0;
  }
  return result;
}
