int __fastcall sub_4336D0(int a1, int a2, int a3)
{
  int result; // eax

  result = sub_587DD0(a1, a2, a3);
  *(_BYTE *)(a1 + a3) = 0;
  return result;
}

