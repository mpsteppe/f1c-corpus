// positive sp value has been detected, the output may be wrong!
char __usercall sub_58E546@<al>(char result@<al>, int a2@<ebx>)
{
  *(_BYTE *)(a2 + 1599997124) += result;
  return result;
}
