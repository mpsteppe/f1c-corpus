// positive sp value has been detected, the output may be wrong!
char __usercall sub_4C4BA8@<al>(char result@<al>, int a2@<ebx>)
{
  *(_BYTE *)(a2 + 1566442692) += result;
  return result;
}
