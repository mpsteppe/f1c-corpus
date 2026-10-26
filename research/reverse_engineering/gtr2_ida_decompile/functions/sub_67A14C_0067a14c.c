int __stdcall sub_67A14C(int a1, int a2)
{
  if ( (*(_BYTE *)(a1 + 88) & 4) == 0 )
    sub_679F05(a1, (int)"No IDATs written into file");
  *(_DWORD *)(a1 + 88) |= 8u;
  return sub_6B7BF6(a1);
}
