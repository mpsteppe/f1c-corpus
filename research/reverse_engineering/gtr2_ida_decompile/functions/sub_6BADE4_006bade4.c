int __stdcall sub_6BADE4(int a1, int a2, unsigned int a3)
{
  int v3; // eax

  sub_6B9E38(a1, (unsigned __int8 *)(a1 + 268));
  if ( (*(_BYTE *)(a1 + 268) & 0x20) == 0 )
    sub_679F41(a1, "unknown critical chunk");
  v3 = *(_DWORD *)(a1 + 88);
  if ( (v3 & 4) != 0 )
    *(_DWORD *)(a1 + 88) = v3 | 8;
  return sub_6BA69B(a1, a3);
}
