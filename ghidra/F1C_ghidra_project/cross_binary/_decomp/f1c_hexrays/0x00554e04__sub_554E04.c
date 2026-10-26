// f1c  0x00554e04  size=12
// positive sp value has been detected, the output may be wrong!
char __userpurge sub_554E04@<al>(char result@<al>, int a2@<ebp>, int a3)
{
  *(_BYTE *)(a2 + 1586460159) += result;
  return result;
}
