int __usercall sub_4B1A4A@<eax>(int a1@<ecx>, int a2@<ebp>, int a3@<esi>)
{
  *(_DWORD *)(a2 + 8 * a3 - 1) |= a1;
  return InitWithSentinelPattern(a1);
}

