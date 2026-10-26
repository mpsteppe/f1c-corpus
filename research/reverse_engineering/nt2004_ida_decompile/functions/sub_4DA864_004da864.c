int __usercall sub_4DA864@<eax>(int a1@<eax>, int a2@<ecx>)
{
  *(_BYTE *)(a1 + a2) = *(_BYTE *)(a1 + a2);
  return sub_4DA870();
}
