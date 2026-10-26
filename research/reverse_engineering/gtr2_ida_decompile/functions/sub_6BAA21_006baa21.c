int __stdcall sub_6BAA21(int a1, int a2, unsigned int a3)
{
  int v3; // eax

  v3 = *(_DWORD *)(a1 + 88);
  if ( (v3 & 1) == 0 || (v3 & 4) == 0 )
    sub_679F05(a1, (int)"No image in file");
  *(_DWORD *)(a1 + 88) |= 0x18u;
  if ( a3 )
    sub_679F26(a1, (int)"Incorrect IEND chunk length");
  return sub_6BA69B(a1, a3);
}
