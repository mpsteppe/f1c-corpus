// f1c  0x004b1a2a  size=6
int __usercall sub_4B1A2A@<eax>(int a1@<ecx>, int a2@<ebp>, int a3@<esi>)
{
  *(_DWORD *)(a2 + 8 * a3 - 1) -= a1;
  return sub_4B1A30(a1);
}
