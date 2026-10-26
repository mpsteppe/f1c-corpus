// f1c  0x00587d02  size=49
int __cdecl sub_587D02(int a1)
{
  int v1; // edi

  v1 = -1;
  if ( (*(_BYTE *)(a1 + 12) & 0x40) != 0 )
  {
    *(_DWORD *)(a1 + 12) = 0;
  }
  else
  {
    sub_58C1B1(a1);
    v1 = sub_587D33(a1);
    sub_58C203(a1);
  }
  return v1;
}
