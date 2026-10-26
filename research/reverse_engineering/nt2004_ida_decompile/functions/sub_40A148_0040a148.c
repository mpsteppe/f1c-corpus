int __usercall sub_40A148@<eax>(int a1@<eax>, char a2@<bl>, int a3@<edi>)
{
  int result; // eax

  result = a1 - 1;
  *(_BYTE *)(a3 + 94) += a2;
  return result;
}
