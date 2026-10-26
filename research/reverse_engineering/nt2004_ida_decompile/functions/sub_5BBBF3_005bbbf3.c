int __usercall sub_5BBBF3@<eax>(int result@<eax>, int a2@<ecx>)
{
  *(_DWORD *)(a2 + 8) = result;
  return result;
}
