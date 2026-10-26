char __usercall sub_49EBA2@<al>(char result@<al>, int a2@<ecx>)
{
  *(_BYTE *)(a2 + 280) = 1;
  *(_BYTE *)(a2 + 281) = result;
  return result;
}
