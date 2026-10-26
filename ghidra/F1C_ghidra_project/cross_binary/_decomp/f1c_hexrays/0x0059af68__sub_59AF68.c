// f1c  0x0059af68  size=90
int __usercall sub_59AF68@<eax>(int a1@<ebp>)
{
  char *v1; // eax

  sub_58A5D8();
  *(_BYTE *)(a1 - 32) = *(_BYTE *)(a1 - 13);
  sub_5993AF((_DWORD *)(a1 - 32), 0);
  v1 = sub_58E1B0("invalid string position");
  sub_599615((_DWORD *)(a1 - 32), "invalid string position", (unsigned int)v1);
  *(_DWORD *)(a1 - 4) = 0;
  sub_59ADA3(a1, a1 - 32);
  *(_DWORD *)(a1 - 60) = &std::out_of_range::`vftable';
  sub_59BFC3(a1 - 60, &_TI3_AVout_of_range_std__);
  return sub_59AFC2();
}
