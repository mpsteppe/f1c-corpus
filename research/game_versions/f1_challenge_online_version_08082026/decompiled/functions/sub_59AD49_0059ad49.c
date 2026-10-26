int __userpurge sub_59AD49@<eax>(int a1@<ebp>, int a2)
{
  char *v2; // eax

  sub_58A5D8();
  *(_BYTE *)(a1 - 32) = *(_BYTE *)(a1 - 13);
  sub_5993AF((_DWORD *)(a1 - 32), 0);
  v2 = sub_58E1B0("string too long");
  sub_599615((_DWORD *)(a1 - 32), "string too long", (unsigned int)v2);
  *(_DWORD *)(a1 - 4) = 0;
  sub_59ADA3(a1 - 32);
  *(_DWORD *)(a1 - 60) = &std::length_error::`vftable';
  sub_59BFC3(a1 - 60, &_TI3_AVlength_error_std__);
  return sub_59ADA3(a2);
}
