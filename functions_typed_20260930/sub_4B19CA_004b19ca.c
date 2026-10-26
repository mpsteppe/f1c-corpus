int __usercall sub_4B19CA@<eax>(int a1@<ecx>, int a2@<ebp>, int a3@<esi>)
{
  *(_DWORD *)(a2 + 8 * a3 - 1) = a1;
  return sub_4B19D0(a1);
}

