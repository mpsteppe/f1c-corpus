int __stdcall sub_6BA69B(int a1, unsigned int a2)
{
  unsigned int i; // edi

  for ( i = *(_DWORD *)(a1 + 160); a2 > i; a2 -= i )
    sub_6B9DC1(a1, *(_DWORD *)(a1 + 156), *(_DWORD *)(a1 + 160));
  if ( a2 )
    sub_6B9DC1(a1, *(_DWORD *)(a1 + 156), a2);
  if ( !sub_6B9DDA(a1) )
    return 0;
  if ( ((*(_BYTE *)(a1 + 268) & 0x20) == 0 || (*(_BYTE *)(a1 + 93) & 2) != 0)
    && ((*(_BYTE *)(a1 + 268) & 0x20) != 0 || (*(_BYTE *)(a1 + 93) & 4) == 0) )
  {
    sub_679F41(a1, "CRC error");
  }
  sub_679F64(a1, "CRC error");
  return 1;
}
