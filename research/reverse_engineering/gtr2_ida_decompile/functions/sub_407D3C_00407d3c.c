int __usercall sub_407D3C@<eax>(int a1@<esi>, int a2, int a3, int a4, int a5)
{
  unsigned int v5; // kr00_4

  v5 = __readeflags();
  sub_1007D10(&byte_16C456B, a1);
  __writeeflags(v5);
  *(_DWORD *)(a1 + 8) = 0;
  dword_91BE28 = a1;
  return sub_5A8CA0(a2, a3, a4, -1);
}
